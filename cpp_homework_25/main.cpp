//
//  main.cpp
//  cpp_homework_25
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
#include <vector>
#include "f.h"
using namespace std;

auto FillZeroes(int width, int height);
auto FillCin(int width, int height);
int Sum(vector<vector<int>> vectorA, int width, int height);
int Min(vector<vector<int>> vectorA, int width, int height);
int Max(vector<vector<int>> vectorA, int width, int height);
int Below(vector<vector<int>> vectorA, int width, int height);

int main()
{
    //Task 1
    vector<vector<int>> vectorA;
    vectorA = FillZeroes(10, 5);

    //Task 2
    vector<vector<int>> vectorB;
    vectorB = FillCin(5, 6);

    //Task 3
    Sum(vectorB, 5, 6);

    //Task 4
    Min(vectorB, 5, 6);

    //Task 5
    Max(vectorB, 5, 6);

    //Task 6
    Below(vectorB, 5, 6);
}

