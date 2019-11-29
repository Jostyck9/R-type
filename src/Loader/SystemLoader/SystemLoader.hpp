/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemLoader.hpp
*/

#ifndef SYSTEMLOADER_HPP
#define SYSTEMLOADER_HPP

#include "ILoader.hpp"
#include <memory>
#include <vector>
#include "ISystemConstructor.hpp"

namespace ecs
{
class SystemLoader : public ILoader<ecs::system::ISystemConstructor>
{
private:
public:
    SystemLoader(/* args */);
    ~SystemLoader();

    /**
     * @brief load all libraries which are ISystemConstructor
     * 
     * @return std::vector<std::shared_ptr<ecs::system::ISystemConstructor>> 
     */
    std::vector<std::shared_ptr<ecs::system::ISystemConstructor>> loadAllLibrary() override;

    /**
     * @brief load single library which is an ISystemConstructor
     * 
     * @param const std::string
     * 
     * @return std::shared_ptr<ecs::system::ISystemConstructor>> 
     */
    std::shared_ptr<ecs::system::ISystemConstructor> loadLibrary(const std::string &) override;
};
} // namespace ecs

#endif //SYSTEMLOADER_HPP