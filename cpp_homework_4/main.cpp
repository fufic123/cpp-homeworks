//
//  main.cpp
//  cpp_homework_4
//
//  Created by Mark Semenov on 02.06.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //Task 1 (average)
    double a,b,c;
    cin >> a >> b >> c;
    cout << (a + b + c)/3;
    
    //Task 2 (ax + b = 0 | x - ?)
    double a, b;
    cin >> a >> b;
    cout << "x = " << -b/a;
    
    //Task 3 (S and C of circle)
    const double pi = 3.14159265359;
    double r;
    cin >> r;
    cout << "S = " << pi * r * r << "\n" << "C = " << 2 * pi * r << "\n";
    
    //Task 4 (km to see miles and land miles)
    double km;
    const double lm = 0.62;
    const double sm = 0.53995680346;
    
    cin >> km;
    cout << km * lm << " = lm\n" << km * sm << " = sm\n";
    
    
}
