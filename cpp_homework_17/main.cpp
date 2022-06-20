//
//  main.cpp
//  cpp_homework_17
//
//  Created by Mark Semenov on 20.06.2022.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {

    //TASK 1
    int n;
    int i = 1, a = 0;

    cin >> n;

    for (; i <= n; i++) {
        if (n % i == 0) {
            a++;
        }
    }
    if (a == 2) {
        cout << "Ok" << "\n";
    }
    else {
        cout << "Error" << "\n";
    }
    
    //TASK 2
    int n, a, b;

    cin >> n;

    for (;;) {
        a = n % 10;
        b = n % 100 / 10;
        if (a == b) {
            cout << "error" << "\n";
            break;
        }
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    if (a != b) {
        cout << "Ok" << "\n";
    }
    
    //TASK 3
    int n, a, a;
    int c = 0;

    cin >> n;

    for (;;) {
        a = n % 10;
        a = n % 100 / 10;
        if (a < b) {
            cout << "Ok" << "\n";
            ++c;
            break;
        }
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    if (c == 0) {
        cout << "Error" << endl;
    }
    
    //TASK 4
    int n = 10000000;
    int a, b, c, d, e, f, g, h;
    int i = 0;

    for (;n <= 99999999; n++) {

        if (n % 12345 == 0) {

            a = n % 10;
            b = n % 100 / 10;
            c = n % 1000 / 100;
            d = n % 10000 / 1000;
            e = n % 100000 / 10000;
            f = n % 1000000 / 100000;
            g = n % 10000000 / 1000000;
            h = n % 100000000 / 10000000;

            if (a != b && a != c && a != d && a != e && a != f && a != g && a != h && b != c && b != d && b != e && b != f && b != g && b != h && c != d && c != e && c != f && c != g && c != h && d != e && d != f && d != g && d != h && e != f && e != g && e != h && f != g && f != h && g != h) {
                cout << n << "\n";
                i++;
            }
        }
    }
    cout << i << "\n";

    //TASK 5
    srand(time(NULL));
    int r = -100 + rand() % (100 - -100 + 1);
    int n;
    int pos = 0, neg = 0, zero = 0, even = 0, odd = 0;

    for (;;) {
        for (int i = 0; i < 100; i++) {

            n = r;

            if (n > 0) {
                pos++;
            }
            else if (n < 0) {
                neg++;
            }
            else {
                zero++;
            }
            if (n % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }
        break;
    }

    cout << "Positive: " << pos << "%" << "\n";
    cout << "Negative: " << neg << "%" << "\n";
    cout << "Zero: " << zero << "%" << "\n";
    cout << "Even: " << even << "%" << "\n";
    cout << "Odd: " << odd << "%" << "\n";
}


