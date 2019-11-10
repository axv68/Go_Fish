// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"
#include "player.h"
using namespace std;

Player::Player(){ 
    myName = "Timmy"; 
}

string Player::showHand() const{
    if(myHand.size() == 0){
        return " ";
    }
    string result = myHand[0].toString(); 
    for (int i=1; i < myHand.size(); i++){
         result = result + " " + myHand[i].toString(); 
    }
    return result; 
}

void Player::addCard(Card c){ 
    myHand.push_back(c); //adds card to a hand
}

Card Player::removeCardFromHand(Card c){            // bad function, needs to remove a specific card from player hand not a card of similar rank
    Card dummyCard;
    for (int j = 0; j < myHand.size(); j++){
        if (myHand[j] == c){
            Card temp = myHand[j]; 
            myHand.erase(myHand.begin()+j); 
            return temp; 
        }
    }
    return dummyCard;
}

void Player::bookCards(Card c1, Card c2){ 
    myBook.push_back(c1);                       // puts c1 at the end of the vector
    myBook.push_back(c2);
    cout <<"    "<< this->getName() << " booked " << c1 << " and " << c2 << endl << endl;
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

Card Player::cardInHand(Card c) const{             // CHRIS CHANGED function return from bool to Card
    Card dummyCard;
    for (int j = 0; j < myHand.size(); j++){
        if (myHand[j].getRank() == c.getRank()){ 
            return myHand[j];
        }
    }
    return dummyCard;
}

bool Player::sameRankInHand(Card c) const {
    for (int j = 0; j < myHand.size(); j++){
        if (myHand[j].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

void Player::checkHandForPair(){                  // had to alter this function. cant remove cards while iterating though the vector as it will
                                                  // skip over some cards due to the deletion and reordering of the vector
    for (int i = 0; i < myHand.size(); i++){ 
        for (int j = i+1; j < myHand.size(); j++){
//            if (i != j){
                if (myHand[i].getRank() == myHand[j].getRank()){
                    bookCards(myHand[i] ,myHand[j]);
                    removeCardFromHand(myHand[i]);
                    removeCardFromHand(myHand[j-1]);                // j-1 to deal with the removal from the vector of the ith element.
                    i--;                                            // positioning of vector has changed and needs to be accounted for
                    j--;
                }
//            }
        }
    }
//    for(int i = 0; i < myBook.size(); i++){
//        removeCardFromHand(myBook[i]);
//    }
}

int Player::getBookSize() const{
    return myBook.size();
}


