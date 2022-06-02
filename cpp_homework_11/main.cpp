//
//  main.cpp
//  cpp_homework_11
//
//  Created by Mark Semenov on 02.06.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    //Task 1
    double x1, y1, x2, y2;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    
    if (x1 == y1 && x2 == y2)
    {
        cout << "||";
    }
    else
    {
        cout << "not ||";
    }

    //Task 2
    double num;
    double answer;
    
    cin >> num;
    answer = num - (int)num;

    if (answer == 0.0 || 0) {
        cout << "Don't have it";
    }
    else {
        cout << "Ok";
    }

    //Task 3
    int h, m, s;
    
    cin >> h >> m >> s;

    if (h >= 24 || m >= 60 || s >= 60 || h >= -1 || m >= -1 || s >= -1) {
        cout << "error";
    }
    else {
        cout << "Ok";
    }

    //Task 4
    int a;
    int b;
    int c;
    
    cin >> a;
    
    c = (a / 100000 % 10) + (a / 10000 % 10) + (a / 1000 % 10);
    b = (a / 100 % 10) + (a / 10 % 10) + (a % 10);


    if (c == b) {
        cout << "Ok";
    }
    else {
        cout << "error";
    }

    //Task 5
    int t;
    
    cin >> t;
    
    if (t >= 0 && t <= 6) {
        cout << "Good Night";
    }
    else if (t >= 7 && t <= 11) {
        cout << "Morning!";
    }
    else if (t >= 12 && t <= 16) {
        cout << "Good afternoon";
    }
    else if (t >= 17 && t <= 21) {
        cout << "Good evening";
    }
    else {
        cout << "error";
    }
}
