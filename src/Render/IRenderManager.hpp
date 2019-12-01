
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Sprite.hpp"
#include "Position.hpp"
#include "Text.hpp"
#include "Input.hpp"

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
        virtual void init() = 0;
        virtual void terminate() = 0;
        virtual void graphicsUpdate(std::shared_ptr<components::Sprite> &sprite, std::shared_ptr<components::Position> &pos) = 0;
        virtual void audioUpdate() = 0;
        virtual void textUpdate(std::shared_ptr<components::Text> &Text, std::shared_ptr<components::Position> &pos) = 0;
        virtual bool eventUpdate() = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
        virtual std::map<ecs::input::Key, KEY_STATE> &getKeysMap() = 0;
    };
}

#endif //IRENDERMANAGER_HPP
