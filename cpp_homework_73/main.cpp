#include <iostream>

class Animal {
public:
    virtual void speak() const = 0;
};

class Frog : public Animal {
public:
    void speak() const override {
        std::cout << "Frog: Ribbit!" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Cat: Meow!" << std::endl;
    }

    void scratch(bool didHomework) {
        if (didHomework) {
            std::cout << "Cat: I'm not scratching. Homework is done." << std::endl;
        } else {
            std::cout << "Cat: I'm scratching!" << std::endl;
        }
    }

    void purr() const {
        std::cout << "Cat: Purring... Purr purr!" << std::endl;
    }
};

int main() {
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    animals[0] = new Frog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Frog();

    for (int i = 0; i < numAnimals; i++) {
        animals[i]->speak();
    }

    Cat* cat = dynamic_cast<Cat*>(animals[2]);
    if (cat) {
        cat->scratch(false);
        cat->purr();
    }

    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    return 0;
}
