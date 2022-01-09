#pragma once
#include <iostream>
#include <filesystem> //catalogs
#include <vector> 
#include <string.h>
#include <fstream>  //opening files


#pragma once
using std::vector, std::wstring,std::string, std::fstream;
namespace fs = std::filesystem; //to scan through catalogs
using vect = vector<wstring>;

/// <summary>
/// this class opens vect variable from "reader" class
/// then it counts files parameters
/// parameters are passed to main MFC class through getters() 
/// </summary>

class scanner
{
    vect f_p{}; //file paths from reader class
    string all;    
    int word_count{ 0 };
    int letter_count{ 0 };
    int line_count{ 0 };
    
public:
    scanner(vect f_p) { 
        this->f_p = f_p; 
    }

    void summ();
    
    int get_letters() const;
    int get_words() const;
    int get_lines() const;
};

