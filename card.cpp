#include<stdlib.h>
#include<string>
#include<stdbool.h>
#include "card.h"

using namespace std;

Card::Card() {

}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string name = "";
    name += rankString(myRank);
    name += suitString(mySuit);
    return name;
}

bool Card::sameSuitAs(const Card &c) const {
    if (myRank == c.getRank()) return true;
    return false;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    string suit = "";
    if (s == spades) {
        suit += 's';
    } else if (s == hearts) {
        suit += 'h';
    } else if (s == diamonds) {
        suit += 'd';
    } else { //my Suit == clubs
        suit += 'c';
    }
    return suit;
}

string Card::rankString(int r) const {
    string rank = "";
    if (r == 1) {
        rank += 'A';
    } else if (r == 11) {
        rank += 'J';
    } else if (r == 12) {
        rank += 'Q';
    } else if (r == 13) {
        rank += 'K';
    } else {
        rank += to_string(myRank);
    }
    return rank;
}

bool Card::operator==(const Card &rhs) const {
    if (myRank == rhs.getRank()) return true;
    return false;
}

bool Card::operator!=(const Card &rhs) const {
    if (myRank == rhs.getRank()) return false;
    return true;
}