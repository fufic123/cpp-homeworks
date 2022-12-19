//
//  main.cpp
//  cpp_homework_34
//
//  Created by Mark Semenov on 19.12.2022.
//

#include <iostream>
using namespace std;

struct Date {
private:
	int day;
	int month;
	int year;

public:

	Date() {
		day = 0;
		month = 0;
		year = 0;
	}

	Date(int Day, int Month, int Year) {
		day = Day;
		month = Month;
		year = Year;
	}

	void SetDay(int day) { this->day = day; }
	void SetMonth(int month) { this->month = month; }
	void SetYear(int year) { this->year = year; }
	
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }

	void PrintDate() {
		if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 2022) {
			cout << "Invalid date" << endl;
			return;
		}
		printf("%02d.%02d.%04d\n", day, month, year);
	}

	Date NewDate() {
		Date tmp;
		int day, month, year;

		// Day
		cout << "Please, enter day: ";
		cin >> day;
		tmp.SetDay(day);

		//Month
		cout << "Please, enter month: ";
		cin >> month;
		tmp.SetMonth(month);

		//Year
		cout << "Please, enter year: ";
		cin >> year;
		tmp.SetYear(year);

		cout << endl;
		return tmp;
	}
};

struct Device {
private:
	string typeOfDevice;
	string name;
	string model;
	string brand;
	Date guarantee;
	int price;
	Date dateOfSale;

public:
	// setters
	void SetTypeOfDevice(string typeOfDevice) { this->typeOfDevice = typeOfDevice; }
	void SetName(string name) { this->name = name; }
	void SetModel(string model) { this->model = model; }
	void SetBrand(string brand) { this->brand = brand; }
	void SetGuarantee(Date guarantee) { this->guarantee = guarantee; }
	void SetPrice(int price) { this->price = price; }
	void SetDateOfSale(Date dateOfSale) { this->dateOfSale = dateOfSale; }

	// getters
	string GetTypeOfDevice() { return typeOfDevice; }
	string GetName() { return name; }
	string GetModel() { return model; }
	string GetBrand() { return brand; }
	Date GetGuarantee() { return guarantee; }
	int GetPrice() { return price; }
	Date GetDateOfSale() { return dateOfSale; }

	Device NewDevice() {
		Device tmp;
		string typeOfDevice, name, model, brand;
		int price;
		Date guarantee, dateOfSale;

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

		// Guarantee
		cout << "Please, enter guarantee:" << endl;
		guarantee = guarantee.NewDate();
		tmp.SetGuarantee(guarantee);

		// Price
		cout << "Please, enter price: ";
		cin >> price;
		cout << endl;
		tmp.SetPrice(price);

		// Date Of Sale
		cout << "Please, enter date of sale:" << endl;
		dateOfSale = dateOfSale.NewDate();
		tmp.SetDateOfSale(dateOfSale);

		cout << endl;
		return tmp;
	}

	void PrintDataOfDevice() {
		cout << "Type of device: " << typeOfDevice << endl;
		cout << "Name: " << name << endl;
		cout << "Brand: " << brand << endl;
		cout << "Model: " << model << endl;
		cout << "Guarantee date: ";
		guarantee.PrintDate();
		cout << "Price: " << price << endl;
		cout << "Date of sale: ";
		dateOfSale.PrintDate();
	}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Device MyDevice;
    MyDevice = MyDevice.NewDevice();
    MyDevice.PrintDataOfDevice();
}
