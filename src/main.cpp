#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>


std::string getTextInput(){
    std::string text{};
    getline(std::cin, text);
    return text;
}


std::string rgbArrToHexString(std::vector<uint_fast8_t> rgbVals){
    std::stringstream hexString;
    for (int n : rgbVals){
        if ((n % 10) == n){
            hexString << std::hex << "0" << n;
        }
        else
            hexString << std::hex << n;
    }
    return hexString.str();
}


std::string hexToText(std::string hexString){
    std::stringstream converted{};
    std::string seg{};
    int length {static_cast<int>(std::size(hexString))};
    uint_fast8_t n{};
    for (int i{0}; i<length; i+=2) {
        seg = hexString.substr(i, 2);
        if (seg == "aa"){
            converted << "\n\n";
            i+=2;
            seg = hexString.substr(i, 2);
        }
        else if (seg[0] == 'a'){
            converted << "\n";
            ++i;
            seg = hexString.substr(i, 2);
        }
        n = std::stoi(seg, nullptr, 16);
        converted << n;
    }
    return converted.str();
}


void writeTextToFile(std::string filename, std::string text) {
    std::ofstream file(filename.c_str());
    file << text;
    file.close();
}


int main() {
    /*bitmap_image image ("../test.bmp");
    if (!image){
        std::cout << "Error - could not open the selected image";
    }
    std::vector<uint_fast8_t> rgbVals{};
    int row;
    int col;
    unsigned int numRows{image.height()};
    unsigned int numCols{image.width()};
    rgb_t color;

    for (row = 0; row < numRows; ++row){
        for (col = 0; col < numCols; ++col) {
            image.get_pixel(col,row,color);
            if (color.red != 255 && color.green != 255 && color.blue != 255){
                rgbVals.push_back(color.red);
                rgbVals.push_back(color.green);
                rgbVals.push_back(color.blue);
            }
        }
    }*/

    return 0;
    
}
