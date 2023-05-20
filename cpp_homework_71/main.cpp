#include <iostream>
#include <list>
#include "Point.h"
using namespace std;

int main() {
	list<Point> pointList;
	for (int i = 0; i < 5; i++) 
    {
		Point tmp;
		cin >> tmp;
		pointList.push_back(tmp);
	}

	for (Point point : pointList) 
    {
        cout << point << "\n";
    }
}