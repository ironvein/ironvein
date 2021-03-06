################
#### INITIAL####
################

#Make sure we have a minimum version
cmake_minimum_required(VERSION 2.6)

###############
#### SETUP ####
###############

#Set globally required variables
set(APPLICATION_NAME ironvein)
set(APPLICATION_LINK_LIBRARIES)

#Set the project name and primary language
project(${APPLICATION_NAME} CXX)

#Set the version numbers
set(APPLICATION_VERSION_MAJOR 0)
set(APPLICATION_VERSION_MINOR 1)
set(APPLICATION_VERSION_BUILD 0)
set(APPLICATION_VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_BUILD}")
set(APPLICATION_DEBUG_ENABLED true)

#Set the source files and directories we will use
set(APPLICATION_SOURCE_FILES)
set(APPLICATION_SOURCE_DIRS)

#Set CMake modules path
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})

#Add compiler flags
add_definitions(-std=c++11 -Wall -g3)

#######################
#### ADD LIBRARIES ####
#######################

########
# SFML #
########

#Find SFML
find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
	set(APPLICATION_SOURCE_DIRS ${APPLICATION_SOURCE_DIRS} ${SFML_INCLUDE_DIR})
	set(APPLICATION_LINK_LIBRARIES ${APPLICATION_LINK_LIBRARIES} ${SFML_LIBRARIES})
	message(${SFML_LIBRARIES})
else ()
	message(FATAL_ERROR "SFML could not be found, and is required to build this application.")
endif ()

#######
# GLM #
#######

#Find GLM
find_package(GLM REQUIRED)

if (GLM_FOUND)
	set(APPLICATION_SOURCE_DIRS ${APPLICATION_SOURCE_DIRS} ${GLM_INCLUDE_DIR})
else ()
	message(FATAL_ERROR "GLM could not be found, and is required to build this application.")
endif ()

##################
#### BUILDING ####
##################

#Include the src directory (all the project code)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/include")

#Add all directories that need to be added
include_directories(${APPLICATION_SOURCE_DIRS})

#Take the code and turn it into the executable
add_executable(${APPLICATION_NAME} ${APPLICATION_SOURCE_FILES})

#Link the final executable to the needed libraries
target_link_libraries(${APPLICATION_NAME} ${APPLICATION_LINK_LIBRARIES})
