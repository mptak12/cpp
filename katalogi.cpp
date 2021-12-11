//#include <dirent.h> tylko w linux
#include <iostream>
#include <filesystem> //cpp 17+
#include <vector>
#include <string.h>
#include <fstream>
#include <Windows.h>

namespace fs = std::filesystem; //to musi byc u gory
using namespace std;
using vect = vector<wstring>;

/*
vect read(wstring pathToShow) {
    vect paths{};
    vect temp{};

    for (const auto& entry : fs::directory_iterator(pathToShow)) { //zmienna entry: tam sa wszystkie sciezki
        const auto filenameStr = entry.path().filename().string();  //w tym pliku sa same nazwy plikow
        //cout << entry << endl; //pomocnicze
        string ext = std::filesystem::path(entry).extension().string(); //zmienna z formatem pliku
        
        if (ext.compare(".txt") == 0 || ext.compare(".cpp") == 0) {
            //cout << "jest tekst lub cpp Nazwa: " << filenameStr << endl; //info ze znalazl plik
            paths.push_back(entry.path());
        }
        else if (entry.is_directory())
        {   
            temp = read(entry.path()); //rekurencja
            paths.insert(paths.end(), temp.begin(), temp.end()); //laczenie wektorow
        }
        
    }
    return paths;
}*/
class reader {
    const fs::path curr_path{ fs::current_path() }; //zmienna z aktualna sciezka
    vect paths{}, temp{};
    wstring src_path;

public:
    reader(string addr) {
        if (addr.compare("here") == 0) src_path = curr_path;
        else src_path=wstring(addr.begin(), addr.end()); //konwersja z string na wstring
    }

    void read();
    auto set_paths(vect p) { paths = p; }
    auto get_paths() const { return paths; }
};

void reader::read()//wstring pathToShow) 
{                                           
        for (const auto& entry : fs::directory_iterator(src_path)) { //zmienna entry: tam iteruj¹ siê sciezki
            const auto filenameStr = entry.path().filename().string();  //w tym pliku sa same nazwy plikow
            //cout << entry << endl; //pomocnicze
            string ext = std::filesystem::path(entry).extension().string(); //zmienna z formatem pliku

            if (ext.compare(".txt") == 0 || ext.compare(".cpp") == 0) {
                //cout << "jest tekst lub cpp Nazwa: " << filenameStr << endl; //info ze znalazl plik
                paths.push_back(entry.path());
            }
            /*
            else if (entry.is_directory())
            {  
                temp = read(entry.path()); //rekurencja
                paths.insert(paths.end(), temp.begin(), temp.end()); //laczenie wektorow
            }
            */
        }
        //return paths;
}

int main() {
    string catalog;

    cout << "Tell me catalog path. Type 'here' to start from current catalog" << endl;
    cin >> catalog;
  
    reader* files = new reader(catalog);
    files->read(); //tu jest blad 
    //funkcja wykorzystuje referencje - nie wiem jak jej uzywac, jesli nie przekazuje parametru do funkcji
    

    /*
    vect paths=files->get_paths(); //odczytanie sciezek do programu glownego

    if (paths.size() == 0) cout << "nie ma wody na pustyni" << endl;
    else 
        cout << "Liczba plikow cpp i txt: " << paths.size() <<endl; 
    
    for (const auto p : paths) wypisanie sciezek na ekran
        wcout << p<<endl;

    //Sleep(4000);
    //string s;
    //ifstream czytaj(paths[4]);
    //czytaj >> s;
    //czytaj.close();
    //cout << endl << s << endl;
    */
    return 0;
}