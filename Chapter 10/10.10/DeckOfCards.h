#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>
#include "Card.h"

using std::vector;

class DeckOfCards
{
private:
	vector<Card> deck;
	int currentCard;
public:
	DeckOfCards();
	void shuffle();
	Card dealCard();
	bool moreCards();
};

#endif // !DECKOFCARDS_H
