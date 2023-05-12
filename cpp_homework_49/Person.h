#pragma once
#include <iostream>
using namespace std;

class Person{
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
    friend ostream& operator << (ostream& o, const Person& p);
};

Person::Person(const char* fullName){
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
}

Person::Person(const char* fullName, const char* homePhone): Person(fullName){
    this->homePhone = new char[strlen(homePhone) + 1];
    strcpy(this->homePhone, homePhone);
}

Person::Person(const char* fullName, const char* homePhone, const char* workPhone): Person(fullName, homePhone){
    this->workPhone = new char[strlen(workPhone) + 1];
    strcpy(this->workPhone, workPhone);
}

Person::Person(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone): Person(fullName, homePhone, workPhone){
    this->mobilePhone = new char[strlen(mobilePhone) + 1];
    strcpy(this->mobilePhone, mobilePhone);
}

Person::Person(){
    fullName = nullptr;
    homePhone = nullptr;
    workPhone = nullptr;
    mobilePhone = nullptr;
    additionalInfo = nullptr;
}

Person::Person(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo): Person(fullName, homePhone, workPhone, mobilePhone){
    this->additionalInfo = new char[strlen(additionalInfo) + 1];
    strcpy(this->additionalInfo, additionalInfo);
}

Person::Person(const Person& person){
    if (this->fullName != nullptr) delete[] this->fullName;
    if (this->homePhone != nullptr) delete[] this->homePhone;
    if (this->workPhone != nullptr) delete[] this->workPhone;
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;

    this->fullName = new char[strlen(person.fullName) + 1];
    strcpy(this->fullName, person.fullName);

    this->homePhone = new char[strlen(person.homePhone) + 1];
    strcpy(this->homePhone, person.homePhone);

    this->workPhone = new char[strlen(person.workPhone) + 1];
    strcpy(this->workPhone, person.workPhone);

    this->mobilePhone = new char[strlen(person.mobilePhone) + 1];
    strcpy(this->mobilePhone, person.mobilePhone);

    this->additionalInfo = new char[strlen(person.additionalInfo) + 1];
    strcpy(this->additionalInfo, person.additionalInfo);
}

Person::~Person(){
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
    delete[] additionalInfo;
}

void Person::Print(){
    if (fullName != nullptr) cout << fullName << "'s phone numbers:" << "\n";
    else cout << "• There are no phone numbers:" << "\n";

    if (homePhone != nullptr) cout << "• Home phone: " << homePhone << "\n";
    else cout << "• There are no home phones" << "\n";

    if (workPhone != nullptr) cout << "• Work phone: " << workPhone << "\n";
    else cout << "• There are no work phones" << "\n";

    if (mobilePhone != nullptr) cout << "• Mobile phone: " << mobilePhone << "\n";
    else cout << "• There are no mobile phones: None" << "\n";

    if (additionalInfo != nullptr) cout << "• Additional info: " << additionalInfo << "\n";
    else cout << "• There is no additional info" << "\n";
}

void Person::Init(){
    if (this->fullName != nullptr) delete[] this->fullName;
    if (this->homePhone != nullptr) delete[] this->homePhone;
    if (this->workPhone != nullptr) delete[] this->workPhone;
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;
    
    char buff[200];
    cin.ignore();

    cout << "Enter full name: ";
    cin.getline(buff, 200);
    this->fullName = new char[strlen(buff) + 1];
    strcpy(this->fullName, buff);

    cout << "Enter home phone: ";
    cin.getline(buff, 200);
    this->homePhone = new char[strlen(buff) + 1];
    strcpy(this->homePhone, buff);

    cout << "Enter work phone: ";
    cin.getline(buff, 200);
    this->workPhone = new char[strlen(buff) + 1];
    strcpy(this->workPhone, buff);

    cout << "Enter mobile phone: ";
    cin.getline(buff, 200);
    this->mobilePhone = new char[strlen(buff) + 1];
    strcpy(this->mobilePhone, buff);

    cout << "Enter additional info: ";
    cin.getline(buff, 200);
    this->additionalInfo = new char[strlen(buff) + 1];
    strcpy(this->additionalInfo, buff);
}

char* Person::GetName() const{
    return fullName;
}
char* Person::GetHomePhone() const{
    return homePhone;
}
char* Person::GetWorkPhone() const{
    return workPhone;
}
char* Person::GetMobilePhone() const{
    return mobilePhone;
}
char* Person::GetAdditionalInfo() const{
    return additionalInfo;
}

void Person::SetName(const char* fullName){
    if (this->fullName != nullptr) delete[] this->fullName;
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
}

void Person::SetHomePhone(const char* homePhone){
    if (this->homePhone != nullptr) delete[] this->homePhone;
    this->homePhone = new char[strlen(homePhone) + 1];
    strcpy(this->homePhone, homePhone);
}

void Person::SetWorkPhone(const char* workPhone){
    if (this->workPhone != nullptr) delete[] this->workPhone;
    this->workPhone = new char[strlen(workPhone) + 1];
    strcpy(this->workPhone, workPhone);
}

void Person::SetMobilePhone(const char* mobilePhone){
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    this->mobilePhone = new char[strlen(mobilePhone) + 1];
    strcpy(this->mobilePhone, mobilePhone);
}

void Person::SetAdditionalInfo(const char* additionalInfo){
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;
    this->additionalInfo = new char[strlen(additionalInfo) + 1];
    strcpy(this->additionalInfo, additionalInfo);
}

void Person::operator = (const Person& person){
    if (this->fullName != nullptr) delete[] this->fullName;
    if (this->homePhone != nullptr) delete[] this->homePhone;
    if (this->workPhone != nullptr) delete[] this->workPhone;
    if (this->mobilePhone != nullptr) delete[] this->mobilePhone;
    if (this->additionalInfo != nullptr) delete[] this->additionalInfo;

    this->fullName = new char[strlen(person.fullName) + 1];
    strcpy(this->fullName, person.fullName);

    this->homePhone = new char[strlen(person.homePhone) + 1];
    strcpy(this->homePhone, person.homePhone);

    this->workPhone = new char[strlen(person.workPhone) + 1];
    strcpy(this->workPhone, person.workPhone);

    this->mobilePhone = new char[strlen(person.mobilePhone) + 1];
    strcpy(this->mobilePhone, person.mobilePhone);

    this->additionalInfo = new char[strlen(person.additionalInfo) + 1];
    strcpy(this->additionalInfo, person.additionalInfo);
}

ostream& operator << (ostream& o, const Person& p){
    if (p.fullName != nullptr) o << p.fullName << "'s phone numbers:" << "\n";
    else o << "• There are no phone numbers:" << "\n";

    if (p.homePhone != nullptr) o << "• Home phone: " << p.homePhone << "\n";
    else o << "• There are no home phones" << "\n";

    if (p.workPhone != nullptr) o << "• Work phone: " << p.workPhone << "\n";
    else o << "• There are no work phones" << "\n";

    if (p.mobilePhone != nullptr) o << "• Mobile phone: " << p.mobilePhone << "\n";
    else o << "• There are no mobile phones" << "\n";

    if (p.additionalInfo != nullptr) o << "• Additional info: " << p.additionalInfo << "\n";
    else o << "• There is no additional info" << "\n";

    return o;
}
