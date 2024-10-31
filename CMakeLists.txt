cmake_minimum_required(VERSION 3.10)
project(MonstersUniversityGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/headers)

# Source files
set(SOURCES
    ${CMAKE_SOURCE_DIR}/code/Book.cpp
    ${CMAKE_SOURCE_DIR}/code/BookStack.cpp
    ${CMAKE_SOURCE_DIR}/code/CourseStructure.cpp
    ${CMAKE_SOURCE_DIR}/code/Monster.cpp
    ${CMAKE_SOURCE_DIR}/code/MikeMonster.cpp
    ${CMAKE_SOURCE_DIR}/code/SullyMonster.cpp
    ${CMAKE_SOURCE_DIR}/code/RandallMonster.cpp
    ${CMAKE_SOURCE_DIR}/code/Boo.cpp
    ${CMAKE_SOURCE_DIR}/code/Student.cpp
    ${CMAKE_SOURCE_DIR}/code/MUGraduate.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp
)

# Executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})  # Output executable to the root directory
add_executable(story ${SOURCES})
