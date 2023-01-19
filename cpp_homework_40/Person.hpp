//
//  Person.hpp
//  cpp_homework_40
//
//  Created by Mark Semenov on 15.01.2023.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#pragma once
class Person {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

    Person(const char* fullName);
    Person(const char* fullName, const char* homePhone);
    Person(const char* fullName, const char* homePhone, const char* workPhone);
    Person(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone);

public:
    Person();
    Person(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo);
    Person(const Person& person);
    ~Person();

    void Print();
    void Init();

    char* GetName() const;
    char* GetHomePhone() const;
    char* GetWorkPhone() const;
    char* GetMobilePhone() const;
    char* GetAdditionalInfo() const;

    void SetName(const char* fullName);
    void SetHomePhone(const char* homePhone);
    void SetWorkPhone(const char* workPhone);
    void SetMobilePhone(const char* mobilePhone);
    void SetAdditionalInfo(const char* additionalInfo);

    void operator = (const Person& person);
};

#endif /* Person_hpp */
