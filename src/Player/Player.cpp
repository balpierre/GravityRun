/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player class
*/

#include "Player.hpp"

Player::Player(sf::Vector2f pos)
{
    this->_pos = pos;
}

Player::~Player() {}

sf::Vector2f Player::get_pos() { return (this->_pos); }

void Player::update()
{
    
}