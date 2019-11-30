/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** EnnemiesController.hpp
*/

#ifndef ENNEMIESCONTROLLER_HPP
#define ENNEMIESCONTROLLER_HPP

#include <typeindex>
#include <string>
#include "IGameLogic.hpp"

namespace ecs::components
{
    /**
     * @brief EnnemiesController is used to recognize player entity
     *
     */
    class EnnemiesController : public IGameLogic
    {
    public:
        EnnemiesController();
        EnnemiesController(const std::string &type);
        EnnemiesController(const EnnemiesController &oldEnnemiesController);
        ~EnnemiesController() = default;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const override;
        std::string getShipType(void) const;
        void setShipType(const std::string &type);
        bool operator==(EnnemiesController &other);
    private:
        std::string _shipType;
        //futur enum pour les patterns ?
    };
}

#endif //ENNEMIESCONTROLLER_HPP