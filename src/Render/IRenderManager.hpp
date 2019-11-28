
#include <memory>
#include <vector>
#include <string>
#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Display/Sprite.hpp"
#include "Physics/Position.hpp"

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
        /*!
         * @brief dtor
         */
		virtual ~IRenderManager() = default;
        virtual void init() = 0;
        virtual void terminate() = 0;
        virtual void graphicsUpdate(std::shared_ptr<components::Sprite> &sprite, std::shared_ptr<components::Position> &pos) = 0;
        virtual void audioUpdate() = 0;
        virtual void textUpdate() = 0;
        virtual bool eventUpdate() = 0;
    };
}

#endif //IRENDERMANAGER_HPP
