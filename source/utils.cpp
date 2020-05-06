#include "../headers/utils.hpp"

int Utils::getIntChoice()
{
    int choice = 0;

    std::cout << '\n' << ": ";

    std::cin >> std::setw(1) >> choice;

    if( !std::cin.good() ) choice = -1;

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    return choice;
}