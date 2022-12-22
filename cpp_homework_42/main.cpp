//
//  main.cpp
//  cpp_homework_42
//
//  Created by Mark Semenov on 21.12.2022.
//

#include <iostream>
#include "MyString.hpp"
using namespace std;

int main() {
    MyString str1("Hello world!");
    str1.Print();
    cout << str1.MyStrLen() << endl;

    str1.Input();
    str1.Print();
    cout << str1.MyStrLen() << endl;

    MyString str2;
    str1.MyStrcpy(str2);
    str2.Print();

    cout << str1.MyStrStr("methi") << endl;
    cout << str1.MyStrStr("fefew") << endl;

    cout << str1.MyChr('I') << endl;

    MyString str3(" Ok, all tests is passed :)");
    str1.MyStrCat(str3);
    str1.Print();

    str1.MyDelChr('i');
    str1.Print();

    MyString str4;
    str1.MyStrcpy(str4);
    cout << str1.MyStrCmp(str2) << endl; // -1
    cout << str2.MyStrCmp(str1) << endl; // 1
    cout << str1.MyStrCmp(str4) << endl; // 0
}
