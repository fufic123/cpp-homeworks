#include "Wallet.hpp"
using namespace std;

Wallet::Wallet() : User(), UserWalletName("No bank title"), UserCreditLimit(0.0) {}
Wallet::Wallet(string Holder, string Number, double Balance, string UserWalletName, double UserCreditLimit, vector<Expense> Expenses) :
	User(Holder, Number, Balance, Expenses), UserWalletName(UserWalletName), UserCreditLimit(UserCreditLimit) {}
void Wallet::Deposit(double Amount) { Balance += Amount; }

void Wallet::Withdraw(double Amount, Category ECategory, Date EDate, Time ETime)
{
	Balance -= Amount;
	if (Balance < 0) 
	{
		if (Balance < UserCreditLimit) 
		{
			Balance += Amount;
			cout << "Expense is too big";
		}
	}
	Balance += Amount * (ECategory.GetCategoryCashback() / 100);
	Expense tmp(Amount, ECategory, EDate, ETime);
	Expenses.push_back(tmp);
}
void Wallet::Show() 
{
	cout << "-----------------------------" << "\n"
		<< "Wallet " << UserWalletName << ":" << "\n"
		<< " Balance: " << Balance << "\n"
		<< " Credit limit: " << UserCreditLimit << "\n"
		<< "Holder: " << "\n"
		<< " Name: " << Holder << "\n"
		<< " Wallet number: " << Number << "\n"
		<< "-----------------------------" << "\n";
}

vector<Expense> Wallet::getExpensesByCategory(Category category) 
{
	vector<Expense> tmp;
	for (int i = 0; i < Expenses.size(); i++) if (Expenses[i].GetECategory() == category) tmp.push_back(Expenses[i]);
	return tmp;
}

vector<Expense> Wallet::getAllExpenses() { return Expenses; }

ostream& operator << (ostream& o, const Wallet& w) 
{
	o << "-----------------------------" << "\n"
		<< "Wallet " << w.UserWalletName << ":" << "\n"
		<< " Balance: " << w.Balance << "\n"
		<< " Credit limit: " << w.UserCreditLimit << "\n"
		<< "Holder: " << "\n"
		<< " Name: " << w.Holder << "\n"
		<< " Wallet number: " << w.Number << "\n"
		<< "-----------------------------";
	return o;
}

istream& operator >> (istream& i, Wallet& w) 
{
	cout << "New wallet:" << "\n"
		<< " Account holder >> ";
	i.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(i, w.Holder);

	cout << " Account number >> ";
	getline(i, w.Number);

	cout << " Balance >> ";
	i >> w.Balance;

	cout << " Credit limit (if wallet is debit enter 0) >> ";
	i >> w.UserCreditLimit;

	cout << " Bank name >> ";
	i.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(i, w.UserWalletName);

	vector<Expense> tmp;
	tmp.push_back(Expense());
	w.Expenses = tmp;

	return i;
}