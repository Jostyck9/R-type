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
include(../../../../build/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(${CMAKE_INCLUDE_PATH}
        ./
        ../
        ../../
        ../../../Components/ComponentManager/
        ../../../Components/
        ../../../Components/Display/
        ../../../Components/GameLogic/
        ../../../Components/IO/
        ../../../Components/Physics/
        ../../../RessourceManager/
        ../../../Entities/
        ../../../Entities/EntityConstructor/
        ../../../Entities/EntityConstructor/TestEntity/
        ../../../Entities/EntityConstructor/TestEntity2/
        ../../../Entities/EntityManager/
        ../../../Entities/Factories/
        ../../../Exceptions
        ../../../Render/
        ../../../ManagerWrapper
        ../../../DlLoader
        ../../Factories
        ../../SystemManager
        ../Display
        ../testSystem
)

#Display librairy
add_library(testSystem SHARED
        "../../../Components/ComponentManager/ComponentManager.cpp"
        "../../../Components/Display/Animator.cpp"
        "../../../Components/Display/Button.cpp"
        "../../../Components/Display/Image.cpp"
        "../../../Components/Display/PopUp.cpp"
        "../../../Components/Display/Sprite.cpp"
        "../../../Components/Display/StaticText.cpp"
        "../../../Components/Display/Text.cpp"
        "../../../Components/GameLogic/Damage.cpp"
        "../../../Components/GameLogic/Health.cpp"
        "../../../Components/GameLogic/Item.cpp"
        "../../../Components/GameLogic/Level.cpp"
        "../../../Components/GameLogic/Power.cpp"
        "../../../Components/GameLogic/Scale.cpp"
        "../../../Components/IO/Controller.cpp"
        "../../../Components/IO/DummyInput.cpp"
        "../../../Components/IO/GameController.cpp"
        "../../../Components/IO/Input.cpp"
        "../../../Components/IO/Keyboard.cpp"
        "../../../Components/IO/Output.cpp"
        "../../../Components/IO/Sound.cpp"
        "../../../Components/Physics/Acceleration.cpp"
        "../../../Components/Physics/Collision.cpp"
        "../../../Components/Physics/Gravity.cpp"
        "../../../Components/Physics/Motion.cpp"
        "../../../Components/Physics/Rotation.cpp"
        "../../../Components/Physics/Transform.cpp"
        "../../../Components/Physics/Velocity.cpp"
        "../../../Components/Physics/Position.cpp"
        "../../../ResourceManager/ResourceManager.cpp"
        "../../../ResourceManager/Music.cpp"
        "../../../ResourceManager/Sound.cpp"
        "../../../ResourceManager/Texture.cpp"
        "../../../ResourceManager/Font.cpp"
        "../../../ResourceManager/Text.cpp"
        "../../../Entities/Entity.cpp"
        "../../../Entities/EntityConstructor/TestEntity/TestEntity.cpp"
        "../../../Entities/EntityConstructor/TestEntity2/TestEntity2.cpp"
        "../../../Entities/EntityManager/EntityManager.cpp"
        "../../../Entities/Factories/EntityFactory.cpp"
        "../../../Exceptions/ComponentExceptions.cpp"
        "../../../Exceptions/ECSExceptions.cpp"
        "../../../Exceptions/EntityExceptions.cpp"
        "../../../Exceptions/RTypeExceptions.cpp"
        "../../../Exceptions/ServerExceptions.cpp"
        "../../../Exceptions/SystemExceptions.cpp"
        "../../ASystem.cpp"
        "../../SystemManager/SystemManager.cpp"
        "../../SystemManager/SystemManager.cpp"
        "../../Factories/SystemFactory.cpp"
        "../MovementSystem/MovementSystem.cpp"
        "../Display/DisplaySystem.cpp"
        "../testSystem/testSystem.cpp"
        "../../../Render/SFMLRenderManager.cpp"
        "../../../ManagerWrapper/ManagerWrapper.cpp"
)
target_link_libraries(testSystem ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
