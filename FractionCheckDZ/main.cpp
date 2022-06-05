#pragma warning (disable:4326)

#include"Fraction.h"


//#define CONSTRUCTORS_CHECK
//#define DZ
//#define INCREMETN_CHECK
//#define TYPE_CONVERSIONS_BASE
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define DZ_2
#define CLASS_WORK


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
	/*for (int i = 0; i < 2; i++)
	{
		A.set_numerator(A.get_numerator() * 10);
		A.set_denominator(A.get_denominator() * 10);
	}*/
	cout << A << endl;

#endif // DZ_2


#ifdef CLASS_WORK
	Fraction A = 2.75;
	cout << A << endl;
	Fraction B;
	cout << "Введите простую дробь: "; cin >> B;
	cout << B << endl;
	cout << (double)A << endl;

	/*A.set_integer(123);
	A.get_numerator(55);
	A.get_denominator(77);*/

	//A(52, 85, 86);
	//cout << A << endl;  
#endif // CLASS_WORK





}