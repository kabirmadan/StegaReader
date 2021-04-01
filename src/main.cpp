#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>


std::string getTextInput(){
    std::string text{};
    getline(std::cin, text);
    return text;
}


void writeTextToFile(std::string filename, std::string text) {
    std::ofstream file(filename.c_str());
    file << text;
    file.close();
}


std::string hexFormat(std::string hexString){
    std::stringstream sstr;
    for (char c : hexString){
        if (c == 'a')
            sstr << '\n';
        else
            sstr << c;
    }
    return sstr.str();
}


int main() {
    std::cout << "Enter filename: ";
    std::string filename {getTextInput()};
    std::cout << "Enter text: ";
    std::string text {getTextInput()};
    writeTextToFile(filename, text);

    return 0;
}
