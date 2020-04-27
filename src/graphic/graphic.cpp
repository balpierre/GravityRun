/*
** EPITECH PROJECT, 2019
** GravityRun
** File description:
** graphic.cpp
*/

#include "def/keyword.h"
#include "../../inc/graphic/map.hpp"

Map::Map()
{
    _size = 50;
    _speed = 0;
    _distance = 0;
    _score = 0;
    _backDist = 0;
}

Map::~Map()
{
    _bloc.clear();
}

std::vector<std::string> Map::getFileContent(std::string filePath)
{
    std::string line;
    std::ifstream myFile(filePath);
    std::vector<std::string> res;
    if (myFile.is_open()) {
        while (std::getline(myFile, line)) {
            res.push_back(line);
        }
    }
    myFile.close();
    return (res);
}

std::vector<std::string> Map::loadFilePaths(std::string dir)
{
    struct dirent *entry;
    DIR *directory = opendir(dir.c_str());
    std::vector<std::string> res;
    if (!directory)
        return (res);

    entry = readdir(directory);
    while (entry != NULL) {
        if (std::string(entry->d_name) != "." &&
        std::string(entry->d_name) != "..") {
            res.push_back(dir + "/" + std::string(entry->d_name));
        }
        entry = readdir(directory);
    }
    closedir(directory);
    return (res);
}

sf::Sprite loadSprite(const std::string path)
{
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(path);
    return (sf::Sprite(*texture));
}

std::vector<std::vector<std::string>> Map::getAllblock( std::vector<std::string> filePaths)
{
    std::vector<std::vector<std::string>> res;
    for (unsigned int i = 0; i < filePaths.size(); i++)
        res.push_back(getFileContent(filePaths[i]));
    return (res);
}

void Map::initMap(std::string dir)
{
    _filePaths = loadFilePaths(dir);
    if (_filePaths.size() != 0)
        _map = getFileContent(_filePaths.at(0));

    _background = loadSprite("./assets/background_ingame.png");
    _assetList.insert(std::pair<char, sf::Sprite>('X', loadSprite("./assets/bloc1.png")));
    _assetList.insert(std::pair<char, sf::Sprite>('#', loadSprite("./assets/bloc2.png")));
    _actualBock = std::experimental::randint(0, (int)_filePaths.size() - 1);
    _nextBlock = std::experimental::randint(0, (int)_filePaths.size() - 1);

    _bloc = getAllblock(_filePaths);
    _scroll.restart();
}

sf::Sprite Map::getSpriteFromAssetList(char c)
{
    auto itr = _assetList.begin();

    for (; itr != _assetList.end(); ++itr) {
        if (itr->first == c) {
            break;
        }
    }
    return (itr->second);
}

float getScale(float n, float size)
{
    float r;

    r = (float)((size+ 1.0f) / n);
    return ((float)r);
}

void Map::drawBackground(sf::RenderWindow &window)
{
    if (_backDist > 1920)
        _backDist = 0;
    _background.setPosition((-_backDist), 0);
    window.draw(_background);
    _background.setPosition(((float)_background.getPosition().x + 1920), 0);
    window.draw(_background);
}

int Map::drawBloc(sf::RenderWindow &window, std::vector<std::string> bloc1, std::vector<std::string> bloc2)
{
    sf::Vector2f pos(0, 0);
    sf::Sprite s;

    for (unsigned int i = 0; i < bloc1.size(); i++) {
        for (unsigned int j = 0; j < bloc1[i].size() && ( (int)(j * _size - _distance) < 1920) ; j++) {
            if (bloc1[i][j] == 'X' || (bloc1[i][j] == '#' && ((int)(j * _size) - _distance) > 0)) {
                pos.x =  (((int)j) * _size) - _distance;
                pos.y = (i * _size);
                s = getSpriteFromAssetList(bloc1[i][j]);
                s.setPosition(pos);
                s.setScale((float)getScale(s.getTextureRect().width, _size), (float)getScale(s.getTextureRect().width, _size));
                window.draw(s);
            }
        }
        if ((bloc1[i].size() * _size) - _distance <= window.getSize().x && i < bloc2.size()) {
            for (unsigned int j = 0; j < bloc2[i].size() && ( (int)((bloc1[i].size() + j) * _size) - _distance) < (int)window.getSize().x; j++) {
                if (bloc2[i][j] == 'X' || (bloc2[i][j] == '#' &&
                    ((int)((bloc1[i].size() + j) * _size) - _distance) > 0)) {
                    pos.x = (((bloc1[i].size() + j) * _size) - _distance);
                    pos.y = (i * _size);
                    s = getSpriteFromAssetList(bloc2[i][j]);
                    s.setPosition(pos);
                    s.setScale((float)getScale(s.getTextureRect().width, _size), (float)getScale(s.getTextureRect().width, _size));
                    window.draw(s);
                }
            }
        }
    }
    return (0x0);
}

int Map::draw(sf::RenderWindow &window)
{
    drawBackground(window);
    for (unsigned int i = 0; i < _bloc[_actualBock].size(); i++) {
        if (( _bloc[_actualBock][i].size() * _size) - _distance <= 0) {
            _distance = 0;
            _actualBock = _nextBlock;
            _nextBlock = std::experimental::randint(0, (int)_filePaths.size() - 1);
        }
    }
    drawBloc(window, _bloc[_actualBock], _bloc[_nextBlock]);
    return (0);
}

std::vector<std::string> Map::getMap(sf::Vector2f posPlayer __unused)
{
    std::vector<std::string> res;

    for (unsigned int i = 0; i < _bloc[_actualBock].size(); i++) {
        res.push_back(_bloc[_actualBock][i] + _bloc[_nextBlock][i]);
    }
    return (res);
}

void Map::setSpeed(int speed)
{
    _speed = speed;
}

int Map::getPos()
{
    for (unsigned int i = 0; i < _bloc[_actualBock].size(); i++) {
        for (uint j = 0; j < _bloc[_actualBock][i].size(); j++) {
            if ((j) - _distance / _size == 0)
                return (j);
        }
    }
    return (-1);
}

void Map::setSize(int size)
{
    _size = size;
}

int Map::getDistance()
{
    return (_distance);
}

int Map::getSize()
{
    return (_size);
}

int Map::getSpeed()
{
    return (_speed);
}

void Map::setDistance(int distance)
{
    _distance = distance;
}

int Map::getScore()
{
    return (_score);
}

void Map::restart()
{
    _distance = 0;
    _actualBock = std::experimental::randint(0, (int)_filePaths.size() - 1);
    _nextBlock = std::experimental::randint(0, (int)_filePaths.size() - 1);
    _scroll.restart();
}

int Map::scrollMap()
{
    if (_scroll.getElapsedTime().asMicroseconds() > 1) {
        _scroll.restart();
        _distance += 2;
        _backDist += 0.6;
        _score++;
    }

    return (0);
}