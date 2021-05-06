#include <iostream>                         //cin, cout
#include <string>                           //string
#include <vector>                           //vector, push_back

#include "conversion.h"                     //rgbArrToHexString, hexToText
#include "io_util.h"                        //getTextInput, writeTextToFile

#include "third_party/bitmap_image.hpp"     //bitmap_image, height, width, get_pixel


int main() {

    //open bitmap
    std::cout << "Enter filename (without .bmp extension): ";
    std::string filename {getTextInput()};
    bitmap_image image ("../bitmap/" + filename + ".bmp");
    if (!image)
        std::cout << "Error - could not open the selected image";

    //remaining variable declarations
    std::string convertedString{};
    std::vector<uint_fast8_t> rgbVals{};
    int row;
    int col;
    unsigned int numRows{image.height()};
    unsigned int numCols{image.width()};
    rgb_t color;

    //iterate through image pixel by pixel, storing each R,G, and B value in a vector
    for (row = 0; row < numRows; ++row){
        for (col = 0; col < numCols; ++col) {
            image.get_pixel(col,row,color);
            if (color.red != 255 && color.green != 255 && color.blue != 255){
                rgbVals.push_back(color.red);
                rgbVals.push_back(color.green);
                rgbVals.push_back(color.blue);
            }
        }
    }

    //convert RGB values to plain text
    convertedString = rgbArrToHexString(rgbVals);
    convertedString = hexToText(convertedString);

    //output file
    writeTextToFile("../" + filename + ".txt", convertedString);
    std::cout << "\nConversion complete - see '" << filename << ".txt'";

    return 0;

}