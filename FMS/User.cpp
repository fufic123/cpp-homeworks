#include "User.hpp"
#include <iostream>
using namespace std;

User::User() : Holder("No name"), Number("AA00 AAAA 0000 0000 0000 0000"), Balance(0.0) {
	vector<Expense> tmp;
	tmp.push_back(Expense());
	Expenses = tmp;
}

User::User(string Holder, string Number, double Balance, vector<Expense> Expenses) :
	Holder(Holder), Number(Number), Balance(Balance), Expenses(Expenses) {}