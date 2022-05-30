#pragma warning (disable:4326)
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

	int get_integer() const
	{
		return integer;
	}
	double get_numerator() const
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
	void set_numerator(double numerator)
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

	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}

	//explicit Fraction(double decimal)
	//{
	//	decimal += 1e-10;
	//	/*this->integer = 0;
	//	this->numerator = decimal;
	//	this->denominator = 1;*/
	//	integer = decimal;	//Сохраняем целую часть десятичной дроби
	//	decimal -= integer;	//Убираем сохраненную целую часть из десятичной дроби
	//	//Теперь нужно посчитать количество разрядов в дробной части:
	//	numerator = 0;
	//	int i = 0;
	//	int digit = 0;	//старший дробный разряд
	//	for (; decimal && i < 9; i++)
	//	{
	//		numerator *= 10;	//Освобождаем младшую цифру для следующего дробного разряда
	//		decimal *= 10;		//Сдвигаем запятую на один разряд вправо
	//		digit = decimal;
	//		numerator += digit;
	//		decimal -= digit;
	//	}
	//	denominator = pow(10, i);
	//	cout << "1argConstructor:" << this << endl;
	//}

	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "ConstructorDBL:\t" << this << endl;


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

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
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

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;

	}



	// Type-cast operators

	explicit operator int()const
	{
		return integer;
	}
	operator double()const
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

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		//numerator = numerator - integer * denominator;
		numerator %= denominator;
		/*if (numerator)
		{
			int nod = NOD(numerator, denominator);
			if (nod != 1 && nod != 0)
			{
				numerator /= nod;
				denominator /= nod;
			}
		}*/
		return *this;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}


	Fraction inverted()
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}

	Fraction& reduce()
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

	ostream& print(ostream& os)const
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
	).to_proper();
}


Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	);*/

	return left.to_improper() * right.inverted();

}




//bool operator==(Fraction left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	return (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());
//		
//}

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
	/*if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0) os << 0;
	return os;*/
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

//void operator>>(istream& is, Fraction& obj)
//{
//	char str[20] = {};
//	cin.getline(str, 20);
//	int length = StringLength(str);
//	bool slash = false;
//	bool space = false;
//	bool bracket = false;
//	int a;
//	int z;
//	int q;
//	for (int i = 0; i <= length; i++)
//	{
//		if (str[i] == '/')
//		{
//			slash = true;
//			a = i;
//		}
//		else if (str[i] == ' ')
//		{
//			space = true;
//			z = i;
//		}
//		else if (str[i] == '(')
//		{
//			bracket = true;
//			q = i;
//		}
//	}
//
//	if (slash == true && space == false && bracket == false)
//	{
//		int b = 0;
//		for (int i = 0; i < a; i++)
//		{
//			b += str[i] - 48;
//			b *= 10;
//		}
//		obj.set_numerator(b / 10);
//		int c = 0;
//		for (int i = a + 1; str[i] != 0; i++)
//		{
//			c += str[i] - 48;
//			c *= 10;
//		}
//		obj.set_denominator(c / 10);
//	}
//
//	if (slash == false && space == false && bracket == false)
//	{
//		int c = 0;
//		for (int i = 0; str[i] != 0; i++)
//		{
//			c += str[i] - 48;
//			c *= 10;
//		}
//		obj.set_integer(c / 10);
//	}
//
//	if (slash == true && space == false && bracket == true)
//	{
//		int c = 0;
//		for (int i = 0; i < q; i++)
//		{
//			c += str[i] - 48;
//			c *= 10;
//		}
//		obj.set_integer(c / 10);
//
//		int d = 0;
//		for (int i = q + 1; i < a; i++)
//		{
//			d += str[i] - 48;
//			d *= 10;
//		}
//		obj.set_numerator(d / 10);
//
//		int e = 0;
//		for (int i = a + 1; i < (length - 1); i++)
//		{
//			e += str[i] - 48;
//			e *= 10;
//		}
//		obj.set_denominator(e / 10);
//	}
//
//	if (slash == true && space == true && bracket == false)
//	{
//		int c = 0;
//		for (int i = 0; i < z; i++)
//		{
//			c += str[i] - 48;
//			c *= 10;
//		}
//		obj.set_integer(c / 10);
//
//		int d = 0;
//		for (int i = z + 1; i < a; i++)
//		{
//			d += str[i] - 48;
//			d *= 10;
//		}
//		obj.set_numerator(d / 10);
//
//		int e = 0;
//		for (int i = a + 1; i < length; i++)
//		{
//			e += str[i] - 48;
//			e *= 10;
//		}
//		obj.set_denominator(e / 10);
//	}
//}




//#define CONSTRUCTORS_CHECK
//#define DZ
//#define INCREMETN_CHECK
//#define TYPE_CONVERSIONS_BASE
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define DZ_2


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

#ifdef DZ
	Fraction A(3, 2, 5);
	Fraction B(4, 8, 9);
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
	cout << "E = A * B = "; E.print();
	cout << delimiter;

	Fraction F = A / B;
	//F.to_proper();
	cout << "F = A / B = ";
	(A / B).to_proper().print(); //F.print(); //(A / B).print(); 
	cout << delimiter;

	++E;
	cout << "Префексный инкремент E = "; E.print();
	E++;
	F = E++;
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
#endif // DZ


#ifdef INCREMETN_CHECK
	for (Fraction i(1, 2); i.get_integer() < 10; ++i)
	{
		i.print();
}
#endif // INCREMETN_CHECK

#ifdef TYPE_CONVERSIONS_BASE

	/*Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;*/


	cout << typeid(7 / .2).name();
	int a = 2; //No conversion
	double b = 3; //Conversion from less to more
	int c = b; //Conversion more to less without data loss
	int d = 5.5; //Conversion more to less with data loss

#endif // TYPE_CONVERSIONS_BASE


#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = 5; // Conversion fron int to Fraction
	cout << A << endl;
	Fraction B;
	cout << "\n-----------------------------\n";
	B = (Fraction)8;
	cout << "\n-----------------------------\n";
	cout << B << endl;
#endif // !CONVERSIONS_FROM_OTHER_TO_CLASS


#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	int a = A;
	cout << a << endl;

	double b = A;
	cout << b << endl;

	cout << (Fraction(1, 2) == Fraction(5, 11)) << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER


#ifdef DZ_2
	Fraction A = 2.75;
	;
	/*for (int i = 0; i < 2; i++)
	{
		A.set_numerator(A.get_numerator() * 10);
		A.set_denominator(A.get_denominator() * 10);
	}*/
	cout << A << endl;

#endif // DZ_2


	Fraction A = 2.75;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
	cout << (double)A << endl;
	
	/*A.set_integer(123);
	A.get_numerator(55);
	A.get_denominator(77);*/

	A(52, 85, 86);
	cout << A << endl;




}