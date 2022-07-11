//
//  main.cpp
//  cpp_homework_22
//
//  Created by Mark Semenov on 11.07.2022.
//

#include <iostream>
using namespace std;

//Task 1
void ShowMessage(int n, char s, bool b) {
    if (b == true) {
        for (int i; i < n; i++) {
            cout << s;
        }
        cout << "\n";
    }
    else if (b == false) {
        for (int i; i < n; i++) {
            cout << s << "\n";
        }
    }
}

//Task 2
void Cube(int n) {
    cout << n*n*n << "\n";
}

//Task 3
void isPrime(int n) {
    int i = n;
    if (n % i == 0) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}

int main(int argc, const char * argv[]) {
    //testing
    ShowMessage(20, '@', true);
    Cube(5);
    isPrime(5);
}
