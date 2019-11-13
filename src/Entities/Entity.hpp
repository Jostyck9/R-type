/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP__
#define ENTITY_HPP__

namespace entities
{
    /**
     * @brief Entity defined a object in the game with a simple id and his component
     * 
     */
    class Entity
    {
    private:
        size_t _id;

    public:
        Entity();
        ~Entity();

        /**
         * @brief returns the id on the entity, each entity has an unique ID
         * 
         * @return size_t 
         */
        size_t getID() const;

        bool operator==(const Entity &other) const
        {
            if (this->getID() == other.getID())
                return true;
            return false;
        }
    };
}

#endif //ENTITY_HPP__