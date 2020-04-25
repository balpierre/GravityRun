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
    this->_acc = 980;
    this->_lastUpt = NOW;
}

Player::~Player() {}

sf::Vector2f Player::get_pos() { 
    std::cout << this->_pos.x << " " << this->_pos.y << std::endl;
    return (this->_pos); }

void Player::update()
{
    if (DURATION<MILLISECONDS>(NOW - _lastUpt).count() > UPDATE_CD)
    {
        this->_pos.y = this->_pos.y + ((this->_speed.y * POSITION_UPDATE_TIME_IN_CS) / 100);
        this->_speed.y = (this->_acc * POSITION_UPDATE_TIME_IN_CS) + this->_speed.y;
        this->_lastUpt = NOW;
    }
}

void Player::swap_gravity()
{

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
        ply.update();
        rect.setPosition(ply.get_pos());
        wd->draw(rect);
        wd->display();
    }
}