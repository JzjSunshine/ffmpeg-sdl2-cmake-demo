##
# CMake minimum required version for the project.
##
cmake_minimum_required(VERSION 3.10)

##
# FFmpeg-Video-Player C Project CMakeLists.txt.
##
project(FFmpeg_Example C CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_FLAGS "-D_STDC_CONSTANT_MACROS")
##
# Include module pkg-config for CMake.
##
INCLUDE(FindPkgConfig)



##
# Find FFmpeg include directories and link libraries.
# define FFMPEG_LIBRARIES and FFMPEG_INCLUDE_DIRS
##
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}"/Modules)
# set(SDL2MAIN_LIBRARY "")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/Modules)
message("CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})

find_package(SDL2 REQUIRED)
find_package(FFMPEG REQUIRED)
include_directories(${FFMPEG_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR})

message("FFMPEG_INCLUDE_DIRS: " ${FFMPEG_INCLUDE_DIRS})
message("SDL2_INCLUDE_DIR: " ${SDL2_INCLUDE_DIR})


add_subdirectory(src)
# # load user source and header files
# file(GLOB SOURCE_FILES "src/*.h" "src/*.cpp")
# add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
add_executable(FFmpeg_Example ${SOURCES})

# https://stackoverflow.com/questions/50760024/cmake-configuration-for-ffmpeg-in-c-project
target_link_libraries(FFmpeg_Example PRIVATE ${FFMPEG_LIBRARIES} ${SDL2_LIBRARIES})
# target_include_directories(FFmpeg_Example PRIVATE ${FFMPEG_INCLUDE_DIRS})
