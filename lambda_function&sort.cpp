#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <xutility>
#include <iterator>
#include <string>
using std::vector, std::cout, std::endl;
using std::generate, std::copy, std::ostream_iterator, std::sort;
using std::string;
using VDD = vector<vector<int>>;

int main()
{
	srand(time(0));
	vector <int> los(10);
	//generate(los.begin(), los.end(), std::mt19937(std::random_device{}()));
	generate(los.begin(), los.end(), []() {return rand() % 15; }); //tu jest ju¿ f.lambda co generuje rand
	copy(los.begin(), los.end(), ostream_iterator<int>(cout," ")); //wypisanie na ekran

	sort(los.begin(), los.end(), [](int a, int b) {return a < b;}); //sortowanie z lambd¹
	cout << endl;
	for (const auto x : los) cout << x << " "; //wypisanie wektora

	/*
	VDD matrix(10, vector(10, 1));
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int row = 0; row < 10; row++) {
		copy(matrix[0].begin(), matrix[0].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	
	copy_if(los.begin(), los.end(),
		std::ostream_iterator<int>(std::cout, " "),
		[](int x) { return x % 2 != 0; });
	*/
	string A = "abc";
	string B;
	reverse_copy(A.begin(), A.end(), std::back_inserter(B));

	return 0;
}
