#include "includes.hpp"
using namespace std;

int main() {
	vector<User*> accounts;

	MAINMENU: {
		int choice = menu();
		if (choice < 1 || choice > 5) goto MAINMENU;
		else if (choice == 3)
		{
			system("cls");
			cout << "Thank you" << "\n";
			return 0;
		}
		else if (choice == 2) 
		{
			ADDMENU: {
				int addChoice = add();
				if (addChoice < 1 || addChoice > 3) goto ADDMENU;
				else if (addChoice == 3) goto MAINMENU;
				else if (addChoice == 2) 
				{
					addwallet(accounts);
					goto MAINMENU;
				}
				else {
					addcard(accounts);
					goto MAINMENU;
				}
			}
			
		}
		else {
			LISTMENU: {
				int listChoice = list(accounts);
				if (listChoice == 0) goto MAINMENU;
				else if (listChoice < 0 || listChoice > accounts.size()) goto LISTMENU;
				else {
					ACTIONMENU: {
						int actionChoice = actions(accounts, listChoice);
						if (actionChoice < 1 || actionChoice > 5) goto ACTIONMENU;
						else if (actionChoice == 1) 
						{
							replenishment(accounts[listChoice - 1]);
							goto ACTIONMENU;
						}
						else if (actionChoice == 2) 
						{
							addexpense(accounts[listChoice - 1]);
							goto ACTIONMENU;
						}
						else if (actionChoice == 3) 
						{
							REPORTMENU: {
								int reportChoice = reports();
								if (reportChoice == 1) {
									Date date = dayreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateDayReport(date, accounts);
									int ReportAction = reportactions();
									if (ReportAction == 1) 
									{
										Report report(tmp);
										report.ShowDayReport(rg, date, accounts);
										Sleep(5000);
										goto ACTIONMENU;
									}
									else if (ReportAction == 2) 
									{
										Report report(tmp);
										report.AddToFileDayReport(rg, date, accounts);
									}
									else 
									{
										cout << "Incorrect choice :(" << "\n";
										Sleep(2000);
										goto REPORTMENU;
									}
								}
								else if (reportChoice == 2) {
									Date date = weekreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateWeekReport(date, accounts);
									int ReportAction = reportactions();
									if (ReportAction == 1) 
									{
										Report report(tmp);
										report.ShowDayReport(rg, date, accounts);
										Sleep(5000);
										goto ACTIONMENU;
									}
									else if (ReportAction == 2) 
									{
										Report report(tmp);
										report.AddToFileWeekReport(rg, date, accounts);
									}
									else 
									{
										cout << "Incorrect choice :(" << "\n";
										Sleep(2000);
										goto REPORTMENU;
									}
								}
								else if (reportChoice == 3) 
								{
									Date date = monthreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateMonthReport(date, accounts);
									int ReportAction = reportactions();
									if (ReportAction == 1)
									{
										Report report(tmp);
										report.ShowMonthReport(rg, date, accounts);
										Sleep(5000);
										goto ACTIONMENU;
									}
									else if (ReportAction == 2) 
									{
										Report report(tmp);
										report.AddToFileMonthReport(rg, date, accounts);
									}
									else 
									{
										cout << "Incorrect choice :(" << "\n";
										Sleep(2000);
										goto REPORTMENU;
									}
								}
								else if (reportChoice == 4) goto ACTIONMENU;
								else goto REPORTMENU;
							}
						}
						else if (actionChoice == 4) 
						{
							RATINGMENU: {
								int ratingChoice = ratings();
								if (ratingChoice == 1) {
									Date date = weekreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateWeekReport(date, accounts);
									Report report(tmp);
									int whichRating = ByPriceOrByCategory();
									if (whichRating == 1) report.ShowWeekRatingByPrice(rg, date, accounts);
									else if (whichRating == 2) report.ShowWeekRatingByCategory(rg, date, accounts);
									else goto RATINGMENU;
								}
								else if (ratingChoice == 2) 
								{
									Date date = monthreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateMonthReport(date, accounts);
									Report report(tmp);
									int whichRating = ByPriceOrByCategory();
									if (whichRating == 1) report.ShowMonthRatingByPrice(rg, date, accounts);
									else if (whichRating == 2) report.ShowMonthRatingByCategory(rg, date, accounts);
									else goto RATINGMENU;
								}
								else if (ratingChoice == 3) 
								{
									Date date = weekreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateWeekReport(date, accounts);
									Report report(tmp);
									int whichRating = ByPriceOrByCategory();
									if (whichRating == 1) report.AddToFileWeekRatingByPrice(rg, date, accounts);
									else if (whichRating == 2) report.AddToFileWeekRatingByCategory(rg, date, accounts);
									else goto RATINGMENU;
								}
								else if (ratingChoice == 4) 
								{
									Date date = monthreport();
									ReportGenerator rg;
									map<Date, vector<Expense>> tmp = rg.generateMonthReport(date, accounts);
									Report report(tmp);
									int whichRating = ByPriceOrByCategory();
									if (whichRating == 1) report.AddToFileMonthRatingByPrice(rg, date, accounts);
									else if (whichRating == 2) report.AddToFileMonthRatingByCategory(rg, date, accounts);
									else goto RATINGMENU;
								}
							}
						}
						else if (actionChoice == 5) goto LISTMENU;
						else goto ACTIONMENU;
					}
				}
			}
		}
	}
}