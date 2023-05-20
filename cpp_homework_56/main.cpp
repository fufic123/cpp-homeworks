#include <iostream>
#include "MyStringStatic.h"
using namespace std;

int MyString::count = 0;

MyString test(const char* str);

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

    MyString str4;
    str1.MyStrcpy(str4);
    MyString::ShowNumberOfObjects();
    
    MyString str5 = test("string");
    str5.Print();
    
    str1 = test("string");
    str1.Print();

    MyString str6 = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!' };
    str6.Print();
}

MyString test(const char* str)
{
    MyString value(str);
    return value;
}

