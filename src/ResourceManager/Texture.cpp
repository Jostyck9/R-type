//
// Created by romane on 19/11/2019.
//

#include "Texture.hpp"
#include "ECSExceptions.hpp"

namespace ecs {

Texture::Texture(const std::string &name, const std::string &filePath)
{
    _name = name;
    if (!_texture.loadFromFile(filePath))
        throw ECSExceptions("Error: Could not load texture \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

Texture::~Texture()
{
}

const std::string &Texture::getName()
{
    return _name;
}

sf::Texture &Texture::getSFMLTexture()
{
    return _texture;
}

}