#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iterator>

//nie mój plik//

// Listing them here allows omitting std::
using std::cout, std::cin, std::endl;
//using std::string, std::vector;

void  letter_histogram(void)
{
	// Make slot for each letter, from 'a' to 'z'
	// Initial count set to 0 for each.
	std::vector histogram('z' - 'a' + 1, 0);

	std::string in_str;

	//std::cin >> in_str;
	getline(cin, in_str); //poprawnie
	//in_str = "AGH University of Science and Technology";
	//in_str = "Gosia mnie kosia";

	for (auto c : in_str)
	{

		if (isalpha(c))
		{
			++histogram[tolower(c) - 'a'];
			cout << c << endl;
		}
	}
	cout << endl;

	for (auto k{ 'a' }; k <= 'z'; ++k)
		cout << k << " ";		// Print all characters ‘a’ to ‘z’

	cout << endl;

	for (auto h : histogram)
		cout << h << " ";		// Print histogram values

	cout << endl;
}

// 2nd version using the ST algorithms
void letter_histogram_stl(void)
{
	std::vector histogram('z' - 'a' + 1, 0);

	std::string in_str;

	//std::cin >> in_str;
	in_str = "AGH University of Science and Technology";


	std::for_each(in_str.begin(), in_str.end(),
		[&histogram](const auto c) {
			if (isalpha(c))
				++histogram[tolower(c) - 'a'];
		}
	);


	cout << endl;
	std::generate_n(std::ostream_iterator< char >(std::cout, " "), histogram.size(), [k = 'a']() mutable { return k++; });

	cout << endl;
	std::copy(histogram.begin(), histogram.end(), std::ostream_iterator< int >(std::cout, " "));

	cout << endl;

}

int main() {
	letter_histogram();
	//pow(5, 2);
	return 0;
}
