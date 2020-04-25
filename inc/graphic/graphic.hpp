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

#include <fstream>
#include <dirent.h>
#include <map>
#include <iterator>
#include <experimental/random>

class Map {
    private:
        std::vector<std::string> _filePaths;
        std::vector<std::string> _map;
        std::vector<std::vector<std::string>> _bloc;
        int _actualBock;
        int _nextBlock;
        
        std::map<char, sf::Sprite> _assetList;
        sf::Sprite _background;
        sf::Clock _scroll;
        sf::Clock _draw;
        int _size;
        int _speed;
        int _distance;
        int _sum;

    public:
        Map();
        ~Map();

        /* ---- init ---- */
        void initMap(std::string dir);
        std::vector<std::string> getFileContent(std::string filePath);
        std::vector<std::string> loadFilePaths(std::string dir);
        sf::Sprite getSpriteFromAssetList(char c);
        std::vector<std::vector<std::string>> getAllblock( std::vector<std::string> filePaths);

        /* ---- get/set Attribut ---- */
        std::vector<std::string> getMap();
        int getDistance();
        int getSize();
        int getSpeed();

        void setSize(int size);
        void setSpeed(int speed);
        void setDistance(int distance);

        int scrollMap();
        int drawBloc(sf::RenderWindow &window, std::vector<std::string> bloc1, std::vector<std::string> bloc2);
        void drawBackground(sf::RenderWindow &window);
        int draw(sf::RenderWindow &);
};

int printSimpleVectorString(std::vector<std::string> vec);

#endif /* !GRAPHIC_H_ */