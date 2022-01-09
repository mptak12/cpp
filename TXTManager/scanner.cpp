#include "pch.h"
#include "scanner.h"

/// <summary>
/// scans all files 
/// modifies word_count,letter_count, line_count
/// </summary>
void scanner::summ() {

    string word, line;
    for (const auto a : f_p)
    {
        fstream czytaj(a); //words, letters buffer
        while (czytaj >> word) {
            word_count++;
            all += word;
        }
        czytaj.close();

        fstream czytaj2(a); //number of lines buffer
        while (!czytaj2.eof()) {
            getline(czytaj2, line);
            line_count++;
        }
        //line_count--; //usuwam ostatni¹ pust¹ linijkê
        czytaj2.close();

    }
    letter_count = int(all.length());
}

int scanner::get_letters() const { return letter_count; }
int scanner::get_words() const { return word_count; }
int scanner::get_lines() const { return line_count; }