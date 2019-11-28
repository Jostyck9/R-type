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
        ./
        ../
        ../../
        src/Components/
        src/Components/ComponentManager/
        src/Components/Display/
        src/Components/Physics/
        src/RessourceManager/
        src/Entities/
        src/Entities/EntityManager/
        src/Systems/
        src/Systems/SystemConstructor/Display
        src/Systems/SystemManager
        src/Exceptions
        src/Systems/SystemConstructor
        src/Systems/Factories
        src/Render/
        src/ManagerWrapper
        src/DlLoader
)

#Display librairy
add_library(DisplaySystem SHARED
        "src/Components/ComponentManager/ComponentManager.cpp"
        "src/Components/Display/Animator.cpp"
        "src/Components/Display/Button.cpp"
        "src/Components/Display/Image.cpp"
        "src/Components/Display/PopUp.cpp"
        "src/Components/Display/Sprite.cpp"
        "src/Components/Display/StaticText.cpp"
        "src/Components/Display/Text.cpp"
        "src/Components/Physics/Collision.cpp"
        "src/Components/Physics/Position.cpp"
        "src/Entities/Entity.cpp"
        "src/Entities/EntityManager/EntityManager.cpp"
        "src/Exceptions/ComponentExceptions.cpp"
        "src/Exceptions/ECSExceptions.cpp"
        "src/Exceptions/RTypeExceptions.cpp"
        "src/Exceptions/SystemExceptions.cpp"
        "src/Systems/ASystem.cpp"
        "src/Systems/SystemConstructor/Display/DisplaySystem.cpp"
        "src/Systems/SystemManager/SystemManager.cpp"
        "src/Systems/Factories/SystemFactory.cpp"
        "src/Render/SFMLRenderManager.cpp"
        "src/ManagerWrapper/ManagerWrapper.cpp"
)
target_link_libraries(DisplaySystem ${CONAN_LIBS})

#Display librairy
# add_executable(DisplaySystem
#         "../../../main_client.cpp"
#         "../../../Components/ComponentManager/ComponentManager.cpp"
#         "../../../Components/Display/Animator.cpp"
#         "../../../Components/Display/Button.cpp"
#         "../../../Components/Display/Image.cpp"
#         "../../../Components/Display/PopUp.cpp"
#         "../../../Components/Display/Sprite.cpp"
#         "../../../Components/Display/StaticText.cpp"
#         "../../../Components/Display/Text.cpp"
#         "../../../Components/Physics/Collision.cpp"
#         "../../../Components/Physics/Position.cpp"
#         "../../../Entities/Entity.cpp"
#         "../../../Entities/EntityManager/EntityManager.cpp"
#         "../../../Exceptions/ComponentExceptions.cpp"
#         "../../../Exceptions/ECSExceptions.cpp"
#         "../../../Exceptions/RTypeExceptions.cpp"
#         "../../../Exceptions/SystemExceptions.cpp"
#         "../../ASystem.cpp"
#         "./DisplaySystem.cpp"
#         "../../SystemManager/SystemManager.cpp"
#         "../../Factories/SystemFactory.cpp"
#         "../../../Render/SFMLRenderManager.cpp"
#         "../../../ManagerWrapper/ManagerWrapper.cpp"
# )
# target_link_libraries(DisplaySystem ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})