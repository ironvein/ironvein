#######################
#### CONFIGURATION ####
#######################

#settings.h header file
configure_file(
"util/config.h.in"
"util/config.h"
)

##################
#### INCLUDES ####
##################

#Add the appropriate source directories
set(APPLICATION_SOURCE_DIRS
${APPLICATION_SOURCE_DIRS}
"${PROJECT_BINARY_DIR}/include"
"${CMAKE_CURRENT_SOURCE_DIR}"
PARENT_SCOPE
)
