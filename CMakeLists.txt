cmake_minimum_required(VERSION 3.21)

# Project name
set(PROJECT_NAME SFML)
project(${PROJECT_NAME} LANGUAGES CXX)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Adding code and linking lbiraries
set(SOURCES
	src/main.cpp)
include_directories(include)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Not sure what this does
install(TARGETS ${PROJECT_NAME})
