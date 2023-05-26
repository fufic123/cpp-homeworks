#include "ReportGenerator.hpp"
#include <algorithm>
using namespace std;

ReportGenerator::ReportGenerator() {}
map<Date, vector<Expense>> ReportGenerator::generateDayReport(Date date, vector<User*>& accounts) 
{
	vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if (accounts[i]->getAllExpenses()[j].GetEDate() == date) {
				report.push_back(accounts[i]->getAllExpenses()[j]);
			}
		}
	}
	while (count--) {
		bool IsSwapped = false;
		for (int i = 0; i < count; i++) {
			if (report[i] > report[i + 1]) {
				swap(report[i], report[i + 1]);
				IsSwapped = true;
			}
		}
	}
	reverse(report.begin(), report.end());
	map<Date, vector<Expense>> resoltReport;
	resoltReport.insert(make_pair(date, report));
	return resoltReport;
}

map<Date, vector<Expense>> ReportGenerator::generateWeekReport(Date date, vector<User*>& accounts) 
{
	vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if ((accounts[i]->getAllExpenses()[j].GetEDate() > date - 8) || (accounts[i]->getAllExpenses()[j].GetEDate() < date)) {
				report.push_back(accounts[i]->getAllExpenses()[j]);
			}
		}
	}
	while (count--) {
		bool IsSwapped = false;
		for (int i = 0; i < count; i++) {
			if (report[i] > report[i + 1]) {
				swap(report[i], report[i + 1]);
				IsSwapped = true;
			}
		}
	}
	reverse(report.begin(), report.end());
	map<Date, vector<Expense>> resoltReport;
	resoltReport.insert(make_pair(date, report));
	return resoltReport;
}

map<Date, vector<Expense>> ReportGenerator::generateMonthReport(Date date, vector<User*>& accounts) 
{
	vector<Expense> report;
	int count = report.size();
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i]->getAllExpenses().size(); j++) {
			if (accounts[i]->getAllExpenses()[j].GetEDate().GetMonth() == date.GetMonth() &&
				accounts[i]->getAllExpenses()[j].GetEDate().GetYear() == date.GetYear()) {
				report.push_back(accounts[i]->getAllExpenses()[j]);
			}
		}
	}
	while (count--) {
		bool IsSwapped = false;
		for (int i = 0; i < count; i++) {
			if (report[i] > report[i + 1]) {
				swap(report[i], report[i + 1]);
				IsSwapped = true;
			}
		}
	}
	reverse(report.begin(), report.end());
	map<Date, vector<Expense>> resoltReport;
	resoltReport.insert(make_pair(date, report));
	return resoltReport;
}