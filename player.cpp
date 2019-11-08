// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
#include "player.h"
using namespace std;

Player::Player(){ 
    myName = "Timmy"; 
}

string Player::showHand() const{ 
    string result = myHand[0].toString(); 
    for (int i=1; i < myHand.size(); i++){
         result = result + " " + myHand[i].toString(); 
    }
    return result; 
}

void Player::addCard(Card c){ 
    myHand.push_back(c); //adds card to a hand
}

Card Player::removeCardFromHand(Card c){
    for (int j = 0; j < myHand.size(); j++){
        if (myHand[j].getRank() == c.getRank()){ 
            Card temp = myHand[j]; 
            myHand.erase(myHand.begin()+j); 
            return temp; 
        }
    } 
}

void Player::bookCards(Card c1, Card c2){ 
    myBook.push_back(c1); 
    myBook.push_back(c2); 
}

Card Player::chooseCardFromHand() const { 
    //ask for random card 
    int randomCardNum = rand() % myHand.size();
    return (myHand[randomCardNum]); 

}

int Player::getHandSize() const{ 
    return (myHand.size()); 
}

// bool Player::checkHandForPair(Card &c1, Card &c2){ 
//     if (c1.getRank() == c2.getRank()){ 
//         bookCards(c1, c2); 
//         return true; 
//     }
//     else { 
//         return false; 
//     }
// }

bool Player::cardInHand(Card c) const{ 
    for (int j = 0; j < myHand.size(); j++){ 
        if (myHand[j].getRank() == c.getRank()){ 
            return true;
        }
    }
    return false; 
}

void Player::checkHandForPair(){
    for (int i = 0; i < myHand.size(); i++){ 
        for (int j = 0; j < myHand.size(); j++){ 
            if (i != j){
                if (myHand[i].getRank() == myHand[j].getRank()){
                    bookCards(myHand[i],myHand[j]); 
                    removeCardFromHand(myHand[i]); 
                    removeCardFromHand(myHand[j]); 
                }
            }
        }
    }
}


