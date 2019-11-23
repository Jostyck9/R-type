//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_FONT_HPP
#define R_TYPE_FONT_HPP

#include <SFML/Graphics.hpp>
#include "IFont.hpp"

namespace ecs {
    /**
     * @brief Font for the game
     * 
     */
    class Font : public IFont {
    public:
        Font(const std::string& name, const std::string &filePath);
        ~Font();

        /**
         * @brief Get name of the front
         * 
         * @return std::string 
         */
        const std::string &getName() override;

    private:
        std::string _name;
        sf::Font _font;
    };
}


#endif //R_TYPE_FONT_HPP
