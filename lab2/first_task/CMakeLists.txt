cmake_minimum_required(VERSION 3.5)

project(LAB2_1)

file(GLOB CPP_SOURCES
  "src/*.cpp"
  "src/LinkedList/*.cpp"
  "src/Array/*.cpp"
  "src/Graph/MatrixGraph/*.cpp"
  "src/Graph/ListGraph/*.cpp")

include_directories(${LAB2_1_SOURCE_DIR}/src/Array)
include_directories(${LAB2_1_SOURCE_DIR}/src/LinkedList)
include_directories(${LAB2_1_SOURCE_DIR}/src/Graph)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})