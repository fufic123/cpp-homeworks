#include <iostream>
#include <fstream>
#include <string>
#include "Fraction.h"
using namespace std;

int main() {
	fstream first("first.txt");
	ofstream newFirst("newFirst.txt");
	while (first) 
	{
		string tmp;
		first >> tmp;
		if (tmp.size() >= 8) 
		{ 
			if (tmp.find('.')) 
			{
				tmp.erase(remove(tmp.begin(), tmp.end(), '.'), tmp.end());
			}

			if (tmp.find(','))
			{
				tmp.erase(remove(tmp.begin(), tmp.end(), ','), tmp.end());
			}

			if (tmp.find(':'))
			{
				tmp.erase(remove(tmp.begin(), tmp.end(), ':'), tmp.end());
			}

			if (tmp.find('-'))
			{
				tmp.erase(remove(tmp.begin(), tmp.end(), '-'), tmp.end());
			}
			newFirst << tmp << "\n"; 
		}
	}
	first.close();
	newFirst.close();

	fstream second("second.txt");
	ofstream newSecond("newSecond.txt");
	while (second) 
	{
		string tmp;
		getline(second, tmp);
		newSecond << tmp << "\n";
	}
	second.close();
	newSecond.close();

	Fraction f1[4] = { Fraction(1, 5), Fraction(2, 3), Fraction(4, 5), Fraction(6, 4) };
	Fraction f2[4];
	ofstream third1("third.dat", ios::binary);
	third1.write((char*)f1, 4 * sizeof(Fraction));
	third1.close();
	ifstream third2("third.dat", ios::binary);
	third2.read((char*)f2, 4 * sizeof(Fraction));
	for (int i = 0; i < 4; i++) 
	{
		cout << f2[i] << "\n";
	}
	third2.close();

	Fraction f3[4] = { Fraction(3, 5), Fraction(3, 7), Fraction(4, 8), Fraction(9, 5) };
	Fraction f4;
	ofstream fourth1("fourth.dat", ios::binary);
	fourth1.write((char*)f3, 4 * sizeof(Fraction));
	fourth1.close();
	ifstream fourth2("fourth.dat", ios::binary);
	fourth2.seekg(2 * sizeof(Fraction));
	fourth2.read((char*)&f4, sizeof(Fraction));
	cout << f4 << "\n";
	fourth2.close();
}