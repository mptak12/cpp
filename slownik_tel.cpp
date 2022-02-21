///OPIS
///Podczas pisania krótkich wiadomoœci tekstowych istotny jest sposób przechowywania wyrazów 
/// w s³owniku oraz odgadywanie ich na podstawie wciœniêtych klawiszy numerycznych. 
/// W klasycznej klawiaturze telefonu komórkowego cyfrom 2-9 odpowiadaj¹ nastêpuj¹ce 
/// litery alfabetu: 2 (abc), 3 (def), 4 (ghi), 5 (jkl), 6 (mno), 7 (pqrs), 8 (tuv), 9 (wxyz).
/// W ten sposób, na przyk³ad liczbie 25 odpowiada 
/// 9 dwuliterowych wyrazów: aj, ak, al, bj, bk, bl, cj, ck, cl, 
/// liczbie 438 odpowiada 27 trzyliterowych wyrazów, 
/// a liczbie 5378 odpowiada 108 wyrazów czteroliterowych.. 
/// S³ownik jednak¿e nie zawiera wszystkich w ten sposób utworzonych wyrazów 
/// (zawiera tylko pewien podzbiór). Za³ó¿my, ¿e w telefonie komórkowym z klasyczn¹ klawiatur¹ 
/// zosta³ zainstalowany s³ownik sk³adaj¹cy siê z wyrazów utworzonych z ma³ych liter alfabetu
/// ³aciñskiego o d³ugoœci od 1 do 15 znaków. 
/// Dla podanej liczby, sk³adaj¹cej siê z co najwy¿ej 15 cyfr, 
/// nale¿y wypisaæ wszystkie wyrazy wystêpuj¹ce w s³owniku odpowiadaj¹ce tej liczbie.
/// 
/// WEJSCIE
/// W pierwszym wierszu podana jest liczba n (n <= 100000) wyrazów w s³owniku oraz iloœæ k 
/// (k <= 1000000) liczb, dla których bêdziemy szukaæ wyrazów. 
/// W kolejnych n wierszach podane zosta³y wyrazy s³ownika, 
/// a w nastêpnych k wierszach liczby sk³adaj¹ce siê z cyfr ze zbioru {2,3,4,5,6,7,8,9}.
/// 
/// WYJSCIE
/// W ka¿dym z k wierszy nale¿y wypisaæ w porz¹dku alfabetycznym wszystkie wyrazy s³ownika \
/// odpowiadaj¹ce liczbie lub napis BRAK, je¿eli takich s³ów nie ma w s³owniku
///KONIEC OPISU

#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::string, std::to_string;
using v_char = std::vector<string>;
using v_number = std::vector<int>;

v_char czytaj_wyrazy(int l_wyr, v_char& wyrazy) {
	string wyr;
	for (int i = 0; i < l_wyr; i++)
	{
		cin >> wyr;
		wyrazy.push_back(wyr);
	}
	return wyrazy;
}

v_number czytaj_numery(int il_liczb, v_number& numery) {
	int liczba;
	for (int i = 0; i < il_liczb; i++)
	{
		cin >> liczba;
		numery.push_back(liczba);
	}
	return numery;
}

int main()
{
	int l_wyr{ 0 }, il_liczb{ 0 };
	char tab[][5] = { "","","abc.","def.","ghi.","jkl.","mno.", "pqrs", "tuv.", "wxyz" };

	v_char wyrazy;  // = {"abc", "xda"} vector
	v_number numery; // = {2311, 2321, 2321} vector
	cout << "READY" << endl;
	cin >> l_wyr >> il_liczb;
	czytaj_wyrazy(l_wyr, wyrazy);
	czytaj_numery(il_liczb, numery);

	for (int z = 0; z < il_liczb; z++)  //sprawdza dla kazdej liczby
	{
		int overall_dopasowanie{ 0 };
		for (int i = 0; i < l_wyr; i++) //sprawdza dla ka¿dego wyrazu
		{
			string temp = wyrazy[i];  //temp = wyraz
			int dopasowanie{ 0 };
			string num_tab = to_string(numery[z]); //num_tab = klikniete przyciski

			if (temp.length() > num_tab.length()) //zabezpieczenie
			{
				i++;
				dopasowanie=0;
				break;
			}
			for (int j = 0; j < temp.size(); j++)  //skanuje litery wyrazu a l a
			{
				for (int k = 0; k < 4; k++) //kazdy przycisk 4 mozliwosci
				{
					if (temp[j] == tab[int(num_tab[j] - 48)][k]) { //literka pasuje
						dopasowanie++;
						break;
					}
				}
				if (dopasowanie == temp.length())
				{
					cout << temp << " ";
					overall_dopasowanie++;
				}
			}
		}
		if (overall_dopasowanie == 0) cout << endl<<"BRAK" << endl;

	}
	return 0;
}

