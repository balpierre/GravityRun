/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** Player class header
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();
    ~Player();
private:
    sf::Vector2f _pos;
    sf::Vector2f _acc;
};

#endif
