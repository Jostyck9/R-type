//
// Created by romane on 19/11/2019.
//

#include "RessourceManager.hpp"

RessourceManager &RessourceManager::getInstance()
{
    static RessourceManager ressourceManager;
    return ressourceManager;
}

RessourceManager::RessourceManager()
{

}

RessourceManager::~RessourceManager()
{

}