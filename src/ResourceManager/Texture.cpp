//
// Created by romane on 19/11/2019.
//

#include "Texture.hpp"

namespace ecs {

Texture::Texture(const std::string &name, const std::string &filePath)
{
    _name = name;
    _texture.loadFromFile(filePath);
}

Texture::~Texture()
{
}

const std::string &Texture::getName()
{
    return _name;
}

}