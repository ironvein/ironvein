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
"${CMAKE_CURRENT_SOURCE_DIR}/client.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/multiplexer.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/server.cpp"
PARENT_SCOPE
)
