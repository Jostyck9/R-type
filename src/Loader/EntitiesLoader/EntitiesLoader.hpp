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
namespace ecs
{
class EntitiesLoader : public ILoader<ecs::entities::IEntityConstructor>
{
private:
public:
    EntitiesLoader(/* args */);
    ~EntitiesLoader();

     /**
     * @brief load all libraries which are IEntityConstructor
     * 
     * @return std::vector<std::shared_ptr<ecs::system::IEntityConstructor>> 
     */
    std::vector<std::shared_ptr<ecs::entities::IEntityConstructor>> loadAllLibrary() override;
    
    /**
     * @brief load single library which is an IEntityConstructor
     * 
     * @param const std::string
     * 
     * @return std::shared_ptr<ecs::system::IEntityConstructor>> 
     */
    std::shared_ptr<ecs::entities::IEntityConstructor> loadLibrary(const std::string &) override;
};
}

#endif //ENTITIESLOADER_HPP