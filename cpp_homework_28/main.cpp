//
//  main.cpp
//  cpp_homework_28
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Task 1
    const int size = 5;
    int i = 0;
    int *arr = new int[size]{1, 2, 3, 4, 5};
    int *copyarr = new int[size];


    for (int* ptr = arr; ptr <= &arr[4]; ptr++)
    {
        copyarr[i++] = *ptr;
    }


    for (int* ptr = copyarr; ptr <= &copyarr[4]; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << "\n\n";


    delete[] arr;
    delete[] copyarr;



    //Task 2
    const int size_arr = 5;
    int* array = new int[size_arr] {1, 2, 3, 4, 5};


    for (int* ptr = array + 4; ptr >= &array[0]; ptr--)
    {
        cout << *ptr << " ";
    }
    cout << "\n\n";


    delete[] array;



    //Task 3
    int num = 0, f = 0, s = 0;
    const int size_arraychik = 5;
    int** arraychik = new int* [size_arraychik];
    int** copyarraychik = new int* [size_arraychik];


    for (int i = 0; i < size_arraychik; i++)
    {
        arraychik[i] = new int[size_arraychik];
        for (int j = 0; j < size_arraychik; j++)
        {
            arraychik[i][j] = num++;
        }
        num = 0;
    }


    for (int i = 0; i < size_arraychik; i++)
    {
        copyarraychik[i] = new int[size_arraychik];
    }


    for (int** ptr = arraychik + 16; ptr >= &arraychik[0]; ptr--)
    {
        copyarraychik[f++][s] = **ptr;
        if (f % 10 == 0)
        {
            s++;
        }
    }


    for (int** ptr = copyarraychik; ptr <= &copyarraychik[0]; ptr++)
    {
        cout << **ptr << " ";
    }


    delete[] arraychik;
    delete[] copyarraychik;
}
