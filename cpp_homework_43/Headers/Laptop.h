#pragma once
#include <iostream>
#include "VideoCard.h"
#include "CPU.h"
#include "RAM.h"
#include "HDD.h"
using namespace std;

class Laptop {
private:
  char *name;
  VideoCard vc;
  CPU cpu;
  RAM ram;
  HDD hdd;
  double price;

public:
  Laptop(const Laptop &copy);
  Laptop(const char *name, VideoCard &vc, CPU &cpu, RAM &ram, HDD &hdd);
  ~Laptop();

  void Input();
  void Print();

  const char *getName();
  HDD getHDD();
  VideoCard getVideoCard();
  CPU getCPU();
  RAM getRAM();
  double getPrice();

  void setName(char *name);
  void setHDD(HDD hdd);
  void setVideoCard(VideoCard vc);
  void setCPU(CPU cpu);
  void setRAM(RAM ram);
};

Laptop::Laptop(const Laptop &copy) : vc(copy.vc), cpu(copy.cpu), ram(copy.ram), hdd(copy.hdd), price(copy.price) {
  name = new char[strlen(copy.name) + 1];
  strcpy(name, copy.name);
}

Laptop::Laptop(const char *name, VideoCard &vc, CPU &cpu, RAM &ram, HDD &hdd) : vc(vc), cpu(cpu), ram(ram), hdd(hdd), price(vc.GetPrice() + cpu.GetPrice() + ram.GetPrice() + hdd.GetPrice()) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

Laptop::~Laptop() {
  delete[] name;
}

void Laptop::Input() {
  char buff[20];
  cout << "Enter name: ";
  cin.getline(buff, 20);
  this->name = new char[strlen(buff) + 1];
  strcpy(this->name, buff);

  cout << "Enter VideoCard: ";
  vc.Input();

  cout << "Enter CPU: ";
  cpu.Input();

  cout << "Enter RAM: ";
  ram.Input();

  cout << "Enter HDD: ";
  hdd.Input();
}

void Laptop::Print() {
  cout << "Name: " << name << "\n\n";
  cout << "Video card: "
       << "\n";
  vc.Print();
  cout << "CPU: "
       << "\n";
  cpu.Print();
  cout << "RAM: "
       << "\n";
  ram.Print();
  cout << "HDD: "
       << "\n";
  hdd.Print();
  cout << "Laptop price: " << price << "\n";
}

const char *Laptop::getName() {
  return name;
}
HDD Laptop::getHDD() {
  return hdd;
}
VideoCard Laptop::getVideoCard() {
  return vc;
}
CPU Laptop::getCPU() {
  return cpu;
}
RAM Laptop::getRAM() {
  return ram;
}
double Laptop::getPrice() {
  return price;
}

void Laptop::setName(char *name) {
  if (name != nullptr)
    delete[] name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
void Laptop::setHDD(HDD hdd) {
  this->hdd.SetName(hdd.GetName());
  this->hdd.SetPrice(hdd.GetPrice());
}
void Laptop::setVideoCard(VideoCard gc) {
  this->vc.SetName(hdd.GetName());
  this->vc.SetPrice(hdd.GetPrice());
}
void Laptop::setCPU(CPU cpu) {
  this->cpu = cpu;
}
void Laptop::setRAM(RAM ram) {
  this->ram = ram;
}