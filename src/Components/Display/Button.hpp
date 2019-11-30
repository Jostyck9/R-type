/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Button.hpp
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <typeindex>
#include "IUserInterface.hpp"
#include "SystemResponse.hpp"

namespace ecs::components
{
    /**
     * @brief Button describes an attribute that is button. 
     *
     */
    class Button : public IUserInterface

    {
    public:
        Button(bool isSelected = false, ecs::system::SystemResponse::CMD cmd = ecs::system::SystemResponse::CMD::NOACTION, const std::string &parameter = "");
        Button(const Button &oldButton);
        ~Button() = default;

        /**
         * @brief Set the isSelected object
         *
         * @param newState
         */
        void setIsSelected(bool newState);
        /**
        * @brief Get the isSelected object
        *
        * @return bool
        */
        bool getIsSelected() const;
        /**
         * @brief Set the cmd object
         *
         * @param newCmd
         */
        void setCmd(const ecs::system::SystemResponse::CMD &newCmd);
        /**
        * @brief Get the cmd object
        *
        * @return ecs::system::SystemResponse::CMD
        */
        const ecs::system::SystemResponse::CMD &getCmd() const;
        /**
         * @brief Set the parameter object
         *
         * @param newParameter
         */
        void setParameter(const std::string &newParameter);
        /**
        * @brief Get the parameter object
        *
        * @return std::string
        */
        const std::string &getParameter() const;
         /**
         * @brief Get the Type object
         * 
         * @return const std::type_index 
         */
        const std::type_index getType() const;
        bool operator==(Button &other);

    private:
        bool _isSelected;
        ecs::system::SystemResponse::CMD _cmd;
        std::string _parameter;
    };
}

#endif //BUTTON_HPP