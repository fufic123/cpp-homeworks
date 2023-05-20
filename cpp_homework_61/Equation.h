#pragma once
#include <iostream>

class Equation {
protected:
    float a;
    float b;

public:
    Equation() {
        a = 0;
        b = 0;
    }
    Equation(float a, float b) {
        this->a = a;
        this->b = b;
    }

    virtual void ShowAnswer() = 0;
};

class LinearEquation : public Equation {
public:
    LinearEquation() {
        a = 0;
        b = 0; 
    }

    LinearEquation(float k, float b) {
        this->a = k;
        this->b = b;
    }

    void ShowAnswer() { 
        if (a == 0 && b == 0) cout << "Root is any number" << "\n";
        else if (a == 0 && b != 0) cout << "No roots" << "\n";
        else cout << "Root of the equation: " << -b / a << "\n"; 
    }
};

class QuadraticEquation : public Equation {
private:
    float c;

public:
    QuadraticEquation() {
        a = 0;
        b = 0;
        c = 0;
    }

    QuadraticEquation(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void ShowAnswer() {
        if (a == 0) 
        { 
            cout << "Not a quadratic equation!" << "\n"; 
            return; 
        }
        if (pow(b, 2) - 4 * a * c < 0) cout << "No real solutions" << "\n";
        else if (pow(b, 2) - 4 * a * c == 0) cout << "Root of the equation: " << -b / (2 * a) << "\n";
        else {
            cout << "First root: " << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << "\n";
            cout << "Second root: " << (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << "\n";
        }
    }
};