# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(InvManager VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Gather all .cpp files from the src directory
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*")

# Add the executable target
add_executable(InvManager src/main.cpp)

# Include directories (if headers are in a different folder)
target_include_directories(InvManager PUBLIC "${PROJECT_SOURCE_DIR}/src")

# Specify the source and destination paths
add_custom_command(TARGET InvManager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/src/scripts/createLoginInfo.sh ${CMAKE_BINARY_DIR}/
)
add_custom_command(TARGET InvManager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/src/login.info ${CMAKE_BINARY_DIR}/
)

