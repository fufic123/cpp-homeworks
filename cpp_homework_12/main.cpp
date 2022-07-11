//
//  main.cpp
//  cpp_homework_12
//
//  Created by Mark Semenov on 02.06.2022.
//

#include <iostream>
#include <string>
using namespace std;

int random(int min, int max) {
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

int main(int argc, const char * argv[]) {
    //Task 1
    float h, w, i, res;
    string g;
    
    cout << "Height: ";
    cin >> h;
    cout << "Weight: ";
    cin >> w;
    cout << "Boy or girl(g/b): ";
    cin >> g;
    
    if (g == "g") {
        i = h - 110;
        res = w - i;
        if (res < 0) {
            cout << "You need to gain " << res * -1 << " kg";
        }
        else if (res > 0) {
            cout << "You need to lose " << res << " kg";
        }
        else {
            cout << "You are OK";
        }
    }
    else if (g == "b") {
        i = h - 100;
        res = w - i;
        if (res < 0) {
            cout << "You need to gain " << res * -1 << " kg";
        }
        else if (res > 0) {
            cout << "You need to lose " << res << " kg";
        }
        else {
            cout << "You are OK";
        }
    }
    else {
        cout << "error";
    }
    
    //Task 2
    int bm, bd;
    string p[] = {"There will be more cases than you expected. It's worth starting the day with the most important; this approach will allow you to avoid many worries and worries.",
        "You should not rush. Morning is hardly suitable for important matters and serious decisions. Most likely, you will need time to gather your thoughts, tune in the right way.",
        "At the beginning of the day, it can be difficult to keep calm. This time will be quite stressful, especially for those who have planned trips, important meetings, participation in some social events.",
        "Be persistent and you will achieve great things. When choosing what to focus on today, rely on intuition; do what causes genuine interest.",
        "If you have big plans for this day, be prepared to act on your own. Even trusted allies will hardly be able to help you today, but they can unwittingly create problems.",
        "Do not rush. The first half of the day should be spent calmly, if possible avoiding communication with people who often unbalance you, make you worry.",
        "Many issues today will be resolved faster and easier than expected. And all because you will take a fresh look at what previously seemed familiar and completely natural.",
        "Look at things realistically. Much will seem possible today, but if you are not overly optimistic, you will quickly understand where you will succeed and where problems may arise.",
        "Any important meetings should be planned for the first half of the day. It is at this time that it will be especially easy for you to get along with both close people and new acquaintances.",
        "Don't rush anywhere. This day is well suited for putting things in order, solving issues that have long required attention, doing things that have not been reached for a long time.",
        "The day will hardly go without excitement, but you will not lose your head. The experience gained earlier will be very useful: thanks to it, you will not take risks where this can be avoided, make informed decisions.",
        "It's a good day for solving many serious issues. You don't miss anything, pay attention to important details, carefully consider every step."
    };
    cout << "your birthday day: ";
    cin >> bd;
    cout << "your birthday month: ";
    cin >> bm;
    
    if (bd < 1 || bd > 31 || bm < 1 || bm > 12) {
        cout << "error" << "\n";
    }
    else {
        if ((bd >= 21 & bm == 3) || (bd <= 20 & bm == 4)) {
            cout << "You are an Aries. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 21 && bm == 4) || (bd <= 20 && bm == 5)) {
                cout << "You are a Taurus. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 21 & bm == 5) || (bd <= 20 & bm == 6)) {
                cout << "You are Gemini. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 21 & bm == 6) || (bd <= 22 & bm == 7)) {
                cout << "You are Cancer. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 23 & bm == 7) || (bd <= 22 & bm == 8)) {
                cout << "You are Leo. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 23 & bm == 8) || (bd <= 22 & bm == 9)) {
                cout << "You are a Virgo. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 23 & bm == 9) || (bd <= 22 && bm == 10)) {
                cout << "You are Libra. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 23 & bm == 10) || (bd <= 22 & bm == 11)) {
                cout << "You are a Scorpio. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 23 & bm == 11) || (bd <= 21 & bm == 12)) {
                cout << "You are a Sagittarius. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 22 & bm == 12) || (bd <= 19 & bm == 1)) {
                cout << "You are a Capricorn. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 20 & bm == 1) || (bd <= 19 & bm == 2)) {
                cout << "You are an Aquarius. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else if ((bd >= 20 & bm == 2) || (bd <= 20 & bm == 3)) {
                cout << "You are Pisces. Your Prediction:" << p[random(0, 11)] << "\n";
            }
            else {
                cout << "error" << "\n";
            }
        }
    
    //Task 3
    int m = 0, a1, a2, a3, a4, a5, r = 0;
    string q[] = {"In what year did WW2 start?\n1) 1941\n2) 1939\n3) 1918\n4) There was no such", "What is the name of the main ninja turtle?\n1) Leonardo\n2) Michelangelo\n3) Ratatouille\n 4) Me", "Who wrote 'The Hound of the Baskervilles'?\n1) Artur Doyl\n2) Idk\n3) Leonardo da Vinci\n4) Me", "Who directed the movie 'Titanic'?\n1) James Cameron\n2) Me\n3) Ryan Gosling\n 4) Leonardo Dicaprio", "Who is better Max Verstappen or Lewis Hamilton?\n1) Max\n2) Lewis\n3) Nicolas Goatifi"};
    
    cout << q[r];
    cin >> a1;
    if (a1 == 2) {
        ++r;
        cout << "+1000";
        m += 1000;
        cout << q[r];
        cin >> a2;
        if (a2 == 1) {
            ++r;
            cout << "+1000";
            m += 1000;
            cout << q[r];
            cin >> a3;
            if (a3 == 1) {
                ++r;
                cout << "+1000";
                m += 1000;
                cout << q[r];
                cin >> a4;
                if (a4 == 1) {
                    ++r;
                    cout << "+1000";
                    m += 1000;
                    cout << q[r];
                    cin >> a5;
                    if (a5 == 3) {
                        cout << "You nailed it" << "\n" << "+10000";
                        m += 10000;
                    }
                    else if (a5 == 2) {
                        cout << "Yes Sir" << "\n" << "+5000";
                        m += 5000;
                    }
                    else if (a5 == 1) {
                        cout << "OK" << "\n" << "+1000";
                        m += 1000;
                    }
                    else {
                        cout << "Game over. You get " << m;
                    }
                }
                else {
                    cout << "Game over. You get " << m;
                }
            }
            else {
                cout << "Game over. You get " << m;
            }
        }
        else {
            cout << "Game over. You get " << m;
        }
    }
    else {
        cout << "Game over. You get " << m;
    }
}
