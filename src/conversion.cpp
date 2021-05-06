#include <sstream>                          //sstream
#include <string>                           //string
#include <vector>                           //vector, push_back

#include "conversion.h"                     //forward declarations


/*Takes an array of unsigned 8-bit integers (RGB values), converts
 * each value to hex, and appends the two-digit hex conversion to a
 * long hex string*/
std::string rgbArrToHexString(std::vector<uint_fast8_t> rgbVals){
    std::stringstream hexString;
    for (int n : rgbVals){
        if (n<10)
            hexString << std::hex << "0" << n;
        else
            hexString << std::hex << n;
    }
    return hexString.str();
}


/*Processes long hex string one character at a time;
 * if an 'a' is read, a newline character is added
 * to the plaintext conversion; otherwise the next character in
 * the hex string is read and the two-digit hex substring is
 * converted + added — the second character in the substring is
 * then skipped on the next iteration*/
std::string hexToText(std::string hexString){
    std::stringstream converted{};
    std::string seg{};
    uint_fast8_t n{};
    int length {static_cast<int>(std::size(hexString))};
    for (int i{0}; i<length; ++i) {
        if (hexString[i] == 'a')
            converted << "\n";
        else {
            seg = hexString.substr(i, 2);
            n = std::stoi(seg, nullptr, 16);
            converted << n;
            ++i;
        }
    }
    return converted.str();
}