#include <iostream>
#include <iomanip>

#ifndef TORMENTA_UTILS_HPP
#define TORMENTA_UTILS_HPP

class Utils
{
public:
    static int getIntChoice();
    static void underscoreSpaces(std::string& string);
    static void ununderscoreSpaces(std::string& string);
};

#endif