cmake_minimum_required(VERSION 3.5)

project(LAB3_2)

file(GLOB CPP_SOURCES
  "src/*.cpp",
  "src/RedBlackTree/*.cpp",
  "src/HashMap/*.cpp",
  "src/LinkedList/*.cpp"
)

include_directories(${PROJECT_SOURCE_DIR}/src/)
include_directories(${LAB3_2_SOURCE_DIR}/src/RedBlackTree)
include_directories(${LAB3_2_SOURCE_DIR}/src/HashMap)
include_directories(${LAB3_2_SOURCE_DIR}/src/LinkedList)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})