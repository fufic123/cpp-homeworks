#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	unsigned short year;
	unsigned short month;
	unsigned short day;
	
public:
	Date();
	Date(unsigned short day, unsigned short month, unsigned short year);
	void Show() const;
	void Init();
	short GetDay() const;
	short GetMonth() const;
	short GetYear() const;
	void SetDay(unsigned short day);
	void SetMonth(unsigned short month);
	void SetYear(unsigned short year);
	bool isLeap() const;
	int daysInMonth() const;
	int daysInYear() const;
	int daysFromBegin() const;
	string toString();
	string toString() const;
	bool operator == (const Date& d) const;
	bool operator > (const Date& d) const;
	bool operator < (const Date& d) const;
	Date operator - (const int days);
};

ostream& operator << (ostream& o, const Date& d);
istream& operator >> (istream& i, Date& d);