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

class Connexion{
    public:
        Connexion();
        ~Connexion();
        int connexion_page();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::String playerInput;
        sf::Text playerText;
        sf::Text text;
        sf::Text text_username;
        sf::Text text_ip;
        sf::Text text_port;
        sf::Font font;
        std::string _ip;
        unsigned short _port;
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

int Game_Loop(void);
int Choose_Character(void);
#endif /* !GRAPHIC_H_ */