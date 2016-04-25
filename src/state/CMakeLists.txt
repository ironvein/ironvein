########################
#### Subdirectories ####
########################

#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/app")

#################
#### SOURCES ####
#################

#Add the appropriate source files
set(APPLICATION_SOURCE_FILES
${APPLICATION_SOURCE_FILES}
"${CMAKE_CURRENT_SOURCE_DIR}/chatstate.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/gamestate.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/playerstate.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/regionstate.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/worldstate.cpp"
PARENT_SCOPE
)
