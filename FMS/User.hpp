#pragma once
#include <iostream>
#include "Expense.hpp"
using namespace std;

class User {
protected:
	string Holder;
	string Number;
	vector<Expense> Expenses;
	double Balance;

public:
	User();
	User(string Holder, string Number, double Balance, vector<Expense> Expenses);

	virtual void Deposit(double Amount) = 0;
	virtual void Withdraw(double Amount, Category ECategory, Date EDate, Time ETime) = 0;
	virtual void Show() = 0;

	virtual vector<Expense> getAllExpenses() = 0;
};