//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_TEXTURE_HPP
#define R_TYPE_TEXTURE_HPP

#include <SFML/Graphics.hpp>

class Texture {
public:
    Texture(const std::string& name, const std::string &filePath);
    ~Texture();

    const std::string &getName();
    const sf::Texture &getTexture();

private:
    std::string _name;
    sf::Texture _texture;
};


#endif //R_TYPE_TEXTURE_HPP
