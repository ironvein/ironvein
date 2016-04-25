########################
#### Subdirectories ####
########################

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/app")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/game")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/net")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/state")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ui")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/util")

#################
#### SOURCES ####
#################

#Add the appropriate source files
set(APPLICATION_SOURCE_FILES
${APPLICATION_SOURCE_FILES}
"${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
PARENT_SCOPE
)
