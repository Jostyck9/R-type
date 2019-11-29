/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntitiesLoader.cpp
*/

#include "EntitiesLoader.hpp"
#include "DlLoader.hpp"

using namespace ecs;

EntitiesLoader::EntitiesLoader(/* args */)
{
}

EntitiesLoader::~EntitiesLoader()
{
}

std::vector<std::shared_ptr<ecs::entities::IEntityConstructor>> EntitiesLoader::loadAllLibrary()
{

}

std::shared_ptr<ecs::entities::IEntityConstructor> EntitiesLoader::loadLibrary(const std::string &path)
{
    DlLoader<ecs::entities::IEntityConstructor> lib;

    lib.loadInstance(path);
    auto instancied_lib = lib.getInstance();
    return(instancied_lib);
}