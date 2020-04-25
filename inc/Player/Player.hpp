/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** Player class header
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name);

#define POSITION_UPDATE_TIME_IN_CS 10

class Player
{
public:
    Player(sf::Vector2f pos);
    ~Player();
    sf::Vector2f get_pos();
    void update();
private:
    sf::Vector2f _pos;   // {pxX, pxY}
    sf::Vector2f _speed; // mm / cs
    double       _acc;   // mm / cs^2
};

#endif
