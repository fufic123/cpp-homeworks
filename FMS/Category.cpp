#include "Category.hpp"
using namespace std;

Category::Category(): CategoryName("None"), CategoryCashback(0.0){}
Category::Category(string CategoryName, double CategoryCashback): CategoryName(CategoryName), CategoryCashback(CategoryCashback){}
string Category::GetCategoryName() const { return CategoryName; }
double Category::GetCategoryCashback() const { return CategoryCashback; }
string Category::toString() { return "Category name: " + CategoryName + "\nCategory cashback: " + to_string(CategoryCashback); }
bool Category::operator == (const Category& c) const { return CategoryName == c.GetCategoryName(); }
bool Category::operator!=(const Category& c) const { return CategoryName != c.GetCategoryName(); }
ostream& operator<<(ostream& o, const Category& c) 
{
	o << "Category: " << c.GetCategoryName() << "\n" << "Cashback: " << c.GetCategoryCashback();
	return o;
}

istream& operator >> (istream& i, Category& c) {
	string CategoryName;
	double CategoryCashback;

	cout << "Category name: ";
	i >> CategoryName;
	cout << "Category cashback: ";
	i >> CategoryCashback;

	return i;
}