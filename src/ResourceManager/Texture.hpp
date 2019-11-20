//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_TEXTURE_HPP
#define R_TYPE_TEXTURE_HPP

#include <SFML/Graphics.hpp>
#include "ITexture.hpp"

class Texture : public ITexture {
public:
    Texture(const std::string& name, const std::string &filePath);
    ~Texture();

    const std::string &getName() override;

private:
    std::string _name;
    sf::Texture _texture;
};


#endif //R_TYPE_TEXTURE_HPP
