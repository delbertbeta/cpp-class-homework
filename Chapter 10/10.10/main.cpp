#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

int main()
{
	DeckOfCards deck;
	deck.shuffle();
	while (deck.moreCards())
	{
		cout << deck.dealCard().toString() << endl;
	}
	//cout << endl;
	// system("pause");
	return 0;

}