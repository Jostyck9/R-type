//
// Created by romane on 19/11/2019.
//

#include <iostream>
#include <memory>
#include "ResourceManager.hpp"

namespace ecs {

ResourceManager &ResourceManager::getInstance()
{
    static ResourceManager ressourceManager;
    return ressourceManager;
}

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::loadMusic(const std::string &name, const std::string &filename)
{
    std::shared_ptr<Music> music = std::make_shared<Music>(name, filename);
    _musics.push_back(music);
}

std::shared_ptr<Music> ResourceManager::getMusic(const std::string &name)
{
    for (auto &i: _musics)
        if (i->getName() == name)
            return i;
    return nullptr;
}

void ResourceManager::loadSound(const std::string &name, const std::string &filename)
{
    std::shared_ptr<Sound> sound = std::make_shared<Sound>(name, filename);
    _sounds.push_back(sound);
}

std::shared_ptr<Sound> ResourceManager::getSound(const std::string &name)
{
    for (auto &i: _sounds)
        if (i->getName() == name)
            return i;
    return nullptr;
}

void ResourceManager::loadTexture(const std::string &name, const std::string &filename)
{
    std::shared_ptr<Texture> texture = std::make_shared<Texture>(name, filename);
    _textures.push_back(texture);
}

std::shared_ptr<Texture> ResourceManager::getTexture(const std::string &name)
{
    for (auto &i: _textures)
        if (i->getName() == name)
            return i;
    return nullptr;
}

void ResourceManager::loadFont(const std::string &name, const std::string &filename)
{
    std::shared_ptr<Font> font = std::make_shared<Font>(name, filename);
    _fonts.push_back(font);
}

std::shared_ptr<Font> ResourceManager::getFont(const std::string &name)
{
    for (auto &i: _fonts)
        if (i->getName() == name)
            return i;
    return nullptr;
}

}