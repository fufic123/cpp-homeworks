//
//  main.cpp
//  cpp_homework_40
//
//  Created by Mark Semenov on 15.01.2023.
//

#include <iostream>
#include "Person.hpp"
#include "PhoneBook.hpp"

int main() {
    int size = 3;
    Person* persons = new Person[size];
    persons[0] = Person("Nikita Terpilovskyi", "+380666436435", "+380672056473", "+380972619238", "Some information 1");
    persons[1] = Person("Vladislav Kolisnyk", "+380675839238", "+380978758493", "+380374758493", "Some information 2");
    persons[2] = Person("Lahoda Daniil", "+380666758655", "+380674937582", "+380972957165", "Some information 3");

    PhoneBook db(persons, size);

    int choice = 0;
    while (true) {
        userChoice:
            std::cout << "What do you want to do?" << std::endl;
            std::cout << "-------------------------------------" << std::endl;
            std::cout << "1. See all persons" << std::endl;
            std::cout << "2. Add person" << std::endl;
            std::cout << "3. Delete person" << std::endl;
            std::cout << "4. Search person by name" << std::endl;
            std::cout << "5. Exit" << std::endl;
            std::cout << "-------------------------------------" << std::endl;

            std::cout << ">>> ";
            std::cin >> choice;

            system("cls");
            std::cout << std::endl;

        if (choice == 1) {
            char symb;
            std::cout << "All persons:" << std::endl;
            db.Print();
            std::cout << "To return enter \"r\": ";
            do {
                std::cin >> symb;
            } while (symb != 'r');
            system("cls");
            goto userChoice;
        }

        else if (choice == 2) {
            while (true) {
                userChoiceAdd:
                    std::cout << "Select:" << std::endl;
                    std::cout << "----------------------------" << std::endl;
                    std::cout << "1. Add a new person" << std::endl;
                    std::cout << "2. Return" << std::endl;
                    std::cout << "----------------------------" << std::endl;
                
                    int ch = 0;
                
                    std::cout << ">>> ";
                    std::cin >> ch;

                    if (ch == 1) {
                        db.AddPersonData();
                        system("cls");
                        goto userChoiceAdd;
                    }
                    else if (ch == 2) {
                        break;
                    }
                    else {
                        system("cls");
                        goto userChoiceAdd;
                    }
            }
            system("cls");
            goto userChoice;
        }

        else if (choice == 3) {
            while (true) {
                userChoiceDelete:
                    std::cout << "Select person to delete:" << std::endl;
                    std::cout << "------------------------" << std::endl;
                    db.PrintNames();
                    std::cout << db.GetSize() + 1 << ". Return" << std::endl;
                    std::cout << "------------------------" << std::endl;

                    int ch = 0;

                    std::cout << ">>> ";
                    std::cin >> ch;

                    if (ch > 0 && ch < db.GetSize() + 1) {
                        db.DeletePerson(ch - 1);
                    }
                    else if (ch == db.GetSize() + 1) {
                        break;
                    }
                    else {
                        system("cls");
                        goto userChoiceDelete;
                    }
            }
            system("cls");
            goto userChoice;
        }

        else if (choice == 4) {
            char symb;
            char buf[200];
            std::cout << "Enter a name to search:" << std::endl;
            std::cin.ignore();
            std::cout << ">>> ";
            std::cin.getline(buf, 200);

            system("cls");

            std::cout << "Results for \"" << buf << "\": " << std::endl;
            db.Search(buf);

            std::cout << "To return enter \"r\": ";
            do {
                std::cin >> symb;
            } while (symb != 'r');
            system("cls");
            goto userChoice;
        }

        else if (choice == 5) {
            break;
        }

        else {
            system("cls");
            goto userChoice;
        }
    }
    delete[] persons;
}
