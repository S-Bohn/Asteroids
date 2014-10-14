cmake_minimum_required(VERSION 2.8)

project(asteroids)

# Variables
set(APPLICATION_VERSION_MAJOR "0")
set(APPLICATION_VERSION_MINOR "1")
set(APPLICATION_VERSION_PATCH "0")
set(APPLICATION_VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")
set(APPLICATION_NAME ${PROJECT_NAME})

# User config
include("UserDefinitions.cmake" OPTIONAL)

# CMakeScripts
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeScripts ${CMAKE_MODULE_PATH})

# GLEW
find_package(glew REQUIRED)
include_directories(${GLEW_INCLUDE_DIR})
link_directories(${GLEW_LIBRARY_DIR})

# GLFW3
find_package(glfw3 REQUIRED)
include_directories(${GLFW3_INCLUDE_DIR})
link_directories(${GLFW3_LIBRARY_DIR})

# GLM
find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIR})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# Add subdirs
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

if(MSVC)
    message(STATUS "Detected MSVC")
	set(MSVC_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
    file(MAKE_DIRECTORY  "${CMAKE_BINARY_DIR}/src/asteroids/")
    configure_file("${PROJECT_SOURCE_DIR}/templates/asteroids.vcxproj.user.in" "${CMAKE_BINARY_DIR}/src/asteroids.vcxproj.user")
endif()