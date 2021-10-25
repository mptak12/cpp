#include <iostream>
#include<vector>
#include <iomanip>

using std::cin, std::cout, std::endl, std::setw;
using VD = std::vector<double>;
using VDD = std::vector<VD>;

VDD creatematrix(int row, int col) {
	VDD m(row, VD(col, 0));
	return m;
}

void printmatrix(VDD mat) { //mat.size() daje wiersze mat[0].size daje kolumny
	for (int row = 0; row < mat.size(); row++) {
		for (int col = 0; col < mat[0].size(); col++) {
			cout << setw(4) << mat[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

VDD summatrix(VDD a, VDD b)
{
	if ((a.size() != b.size()) || a[0].size() != b[0].size()) {
		cout << "zle rozmiary" << endl;
		return { {0} };
	}
	VDD sum(a.size(), VD(a[0].size(), 0));
	for (int row = 0; row < a.size(); row++) {
		for (int col = 0; col < a[0].size(); col++) {
			sum[row][col] = a[row][col] + b[row][col];
		}
	}
	return sum;
}

VDD mmat(VDD a, VDD b)
{
	if (a.size() != b[0].size()) {
		cout << "zle wymiary macierzy" << endl;
		return { {0} };
	}
	VDD mult(a.size(), VD(b[0].size(), 0)); //w z pierwszej kol z drugiej
	for (int row = 0; row < a.size(); row++) {
		for (int col = 0; col < b[0].size(); col++) {
			for (int k = 0; k < a[0].size(); k++) {
				mult[row][col] += a[row][k] * b[k][col];
			}
		}
	}

	return mult;
}

int main()
{
	//int col, row;
	//cout << "Enter matrix size [col][row]" << endl;
	//cin >> col >> row;
	//VDD mat{ creatematrix(col, row) }, mat2{ creatematrix(col,row)};

	VDD mat(2, VD(3, 0));
	mat = {
			{1,0,2},
			{-1,3,1},
	};
	VDD mat2(3, VD(2, 0));
	mat2 = {
			{3,1},
			{2,1},
			{1,0},
	};
	
	//printmatrix(mat);
	//printmatrix(mat2);
	//printmatrix(summatrix(mat, mat));
	//printmatrix(summatrix(mat2,mat2));
	cout << "Wynik mno¿enia" << endl;
	printmatrix(mmat(mat, mat2));
}