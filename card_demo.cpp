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
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    // Card c(4, c.clubs); 
    // p1.addCard(c); 

    // cout << p1.getName() <<" has : " << p1.showHand() << endl;
    // cout << "Joe Cards: "<< p1.getHandSize() << endl ;
    // Card q = p1.chooseCardFromHand(); 
    // cout << q << endl; 

    string winner; 
    
    while (d.size() != 0){ 

        if (p1.getHandSize() == 0){ 
            winner = p1.getName(); 
            break; 
        }
        if (p2.getHandSize() == 0){ 
            winner = p2.getName(); 
            break; 
        }

        cout << "       It is " << p1.getName() << " 's turn" << endl; 
        p1.checkHandForPair();
        if (p1.getHandSize() == 0){ 
                winner = p1.getName(); 
                break; 
        }
        Card p = p1.chooseCardFromHand(); 
        cout << endl << p1.getName() << " asks if " << p2.getName() << " has " << p << endl; 

        if (p2.cardInHand(p)){ 
            cout << p1.getName() << " has a match " << endl;     
            p1.removeCardFromHand(p); 
            p1.bookCards(p, p2.removeCardFromHand(p)); 
            if (p1.getHandSize() == 0){ 
                winner = p1.getName(); 
            break; 
        }
        }
        else{ 
            cout << endl << p2.getName() << " doesn't have a card with rank " << p.getRank() << endl; 
            cout << endl << p1.getName() << " now needs to add card to his/her hand " << endl; 
            p1.addCard(d.dealCard()); 
            cout << p1.getName() <<" NOW has : " << p1.showHand() << endl;
            if (d.size() == 0){ 
                break; 
            }
        }

        cout << "       It is " << p2.getName() << " 's turn" << endl;
        p2.checkHandForPair();
        if (p2.getHandSize() == 0){ 
                winner = p2.getName(); 
                break; 
        }
        Card t = p2.chooseCardFromHand(); 
        cout << endl << p2.getName() << " asks if " << p1.getName() << " has " << t << endl; 

        if (p1.cardInHand(t)){ 
            cout << p2.getName() << " has a match " << endl;         
            p2.removeCardFromHand(t); 
            p2.bookCards(t, p1.removeCardFromHand(t)); 
            if (p2.getHandSize() == 0){ 
                winner = p2.getName(); 
            break; 
        }
        }
        else{ 
            cout << endl << p1.getName() << " doesn't have a card with rank " << p.getRank() << endl; 
            cout << endl << p2.getName() << " now needs to add card to his/her hand " << endl; 
            p2.addCard(d.dealCard()); 
            cout << p2.getName() <<" NOW has : " << p1.showHand() << endl;
        }

    }

    cout << "The Winner is " << winner << "!" <<endl; 
    
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   


