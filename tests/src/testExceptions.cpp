/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testExceptions.cpp
*/

#include <criterion/criterion.h>
#include "ServerExceptions.hpp"
#include "ComponentExceptions.hpp"
#include "SystemExceptions.hpp"
#include "EntityExceptions.hpp"

Test(Exceptions, System_Exceptions)
{
    SystemExceptions test("System not found", "Here");
    
    cr_assert_str_eq(test.what(), "System not found");
}

Test(Exceptions, Server_Exceptions)
{
    ServerExceptions test("Server not found", "Here");
    
    cr_assert_str_eq(test.what(), "Server not found");
}

Test(EntityExceptions, Entity_Exceptions)
{
    EntityExceptions test("Entity not found", "Here");
    
    cr_assert_str_eq(test.what(), "Entity not found");
}

Test(ComponentExceptions, Component_Exceptions)
{
    ComponentExceptions test("Component not found", "Here");
    
    cr_assert_str_eq(test.what(), "Component not found");
}

Test(ECSExceptions, ECS_Exceptions)
{
    ECSExceptions test("ECS not found", "Here");
    
    cr_assert_str_eq(test.what(), "ECS not found");
}