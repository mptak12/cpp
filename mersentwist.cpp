//algorytm do generowania losowych liczb mersen twister
#include <iostream>
#include <random>

using std::cout;

int twist(int a, int b) {
	std::mt19937	twister(rand());
	std::uniform_int_distribution<int> dist(a, b);
	return dist(twister);
}

int main()
{
	cout << twist(10, 24);
	cout << " "<<twist(10, 24);
	return 0;
}
