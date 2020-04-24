/*
** EPITECH PROJECT, 2020
** GravityRun
** File description:
** menu
*/

#include "../../inc/graphic/graphic.hpp"

Options::Options()
{
}

Options::~Options()
{
}

Menu::Menu()
{

    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("./assets/menu.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Menu::~Menu()
{

}

int Game_Loop(void)
{
    Menu menu;
    Options opt;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GravityRun");

    if (!opt.font.loadFromFile("./assets/Sonic Barrier.ttf")) {
        std::cout << "can't open this" << std::endl;
        return (84);
    }
    opt.font.loadFromFile("./assets/Sonic Barrier.ttf");
    opt.options.setFont(opt.font);
    opt.options.setPosition(60, 300);
    opt.options.setString("PLAY");
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
        window.draw(opt.options);
        window.display();
    }
    return (0);
}