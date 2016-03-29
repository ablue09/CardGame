#include "Card.h"
#include "Stack.h"

#include <iostream>

int main()
{
	Stack s(20);

	for(int i = 0; i < 10; i++)
	{
		s.push(new Card(i));
	}

	s.dislay();

	s.push(new Card(10));
	cout << endl;
	s.dislay();

	system("pause");

	return 0;
}