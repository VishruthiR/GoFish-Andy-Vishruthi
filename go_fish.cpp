#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
#include<string>
#include<vector>
#include<algorithm>
#include<time.h>
#include"player.h"
#include "deck.h"

using namespace std;

void turn(Player p1, Player p2, Deck deck);
void gofish(Player p, Deck deck);
void makePairs(Player p);

int main(int argc, char *argv[]){
    Deck deck;
    deck.shuffle();
    Player Andy ("Andy");
    Player Vish ("Vish");

    
    for (int i = 0; i < 7; i++) {
        Andy.addCard(deck.dealCard());
        Vish.addCard(deck.dealCard());
    }

    Player temp;
    
    for(int i = 0; i < 20; i++){
    Player p1 = Andy;
    Player p2 = Vish;
    turn(p1, p2, deck);
    cout << "Andy's book size: " << Andy.getBookSize() << endl;
    cout << "Andy's book: " << Andy.showBooks() << endl;
    cout << "Vish's book size: " << Vish.getBookSize() << endl;
    cout << "Vish's book: " << Vish.showBooks() << endl;
    cout << "Andy's hand size: " << Andy.getHandSize() << endl;
    cout << "Andy's hand: " << Andy.showHand() << endl;
    cout << "Vish's hand size: " << Vish.getHandSize() << endl;
    cout << "Vish's hand: " << Vish.showHand() << endl;
    temp = p1;
    p1 = p2;
    p2 = temp; 
    }
    
    /*
    while((Andy.getBookSize() + Vish.getBookSize()) != 52){
        Player p1 = Andy;
        Player p2 = Vish;
        turn(p1, p2, deck);
        temp = p1;
        p1 = p2;
        p2 = temp; 
    }*/

}

void turn(Player p1, Player p2, Deck deck){
    makePairs(p1);
    int handSize = p1.getHandSize();
    Card chosenCard = p1.chooseCardFromHand();
    cout << p1.getName() << " asks - Do you have any " << chosenCard.rankString(chosenCard.getRank()) <<endl;

    Card cs(chosenCard.getRank(), chosenCard.spades);
    Card ch(chosenCard.getRank(), chosenCard.hearts);
    Card cd(chosenCard.getRank(), chosenCard.diamonds);
    Card cc(chosenCard.getRank(), chosenCard.clubs);

    cout << p2.getName() << " says - ";

    if(p2.sameRankInHand(chosenCard)){
        cout << "Yes! Here you go" << endl;

        if(p2.cardInHand(cs)) {
            p2.removeCardFromHand(cs);
            p1.addCard(cs);
        }
        if (p2.cardInHand(ch)) {
            p2.removeCardFromHand(ch);
            p1.addCard(ch);
        }
        if (p2.cardInHand(cd)) {
            p2.removeCardFromHand(cd);
            p1.addCard(ch);
        }
        if (p2.cardInHand(cc)) {
            p2.removeCardFromHand(cc);
            p1.addCard(cc);
        }  
        cout << p1.getName() << " books the " << chosenCard.getRank() << endl;
        makePairs(p1);
    } 
    else {
        cout << "GO FISH" << endl;
        gofish(p1, deck);
    }

    return;
}
void makePairs(Player p){
    Card c1;
    Card c2;
    while(p.checkHandForPair(c1, c2)){
        p.bookCards(c1, c2);
        p.removeCardFromHand(c1);
        p.removeCardFromHand(c2);
    }

    return;
}
void gofish(Player p, Deck deck){
    if(deck.size() != 0){
        p.addCard(deck.dealCard());
    }
    return;
}
