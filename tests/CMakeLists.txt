cmake_minimum_required(VERSION 2.8)
project(R-type_test)

set(PROJECT_ROOT "..")
set(SOURCE_ROOT "${PROJECT_ROOT}/src")

# Compilation
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(
    ${SOURCE_ROOT}
    ${SOURCE_ROOT}/Entities/
    ${SOURCE_ROOT}/Components/
    ${SOURCE_ROOT}/Components/Physics/
    ${SOURCE_ROOT}/Components/ComponentManager/
    ${SOURCE_ROOT}/Exceptions/
    ${SOURCE_ROOT}/ResourceManager/
)

add_executable(unit_test
    ./src/testComponentManager.cpp
    ./src/testEntityManager.cpp
    ./src/testEntity.cpp
    ./src/testExceptions.cpp
    ${SOURCE_ROOT}/Entities/Entity.cpp
    ${SOURCE_ROOT}/Entities/EntityManager.cpp
    ${SOURCE_ROOT}/Components/ComponentManager/ComponentManager.cpp
    ${SOURCE_ROOT}/Components/Physics/Acceleration.cpp
    ${SOURCE_ROOT}/Components/Physics/Motion.cpp
    ${SOURCE_ROOT}/Exceptions/ComponentExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ECSExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/EntityExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/RTypeExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/ServerExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/SystemExceptions.cpp
)
target_link_libraries(unit_test criterion)

add_executable(unit_test_graphic
    ./src/testResourceManager.cpp
    ${SOURCE_ROOT}/Exceptions/ECSExceptions.cpp
    ${SOURCE_ROOT}/Exceptions/RTypeExceptions.cpp
    ${SOURCE_ROOT}/ResourceManager/Font.cpp
    ${SOURCE_ROOT}/ResourceManager/Music.cpp
    ${SOURCE_ROOT}/ResourceManager/ResourceManager.cpp
    ${SOURCE_ROOT}/ResourceManager/Sound.cpp
    ${SOURCE_ROOT}/ResourceManager/Text.cpp
    ${SOURCE_ROOT}/ResourceManager/Texture.cpp
)
target_link_libraries(unit_test_graphic criterion ${CONAN_LIBS})