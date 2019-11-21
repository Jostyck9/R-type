//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_ITEXTURE_HPP
#define R_TYPE_ITEXTURE_HPP

namespace ecs {
    class ITexture {
    public:
        
        /**
         * @brief Get name of the texture
         * 
         * @return std::string 
         */
        virtual const std::string &getName() = 0;
    };
}

#endif //R_TYPE_TEXTURE_HPP
