//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card(){ 
    myRank = 0;
    mySuit = spades; 
}

Card::Card(int rank, Suit s){
    myRank = rank; 
    mySuit = s; 
}

string Card::toString() const{
    //Conditional Check For myRank
    string result; 
    if (myRank == 1){ 
        result = "A";
    }
    if (myRank == 11){
        result = "J"; 
    }
    if (myRank == 12){
        result = "Q"; 
    }
    if (myRank == 13){
        result = "K"; 
    }
    if (myRank >= 2 && myRank <= 10){ 
        if (myRank == 10){
            result = "10"; 
        }
        else {
            result = myRank + 0x30; 
        }
    }
    if (mySuit == spades){
        result = result + "s"; 
    }
    if (mySuit == hearts){
        result = result + "h"; 
    }
    if (mySuit == diamonds){
        result = result + "d"; 
    }
    if (mySuit == clubs){
        result = result + "c"; 
    } 
    return result; 
}

bool Card::sameSuitAs(const Card& c) const{ 
    if (mySuit == c.mySuit){ 
        return true; 
    } 
    return false;    
}

int Card::getRank() const{ 
    return myRank; 
}

string Card::rankString(int r) const{
    string result;
    bool faceCard = false;
    if (myRank == 1){
        result = "A";
        faceCard = true;
    }
    if (myRank == 11){
        result = "J";
        faceCard = true;
    }
    if (myRank == 12){
        result = "Q";
        faceCard = true;
    }
    if (myRank == 13){
        result = "K";
        faceCard = true;
    }
    if (myRank == 10){
        result = "10";
        faceCard = true;
    }
    if (!faceCard) {
        result = myRank + 0x30; 
    }
    return result; 
}

//AMITS FUNCTIONS

void Card::setRank(int r){ 
    myRank = r; 
}

void Card::setSuit(Suit s){
    mySuit = s; 
}

bool Card::operator == (Card const &rhs) const
{
    return (myRank == rhs.myRank && mySuit == rhs.mySuit); 
}

bool Card::operator !=(Card const &rhs) const
{
    return (myRank != rhs.myRank || mySuit != rhs.mySuit); 
}

ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString();
    return out;
}
