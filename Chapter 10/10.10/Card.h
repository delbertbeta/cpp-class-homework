#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
	Card(int = 1, int = 1);
	std::string toString();
	static const std::string faces[];
	static const std::string suits[];
private:
	int face;		// J = 10, Q = 11, K = 12
	int suit;		// clubs = 0, diamonds = 1, hearts = 2, spades = 3
};

#endif // !CARD_H
