#include<iostream>
using namespace std;

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


class String;
String operator+(const String& left, const String& right);

class String
{
	int size; // Размер строки в байтах
	char* str; // Укзатель на строку
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	// Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;

	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t" << this << endl;

	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];

		}
		cout << "CopyConstructor:" << this << endl;
		
	}

	String(String&& other)
	{
		//MoveConstructor выполняет Shellow copy
		this->size = other.size;
		this->str = other.str; //Копируем адрес памяти
		other.size = 0;
		other.str = nullptr; //Зануляем адрес памяти в другом объекте
		cout << "MoveConstructor:" << this << endl;
	}





	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}


	// Operators

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
			cout << "CopyAssingment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssingment:\t" << this << endl;
		return *this;

	}


	String& operator+=(const String& other)
	{
		//return *this = *this + " " + other;
		

		String cat(this->size + other.size - 1);
		for (int i = 0; i < this->size; i++)
		{
			cat[i] = this->str[i];
		}
		
		for (int i = 0; i < other.size; i++)
		{
			cat[i + this->size - 1] = other[i];
		}
		*this = cat;
		return *this;
	}





	char operator[](int i) const
	{
		return str[i];

	}
	char& operator[](int i)
	{
		return str[i];

	}



	// Methods

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;

	}


};

//Конкатенация строк
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	}
	// Правую строку копируем со смещением вправо на размер левой строки
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return cat;
}


ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();

}


istream& operator>>(istream& is, String& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	cin.getline(buffer, SIZE);
	obj = buffer;
	return is;

}




//#define CONSTRUCTORS_CHECK
//#define MOVE_METHODS_CHECK

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
	String str4;
	cout << "Введите строку: "; cin >> str4;
	cout << str4 << endl;
#endif // MOVE_METHODS_CHECK

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


	

	





}

