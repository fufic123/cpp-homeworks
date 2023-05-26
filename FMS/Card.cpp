#include "Card.hpp"
using namespace std;

Card::Card() : User(), CardName("No bank title"), UserCreditLimit(0.0) {}

Card::Card(string Holder, string Number, double Balance, string CardName, double UserCreditLimit, vector<Expense> Expenses) :
	User(Holder, Number, Balance, Expenses), CardName(CardName), UserCreditLimit(UserCreditLimit) {}

void Card::Deposit(double Amount) { Balance += Amount; }

void Card::Withdraw(double Amount, Category ECategory, Date EDate, Time ETime) {
	Balance -= Amount;
	if (Balance < 0) {
		if (Balance < UserCreditLimit) {
			Balance += Amount;
			cout << "Expense is too big";
		}
	}
	Balance += Amount * (ECategory.GetCategoryCashback() / 100);
	Expense tmp(Amount, ECategory, EDate, ETime);
	Expenses.push_back(tmp);
}

void Card::Show() {
	cout << "-----------------------------" << "\n"
		<< "Card " << CardName << ":" << "\n"
		<< " Balance: " << Balance << "\n"
		<< " Credit limit: " << UserCreditLimit << "\n"
		<< "Holder: " << "\n"
		<< " Name: " << Holder << "\n"
		<< " Card number: " << Number << "\n"
		<< "-----------------------------" << "\n";
}

vector<Expense> Card::getExpensesByCategory(Category category) {
	vector<Expense> tmp;
	for (int i = 0; i < Expenses.size(); i++) if (Expenses[i].GetExpenseCategory() == category) tmp.push_back(Expenses[i]);
	return tmp;
}

vector<Expense> Card::getAllExpenses() { return Expenses; }

ostream& operator << (ostream& o, const Card& c) {
	o << "-----------------------------" << "\n"
		<< "Card " << c.CardName << ":" << "\n"
		<< " Balance: " << c.Balance << "\n"
		<< " Credit limit: " << c.UserCreditLimit << "\n"
		<< "Holder: " << "\n"
		<< " Name: " << c.Holder << "\n"
		<< " Card number: " << c.Number << "\n"
		<< "-----------------------------";
	return o;
}

istream& operator >> (istream& i, Card& c) {
	cout << "New Card:" << "\n"
		<< " User holder >> ";
	i.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(i, c.Holder);

	cout << " User number >> ";
	getline(i, c.Number);

	cout << " Balance >> ";
	i >> c.Balance;

	cout << " Credit limit (if card is debit enter 0) >> ";
	i >> c.UserCreditLimit;

	cout << " Bank name >> ";
	i.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(i, c.CardName);

	vector<Expense> tmp;
	tmp.push_back(Expense());
	c.Expenses = tmp;

	return i;
}