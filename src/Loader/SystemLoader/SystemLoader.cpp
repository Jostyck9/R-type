/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemLoader.cpp
*/

#include "SystemLoader.hpp"
#include "DlLoader.hpp"
#include <experimental/filesystem>

using namespace ecs;

SystemLoader::SystemLoader()
{
}

SystemLoader::~SystemLoader()
{
}

std::vector<std::shared_ptr<ecs::system::ISystemConstructor>> SystemLoader::loadAllLibrary()
{
    std::vector<std::string> all_paths;
    DlLoader<ecs::system::ISystemConstructor> lib;
    std::vector<std::shared_ptr<ecs::system::ISystemConstructor>> all_libs;

    std::string path = "./build/lib/systems/";
    try
    {
        for (const auto &entry : std::experimental::filesystem::directory_iterator(path))
        {
            all_paths.push_back(entry.path());
        }
        for (size_t i = 0; i < all_paths.size(); i++)
        {
            lib.loadInstance(all_paths[i]);
            all_libs.push_back(lib.getInstance());
        }
        return (all_libs);
    }
    catch (const std::exception &e)
    {
    }
    throw RTypeExceptions("Error: Cannont acces to lib folder", "Entities Loader");
}

std::shared_ptr<ecs::system::ISystemConstructor> SystemLoader::loadLibrary(const std::string &path)
{
    DlLoader<ecs::system::ISystemConstructor> lib;

    lib.loadInstance(path);
    auto instancied_lib = lib.getInstance();
    return(instancied_lib);
}