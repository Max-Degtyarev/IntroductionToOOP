#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------------\n"


class Fraction;
Fraction operator+(const Fraction& left, const Fraction& right);

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

	// Constructors

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
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
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;

	}

	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;

	}

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}


		
	// Methods

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

	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		if (numerator)
		{
			int nod = NOD(numerator, denominator);
			if (nod != 1)
			{
				numerator /= nod;
				denominator /= nod;
			}
		}
	}

	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}


	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
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
	if (nod_2 != 1 && nod_2 != 0)
	{
		result.set_numerator(result.get_numerator() / nod_2);
		result.set_denominator(result.get_denominator() / nod_2);
	}
	return result;
}



Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
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

	result.set_numerator(fraction_1.get_numerator() - fraction_2.get_numerator());
	result.set_denominator(fraction_1.get_denominator());

	if (result.get_numerator() >= result.get_denominator())
	{
		result.set_integer(result.get_integer() + result.get_numerator() / result.get_denominator());
		result.set_numerator(result.get_numerator() % result.get_denominator());
	}

	if (result.get_numerator() < 0 && (result.get_numerator() - result.get_numerator() * 2) >= result.get_denominator())
	{
		result.set_integer(result.get_integer() + (result.get_numerator() - result.get_numerator() * 2) / result.get_denominator());
		result.set_numerator((result.get_numerator() - result.get_numerator() * 2) % result.get_denominator());
		result.set_integer(result.get_integer() - result.get_integer() * 2);
	}

	if (result.get_numerator() < 0)
	{
		int nod_3 = NOD(result.get_numerator() - result.get_numerator() * 2, result.get_denominator());
		if (nod_3 != 1 && nod_3 != 0)
		{
			result.set_numerator(result.get_numerator() / nod_3);
			result.set_denominator(result.get_denominator() / nod_3);
		}
	}
	else
	{
		int nod_3 = NOD(result.get_numerator(), result.get_denominator());
		if (nod_3 != 1 && nod_3 != 0)
		{
			result.set_numerator(result.get_numerator() / nod_3);
			result.set_denominator(result.get_denominator() / nod_3);
		}
	}

	return result;
}


Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()

	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}


Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	);


}



//Fraction& operator+=(Fraction& left, Fraction& right)
//{
//	return left = operator+(left, right);
//}

Fraction& operator-=(Fraction& left, Fraction& right)
{
	return left = operator-(left, right);
}

Fraction& operator*=(Fraction& left, Fraction& right)
{
	return left = operator*(left, right);
}

Fraction& operator/=(Fraction& left, Fraction& right)
{
	return left = operator/(left, right);
}

bool operator==(const Fraction& left, const Fraction& right)
{
	if ((left.get_integer() > right.get_integer()) || (left.get_integer() < right.get_integer()))return false;
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
	return (fraction_1.get_numerator() == fraction_2.get_numerator());
}


bool operator!=(const Fraction& left, const Fraction& right)
{
	if ((left.get_integer() > right.get_integer()) || (left.get_integer() < right.get_integer()))return true;
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
	return (fraction_1.get_numerator() != fraction_2.get_numerator());
}


bool operator>(const Fraction& left, const Fraction& right)
{
	if (left.get_integer() > right.get_integer())return true;
	if (left.get_integer() < right.get_integer())return false;
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
	return (fraction_1.get_numerator() > fraction_2.get_numerator());
}


bool operator<(const Fraction& left, const Fraction& right)
{
	if (left.get_integer() < right.get_integer())return true;
	if (left.get_integer() > right.get_integer())return false;
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
	return (fraction_1.get_numerator() < fraction_2.get_numerator());
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	if (left.get_integer() > right.get_integer())return true;
	if (left.get_integer() < right.get_integer())return false;
	else
	{
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
		return (fraction_1.get_numerator() >= fraction_2.get_numerator());
	}
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	if (left.get_integer() < right.get_integer())return true;
	if (left.get_integer() > right.get_integer())return false;
	else
	{
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
		return (fraction_1.get_numerator() <= fraction_2.get_numerator());
	}
}


//#define CONSTRUCTORS_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;
	E.print();

	A = D;
	A.print();
#endif CONSTRUCTORS_CHECK

	Fraction A(1, 1, 2);
	Fraction B(3, 2);
	cout << "Дробь А = "; A.print();
	cout << "Дробь В = "; B.print();
	cout << delimiter;

	Fraction C = A + B;
	cout << "C = A + B = "; C.print();
	cout << delimiter;

	Fraction D = A - B;
	cout << "D = A - B = "; D.print();
	cout << delimiter;

	Fraction E = A * B;
	E.to_proper();
	cout << "E = A * B = "; E.print();
	cout << delimiter;

	Fraction F = A / B;
	F.to_proper();
	cout << "F = A / B = "; F.print(); //(A / B).print();
	cout << delimiter;

	++E;
	cout << "Префексный инкремент E = "; E.print();
	E++;
	cout << "Постфиксный инкремент E = "; E.print();
	cout << delimiter;

	--F;
	cout << "Префексный декремент F = "; F.print();
	F--;
	cout << "Постфиксный декремент F = "; F.print();
	cout << delimiter;

	Fraction G(1, 1, 2);
	cout << "G = "; G.print();
	G += C;
	cout << "G += C = "; G.print();
	cout << delimiter;

	Fraction H(2, 3, 5);
	cout << "H = "; H.print();
	H -= B;
	cout << "H -= B = "; H.print();
	cout << delimiter;

	Fraction I(3, 4, 7);
	cout << "I = "; I.print();
	I *= A;
	cout << "I *= A = ";
	I.to_proper();
	I.print();
	cout << delimiter;

	Fraction J(2, 5, 6);
	cout << "J = "; J.print();
	J /= A;
	cout << "J /= A = ";
	J.to_proper();
	J.print();
	cout << delimiter;


	if (A == B)
	{
		cout << "А и В равны" << endl;
	}
	else cout << "А и В не равны" << endl;

	if (A != B)
	{
		cout << "А и В не равны" << endl;
	}
	else cout << "А и В равны" << endl;


	if (A > B)
	{
		cout << "А больше В" << endl;
	}
	else cout << "А не больше В" << endl;


	if (A < B)
	{
		cout << "А меньше В" << endl;
	}
	else cout << "А не меньше В" << endl;


	if (A >= B)
	{
		cout << "А больше или равно В" << endl;
	}
	else cout << "А не больше или равно В" << endl;

	if (A <= B)
	{
		cout << "А меньше или равно В" << endl;
	}
	else cout << "А не меньше или равно В" << endl;







}
