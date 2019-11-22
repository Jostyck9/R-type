
#include <memory>
#include <vector>
#include <string>
#include "../Components/IComponent.hpp"
#include "../Components/ComponentManager/ComponentManager.hpp"
#include "../Entities/EntityManager.hpp"

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
        virtual void ~IDisplayModule() = 0;
        virtual void init() = 0;
        virtual void terminate() = 0;
        virtual void graphicsUpdate() = 0;
        virtual void audioUpdate() = 0;
        virtual void textUpdate() = 0;
        virtual void eventUpdate() = 0;
    };
}

#endif //OOP_rtype_2019