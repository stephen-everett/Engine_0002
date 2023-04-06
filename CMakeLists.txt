cmake_minimum_required(VERSION 3.10.0)

#project name
project (Engine_0002)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
file(GLOB SOURCES "src/*.cpp")

include_directories(
    ${CMAKE_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/includes/Nodes
    ${CMAKE_SOURCE_DIR}/includes/Nodes/Entities
    ${CMAKE_SOURCE_DIR}/includes/Nodes/Levels
    ${CMAKE_SOURCE_DIR}/includes/Nodes/Systems
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    )

add_executable(Main ${SOURCES})
target_link_libraries(Main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
