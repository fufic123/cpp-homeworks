//
//  main.cpp
//  cpp_homework_15
//
//  Created by Mark Semenov on 11.07.2022.
//

#include <iostream>
using namespace std;

int random(int MIN, int MAX) {
    int k = MAX - MIN + 1;
    return MIN + rand() % k;
}

int main(int argc, const char * argv[]) {
    //Task 1
    const int s = 5;
    int n[s] = {};
    for (int i = 0; i < s; i++) {
        cout << "Enter number #" << i + 1 << ": ";
        cin >> n[i];
    }
    for (int i = s - 1; i >= 0; i--) {
        cout << n[i] << "\n";
    }
    cout << "\n";

    //Task 2
    const int s = 20;
    int n[s] = {};
    srand(time(NULL));
    rand();
    for (int i = 0; i < s; i++) {
        n[i] = rand();
        if (i % 2 == 0) {
            cout << n[i] << "\n";
        }
    }
    cout << "\n";

    //Task 3
    const int s = 10;
    int n[s] = {}, a = 0, sum = 0;
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < s; i++) {
            n[i] = random(-10, 10);
            if (n[i] > 0) {
                a++;
                sum += n[i];
            }
        }
        break;
    }
    cout << "Quantity = " << n << "\nSum = " << sum << "\nAverage = " << (double)sum / a << "\n\n";

    //Task 4
    const int s = 100;
    int symbol[s] = {}, letter = 0, num = 0, symb = 0;
    while (true) {
        srand(time(0));
        for (int i = 0; i < s; i++) {
            symbol[i] = random(0, 127);
            if (symbol[i] >= 48 && symbol[i] <= 57) {
                num++;
                cout << (char)symbol[i] << ", ";
            }
            else if ((symbol[i] >= 65 && symbol[i] <= 90) || (symbol[i] >= 97 && symbol[i] <= 122)) {
                letter++;
                cout << (char)symbol[i] << ", ";
            }
            else {
                symb++;
                cout << (char)symbol[i] << ", ";
            }
        }
        break;
    }
    cout << "\n";
    cout << "Letters are " << letter << "%\nNumbers are " << num << "%\nSymbols are " << symb << "%\n\n";

    //Task 5
    const int s = 100;
    int n[s] = {}, a, c = 0;
    cin >> a;
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < s; i++) {
            n[i] = rand();
            if (n[i] == a) {
                c++;
            }
        }
        break;
    }
    cout << "Number repeats " << c << " times" << "\n\n";

    //Task 6
    const int s = 20;
    int n[s] = {}, count, sum = 0;
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < s; i++) {
            n[i] = random(-10, 30);
            if (n[i] < 0) {
                count = i;
                break;
            }
        }
        for (int i = count; i < s; i++) {
            n[i] = random(-10, 30);
            sum += n[i];
        }
        break;
    }
    cout << "Sum after first negative number is equal to " << sum << "\n\n";

    //Task 7
    const int s = 20;
    int n[s] = {}, max = 0, min, max_i, min_i;
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < s; i++) {
            n[i] = rand();
            cout << n[i] << " ";
            if (n[i] > max) {
                max = n[i];
                max_i = i;
            }
        }
        min = max;
        for (int i = 0; i < s; i++) {
            if (n[i] < min) {
                min = n[i];
                min_i = i;
            }
        }
        break;
    }
    cout << "\n";
    cout << max << " #" << max_i + 1 << endl << min << " #" << min_i + 1 << "\n\n";

    //Task 8
    const int s = 100;
    double n[s] = {};
    int counter = 0;
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < s; i++) {
            n[i] = round(rand() / (double)RAND_MAX * 10000) / 10;
            if (n[i] - (int)n[i] == 0) {
                counter++;
            }
        }
        break;
    }
    cout << counter << "% of numbers don`t have a fractional part\n\n";

    //Task 9
    const int s = 200;
    int n[s] = {}, o = 0, t = 0, th = 0;
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < s; i++) {
            n[i] = random(0, 200);
            if (n[i] / 10 == 0) {
                o++;
            }
            else if (n[i] / 10 > 0 & n[i] / 10 < 10) {
                t++;
            }
            else {
                th++;
            }
        }
        break;
    }
    cout << "Single-digit numbers: " << o / 2.0 << "%" << "\n";
    cout << "Double-digit numbers: " << t / 2.0 << "%" << "\n";
    cout << "Three-digit numbers: " << th / 2.0 << "%" << "\n";
}
