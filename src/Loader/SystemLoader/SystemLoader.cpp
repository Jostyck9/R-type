/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemLoader.cpp
*/

#include "SystemLoader.hpp"
#include "DlLoader.hpp"

using namespace ecs;

SystemLoader::SystemLoader()
{
}

SystemLoader::~SystemLoader()
{
}

std::vector<std::shared_ptr<ecs::system::ISystemConstructor>> SystemLoader::loadAllLibrary()
{

}

std::shared_ptr<ecs::system::ISystemConstructor> SystemLoader::loadLibrary(const std::string &path)
{
    DlLoader<ecs::system::ISystemConstructor> lib;

    lib.loadInstance(path);
    auto instancied_lib = lib.getInstance();
    return(instancied_lib);
}