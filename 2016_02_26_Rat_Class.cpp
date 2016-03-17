#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/*Define Rat class*/
class Rat
{
private:
	int num;
	int denom;

public: /*Public functions are accessible anywhere*/
	void input();
	void output() const;
	const Rat add(const Rat & r2) const;
	const Rat sub(const Rat & r2) const;
	const Rat mult(const Rat & r2) const;
	const Rat div(const Rat & r2) const;
	const Rat reduce() const;

	/*Accessor functions get value of private members*/
	int getNum() const;
	int getDenom() const;

	/*Mutator functions set value of private members*/
	void setNum(int n);
	void setDenom(int d);

	/*Constructor to initialize class private members' values*/
	Rat(int n, int d); 
	Rat(int n); /*n here is an integer*/

	/*Constructor to set default class private members' values*/
	Rat(); 
};

int compare(const Rat & r1, const Rat & r2); 
int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
	/*Declare class variables*/
	/*Call Constructor Rat()*/
	Rat r1, 
		r2,
		r5(2) /*an integer*/; 

	/*Declare local variables*/
	int n1, n2, n3, n4,
		d1, d2, d3, d4;

	r5.output();

	r1.input();
	r2.input();

	r1.output();
	r2.output();

	cout << compare(r1, r2) << endl;

	Rat sum = r1.add(r2);
	Rat diff = r1.sub(r2);
	Rat prod = r1.mult(r2);
	Rat quot = r1.div(r2);

	cout << "sum is: ";
	sum.output();

	cout << "diff is: ";
	diff.output();

	cout << "prod is: ";
	prod.output();

	cout << "quot is: ";
	quot.output();

	cout << "Numerator of Rat 1: " << r1.getNum() << endl;
	cout << "Denominator of Rat 1: " << r1.getDenom() << endl;
	cout << "Numerator of Rat 2: " << r2.getNum() << endl;
	cout << "Denominator of Rat 2: " << r2.getDenom() << endl;

	cout << "Set Rational 1 num: ";
	cin >> n1;
	cout << "Set Rational 1 denom: ";
	cin >> d1;
	cout << "Set Rational 2 num: ";
	cin >> n2;
	cout << "Set Rational 2 denom: ";
	cin >> d2;

	r1.setNum(n1);
	r1.setDenom(d1);
	r2.setNum(n2);
	r2.setDenom(d2);

	r1.output();
	r2.output();

	cout << "Set Rational 3 num: ";
	cin >> n3;
	cout << "Set Rational 3 denom: ";
	cin >> d3;
	cout << "Set Rational 4 num: ";
	cin >> n4;
	cout << "Set Rational 4 denom: ";
	cin >> d4;

	/*Call Constructor Rat(int n, int d)*/
	Rat r3(n3,d3);
	Rat r4(n4,d4);

	r3.output();
	r4.output();

	return 0;
}

/*Constructor with 1 argument represents an integer*/
Rat::Rat(int n) : num(n), denom(1)
{
}

/*Constructor to set default class private members' values*/
Rat::Rat() : num(0), denom(1) /*Initialize fields inside a class instead of assign them*/
{
}

/*Constructor to initialize class private members' values*/
Rat::Rat(int n, int d) : num(n), denom(d)
{
	if(denom == 0)
	{
		cout << "Error: Denominator cannot be zero." << endl;
		exit(1);
	}
	else if(denom < 0)
	{
		denom = -denom;
		num = -num;
	}
}

void Rat::setNum(int n)
{
	num = n;
}

void Rat::setDenom(int d)
{
	denom = d;

	if(denom == 0)
	{
		cout << "Error: Denominator cannot be zero." << endl;
		exit(1);
	}
	else if(denom < 0)
	{
		denom = -denom;
		num = -num;
	}
}

int Rat::getNum() const
{
	return num;
}

int Rat::getDenom() const
{
	return denom;
}

/*returns negative if r1 < r2, positive if r1 > r2, 0 if r1 == r2*/
int compare(const Rat & r1, const Rat & r2)
{
	return (r1.getNum() * r2.getDenom()) - (r2.getNum() * r1.getDenom());
}

const Rat Rat::reduce() const
{
	Rat rr;
	int d = abs(gcd(num, denom));

	if(num == 0)
	{
		rr.num = 0;
		rr.denom = d;
		return rr;
	}

	rr.num = num / d;
	rr.denom = denom / d;

	if(rr.num < 0 && rr.denom < 0) /*Check if both top and bottom are < 0. Ex: -1/-2 is 1/2*/
	{
		rr.num = -rr.num;
		rr.denom = -rr.denom;
	}

	return rr;
}

const Rat Rat::div(const Rat & r2) const 
{
	Rat r;

	if(r2.denom == 0)
	{
		cout << "Error. Cannot divide by zero." << endl;
		exit(1);
	}

	r.num = num * r2.denom;
	r.denom = denom * r2.num;

	return r.reduce();
}

const Rat Rat::mult(const Rat & r2) const
{
	Rat r;

	r.num = num * r2.num;
	r.denom = denom * r2.denom;

	return r.reduce();
}

const Rat Rat::sub(const Rat & r2) const
{
	Rat r; 
	int ell = lcm(denom, r2.denom);

	r.denom = ell;
	r.num = (num * (ell / denom)) - (r2.num * (ell / r2.denom));

	return r.reduce();
}

const Rat Rat::add(const Rat & r2) const
{
	Rat r;
	int ell = lcm(denom, r2.denom);

	r.denom = ell;
	r.num = (num * (ell / denom)) + (r2.num * (ell / r2.denom));

	return r.reduce();
}

void Rat::output() const
{
	cout << num<< "/" << denom << endl;
}

void Rat::input()
{
	cout << "Numerator:";
	cin >> num;
	cout << "Denominator:";
	cin >> denom;

	if(denom == 0)
	{
		cout << "Error: Denominator cannot be zero." << endl;
		exit(1);
	}
	else if(denom < 0)
	{
		denom = -denom;
		num = -num;
	}
}

int gcd(int a, int b)
{
	while(b != 0)
	{
		int c = a;
		a = b;
		b = c % b;
	}

	return a;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a,b);
}