cmake_minimum_required(VERSION 2.8)
project(R-type_test)

set(PROJECT_ROOT "..")
set(SOURCE_ROOT "${PROJECT_ROOT}/src")

if(MSVC)
    set (CMAKE_CXX_STANDARD 17)
else()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
endif()

# Compilation
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(
    ${SOURCE_ROOT}
    ${SOURCE_ROOT}/Entities/
    ${SOURCE_ROOT}/Entities/Serializer/
    ${SOURCE_ROOT}/Entities/EntityConstructor/
    ${SOURCE_ROOT}/Entities/Factories/
    ${SOURCE_ROOT}/Entities/EntityConstructor/TestEntity/
    ${SOURCE_ROOT}/Entities/EntityManager/
    ${SOURCE_ROOT}/Components/
    ${SOURCE_ROOT}/Components/Physics/
    ${SOURCE_ROOT}/Components/Display/
    ${SOURCE_ROOT}/Components/GameLogic/
    ${SOURCE_ROOT}/Components/ComponentManager/
    ${SOURCE_ROOT}/Exceptions/
    ${SOURCE_ROOT}/ResourceManager/
    ${SOURCE_ROOT}/ManagerWrapper/
    ${SOURCE_ROOT}/Systems/
    ${SOURCE_ROOT}/Systems/Display/
    ${SOURCE_ROOT}/Systems/Factories/
    ${SOURCE_ROOT}/Systems/SystemConstructor/
    ${SOURCE_ROOT}/Systems/SystemConstructor/testSystem/
    ${SOURCE_ROOT}/Systems/SystemManager/
    ${SOURCE_ROOT}/Render/
    ${SOURCE_ROOT}/Network/
    ${SOURCE_ROOT}/Utils/
)

add_executable(unit_test
    ./src/testComponentManager.cpp
    ./src/testEntityManager.cpp
    ./src/testEntity.cpp
    ./src/testExceptions
    ./src/testEntityConstructor.cpp
    ./src/testSerialization.cpp
    ./src/testDeserialization.cpp
    ./src/testPacketManager.cpp
    ./src/testTimer.cpp
    ${SOURCE_ROOT}/Entities/Entity.cpp
    ${SOURCE_ROOT}/Entities/EntityConstructor/TestEntity/TestEntity.cpp
    ${SOURCE_ROOT}/Entities/EntityManager/EntityManager.cpp
    ${SOURCE_ROOT}/Entities/Factories/EntityFactory.cpp
    ${SOURCE_ROOT}/Entities/Serializer/Serializer.cpp
    ${SOURCE_ROOT}/Components/ComponentManager/ComponentManager.cpp
    ${SOURCE_ROOT}/Components/Physics/Acceleration.cpp
    ${SOURCE_ROOT}/Components/Physics/Motion.cpp
    ${SOURCE_ROOT}/Components/Physics/Velocity.cpp
    ${SOURCE_ROOT}/Components/Physics/Position.cpp
    ${SOURCE_ROOT}/Components/Physics/Collision.cpp
    ${SOURCE_ROOT}/Components/Physics/Rotation.cpp
    ${SOURCE_ROOT}/Components/Display/Image.cpp
    ${SOURCE_ROOT}/Components/Display/Sprite.cpp
    ${SOURCE_ROOT}/Components/Display/Text.cpp
    ${SOURCE_ROOT}/Components/GameLogic/Timer.cpp
    ${SOURCE_ROOT}/Exceptions/ComponentExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ECSExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/EntityExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/RTypeExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ServerExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/SystemExceptions.cpp
    ${SOURCE_ROOT}/Network/PacketManager.cpp
    ${SOURCE_ROOT}/Systems/ASystem.cpp
    ${SOURCE_ROOT}/Systems/SystemManager/SystemManager.cpp
    ${SOURCE_ROOT}/Systems/Factories/SystemFactory.cpp
    ${SOURCE_ROOT}/Systems/Display/DisplaySystem.cpp
    ${SOURCE_ROOT}/Systems/SystemConstructor/testSystem/testSystem.cpp
    ${SOURCE_ROOT}/ManagerWrapper/ManagerWrapper.cpp
    ${SOURCE_ROOT}/Render/SFMLRenderManager.cpp
    ${SOURCE_ROOT}/Utils/Rect.cpp
    ${SOURCE_ROOT}/ResourceManager/RtypeResources.cpp
    ${SOURCE_ROOT}/ResourceManager/ResourceManager.cpp
    ${SOURCE_ROOT}/ResourceManager/Font.cpp
    ${SOURCE_ROOT}/ResourceManager/Music.cpp
    ${SOURCE_ROOT}/ResourceManager/Sound.cpp
    ${SOURCE_ROOT}/ResourceManager/Texture.cpp
)
target_link_libraries(unit_test criterion ${CONAN_LIBS})

add_executable(unit_test_graphic
    ./src/testResourceManager.cpp
    ./src/testSystemConstructor.cpp
    ${SOURCE_ROOT}/Exceptions/ECSExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/RTypeExceptions.cpp
    ${SOURCE_ROOT}/ResourceManager/Font.cpp
    ${SOURCE_ROOT}/ResourceManager/Music.cpp
    ${SOURCE_ROOT}/ResourceManager/ResourceManager.cpp
    ${SOURCE_ROOT}/ResourceManager/RtypeResources.cpp
    ${SOURCE_ROOT}/ResourceManager/Sound.cpp
    ${SOURCE_ROOT}/ResourceManager/Texture.cpp
    ${SOURCE_ROOT}/Exceptions/ComponentExceptions.cpp
    ${SOURCE_ROOT}/Components/ComponentManager/ComponentManager.cpp
    ${SOURCE_ROOT}/Entities/EntityManager/EntityManager.cpp
    ${SOURCE_ROOT}/Entities/Entity.cpp
    ${SOURCE_ROOT}/Render/SFMLRenderManager.cpp
    ${SOURCE_ROOT}/ManagerWrapper/ManagerWrapper.cpp
    ${SOURCE_ROOT}/Systems/ASystem.cpp
    ${SOURCE_ROOT}/Systems/SystemManager/SystemManager.cpp
    ${SOURCE_ROOT}/Systems/Factories/SystemFactory.cpp
    ${SOURCE_ROOT}/Systems/Display/DisplaySystem.cpp
    ${SOURCE_ROOT}/Systems/SystemConstructor/testSystem/testSystem.cpp
    ${SOURCE_ROOT}/Exceptions/ComponentExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ECSExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/EntityExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/RTypeExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ServerExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/SystemExceptions.cpp
    ${SOURCE_ROOT}/Components/Physics/Acceleration.cpp
    ${SOURCE_ROOT}/Components/Physics/Motion.cpp
    ${SOURCE_ROOT}/Components/Physics/Velocity.cpp
    ${SOURCE_ROOT}/Components/Physics/Position.cpp
    ${SOURCE_ROOT}/Components/Physics/Collision.cpp
    ${SOURCE_ROOT}/Components/Physics/Rotation.cpp
    ${SOURCE_ROOT}/Components/Display/Image.cpp
    ${SOURCE_ROOT}/Components/Display/Sprite.cpp
    ${SOURCE_ROOT}/Components/Display/Text.cpp
    ${SOURCE_ROOT}/Utils/Rect.cpp
)
target_link_libraries(unit_test_graphic criterion ${CONAN_LIBS})