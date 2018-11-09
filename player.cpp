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

using namespace std;


Player::Player(){
    myName = "";
}

Player::Player(string name) {
   myName = name;
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

Card Player::removeCardFromHand(Card c) {
    Card tmp;
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].toString() == c.toString()) {
            tmp = myHand[i];
            myHand.erase(myHand.begin()+i);
            return tmp;
        }
    }
    return tmp;
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

Card Player::chooseCardFromHand() const {
    int randNum = rand() % myHand.size();
    return myHand[randNum];
}

bool Player::cardInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) return true;
    }
    return false;
}

int Player::getBookSize() const {
    return myBook.size();
}

int Player::getHandSize() const {
    return myHand.size();
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    if (myHand.size() < 2) return false;
    for(int i = 0; i < myHand.size()-1; i++){
        for(int j = i+1; j < myHand.size(); j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

string Player::showBooks() const {
    string book;
    for(int i = 0; i < myBook.size(); i++){
        book = book + myBook[i].toString() + "   ";
    }
    return book;
}

string Player::showHand() const {
    string hand;
    for(int i = 0; i < myHand.size(); i++){
        hand = hand + myHand[i].toString() + "   ";
    }
    return hand;
}

bool Player ::sameRankInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if (myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}
