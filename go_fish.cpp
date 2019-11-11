// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main()
{
    ofstream thisFile ("go_fish.txt"); //Open the text file

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
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl << endl;
        thisFile << p1.getName() <<" has : " << p1.showHand() << endl << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl << endl;
        thisFile << p2.getName() <<" has : " << p2.showHand() << endl << endl;
    
    while (!win) {
        askingPlayer->checkHandForPair();
        if (askingPlayer->getHandSize() == 0) {
            if(d.size() != 0) {
                cardToAdd = d.dealCard();
                askingPlayer->addCard(cardToAdd);
                cout << "    "<< askingPlayer->getName() << " is out of cards and draws a " << cardToAdd << endl;
                    thisFile << "    "<< askingPlayer->getName() << " is out of cards and draws a " << cardToAdd << endl;
                temp = askingPlayer;
                askingPlayer = stillPlayer; 
                stillPlayer = temp;
            }
            else{
                break; // if the players hand is 0 AND the deck is 0, you should break
            }
        }
        cout << endl << "It is " << askingPlayer->getName() << " 's turn" << endl;
            thisFile << endl << "It is " << askingPlayer->getName() << " 's turn" << endl;
        Card p = askingPlayer->chooseCardFromHand();
        cout << endl << "   " << askingPlayer->getName() << " asks if " << stillPlayer->getName() << " has a " << p.rankString(p.getRank()) << endl;
            thisFile << endl << "   " << askingPlayer->getName() << " asks if " << stillPlayer->getName() << " has a " << p.rankString(p.getRank()) << endl;

        if (stillPlayer->sameRankInHand(p)) {
            matchCounter = 0;
            while (stillPlayer->cardInHand(p) != dummyCard) {
                askingPlayer->addCard(stillPlayer->cardInHand(p));
                stillPlayer->removeCardFromHand(stillPlayer->cardInHand(p));
                matchCounter++;
            }
            cout << "   "<<stillPlayer->getName() << " has " << matchCounter << " " << p.rankString(p.getRank()) << "'s" << endl;
                thisFile << "   "<<stillPlayer->getName() << " has " << matchCounter << " " << p.rankString(p.getRank()) << "'s" << endl;
        }else {
            cout << endl << "   " << stillPlayer->getName() << " says 'Go Fish' " <<  endl;
                thisFile << endl << "   " << stillPlayer->getName() << " says 'Go Fish' " <<  endl;
            if(d.size() != 0) {
                cardToAdd = d.dealCard();
                askingPlayer->addCard(cardToAdd);
                cout << endl << "   "<< askingPlayer->getName() << " draws a " << cardToAdd.rankString(cardToAdd.getRank()) << endl << endl;
                    thisFile << endl << "   "<< askingPlayer->getName() << " draws a " << cardToAdd.rankString(cardToAdd.getRank()) << endl << endl;
                temp = askingPlayer;
                askingPlayer = stillPlayer;
                stillPlayer = temp;
            }
        }
        cout << askingPlayer->getName() << " NOW has : " << askingPlayer->showHand() << endl << endl;
            thisFile << askingPlayer->getName() << " NOW has : " << askingPlayer->showHand() << endl << endl;
        cout << stillPlayer->getName() << " NOW has : " << stillPlayer->showHand() << endl << endl;
            thisFile << stillPlayer->getName() << " NOW has : " << stillPlayer->showHand() << endl << endl;
        if(d.size() == 0){
            cout << "The deck is empty! Time to tally up results ...." << endl << endl;
                thisFile << "The deck is empty! Time to tally up results ...." << endl << endl;
            win = true;
        }
    }

    cout << "________________________________" << endl << endl; 
        thisFile << "________________________________" << endl << endl; 
    
    cout << p1.getName() << " has " << (p1.getBookSize())/2 << " books " << endl << endl; 
        thisFile << p1.getName() << " has " << (p1.getBookSize())/2 << " books " << endl << endl; 

    cout << p2.getName() << " has " << (p2.getBookSize())/2 << " books " << endl << endl; 
        thisFile << p2.getName() << " has " << (p2.getBookSize())/2 << " books " << endl << endl; 

    if((p1.getBookSize())/2 > (p2.getBookSize())/2){
        winner = p1.getName();
        cout << "The Winner is " << winner << "!" <<endl << endl; 
            thisFile << "The Winner is " << winner << "!" <<endl << endl; 
    }
    if ((p2.getBookSize())/2 > (p1.getBookSize())/2){
        winner = p2.getName();
        cout << "The Winner is " << winner << "!" <<endl << endl; 
            thisFile << "The Winner is " << winner << "!" <<endl << endl; 
    }
    if ((p2.getBookSize())/2 == (p1.getBookSize())/2){
        cout << "There is tie between " << p1.getName() << " and " << p2.getName() << endl << endl; 
            thisFile << "There is tie between " << p1.getName() << " and " << p2.getName() << endl << endl; 
    }

    thisFile.close();

    return EXIT_SUCCESS;  
}


void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   


