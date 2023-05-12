#pragma once
#include <iostream>
using namespace std;

class VideoCard {
private:
  char *name;
  const int memory;
  double price;

public:
  VideoCard(const VideoCard &copy);
  VideoCard(const char *name, int memory, double price);
  ~VideoCard();

  void Input();
  void Print();

  const char *GetName();
  const int GetMemory();
  double GetPrice();

  void SetName(const char *name);
  void SetPrice(double price);
};

VideoCard::VideoCard(const VideoCard &copy) : memory(copy.memory), price(copy.price) {
  name = new char[strlen(copy.name) + 1];
  strcpy(name, copy.name);
}

VideoCard::VideoCard(const char *name, int memory, double price) : memory(memory), price(price) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

VideoCard::~VideoCard() {
  delete[] name;
}

void VideoCard::Input() {
  char buff[20];
  cout << "Enter name: ";
  cin.getline(buff, 20);
  this->name = new char[strlen(buff) + 1];
  strcpy(this->name, buff);
  cout << "Enter price: ";
  cin >> price;
}

void VideoCard::Print() {
  cout << "\tName: " << name << "\n";
  cout << "\tMemory: " << memory << "\n";
  cout << "\tPrice: " << price << "\n\n";
}

const char *VideoCard::GetName() {
  return name;
}
const int VideoCard::GetMemory() {
  return memory;
}
double VideoCard::GetPrice() {
  return price;
}

void VideoCard::SetName(const char *name) {
  if (name != nullptr)
    delete[] name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
void VideoCard::SetPrice(double price) {
  this->price = price;
}