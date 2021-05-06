#include <iostream>                         //cin, cout
#include <ostream>                          //ofstream
#include <fstream>                          //ofstream
#include <string>                           //string

#include "io_util.h"                        //forward declarations


/*Retrieves text input*/
std::string getTextInput(){
    std::string text{};
    getline(std::cin, text);
    return text;
}


/*Writes text to a new .txt file*/
void writeTextToFile(std::string filename, std::string text){
    std::ofstream file(filename.c_str());
    file << text;
    file.close();
}