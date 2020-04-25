/*
** EPITECH PROJECT, 2019
** GravityRun
** File description:
** graphic.cpp
*/

#include "../../inc/graphic/graphic.hpp"

int printSimpleVectorString(std::vector<std::string> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
}

Map::Map()
{
    _size = 50;
    _speed = 0;
    _distance = 0;
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
    _draw.restart();
}

sf::Sprite Map::getSpriteFromAssetList(char c)
{
    for (auto itr = _assetList.begin(); itr != _assetList.end(); ++itr) {
        if (itr->first == c) {
            return (itr->second);
        }
    }
}

float getScale(float n, float size)
{
    float r;
    
    r = (float)((size+ 1.0f) / n);
    return ((float)r);
}

void Map::drawBackground(sf::RenderWindow &window)
{
    window.draw(_background);
}


int Map::drawBloc(sf::RenderWindow &window, std::vector<std::string> bloc1, std::vector<std::string> bloc2)
{
    sf::Vector2f pos(0, 0);
    sf::Sprite s;

    for (unsigned int i = 0; i < bloc1.size(); i++) {
        for (unsigned int j = 0; j < bloc1[i].size(); j++) {
            if (bloc1[i][j] == 'X' || bloc1[i][j] == '#') {
                pos.x = (j * _size) - _distance;
                pos.y = (i * _size);
                s = getSpriteFromAssetList(bloc1[i][j]);
                s.setPosition(pos);
                s.setScale((float)getScale(s.getTextureRect().width, _size), (float)getScale(s.getTextureRect().width, _size));
                window.draw(s);
            }
        }

        if ((bloc1.size() *  _size)  - _distance <= window.getSize().x && i < bloc2.size()) {
            for (unsigned int j = 0; j < bloc2[i].size(); j++) {
                if (bloc2[i][j] == 'X' || bloc2[i][j] == '#') {
                    pos.x = ((j + bloc1.size()) * _size) - _distance;
                    pos.y = i * _size;
                    s = getSpriteFromAssetList(bloc2[i][j]);
                    s.setPosition(pos);
                    s.setScale((float)getScale(s.getTextureRect().width, _size), (float)getScale(s.getTextureRect().width, _size));
                    window.draw(s);
                }
            }
        }
    }
}

int Map::draw(sf::RenderWindow &window)
{
    // if (_draw.getElapsedTime().asMilliseconds() < 10) {
    //     return (0);
    // }

    // _draw.restart();
    drawBackground(window);
    if (_bloc[_actualBock].size() * _size - _distance <= 0) {
        _sum += _bloc[_actualBock].size();
        _actualBock = _nextBlock;
        _nextBlock = std::experimental::randint(0, (int)_filePaths.size() - 1);
    }
    drawBloc(window, _bloc[_actualBock], _bloc[_nextBlock]);
}

std::vector<std::string> Map::getMap()
{
    return (_map);
}

void Map::setSpeed(int speed)
{
    _speed = speed;
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

int Map::scrollMap()
{
    if (_scroll.getElapsedTime().asMicroseconds() > _speed) {
        _scroll.restart();
        _distance += 1;
    }
}