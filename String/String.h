#pragma once
#include<iostream>
using namespace std;
using std::cout;

//class String
//{
//	//int SIZE;
//	char* str;
//
//public:
//	//int get_SIZE()const
//	//{
//	//	return SIZE;
//	//}
//	//void set_SIZE(int SIZE)
//	//{
//	//	this->SIZE = SIZE;
//	//}
//
//
//	int StringLength(const char str[])
//	{
//		int i = 0;
//		for (; str[i] != 0; i++);
//		return i;
//	}
//
//
//
//	String()
//	{
//		const int SIZE = 80;
//		char str [SIZE] = {};
//		cout << "Constructor_1" << endl;
//	}
//
//
//	String(int)
//	{
//		const int SIZE = 8;
//		char str[SIZE] = {};
//		cout << "Constructor_2" << endl;
//
//	}
//
//	
//
//	String(const char* str)
//	{
//		int length = StringLength(str);
//		this->str = new char[length];
//		for (int i = 0; i < length; i++)
//		{
//			this->str[i] = str[i];
//
//		}
//		cout << "Constructor_3" << endl;
//		
//	}
//
//
//	~String()
//	{
//		delete[] this->str;
//		cout << "Destructor" << endl;
//	}
//
//	String& operator=(const String& other)
//	{
//		this->str = other.str;
//		return *this;
//
//	}
//
//	ostream& print(ostream& os)const
//	{
//		os << str << endl;
//		return os;
//
//
//	}
//
//	
//};
//
//
//ostream& operator<<(ostream& os, const String& obj)
//{
//	return obj.print(os);
//	
//}
//
//
//
//
//void main()
//{
//	setlocale(LC_ALL, "");
//
//	String str1;
//	String str2(8);
//	String str3 = "Hello";
//	cout << str3;
//	String str4 = "World";
//	cout << str4;
//
//
//}


//////////////////////////////////////////////////////////
/////////////        Class declaration     ///////////////
//////////////////////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size; // Размер строки в байтах
	char* str; // Укзатель на строку
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	// Constructors
	explicit String(int size = 80);

	String(const char* str);

	String(const String& other);

	String(String&& other);

	~String();


	// Operators

	String& operator=(const String& other);

	String& operator=(String&& other);


	String& operator+=(const String& other);





	char operator[](int i) const;
	char& operator[](int i);



	// Methods

	void print()const;


};


String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);








//////////////////////////////////////////////////////////
/////////////        Class declaration end       /////////
//////////////////////////////////////////////////////////