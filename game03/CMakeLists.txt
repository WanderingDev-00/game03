cmake_minimum_required(VERSION 3.16)
project(game03 VERSION 1.0 LANGUAGES CXX)

# 1. Find SDL3 and SDL3_image
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# 2. File Organization
# game03.cpp is in the root, so no prefix needed.
# Others are in their respective folders.
set(HEADER_FILES
    "src/engine/core/game.h"
     "src/engine/core/game_loop.h"  "src/engine/core/time_manager.h")

set(SOURCE_FILES
    "game03.cpp" 
    "src/engine/core/game.cpp""src/engine/core/game_loop.cpp"
     "src/engine/core/time_manager.cpp")

# 3. Create the Executable
add_executable(game03 ${SOURCE_FILES} ${HEADER_FILES} )

# 4. Target Settings
target_compile_features(game03 PRIVATE cxx_std_20)

# This lets you write #include "animtimer.h" instead of #include "header/animtimer.h"
target_include_directories(game03 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header")

# 5. Linking
target_link_libraries(game03 PRIVATE 
    SDL3::SDL3 
    SDL3_image::SDL3_image
)

# 6. Organize files into folders within Visual Studio's Solution Explorer
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCE_FILES} ${HEADER_FILES})