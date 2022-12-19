//
//  main.cpp
//  cpp_homework_34
//
//  Created by Mark Semenov on 19.12.2022.
//

#include <iostream>
using namespace std;

struct Device {
private:
    string typeOfDevice;
    string name;
    string model;
    string brand;
    int price;

public:
    // setters
    void SetTypeOfDevice(string typeOfDevice) { this->typeOfDevice = typeOfDevice; }
    void SetName(string name) { this->name = name; }
    void SetModel(string model) { this->model = model; }
    void SetBrand(string brand) { this->brand = brand; }
    void SetPrice(int price) { this->price = price; }

    // getters
    string GetTypeOfDevice() { return typeOfDevice; }
    string GetName() { return name; }
    string GetModel() { return model; }
    string GetBrand() { return brand; }
    int GetPrice() { return price; }

    Device NewDevice() {
        Device tmp;
        string typeOfDevice, name, model, brand;
        int price;

        // Type Of Device
        cout << "Please, enter type of device: ";
        getline(cin, typeOfDevice);
        cout << endl;
        tmp.SetTypeOfDevice(typeOfDevice);

        // Name
        cout << "Please, enter name of shop: ";
        getline(cin, name);
        cout << endl;
        tmp.SetName(name);

        // Brand
        cout << "Please, enter brand: ";
        getline(cin, brand);
        cout << endl;
        tmp.SetBrand(brand);

        // Model
        cout << "Please, enter model: ";
        getline(cin, model);
        cout << endl;
        tmp.SetModel(model);

        // Price
        cout << "Please, enter price: ";
        cin >> price;
        cout << endl;
        tmp.SetPrice(price);

        cout << endl;
        return tmp;
    }

    void PrintDataOfDevice() {
        cout << "Type of device: " << typeOfDevice << endl;
        cout << "Name: " << name << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Device MyDevice;
    MyDevice = MyDevice.NewDevice();
    MyDevice.PrintDataOfDevice();
}
