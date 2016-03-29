#ifndef STACK_H
#define STACK_H

#include "Card.h"

class Stack
{
private:
	Card **stack; //pointer to a pointer
	int capacity;
	int size;
	bool isFull();
	bool isEmpty();

public:
	Stack();
	Stack(int size);
	int getSize();
	bool push(Card *card);
	Card *pop();
	Card *peek();
	void dislay();
};

#endif