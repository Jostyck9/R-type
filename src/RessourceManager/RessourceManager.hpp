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

class RessourceManager {
public:
    static RessourceManager &getInstance();

    RessourceManager(const RessourceManager &) = delete;
    RessourceManager operator=(const RessourceManager &) = delete;

private:
    RessourceManager();
    ~RessourceManager();

private:
    std::vector<Music> _musics;
    std::vector<Sound> _sounds;
    std::vector<Texture> _textures;
    std::vector<Font> _fonts;
};


#endif //R_TYPE_RESSOURCEMANAGER_H
