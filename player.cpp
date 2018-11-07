//
// Created by Vishruthi Ramaswamy on 11/5/18.
//

#include <iostream>
#include <string>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include "player.h"


Player::Player() {}

void Player::addCard(Card c) {
    myHand.push_back(c);
}
Card Player::removeCardFromHand(Card c) {
    myHand.erase(find(myHand.begin(), myHand.end(), c));
    return c;
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

Card Player::chooseCardFromHand() const {
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int randNum = rand() % 5;
    return myHand[randNum];
}

bool Player::cardInHand(Card c) const {
    if(find(myHand.begin(),myHand.end(),c) != myHand.end()){
        return true;
    }
    else{
        return false;
    }
}

int Player::getBookSize() const {
    return myBook.size()/2;
}

int Player::getHandSize() const {
    return myHand.size();
}

bool Player::checkHandForPair(Card &c1, Card &c2) {}

string Player::showBooks() const {
    string book;
    for(int i = 0; i < myBook.size(), i++){
        book = myBook[i].toString() + "   ";
    }
    return book;
}

}

string Player::showHand() const {
    string hand;
    for(int i = 0; i < myHand.size(), i++){
        hand += myHand[i].toString();
    }
    return hand;
}

bool Player ::sameRankInHand(Card c) const {
    for(int i = 1; i < myHand.size(); i++){
        if (myHand[i].getRank() == myHand[i-1].getRank()){
            return true;
        }
    }
    return false;
}

