#pragma once
#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int kg;

public:
    Animal() = default;
    Animal(string n, int k) {
        name = n;
        kg = k;
    }
    virtual void Print() = 0;
};

struct IAnimal {
    virtual void Eat() = 0;
    virtual void Move() = 0;
};

struct IBird 
{ 
    virtual void Fly() = 0; 
};

struct ISwim 
{ 
    virtual void Swim() = 0; 
};

class Cat: public Animal, public IAnimal {
private:
    string color;

public:
    Cat(string n, int k, string c) 
    { 
        color = c; 
        name = n;
        kg = k;
    }
    void Print() {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
        cout << "Color: " << color << "\n";
    }
    void Eat() 
    {
        cout << "Cat eats" << "\n"; 
    }
    void Move() 
    { 
        cout << "Cat moves" << "\n"; 
    }
};

class Elephant : public Animal, public IAnimal {
private:
    string color;

public:
    Elephant(string n, int k, string c) {
        color = c;
        name = n;
        kg = k;
    }
    void Print() {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
        cout << "Color: " << color << "\n";
    }
    void Eat() 
    {
        cout << "Elephant eats" << "\n"; 
    }
    void Move()
    { 
        cout << "Elephant moves" << "\n"; 
    }
};

class Penguin : public Animal, public IAnimal, public ISwim {
private:
    string color;

public:
    Penguin(string n, int k, string c) 
    { 
        color = c; 
        name = n;
        kg = k;
    }

    void Print() {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
        cout << "Color: " << color << "\n";
    }

    void Eat() 
    { 
        cout << "Penguin eats" << "\n"; 
    }

    void Move() 
    {
        cout << "Penguin moves" << "\n"; 
    }

    void Swim() 
    {
        cout << "Penguin swims" << "\n"; 
    }
};

class Parrot : public Animal, public IAnimal, public IBird {
private:
    string color;

public:
    Parrot(string n, int k, string c)
    { 
        color = c; 
        name = n;
        kg = k;
    }

    void Print() {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
        cout << "Color: " << color << "\n";
    }

    void Eat() 
    { 
        cout << "Parrot eats" << "\n"; 
    }
    void Move() 
    { 
        cout << "Parrot moves" << "\n"; 
    }
    void Fly() 
    { 
        cout << "Parrot flies" << "\n"; 
    }
};

class Duck : public Animal, public IAnimal, public IBird, public ISwim {
private:
    string color;

public:
    Duck(string n, int k, string c)
    { 
        color = c; 
        name = n;
        kg = k;
    }

    void Print() {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
        cout << "Color: " << color << "\n";
    }

    void Eat() { cout << "Duck eats" << "\n"; }
    void Move() { cout << "Duck moves" << "\n"; }
    void Fly() { cout << "Duck flies" << "\n"; }
    void Swim() { cout << "Duck swims" << "\n"; }
};