#include "Card.h"
#include <string>

using std::string;

const string Card::faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const string Card::suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

Card::Card(int f, int s)
{
	face = f;
	suit = s;
}

std::string Card::toString()
{
	return faces[face] + " of " + suits[suit];
}
