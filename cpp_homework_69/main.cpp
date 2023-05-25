#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(std::string str1, std::string str2) { return str1.length() < str2.length(); }

int main() {
	std::vector<std::string> vect = { "lalal", "tralala", "Hihi", "tratatatatataa", "opa" };
	for (auto i : vect) std::cout << i << std::endl;
	std::cout << std::endl;
	std::sort(vect.begin(), vect.end(), cmp);
	for (auto i : vect) std::cout << i << std::endl;
}