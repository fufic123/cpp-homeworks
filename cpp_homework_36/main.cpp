//
//  main.cpp
//  cpp_homework_36
//
//  Created by Mark Semenov on 22.12.2022.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string term;
    string temp;
    char res[200];
    cout << "Введите слово: ";
    cin >> term;

    ifstream(file);
    file.open("files/db.txt", ios::in | ios::app);

    char buffer[50];
    while (!file.eof()) {
        file.getline(buffer, 50);
        temp = buffer;
    }
    if (term[term.length() - 2] == temp[temp.length() - 3] &&
        term[term.length() - 1] == temp[temp.length() - 2]) {
        cout << temp;
        }
    file.close();
}
