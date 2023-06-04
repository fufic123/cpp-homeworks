#include <iostream>
using namespace std;

class House abstract{};

class BrickHouse : public House {
public:
	BrickHouse() {
		cout << "Brick House built\n";
	}
};

class PanelHouse : public House {
public:
	PanelHouse() {
		cout << "Panel house built\n";
	}
};

class WoodHouse : public House{
public:
	WoodHouse(){
		cout << "Wooden house built\n";
	}
};

class Creator abstract {
public:
	virtual House* Create() = 0;
};

class BrickCreator : public Creator {
public:
	House* Create() override {
		return new BrickHouse;
	}
};

class PanelCreator : public Creator {
public:
	House* Create() override {
		return new PanelHouse;
	}
};

class WoodCreator : public Creator {
public:
	House* Create() override {
		return new WoodHouse;
	}
};

House* Client(Creator* pCr) {
	return pCr->Create();
}

int main() {
	Creator* pCr = new PanelCreator();
	House* pHouse = Client(pCr);
	delete pHouse;
	delete pCr;

	pCr = new WoodCreator();
	pHouse = Client(pCr);
	delete pHouse;
	delete pCr;

	pCr = new BrickCreator();
	pHouse = Client(pCr);
	delete pHouse;
	delete pCr;
}