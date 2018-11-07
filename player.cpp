//
// Created by Vishruthi Ramaswamy on 11/5/18.
//

#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include "player.h"


void Player::addCard(Card c) {
    myHand.push_back(c);
}
Card Player::removeCardFromHand(Card c) {
    myHand.erase(find(myHand.begin(), myHand.end(), c));
    return c;
}

void Player::bookCards(Card c1, Card c2) {}

Card Player::chooseCardFromHand() const {}

bool Player::cardInHand(Card c) const {}

bool Player::checkHandForPair(Card &c1, Card &c2) {}

int Player::getBookSize() const {}

int Player::getHandSize() const {}



string Player::showBooks() const {}

string Player::showHand() const {}

bool Player ::sameRankInHand(Card c) const {}
