//
//  main.cpp
//  a
//
//  Created by Mark Semenov on 16.05.2022.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    //Task 1
    double number;

    cout << "duoble number: ";
    cin >> number;

    number = ceil(number * 100) / 100;

    cout << "round number = " << number;

    //Task 2
    int gst, bst;
    double bstp;

    cout << "Great students: ";
    cin >> bst;
    cout << "Bad students: ";
    cin >> gst;

    bstp = ((double)bst / (bst + gst)) * 100;
    bstp = ceil(bst * 100) / 100;

    cout << bstp;

    //Task 3
    double ds;
    int hours, mins, secs, rs;

    cout << "sec: ";
    cin >> ds;

    rs = 86400 - ds;
    hours = (rs - rs % 3600) / 3600;
    mins = (rs - rs % 60) / 60 - hours * 60;
    secs = rs - mins * 60 - hours * 3600;

    cout << hours << " hours " << mins << " minutes " << secs << " sec";

    //Task 4
    double sum, ir, end_sum;
    int months;

    cout << "sum: ";
    cin >> sum;
    cout << "months: ";
    cin >> months;
    cout << "ir: ";
    cin >> ir;

    end_sum = sum + sum * ir * months / 12 / 100;

    cout << "After " << months << " you'll take " << end_sum << " uah";

    //Task 5
    double r = 6.371 * 1000;
    const double pi = 3.141592653589793;
    long long S;

    S = 4 * pi (r*r);

    cout << S;

}
