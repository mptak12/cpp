#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <xutility>
#include <iterator>

using std::vector, std::cout, std::endl;
using std::generate, std::copy, std::ostream_iterator, std::sort;

int main()
{
	srand(time(0));
	vector <int> los(10);
	//generate(los.begin(), los.end(), std::mt19937(std::random_device{}()));
	generate(los.begin(), los.end(), []() {return rand() % 15; }); //tu jest ju¿ f.lambda co generuje rand
	copy(los.begin(), los.end(), ostream_iterator<int>(cout," ")); //wypisanie na ekran

	sort(los.begin(), los.end(), [](int a, int b) {return a > b;}); //sortowanie z lambd¹
	cout << endl;
	for (const auto x : los) cout << x << " "; //wypisanie wektora

	return 0;
}
