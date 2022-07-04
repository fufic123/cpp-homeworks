//
//  main.cpp
//  cpp_homework_21
//
//  Created by Mark Semenov on 04.07.2022.
//

#include <iostream>
#include <iomanip>
using namespace std;

int random(int min, int max) {
    int r = max - min + 1;
    return min + rand() % r;
}

int main(int argc, const char * argv[]) {
    
    //Task 1
    const int x = 4, y = 5;
    int numbers[y][x] = {};
    cout << "-----------------------" << "\n";
    while (true) {
        srand(time(NULL));
        for (int i = 0; i < y; i++) {
            cout << " |";
            for (int j = 0; j < x; j++) {
                numbers[i][j] = random(0, 100);
                cout << setw(3) << numbers[i][j] << " |";
            }
            cout << "\n";
            cout << "-----------------------" << "\n";
        }
        break;
    }
    cout << "\n";
    
    //Task 2
    const int s = 5;
    char l[s][s] = {};

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (i <= j) {
                l[i][j] = '*';
                cout << l[i][j] << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << "\n";
        
    }
    cout << "\n";

    //Task 3
    const int s = 5;
    char l[s][s] = {};
    
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            l[i][j] = '*';
            if (i <= s - j - 1) {
                l[i][j] = '*';
                cout << l[i][j] << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

}
