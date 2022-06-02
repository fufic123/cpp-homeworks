//
//  main.cpp
//  cpp_homework_5
//
//  Created by Mark Semenov on 02.06.2022.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    //Task 1 (with c)
    int a = 1;
    int b = 2;
    int c;
    
    c = a;
    a = b;
    b = c;
    
    cout << a << "\n" << b;
    
    //Task 2 (without c)
    int a = 1;
    int b = 2;
    int c;
    
    swap(a, b);
    
    cout << a << "\n" << b;
}
