#include <iostream>
#include <map>
#include "Student.hpp"

int main() {
	// 1st task
	std::map<std::string, float> students;
	for (int i = 0; i < 5; i++) {
		std::string tmp1;
		float tmp2;
		std::cout << "Enter name >> ";
		std::cin >> tmp1;
		std::cout << "Enter average mark >> ";
		std::cin >> tmp2;
		students.insert(std::make_pair(tmp1, tmp2));
	}
	for (const auto& elem : students) std::cout << "Name: " << elem.first << std::endl << "Average mark: " << elem.second << std::endl;

	// 2nd task
	std::map<Student, float> students2;
	for (int i = 0; i < 5; i++) {
		Student tmp1;
		float tmp2;
		std::cin >> tmp1;
		std::cout << "Enter average mark >> ";
		std::cin >> tmp2;
		students2.insert(std::make_pair(tmp1, tmp2));
	}
	for (const auto& elem : students2) std::cout << elem.first << std::endl << "Average mark: " << elem.second << std::endl;

	std::string searchName;
	int searchAge;
	std::cout << "Enter name to search >> ";
	std::cin >> searchName;
	std::cout << "Enter age to search >> ";
	std::cin >> searchAge;
	auto searchResult = students2.find(Student(searchName, searchAge));
	if (searchResult != students2.end()) std::cout << "Student found! " << std::endl;
	else std::cout << "Student not found! " << std::endl;
}