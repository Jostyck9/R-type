//
// Created by romane on 19/11/2019.
//

#include <iostream>
#include <memory>
#include "ResourceManager.hpp"

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

std::shared_ptr<Music> &ResourceManager::getMusic(const std::string &name)
{
    for (auto &i: _musics)
        if (i->getName() == name)
            return i;
}
