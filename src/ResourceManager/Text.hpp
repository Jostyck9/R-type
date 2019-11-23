//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_TEXT_HPP
#define R_TYPE_TEXT_HPP

#include <SFML/Graphics.hpp>
#include "IText.hpp"

namespace ecs {
    /**
     * @brief Text for the game
     * 
     */
    class Text : public IText {
    public:
        Text(const std::string& name, const std::string &filePath);
        ~Text();

        /**
         * @brief Get name of the text
         * 
         * @return std::string
         */
        const std::string &getName() override;
        
        /**
         * @brief Set text of the Text
         * 
         * @param std::string
         */
        void setText(const std::string &text) override; 

    private:
        std::string _name;
        sf::Text _text;
    };
}


#endif //R_TYPE_TEXT_HPP
