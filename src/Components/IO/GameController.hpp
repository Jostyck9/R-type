/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** GameController.hpp
*/

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <typeindex>
#include <map>

namespace ecs::components
{
    /**
     * @brief GameController describes the GameController of the Controller of an Component
     * 
     */
    class GameController
    {
    private:
        unsigned int _id;
//        std::map<> _keyMap;
    public:
        GameController();
        GameController(const GameController &oldGameController);
        ~GameController();

        /**
         * @brief Set the Id object
         * 
         * @param int 
         */
        void setId(const unsigned int &);

        /**
         * @brief Get the Id object
         * 
         * @return const unsigned int 
         */
        unsigned int getId() const;
        /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;

        bool operator==(GameController const& other) const;
    };
}

#endif