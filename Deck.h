#ifndef DECK_H
#define DECK_H

#include "Stack.h"

class Deck
{
private:
	Stack* deck;

public:
	Deck();
	void shuffle();
	Card* deal();
	int getSize();
	void display();
};

#endif