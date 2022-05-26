//
//  main.cpp
//  a
//
//  Created by Mark Semenov on 19.05.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //Task 1 (how much does it cost to paint a room)
    double h,w,l;
    double n,m,r;
    double res;

    cout << "Lenth: ";
    cin >> l;
    cout << "Height: ";
    cin >> h;
    cout << "Width: ";
    cin >> w;

    cout << "how much paint is spent on 1 square meter of wall?\n";
    cin >> n;
    cout << "what percentage of the wall is occupied by windows and doors?\n";
    cin >> m;
    cout << "how much does a liter of paint cost?\n";
    cin >> r;

    res = ((l * h * w) - (l * h * w)*m/100)/n*r;

    cout << res;

    //Task 2 (minimum number)
    float a,b,c;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    cout << min(a,b,c);

    //Task 3 (more, less than or equal to 0)
    double a;

    cout << "a: ";
    cin >> a;

    if (a < 0){
        cout << "a < 0";
    }
    if (a > 0){
        cout << "a > 0";
    }
    else{
        cout << "a = 0";
    }
    
    //Task 4 (calculator)
    double n1,n2,res1;
    int lg;
    
    cout << "Lets go?(1 - yea; 2 - no): ";
    cin >> lg;
    if (lg != 1 && lg != 2){
        cout << "Lets go?(1 - yea; 2 - no): ";
        cin >> lg;
    }
    
    if (lg == 1){
        cout << "n1: ";
        cin >> n1;
        cout << "n2: ";
        cin >> n2;
        
        cout << "\n1) n1 + n2\n2) n1 - n2\n3) n1 * n2\n4) n1 / n2\n5) n1 % n2\n";
        cin >> res1;
        
        if (res1 == 1){
            cout << n1 + n2 << "\n";
        }
        if (res1 == 2){
            cout << n1 - n2 << "\n";
        }
        if (res1 == 3){
            cout << n1 * n2 << "\n";
        }
        if (res1 == 4){
            if (n2 < 0){
                cout << "Error: n2 < 0. WRITE n2 AGAIN: ";
                cin >> n2;
            }
            else{
                cout << n1 / n2 << "\n";
            }
        }
        if (res1 == 5){
            cout << (int)n1 % (int)n2 << "\n";
        }
        
        cout << "Continue?(1 - yea; 2 - no): ";
        cin >> lg;
        if (lg != 1 && lg != 2){
            cout << "Continue?(1 - yea; 2 - no): ";
            cin >> lg;
        }
        if (lg == 1) main();
    }
    if (lg == 2){
        cout << "Bye!";
    }
    
    
}
