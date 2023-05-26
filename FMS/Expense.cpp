#include "Expense.hpp"
using namespace std;

Expense::Expense() : ExpenseAmount(0), ECategory(Category()), EDate(Date()), ETime(Time()) {}
Expense::Expense(double ExpenseAmount, Category ECategory, Date EDate, Time ETime) : 
	ExpenseAmount(ExpenseAmount), ECategory(ECategory), EDate(EDate), ETime(ETime) {}
Expense::Expense(double ExpenseAmount, string ExpenseCategoryName, double ExpenseCategoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours) :
	ExpenseAmount(ExpenseAmount), ECategory(Category(ExpenseCategoryName, ExpenseCategoryCashback)), EDate(Date(day, month, year)), ETime(Time(seconds, minutes, hours)) {}

double Expense::GetExpenseAmount() const { return ExpenseAmount; }
Category Expense::GetExpenseCategory() const { return ECategory; }
Date Expense::GetExpenseDate() const { return EDate; }
Time Expense::GetExpenseTime() const { return ETime; }

string Expense::toString() { return "Expense: \nAmount: " + to_string(ExpenseAmount) + "\nCategory: " + ECategory.toString() + "\nDate: " + EDate.toString() + "\nTime: " + ETime.toString(); }

void Expense::SetExpenseAmount(double ExpenseAmount) { this->ExpenseAmount = ExpenseAmount; }
void Expense::SetExpenseCategory(Category ECategory) { this->ECategory = ECategory; }
void Expense::SetExpenseDate(Date EDate) { this->EDate = EDate; }
void Expense::SetExpenseTime(Time ETime) { this->ETime = ETime; }

bool Expense::operator < (const Expense& e) const { return ExpenseAmount < e.ExpenseAmount; }
bool Expense::operator > (const Expense& e) const { return ExpenseAmount > e.ExpenseAmount; }

ostream& operator << (ostream& o, const Expense& e) {
	o << "Expense: " << "\n"
		<< "Amount: " << e.ExpenseAmount << "\n"
		<< "Category: " << "\n" << e.ECategory << "\n"
		<< "Date: " << e.EDate << "\n"
		<< "Time: " << e.ETime;
	return o;
}

istream& operator >> (istream& i, Expense& e) {
	cout << "New Expense:" << "\n" << "Amount: ";
	i >> e.ExpenseAmount;
	cout << "Category: ";
	i >> e.ECategory;
	i >> e.EDate;
	i >> e.ETime;

	return i;
}