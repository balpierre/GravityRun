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
#include <vector>

#include "Player/time_management.hpp"

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name);

#define UPDATE_CD 0.1
#define IS_A_WALL(c) (c == 'X' || c == '#')

class Player
{
public:
    Player(sf::Vector2f pos);
    ~Player();
    sf::Vector2f get_pos();
    void update(std::vector<std::string> map, int dist);
    void swap_gravity();
    void check_collision(std::vector<std::string> map, int dist);
private:
    sf::Vector2f _pos;     // {pxX, pxY}
    sf::Vector2f _nextpos; // {pxX, pxY}
    sf::Vector2f _speed;   // mm / cs
    double       _acc;     // mm / cs^2
    TIMEPOINT _lastUpt;
    bool _colX, _colY;
};

#endif
