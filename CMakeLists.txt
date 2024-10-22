cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Collect all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Optionally collect all .h files in the src directory (for reference)
file(GLOB_RECURSE HEADER_FILES src/*.h)

# Add the executable target with all source files
add_executable(${PROJECT_NAME} ${SRC_FILES} src/main.cpp)

# Include the src directory for header files
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

