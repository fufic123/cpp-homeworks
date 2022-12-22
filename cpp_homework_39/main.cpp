//
//  main.cpp
//  cpp_homework_39
//
//  Created by Mark Semenov on 22.12.2022.
//

#include <iostream>
#include <limits>
using namespace std;

class Fraction {
private:
    // Fields
    int num;
    int den;

public:
    // Constructors
    Fraction() {
        num = 1;
        den = 1;
    }
    Fraction(int n, int d) {
        if (d == 0) {
            num = numeric_limits<int>::max();
            den = 1;
        }
        else {
            num = n;
            den = d;
        }
    }

    // Setters
    void setNumerator(int num) { this->num = num; }
    void setDenominator(int den) { this->den = den; }

    // Getters
    int getNumerator() { return num; }
    int getDenominator() { return den; }

    // Methods
    
    // Print fraction
    void showFraction() {
        printf("%d/%d\n", num, den);
    }

    // Fraction reduction
    void reduction() {
        for (int i = den; i >= 1; i--) {
            if (num % i == 0 && den % i == 0) {
                int num_res = num / i;
                int den_res = den / i;
                num = num_res;
                den = den_res;
            }
        }
    }

    // Sum
    void sumOfFractions(int user_num, int user_den) {
        num = (num * user_den) + (den * user_num);
        den *= user_den;
        reduction();
        showFraction();
    }

    // Difference
    void differenceOfFractions(int user_num, int user_den) {
        num = (num * user_den) - (den * user_num);
        den *= user_den;
        reduction();
        showFraction();
    }

    // Multiplication
    void multiplicationOfFractions(int user_num, int user_den) {
        num *= user_num;
        den *= user_den;
        reduction();
        showFraction();
    }

    // Division
    void divisionOfFractions(int user_num, int user_den) {
        num *= user_den;
        den *= user_num;
        reduction();
        showFraction();
    }
};

int main() {
    Fraction f = Fraction(3, 0);

    // 2147483647/1 (inf)
    f.showFraction();

    // 4/8 = 1/2
    f.setNumerator(4);
    f.setDenominator(8);
    f.reduction();
    f.showFraction();

    // 6/9 + 2/8 = 66/72 = 11/12
    f.setNumerator(6);
    f.setDenominator(9);
    f.sumOfFractions(2, 8);

    // 5/12 - 5/3 = -15/12 = -5/4
    f.setNumerator(5);
    f.setDenominator(12);
    f.differenceOfFractions(5, 3);

    // 6/13 * 26/9 = 156/117 = 4/3
    f.setNumerator(6);
    f.setDenominator(13);
    f.multiplicationOfFractions(26, 9);

    // 18/14 : 9/24 = 432/126 = 24/7
    f.setNumerator(18);
    f.setDenominator(14);
    f.divisionOfFractions(9, 24);
}
