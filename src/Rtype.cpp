//
// Created by romane on 25/11/2019.
//

#include "SystemManager.hpp"
#include "DisplaySystem.hpp"
#include "Factories/EntityFactory.hpp"
#include "SFMLRenderManager.hpp"
#include "MovementSystem.hpp"
#include "PlayerMovementSystem.hpp"
#include "Rtype.hpp"

Rtype::Rtype()
{
}

void Rtype::start()
{
    _sceneManager = std::make_shared<SceneManager>();
}