#include <iostream>
using namespace std;

class Employer {
protected:
	string name;

public:
    Employer() {
        name = "";
    }

    Employer(std::string name) {
        this->name = name;
    }

	virtual void Show() = 0;
};

class President : public Employer {
public:
    President() {}
    President(string name) {
        this->name = name;
    }

    void Show() 
    { 
        cout << "President: " << name << "\n";
    }
};

class Manager : public Employer {
public:
    Manager() {}
    Manager(string name) {
        this->name = name;
    }

    void Show() 
    { 
        cout << "Manager: " << name << "\n"; 
    }
};

class Worker : public Employer {
public:
    Worker() {}

    Worker(string name) {
        this->name = name;
    }

    void Show() { std::cout << "Worker: " << name << "\n"; }
};