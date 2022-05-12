//
//  main.cpp
//  erjvbekr
//
//  Created by Mark Semenov on 12.05.2022.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    //1
    double a;
    double b;

    cout << "first number: ";
    cin >> a;
    cout << "second number: ";
    cin >> b;

    cout << (int)a + (int)b << "\n" << (a - (int)a) + (b - (int)b) << "\n";
    
    //2
    float km;
    float m;
    float w; // сами понимаете почему такое В

    cout << "S:";
    cin >> km;
    cout << "Time:";
    cin >> m;

    w = (km * 1000) / (m * 60);

    cout << (int)w << "m/s or " << (int)(w * 60 / 1000) << "km/h\n";
    
    //3
    int sec;
    double t;

    cout << "time from start working day(in seconds): ";
    cin >> sec;

    t = (8 * 60 * 60) - sec;

    if (t < 0)
    {
        cout << "Your working day already finished xD\n";
    }
    else
    {
        cout << "You have to work" << (int)(t/3600) << "h more\n";
    }
    
    //4
    float prc;
    int n;
    float disc;

    cout << "Price of the laptop: ";
    cin >> prc;
    cout << "N: ";
    cin >> n;
    cout << "Discount(%): ";
    cin >> disc;

    cout << (prc*n) - ((prc * n) / 100 * disc) << "\n";
    
    //5
    float mov;
    float w;
    float res;
    int hour, min, sec;
    
    cout << "Movie size(GB): ";
    cin >> mov;
    cout << "Speed of your internet(MB per second): ";
    cin >> w;
    
    res = mov * 1024 / w;
    
    hour = res / 60 / 60;
    min = (res - (hour * 3600)) / 60;
    sec = res - (hour * 3600 + min * 60);
    
    cout << "Download will continue: " << hour << " hours, " << min << " minutes and " << sec << " second\n";

}
