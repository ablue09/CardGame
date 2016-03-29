#include "Card.h"

#include <iostream>
using namespace std;


Card::Card() : rank(0), value(0), suit(0)
{ 

}

Card::Card(int n) : value(n%13), suit(n%4)
{ 

}

Card::Card(int r, int s) : rank(r), suit(s)
{ 

}

Card::Card(int r, int s, int v) : rank(r), suit(s), value(v)
{ 

}

int Card::getRank() const
{
	return rank;
}

int Card::getValue() const
{ 
	return value;
}

int Card::getSuit() const
{ 
	return suit;
}

void Card::setRank(int r)
{ 
	rank = r;
}

void Card::setvalue(int v)
{ 
	value = v;
}

void Card::setSuit(int s)
{ 
	suit = s;
}

//Compare by value first then suit
int Card::compareTo(const Card& otherCard) const
{ 
	return otherCard.compareByValue + otherCard.compareBySuit;
}

int Card::compareByRank(const Card& otherCard) const
{ 
	return rank - otherCard.rank;
}

int Card::compareByValue(const Card& otherCard) const
{ 
	return value - otherCard.value;
}

int Card::compareBySuit(const Card& otherCard) const
{ 
	return suit - otherCard.suit;
}

string Card::display() const
{ 
	//string aRank[] ={"1", "2", "3", "4", "5", "6", "7", "8", "9","10","11","12","13"};
	string aValue[] ={"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	string aSuit[] ={"Spade", "Heart", "Diamond", "Club"};

	return /*"Rank: " + aRank[rank] + "\n" +*/ "Value: " + aValue[value] + "\n" + "Suit: " + aSuit[suit] + "\n";  
}