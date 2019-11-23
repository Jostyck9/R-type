//
// Created by romane on 19/11/2019.
//

#include "Text.hpp"

namespace ecs {

Text::Text(const std::string &name, const std::string &text)
{
    _name = name;
    setText(text);
}

Text::~Text()
{
}

const std::string &Text::getName()
{
    return _name;
}

void Text::setText(const std::string &text)
{
    _text.setString(text);
}

}