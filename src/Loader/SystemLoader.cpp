/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemLoader.cpp
*/

#include "SystemLoader.hpp"

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

std::shared_ptr<ecs::system::ISystemConstructor> loadLibrary(const std::string &path)
{

}