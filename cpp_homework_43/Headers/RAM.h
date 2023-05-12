#pragma once
#include <iostream>
using namespace std;

class RAM {
private:
  char *name;
  int memory;
  double price;

public:
  RAM(const RAM &copy);
  RAM(const char *name, int memory, double price);
  ~RAM();

  void Input();
  void Print();

  const char *GetName();
  int GetMemory();
  double GetPrice();

  void SetName(const char *name);
  void SetMemory(int memory);
  void SetPrice(double price);
};

RAM::RAM(const RAM &copy) : memory(copy.memory), price(copy.price) {
  name = new char[strlen(copy.name) + 1];
  strcpy(name, copy.name);
}

RAM::RAM(const char *name, int memory, double price) : memory(memory), price(price) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

RAM::~RAM() {
  delete[] name;
}

void RAM::Input() {
  char buff[20];
  cout << "Enter name -> ";
  cin.getline(buff, 20);
  this->name = new char[strlen(buff) + 1];
  strcpy(this->name, buff);

  cout << "Enter memory -> ";
  cin >> memory;

  cout << "Enter price -> ";
  cin >> price;
}

void RAM::Print() {
  cout << "\tName: " << name << "\n";
  cout << "\tMemory: " << memory << "\n";
  cout << "\tPrice: " << price << "\n\n";
}

const char *RAM::GetName() {
  return name;
}
int RAM::GetMemory() {
  return memory;
}
double RAM::GetPrice() {
  return price;
}

void RAM::SetName(const char *name) {
  if (name != nullptr)
    delete[] name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
void RAM::SetMemory(int memory) {
  this->memory = memory;
}
void RAM::SetPrice(double price) {
  this->price = price;
}