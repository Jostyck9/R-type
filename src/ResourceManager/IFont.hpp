//
// Created by romane on 20/11/2019.
//

#ifndef R_TYPE_IFONT_HPP
#define R_TYPE_IFONT_HPP

namespace ecs {
    class IFont {
    public:
    
        /**
         * @brief Get name of the music
         * 
         * @return std::string 
         */
        virtual const std::string &getName() = 0;
    };
}

#endif //R_TYPE_IFONT_HPP
