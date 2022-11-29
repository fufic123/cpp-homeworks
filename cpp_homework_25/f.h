//
//  f.h
//  cpp_homework_25
//
//  Created by Mark Semenov on 29.11.2022.
//

#ifndef f_h
#define f_h
#include <iostream>
#include <vector>
using namespace std;

auto FillZeroes(int width, int height)
{
    vector<vector<int>> vectorA;


    for (int i = 0; i < height; i++)
    {
        vector<int> vectorB;
        for (int y = 0; y < width; y++)
        {
            vectorB.push_back(0);
        }
        vectorA.push_back(vectorB);
    }


    return vectorA;
}


auto FillCin(int width, int height)
{
    vector<vector<int>> vectorA;


    for (int i = 0; i < height; i++)
    {
        vector<int> vectorB;
        for (int y = 0; y < width; y++)
        {
            int user;
            cin >> user;
            vectorB.push_back(user);
        }
        vectorA.push_back(vectorB);
    }


    return vectorA;
}


int Sum(vector<vector<int>> vectorA, int width, int height)
{
    int count = 0;


    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < width; y++)
        {
            count += vectorA[i][y];
        }
    }


    return count;
}


int Min(vector<vector<int>> vectorA, int width, int height)
{
    int count = 999999999;


    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < width; y++)
        {
            if (vectorA[i][y] < count)
                count = vectorA[i][y];
        }
    }


    return count;
}


int Max(vector<vector<int>> vectorA, int width, int height)
{
    int count = 0;


    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < width; y++)
        {
            if (vectorA[i][y] > count)
                count = vectorA[i][y];
        }
    }


    return count;
}


int Below(vector<vector<int>> vectorA, int width, int height)
{
    int count = 0, sum = 0, ans;


    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < width; y++)
        {
            count++;
            sum += vectorA[i][y];
        }
    }


    ans = sum / count;
    return ans;
}


#endif /* f_h */
