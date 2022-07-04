//
//  main.cpp
//  cpp_homework_20
//
//  Created by Mark Semenov on 01.07.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    //Task 1
   int n, l, k = 1;
   cin >> n >> l;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < l; j++) {
           cout << "*";
       }
       cout << "\n";
       for (int a = 0; a < k; a++) {
           cout << " ";
       }
       k++;
   }

   //Task 2
   int n, a = 0;
   cin >> n;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < a; j++) {
           cout << " ";
       }
       cout << "***" << "\n";
       for (int j = 0; j < a; j++) {
           cout << " ";
       }
       cout << "  *" << "\n";
       for (int j = 0; j < a; j++) {
           cout << " ";
       }
       cout << "  *" << "\n";
       a += 2;
   }
   
   //Task 3
   int n, h, q, a = 1, b = 0, c = 2, d = 0;
   cin >> h >> q;
   for (int i = 0; i < q; i++) {
       n = h + q - c;
       a += d;
       for (int i = 0; i < h; i++) {
           for (int j = 0; j < n - b; j++) {
               cout << " ";
           }
           for (int f = 0; f < a; f++) {
               cout << "*";
           }
           a += 2;
           b += 1;
           cout << "\n";
       }
       c += 1;
       a = 1;
       b = 0;
       d += 2;
   }
   for (int r = 0; r < 3; r++) {
       n = h + q - 4;
       for (int k = 0; k < n; k++) {
           cout << " ";
       }
       for (int t = 0; t < 5; t++) {
           cout << "*";
       }
       cout << "\n";
   }
}
