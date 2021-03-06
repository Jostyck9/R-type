//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_RESOURCEMANAGER_H
#define R_TYPE_RESOURCEMANAGER_H

#include <memory>
#include <vector>
#include "Music.hpp"
#include "Sound.hpp"
#include "Texture.hpp"
#include "Font.hpp"
#include "Text.hpp"

namespace ecs {
    /**
     * @brief Manage all resources of the game
     * 
     */
    class ResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();

    public:
        /**
         * @brief Load a music
         * 
         * @param name 
         * @param filename 
         */
        void loadMusic(const std::string &name, const std::string &filename);
        
        /**
         * @brief Get a music with her name
         * 
         * @param name 
         * @return std::shared_ptr<Music> 
         */
        std::shared_ptr<Music> getMusic(const std::string &name);

        
        /**
         * @brief Load a sound
         * 
         * @param name 
         * @param filename 
         */
        void loadSound(const std::string &name, const std::string &filename);
        
        /**
         * @brief Get a sound with his name
         * 
         * @param name 
         * @return std::shared_ptr<Sound> 
         */
        std::shared_ptr<Sound> getSound(const std::string &name);

        
        /**
         * @brief Load a texture
         * 
         * @param name 
         * @param filename 
         */
        void loadTexture(const std::string &name, const std::string &filename);
        
        /**
         * @brief Get a texture with her name
         * 
         * @param name 
         * @return std::shared_ptr<Texture> 
         */
        std::shared_ptr<Texture> getTexture(const std::string &name);

        
        /**
         * @brief Load a font
         * 
         * @param name 
         * @param filename 
         */
        void loadFont(const std::string &name, const std::string &filename);
        
        /**
         * @brief Get a font with her name
         * 
         * @param name 
         * @return std::shared_ptr<Font> 
         */
        std::shared_ptr<Font> getFont(const std::string &name);

    private:
        std::vector<std::shared_ptr<Music>> _musics;
        std::vector<std::shared_ptr<Sound>> _sounds;
        std::vector<std::shared_ptr<Texture>> _textures;
        std::vector<std::shared_ptr<Font>> _fonts;
    };
}

#endif //R_TYPE_RESOURCEMANAGER_H
