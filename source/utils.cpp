#include "../headers/utils.hpp"

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