# Minimum required CMake version
cmake_minimum_required(VERSION 3.20)

# Project name
project(tryOgreQt)

# Qt tool switches
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set the output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Create output directories if they don't exist
file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
file(MAKE_DIRECTORY log)

# Uncomment and modify this line if your Qt is at a custom location
# set(Qt5_DIR C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(OGRE_DIR ogre-sdk-v13.6.5-msvc141-x64/CMake)
# The COMPONENTS part checks that OGRE was built the way we need it
# The CONFIG flag makes sure we get OGRE instead of OGRE-next
find_package(OGRE REQUIRED COMPONENTS Bites CONFIG)

# Add the source files as usual
add_executable(tryOgreQt
        main.cpp
        OgreContext.cpp
        OgreContext.h
        OgreWidget.cpp
        OgreWidget.h
)

# This also sets the includes and pulls third party dependencies
target_link_libraries(tryOgreQt OgreBitesQt Qt5::Core Qt5::Gui Qt5::Widgets)

# Define DLL directory
set(OGRE_DLL_DIR ogre-sdk-v13.6.5-msvc141-x64/bin)
set(DESTINATION_DIR ${EXECUTABLE_OUTPUT_PATH}/RelWithDebInfo)

# Find all DLL files in the DLL directory
file(GLOB DLLS "${OGRE_DLL_DIR}/*.dll")

# Iterate over each DLL file and add a post-build command to copy it
foreach(DLL ${DLLS})
    add_custom_command(TARGET tryOgreQt POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLL}
            ${DESTINATION_DIR}
    )
endforeach()
