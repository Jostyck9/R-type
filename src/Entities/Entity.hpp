/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP__
#define ENTITY_HPP__

namespace ecs::entities
{
    /**
     * @brief Entity defined a object in the game with a simple id and his component
     * 
     */
    class Entity
    {
    private:
        size_t _id;
        size_t _gameId;

    public:
        enum option : size_t {
            NOGAMEID,
            AUTOID
        };

    public:
        /**
         * @brief Construct a new Entity object
         * 
         * @param gameId can be NOGAMEID: that dosen't define a gameId
         *               can be AUTOID: that create a gameID auto
         *               or a size_t directly defined by yourself
         */
        Entity(option gameId = NOGAMEID);
        ~Entity();

        /**
         * @brief returns the id on the entity, each entity has an unique ID
         * 
         * @return size_t 
         */
        size_t getID() const;

        /**
         * @brief Get the In Game ID object
         * 
         * @return size_t 
         */
        size_t getInGameID() const;

        bool operator==(const Entity &other) const
        {
            if (this->getID() == other.getID())
                return true;
            return false;
        }
    };
}

#endif //ENTITY_HPP__