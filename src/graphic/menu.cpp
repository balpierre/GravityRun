/*
** EPITECH PROJECT, 2020
** GravityRun
** File description:
** menu
*/

#include "../../inc/graphic/graphic.h"

Menu::Menu()
{

    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("src/client/graphic/");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}