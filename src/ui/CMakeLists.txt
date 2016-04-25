########################
#### Subdirectories ####
########################

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/widgets")

#################
#### SOURCES ####
#################

#Add the appropriate source files
set(APPLICATION_SOURCE_FILES
${APPLICATION_SOURCE_FILES}
"${CMAKE_CURRENT_SOURCE_DIR}/interface.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/renderer.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/window.cpp"
PARENT_SCOPE
)
