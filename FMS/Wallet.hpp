#pragma once
#include "User.hpp"
#include "Expense.hpp"
#include <limits>
#include <string>
#include <vector>
using namespace std;
class Wallet : public User {
private:
	string UserWalletName;
	double UserCreditLimit;

public:
	Wallet();
	Wallet(string Holder, string Number, double Balance, string UserWalletName, double UserCreditLimit, vector<Expense> Expenses);
	void Deposit(double Amount);
	void Withdraw(double Amount, Category ECategory, Date EDate, Time ETime);
	void Show();
	vector<Expense> getAllExpenses();
	vector<Expense> getExpensesByCategory(Category category);
	friend ostream& operator << (ostream& o, const Wallet& w);
	friend istream& operator >> (istream& i, Wallet& w);
};
