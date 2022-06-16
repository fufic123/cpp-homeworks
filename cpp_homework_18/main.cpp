//
//  main.cpp
//  cpp_homework_18
//
//  Created by Mark Semenov on 16.06.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int width, height;
    
    cout << "width: ";
    cin >> width;
    cout << "height: ";
    cin >> height;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((x + 1) % 2 == 0 & x <= width * 0.38 & y <= height * 0.38 & (y + 1) % 2 == 0){
                 cout << "⬜";
            }
            else if (x <= width * 0.4 & y <= height * 0.4) {
                cout << "🟦";
            }
            else if (y % 2 == 0) {
                cout << "🟥";
            }
            else {
                cout << "⬜";
            }
        }
        cout << "\n";
    }
}

