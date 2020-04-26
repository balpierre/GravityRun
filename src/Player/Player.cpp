/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player class
*/

#include "Player/Player.hpp"

Player::Player(sf::Vector2f pos, Character ch)
{
    this->_pos = pos;
    this->_speed = {0x0, 0x0};
    this->_acc = 180;
    this->_nextpos = pos;
    this->_lastUpt = NOW;
    this->_colX = false;
    this->_colY = true;
    this->_ch = ch;
    std::string path = "assets/";
    if (ch == MARIO)
        path.append("mario.png");
    else
        path.append("sonic.png");
    this->_text.loadFromFile(path);
    this->_sprite.setTexture(_text);
    this->_sprite.setPosition(pos);
    this->_offsetX = 0;
    this->_offsetY = 0;
    this->_sprite.setTextureRect(sf::Rect<int>(_offsetX, _offsetY, SPRITE_SIZE, SPRITE_SIZE));
}

Player::~Player() {}

sf::Vector2f Player::get_pos()
{ 
    std::cout << this->_pos.x << " " << this->_pos.y << std::endl;
    return (this->_pos);
}

bool Player::check_collision(std::vector<std::string> map, int dist)
{
    if (_acc > 0)
    {
        if (IS_A_WALL(map[(_nextpos.y + 100) / 50][_pos.x / 50 + dist / 50])) {
            this->_colY = true;
            this->_speed.y = 0;
        } else
            this->_colY = false;
    } else
    {
        if (IS_A_WALL(map[_nextpos.y / 50][_pos.x / 50 + dist / 50])) 
        {
            this->_colY = true;
            this->_speed.y = 0;
        } else
            this->_colY = false;
    }
    if (_pos.x < 0 || _pos.y < 0 || _pos.y > 1060)
        return (false);
    return (true);
}

bool Player::update(std::vector<std::string> map, int dist)
{
    if (IS_A_WALL(map[this->_pos.y / 50][ dist / 50 + ( this->_pos.x + 100)/ 50 + 1])) {
        this->_pos.x -=2;
    }
    if (this->_pos.x <= 0 || this->_pos.y >= 1080)
        exit (0);
    if (DURATION<MILLISECONDS>(NOW - _lastUpt).count() > UPDATE_CD)
    {
        if (!check_collision(map, dist))
            return (false);
        if (!this->_colY)
        {
            this->_pos.y = this->_pos.y + ((this->_speed.y * UPDATE_CD) / 100);
            this->_speed.y = (this->_acc * UPDATE_CD) + this->_speed.y;
        }
        this->_nextpos.y = this->_pos.y + ((this->_speed.y * UPDATE_CD) / 100);

        this->_lastUpt = NOW;
    }
    update_sprite();
    this->_sprite.setPosition(this->_pos);
}

void Player::update_sprite()
{
    if (_colY && _acc > 0)
    {
        if (_offsetY != 0 || _offsetX == 500)
            _offsetX = 0;
        else
            _offsetX += SPRITE_SIZE;
        _offsetY = 0;
    }
    if (_colY && _acc < 0)
    {
        if (_offsetY != 100 || _offsetX == 500)
            _offsetX = 0;
        else
            _offsetX += SPRITE_SIZE;
        _offsetY = 100;
    }
    if (!_colY)
    {
        if (_offsetY != 200 || _offsetX == 500)
            _offsetX = 0;
        else
            _offsetX += SPRITE_SIZE;
        _offsetY = 200;
    }
    this->_sprite.setTextureRect(sf::Rect<int>(_offsetX, _offsetY, SPRITE_SIZE, SPRITE_SIZE));
}

void Player::swap_gravity()
{
    this->_acc *= -1;
    this->_speed.y = 0x0;
}

sf::Sprite Player::get_sprite() { return (this->_sprite); }