//
//  main.cpp
//  cpp_homework_33
//
//  Created by Mark Semenov on 04.12.2022.
//

#include <iostream>
using namespace std;

void myswap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
//    int arr[10] {44,54,3,2,1,7,8,99,22,10};
//    int arr_copy[10];
//    int* ptr = arr;
//    int min = *arr;
//    int max = *arr;
//    int* ptr_for_copy = arr;
//
//    for (short i = 0, k = 9; i < 5; ++i, --k) {
//        int n = *(ptr + i);
//        *(ptr + i) = *(ptr + k);
//        *(ptr + k) = n;
//
//    }
//    for (short i = 0; i < 10; ++i) {
//        *(ptr_for_copy + i) = *(ptr + i);
//    }
//
//    for (short i = 0; i < 10; ++i) {
//        cout << *(ptr + i) << "\t";
//    }
//    cout << "\n";
//    for (short i = 0; i < 10; ++i) {
//        cout << *(ptr_for_copy + i) << "\t";
//    }
//    for (short i = 0; i < 10; ++i) {
//        if(*(ptr + i) < min) {
//            min = *(arr + i);
//        }
//    }
//
//    for (short i = 0; i < 10; ++i) {
//        if(*(ptr + i) > max) {
//            max = *(arr + i);
//        }
//    }
//    cout << min << "\n" << max;
//    int n;
//    cout << "W: ";
//    cin >> n;
//    for (short i = 0; i < n; ++i) {
//        for (short k = 0; k < 10; ++k) {
//            myswap((ptr + k), (ptr + k +1));
//    }}
//    for (short i = 0; i < 10; ++i) {
//            cout << *(ptr + i) << "\t";
//        }
}

