cmake_minimum_required(VERSION 3.0)
project(TripleX)


set(CMAKE_CXX_STANDARD 11)

# grab all files
file(GLOB_RECURSE SRC
        "src/*.h"
        "src/*.cpp"
        )

#find REQ libs

#~~~~~~~

include_directories(.)
include_directories(src)


set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${SRC})

#link libs
