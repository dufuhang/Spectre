cmake_minimum_required(VERSION 2.8)
project(spectre)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

set(LIB_SRC
    spectre/log.cc
    )
#创建共享库
add_library(spectre SHARED ${LIB_SRC})
#add_library(spectre_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (spectre_static PROPERTIES OUTPUT_NAME "spectre")

add_executable(test tests/test.cc)
add_dependencies(test spectre)

target_link_libraries(test spectre)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
