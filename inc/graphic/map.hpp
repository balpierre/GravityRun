/*
** EPITECH PROJECT, 2019
** GravityRun
** File description:
** map.hpp
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <fstream>
#include <dirent.h>
#include <map>
#include <iterator>
#include <experimental/random>

#include "../../inc/graphic/graphic.hpp"

class Map {
    private:
        std::vector<std::string> _filePaths;
        std::vector<std::string> _map;
        std::vector<std::vector<std::string>> _bloc;
        int _actualBock;
        int _nextBlock;

        float _backDist;
        std::map<char, sf::Sprite> _assetList;

        sf::Sprite _background;


        sf::Clock _scroll;

        int _size;
        int _speed;
        int _distance;
        int _score;

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
        int getScore();
        int getPos();

        std::vector<std::string> getMap(sf::Vector2f posPlayer);

        void setSize(int size);
        void setSpeed(int speed);
        void setDistance(int distance);

        void restart();

        int scrollMap();

        int drawBloc(sf::RenderWindow &window, std::vector<std::string> bloc1, std::vector<std::string> bloc2);
        void drawBackground(sf::RenderWindow &window);
        int draw(sf::RenderWindow &);
};

int printSimpleVectorString(std::vector<std::string> vec);
sf::Sprite loadSprite(const std::string path);
float getScale(float n, float size);

#endif