//
//  main.cpp
//  cpp_homework_16
//
//  Created by Mark Semenov on 16.06.2022.
//

#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, const char * argv[]) {
    int dhp, dd, shp, sd, ns;

    cout << "                                " << "\n";
    cout << "      (_                      _)" << "\n";
    cout << "      / \\_     (      )     _/ \\" << "\n";
    cout << "     /    \\    |\\\\^^//|    /    \\" << "\n";
    cout << "    |      |   ( 0  0 )   |      |" << "\n";
    cout << "   /        \\   \\    /   /        \\" << "\n";
    cout << "  |          |  .(oo).  |          |" << "\n";
    cout << " /           \\_/  --  \\_/           \\" << "\n";
    cout << "|             (        )             |" << "\n";
    cout << " \\/\\/\\/\\/\\/\\/\\/\\      /\\/\\/\\/\\/\\/\\/\\/" << "\n";
    cout << " (   (   (   / |  /\\  | \\   )   )   ) " << "\n";
    cout << "           <(  | |  | |  )>" << "\n";
    cout << "          <__\\.|_|  |_|./__>" << "\n";
    cout << "           ^^   ^    ^   ^^" << "\n";

    cout << "\n" << "NAME: Dragon" << "\n";
    cout << "DAMAGE: ";
    cin >> dd;
    cout << "HP: ";
    cin >> dhp;

    cout << "     _____    /|\\" << "\n";
    cout << "    /|||||\\  / | \\" << "\n";
    cout << "   ||O|||O||   |" << "\n";
    cout << "   ||||L||||   |" << "\n";
    cout << "    \\|:::|/    |" << "\n";
    cout << "    / ||| \\    |" << "\n";
    cout << "  /|||||||||\\  |" << "\n";
    cout << " /|||||||||||\\/|" << "\n";
    cout << "||/ \\|||||/ \\|||" << "\n";
    cout << "||\\ / ||| \\  \\/|" << "\n";
    cout << " \\ | ||||| |   |" << "\n";
    cout << "   |||||||||   |" << "\n";
    cout << "   |||||||||   |" << "\n";
    cout << "   | | | | |   |" << "\n";
    cout << "   |/`\\|/`\\|   |" << "\n";

    cout << "\n" << "NAME: Spearman" << "\n";
    cout << "NUMBER OF SPEARMEN: ";
    cin >> ns;
    cout << "DAMAGE: ";
    cin >> sd;
    cout << "HP: ";
    cin >> shp;

    do {
        dhp = dhp - sd * ns;
        if (dhp < 0) {
            dhp = 0;
        }
        cout << "Spearmen attack --->\nDAMAGE = " << sd * ns << "\nDragon has " << dhp << " HP" << "\n\n";

        ns = ceil((shp * ns - dd) / shp);
        if (ns < 0) {
            ns = 0;
        }
        cout << "Dragon attacks --->\nDAMAGE = " << dd << "\n" << ns << " spearmen left" << "\n\n";


        if (dhp == 0) {
            cout << "Spearmen are win" << "\n";
            break;
        }
        else if (ns == 0) {
            cout << "Dragon is win" << "\n";
            break;
        }

    } while (true);
}
