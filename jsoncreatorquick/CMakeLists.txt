cmake_minimum_required(VERSION 3.16)
project(jsoncreatorquick  VERSION 1.0 LANGUAGES CXX)

# 1. Find SDL3 and SDL3_image


# 2. File Organization
# game03.cpp is in the root, so no prefix needed.
# Others are in their respective folders.
set(HEADER_FILES )
    
set(SOURCE_FILES
    "../jsoncreatorquick/jsoncreator.cpp" )
    
# 3. Create the Executable
add_executable(jsoncreator ${SOURCE_FILES} ${HEADER_FILES} )

# 4. Target Settings
target_compile_features(game03 PRIVATE cxx_std_20)

# This lets you write #include "animtimer.h" instead of #include "header/animtimer.h"

target_include_directories(jsoncreatorquick PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")




# 6. Organize files into folders within Visual Studio's Solution Explorer
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCE_FILES} ${HEADER_FILES}) 