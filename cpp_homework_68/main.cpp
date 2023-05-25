#include <iostream>
#include <map>
#include "Student.hpp"

using namespace std;
int main() {
	// 1st task
	map<string, float> students;
	for (int i = 0; i < 5; i++) {
		string tmp1;
		float tmp2;
		cout << "Enter name >> ";
		cin >> tmp1;
		cout << "Enter average mark >> ";
		cin >> tmp2;
		students.insert(make_pair(tmp1, tmp2));
	}
	for (const auto& el : students) cout << "Name: " << el.first << endl << "Average mark: " << el.second << endl;

	// 2nd task
	map<Student, float> s2;
	for (int i = 0; i < 5; i++) {
		Student tmp1;
		float tmp2;
		cin >> tmp1;
		cout << "Enter average mark >> ";
		cin >> tmp2;
		s2.insert(make_pair(tmp1, tmp2));
	}
	for (const auto& el : s2) cout << el.first << endl << "Average mark: " << el.second << endl;

	string searchName;
	int searchAge;
	cout << "Enter name to search >> ";
	cin >> searchName;
	cout << "Enter age to search >> ";
	cin >> searchAge;
	auto searchResult = s2.find(Student(searchName, searchAge));
	if (searchResult != s2.end()) cout << "Student found! " << endl;
	else cout << "Student not found! " << endl;
}