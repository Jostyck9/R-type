
#include <memory>
#include <vector>
#include <string>
#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"

/*!
 * @namespace ecs
 * @brief A namespace containing all the ecs project stuff
 */
namespace ecs {
    /*!
     * @class IRenderManager
     */
    class IRenderManager {
    public:
        /*!
         * @brief dtor
         */
		virtual ~IRenderManager() = default;
        virtual void init() = 0;
        virtual void terminate() = 0;
        virtual void graphicsUpdate() = 0;
        virtual void audioUpdate() = 0;
        virtual void textUpdate() = 0;
        virtual void eventUpdate() = 0;
    };
}