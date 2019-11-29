/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testResourceManager.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "IAudio.hpp"
#include "IFont.hpp"
#include "ITexture.hpp"
#include "Sound.hpp"
#include "Music.hpp"
#include "Font.hpp"
#include "Text.hpp"
#include "Texture.hpp"
#include "ResourceManager.hpp"

void redirect_std(void) 
{
    cr_redirect_stderr();
}

Test(Sound, sound_is_ok)
{
    std::unique_ptr<ecs::IAudio> sound = std::make_unique<ecs::Sound>("laser", "resources/laser.wav");

    cr_assert_eq(sound->getName(), "laser");
}

Test(Music, music_is_ok)
{
    std::unique_ptr<ecs::IAudio> music = std::make_unique<ecs::Music>("music", "resources/music.ogg");

    cr_assert_eq(music->getName(), "music");
}

Test(Texture, texture_is_ok)
{
    std::unique_ptr<ecs::ITexture> texture = std::make_unique<ecs::Texture>("texture", "resources/texture.jpg");

    cr_assert_eq(texture->getName(), "texture");
}

Test(Font, font_is_ok)
{
    std::unique_ptr<ecs::IFont> font = std::make_unique<ecs::Font>("font", "resources/Arial.ttf");

    cr_assert_eq(font->getName(), "font");
}

Test(ResourceManager, music_manager_is_ok)
{
    ecs::ResourceManager resourceManager;

    resourceManager.loadMusic("music", "resources/music.ogg");
    std::shared_ptr<ecs::Music> music = resourceManager.getMusic("music");
    
    cr_assert_eq(music->getName(), "music");
}

Test(ResourceManager, sound_manager_is_ok)
{
    ecs::ResourceManager resourceManager;

    resourceManager.loadSound("sound", "resources/laser.wav");
    std::shared_ptr<ecs::Sound> sound = resourceManager.getSound("sound");
    
    cr_assert_eq(sound->getName(), "sound");
}

Test(ResourceManager, texture_manager_is_ok)
{
    ecs::ResourceManager resourceManager;

    resourceManager.loadTexture("texture", "resources/texture.jpg");
    std::shared_ptr<ecs::Texture> texture = resourceManager.getTexture("texture");
    
    cr_assert_eq(texture->getName(), "texture");
}

Test(ResourceManager, font_manager_is_ok)
{
    ecs::ResourceManager resourceManager;

    resourceManager.loadFont("font", "resources/Arial.ttf");
    std::shared_ptr<ecs::Font> font = resourceManager.getFont("font");
    
    cr_assert_eq(font->getName(), "font");
}