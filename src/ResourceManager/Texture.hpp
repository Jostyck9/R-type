//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_TEXTURE_HPP
#define R_TYPE_TEXTURE_HPP

#include <SFML/Graphics.hpp>
#include "ITexture.hpp"

namespace ecs {
    /**
     * @brief
     * 
     */
    class Texture : public ITexture {
    public:
        Texture(const std::string& name, const std::string &filePath);
        ~Texture();

        /**
         * @brief Get name of the texture
         * 
         * @return std::string
         */
        const std::string &getName() override;
        /**
         * @brief Get SFML texture of the Texture
         *
         * @return sf::Texture
         */
        sf::Texture &getSFMLTexture();
    private:
        std::string _name;
        sf::Texture _texture;
    };
}

#endif //R_TYPE_TEXTURE_HPP
