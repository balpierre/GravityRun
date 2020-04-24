/*
** EPITECH PROJECT, 2020
** GravityRun
** File description:
** menu
*/

#include "../../inc/graphic/graphic.hpp"

Menu::Menu()
{

    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("sonic1920.jpg");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Menu::~Menu()
{

}

int Game_Loop(void)
{
    Menu menu;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GravityRun");

    while (window.isOpen())
    {
        sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::Left) {
            //     if (options)
            //     if (play)
            //     if (exit)
            // }
        if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(menu.sprite);
        window.display();
    }
    return (0);
}