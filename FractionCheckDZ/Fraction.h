#pragma once
#include<iostream>
using namespace std;
using std::cout;


#define delimiter "\n------------------------------------------\n"


class Fraction;
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:

	int get_integer() const;
	double get_numerator() const;
	int get_denominator() const;

	void set_integer(int integer);
	void set_numerator(double numerator);
	void set_denominator(int denominator);

	// Constructors

	Fraction();

	explicit Fraction(int integer);


	Fraction(double decimal);




	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);

	Fraction(const Fraction& other);

	~Fraction();


	// Operators
	Fraction& operator=(const Fraction& other);

	Fraction& operator+=(const Fraction& other);

	Fraction& operator-=(const Fraction& other);

	Fraction& operator*=(const Fraction& other);

	Fraction& operator/=(const Fraction& other);




	Fraction& operator++();
	Fraction operator++(int);

	Fraction& operator--();
	Fraction operator--(int);

	Fraction& operator()(int integer, int numerator, int denominator);



	// Type-cast operators

	explicit operator int()const;
	operator double()const;




	// Methods

	int NOD(int a, int b);

	Fraction& to_proper();

	Fraction& to_improper();


	Fraction inverted();

	Fraction& reduce();



	void print()const;

	ostream& print(ostream& os)const;

};


istream& operator>>(istream& is, Fraction& obj);