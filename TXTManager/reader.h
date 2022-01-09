#include <iostream>
#include <filesystem> //cpp 17+
#include <vector>
#include "TXTDlg.h"
#include "TXT.h"
#pragma once
using std::vector, std::wstring;
namespace fs = std::filesystem;
using vect = vector<wstring>;

/// <summary>
/// this class is iterating through filesystem
/// variable path is uppdated every time a file matches to extension pattern stored in "flags"
/// </summary>

class reader
{
    vect paths{}; // paths to files 
    wstring src_path; //start catalog
    BOOL flags[3];

public:
    reader(wstring addr, BOOL f[]) {
        src_path = addr;
        flags[0] = f[0];
        flags[1] = f[1];
        flags[2] = f[2];
    }

    void read(); //main class function

    vect get_paths() const;
};

