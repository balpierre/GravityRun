/*
** EPITECH PROJECT, 2019
** GravityRun
** File description:
** tools.cpp
*/

#include "../inc/graphic/graphic.hpp"

int printSimpleVectorString(std::vector<std::string> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
    return (0);
}