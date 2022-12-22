//
//  MyString.cpp
//  cpp_homework_42
//
//  Created by Mark Semenov on 22.12.2022.
//

#include "MyString.hpp"
#include <iostream>
using namespace std;

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
}

MyString::MyString(const char* str) {
    length = 0;
    while (str[length] != '\0') length++;
    this->str = new char[length + 1];
    for (int i = 0; i <= length; ++i) this->str[i] = str[i];
}

MyString::MyString(const MyString& copyStr): length(copyStr.length) {
    str = new char[copyStr.length + 1];
    strcpy_s(str, std::strlen(copyStr.str) + 1, copyStr.str);
}

MyString::~MyString() {
    delete[] str;
}

void MyString::Input() {
    char* buff = new char[100000 + 1];
    cout << "Enter string -> ";
    cin.getline(buff, 100000);
    this->str = new char[strlen(buff) + 1];
    strcpy_s(this->str, strlen(buff) + 1, buff);
    length = strlen(str);
    delete[] buff;
}

void MyString::Print() {
    cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj) {
    delete[] obj.str;
    obj.length = length;
    obj.str = new char[length + 1];
    for (int i = 0; i <= length; ++i) {
        obj.str[i] = str[i];
    }
}

bool MyString::MyStrStr(const char* str) {
    int strLength = strlen(str);
    if (strLength > length) return false;
    for (int i = 0; i <= length - strLength; ++i) {
        bool found = true;
        for (int j = 0; j < strLength; ++j) {
            if (this->str[i + j] != str[j]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}

int MyString::MyChr(char c) {
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() {
    return length;
}

void MyString::MyStrCat(MyString& b) {
    int newLength = length + b.length;
    char* newStr = new char[newLength + 1];
    for (int i = 0; i < length; i++) newStr[i] = str[i];
    for (int i = 0; i <= b.length; i++) newStr[length + i] = b.str[i];
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyDelChr(char c) {
    int newLength = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) newLength++;
    }
    char* newStr = new char[newLength + 1];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) newStr[j++] = str[i];
    }
    newStr[newLength] = '\0';
    delete[] str;
    str = newStr;
    length = newLength;
}

int MyString::MyStrCmp(MyString& b) {
    if (length > b.length) return -1;
    if (length < b.length) return 1;
    return 0;
}
