#pragma once
#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

	Date(int day);
	Date(int day, int month);

public:
	Date();
	Date(int day, int month, int year);

	void Print();
	void Init();

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);

	Date& operator ++ ();
	Date& operator -- ();
	Date operator ++ (int);
	Date operator -- (int);

	Date operator + (int d);
	Date operator - (int d);
	Date operator - (Date d);

	Date& operator += (int d);
	Date& operator -= (int d);

	bool operator == (const Date& d);
	bool operator != (const Date& d);

	bool operator < (const Date& d);
	bool operator <= (const Date& d);

	bool operator > (const Date& d);
	bool operator >= (const Date& d);

	int operator [] (int index);

	friend ostream& operator << (ostream& ostream, const Date& date);
	friend istream& operator >> (istream& istream, Date& date);
};

Date::Date() { 
    day = month = year = 0; 
}

Date::Date(int day) { 
	if (day < 0 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || 
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) 
    {
		this->day = 0;
	}
	else 
    {
		this->day = day;
	}
}

Date::Date(int day, int month): Date(day) { 
	if (month < 0 || month > 12) 
    { 
        this->month = 0; 
    }
	else 
    { 
        this->month = month; 
    }
}

Date::Date(int day, int month, int year): Date(day, month){ 
    this->year = year; 
}

void Date::Print() { 
    printf("%02d.%02d.%d\n", day, month, year); 
}

void Date::Init() {
	char cin1, cin2;
	cout << "Enter date: ";
	cin >> day;
    cin1 >> month;
    cin2 >> year;
	if (cin1 != '.' || cin2 != '.' || day < 0 || month < 0 || month > 12 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) 
    {
		Init();
	}
}

int Date::GetDay() const { 
    return day; 
}

int Date::GetMonth() const {
    return month; 
}

int Date::GetYear() const {
    return year; 
}

void Date::SetDay(int day) {
	if (day < 0 || 
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) 
    {
        this->day = this->day; 
    }
	else 
    { 
        this->day = day; 
    }
}

void Date::SetMonth(int month) {
	if (month < 0 || month > 12) 
    { 
        this->month = this->month; 
    }
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		day = 31;
		this->month = month;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day = 30;
		this->month = month;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) {
		day = 28;
		this->month = month;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) {
		day = 29;
		this->month = month;
	}
	else { this->month = month; }
}

void Date::SetYear(int year) {
    this->year = year;
}


// operators
Date& Date::operator ++ () {
	day += 1;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) 
    {
		day = 1;
		month += 1;
	}
	if (month > 12) 
    {
		month = 1;
		year += 1;
	}
	return *this;
}

Date& Date::operator -- (){
	day -= 1;
	if (day < 1) 
    {
		day = 1;
		month -= 1;
	}
	if (month < 1) 
    {
		month = 1;
		year -= 1;
	}
	return *this;
}

Date Date::operator ++ (int) {
	Date tmp(this->day, this->month, this->year);
	day += 1;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		(month == 2 && year % 4 != 0 && day > 28) ||
		(month == 2 && year % 4 == 0 && day > 29)) 
    {
		day = 1;
		month += 1;
	}
	if (month > 12) 
    {
		month = 1;
		year += 1;
	}
	return tmp;
}

Date Date::operator -- (int) {
	Date tmp(this->day, this->month, this->year);
	day -= 1;
	if (day < 1) 
    {
		day = 1;
		month -= 1;
	}
	if (month < 1) 
    {
		month = 1;
		year -= 1;
	}
	return tmp;
}

Date Date::operator + (int d){
	Date tmp(this->day, this->month, this->year);
	day += d;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)) {
		day -= 31;
		month += 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day -= 30;
		month += 1;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) {
		day -= 28;
		month += 1;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) {
		day -= 29;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
	return tmp;
}

Date Date::operator - (int d) {
	Date tmp(this->day, this->month, this->year);
	day -= d;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 0)) 
    {
		day += 31;
		month -= 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 0) 
    {
		day += 30;
		month -= 1;
	}
	else if ((month == 2 && year % 4 != 0 && day < 0)) 
    {
		day += 28;
		month -= 1;
	}
	else if ((month == 2 && year % 4 == 0 && day < 0)) 
    {
		day += 29;
		month -= 1;
	}
	if (month < 1) 
    {
		month = 12;
		year -= 1;
	}
	return tmp;
}

Date Date::operator - (Date d) {
	Date tmp(this->day, this->month, this->year);
	day -= d.day;
	month -= d.month;
	year -= d.year;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 0)) 
    {
		day += 31;
		month -= 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
    {
		day += 30;
		month -= 1;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) 
    {
		day += 28;
		month -= 1;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) 
    {
		day += 29;
		month -= 1;
	}
	if (month < 1) 
    {
		month = 12;
		year -= 1;
	}
	return tmp;
}

Date& Date::operator += (int d) {
	day += d;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)) 
    {
		day -= 31;
		month += 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
    {
		day -= 30;
		month += 1;
	}
	else if ((month == 2 && year % 4 != 0 && day > 28)) 
    {
		day -= 28;
		month += 1;
	}
	else if ((month == 2 && year % 4 == 0 && day > 29)) 
    {
		day -= 29;
		month += 1;
	}
	if (month > 12) 
    {
		month = 1;
		year += 1;
	}
	return *this;
}

Date& Date::operator -= (int d) {
	day -= d;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 0)) 
    {
		day += 31;
		month -= 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 0) 
    {
		day += 30;
		month -= 1;
	}
	else if ((month == 2 && year % 4 != 0 && day < 0)) 
    {
		day += 28;
		month -= 1;
	}
	else if ((month == 2 && year % 4 == 0 && day < 0)) 
    {
		day += 29;
		month -= 1;
	}
	if (month < 1) 
    {
		month = 12;
		year -= 1;
	}
	return *this;
}

int Date::operator [] (int index) {}

bool Date::operator == (const Date& d) {
	if (day == d.day && month == d.month && year == d.year) return true;
	return false;
}

bool Date::operator != (const Date& d) {
	if (day == d.day && month == d.month && year == d.year) return false;
	return true;
}

bool Date::operator < (const Date& d) {
	if (year < d.year) return true;
	else if (year == d.year) 
    {
		if (month < d.month) return true;
		else if (month == d.month) 
        {
			if (day < d.day) return true;
		}
	}
	return false;
}

bool Date::operator <= (const Date& d) {
	if (year < d.year) return true;
	else if (year == d.year) 
    {
		if (month < d.month) return true;
		else if (month == d.month) 
        {
			if (day < d.day || day == d.day) return true;
		}
	}
	return false;
}

bool Date::operator > (const Date& d) {
	if (year > d.year) return true;
	else if (year == d.year) 
    {
		if (month > d.month) return true;
		else if (month == d.month) 
        {
			if (day > d.day) return true;
		}
	}
	return false;
}

bool Date::operator >= (const Date& d){
	if (year > d.year) return true;
	else if (year == d.year) 
    {
		if (month > d.month) return true;
		else if (month == d.month) 
        {
			if (day > d.day || day == d.day) return true;
		}
	}
	return false;
}

int Date::operator [] (int index) {
	if (index == 0) 
	{
		return day;
	}
	else if (index == 1) 
	{
		return month;
	}
	else if (index == 2) 
	{
		return year;
	}
	else throw "Error";
	return 0;
}

ostream& operator << (ostream& ostream, const Date& date) {
	if (date.day < 10 && date.month < 10) 
    { 
        ostream << "0" << date.day << ".0" << date.month << "." << date.year; 
    }
	else if (date.day < 10 && date.month > 10) 
    { 
        ostream << "0" << date.day << "." << date.month << "." << date.year; 
    }
	else if (date.day > 10 && date.month < 10) 
    { 
        ostream << date.day << ".0" << date.month << "." << date.year; 
    }
	else 
    { 
        ostream << date.day << "." << date.month << "." << date.year; 
    }
	return ostream;
}

istream& operator>>(istream& istream, Date& date){
	init:
		char cin1, cin2;
		cout << "Enter date: ";
		cin >> date.day >> cin1 >> date.month >> cin2 >> date.year;
		if (cin1 != '.' || cin2 != '.' || date.day < 0 || date.month < 0 || date.month > 12 ||
			((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) && date.day > 31) ||
			((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) ||
			(date.month == 2 && date.year % 4 != 0 && date.day > 28) ||
			(date.month == 2 && date.year % 4 == 0 && date.day > 29)) {
			goto init;
		}
	return istream;
}