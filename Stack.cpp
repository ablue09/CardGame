#include "Card.h"
#include "Stack.h"

#include <iostream>
//#include <stdlib.h>

Stack::Stack()
{
	Stack(100);
}

Stack::Stack(int cap) : capacity(cap), size(0), stack(new Card*[capacity])
{

}

bool Stack::isFull()
{
	return size == capacity;
}

bool Stack::isEmpty()
{
	return size == 0;
}

int Stack::getSize()
{
	return size;
}

bool Stack::push(Card *card)
{
	if(isFull())
	{
		cerr << "Stack is full" << endl;
		return false;
	}

	stack[size] = card;
	size++;
	return true;
}

Card * Stack::pop()
{
	if(isEmpty())
	{
		cerr << "Stack is empty" << endl;
		return NULL;
	}

	size--;
	Card * temp = stack[size];

	return temp;
}

Card * Stack::peek()
{
		if(isEmpty())
	{
		cerr << "Stack is empty" << endl;
		return NULL;
	}

	Card * temp = stack[size - 1];
}

void Stack::dislay()
{
	for(int i = size - 1; i >= 0; i--)
	{
		cout << stack[i] -> display() << endl; // (*stack[i]).func
	}
}