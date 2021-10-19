#include <iostream>
#include <vector>

using std::vector;
using std::cout, std::endl;
using VD = std::vector <double>;

int main()
{
	//vector <double> VD; mozna tez tak utworzyæ wektor
	//cout << a.size()<<endl; wyœwietla rozmiar wektora
	// a.push_back(3); doda 3 do wektora
	// a.size(); poda rozmiar
	VD a;
	VD b;

	cout << "this program creates 2 vectors and calculates their outer product" << endl;
	for (int i = 0; i < 10;i++) {

		a.push_back(i);
		//cout << a[i] <<endl;
	}
	for (auto elem : a)
		cout <<elem<<endl;
	cout << endl;
	for (int i = 10; i < 20; i++) {
		b.push_back(i);
		cout << b[i - 10] <<" ";
	}

	using VD2 = std::vector < std::vector<double>>;
	cout << endl <<endl<< "Solution matrix = " << endl;
	/////////////
	/*testy macierzowe
	VD c, d, e, f(5, 0), g(5, 3.2);
	VD2 matrix;
	for (int i = 0; i < 5; i++) {
		c.push_back(i);
		d.push_back(10.0 * i / 2);
		e.push_back(13.4 * i / 2);
	}

	matrix.push_back(c);
	matrix.push_back(d);
	matrix.push_back(e);
	matrix.push_back(f);
	matrix.push_back(g);
	//////////////

	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 5; col++) {
			cout << matrix[col][row]<<" ";
		}
		cout << endl;
	}
	*/
	//VD blank(a.size(), 0);
	VD2 outer(a.size(),VD(a.size(),0));
	for (int row = 0; row < a.size(); row++) {
		for (int col = 0; col < b.size(); col++) {
			outer[col][row] = a[row] * b[col];
			cout << outer[col][row] << " ";
		}
		cout << endl;
	}
		return 0;
}