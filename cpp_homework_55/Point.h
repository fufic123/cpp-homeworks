#include <iostream>
using namespace std;

template<class T>
class Point;

template<class T>
class Point {
private:
	T X;
	T Y;
	T Z;

public:
	Point();
	Point(T x, T y, T z);

	Point<T> operator + (const Point<T>& obj);
	Point<T> operator + (T n);

	Point<T>& operator += (const Point<T>& obj);
	Point<T>& operator += (T n);

	Point<T>& operator = (T n);

	template<class U>
	friend ostream& operator << (ostream & o, const Point<U>& obj);

	T GetX() const;
	T GetY() const;
	T GetZ() const;

	void SetX(T x);
	void SetY(T y);
	void SetZ(T z);
};

template<class T>
Point<T>::Point() { X = Y = Z = 0; }

template<class T>
Point<T>::Point(T x, T y, T z): X(x), Y(y), Z(z) {}

template<class T>
Point<T> Point<T>::operator + (const Point<T>& obj) { return Point<T>(X + obj.X, Y + obj.Y, Z + obj.Z); }

template<class T>
Point<T> Point<T>::operator + (T num) { return Point<T>(num, num, num); }

template<class T>
Point<T>& Point<T>::operator += (const Point<T>& obj) {
	*this = Point<T>(X + obj.X, Y + obj.Y, Z + obj.Z );
	return *this;
}

template<class T>
Point<T>& Point<T>::operator += (T num) {
	*this = Point<T>(num, num, num);
	return *this;
}

template<class T>
Point<T>& Point<T>::operator = (T num) {
	*this = Point<T>(num, num, num);
	return *this;
}

template<class T>
T Point<T>::GetX() const 
{
	return X; 
}

template<class T>
T Point<T>::GetY() const 
{
	return Y; 	
}

template<class T>
T Point<T>::GetZ() const 
{ 
	return Z; 
}

template<class T>
void Point<T>::SetX(T x) 
{ 
	X = x; 
}

template<class T>
void Point<T>::SetY(T y) 
{
	Y = y; 
}

template<class T>
void Point<T>::SetZ(T z) { 
	Z = z; 
}

template<class U>
ostream& operator << (ostream& o, const Point<U>& obj) {
	o << "(" << obj.X << ", " << obj.Y << ", " << obj.Z << ")";
	return o;
}