/*
** EPITECH PROJECT, 2020
** GravityRun
** File description:
** graphic
*/

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>

enum Character
{
    undifined,
    SONIC,
    MARIO
};
class Menu {
    public:
        Menu();
        ~Menu();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Mouse mouse;
        std::string _username;
        std::string _ip;
        int _port;

    private:
    protected:
};

class Character_player {
    public:
    Character_player();
    ~Character_player();
    sf::Sprite sprite;
    sf::Texture texture;
    private:
    protected:
};

class Options {
    public:
        Options();
        ~Options();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Text options;
        sf::Text play;
        sf::Text exit;
        sf::Text volume_25;
        sf::Text volume_50;
        sf::Text volume_75;
        sf::Text volume_100;
        sf::Font font;
    private:
    protected:
};

<<<<<<< HEAD
#include <fstream>
#include <dirent.h>
#include <map>
#include <iterator>
#include <experimental/random>

int printSimpleVectorString(std::vector<std::string> vec);

Character Game_Loop(void);
int Options_Page(void);
Character Choose_Character(void);
#endif /* !GRAPHIC_H_ */