/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player class
*/

#include "Player/Player.hpp"

Player::Player(sf::Vector2f pos)
{
    this->_pos = pos;
    this->_speed = {0x0, 0x0};
    this->_acc = 120;
    this->_nextpos = pos;
    this->_lastUpt = NOW;
    this->_colX = false;
    this->_colY = true;
}

Player::~Player() {}

sf::Vector2f Player::get_pos()
{ 
    std::cout << this->_pos.x << " " << this->_pos.y << std::endl;
    return (this->_pos);
}

void Player::check_collision(std::vector<std::string> map, int dist)
{
    if (_acc > 0)
    {
        if (IS_A_WALL(map[(_nextpos.y + 20) / 50][_pos.x / 50 + dist / 50])) 
            this->_colY = true;
        else
            this->_colY = false;
    } else
    {
        if (IS_A_WALL(map[_nextpos.y / 50][_pos.x / 50 + dist / 50])) 
            this->_colY = true;
        else
            this->_colY = false;
    }
    // } else
    //     if (IS_A_WALL(map[this->_nextpos.y / 50][ dist / 50 + this->_pos.x / 50]) )
    //         this->_colY = true;
    //     else
    //         this->_colY = false;
}

void Player::update(std::vector<std::string> map, int dist)
{
    if (IS_A_WALL(map[this->_pos.y / 50][ dist / 50 + ( this->_pos.x + 20)/ 50 + 1])) {
        this->_pos.x -=2;
    }
    if (this->_pos.x <= 0 || this->_pos.y >= 1080)
        exit (0);
    if (DURATION<MILLISECONDS>(NOW - _lastUpt).count() > UPDATE_CD)
    {
        // if (this->_pos.y >= 1000 && this->_acc > 0 ||
        // this->_pos.y <= 0 && this->_acc < 0)
        //     return;
        check_collision(map, dist);
        if (!this->_colY)
        {
            this->_pos.y = this->_pos.y + ((this->_speed.y * UPDATE_CD) / 100);
            this->_speed.y = (this->_acc * UPDATE_CD) + this->_speed.y;
        }
        this->_nextpos.y = this->_pos.y + ((this->_speed.y * UPDATE_CD) / 100);

        this->_lastUpt = NOW;
    }
}

void Player::swap_gravity()
{
    this->_acc *= -1;
    this->_speed.y = 0x0;
}