//
//  main.cpp
//  cpp_homework_14
//
//  Created by Mark Semenov on 06.06.2022.
//

#include <iostream>
using  namespace std;

int main(int argc, const char * argv[]) {
    
    //Task 1
    int st;
    int end;
    double f;

    cout << "Range: ";
    cin >> st >> end;

    while (st <= end) {
        f = (st * 1.8) + 32;
        cout << st << "\t\t" << f << "\n";
        st++;
    }
    
    //Task 2
    int n;
    int a;
    int rn = 0;

    cout << "Your number: ";
    cin >> n;

    while (n != 0) {
        a = n % 10;
        rn = rn * 10 + a;
        n /= 10;
    }
    cout << rn;
    
    //Task 3
    int num;
    int a;

    cout << "Your number: ";
    cin >> num;

    a = num;
    while (a != 0) {
        if (num % a == 0)
        {
            cout << a << " ";
        }
        a--;
    }
}
