/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntitiesLoader.cpp
*/

#include "EntitiesLoader.hpp"
#include "DlLoader.hpp"
#include <experimental/filesystem>

using namespace ecs;

EntitiesLoader::EntitiesLoader(/* args */)
{
}

EntitiesLoader::~EntitiesLoader()
{
}

std::vector<std::shared_ptr<ecs::entities::IEntityConstructor>> EntitiesLoader::loadAllLibrary()
{
    std::vector<std::string> all_paths;
    DlLoader<ecs::entities::IEntityConstructor> lib;
    std::vector<std::shared_ptr<ecs::entities::IEntityConstructor>> all_libs;

    std::string path = "../lib/entities/";
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

std::shared_ptr<ecs::entities::IEntityConstructor> EntitiesLoader::loadLibrary(const std::string &path)
{
    DlLoader<ecs::entities::IEntityConstructor> lib;

    lib.loadInstance(path);
    auto instancied_lib = lib.getInstance();
    return (instancied_lib);
}