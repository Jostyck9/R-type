/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ChooseRoomSystem.hpp
*/

#ifndef CHOOSEROOMSYSTEM_HPP
#define CHOOSEROOMSYSTEM_HPP

#include "ASystem.hpp"
#include "IEntityManager.hpp"
#include "IComponentManager.hpp"

namespace ecs::system 
{
    class ChooseRoomSystem : public ASystem
    {
    private:
    public:
        ChooseRoomSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~ChooseRoomSystem() = default;

        SystemResponse update() override;

    };
}
#endif //CHOOSEROOMSYSTEM_HPP