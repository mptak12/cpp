#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> //std::find
using std::cin, std::cout, std::endl, std::vector, std::string, std::ofstream;
using std::ostream, std::find;
struct person {
	string name;
	int age;

	person(string n="", int a=0) { //konstruktor parametryczny default = 0
		name = n;
		age = a;
	}
};
ostream& operator<<(ostream& os, const person& tab) { //przeci¹zenie operatora
	os <<"Imie:" << tab.name <<"  Wiek:" << tab.age << endl;
	return os;
}
using TAB = vector<person>;

void addP(person a, TAB& tabela) { //dodaje wpisy
	tabela.push_back(a);
}

void showP(TAB tabela) { //pokazuje liste
	if (tabela.size() == 0) cout << endl << "The list is empty" << endl;
	else {
		cout << "\nRecords existing on the list:\n";
		for (int i = 0; i < tabela.size();i++)
			cout << tabela[i];
		//cout << tabela[i].name << " " << tabela[i].age << endl;
		cout << endl;
	}
}

void saveP(TAB tabela){//zapis do pliku
	ofstream outFile("names.txt");
	for (int i = 0; i < tabela.size();i++)
		outFile << tabela[i];
	outFile.close();
}

void searchP(TAB tabela) { //szukanie czy imie istnieje w tabeli
	string srcn;
	//cout<<find(tabela[0].name, tabela[2].name,"Alex");
	cout << "What name do u want to look for?\n";
	cin >> srcn;
	for (int i = 0; i < tabela.size();i++) {
		if (tabela[i].name == srcn) cout << tabela[i];
	}
}
int main()
{
	int choice{ 0 }, wiek{0};
	char temp;
	string imie;
	TAB list;
	//person a("Aga", 3);
	//person b("Wojtas", 21);
	//person b;
	//list.push_back(a);
	//addP(b,list);
	//showP(list);
	for (;;) {
		cout << "a - dopisz do tabeli, s - pokaz tabele \nw - zapisz tabele do pliku l - szukanie imion \nq -zakoncz\n\n";
		cin >> temp;
		choice = int(temp);
		switch (choice) {
		case 'a': //dopiszemy do tabeli
			cout << "podaj imie\n";
			cin >> imie;
			cout << "podaj wiek\n";
			cin >> wiek;
			addP(person(imie, wiek),list);
			break;
		case 's': //pokazemy tabele
			showP(list);
			break;
		case 'w': //zapis do pliku
			saveP(list);
			cout << "List saved to file .txt\n";
			break;
		case 'l': //szukanie imion
			searchP(list);
			break;
		case 'q': //wyjdziemy z pêtli
			return 0;
		}
	}
	return 0;
}
