#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
#include<string>
#include <fstream>
#include<vector>
#include<algorithm>
#include<time.h>
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;

void turn(Player& p1, Player& p2, Deck& deck, ofstream& fout);
void gofish(Player& p, Deck& deck);
void makePairs(Player& p);

int main(int argc, char *argv[]){
    ofstream fout ("gofish_results.txt");
    Deck deck;
    deck.shuffle();
    Player Andy ("Andy");
    Player Vish ("Vish");

    
    for (int i = 0; i < 7; i++) {
        Andy.addCard(deck.dealCard());
        //fout << Andy.showHand() << endl << endl;
        Vish.addCard(deck.dealCard());
    }

    Player temp;
    Player* p1 = &Andy;
    Player* p2 = &Vish;
    int i = 0;
    while(p1->getBookSize() + p2->getBookSize() < 52) {
        if (i % 2 == 0) turn(*p1, *p2, deck, fout);
        else turn(*p2, *p1, deck, fout);
        fout << "Andy's book size: " << Andy.getBookSize() << endl;
        fout << "Andy's book: " << Andy.showBooks() << endl;
        fout << "Vish's book size: " << Vish.getBookSize() << endl;
        fout << "Vish's book: " << Vish.showBooks() << endl;
        fout << "Andy's hand size: " << Andy.getHandSize() << endl;
        fout << "Andy's hand: " << Andy.showHand() << endl;
        fout << "Vish's hand size: " << Vish.getHandSize() << endl;
        fout << "Vish's hand: " << Vish.showHand() << endl;
        fout << "End of " << p1->getName() << "s, turn" << endl << endl;
        i++;
    }

    fout << "THE GAME IS OVER" << endl; 
    if (p1->getBookSize() > p2->getBookSize()) {
        fout << p1->getName() << " is the WINNNER" << endl;
    } else if (p1->getBookSize() < p2->getBookSize()) {
        fout << p1->getName() << " is the Winner" << endl;
    } else {
        fout << "TIE GAME" << endl;
    }
    
}

void turn(Player& p1, Player& p2, Deck& deck, ofstream& fout){
    fout << p1.getName() << " is checking for pairs" << endl;
    makePairs(p1);
    int handSize = p1.getHandSize();
    if (handSize == 0){
        fout << "No Cards in Hand -  Go Fish" << endl;
        if (deck.size() == 0) {
            fout << " No more cards left" << endl;
            return;
        }
        gofish(p1, deck);
        return;
    }
    fout << handSize << " handsize" << endl;
    Card chosenCard = p1.chooseCardFromHand();
    fout << p1.getName() << " asks - Do you have any " << chosenCard.rankString(chosenCard.getRank()) <<endl;

    Card cs(chosenCard.getRank(), chosenCard.spades);
    Card ch(chosenCard.getRank(), chosenCard.hearts);
    Card cd(chosenCard.getRank(), chosenCard.diamonds);
    Card cc(chosenCard.getRank(), chosenCard.clubs);

    fout << p2.getName() << " says - ";

    if(p2.sameRankInHand(chosenCard)){
        fout << "Yes! Here you go" << endl;

        if(p2.cardInHand(cs)) {
            p1.addCard(p2.removeCardFromHand(cs));
        }
        if (p2.cardInHand(ch)) {
            p1.addCard(p2.removeCardFromHand(ch));
        }
        if (p2.cardInHand(cd)) {
            p1.addCard(p2.removeCardFromHand(cd));
        }
        if (p2.cardInHand(cc)) {
            p1.addCard(p2.removeCardFromHand(cc));
        }  
        fout << p1.getName() << " books the " << chosenCard.getRank() << endl;
        makePairs(p1);
        fout << p1.showHand() << endl;
    } 
    else {
        fout << " GO FISH " << endl;
        gofish(p1, deck);
    }

    return;
}
void makePairs(Player& p){
    Card* c1 = new Card();
    Card* c2 = new Card();
    while(p.checkHandForPair(*c1, *c2)){
        p.bookCards(p.removeCardFromHand(*c1), p.removeCardFromHand(*c2));
    }
    delete c1; 
    delete c2;

    return;
}
void gofish(Player& p, Deck& deck){
    if(deck.size() != 0){
        p.addCard(deck.dealCard());
    }
    return;
}
