// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main()
{
    int numCards = 7;
    int matchCounter = 0;
    
    Player p1("Chris");
    Player p2("Amit");
    bool win = false;
    bool switchPlayer = false;
    Card dummyCard;
    Card cardToAdd;

    Player* askingPlayer = &p1;
    Player* stillPlayer = &p2;
    Player* temp = &p2;
    string winner;

    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    cout << endl;
    
    while (!win) {
        askingPlayer->checkHandForPair();
        if (askingPlayer->getHandSize() == 0) {
            if(d.size() != 0) {
                cardToAdd = d.dealCard();
                askingPlayer->addCard(cardToAdd);
                cout << askingPlayer->getName() << " is out of cards and draws a " << cardToAdd << endl;
                temp = askingPlayer;
                askingPlayer = stillPlayer;
                stillPlayer = temp;
            }
        }
        cout << "It is " << askingPlayer->getName() << " 's turn" << endl;
        Card p = askingPlayer->chooseCardFromHand();
        cout << endl << askingPlayer->getName() << " asks if " << stillPlayer->getName() << " has a " << p.rankString(p.getRank()) << endl;

        if (stillPlayer->sameRankInHand(p)) {
            matchCounter = 0;
            while (stillPlayer->cardInHand(p) != dummyCard) {
                askingPlayer->addCard(stillPlayer->cardInHand(p));
                stillPlayer->removeCardFromHand(stillPlayer->cardInHand(p));
                matchCounter++;
            }
            cout << stillPlayer->getName() << " has " << matchCounter << " " << p.rankString(p.getRank()) << "'s" << endl;
        }else {
            cout << endl << stillPlayer->getName() << " says 'Go Fish' " << endl;
            if(d.size() != 0) {
                cardToAdd = d.dealCard();
                askingPlayer->addCard(cardToAdd);
                cout << endl << askingPlayer->getName() << " draws a " << cardToAdd.rankString(cardToAdd.getRank()) << endl << endl;
                temp = askingPlayer;
                askingPlayer = stillPlayer;
                stillPlayer = temp;
            }
        }
        cout << askingPlayer->getName() << " NOW has : " << askingPlayer->showHand() << endl;
        cout << stillPlayer->getName() << " NOW has : " << stillPlayer->showHand() << endl << endl;
        if(d.size() == 0){
            cout << "Deck is empty" << endl << endl;
            win = true;
        }
    }
    if(p1.getBookSize() > p2.getBookSize()){
        winner = p1.getName();
    }else{
        winner = p2.getName();
    }

    cout << "The Winner is " << winner << "!" <<endl; 
    
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   


