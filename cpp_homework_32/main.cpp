//
//  main.cpp
//  cpp_homework_32
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
using namespace std;

struct Device {
    string DeviceType;
    string Description;
    string Model;
    string Brand;
    double GuaranteePeriod;
    double Price;
    string DateOfSale;
};


Device DeviceInfo() {
    Device temp;
    cout << "Please, enter device type:";
    cin >> temp.DeviceType;
    cout << "Please, enter description:";
    cin >> temp.Description;
    cout << "Please, enter model:";
    cin >> temp.Model;
    cout << "Please, enter brand:";
    cin >> temp.Brand;
    cout << "Please, enter guarantee period:";
    cin >> temp.GuaranteePeriod;
    cout << "Please, enter price:";
    cin >> temp.Price;
    cout << "Please, enter date of sale:";
    cin >> temp.DateOfSale;


    return temp;
}


void ShowDevice(const Device& device)
{
    cout << "Device type - " << device.DeviceType << "\n";
    cout << "Denomination - " << device.Description << "\n";
    cout << "Model - " << device.Model << "\n";
    cout << "Brand - " << device.Brand << "\n";
    cout << "Guarantee period - " << device.GuaranteePeriod << "\n";
    cout << "Price - " << device.Price << "\n";
    cout << "Date of sale - " << device.DateOfSale << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Device device = DeviceInfo();
    ShowDevice(device);
}
