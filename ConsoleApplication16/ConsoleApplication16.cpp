#include <iostream>
using namespace std;
class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		void init()
		{
			cout << "Type a numerator of a fraction" << endl;
			cin >> numerator;
			cout << "Type a denominator of a fraction" << endl;
			do
			{
				cin >> denominator;
				if (!denominator)
					cout << "Denominator can`t be 0" << endl;
			} while (!denominator);
			
		}
		void get_fraction()
		{
			if (numerator == 1 && denominator == 1)
				cout << "1" << endl;
			else if (numerator == 0)
				cout << "0" << endl;
			else
				cout << numerator << "/" << denominator << endl;
		}
		void set_num(int value)
		{
			numerator = value;
		}
		void set_denom(int value)
		{
			if (value != 0)
				denominator = value;
		}
		int get_num()
		{
			return numerator;
		}
		int get_denom()
		{
			return denominator;
		}
		Fraction sum(Fraction b)
		{
				Fraction rez;
				rez.denominator = denominator*b.denominator;
				rez.numerator = (numerator * (rez.denominator / denominator)) + (b.numerator * (rez.denominator / b.denominator));
				return rez;
		}
		Fraction substraction(Fraction b)
		{
			Fraction rez;
			rez.denominator = denominator * b.denominator;
			rez.numerator = (numerator * (rez.denominator / denominator)) - (b.numerator * (rez.denominator / b.denominator));
			return rez;
		}
		Fraction multiplication(Fraction b)
		{
			Fraction rez;
			rez.numerator = numerator * b.numerator;
			rez.denominator = denominator * b.denominator;
			return rez;
		}
		Fraction division(Fraction b)
		{
			Fraction rez;
			rez.numerator = numerator * b.denominator;
			rez.denominator = denominator * b.numerator;
			return rez;
		}
		void reduction()
		{
			if (numerator != 0)
			{
				if ((denominator >= numerator) && (denominator % numerator == 0))
				{
					denominator = denominator / numerator;
					numerator = numerator / numerator;
				}
			}
			
			else
				return;
		}
};
int main()
{
	Fraction a, b;
	a.init();
	a.set_num(5);
	a.set_denom(10);
	b.set_num(3);
	b.set_denom(6);
	Fraction c = a.sum(b);
	c.reduction();
	c.get_fraction();
	c = a.substraction(b);
	c.reduction();
	c.get_fraction();
	c = a.multiplication(b);
	c.reduction();
	c.get_fraction();
	c = a.division(b);
	c.reduction();
	c.get_fraction();
	return 0;
}
