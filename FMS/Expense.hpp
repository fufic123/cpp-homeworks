#pragma once
#include <iostream>
#include <string>
#include "Date.hpp"
#include "Time.hpp"
#include "Category.hpp"
using namespace std;

class Expense 
{
private:
	double EAmount;
	Category ECategory;
	Date EDate;
	Time ETime;

public:
	Expense();
	Expense(double EAmount, Category ECategory, Date EDate, Time ETime);
	Expense(double EAmount, string ExpenseCategoryName, double ExpenseCategoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours);

	double GetEAmount() const;
	Category GetECategory() const;
	Date GetEDate() const;
	Time GetETime() const;

	string toString();

	void SetEAmount(double EAmount);
	void SetECategory(Category ECategory);
	void SetEDate(Date EDate);
	void SetETime(Time ETime);
	bool operator < (const Expense& e) const;
	bool operator > (const Expense& e) const;
	friend ostream& operator << (ostream& o, const Expense& e);
	friend istream& operator >> (istream& i, Expense& e);
};