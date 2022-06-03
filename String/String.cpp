



#include"String.h"

//--------------------------------------------------//


//////////////////////////////////////////////////////////
/////////////        Class definition      ///////////////
//////////////////////////////////////////////////////////


int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

// Constructors
String::String(int size) :size(size), str(new char [size] {})
{
	//this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;

}

String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t" << this << endl;

}

String::String(const String& other) : String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	/*for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];

	}*/
	cout << "CopyConstructor:" << this << endl;

}

String::String(String&& other) :size(other.size), str(other.str)
{
	//MoveConstructor выполняет Shallow copy
	//this->size = other.size;
	//this->str = other.str; //Копируем адрес памяти
	other.size = 0;
	other.str = nullptr; //Зануляем адрес памяти в другом объекте
	cout << "MoveConstructor:" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}



// Operators

String& String::operator=(const String& other)
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

String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssingment:\t" << this << endl;
	return *this;

}


String& String::operator+=(const String& other)
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





char String::operator[](int i) const
{
	return str[i];

}
char& String::operator[](int i)
{
	return str[i];

}



// Methods

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;

}




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


//////////////////////////////////////////////////////////
/////////////        Class definition end      ///////////
//////////////////////////////////////////////////////////