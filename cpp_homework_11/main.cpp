//
//  main.cpp
//  dz
//
//  Created by Mark Semenov on 02.06.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a;
    string n[10] = {"Greater than 9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "1-9: ";
    cin >> a;

    if(a > 9){
        cout << n[0] << "\n";
    }
    else{
        cout << n[a] << "\n";
    }
}

