﻿#include<iostream>
//#include<math.h>
using namespace std;
using std::cout;



class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//					Constructors
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}




	//					Methods
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;

	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	/*double get_distance(Point A)const
	{
		double a = A.get_x() * A.get_x();
		double b = A.get_y() * A.get_y();
		double distance = sqrt(a + b);
		return distance;
	}*/
	/*double get_distance_b(Point B)const
	{
		double a = B.get_x() * B.get_x();
		double b = B.get_y() * B.get_y();
		double distance = sqrt(a + b);
		return distance;
	}*/


};

//#define STRUCT_POINT
//#define DISTANCE

double distance(Point A, Point B);


void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a; //Объявление переменной 'a' типа 'int'
	Point A; //Объявление переменной 'A' типа 'Point'
			// Объявление объекта 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;

	cout << sizeof(Point) << endl;
	cout << typeid(A).name() << endl;
#endif

#ifdef DISTANCE
	Point A;
	//double x = 2, y = 3;
	//cout << "Введите координаты точки :"; cin >> x >> y;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	//cout << B.get_x() << "\t" << B.get_y() << endl;

	//cout << "Расстояние от 0 до точки A = " << A.get_distance(A) << endl;
	//cout << "Расстояние от 0 до точки B = " << B.get_distance(B) << endl;
	cout << "Расстояние между точками A и B =  " << distance(A, B) << endl;
	cout << "Расстояние между точками B и A =  " << distance(B, A) << endl;
	cout << "Расстояние от точки А до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
#endif

	Point A;
	A.print();



}

double distance(Point A, Point B)
{
	/*double a = (B.get_x() - A.get_x()) * (B.get_x() - A.get_x());
	double b = (B.get_y() - A.get_y()) * (B.get_y() - A.get_y());
	double distance = sqrt(a + b);
	return distance;*/

	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}
