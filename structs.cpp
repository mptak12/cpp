#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cin, std::cout, std::endl, std::vector, std::string, std::ofstream;

struct person {
	string name;
	int age;

	person(string n="", int a=0) { //konstruktor parametryczny default = 0
		name = n;
		age = a;
	}
};

using TAB = vector<person>;

void addP(person a, TAB& tabela) { //dodaje wpisy
	tabela.push_back(a);
}

void showP(TAB tabela) { //pokazuje liste
	if (tabela.size() == 0) cout << endl << "The list is empty" << endl;
	else {
		cout << "\nRecords existing on the list:\n";
		for (int i = 0; i < tabela.size();i++)
			cout << tabela[i].name << " " << tabela[i].age << endl;
		cout << endl;
	}
}

void saveP(TAB tabela){//zapis do pliku
	ofstream outFile("names.txt");
	for (int i = 0; i < tabela.size();i++)
		outFile << tabela[i].name << " " << tabela[i].age << endl;
	outFile.close();
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
		cout << "a - dopisz do tabeli, s - pokaz tabele \nw - zapisz tabele do pliku q -zakoncz\n\n";
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
		case 'q': //wyjdziemy z pętli
			return 0;
		}
	}
	return 0;
}
