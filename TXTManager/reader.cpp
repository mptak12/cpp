#include "pch.h"
#include "reader.h"

/// summary ///
/// this function updates a class vector paths{}, which stores paths of files to analyze
/// files matching to pattern are added to vector
/// </summary>
void reader::read()
{
    
    const fs::directory_options options = (
        fs::directory_options::skip_permission_denied);   //allows to omit hidden files
    for (const auto& entry : fs::recursive_directory_iterator(src_path)) { //iterating folders & subfolders
        if (entry.path().extension().string() == ".cpp" && flags[0] || 
            entry.path().extension().string() == ".txt" && flags[1] || 
            entry.path().extension().string() == ".c" && flags[2]){
            paths.push_back(entry.path());
        }
    }
}

vect reader::get_paths() const { return paths; }