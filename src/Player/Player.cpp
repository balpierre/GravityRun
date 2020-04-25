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

void Player::check_collision(std::vector<std::string> map)
{
    if (/*map[this->_nextpos.y / 50][this->_pos.x / 50] == 'X' || */(this->_nextpos.y >= 1000 && this->_acc > 0 ||
         this->_nextpos.y <= 0 && this->_acc < 0))
        this->_colY = true;
    else
        this->_colY = false;
    // if (map[this->_pos.y / 50][this->_nextpos.x / 50] == 'X')
    //     this->_colX = true;
    // else
    //     this->_colX = false;

}

void Player::update(std::vector<std::string> map)
{
    if (DURATION<MILLISECONDS>(NOW - _lastUpt).count() > UPDATE_CD)
    {
        // if (this->_pos.y >= 1000 && this->_acc > 0 ||
        // this->_pos.y <= 0 && this->_acc < 0)
        //     return;
        check_collision(map);
        if (!this->_colY)
        {
            this->_pos.y = this->_pos.y + ((this->_speed.y * UPDATE_CD) / 100);
            this->_speed.y = (this->_acc * UPDATE_CD) + this->_speed.y;
            this->_nextpos.y = this->_pos.y + ((this->_speed.y * UPDATE_CD) / 100);
        }
        this->_lastUpt = NOW;
    }
}

void Player::swap_gravity()
{
    this->_acc *= -1;
    this->_speed.y = 0x0;
}

int main(void)
{
    sf::RenderWindow *wd = create_window(1920, 1080, "Test");
    Player ply({50, 1000});
    sf::RectangleShape rect({20, 20});
    rect.setFillColor(sf::Color::White);

    

    while (wd->isOpen())
    {
        sf::Event evt;
        while (wd->pollEvent(evt))
        {
            if (evt.type == sf::Event::Closed)
                wd->close();
            if (evt.type == sf::Event::KeyPressed)
                if (evt.key.code == sf::Keyboard::Space)
                    ply.swap_gravity();
        }
        wd->clear();
        ply.update(std::vector<std::string>());
        rect.setPosition(ply.get_pos());
        wd->draw(rect);
        wd->display();
    }
}