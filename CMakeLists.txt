cmake_minimum_required(VERSION 3.20)

project(learnCG)

#glad_d is debug version
set(CMAKE_BUILD_TYPE "Debug")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(PREDEFINED_TARGETS_FOLDER "CustomTargets")

set(DEV "${CMAKE_SOURCE_DIR}/dev")

#add glad lib
#add_library(glad STATIC ${DEV}/src/glad.c)
#set_target_properties(glad PROPERTIES FOLDER "devLib")

include_directories(${DEV}/include) 

if(WIN32)
  link_libraries("${DEV}/lib/glfw3.lib" "${DEV}/lib/glad_d.lib")
endif()

add_subdirectory(01Line)