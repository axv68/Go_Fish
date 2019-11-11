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

Player::Player()
{
    myName = "Timmy";
}

string Player::showHand() const
{
    if (myHand.size() == 0)
    {
        return " ";
    }
    string result = myHand[0].toString();
    for (int i = 1; i < myHand.size(); i++)
    {
        result = result + " " + myHand[i].toString();
    }
    return result;
}

void Player::addCard(Card c)
{
    myHand.push_back(c); 
}

Card Player::removeCardFromHand(Card c)
{ 
    Card dummyCard;
    for (int j = 0; j < myHand.size(); j++)
    {
        if (myHand[j] == c)
        {
            Card temp = myHand[j];
            myHand.erase(myHand.begin() + j);
            return temp;
        }
    }
    return dummyCard;
}

void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1); // puts c1 at the end of the vector
    myBook.push_back(c2);
    cout << "    " << this->getName() << " booked " << c1 << " and " << c2 << endl << endl;
}

Card Player::chooseCardFromHand() const
{
    int randomCardNum = rand() % myHand.size();
    return (myHand[randomCardNum]);
}

int Player::getHandSize() const
{
    return (myHand.size());
}

Card Player::cardInHand(Card c) const
{ 
    Card dummyCard;
    for (int j = 0; j < myHand.size(); j++)
    {
        if (myHand[j].getRank() == c.getRank())
        {
            return myHand[j];
        }
    }
    return dummyCard;
}

bool Player::sameRankInHand(Card c) const
{
    for (int j = 0; j < myHand.size(); j++)
    {
        if (myHand[j].getRank() == c.getRank())
        {
            return true;
        }
    }
    return false;
}

void Player::checkHandForPair()
{   
    for (int i = 0; i < myHand.size(); i++)
    {
        for (int j = i + 1; j < myHand.size(); j++)
        {
            if (myHand[i].getRank() == myHand[j].getRank())
            {
                bookCards(myHand[i], myHand[j]);
                removeCardFromHand(myHand[i]);
                removeCardFromHand(myHand[j - 1]); // j-1 to deal with the removal from the vector of the ith element.
                                                    // positioning of vector has changed and needs to be accounted for
                j--;
            }
        }
    }
    
}

int Player::getBookSize() const
{
    return myBook.size();
}
