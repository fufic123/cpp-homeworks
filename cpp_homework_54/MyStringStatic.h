#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
    char* str;
    int length;
    static int count;
public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &copyStr);
    MyString(MyString&& moveStr);
    ~MyString();

    void Input();
    void Print();
    void MyStrcpy(MyString &obj);
    bool MyStrStr(const char *str);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString &b);
    void MyDelChr(char c);
    int MyStrCmp(MyString &b);

    static void ShowNumberOfObjects();
    const char* GetStr() const;

    MyString& operator = (const MyString& copy);
    MyString& operator = (MyString&& move);
};

ostream& operator << (ostream& o, const MyString& ms);

MyString::MyString()
{
    length = 80;
    str = new char[length + 1];
    MyString::count++;
}

MyString::MyString(const char* str)
{
    length = 0;
    while (str[length] != '\0') length++;
    this->str = new char[length + 1];
    for (int i = 0; i <= length; ++i) this->str[i] = str[i];
    MyString::count++;
}

MyString::MyString(const MyString& copyStr): length(copyStr.length)
{
    MyString::count++;
    str = new char[copyStr.length + 1];
    strcpy(str, copyStr.str);
}

MyString::MyString(MyString&& moveStr): length(moveStr.length), str(moveStr.str)
{
    MyString::count++;
    moveStr.length = 80;
    moveStr.str = new char[moveStr.length + 1];
}

MyString::~MyString()
{
    delete[] str;
    MyString::count--;
}

void MyString::Input()
{
    char* buff = new char[100000 + 1];
    cout << "Enter string: ";
    cin.getline(buff, 100000);
    this->str = new char[strlen(buff) + 1];
    strcpy(this->str, buff);
    length = strlen(str);
    delete[] buff;
}

void MyString::Print()
{
    cout << str << "\n";
}

void MyString::MyStrcpy(MyString& obj)
{
    delete[] obj.str;
    obj.length = length;
    obj.str = new char[length + 1];
    for (int i = 0; i <= length; ++i)
    {
        obj.str[i] = str[i];
    }
}

bool MyString::MyStrStr(const char* str)
{
    int strLength = strlen(str);
    if (strLength > length)
    {
        return false;
    }
    for (int i = 0; i <= length - strLength; ++i)
    {
        bool found = true;
        for (int j = 0; j < strLength; ++j)
        {
            if (this->str[i + j] != str[j])
            {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}

int MyString::MyChr(char c)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen()
{
    return length;
}

void MyString::MyStrCat(MyString& b)
{
    int newLength = length + b.length;
    char* newStr = new char[newLength + 1];
    for (int i = 0; i < length; i++)
    {
        newStr[i] = str[i];
    }
    for (int i = 0; i <= b.length; i++)
    {
        newStr[length + i] = b.str[i];
    }
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyDelChr(char c)
{
    int newLength = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) newLength++;
    }
    char* newStr = new char[newLength + 1];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) newStr[j++] = str[i];
    }
    newStr[newLength] = '\0';
    delete[] str;
    str = newStr;
    length = newLength;
}

int MyString::MyStrCmp(MyString& b)
{
    if (length > b.length)
    {
        return -1;
    }
    if (length < b.length)
    {
        return 1;
    }
    return 0;
}

void MyString::ShowNumberOfObjects()
{
    if (MyString::count)
    {
        cout << MyString::count << " object(s)" << "\n";
    }
    else
    {
        cout << "There are no objects" << "\n";
    }
}

const char* MyString::GetStr() const
{
    return str;
}

ostream& operator<<(ostream& o, const MyString& ms)
{
    o << ms.GetStr();
    return o;
}

MyString& MyString::operator = (const MyString& copy) {
    if (this != &copy) {
        if (copy.str == nullptr) {
            str = nullptr;
            length = copy.length;
            return *this;
        }
        length = copy.length;
        if (str != nullptr) delete[] str;
        str = new char[copy.length + 1];
        strcpy(str, copy.str);
    }
    return *this;
}

MyString& MyString::operator = (MyString&& move) {
    if (this != &move) {
        delete[] str;
        length = move.length;
        str = move.str;
        move.length = 80;
        move.str = new char[move.length + 1];
    }
    return *this;
}
