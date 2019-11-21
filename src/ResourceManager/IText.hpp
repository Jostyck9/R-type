//
// Created by romane on 20/11/2019.
//

#ifndef R_TYPE_ITEXT_HPP
#define R_TYPE_ITEXT_HPP

namespace ecs {
    class IText {
    public:
        
        /**
         * @brief Get name of the text
         * 
         * @return std::string 
         */
        virtual const std::string &getName() = 0;
        
        /**
         * @brief Set text of the Text
         * 
         * @return std::string 
         */
        virtual void setText(const std::string &text) = 0;
    };
}
 
#endif //R_TYPE_ITEXT_HPP
