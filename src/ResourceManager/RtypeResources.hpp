//
// Created by romane on 26/11/2019.
//

#ifndef R_TYPE_RTYPERESOURCES_HPP
#define R_TYPE_RTYPERESOURCES_HPP

#include "ResourceManager.hpp"

namespace ecs
{
class RtypeResources : public ResourceManager
{
public:
    RtypeResources();
    ~RtypeResources() = default;
};
} // namespace ecs

#endif //R_TYPE_RTYPERESOURCES_HPP
