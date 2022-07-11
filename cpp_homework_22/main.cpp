//
//  main.cpp
//  cpp_homework_21
//
//  Created by Mark Semenov on 11.07.2022.
//

#include <iostream>
using namespace std;

int random(int min, int max) {
    srand(time(NULL));
    int n = min + rand() % (max - min + 1);
    return n;
}

int main(int argc, const char * argv[]) {
    int counter = 0, a, m, n;
    
    cout << "places";
    cin >> a;
    cout << "row: ";
    cin >> m;
    cout << "n: ";
    cin >> n;
    
    cout << "info: " << "\n\n";
    
    int arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = random(0, 1);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0)  {
                counter++;
                if (counter == a) {
                    cout << "place is free" << "\n";
                }
            }
            else {
                counter = 0;
                cout << "place is taken" << "\n";
            }
        }
        counter = 0;
        cout << "\n";
    }
}
