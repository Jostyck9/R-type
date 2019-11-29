/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EntitiesLoader.hpp
*/

#ifndef ENTITIESLOADER_HPP
#define ENTITIESLOADER_HPP

#include "ILoader.hpp"
#include <vector>
#include <memory>
#include "IEntityConstructor.hpp"

class EntitiesLoader : public ILoader<ecs::entities::IEntityConstructor>
{
private:
public:
    EntitiesLoader(/* args */);
    ~EntitiesLoader();

    std::vector<std::shared_ptr<ecs::entities::IEntityConstructor>> loadAllLibrary() override;
    std::shared_ptr<ecs::entities::IEntityConstructor> loadLibrary(const std::string &) override;
};

#endif //ENTITIESLOADER_HPP