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

void Utils::underscoreSpaces(std::string& t_string)
{
    for (auto &i : t_string)
    {
        if(i == ' ') i = '_';
    }
}

void Utils::ununderscoreSpaces(std::string& t_string)
{
    for (auto &i : t_string)
    {
        if(i == '_') i = ' ';
    }
}