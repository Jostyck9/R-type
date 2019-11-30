cmake_minimum_required(VERSION 3.1.0)
project(R-type VERSION 0.1.0)

# include(CTest)
# enable_testing()

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
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

include(${CMAKE_CURRENT_SOURCE_DIR}/src/Entities/EntityConstructor/TestEntity/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/Entities/EntityConstructor/TestEntity2/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/SystemConstructor/MovementSystem/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/SystemConstructor/Display/CMakeLists.txt)

#Link shared libraries
set_property(TARGET TestEntity PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/libTestEntity.so)
set_target_properties(TestEntity PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/entities)
#set_property(TARGET testEntity1 PROPERTY IMPORTED_IMPLIB c:/path/to/bar.lib)

set_property(TARGET TestEntity2 PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/libTestEntity2.so)
set_target_properties(TestEntity2 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/entities)
#set_property(TARGET testEntity2 PROPERTY IMPORTED_IMPLIB c:/path/to/bar.lib)

set_property(TARGET MovementSystem PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/libMovementSystem.so)
set_target_properties(MovementSystem PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/systems)
#set_property(TARGET Movement PROPERTY IMPORTED_IMPLIB c:/path/to/bar.lib)

set_property(TARGET DisplaySystem PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/libDisplaySystem.so)
set_target_properties(DisplaySystem PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/systems)
#set_property(TARGET Display PROPERTY IMPORTED_IMPLIB c:/path/to/bar.lib)


include_directories(${CMAKE_INCLUDE_PATH}
        src/Loader/
        src/Loader/EntitiesLoader/
        src/Loader/SystemLoader/
        src/Components/
        src/Components/ComponentManager/
        src/Components/Display/
        src/Components/GameLogic/
        src/Components/IO/
        src/Components/Physics/
        src/ResourceManager/
        src/Entities/
        src/Entities/EntityConstructor/
        src/Entities/EntityConstructor/TestEntity/
        src/Entities/EntityConstructor/TestEntity2/
        src/Entities/EntityConstructor/PlayerEntity/
        src/Entities/EntityConstructor/PlayEntity/
        src/Entities/EntityConstructor/StopEntity/
        src/Entities/EntityConstructor/EnnemyEntity/
        src/Entities/EntityConstructor/EnnemyType01Entity/
        src/Entities/EntityConstructor/BulletEntity/
        src/Entities/EntityConstructor/BackgroundMenuEntity/
        src/Entities/EntityConstructor/GameBackgroundEntity/
        src/Entities/EntityConstructor/TestBackground/
        src/Entities/EntityConstructor/NameRoomEntity/
        src/Entities/EntityConstructor/NumberPlayersEntity/
        src/Entities/EntityConstructor/BackgroundWithoutTitleEntity/
        src/Entities/EntityConstructor/BackEntity/
        src/Entities/EntityManager/
        src/Entities/Factories/
        src/Entities/Serializer/
        src/Systems/
        src/Systems/SystemManager
        src/Exceptions
        src/Network/Session
        src/Systems/SystemConstructor
        src/Systems/SystemConstructor/MovementSystem
        src/Systems/SystemConstructor/MenuSystem
        src/Systems/SystemConstructor/ButtonColorSystem
        src/Systems/SystemConstructor/PlayerMovementSystem
        src/Systems/SystemConstructor/EnnemiesMovementSystem
        src/Systems/SystemConstructor/testSystem
        src/Systems/SystemConstructor/AnimationSystem
        src/Systems/SystemConstructor/ChooseRoomSystem
        src/Systems/Factories
        src/Systems/SystemResponse/
        src/Render/
        src/ManagerWrapper
        src/Network/
        src/Network/Client
        src/Network/Server
        src/Network/Session
        src/Exceptions
        src/Utils/
        src/FactoriesWrapper/
        src/Scenes/
        src/)

#r-type_client
set(SOURCE_CLIENT
        "src/main_client.cpp"
        "src/Ecs.cpp"
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
        "src/Components/GameLogic/Timer.cpp"
        "src/Components/GameLogic/PlayerController.cpp"
        "src/Components/GameLogic/EnnemiesController.cpp"
        "src/Components/IO/GameController.cpp"
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
        "src/ResourceManager/RtypeResources.cpp"
        "src/Entities/Entity.cpp"
        "src/Entities/EntityConstructor/PlayerEntity/PlayerEntity.cpp"
        "src/Entities/EntityConstructor/PlayEntity/PlayEntity.cpp"
        "src/Entities/EntityConstructor/StopEntity/StopEntity.cpp"
        "src/Entities/EntityConstructor/BulletEntity/BulletEntity.cpp"
        "src/Entities/EntityConstructor/EnnemyEntity/EnnemyEntity.cpp"
        "src/Entities/EntityConstructor/EnnemyType01Entity/EnnemyType01Entity.cpp"
        "src/Entities/EntityConstructor/BackgroundMenuEntity/BackgroundMenuEntity.cpp"
        "src/Entities/EntityConstructor/TestBackground/TestBackground.cpp"
        "src/Entities/EntityConstructor/GameBackgroundEntity/GameBackgroundEntity.cpp"
        "src/Entities/EntityConstructor/NameRoomEntity/NameRoomEntity.cpp"
        "src/Entities/EntityConstructor/NumberPlayersEntity/NumberPlayersEntity.cpp"
        "src/Entities/EntityConstructor/BackgroundWithoutTitleEntity/BackgroundWithoutTitleEntity.cpp"
        "src/Entities/EntityConstructor/BackEntity/BackEntity.cpp"
        "src/Entities/EntityManager/EntityManager.cpp"
        "src/Entities/Factories/EntityFactory.cpp"
        "src/Entities/Serializer/Serializer.cpp"
        "src/Systems/ASystem.cpp"
        "src/Systems/SystemManager/SystemManager.cpp"
        "src/Systems/SystemConstructor/MenuSystem/MenuSystem.cpp"
        "src/Systems/SystemConstructor/ButtonColorSystem/ButtonColorSystem.cpp"
        "src/Systems/SystemManager/SystemManager.cpp"
        "src/Exceptions/ComponentExceptions.cpp"
        "src/Exceptions/ECSExceptions.cpp"
        "src/Exceptions/EntityExceptions.cpp"
        "src/Exceptions/RTypeExceptions.cpp"
        "src/Exceptions/ServerExceptions.cpp"
        "src/Exceptions/SystemExceptions.cpp"
        "src/Systems/Factories/SystemFactory.cpp"
        "src/Loader/SystemLoader/SystemLoader.cpp"
        "src/Loader/EntitiesLoader/EntitiesLoader.cpp"
        "src/Systems/SystemResponse/SystemResponse.cpp"
        "src/Systems/SystemConstructor/PlayerMovementSystem/PlayerMovementSystem.cpp"
        "src/Systems/SystemConstructor/EnnemiesMovementSystem/EnnemiesMovementSystem.cpp"
        "src/Systems/SystemConstructor/AnimationSystem/AnimationSystem.cpp"
        "src/Systems/SystemConstructor/ChooseRoomSystem/ChooseRoomSystem.cpp"
        "src/Render/SFMLRenderManager.cpp"
        "src/ManagerWrapper/ManagerWrapper.cpp"
        "src/Network/PacketManager.cpp"
        "src/Scenes/SceneManager.cpp"
        "src/Scenes/MenuScene.cpp"
        "src/Scenes/GameScene.cpp"
        "src/Scenes/ChooseRoomScene.cpp"
        "src/Rtype.cpp"
        "src/Utils/Rect.cpp"
        "src/FactoriesWrapper/FactoriesWrapper.cpp"
        "src/Systems/SystemResponse/SystemResponse.cpp"
        "src/Network/Client/UDPClient.cpp"
        "src/Network/PacketManager.cpp"
        "src/Network/AUDPNetwork.cpp"
        "src/Network/Session/ClientSession.cpp"
        )
add_executable(r-type_client ${SOURCE_CLIENT})
target_link_libraries(r-type_client ${CONAN_LIBS} TestEntity TestEntity2 DisplaySystem MovementSystem ${CMAKE_DL_LIBS} "stdc++fs")

#r-type_server
set(SOURCE_SERVER

        "src/main_server.cpp"
        "src/Room/RoomManager.cpp"
        "src/Room/Room.cpp"
        "src/Network/PacketManager.cpp"
        "src/Network/AUDPNetwork.cpp"
        "src/Network/Server/UDPServer.cpp"
        "src/Network/Session/ServerSession.cpp"
        "src/Exceptions/RTypeExceptions.cpp"
        "src/Exceptions/ServerExceptions.cpp"
        )
add_executable(r-type_server ${SOURCE_SERVER})

target_link_libraries(r-type_server ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)