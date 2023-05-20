#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

int main() 
{
    vector<Point> pointVect;

	for (int i = 0; i < 5; i++) 
    {
		Point tmp;
		cin >> tmp;
		pointVect.push_back(tmp);
	}

	for (int i = 0; i < 5; i++)
    { 
        cout << pointVect[i] << "\n";
    }
}