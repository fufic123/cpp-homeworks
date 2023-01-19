//
//  PhoneBook.cpp
//  cpp_homework_40
//
//  Created by Mark Semenov on 15.01.2023.
//

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    persons = nullptr;
    length = 0;
}

PhoneBook::PhoneBook(int length) {
    this->length = length;
}

PhoneBook::PhoneBook(Person* persons, int length): PhoneBook(length) {
    this->persons = new Person[length];
    for (int i = 0; i < length; i++) this->persons[i] = persons[i];
}

PhoneBook::PhoneBook(const PhoneBook& phoneBook) {
    length = phoneBook.length;
    persons = new Person[phoneBook.length];
    for (int i = 0; i < phoneBook.length; i++) persons[i] = phoneBook.persons[i];
}

PhoneBook::~PhoneBook() { delete[] persons; }

void PhoneBook::Print() {
    for (int i = 0; i < length; i++) {
        persons[i].Print();
        std::cout << "--------------------------------" << std::endl;
    }
}

void PhoneBook::PrintNames() {
    for (int i = 0; i < length; i++) {
        std::cout << i + 1 << ". " << persons[i].GetName() << std::endl;
    }
}

void PhoneBook::AddPersonData() {
    Person* tmp = new Person[length + 1];
    for (int i = 0; i < length; i++) {
        tmp[i] = persons[i];
    }

    Person person;
    person.Init();

    tmp[length] = person;
    delete[] persons;
    persons = tmp;
    length++;
}

void PhoneBook::AddPersonData(const Person& person) {
    Person* tmp = new Person[length + 1];
    for (int i = 0; i < length; i++) {
        tmp[i] = persons[i];
    }
    tmp[length] = person;
    delete[] persons;
    persons = tmp;
    length++;
}

void PhoneBook::DeletePerson(int index) {
    Person* tmp = new Person[length - 1];
    int i = 0, j = 0;
    while (i < length - 1) {
        if (j == index) j++;
        else {
            tmp[i] = persons[j];
            i++;
            j++;
        }
    }
    delete[] persons;
    persons = tmp;
    length--;
}

void PhoneBook::Search(char* name) {
    for (int i = 0; i < length; i++) {
        if (strlen(name) > 2 && strlen(persons[i].GetName()) > 2) {
            int count = 0;
            for (int j = 0; j < 3; j++) {
                if (name[j] == persons[i].GetName()[j]) count++;
            }
            if (count == 3) {
                persons[i].Print();
                std::cout << "-------------------------------------" << std::endl;
            }
        }
    }
}

Person* PhoneBook::GetPersons() const { return persons; }
int PhoneBook::GetSize() const { return length; }

void PhoneBook::SetPhoneBook(Person* persons, int length) {
    this->length = length;
    if (this->persons != nullptr) delete[] this->persons;
    this->persons = new Person[length];
    this->persons = persons;
}

void PhoneBook::operator=(const PhoneBook& phoneBook) {
    if (this->persons != nullptr) delete[] this->persons;
    length = phoneBook.length;
    persons = new Person[phoneBook.length];
    for (int i = 0; i < phoneBook.length; i++) {
        persons[i] = phoneBook.persons[i];
    }
}
