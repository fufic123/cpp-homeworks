#pragma once

class Student {
private:
	std::string name;
	int age;

public:
	Student() : name("No name"), age(0) {}
	Student(std::string name, int age) : name(name), age(age) {}

	bool operator < (const Student& s) const { return age < s.age; };

	friend std::istream& operator >> (std::istream& i, Student& s) {
		std::cout << "Enter name >> ";
		i >> s.name;
		std::cout << "Enter age >> ";
		i >> s.age;
		return i;
	}

	friend std::ostream& operator << (std::ostream& o, const Student& s) {
		o << "Name: " << s.name << std::endl << "Age: " << s.age;
		return o;
	}
};