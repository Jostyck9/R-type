//
// Created by romane on 19/11/2019.
//

#include <iostream>
#include <memory>
#include "ResourceManager.hpp"
#include "ECSExceptions.hpp"

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
    try {
        std::shared_ptr<Music> music = std::make_shared<Music>(name, filename);
        _musics.push_back(music);
    } catch (const ECSExceptions &e) {
        throw e;
    }
}

std::shared_ptr<Music> ResourceManager::getMusic(const std::string &name)
{
    try {
        for (auto &i: _musics)
            if (i->getName() == name)
                return i;
    } catch (const std::exception &e) {}
    throw ECSExceptions("Error: Could not get music \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

void ResourceManager::loadSound(const std::string &name, const std::string &filename)
{
    try {
        std::shared_ptr<Sound> sound = std::make_shared<Sound>(name, filename);
        _sounds.push_back(sound);
    } catch (const ECSExceptions &e) {
        throw e;
    }
}

std::shared_ptr<Sound> ResourceManager::getSound(const std::string &name)
{
    try {
        for (auto &i: _sounds)
            if (i->getName() == name)
                return i;
    } catch (const std::exception &e) {}
    throw ECSExceptions("Error: Could not get sound \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

void ResourceManager::loadTexture(const std::string &name, const std::string &filename)
{
    try {
        std::shared_ptr<Texture> texture = std::make_shared<Texture>(name, filename);
        _textures.push_back(texture);
    } catch (const ECSExceptions &e) {
        throw e;
    }
}

std::shared_ptr<Texture> ResourceManager::getTexture(const std::string &name)
{
    try {
        for (auto &i: _textures)
            if (i->getName() == name)
                return i;
    } catch (const std::exception &e) {}
    throw ECSExceptions("Error: Could not get texture \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

void ResourceManager::loadFont(const std::string &name, const std::string &filename)
{
    try {
        std::shared_ptr<Font> font = std::make_shared<Font>(name, filename);
        _fonts.push_back(font);
    } catch (const ECSExceptions &e) {
        throw e;
    }
}

std::shared_ptr<Font> ResourceManager::getFont(const std::string &name)
{
    try {
        for (auto &i: _fonts)
            if (i->getName() == name)
                return i;
    } catch (const std::exception &e) {}
    throw ECSExceptions("Error: Could not get font \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

void ResourceManager::loadText(const std::string &name, const std::string &filename)
{
    std::shared_ptr<Text> text = std::make_shared<Text>(name, filename);
    _texts.push_back(text);
}

std::shared_ptr<Text> ResourceManager::getText(const std::string &name)
{
    try {
        for (auto &i: _texts)
            if (i->getName() == name)
                return i;
    } catch (const std::exception &e) {}
    throw ECSExceptions("Error: Could not get text \'" + name + '\'', std::string(__FILE__) + ' ' + std::to_string(__LINE__));
}

}