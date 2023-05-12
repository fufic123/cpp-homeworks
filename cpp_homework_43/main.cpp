#include <iostream>
#include "Headers/HDD.h"
#include "Headers/VideoCard.h"
#include "Headers/CPU.h"
#include "Headers/RAM.h"
#include "Headers/Laptop.h"
using namespace std;

int main() {
  VideoCard obj1("Nvidia RTX 3060", 12, 30000);
  CPU obj2("Intel Core i7", 3.9, 12000);
  RAM obj3("Kingston", 32, 4600);
  HDD obj4("Asus", 512, 4800);
  Laptop laptop("MSI", obj1, obj2, obj3, obj4);
  laptop.Print();
}