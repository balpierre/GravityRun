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

int main(void)
{
    sf::RenderWindow *wd = create_window(1920, 1080, "Test");
    Player ply({50, 1060});
    sf::RectangleShape rect({20, 20});
    rect.setFillColor(sf::Color::White);

    

    while (wd->isOpen())
    {
        sf::Event evt;
        while (wd->pollEvent(evt))
        {
            if (evt.type == sf::Event::Closed)
                wd->close();
        }
        wd->clear();
        ply.update();
        rect.setPosition(ply.get_pos());
        wd->draw(rect);
        wd->display();
    }
}