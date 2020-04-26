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
    if (this->_acc > 0) {
        if ( IS_A_WALL(map[ ((int)((float)this->_nextpos.y / 50.0f + 1.0f / 2.0f)) ][ dist / 50 + this->_pos.x / 50]) )/*|| (this->_nextpos.y >= 1000 && this->_acc > 0 ||
         this->_nextpos.y <= 0 && this->_acc < 0))*/
            this->_colY = true;
        else
            this->_colY = false;
    } else
        if (IS_A_WALL(map[this->_nextpos.y / 50][ dist / 50 + this->_pos.x / 50]) )/*|| (this->_nextpos.y >= 1000 && this->_acc > 0 ||
         this->_nextpos.y <= 0 && this->_acc < 0))*/
            this->_colY = true;
        else
            this->_colY = false;
    if (IS_A_WALL(map[this->_pos.y / 50][ dist / 50 + this->_pos.x / 50 + 1]))
        this->_pos.x -=2;
    // if (map[this->_pos.y / 50][this->_nextpos.x / 50] == 'X')
    //     this->_colX = true;
    // else
    //     this->_colX = false;

}

void Player::update(std::vector<std::string> map, int dist)
{
    if (DURATION<MILLISECONDS>(NOW - _lastUpt).count() > UPDATE_CD)
    {
        std::cout << "Time to update pos " << DURATION<MILLISECONDS>(NOW - _lastUpt).count() << std::endl;
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