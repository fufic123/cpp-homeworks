#include <iostream>
#include "MyStringStatic.h"
using namespace std;

int MyString::count = 0;

int main() {
	MyString str1("Hello world!");
	cout << str1 << "\n"; 
	cout << str1.MyStrLen() << "\n"; 
	MyString::ShowNumberOfObjects(); 

	str1.Input(); 
	str1.Print(); 
	cout << str1.MyStrLen() << "\n"; 

	MyString str2;
	str1.MyStrcpy(str2);
	str2.Print(); 
	MyString::ShowNumberOfObjects(); 

	MyString str3("Hi");
	str1.MyStrCat(str3);
	str1.Print();

	str1.MyDelChr('o');
	str1.Print(); 

	cout << str1.MyStrCmp(str2) << "\n"; 
	MyString::ShowNumberOfObjects(); 
}