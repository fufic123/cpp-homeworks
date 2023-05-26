#pragma once
#include <vector>
#include <map>
#include "Expense.hpp"
#include "User.hpp"
#include "Date.hpp"
using namespace std;

class ReportGenerator 
{
public:
	ReportGenerator();

	map<Date, vector<Expense>> generateDayReport(Date date, vector<User*>& accounts);
	map<Date, vector<Expense>> generateWeekReport(Date date, vector<User*>& accounts);
	map<Date, vector<Expense>> generateMonthReport(Date date, vector<User*>& accounts);
};