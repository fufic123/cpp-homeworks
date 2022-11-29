//
//  main.cpp
//  cpp_homework_27
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
using namespace std;

int Fibonachi(int number)
{
    if (number == 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    return Fibonachi(number - 1) + Fibonachi(number - 2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    
    cout << Fibonachi(n);
}
