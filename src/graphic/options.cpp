/*
** EPITECH PROJECT, 2020
** GravityRun
** File description:
** options
*/

#include "../../inc/graphic/graphic.hpp"

Options::Options()
{
    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("./assets/sonicoption.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Options::~Options()
{

}

int Options_Page(void)
{
    Options opt;
    sf::Music music;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Options");
    while (window.isOpen())
    {
        sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //     if ((MousePosition.x >= 61 && MousePosition.x <= 270 ) && (MousePosition.y >= 369 && MousePosition.y <= 472)) {
            // }
            //     if ((MousePosition.x >= 56 && MousePosition.x <= 264) && (MousePosition.y >= 564 && MousePosition.y <= 670)) {
            //         std::cout << "STOP" << std::endl;
            //     }

                if ((MousePosition.x >= 52 && MousePosition.x <= 276) && (MousePosition.y >= 839 && MousePosition.y <= 948)) {
                    Game_Loop();
                    window.close();
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(opt.sprite);
        window.display();
    }
    return (0);
}