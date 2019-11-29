/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemResponse.hpp
*/

#ifndef SYSTEMRESPONSE_HPP__
#define SYSTEMRESPONSE_HPP__

#include <string>

namespace ecs::system
{
    class SystemResponse
    {
    public:
        enum CMD {
            NOACTION,
            QUIT,
            LOADSCENE
        };
    private:
        CMD _action;
        std::string _parameters;

    public:
        SystemResponse(CMD action = CMD::NOACTION, std::string parameters = "");
        ~SystemResponse();

        /**
         * @brief Get the Action object
         * 
         * @return const CMD& 
         */
        const CMD &getAction() const;

        /**
         * @brief Get the Parameters object
         * 
         * @return const std::string& 
         */
        const std::string &getParameters() const;

        /**
         * @brief Set the Action object
         * 
         * @param action 
         */
        void setAction(const CMD &action);

        /**
         * @brief Set the Parameters object
         * 
         * @param parameters 
         */
        void setParameters(const std::string &parameters);
    };
} // namespace ecs::system


#endif //SYSTEMRESPONSE_HPP__