#include <iostream>
#include <filesystem> //cpp 17+
#include <vector>
#include <string.h>
#include <fstream>
#include <Windows.h>


using std::cout, std::cin, std::vector, std::wstring, std::string, std::wcout, std::wcin, std::endl, std::fstream;
namespace fs = std::filesystem;
using vect = vector<wstring>;

class reader {
    const fs::path curr_path{ fs::current_path() }; //zmienna z aktualna sciezka
    vect paths{}; //tu skladowane sa sciezki do plikow
    wstring src_path; //tu zaczynamy analize

public:
    reader(string addr) {
        if (addr.compare("here") == 0) src_path = curr_path;
        else src_path=wstring(addr.begin(), addr.end()); //konwersja z string na wstring
    }

    vect read(); //glowna funkcja z klasy
    auto set_paths(vect p) { paths = p; }
    auto get_paths() const { return paths; }
};

vect reader::read()//wstring pathToShow) 
{
    vect pa, temp; //wektory potrzebne do rekurencji

        for (const auto& entry : fs::directory_iterator(src_path)) { //zmienna entry: tam iteruj¹ siê sciezki
            const auto filenameStr = entry.path().filename().string();  //filenamestr = nazwa pliku
            string ext = std::filesystem::path(entry).extension().string(); //zmienna z formatem pliku

            if (ext.compare(".txt") == 0 || ext.compare(".cpp") == 0) {
                //cout << "jest tekst lub cpp Nazwa: " << filenameStr << endl; //info ze znalazl plik
                paths.push_back(entry.path());
            }
            
            else if (entry.is_directory())
            {  
                src_path = entry.path();
                temp = read(); //rekurencja
                paths.insert(paths.end(), temp.begin(), temp.end()); //laczenie wektorow
            }
        }
        return pa;
}

class scanner {
    vect f_p{}; //od poprzedniej klasy - sciezki plikow
    int word_count{ 0 };
public:
    scanner(vect f_p) { this->f_p = f_p; }  //konstr
    void if_empty_check();        //sprawdza czy puste
    void summary();
};

void scanner::if_empty_check() {
    if(f_p.size()==0) cout<< "0 matching" << endl;
    else
        cout << "Number of matches: " << f_p.size() << endl;
    for (const auto p : f_p) //wypisanie sciezek na ekran
        wcout << p << endl;
}

void scanner::summary() {
    //ta funkcja skanuje wszystkie podane sciezki i podaje ich ogolne podsumowanie
    string word;
    for (const auto a : f_p)
    {
        fstream czytaj(a);
        while(czytaj >> word)
            word_count++;
        
        czytaj.close();
    }
    cout <<"Number of words in files : "<< word_count << endl;
}

int main() {
    string catalog;
    cout << "Tell me catalog path, f.ex. 'C:\\Users\\admin\\abcd'  " << endl;
    cout<<"Type 'here' to start from current catalog" << endl;
    cin >> catalog;
  
    reader* files = new reader(catalog);
    files->read(); //skanowanie w poszukiwaniu plikow
    vect fil_p=files->get_paths(); //odczytanie sciezek do programu glownego
    
    cout << endl << "------------------------";
    cout <<endl<<"Scanner on" << endl;
    cout<< "------------------------" << endl<<endl;
    
    scanner* analyze = new scanner(fil_p);
    analyze->if_empty_check();
    analyze->summary();
    Sleep(4000);
   
    return 0;
}