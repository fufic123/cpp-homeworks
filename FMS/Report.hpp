#pragma once
#include "ReportGenerator.hpp"
#include "Expense.hpp"
#include "Date.hpp"
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class Report 
{
private:
	map<Date, vector<Expense>> report;

public:
	Report(map<Date, vector<Expense>> report);

	void ShowDayReport(ReportGenerator rp, Date date, vector<User*>& accounts);
	void ShowWeekReport(ReportGenerator rp, Date date, vector<User*>& accounts);
	void ShowMonthReport(ReportGenerator rp, Date date, vector<User*>& accounts);

	void AddToFileDayReport(ReportGenerator rp, Date date, vector<User*>& accounts);
	void AddToFileWeekReport(ReportGenerator rp, Date date, vector<User*>& accounts);
	void AddToFileMonthReport(ReportGenerator rp, Date date, vector<User*>& accounts);

	void ShowWeekRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts);
	void ShowMonthRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts);
	void ShowWeekRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts);
	void ShowMonthRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts);

	void AddToFileWeekRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts);
	void AddToFileMonthRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts);
	void AddToFileWeekRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts);
	void AddToFileMonthRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts);
};