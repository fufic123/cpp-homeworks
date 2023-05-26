#pragma once
#include "includes.hpp"
using namespace std;

int diffBetweenDates(Date begin_date, Date end_date);

int menu();
int add();
void addcard(vector<User*>& accounts);
void addwallet(vector<User*>& accounts);
int list(vector<User*>& accounts);
int actions(vector<User*>& accounts, int number);
void replenishment(User* User);
void addexpense(User* User);
int reports();
int ratings();
Date dayreport();
Date weekreport();
Date monthreport();
int ByPriceOrByCategory();
int reportactions();