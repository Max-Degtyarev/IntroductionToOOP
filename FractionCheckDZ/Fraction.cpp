#include"Fraction.h"


int Fraction::get_integer() const
{
	return integer;
}
double Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}

void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(double numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

// Constructors

Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefConstructor:\t" << this << endl;
}

Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1argConstructor:" << this << endl;
}


Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
	cout << "ConstructorDBL:\t" << this << endl;


}



Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constructor:\t" << this << endl;
}

Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:" << this << endl;
}

Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}


// Operators
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}



Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;

}

Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;

}

Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;

}



// Type-cast operators

Fraction::operator int()const
{
	return integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
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

Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}

Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}


Fraction Fraction::inverted()
{
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;
}

Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		less = numerator;
		more = denominator;
	}

	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; // GCD - greatest common diviser
	if (GCD == 0)return *this;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}



void Fraction::print()const
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

ostream& Fraction::print(ostream& os)const
{
	if (integer) os << integer;
	if (numerator)
	{
		if (integer)os << "(";
		os << numerator << "/" << denominator;
		if (integer)os << ")";
	}
	if (integer == 0 && numerator == 0)os << 0;
	return os;
}












//int NOD(int a, int b)
//{
//	int nod = 0;
//	for (int i = (a > b ? b : a); i > 0; i--)
//	{
//		if (a % i == 0 && b % i == 0)
//		{
//			nod = i;
//			break;
//		}
//	}
//	return nod;
//}


Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}



Fraction operator-(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}


Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}


Fraction operator/(Fraction left, Fraction right)
{


	return left.to_improper() * right.inverted();

}






bool operator==(const Fraction& left, const Fraction& right)
{
	return (double)left == (double)right;

}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}



bool operator>(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() >
		right.to_improper().get_numerator() * left.get_denominator();
}


bool operator<(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() <
		right.to_improper().get_numerator() * left.get_denominator();
}


bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}




ostream& operator<<(ostream& os, const Fraction& obj)
{
	return obj.print(os);

}

istream& operator>>(istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//cin >> buffer;
	cin.getline(buffer, SIZE);
	char delimiters[] = "()/ ";
	char* sz_numbers[3] = {}; //Массив строк, который будет хранить числа в строковом формате
	//sz - string zero (строка заканчивающася нулем)
	int i = 0; // Счетчик цикла
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		sz_numbers[i++] = pch;
	}
	obj = Fraction(); //Обнуляем объект (сбрасываем его в объект по умолчанию)
	switch (i)
	{
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
		// atoi() - ASCII-string to integer - переводит строку в число
	case 2:
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1]));
		break;
	case 3:
		obj.set_integer(atoi(sz_numbers[0]));
		obj.set_numerator(atoi(sz_numbers[1]));
		obj.set_denominator(atoi(sz_numbers[2]));

	}
	return is;


}



int StringLength(const char str[])
{
	int i = 0;
	for (; str[i] != 0; i++);
	return i;
}
