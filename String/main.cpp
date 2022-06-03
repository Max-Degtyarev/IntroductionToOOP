

#include"String.h"



//#define CONSTRUCTORS_CHECK
#define MOVE_METHODS_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1; // Default Constructor
	str1.print();

	String str2(5); // explicit single-argument Constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3;
	str4.print();

	String str5;
	str5 = str4;
	str5.print();

#endif // CONSTRUCTORS_CHECK

#ifdef MOVE_METHODS_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
	String str2("World");
	cout << str2 << endl;
	//String str3 = str1 + str2; //Move Constructor
	String str3;
	str3 = str1 + str2;
	//str3.print();
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
	String str4 = str3;
	//cout << "Введите строку: "; cin >> str4;
	cout << str4 << endl;
#endif // MOVE_METHODS_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;
	str1.print();
	String str2(55);
	String str3 = "Hello";
	String str4 = str3;
	String str5;
	str5 = str4;
	str5.print();
	String str6(); // Здесь НЕ вызывается никаких конструкторов
					// Здесь объявляется функция str6()
	String str7{}; // Явный вызов конструктора по умолчанию
	str7.print();

#endif // CALLING CONSTRUCTORS


	
	








}

