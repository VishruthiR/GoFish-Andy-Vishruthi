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
    if (myRank == 1) {
        name += 'A';
    } else if (myRank == 11) {
        name += 'J';
    } else if (myRank == 12) {
        name += 'Q';
    } else if (myRank == 13) {
        name += 'K';
    } else {
        name += to_string(myRank);
    }
    if (mySuit == spades) {
        name += 's';
    } else if (mySuit == hearts) {
        name += 'h';
    } else if (mySuit == diamonds) {
        name += 'd';
    } else { //my name == clubs
        name += 'c';
    }
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
        suit = "Spades";
    } else if (s == hearts) {
        suit = "Hearts";
    } else if (s == diamonds) {
        suit = "Diamonds";
    } else { //my Suit == clubs
        suit = "Clubs";
    }
    return suit;
}

string Card::rankString(int r) const {
    string rank = "";
    if (r == 1) {
        rank = "Aces";
    } else if (r == 11) {
        rank = "Jacks";
    } else if (r == 12) {
        rank = "Queens";
    } else if (r == 13) {
        rank = "Kings";
    } else if (r == 1) {
        rank = "Ones";
    } else if (r == 2) {
        rank = "Twos";
    } else if (r == 3) {
        rank = "Threes";
    } else if (r == 4) {
        rank = "Fours";
    } else if (r == 5) {
        rank = "Fives";
    } else if (r == 6) {
        rank = "Sixes";
    } else if (r == 7) {
        rank = "Sevens";
    } else if (r == 8) {
        rank = "Eights";
    } else if (r == 9) {
        rank = "Nines";
    } else if (r == 10) {
        rank = "Tens";
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