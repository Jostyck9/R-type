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
        src/Components/Physics/
        src/Entities/
        src/Entities/EntityConstructor/
        src/Entities/EntityConstructor/TestEntity/
        src/Entities/EntityManager/
        src/Entities/Factories/
        src/Systems/
        src/Systems/SystemManager
        src/Exceptions
        src/Render/
        src/ManagerWrapper)

add_library(TestEntity SHARED 
        "src/Components/ComponentManager/ComponentManager.cpp"
        "src/Components/Physics/Acceleration.cpp"
        "src/Components/Physics/Collision.cpp"
        "src/Components/Physics/Gravity.cpp"
        "src/Components/Physics/Motion.cpp"
        "src/Components/Physics/Rotation.cpp"
        "src/Components/Physics/Transform.cpp"
        "src/Components/Physics/Velocity.cpp"
        "src/Components/Physics/Position.cpp"
        "src/Entities/Entity.cpp"
        "src/Entities/EntityConstructor/TestEntity/TestEntity.cpp"
        "src/Entities/Factories/EntityFactory.cpp"
        "src/Exceptions/ComponentExceptions.cpp"
        "src/Exceptions/ECSExceptions.cpp"
        "src/Exceptions/EntityExceptions.cpp"
        "src/Exceptions/RTypeExceptions.cpp"
        "src/Exceptions/SystemExceptions.cpp"
        "src/Systems/SystemManager/SystemManager.cpp"
        "src/Render/SFMLRenderManager.cpp"
        "src/ManagerWrapper/ManagerWrapper.cpp"
)

# include_directories(${CMAKE_INCLUDE_PATH}
#         ../../../Components/
#         ../../../Components/ComponentManager/
#         ../../../Components/Physics/
#         ../
#         ./
#         ../../
#         ../../EntityManager/
#         ../../Factories/
#         ../../../Systems/
#         ../../../Systems/SystemManager
#         ../../../Exceptions
#         ../../../Render/
#         ../../../ManagerWrapper)

# add_library(TestEntity SHARED 
#         "../../../Components/ComponentManager/ComponentManager.cpp"
#         "../../../Components/Physics/Acceleration.cpp"
#         "../../../Components/Physics/Collision.cpp"
#         "../../../Components/Physics/Gravity.cpp"
#         "../../../Components/Physics/Motion.cpp"
#         "../../../Components/Physics/Rotation.cpp"
#         "../../../Components/Physics/Transform.cpp"
#         "../../../Components/Physics/Velocity.cpp"
#         "../../../Components/Physics/Position.cpp"
#         "../../Entity.cpp"
#         "./TestEntity.cpp"
#         "../../Factories/EntityFactory.cpp"
#         "../../../Exceptions/ComponentExceptions.cpp"
#         "../../../Exceptions/ECSExceptions.cpp"
#         "../../../Exceptions/EntityExceptions.cpp"
#         "../../../Exceptions/RTypeExceptions.cpp"
#         "../../../Exceptions/SystemExceptions.cpp"
#         "../../../Systems/SystemManager/SystemManager.cpp"
#         "../../../Render/SFMLRenderManager.cpp"
#         "../../../ManagerWrapper/ManagerWrapper.cpp"
# )
# target_link_libraries(TestEntity ${CONAN_LIBS})

target_link_libraries(TestEntity ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})