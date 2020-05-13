cmake_minimum_required(VERSION 3.5)

project(LAB2_2)

file(GLOB CPP_SOURCES
  "src/*.cpp"
  "src/BinaryTree/*.cpp")

include_directories(${LAB2_2_SOURCE_DIR}/src/BinaryTree)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})