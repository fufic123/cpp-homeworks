#include "functions.hpp"
using namespace std;

int diffBetweenDates(Date beginDate, Date endDate) { return endDate.daysFromBegin() - beginDate.daysFromBegin(); }

int menu() 
{
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. All cards and wallets" << "\n";
	cout << "2. Add new card" << "\n";
	cout << "3. Exit" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choice:  ";
	cin >> c;
	return c;
}

int add() 
{
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "What do you want to add?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. Card" << "\n";
	cout << "2. Wallet" << "\n";
	cout << "3. Exit" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choice: ";
	cin >> c;
	return c;
}

void addcard(vector<User*>& accounts) 
{
	system("cls");
	Card NewCard;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cin >> NewCard;
	accounts.push_back(new Card(NewCard));
	Sleep(1000);
	system("cls");
	cout << "New card added!" << "\n";
	cout << "Wait 3 seconds for returning to main menu" << "\n";
	Sleep(3000);
	system("cls");
}

void addwallet(vector<User*>& accounts) 
{
	system("cls");
	Wallet NewWallet;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cin >> NewWallet;
	accounts.push_back(new Wallet(NewWallet));
	Sleep(1000);
	system("cls");
	cout << "New wallet added!" << "\n";
	cout << "Wait 3 seconds for returning to main menu" << "\n";
	Sleep(3000);
	system("cls");
}

int list(vector<User*>& accounts) 
{
	system("cls");
	if (accounts.size() == 0) {
		cout << "FMS" << "\n";
		cout << "-----------------------------" << "\n";
		cout << "Sorry, there is no any wallets or cards :(" << "\n";
		cout << "Returning in 3 seconds..." << "\n";
		Sleep(3000);
		return 0;
	}
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Which wallet/card do you want to work with?" << "\n";
	cout << "-----------------------------" << "\n";
	for (int i = 0; i < accounts.size(); i++) {
		cout << i + 1 << ".";
		accounts[i]->Show();
	}
	cout << "Enter your choice (to exit enter 0): ";
	cin >> c;
	return c;
}

int actions(vector<User*>& accounts, int number) 
{
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	accounts[number - 1]->Show();
	cout << "What do you want to do?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. Replenishment" << "\n";
	cout << "2. Add expense" << "\n";
	cout << "3. Generate report" << "\n";
	cout << "4. Generate rating" << "\n";
	cout << "5. Exit" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choise: ";
	cin >> c;
	return c;
}

void replenishment(User* user) 
{
	system("cls");
	int sum;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "What amount of money you want to replenishment on your account?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Enter amount >> ";
	cin >> sum;
	system("cls");
	cout << "Wait 2 seconds, please :)" << "\n";
	user->Deposit(sum);
	Sleep(2000);
}

void addexpense(User* user) 
{
	system("cls");
	Expense tmp;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cin >> tmp;
	cout << "-----------------------------" << "\n";
	system("cls");
	cout << "Wait 2 seconds, please :)" << "\n";
	user->Withdraw(tmp.GetEAmount(), tmp.GetECategory(), tmp.GetEDate(), tmp.GetETime());
	Sleep(2000);
}

int reports() {
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "What you want to do?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. Generate day report" << "\n";
	cout << "2. Generate week report" << "\n";
	cout << "3. Generate month report" << "\n";
	cout << "4. Exit" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choise: ";
	cin >> c;
	return c;
}

int ratings() 
{
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "What you want to do?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. Show week rating" << "\n";
	cout << "2. Show month rating" << "\n";
	cout << "3. Add to file week rating" << "\n";
	cout << "4. Add to file month rating" << "\n";
	cout << "5. Exit" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choise: ";
	cin >> c;
	return c;
}

Date dayreport() 
{
	system("cls");
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Day report (enter date)" << "\n";
	cout << "-----------------------------" << "\n";
	Date tmp;
	cin >> tmp;
	return tmp;
}

Date weekreport() 
{
	system("cls");
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Day report (enter end date)" << "\n";
	cout << "-----------------------------" << "\n";
	Date tmp;
	cin >> tmp;
	return tmp;
}

Date monthreport() 
{
	system("cls");
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Day report (enter date)" << "\n";
	cout << "-----------------------------" << "\n";
	Date tmp;
	cin >> tmp;
	return tmp;
}

int ByPriceOrByCategory() 
{
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Which rating do you want to do?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. By Price" << "\n";
	cout << "2. By Category" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choise: ";
	cin >> c;
	return c;
}

int reportactions() 
{
	system("cls");
	int c;
	cout << "FMS" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "What you want to do?" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "1. Show report" << "\n";
	cout << "2. Add to file report" << "\n";
	cout << "-----------------------------" << "\n";
	cout << "Your choise: ";
	cin >> c;
	return c;
}