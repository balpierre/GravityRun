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
    Player(sf::Vector2f pos);
    ~Player();
    sf::Vector2f get_pos();
    void update();
private:
    sf::Vector2f _pos;
    sf::Vector2f _speed;
    sf::Vector2f _g;
};

#endif
