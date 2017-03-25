#include "DeckOfCards.h"
#include <cstdlib>
#include <ctime>

DeckOfCards::DeckOfCards()
{
    currentCard = 0;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			deck.push_back(Card(i, j));
		}
	}
}

void DeckOfCards::shuffle()
{
	srand(clock());
	for (int i = 0; i < 52; i++)
	{
		int index1 = rand() % 52;
		int index2 = rand() % 52;
		Card tempCard = deck[index1];
		deck[index1] = deck[index2];
		deck[index2] = tempCard;
	}
}

Card DeckOfCards::dealCard()
{
	return deck[currentCard++];
}

bool DeckOfCards::moreCards()
{
	if (currentCard == 52)
		return false;
	else
		return true;
}
