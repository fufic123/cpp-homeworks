#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Category {
private:
	string CategoryName;
	double CategoryCashback;

public:
	Category();
	Category(string Name, double CategoryCashback);
	string GetCategoryName() const;
	double GetCategoryCashback() const;
	string toString();
	bool operator == (const Category& c) const;
	bool operator != (const Category& c) const;
};

ostream& operator << (ostream& o, const Category& c);
istream& operator >> (istream& i, Category& c);