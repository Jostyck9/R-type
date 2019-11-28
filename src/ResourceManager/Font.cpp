//
// Created by romane on 19/11/2019.
//

#include "Font.hpp"
#include "ECSExceptions.hpp"

namespace ecs {

Font::Font(const std::string &name, const std::string &filePath)
{
    _name = name;
    if (!_font.loadFromFile(filePath))
        throw ECSExceptions("Error: Could not load font \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

Font::~Font()
{
}

const std::string &Font::getName()
{
    return _name;
}

sf::Font &Font::getSFMLFont()
{
    return _font;
}

}