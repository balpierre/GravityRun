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

int Text_File(Options *opt)
{
    opt->font.loadFromFile("./assets/Sonic Barrier.ttf");
    opt->play.setFont(opt->font);
    opt->play.setPosition(60, 300);
    opt->play.setCharacterSize(100);
    opt->play.setString("PLAY");

    opt->font.loadFromFile("./assets/Sonic Barrier.ttf");
    opt->options.setFont(opt->font);
    opt->options.setPosition(60, 450);
    opt->options.setCharacterSize(100);
    opt->options.setString("Options");

    opt->font.loadFromFile("./assets/Sonic Barrier.ttf");
    opt->exit.setFont(opt->font);
    opt->exit.setPosition(60, 600);
    opt->exit.setCharacterSize(100);
    opt->exit.setString("Exit");
    return (0);
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
    Text_File(&opt);
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
        window.draw(opt.play);
        window.draw(opt.options);
        window.draw(opt.exit);
        window.display();
    }
    return (0);
}