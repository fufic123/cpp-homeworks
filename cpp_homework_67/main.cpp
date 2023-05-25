#include <iostream>
#include <vector>
#include <algorithm>

struct Print { void operator()(int value) const { std::cout << value << " "; } };

class Multiply { 
private:
	int val;

public:
	Multiply(int val) { this->val = val; };
	void operator()(int& value) { value *= val; } 
};

int main() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	std::for_each(numbers.begin(), numbers.end(), Multiply(3));
	std::for_each(numbers.begin(), numbers.end(), Print());
}