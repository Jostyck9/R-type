//
// Created by romane on 19/11/2019.
//

#include "Texture.hpp"

Texture::Texture(const std::string &name, const std::string &filePath)
{
    _name = name;
    _texture.loadFromFile(filePath);
}

Texture::~Texture()
{
}

const sf::Texture &Texture::getTexture()
{
    return _texture;
}

const std::string &Texture::getName()
{
    return _name;
}