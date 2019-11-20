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
    std::shared_ptr<Music> &getMusic(const std::string &name);
/*
    void loadsSound(const std::string &name, const std::string &filename);
    const sf::Sound &getSound(const std::string &name);

    void loadTexture(const std::string &name, const std::string &filename);
    const sf::Texture &getTexture(const std::string &name);

    void loadFont(const std::string &name, const std::string &filename);
    const sf::Font &getFont(const std::string &name);*/

private:
    std::vector<std::shared_ptr<Music>> _musics;
    std::vector<Sound> _sounds;
    std::vector<Texture> _textures;
    std::vector<Font> _fonts;
};

#endif //R_TYPE_RESSOURCEMANAGER_H
