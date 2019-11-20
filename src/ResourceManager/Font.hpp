//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_FONT_HPP
#define R_TYPE_FONT_HPP

#include <SFML/Graphics.hpp>
#include "IFont.hpp"

class Font : public IFont {
public:
    Font(const std::string& name, const std::string &filePath);
    ~Font();

    const std::string &getName() override;

private:
    std::string _name;
    sf::Font _font;
};


#endif //R_TYPE_FONT_HPP
