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
include_directories(${CMAKE_INCLUDE_PATH} src/Components/ComponentManager/ src/Components/)

#r-type_client

add_executable(r-type_client src/main_client.cpp src/Components/ComponentManager/ComponentManager.cpp)
target_link_libraries(r-type_client ${CONAN_LIBS})

#r-type_server

    # Server Sources files
file(GLOB_RECURSE SRV_SRCS src/Components/*.cpp src/Components/*.hpp src/Thread/*.cpp src/Thread/*.hpp)

add_executable(r-type_server src/main_server.cpp ${SRV_SRCS})
target_link_libraries(r-type_server ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)