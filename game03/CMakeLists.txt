cmake_minimum_required(VERSION 3.16)
project(game03 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# Engine sources
set(ENGINE_SOURCES
    src/engine/core/game_loop.cpp
    src/engine/render/renderer.cpp
    src/engine/input/input_manager.cpp
    # ... more
)

# Game sources
set(GAME_SOURCES
    src/game/player/player.cpp
    src/game/enemies/enemy.cpp
    # ... more
)

# Create executable
add_executable(game03
    src/game03.cpp
    ${ENGINE_SOURCES}
    ${GAME_SOURCES}
)

# Include directories
target_include_directories(game03 PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Link libraries
target_link_libraries(game03 PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
)
# 6. Organize files into folders within Visual Studio's Solution Explorer
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCE_FILES} ${HEADER_FILES})