//
//  main.cpp
//  cpp_homework_31
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    struct Pizza {
            float Cheese;
            float Sausage;
            float Tomato;
            float Ketchup;
            float Butter;
        };
    
    struct Computer {
            string CPU;
            string Motherboard;
            string VideoCard;
            int RAM;
            int StorageDevice;
        };


    struct House {
            int Toalets;
            int Doors;
            int Rooms;
            int Stairs;
            int Windows;
        };


    struct Kover {
            string Figure;
            string Picture;
            double Size;
            double Thickness;
            string Manufacturer;
        };


    struct Alex {
            string Name;
            int Age;
            int Growth;
            string Country;
            int Experience;
        };
}
