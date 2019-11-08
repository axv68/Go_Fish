#include <iostream>
#include <string>
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std; 

int main (){ 
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    string winner; 
    
    while (d.size() != 0){ 
        if (p1.getHandSize() == 5){ 
            winner = p1.getName(); 
        }

    }

    cout << "The Winner is" << winner <<endl; 
    


}

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
