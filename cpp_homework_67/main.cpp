#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Print { void operator()(int value) const { cout << value << " "; } };

class Multiply { 
private:
	int value1;

public:
	Multiply(int value1) { this->value1 = value1; };
	void operator()(int& value2) { value2 *= value1; } 
};

int main() {
	vector<int> n = { 1, 2, 3, 4, 5 };
	for_each(n.begin(), n.end(), Multiply(3));
	for_each(n.begin(), n.end(), Print());
}