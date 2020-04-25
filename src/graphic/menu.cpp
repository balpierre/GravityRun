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
                if ((MousePosition.x >= 29 && MousePosition.x <= 267) && (MousePosition.y >= 281 && MousePosition.y <= 392)) {
                    std::cout << "PLAY" << std::endl;
                    Choose_Character();
                    window.close();
                }
                if ((MousePosition.y >= 413 && MousePosition.y <= 539 ) && (MousePosition.y >= 47 && MousePosition.y <= 420)) {
                    std::cout << "OPTIONS" << std::endl;
                }
                if ((MousePosition.y >= 258 && MousePosition.y <= 677) && (MousePosition.x >= 51 && MousePosition.x <= 572)) {
                    printf("exit");
                    // window.close();
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