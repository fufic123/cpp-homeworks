#include <iostream>
#include "Employer.h"
#include "Equation.h"

int main() {
    Employer* emp[3] = { new President("Mark"), new Manager("Bohdan"), new Worker("Svyatik") };
    for (int i = 0; i < 3; i++) 
        emp[i]->Show();
    cout << "\n";

    LinearEquation linear(3, 9);
    linear.ShowAnswer();

    QuadraticEquation quadratic(4, 7, 12);
    quadratic.ShowAnswer();

    Equation* eq[2] = { 
        new LinearEquation(4, 8), new QuadraticEquation(1, -3, 2) 
    };
    for (int i = 0; i < 2; i++) 
        eq[i]->ShowAnswer();

    cout << "\n";
}