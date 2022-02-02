#include <iostream>
#include <filesystem> //cpp 17+
#include <vector>
#include <string.h>
#include <fstream>
#include <Windows.h>

using std::cout, std::cin, std::vector, std::wstring, std::string, std::wcout, std::wcin, std::endl, std::fstream;
using std::ofstream; //tylko do zapisu
using std::setw;
namespace fs = std::filesystem;
using vect = vector<wstring>;

class reader {
/// <summary>
/// this class is iterating through filesystem
/// variable path is uppdated every time a file matches to extension pattern stored in "flags"
/// </summary>
    const fs::path curr_path{ fs::current_path() }; //zmienna z aktualna sciezka
    vect paths{}; //tu skladowane sa sciezki do plikow
    wstring src_path; //tu zaczynamy analize

public:
    reader(string addr) {
        if (addr.compare("here") == 0) src_path = curr_path;
        else src_path=wstring(addr.begin(), addr.end()); //konwersja z string na wstring
    }

    void read(); //glowna funkcja z klasy
    auto set_paths(vect p) { paths = p; }
    auto get_paths() const { return paths; }
};

void reader::read()//wstring pathToShow) 
{
    const fs::directory_options options = (
        fs::directory_options::skip_permission_denied
        );
    for (const auto& entry : fs::recursive_directory_iterator(src_path, options)) { //zmienna entry: tam iteruj¹ siê sciezki
        if (entry.path().extension().string() == ".txt" || entry.path().extension().string() == ".cpp") {
            paths.push_back(entry.path());
        }
    }
}

class scanner {
/// <summary>
/// this class opens vect variable from "reader" class
/// then it counts files parameters
/// parameters are passed to main MFC class through getters() 
/// </summary>
    vect f_p{}; //od poprzedniej klasy - sciezki plikow
    int word_count{ 0 };
    int letter_count{ 0 };
    int line_count{ 0 };
    string all;

public:
    scanner(vect f_p) { this->f_p = f_p; }  //konstr
    void if_empty_check();        //sprawdza czy puste
    void summary();
    void letter_histogram();
};

void scanner::if_empty_check() {
    if(f_p.size()==0) cout<< "0 matching" << endl;
    else
        cout << "Number of matches: " << f_p.size() << endl;
    /*for (const auto p : f_p) //wypisanie sciezek na ekran
        wcout << p << endl;
        */
}

void scanner::summary() {
    //ta funkcja skanuje wszystkie podane sciezki i podaje ich ogolne podsumowanie
    string word, line;
    for (const auto a : f_p)
    {
        fstream czytaj(a); //bufor do wyrazow i liter
        while (czytaj >> word) {
             word_count++;
            all += word;
        }
        czytaj.close();

        fstream czytaj2(a); //bufor do liczby linii
        while (!czytaj2.eof()) {
            getline(czytaj2, line);
            line_count++;
            //cout << line;
        }
        //line_count--; //usuwam ostatni¹ pust¹ linijkê
        czytaj2.close();

        letter_count = all.length();
    }
    cout <<"Number of words in files : "<< word_count << endl;
    cout << "LINES: " << line_count << endl;
    cout << "LETTERS: " << letter_count << endl;
}

void scanner::letter_histogram() {
    vector histogram('z' - 'a' + 1, 0); //miejsce na kazda literke

    for (auto c : all)
    {
        if (isalpha(c))
        {
            ++histogram[tolower(c) - 'a'];
            //cout << c << endl;
        }
    }
    cout <<"Letters in all files histogram"<< endl;
    for (auto k{'a'}; k <= 'z'; ++k)
        cout <<setw(2)<< k << " ";		// Print all characters ‘a’ to ‘z’
    cout << endl;

    for (auto h : histogram)
        cout << setw(2) << h << " ";		// Print histogram values 
    cout << endl;
}

void rand_letters_generator() { //tej funkcji nie bedzie w programie
    ofstream zapis("C:\\Users\\micha\\Documents\\testycpp\\tekst.txt");
    srand(time(NULL));
    for (int j = 0; j < 50; j++) {
        for (int i = 0; i < rand() % 20 + 10; i++)
            zapis << char(rand() % int('z' - 'a'+1) + int('a'));
        zapis << endl;
    }
    zapis.close();
}

int main() {
    //rand_letters_generator();
    
    string catalog;
    cout << "Tell me catalog path, f.ex. 'C:\\Users\\admin\\abcd'  " << endl;
    cout<<"Type 'here' to start from current catalog" << endl;
    cin >> catalog;
    //catalog = "C:\\Users\\micha\\Documents\\testycpp"; //testing
    
    reader* files = new reader(catalog);
    files->read(); //skanowanie w poszukiwaniu plikow
    vect fil_p=files->get_paths(); //odczytanie sciezek do programu glownego
    
    cout << endl << "------------------------";
    cout <<endl<<"Scanner on" << endl;
    cout<< "------------------------" << endl<<endl;
    
    scanner* analyze = new scanner(fil_p);
    //analyze->if_empty_check();
    analyze->summary();
    analyze->letter_histogram();
    cout << endl << endl;
    
    return 0;
}
