
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Display/Sprite.hpp"
#include "Physics/Position.hpp"
#include "Display/Text.hpp"
#include "Render/Input.hpp"
#include "PacketManager.hpp"
#include "Music.hpp"

#ifndef IRENDERMANAGER_HPP__
#define IRENDERMANAGER_HPP__
/*!
 * @namespace ecs
 * @brief A namespace containing all the ecs project stuff
 */
namespace ecs {
    /*!
     * @class IRenderManager manages rendering depending on your lib
     */
    class IRenderManager {
    public:
        enum KEY_STATE{
            PRESSED,
            RELEASED,
            NONE
        };
    public:
        /*!
         * @brief dtor
         */
		virtual ~IRenderManager() = default;
        /**
         * @brief Init the SFML window
         * 
         */
        virtual void init() = 0;
        /**
         * @brief Terminate the SFML window
         * 
         */
        virtual void terminate() = 0;
        /**
         * @brief Update the sprite to his new position
         * 
         * @param sprite 
         * @param pos 
         */
        virtual void graphicsUpdate(std::shared_ptr<components::Sprite> &sprite, std::shared_ptr<components::Position> &pos) = 0;
        /**
         * @brief Update the text to his new position
         * 
         * @param Text 
         * @param pos 
         */
        virtual void textUpdate(std::shared_ptr<components::Text> &Text, std::shared_ptr<components::Position> &pos) = 0;
        /**
         * @brief Update the event
         * 
         * @return true 
         * @return false 
         */
        virtual bool eventUpdate() = 0;
        /**
         * @brief Clear the window
         * 
         */
        virtual void clear() = 0;
        /**
         * @brief Show all elements on the window
         * 
         */
        virtual void display() = 0;
        /**
         * @brief Get the Keys Map object
         * 
         * @return std::map<ecs::input::Key, KEY_STATE>& 
         */
        virtual std::map<ecs::input::Key, KEY_STATE> &getKeysMap() = 0;
        /**
         * @brief Get the Key To Packet object
         * 
         * @return ecs::network::PacketManager 
         */
        virtual ecs::network::PacketManager getKeyToPacket() = 0;
    };
}

#endif //IRENDERMANAGER_HPP
