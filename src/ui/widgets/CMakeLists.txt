########################
#### Subdirectories ####
########################

#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/widgets")

#################
#### SOURCES ####
#################

#Add the appropriate source files
set(APPLICATION_SOURCE_FILES
${APPLICATION_SOURCE_FILES}
"${CMAKE_CURRENT_SOURCE_DIR}/widget.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/chatwidget.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/overworldwidget.cpp"
PARENT_SCOPE
)
