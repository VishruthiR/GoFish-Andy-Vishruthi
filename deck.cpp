#include "deck.h"
#include "card.h"
#include <stdlib.h>
#include <time.h>

Deck::Deck() {
    Card c;
    for (int i = 1; i <= 13; i++) {
        c = Card(i, c.spades);
        myCards[(i-1)*4+0] = c;
        c = Card(i, c.hearts);
        myCards[(i-1)*4+1] = c;
        c = Card(i, c.clubs);
        myCards[(i-1)*4+2] = c;
        c = Card(i, c.diamonds);
        myCards[(i-1)*4+3] = c;
    }
    myIndex = 0;
}

void Deck::shuffle() {

    srand (time(NULL));
    int count = 52;

    for(int i = 0;i<10000;i++){
        int rand1 = rand() % count;
        int rand2 = rand() % count;
        Card tmp;
        tmp = myCards[rand1];
        myCards[rand1] = myCards[rand2];
        myCards[rand2] = tmp;
    }    
    myIndex = 0;
}

Card Deck::dealCard() {
    if (myIndex >= SIZE) {
        cout << "No more cards to deal!" << endl;
        exit(1);
    }
    myIndex++;
    return myCards[myIndex-1];
}

int Deck::size() const {
    return SIZE-myIndex;
}