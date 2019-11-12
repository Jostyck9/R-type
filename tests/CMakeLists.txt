cmake_minimum_required(VERSION 2.8)

set(PROJECT_ROOT "..")
set(SOURCE_ROOT "${PROJECT_ROOT}/src")

include_directories(
    ${SOURCE_ROOT}/Components/
    ${SOURCE_ROOT}/Components/Physics/
    ${SOURCE_ROOT}/Components/ComponentManager/
)

add_executable(test
    src/test.cpp
    ${SOURCE_ROOT}/Components/ComponentManager/ComponentManager.cpp
    ${SOURCE_ROOT}/Components/Physics/Acceleration.cpp
    ${SOURCE_ROOT}/Components/Physics/Motion.cpp
)

target_link_libraries(test
    criterion
)