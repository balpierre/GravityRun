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
    this->texture.loadFromFile("./assets/menuokay.png");
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
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // std::cout << "x= " << MousePosition.x << "y= " << MousePosition.y << std::endl;
                if ((MousePosition.x >= 29 && MousePosition.x <= 267) && (MousePosition.y >= 281 && MousePosition.y <= 392)) {
                    Choose_Character();
                    window.close();
                }
                if ((MousePosition.y >= 418 && MousePosition.y <= 526 ) && (MousePosition.x >= 61 && MousePosition.x <= 414)) {
                    Options_Page();
                    window.close();
                }
                if ((MousePosition.y >= 569 && MousePosition.y <= 682) && (MousePosition.x >= 68 && MousePosition.x <= 256)) {
                    window.close();
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(menu.sprite);
        window.display();
    }
    return (0);
}