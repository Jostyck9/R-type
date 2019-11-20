//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_RESSOURCEMANAGER_H
#define R_TYPE_RESSOURCEMANAGER_H

#include <vector>
#include "Music.hpp"
#include "Sound.hpp"
#include "Texture.hpp"
#include "Font.hpp"

namespace ecs {
    class ResourceManager {
    public:
        static ResourceManager &getInstance();

        ResourceManager(const ResourceManager &) = delete;
        ResourceManager operator=(const ResourceManager &) = delete;

    private:
        ResourceManager();
        ~ResourceManager();

    public:
        void loadMusic(const std::string &name, const std::string &filename);
        std::shared_ptr<Music> getMusic(const std::string &name);

        void loadSound(const std::string &name, const std::string &filename);
        std::shared_ptr<Sound> getSound(const std::string &name);

       void loadTexture(const std::string &name, const std::string &filename);
        std::shared_ptr<Texture> getTexture(const std::string &name);

        void loadFont(const std::string &name, const std::string &filename);
        std::shared_ptr<Font> getFont(const std::string &name);
    
    private:
        std::vector<std::shared_ptr<Music>> _musics;
        std::vector<std::shared_ptr<Sound>> _sounds;
        std::vector<std::shared_ptr<Texture>> _textures;
        std::vector<std::shared_ptr<Font>> _fonts;
    };
}

#endif //R_TYPE_RESSOURCEMANAGER_H
