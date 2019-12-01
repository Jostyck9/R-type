/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Actions.hpp
*/

#ifndef R_TYPE_ACTIONS_HPP
#define R_TYPE_ACTIONS_HPP

/*!
 * @namespace ecs
 * @brief A namespace containing all the rtype project stuff
 */
namespace ecs {
    /*!
     * @namespace ecs::input
     * @brief A namespace representing inputs
     */
    namespace actions {
        /*!
         * @enum Key
         * @brief A mapping of player available actions
         */
        enum Action {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            SHOOT
        };
    };
};


#endif //R_TYPE_ACTIONS_HPP
