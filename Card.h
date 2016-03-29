#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
private:
	int rank; //    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,   11,    12,   13
	int value; // Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King
	int suit; // Spade, Heart, Diamond, Club

public:
	Card();
	Card(int num);
	Card(int rank, int suit);
	Card(int rank, int suit, int value);

	int getRank() const;
	int getValue() const;
	int getSuit() const;

	void setRank(int rank);
	void setvalue(int value);
	void setSuit(int suit);

	int compareTo(const Card& otherCard) const;
	int compareByRank(const Card& otherCard) const;
	int compareByValue(const Card& otherCard) const;
	int compareBySuit(const Card& otherCard) const;

	string display() const;
};
#endif