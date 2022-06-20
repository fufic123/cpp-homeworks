//
//  main.cpp
//  cpp_homework_19
//
//  Created by Mark Semenov on 20.06.2022.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    //TASK 1
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << i * j << "⚪";
        }
        cout << "\n";
    }
        
    //TASK 2
    int n, n1, n2 = 0, a;

    cin >> n;
    n1 = n;

    while (n > 0) {
        a = n % 10;
        n2 = n2 * 10 + a;
        n /= 10;
    }
    if (n2 == n1) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }

    //TASK 3
    int h, w, l;

    cout << "height: ";
    cin >> h;

    cout << "width: ";
    cin >> w;

    cout << "length: ";
    cin >> l;

    for (int i = 0; i < w / 2; i++) {
        cout << " ";
    }
    for (int i = 0; i < l; i++) {
        cout << "⚪";
    }
    for (int i = 1; i < w / 2; i++) {
        cout << "\n";

        for (int j = 0; j < w / 2 - i; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 2; j < l / 2; j++) {
            cout << " ";
        }
        for (int j = 0; j < l / 2 - i; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << "⚪";
    }
    cout << "\n";

    for (int i = 0; i < l; i++) {
        cout << "⚪";
    }
    for (int i = 1; i < w / 2; i++) {
        cout << " ";
    }
    cout << "⚪";
    for (int i = 2; i < h / 2; i++) {
        cout << "\n";
        cout << "⚪";

        for (int j = 1; j < w / 2; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 2; j < l - w / 2; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 1; j < l / 2; j++) {
            cout << " ";
        }
        cout << "⚪";
    }
    cout << "\n";
    cout << "⚪";

    for (int i = 1; i < w / 2; i++) {
        cout << " ";
    }
    for (int i = 0; i < l; i++) {
        cout << "⚪";
    }
    for (int i = 0; i < w / 2 - 1; i++) {

        cout << "\n";
        cout << "⚪";

        for (int j = 2; j < w / 2 - i; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 1; j < l - w / 2 + i; j++) {
            cout << " ";
        }
        cout << "⚪";
        for (int j = 2; j < w / 2 - i; i++) {
            cout << " ";
        }
        cout << "⚪";
    }
    cout << "\n";
    for (int i = 0; i < l; i++) {
        cout << "⚪";
    }

    //TASK 4
    int n = 0;

    for (int i = 2; i <= 10000000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                n++;
            }
        }
        if (n == 2) {
            cout << i << "\n";
        }
        n = 0;
    }

    //TASK 5
    for (int i = 0; i <= 10000000; i++) {

        int s = 0;
        int n = i;

        for (; n > 0; n /= 10) {

            int a = n % 10;

            if (i < 10) {
                s = s + pow(a, 1);
            }
            else if (i >= 10 && i < 100) {
                s = s + pow(a, 2);
            }
            else if (i >= 100 && i < 1000) {
                s = s + pow(a, 3);
            }
            else if (i >= 1000 && i < 10000) {
                s = s + pow(a, 4);
            }
            else if (i >= 10000 && i < 100000) {
                s = s + pow(a, 5);
            }
            else if (i >= 100000 && i < 1000000) {
                s = s + pow(a, 6);
            }
            else if (i >= 1000000 && i < 10000000) {
                s = s + pow(a, 7);
            }
            else {
                s = s + pow(a, 8);
            }
        }

        if (s == i) {
            cout << i << "\n";
        }
    }
}



