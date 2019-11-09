// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Deck::Deck(){ 
    //sorted deck
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator

    int k = 0; 
    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 14; j++){
            myCards[k].setRank(j); 
            myCards[k].setSuit((Card::Suit) i); 
            //cout << myCards[k] << endl; 
            k++; 
        }
    }

    myIndex = 0; //set index to the top of the deck to deal a card
    
}

void Deck::shuffle(){ 
    //shuffle cards

        Card temp; 
        for(int i = 0; i < 2*SIZE; i++){
            int shufflePosition1 = rand() % SIZE;
            int shufflePosition2 = rand() % SIZE;
            temp = myCards[shufflePosition1]; 
            myCards[shufflePosition1] = myCards[shufflePosition2]; 
            myCards[shufflePosition2] = temp; 
        }

        //cout << "Shuffled Deck\n"; 
        // for (int i = 0; i < 52; i++){ 
        //     cout << myCards[i] << endl;
        // }
}

Card Deck::dealCard(){
    Card dummyCard;
    //Check if there are cards in the deck
     if (myIndex < 52){
        myIndex++; 
        return (myCards[myIndex-1]);
     }else{
         return dummyCard;
     }
}

int Deck::size() const{ 
    //counts # of cards left in the deck 
        return (52-myIndex); 
}


