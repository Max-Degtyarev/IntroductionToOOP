#include<iostream>
//#include<math.h>
using namespace std;
using std::cout;


#define delimiter "\n---------------------------------------\n"

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
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor: \t" << this << endl;

	}*/

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;

	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t" << this << endl;

	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	//					Operators
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssingment:\t\t" << this << endl;
		return *this;

	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;

	}



	//					Methods
	double distance(const Point& other)
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

double distance(const Point& A, const Point& B);
double operator-(const Point& left, const Point& right);
Point operator+(const Point& left, const Point& right);

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2

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
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B =  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A =  " << distance(B, A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
#endif


#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();
	
	Point B = 5;
	B.print();

	Point C(8);
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D; //Copy constructor;
	E.print();

	Point F(D); // Copy constructor;
	F.print();
#endif

#ifdef ASSIGNMENT_CHECK_1
	Point A(2, 3);
	Point B = A; //CopyConstructor
	Point C; // Default constructor
	C = B; // CopyAssingment (присваивание)
#endif

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
#endif

	int a = 2;
	int b = 3;
	int c = a + b;



	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();

	Point C = A + B;
	C.print();

	Point D = C++;
	C.print();
	D.print();


	
	cout << A - B << endl; //Неявный вызов оператора - для объектов класса Point
	cout << operator-(A, B) << endl; // Явный вызов


}




Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;

}


double operator-(const Point& left, const Point& right)
{
	/*double x_distance = left.get_x() - right.get_x();
	double y_distance = left.get_y() - right.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);*/

	return sqrt(pow(left.get_x() - right.get_x(), 2) + pow(left.get_y() - right.get_y(), 2));
}




double distance(const Point& A, const Point& B)
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
