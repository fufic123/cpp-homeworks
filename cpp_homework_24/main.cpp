//
//  main.cpp
//  cpp_homework_24
//
//  Created by Mark Semenov on 11.07.2022.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    //Task 1
    const int s = 10;
    int n[s] = {};

    srand(time(0));
    rand();

    for (int i = 0; i < s; i++) {
        n[i] = rand();
        cout << n[i] << " ";
    }
    cout << "\n";
    reverse(n, n + s);

    for (int i = 0; i < s; i++) {
        cout << n[i] << " ";
    }
    cout << "\n\n";

    //Task 2
    const int s = 5, s1 = 10;
    int n[s] = {}, n1[s] = {}, n2[s1] = {};

    cout << "First array: ";
    for (int i = 0; i < s; i++) {
        n[i] = rand();
        cout << n[i] << " ";
    }
    cout << "\n";
    cout << "Second array: ";
    for (int i = 0; i < s; i++) {
        n1[i] = rand();
        cout << n1[i] << " ";
    }
    for (int i = 0, j = 0; i < s1; i += 2, j++) {
        n2[i] = n[j];
    }
    for (int i = 1, j = 0; i < s1; i += 2, j++) {
        n2[i] = n1[j];
    }
    cout << "\n";
    cout << "Third array: ";
    for (int i = 0; i < s1; i++) {
        cout << n2[i] << " ";
    }
    cout << "\n\n";

    //Task 3
    const int s = 20;
    int n[s] = {}, nr[s] = {}, n1 = 0;

    for (int i = 0; i < s; i++) {
        n[i] = rand() % 201 - 100;
        cout << n[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < s; i++) {
        if (n[i] > 0) {
            nr[n] = n[i];
            n1++;
        }
    }
    for (int i = 0; i < s; i++) {
        if (n[i] == 0) {
            nr[n] = n[i];
            n1++;
        }
    }
    for (int i = 0; i < s; i++) {
        if (n[i] < 0) {
            nr[n] = n[i];
            n1++;
        }
    }
    for (int i = 0; i < s; i++) {
        cout << nr[i] << " ";
    }
    cout << "\n";
}
