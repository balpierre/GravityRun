/*
** EPITECH PROJECT, 2020
** GravityRun
** File description:
** chose_character
*/

#include "../../inc/graphic/graphic.hpp"

Options::Options()
{
    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("./assets/menucharacter.jpg");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Options::~Options()
{
}

Character Choose_Character(void)
{
    Menu menu;
    Options opt;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Choose your runner !");
    while (window.isOpen())
    {
        sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if ((MousePosition.y >= 464 && MousePosition.y <= 857) && (MousePosition.x >= 267 && MousePosition.x <= 871)) {
                    window.close();
                    return (SONIC);
                }
                if ((MousePosition.y >= 787 && MousePosition.y <= 867) && (MousePosition.x >= 1543 && MousePosition.x <= 1742)) {
                    window.close();
                    return (MARIO);
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
    window.clear();
    window.draw(opt.sprite);
    window.display();
    }
    return (undifined);
}