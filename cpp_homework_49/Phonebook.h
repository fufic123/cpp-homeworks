#include <iostream>
#include "Person.h"

class PhoneBook{
private:
    Person* persons;
    int length;

    PhoneBook(int length);

public:
    PhoneBook();
    PhoneBook(Person* persons, int length);
    PhoneBook(const PhoneBook& phoneBook);
    ~PhoneBook();

    void Print();
    void PrintNames();
    void AddPersonData();
    void AddPersonData(const Person& person);
    void DeletePerson(int index);
    void Search(char* name);

    Person* GetPersons() const;
    int GetSize() const;

    void SetPhoneBook(Person* persons, int length);

    PhoneBook& operator = (const PhoneBook& phoneBook);
    Person& operator [] (int index);
    friend ostream& operator << (ostream& o, const PhoneBook& pb);
};


PhoneBook::PhoneBook(){
    persons = nullptr;
    length = 0;
}

PhoneBook::PhoneBook(int length){
    this->length = length;
}

PhoneBook::PhoneBook(Person* persons, int length): PhoneBook(length){
    this->persons = new Person[length];
    for (int i = 0; i < length; i++) this->persons[i] = persons[i];
}

PhoneBook::PhoneBook(const PhoneBook& phoneBook){
    length = phoneBook.length;
    persons = new Person[phoneBook.length];
    for (int i = 0; i < phoneBook.length; i++) persons[i] = phoneBook.persons[i];
}

PhoneBook::~PhoneBook(){
    delete[] persons;
}

void PhoneBook::Print(){
    for (int i = 0; i < length; i++)
    {
        persons[i].Print();
        cout << "--------------------------------" << "\n";
    }
}

void PhoneBook::PrintNames(){
    for (int i = 0; i < length; i++)
    {
        cout << i + 1 << ". " << persons[i].GetName() << "\n";
    }
}

void PhoneBook::AddPersonData(){
    Person* tmp = new Person[length + 1];
    for (int i = 0; i < length; i++)
    {
        tmp[i] = persons[i];
    }

    Person person;
    person.Init();

    tmp[length] = person;
    delete[] persons;
    persons = tmp;
    length++;
}

void PhoneBook::AddPersonData(const Person& person){
    Person* tmp = new Person[length + 1];
    for (int i = 0; i < length; i++)
    {
        tmp[i] = persons[i];
    }
    tmp[length] = person;
    delete[] persons;
    persons = tmp;
    length++;
}

void PhoneBook::DeletePerson(int index){
    Person* tmp = new Person[length - 1];
    int i = 0, j = 0;
    while (i < length - 1)
    {
        if (j == index) j++;
        else
        {
            tmp[i] = persons[j];
            i++;
            j++;
        }
    }
    delete[] persons;
    persons = tmp;
    length--;
}

void PhoneBook::Search(char* name){
    for (int i = 0; i < length; i++){
        if (strlen(name) > 2 && strlen(persons[i].GetName()) > 2){
            int count = 0;
            for (int j = 0; j < 3; j++){
                if (name[j] == persons[i].GetName()[j]) count++;
            }
            if (count == 3){
                persons[i].Print();
                cout << "-------------------------------------" << "\n";
            }
        }
    }
}

Person* PhoneBook::GetPersons() const{
    return persons;
}

int PhoneBook::GetSize() const{
    return length;
}

void PhoneBook::SetPhoneBook(Person* persons, int length){
    this->length = length;
    if (this->persons != nullptr) delete[] this->persons;
    this->persons = new Person[length];
    this->persons = persons;
}

PhoneBook& PhoneBook::operator = (const PhoneBook& phoneBook){
    if (&phoneBook != this)
    {
        if (this->persons != nullptr) delete[] this->persons;
        length = phoneBook.length;
        persons = new Person[phoneBook.length];
        for (int i = 0; i < phoneBook.length; i++) persons[i] = phoneBook.persons[i];
    }
    return *this;
}

Person& PhoneBook::operator [] (int index){
    if (index >= 0 && index < length) return persons[index];
    else throw "Outside the array";
}

ostream& operator << (ostream& o, const PhoneBook& pb){
    for (int i = 0; i < pb.length; i++)
    {
        o << pb.persons[i];
        o << "--------------------------------" << "\n";
    }
    return o;
}
