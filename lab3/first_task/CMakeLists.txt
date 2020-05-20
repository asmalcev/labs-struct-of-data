cmake_minimum_required(VERSION 3.5)

project(LAB3_1)

file(GLOB CPP_SOURCES
  "src/*.cpp",
  "src/Heap/*.cpp",
  "src/Sorts/*.cpp",
  "src/Counter/*.cpp"
)

include_directories(${LAB3_1_SOURCE_DIR}/src/)
include_directories(${LAB3_1_SOURCE_DIR}/src/Heap)
include_directories(${LAB3_1_SOURCE_DIR}/src/Sorts)
include_directories(${LAB3_1_SOURCE_DIR}/src/Counter)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})