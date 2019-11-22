cmake_minimum_required(VERSION 2.8)
project(R-type_test)

set(PROJECT_ROOT "..")
set(SOURCE_ROOT "${PROJECT_ROOT}/src")

if(MSVC)
    set (CMAKE_CXX_STANDARD 17)
else()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
endif()

include_directories(
    ${SOURCE_ROOT}
    ${SOURCE_ROOT}/Entities/
    ${SOURCE_ROOT}/Entities/EntityConstructor/
    ${SOURCE_ROOT}/Entities/EntityConstructor/TestEntity/
    ${SOURCE_ROOT}/Entities/EntityManager/
    ${SOURCE_ROOT}/Components/
    ${SOURCE_ROOT}/Components/Physics/
    ${SOURCE_ROOT}/Components/ComponentManager/
    ${SOURCE_ROOT}/Exceptions/
)

add_executable(test
    ./src/testComponentManager.cpp
    ./src/testEntityManager.cpp
    ./src/testEntity.cpp
    ./src/testExceptions
    ./src/testEntityConstructor.cpp
    ${SOURCE_ROOT}/Entities/Entity.cpp
    ${SOURCE_ROOT}/Entities/EntityConstructor/TestEntity/TestEntity.cpp
    ${SOURCE_ROOT}/Entities/EntityManager/EntityManager.cpp
    ${SOURCE_ROOT}/Components/ComponentManager/ComponentManager.cpp
    ${SOURCE_ROOT}/Components/Physics/Acceleration.cpp
    ${SOURCE_ROOT}/Components/Physics/Motion.cpp
    ${SOURCE_ROOT}/Components/Physics/Velocity.cpp
    ${SOURCE_ROOT}/Components/Physics/Position.cpp
    ${SOURCE_ROOT}/Exceptions/ComponentExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ECSExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/EntityExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/RTypeExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ServerExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/SystemExceptions.cpp
)

target_link_libraries(test
    criterion
)
