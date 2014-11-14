cmake_minimum_required (VERSION 2.6)
project(a2display)

set(LIBNAME a2display)

# check for in-source build, forbid it!
if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "\nIn-source build attempt detected!\n"
    "Please create a new directory (e.g. build) and run `cmake ..`.\n"
    "Also don't forget to delete the created CMakeCache.txt and CMakeFiles dir"
    )
endif()

include (cmake/settings.cmake)

message(STATUS "*** Build Type:      " ${CMAKE_BUILD_TYPE})
message(STATUS "*** Compiler Flags:  " ${DEFAULT_COMPILE_FLAGS})
message(STATUS "*** Install libs to: " ${LIBRARY_OUTPUT_PATH})
message(STATUS "*** Install bin to:  " ${EXECUTABLE_OUTPUT_PATH})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(ROOT "5.30" REQUIRED)

include_directories(${ROOT_INCLUDES})
link_directories(${ROOT_LIBRARY_DIR} ${CURRENT_BINARY_DIR})

include_directories("inc")

set(SRCS
    src/matrixstack.cpp
    src/TH2DrawTool.cpp
    src/TH2CB.cpp
    src/TH2TAPS.cpp
)

get_property(allincdirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY INCLUDE_DIRECTORIES)

ROOT_GENERATE_DICTIONARY("${CMAKE_CURRENT_SOURCE_DIR}/inc/TH2CB.h;${CMAKE_CURRENT_SOURCE_DIR}/inc/TH2TAPS.h" "${CMAKE_CURRENT_SOURCE_DIR}/inc/LinkDef.h" "${CMAKE_BINARY_DIR}/Dict.cc" "${allincdirs}")

file(GLOB_RECURSE ADDITIONAL_FILES "inc/*")
set_source_files_properties(${ADDITIONAL_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)

add_library(${LIBNAME} SHARED  ${SRCS} ${CMAKE_BINARY_DIR}/Dict.cc ${ADDITIONAL_FILES})
target_link_libraries(${LIBNAME} ${ROOT_LIBRARIES})

add_executable(compiled_example compiled_example.cpp)
target_link_libraries(compiled_example ${LIBNAME} ${ROOT_LIBRARIES})
