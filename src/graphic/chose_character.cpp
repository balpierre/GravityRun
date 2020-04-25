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

int Choose_Character(void)
{
    Menu menu;
    Options opt;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Options Page");
    // if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
    //     printf("pas marché l'écriture");
    //     return (84);
    // }
    // opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    // opt.options.setFont(opt.font);
    // opt.options.setPosition(60,300);
    // opt.options.setString("OPTIONS");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    window.clear();
    window.draw(opt.sprite);
    // window.draw(opt.options);
    window.display();
    }
    return (0);
}