//
//  main.cpp
//  cpp_homework_38
//
//  Created by Mark Semenov on 22.12.2022.
//

#include <iostream>
using namespace std;

void first(int* arr1, int* arr2, int size1, int size2);
void second(int* arr, int size, int num);
void third(int* arr, int size, int index);

int main(int argc, const char * argv[]) {
// insert code here...
//1
   int size1, size2;
   cin >> size1;
   cin >> size2;
   int* first = new int[size1];
   for (int i = 0; i < size1; i++) {
       first[i] = rand() % 100;
       cout << first[i] << "\t";
   }
   cout << endl;
   int* second = new int[size2];
   for (int i = 0; i < size2; i++) {
       second[i] = rand() % 100;
       cout << second[i] << "\t";
   }
   cout << endl;
   first(first, second, size1, size2);

//2
   int size3;
   cin >> size3;
   int* third = new int[size3];
   for (int i = 0; i < size3; i++) {
       third[i] = rand() % 100;
       cout << third[i] << "\t";
   }
   cout << endl;
   int rand_num = rand() % 100;
   second(third, size3, rand_num);

//3
   int size4;
   cin >> size4;
   int* fourth = new int[size4];
   for (int i = 0; i < size4; i++) {
       fourth[i] = rand() % 100;
       cout << fourth[i] << "\t";
   }
   cout << endl;
   third(fourth, size4, 5);
}

void first(int* arr1, int* arr2, int size1, int size2) {
   int *arr_res = new int[size1 + size2];
   for (int i = 0; i < size1; i++) {
       *arr_res++ = arr1[i];
   }
   for (int i = 0; i < size2; i++) {
       *arr_res++ = arr2[i];
   }
   arr_res -= size1 + size2;
   for (int i = 0; i < size1 + size2; i++) {
       cout << *arr_res++ << "\t";
   }
   cout << endl;
}

void second(int* arr, int size, int num) {
   int* arr_res = new int[size + 1];
   for (int i = 0; i < size; i++) {
       *arr_res++ = arr[i];
   }
   *arr_res++ = num;
   arr_res -= size + 1;
   for (int i = 0; i < size + 1; i++) {
       cout << *arr_res++ << "\t";
   }
   cout << endl;
}

void third(int* arr, int size, int index) {
   for (int i = index - 1; i < size; i++) {
       arr[i] = arr[i + 1];
   }
   size--;
   for (int i = 0; i < size; i++) {
       cout << *arr++ << "\t";
   }
   cout << endl;
}
