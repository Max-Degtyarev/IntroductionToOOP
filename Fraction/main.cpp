#include<iostream>
using namespace std;


#define delimiter "\n-----------------------------------------\n"


class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}


	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default Constructor" << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Constructor" << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Assignment" << endl;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;

	}

	
	void Print()
	{
		if (integer != 0)cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
		else cout << numerator << "/" << denominator << endl;
	}

};

int NOD(int a, int b)
{
	int nod = 0;
	for (int i = (a > b ? b : a); i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			nod = i;
			break;
		}
	}
	return nod;
}


Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	Fraction fraction_1;
	Fraction fraction_2;
	int a = left.get_denominator();
	int b = right.get_denominator();
	int nod = NOD(a, b);
	int nok = (a * b) / nod;
	int add_1 = nok / a;
	int add_2 = nok / b;
	fraction_1.set_numerator(left.get_numerator() * add_1);
	fraction_1.set_denominator(left.get_denominator() * add_1);
	fraction_2.set_numerator(right.get_numerator() * add_2);
	fraction_2.set_denominator(right.get_denominator() * add_2);

	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(fraction_1.get_numerator() + fraction_2.get_numerator());
	result.set_denominator(fraction_1.get_denominator());

	if (result.get_numerator() >= result.get_denominator())
	{
		result.set_integer(result.get_integer() + result.get_numerator() / result.get_denominator());
		result.set_numerator(result.get_numerator() % result.get_denominator());
	}
	int nod_2 = NOD(result.get_numerator(), result.get_denominator());
	if (nod_2 != 1)
	{
		result.set_numerator(result.get_numerator() / nod_2);
		result.set_denominator(result.get_denominator() / nod_2);

	}
	return result;



	//if (left.get_denominator() == right.get_denominator())
	//{
	//	result.set_integer(left.get_integer() + right.get_integer());
	//	result.set_numerator(left.get_numerator() + right.get_numerator());
	//	result.set_denominator(left.get_denominator());

	//	if (result.get_numerator() >= result.get_denominator())
	//	{
	//		result.set_integer(result.get_integer() + result.get_numerator() / result.get_denominator());
	//		result.set_numerator(result.get_numerator() % result.get_denominator());
	//	}
	//	if (result.get_denominator() % result.get_numerator() == 0)
	//	{
	//		int nod = result.get_numerator();
	//		result.set_numerator(result.get_numerator() / nod);
	//		result.set_denominator(result.get_denominator() / nod);
	//	}
	//}

	//if (left.get_denominator() != right.get_denominator())
	//{
	//	if ((left.get_denominator() % 2 != 0) || (right.get_denominator() % 2 != 0))
	//	{
	//		Fraction fraction_1;
	//		Fraction fraction_2;
	//		fraction_1.set_numerator(left.get_numerator() * right.get_denominator());
	//		fraction_1.set_denominator(left.get_denominator() * right.get_denominator());
	//		fraction_2.set_numerator(left.get_denominator() * right.get_numerator());
	//		fraction_2.set_denominator(left.get_denominator() * right.get_denominator());
	//		result.set_integer(fraction_1.get_integer() + fraction_2.get_integer());
	//		result.set_numerator(fraction_1.get_numerator() + fraction_2.get_numerator());
	//		result.set_denominator(fraction_1.get_denominator());

	//		if (result.get_numerator() >= result.get_denominator())
	//		{
	//			result.set_integer(result.get_integer() + result.get_numerator() / result.get_denominator());
	//			result.set_numerator(result.get_numerator() % result.get_denominator());
	//		}
	//		if (result.get_denominator() % result.get_numerator() == 0)
	//		{
	//			int nod = result.get_numerator();
	//			result.set_numerator(result.get_numerator() / nod);
	//			result.set_denominator(result.get_denominator() / nod);
	//		}

	//	}


	//	if ((left.get_denominator() % 2 == 0) && (right.get_denominator() % 2 == 0))
	//	{
	//		Fraction fraction_1;
	//		Fraction fraction_2;
	//		int a = left.get_denominator();
	//		int b = right.get_denominator();
	//		int nod = NOD(a, b);
	//		int nok = (a * b) / nod;
	//		int add_1 = nok / a;
	//		int add_2 = nok / b;
	//		fraction_1.set_numerator(left.get_numerator() * add_1);
	//		fraction_1.set_denominator(left.get_denominator() * add_1);
	//		fraction_2.set_numerator(right.get_numerator() * add_2);
	//		fraction_2.set_denominator(right.get_denominator() * add_2);
	//		result.set_integer(fraction_1.get_integer() + fraction_2.get_integer());
	//		result.set_numerator(fraction_1.get_numerator() + fraction_2.get_numerator());
	//		result.set_denominator(fraction_1.get_denominator());

	//		if (result.get_numerator() >= result.get_denominator())
	//		{
	//			result.set_integer(result.get_integer() + result.get_numerator() / result.get_denominator());
	//			result.set_numerator(result.get_numerator() % result.get_denominator());
	//		}
	//		if (result.get_denominator() % result.get_numerator() == 0)
	//		{
	//			int nod = result.get_numerator();
	//			result.set_numerator(result.get_numerator() / nod);
	//			result.set_denominator(result.get_denominator() / nod);
	//		}

	//	}

	//}

	//return result;



}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;

}








void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	//A.set_integer(2);
	A.set_numerator(3);
	A.set_denominator(4);
	cout << "Дробь А = "; A.Print();

	Fraction B(5, 8);
	cout << "Дробь B = "; B.Print();

	cout << delimiter << endl;

	Fraction C = A + B;
	cout << "C = A + B = "; C.Print();

	cout << delimiter << endl;

	Fraction D = C;
	cout << "Копирование = "; D.Print();

	cout << delimiter << endl;

	Fraction E;
	E = D;
	cout << "Присваивание = "; E.Print();

	cout << delimiter << endl;

	E++;
	cout << "Инкремент = "; E.Print();

	cout << delimiter << endl;

	Fraction F = A * B;
	cout << "Умножение = "; F.Print();

	cout << delimiter << endl;

	Fraction G = A / B;
	cout << "Деление = "; G.Print();

	



}


