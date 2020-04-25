/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** Player class header
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player/time_management.hpp"

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name);

#define UPDATE_CD 0.1

class Player
{
public:
    Player(sf::Vector2f pos);
    ~Player();
    sf::Vector2f get_pos();
    void update();
    void swap_gravity();
private:
    sf::Vector2f _pos;     // {pxX, pxY}
    sf::Vector2f _nextpos; // {pxX, pxY}
    sf::Vector2f _speed;   // mm / cs
    double       _acc;     // mm / cs^2
    TIMEPOINT _lastUpt;
};

#endif
