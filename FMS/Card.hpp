#pragma once
#include "User.hpp"
#include "Expense.hpp"
#include <limits>
#include <string>
#include <vector>
using namespace std;

class Card : public User {
private:
	string CardName;
	double UserCreditLimit;

public:
	Card();
	Card(string Holder, string Number, double Balance, string CardName, double UserCreditLimit, vector<Expense> Expenses);

	void Deposit(double Amount);
	void Withdraw(double Amount, Category ECategory, Date EDate, Time ETime);
	void Show();

	vector<Expense> getExpensesByCategory(Category category);
	vector<Expense> getAllExpenses();

	friend ostream& operator << (ostream& o, const Card& c);
	friend istream& operator >> (istream& i, Card& c);
};