#include "Expense.hpp"
using namespace std;

Expense::Expense() : EAmount(0), ECategory(Category()), EDate(Date()), ETime(Time()) {}
Expense::Expense(double EAmount, Category ECategory, Date EDate, Time ETime) : 
	EAmount(EAmount), ECategory(ECategory), EDate(EDate), ETime(ETime) {}
Expense::Expense(double EAmount, string ExpenseCategoryName, double ExpenseCategoryCashback, unsigned short day, unsigned short month, unsigned short year, unsigned short seconds, unsigned short minutes, unsigned short hours) :
	EAmount(EAmount), ECategory(Category(ExpenseCategoryName, ExpenseCategoryCashback)), EDate(Date(day, month, year)), ETime(Time(seconds, minutes, hours)) {}

double Expense::GetEAmount() const { return EAmount; }
Category Expense::GetECategory() const { return ECategory; }
Date Expense::GetEDate() const { return EDate; }
Time Expense::GetETime() const { return ETime; }

string Expense::toString() { return "Expense: \nAmount: " + to_string(EAmount) + "\nCategory: " + ECategory.toString() + "\nDate: " + EDate.toString() + "\nTime: " + ETime.toString(); }

void Expense::SetEAmount(double EAmount) { this->EAmount = EAmount; }
void Expense::SetECategory(Category ECategory) { this->ECategory = ECategory; }
void Expense::SetEDate(Date EDate) { this->EDate = EDate; }
void Expense::SetETime(Time ETime) { this->ETime = ETime; }

bool Expense::operator < (const Expense& e) const { return EAmount < e.EAmount; }
bool Expense::operator > (const Expense& e) const { return EAmount > e.EAmount; }

ostream& operator << (ostream& o, const Expense& e) {
	o << "Expense: " << "\n"
		<< "Amount: " << e.EAmount << "\n"
		<< "Category: " << "\n" << e.ECategory << "\n"
		<< "Date: " << e.EDate << "\n"
		<< "Time: " << e.ETime;
	return o;
}

istream& operator >> (istream& i, Expense& e) {
	cout << "New Expense:" << "\n" << "Amount: ";
	i >> e.EAmount;
	cout << "Category: ";
	i >> e.ECategory;
	i >> e.EDate;
	i >> e.ETime;

	return i;
}