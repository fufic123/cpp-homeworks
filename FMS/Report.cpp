#include "Report.hpp"
using namespace std;

Report::Report(map<Date, vector<Expense>> report): report(report) {}

void Report::ShowDayReport(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateDayReport(date, accounts);
	for (auto el : report) 
	{
		for (int i = 0; i < el.second.size(); i++) 
		{
			cout << "Day report:" << "\n"
				<< "Date: " << el.first << "\n"
				<< "Info: " << "\n"
				<< el.second[i] << "\n";
		}
	}
}

void Report::ShowWeekReport(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report) 
	{
		for (int i = 0; i < el.second.size(); i++) 
		{
			cout << "Day report:" << "\n"
				<< "Date: " << el.first << "\n"
				<< "Info: " << "\n"
				<< el.second[i] << "\n";
		}
	}
}

void Report::ShowMonthReport(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report) 
	{
		for (int i = 0; i < el.second.size(); i++) 
		{
			cout << "Day report:" << "\n"
				<< "Date: " << el.first << "\n"
				<< "Info: " << "\n"
				<< el.second[i] << "\n";
		}
	}
}

void Report::AddToFileDayReport(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateDayReport(date, accounts);
	string result;
	for (auto& pair : report) 
	{
		result += pair.first.toString() + ":\n";
		for (auto& expense : pair.second) result += " " + expense.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream ReportDB("DayReportDB.dat", ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::AddToFileWeekReport(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateWeekReport(date, accounts);
	string result;
	for (auto& pair : report) 
	{
		result += pair.first.toString() + ":\n";
		for (auto& expense : pair.second) result += " " + expense.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream ReportDB("WeekReportDB.dat", ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::AddToFileMonthReport(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateMonthReport(date, accounts);
	string result;
	for (auto& pair : report) 
	{
		result += pair.first.toString() + ":\n";
		for (auto& expense : pair.second) result += " " + expense.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream ReportDB("MonthReportDB.dat", ios::binary);
	ReportDB.write(charArray, report.size() * sizeof(report));
	ReportDB.close();
}

void Report::ShowWeekRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateWeekReport(date, accounts);
	int count = 0;
	for (auto el : report) 
	{
		for (int i = 0; i < 3; i++) 
		{
			cout << "Day report:" << "\n"
				<< "Date: " << el.first << "\n"
				<< "Info: " << "\n"
				<< el.second[i] << "\n";
		}
	}
}

void Report::ShowMonthRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateWeekReport(date, accounts);
	int count = 0;
	for (auto el : report) 
	{
		for (int i = 0; i < 3; i++) 
		{
			cout << "Day report:" << "\n"
				<< "Date: " << el.first << "\n"
				<< "Info: " << "\n"
				<< el.second[i] << "\n";
		}
	}
}

void Report::ShowWeekRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report) 
	{
		for (auto elem : el.second) 
		{
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) 
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) 
		{
			for (auto elem : el.second) 
			{
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });
	int num = 1;
	cout << "Week rating by category: " << "\n";
	for (auto el : CategoryMap) 
	{
		cout << " " << num << ". " << el.second << " (" << el.first << " Expenses)" << "\n";
		num++;
		if (num == 3) break;
	}
}

void Report::ShowMonthRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report) 
	{
		for (auto elem : el.second) 
		{
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) {
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) {
			for (auto elem : el.second) 
			{
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({categoryVectCount[i], categoryVect[i]});
	int num = 1;
	cout << "Week rating by category: " << "\n";
	for (auto el : CategoryMap) 
	{
		cout << " " << num << ". " << el.second << " (" << el.first << " Expenses)" << "\n";
		num++;
		if (num == 3) break;
	}
}

void Report::AddToFileWeekRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateWeekReport(date, accounts);
	string result;
	for (auto el : report) 
	{
		result += el.first.toString() + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second[i].toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream RatingDB("WeekRatingDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::AddToFileMonthRatingByPrice(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	report = rp.generateMonthReport(date, accounts);
	string result;
	for (auto el : report) 
	{
		result += el.first.toString() + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second[i].toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream RatingDB("MonthRatingDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::AddToFileWeekRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateWeekReport(date, accounts);
	for (auto el : report) 
	{
		for (auto elem : el.second) 
		{
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) 
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) 
		{
			for (auto elem : el.second) 
			{
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });

	string result;
	for (auto el : CategoryMap) 
	{
		result += to_string(el.first) + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream RatingDB("WeekRatingByCategoryDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}

void Report::AddToFileMonthRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
	vector<Category> categoryVect;
	vector<int> categoryVectCount;
	report = rp.generateMonthReport(date, accounts);
	for (auto el : report) 
	{
		for (auto elem : el.second) 
		{
			Category tmp = elem.GetExpenseCategory();
			for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
		}
	}
	for (int i = 0; i < categoryVect.size(); i++) 
	{
		int count = 0;
		Category tmp = categoryVect[i];
		for (auto el : report) 
		{
			for (auto elem : el.second) 
			{
				Category tmp = elem.GetExpenseCategory();
				for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
			}
		}
		categoryVectCount.push_back(count);
	}
	multimap<int, Category> CategoryMap;
	for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });

	string result;
	for (auto el : CategoryMap) 
	{
		result += to_string(el.first) + ":\n";
		for (int i = 0; i < 3; i++) result += " " + el.second.toString() + "\n";
		result += "\n";
	}
	char* charArray = new char[result.length() + 1];
	strcpy_s(charArray, result.length() + 1, result.c_str());
	ofstream RatingDB("MonthRatingByCategoryDB.dat", ios::binary);
	RatingDB.write(charArray, report.size() * sizeof(report));
	RatingDB.close();
}