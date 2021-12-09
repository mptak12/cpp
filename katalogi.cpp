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
    vect paths{}, temp{};
public:
    vect read(wstring pathToShow);
    auto set_paths(vect p) { paths = p; }
    auto get_paths() const { return paths; }
    //dorobic gettery settery
};

vect reader::read(wstring pathToShow) {

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
}

int main() {
    reader a;

    const fs::path currpath{ fs::current_path() }; //zmienna z aktualna sciezka
    wstring path{};
    vect paths;

    cout << "Tell me catalog path. Type 'here' to start from current catalog" << endl;
    wcin >> path;

    string p(path.begin(), path.end()); //zmienna do porownania
    
    if (p.compare("here") == 0) paths = reader::read(currpath);
    else paths = reader::read(path);

    if (paths.size() == 0) cout << "nie ma wody na pustyni" << endl;
    else 
        cout << "Liczba plikow cpp i txt: " << paths.size() <<endl;
    
    for (const auto p : paths)
        wcout << p<<endl;

    Sleep(4000);
    //string s;
    //ifstream czytaj(paths[4]);
    //czytaj >> s;
    //czytaj.close();
    //cout << endl << s << endl;
    return 0;
}