#include <iostream>
using namespace std;


class Herbivore {
public:
    virtual ~Herbivore() {}
    virtual void eatGrass() = 0;
};


class Wildebeest : public Herbivore {
public:
    void eatGrass() override {
        cout << "Антилопа ест" << "\n";
    }
};


class Bison : public Herbivore {
public:
    void eatGrass() override {
        cout << "Бизон ест" << "\n";
    }
};


class Elk : public Herbivore {
public:
    void eatGrass() override {
        cout << "Лось ест" << "\n";
    }
};


class Carnivore {
public:
    virtual ~Carnivore() {}
    virtual void eat(Herbivore* herbivore) = 0;
};


class Lion : public Carnivore {
public:
    void eat(Herbivore* herbivore) override {
        cout << "Лев ест" << "\n";
    }
};


class Wolf : public Carnivore {
public:
    void eat(Herbivore* herbivore) override {
        cout << "Ауф ест" << "\n";
    }
};

class Tiger : public Carnivore {
public:
    void eat(Herbivore* herbivore) override {
        cout << "Тигр ест" << "\n";
    }
};

class Continent {
public:
    virtual ~Continent() {}
    virtual Herbivore* createHerbivore() = 0;
    virtual Carnivore* createCarnivore() = 0;
};


class Africa : public Continent {
public:
    Herbivore* createHerbivore() override {
        return new Wildebeest();
    }

    Carnivore* createCarnivore() override {
        return new Lion();
    }
};


class NorthAmerica : public Continent {
public:
    Herbivore* createHerbivore() override {
        return new Bison();
    }

    Carnivore* createCarnivore() override {
        return new Wolf();
    }
};


class Europe : public Continent {
public:
    Herbivore* createHerbivore() override {
        return new Elk();
    }

    Carnivore* createCarnivore() override {
        return new Tiger();
    }
};


class AnimalWorld {
private:
    Herbivore* herbivore;
    Carnivore* carnivore;

public:
    AnimalWorld(Continent* continent) {
        herbivore = continent->createHerbivore();
        carnivore = continent->createCarnivore();
    }

    ~AnimalWorld() {
        delete herbivore;
        delete carnivore;
    }

    void herbivoreMeals() {
        herbivore->eatGrass();
    }

    void carnivoreNutrition() {
        carnivore->eat(herbivore);
    }
};

int main() {

    setlocale(0, "");

    Continent* africa = new Africa();
    AnimalWorld* africaWorld = new AnimalWorld(africa);
    africaWorld->herbivoreMeals();
    africaWorld->carnivoreNutrition();

    Continent* northAmerica = new NorthAmerica();
    AnimalWorld* naWorld = new AnimalWorld(northAmerica);
    naWorld->herbivoreMeals();
    naWorld->carnivoreNutrition();

    Continent* europe = new Europe();
    AnimalWorld* euWorld = new AnimalWorld(europe);
    euWorld->herbivoreMeals();
    eu->carnivoreNutrition();

    delete africa;
    delete africaWorld;
    delete northAmerica;
    delete naWorld;
    delete europe;
    delete euWorld;

    return 0;
}