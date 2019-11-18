cmake_minimum_required(VERSION 3.0.0)
project(R-type VERSION 0.1.0)

# include(CTest)
# enable_testing()

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
else ()
    set (CMAKE_CXX_STANDARD 11)
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
        src/Components/ComponentManager/ 
        src/Components/ 
        src/Entities/
        src/Systems/
        src/Systems/Display)

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
        "src/Components/IO/KeyBoard.cpp"
        "src/Components/IO/Output.cpp"
        "src/Components/IO/Sound.cpp"
        "src/Components/Physics/Acceleration.cpp"
        "src/Components/Physics/Collision.cpp"
        "src/Components/Physics/Gravity.cpp"
        "src/Components/Physics/Motion.cpp"
        "src/Components/Physics/Rotation.cpp"
        "src/Components/Physics/Transform.cpp"
        "src/Components/Physics/Velocity.cpp"
        "src/Entities/Entity.cpp"
        "src/Entities/EntityManager.cpp"
        "src/Systems/ASystem.cpp"
        "src/Systems/Display/DisplaySystem.cpp")

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