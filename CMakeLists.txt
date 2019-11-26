cmake_minimum_required(VERSION 3.0.0)
project(R-type VERSION 0.1.0)

# include(CTest)
# enable_testing()

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
else ()
    if(MSVC)
        set (CMAKE_CXX_STANDARD 17)
    else()
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
    endif()
endif ()

#compilation flags
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
endif()

# Compilation
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(${CMAKE_INCLUDE_PATH}
        src/Components/
        src/Components/ComponentManager/
        src/Components/Display/
        src/Components/GameLogic/
        src/Components/IO/
        src/Components/Physics/
        src/RessourceManager/
        src/Entities/
        src/Entities/EntityConstructor/
        src/Entities/EntityConstructor/TestEntity/
        src/Entities/EntityManager/
        src/Entities/Factories/
        src/Systems/
        src/Systems/Display
        src/Systems/SystemManager
        src/Exceptions
        src/Systems/SystemConstructor
        src/Systems/SystemConstructor/testSystem
        src/Systems/Factories
        src/Render/
        src/ManagerWrapper)

#r-type_client
set(SOURCE_CLIENT
        "src/main_client.cpp"
        "src/Components/ComponentManager/ComponentManager.cpp"
        "src/Components/Display/Animator.cpp"
        "src/Components/Display/Button.cpp"
        "src/Components/Display/Image.cpp"
        "src/Components/Display/PopUp.cpp"
        "src/Components/Display/Sprite.cpp"
        "src/Components/Display/StaticText.cpp"
        "src/Components/Display/Text.cpp"
        "src/Components/GameLogic/Damage.cpp"
        "src/Components/GameLogic/Health.cpp"
        "src/Components/GameLogic/Item.cpp"
        "src/Components/GameLogic/Level.cpp"
        "src/Components/GameLogic/Power.cpp"
        "src/Components/GameLogic/Scale.cpp"
        "src/Components/IO/Controller.cpp"
        "src/Components/IO/DummyInput.cpp"
        "src/Components/IO/GameController.cpp"
        "src/Components/IO/Input.cpp"
        "src/Components/IO/Keyboard.cpp"
        "src/Components/IO/Output.cpp"
        "src/Components/IO/Sound.cpp"
        "src/Components/Physics/Acceleration.cpp"
        "src/Components/Physics/Collision.cpp"
        "src/Components/Physics/Gravity.cpp"
        "src/Components/Physics/Motion.cpp"
        "src/Components/Physics/Rotation.cpp"
        "src/Components/Physics/Transform.cpp"
        "src/Components/Physics/Velocity.cpp"
        "src/Components/Physics/Position.cpp"
        "src/ResourceManager/ResourceManager.cpp"
        "src/ResourceManager/Music.cpp"
        "src/ResourceManager/Sound.cpp"
        "src/ResourceManager/Texture.cpp"
        "src/ResourceManager/Font.cpp"
        "src/ResourceManager/Text.cpp"
        "src/Entities/Entity.cpp"
        "src/Entities/EntityConstructor/TestEntity/TestEntity.cpp"
        "src/Entities/EntityManager/EntityManager.cpp"
        "src/Entities/Factories/EntityFactory.cpp"
        "src/Systems/ASystem.cpp"
        "src/Systems/Display/DisplaySystem.cpp"
        "src/Systems/Display/PhysicsSystem.cpp"
        "src/Systems/SystemManager/SystemManager.cpp"
        "src/Systems/SystemManager/SystemManager.cpp"
        "src/Exceptions/ComponentExceptions.cpp"
        "src/Exceptions/ECSExceptions.cpp"
        "src/Exceptions/EntityExceptions.cpp"
        "src/Exceptions/RTypeExceptions.cpp"
        "src/Exceptions/ServerExceptions.cpp"
        "src/Exceptions/SystemExceptions.cpp"
        "src/Systems/SystemConstructor/testSystem/testSystem.cpp"
        "src/Systems/Factories/SystemFactory.cpp"
        "src/Render/SFMLRenderManager.cpp"
        "src/ManagerWrapper/ManagerWrapper.cpp")

add_executable(r-type_client ${SOURCE_CLIENT})
target_link_libraries(r-type_client ${CONAN_LIBS})

#r-type_server
set(SOURCE_SERVER
        src/main_server.cpp)
add_executable(r-type_server ${SOURCE_SERVER})
target_link_libraries(r-type_server ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
