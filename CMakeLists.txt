cmake_minimum_required(VERSION 3.10)

project(memutil)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -ansi -pedantic")

set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sources)
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/headers)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include_directories(${HEADERS_DIR})

file(GLOB_RECURSE SOURCES ${SOURCES_DIR}/*.c)
file(GLOB_RECURSE TESTS ${TESTS_DIR}/*.c)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

add_executable(test_${PROJECT_NAME} ${TESTS})

target_link_libraries(test_${PROJECT_NAME} ${PROJECT_NAME})

