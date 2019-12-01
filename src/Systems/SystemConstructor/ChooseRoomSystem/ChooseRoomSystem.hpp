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
    /**
     * @brief Construct a new Choose Room System object
     * 
     * @param managerWrapper 
     * @param entityFactory 
     * @param entitiesToDelete 
     */
        ChooseRoomSystem(std::shared_ptr<IManagerWrapper> &managerWrapper, std::shared_ptr<ecs::entities::IEntityFactory> &entityFactory, std::list<int> &entitiesToDelete);
        ~ChooseRoomSystem() = default;

        /**
         * @brief update
         * 
         * @return SystemResponse 
         */
        SystemResponse update() override;

    };
}
#endif //CHOOSEROOMSYSTEM_HPP