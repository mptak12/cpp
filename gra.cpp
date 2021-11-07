//the secret chamber game str 41
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using std::vector, std::cout, std::cin, std::setw, std::endl;
using std::fstream, std::ostream;

using VD = vector<char>;
using VDD = vector<VD>;

ostream& operator<< (ostream& os, VDD m) {
	for (int r = 0; r < m.size(); r++) {
		for (int c = 0; c < m.size(); c++) {
			os <<setw(3)<< m[c][r];
		}
		os << endl;
	}
	return os;
}

void player(int p[],VDD& m) {//int p, VDD& m*/
	m[p[1]][p[0]] = '.';
	char kl;
	int num;
	//cin >> kl;
	kl = _getch();
	num = int(kl);
	switch (num) {
	case 'w':
		//cout << "W gore" << endl; //kierunki s¹ odwrocone! 
		p[0]--;
		break;
	case 's':
		//cout << "W dol" << endl;
		p[0]++;
		break;
	case 'a':
		//cout << "lewo" << endl;
		p[1]--;
		break;
	case 'd':
		//cout << "prawo" << endl;
		p[1]++;
		break;
	}
	if (p[0] > 9) p[0] = 9;
	if (p[0] < 0) p[0] = 0;
	if (p[1] > 9) p[1] = 9;
	if (p[1] < 0) p[1] = 0;
	m[p[1]][p[0]] = 'P';
}

void treas(int p[], int tpos[], VDD& m)//losuje pozycje skarbu
{
	m[tpos[1]][tpos[0]] = '.';
	//cout << tpos[1] << " " << tpos[0] << endl;
	tpos[0] = rand()%10;
	tpos[1] = rand()%10;

	if (p[0] == tpos[0] && p[1] == tpos[1]) tpos[0] = rand()%10;
	m[tpos[1]][tpos[0]] = 'T';
}

void trap(int trap1[], int tpos[], VDD& m)//, int trap2[]) //losujemy pulapki
{
	m[trap1[1]][trap1[0]] = '.';
	trap1[0] += rand()%3-1;
	if (trap1[0] < 0) trap1[0]++;
	trap1[1] += rand()%3-1;
	if (trap1[1] < 0) trap1[1]++;
	if (trap1[0] == tpos[0] && trap1[1] == tpos[1]) trap1[1]++; //prowizorka jak sie pozycje pokryja
	else
		m[trap1[1]][trap1[0]] = 'X';
}

int main()
{
	//VD a(2,'.');
	VDD map(10,VD(10,'.'));
	int pos[2] = { 4,4 }; //pozycja gracza [0] - pionowo [1] -prawo_lewo
	int tpos[2] = { 1,1 }; //pozycja skarbu
	int trap1[2] = { 0,0 }, trap2[2] = { 9,9 };
	int pts =0;
	int time = 500;
	cout << "Click 'w' to start" << endl;
	treas(pos, tpos, map);
	while (1) {
		cout << map; //wyœwietlamy mape
		cout << "\nYour points:" << pts<<endl;
		trap(trap1, tpos, map);
		if (pos[0] == tpos[0] && pos[1] == tpos[1])
		{
			treas(pos, tpos, map);
			pts++;
		}
		player(pos, map);
		if (trap1[0] == pos[0] && trap1[1] == pos[1]) 
		{
			for (int i = 0; i < 5; i++) { //jak sie spotkaja
				map[pos[1]][pos[0]] = 'X';
				cout << map;
				Sleep(500);
				system("cls");
				map[pos[1]][pos[0]] = '+';
				cout << map;
				Sleep(500);
				system("cls");
			}
			break;
		}
		Sleep(time); //czas w ms
		time--;
		system("cls");
		
	}
	cout << "\nGAME OVER" << endl;
	return 0;
}
