//
//  main.cpp
//  cpp_homework_10
//
//  Created by Mark Semenov on 02.06.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    //Task 1
    char symbol;
    cin >> symbol;

    if (static_cast<int>(symbol) >= 48 && static_cast<int>(symbol) <= 57) {
        cout << "Number";
    }
    else if (symbol == 'a' || symbol == 'b' || symbol == 'c' || symbol == 'd' || symbol == 'e' || symbol == 'f' || symbol == 'g' || symbol == 'h' || symbol == 'i' || symbol == 'j' || symbol == 'k' || symbol == 'l' || symbol == 'm' || symbol == 'n' || symbol == 'o' || symbol == 'p' || symbol == 'q' || symbol == 'r' || symbol == 's' || symbol == 't' || symbol == 'u' || symbol == 'v' || symbol == 'w' || symbol == 'x' || symbol == 'y' || symbol == 'z' || symbol == 'A' || symbol == 'B' || symbol == 'C' || symbol == 'D' || symbol == 'E'|| symbol == 'F' || symbol == 'G' || symbol == 'H' || symbol == 'I' || symbol == 'J' || symbol == 'K' || symbol == 'L' || symbol == 'M' || symbol == 'N' || symbol == 'O' || symbol == 'P' || symbol == 'Q' || symbol == 'R' || symbol == 'S' || symbol == 'T' || symbol == 'U' || symbol == 'V' || symbol == 'W' || symbol == 'X' || symbol == 'Y' || symbol == 'Z') {
        cout << "Letter";
    }
    else {
        cout << "Symbol";
    }
    
    //Task 2
    int a;
    cin >> a;

    if (a % 3 == 0 && a % 5 == 0 && a % 7 == 0) {
        cout << "Ok";
    }
    else {
        cout << "Not OK";
    }

    //Task 3
    int a;
    cin >> a;

    if (a >= 1000 && a <= 9999) {
        cout << "4";
    }
    else if (a >= 100 && a <= 999) {
        cout << "3";
    }
    else if (a >= 10 && a <= 99) {
        cout << "2";
    }
    else if (a >= 0 && a <= 9) {
        cout << "1";
    }

    //Task 4
    int Palindrom;
    cin >> Palindrom;


    if (Palindrom / 10000 % 10 == Palindrom % 10 && Palindrom / 10 % 10 == Palindrom / 1000 % 10) {
        cout << "OK";
    }
    else {
        cout << " Not OK";
    }


    //Task 5
    int lx, ly, rx, ry, x, y;
    
    cin >> lx >> ly >> rx >> ry >> x >> y;

    if (x <= lx && x >= rx && y <= ly && y >= ry) {
        cout << "OK";
    }
    else {
        cout << "Not OK";
    }

}

