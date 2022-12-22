//
//  MyString.hpp
//  cpp_homework_42
//
//  Created by Mark Semenov on 22.12.2022.
//

#ifndef MyString_hpp
#define MyString_hpp
#pragma once
class MyString {
private:
    char* str;
    int length;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& copyStr);
    ~MyString();
    // Input from keyboard
    void Input();

    // Print to console
    void Print();

    // String copy
    void MyStrcpy(MyString& obj);

    // Search for a substring in a string
    bool MyStrStr(const char* str);

    // Search for a character in a string
    int MyChr(char c);

    // String length
    int MyStrLen();

    // String concatenation
    void MyStrCat(MyString& b);

    // Remove the specified character
    void MyDelChr(char c);

    // String comparison
    int MyStrCmp(MyString& b);
};
#endif /* MyString_hpp */
