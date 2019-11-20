//
// Created by romane on 19/11/2019.
//

#include "Font.hpp"

Font::Font(const std::string &name, const std::string &filePath)
{
    _name = name;
    _font.loadFromFile(filePath);
}

Font::~Font()
{
}

const sf::Font &Font::getFont()
{
    return _font;
}

const std::string &Font::getName()
{
    return _name;
}