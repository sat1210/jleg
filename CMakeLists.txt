cmake_minimum_required(VERSION 3.22)

project(jleg VERSION 0.1)

add_library(jleg include/jleg/jleg.hpp include/jleg/jleg.cpp)

target_include_directories(jleg PUBLIC "${PROJECT_BINARY_DIR}" include/)

#source files
add_subdirectory(
    src/visuals
)

add_subdirectory(
    src/physics
)

add_subdirectory(
    src/scene
)

add_subdirectory(
    src/math
)

add_subdirectory(
    src/debug
)

add_subdirectory(
    src/game
)

add_subdirectory(
    src/io
)
#libraries
add_subdirectory(
    lib/glfw
)

add_subdirectory(
    lib/glad
)

add_subdirectory(
    lib/stb
)

add_subdirectory(
    lib/glm
)

add_subdirectory(
    lib/json
)

add_subdirectory(
    lib/box2d
)

add_subdirectory(
    lib/imgui
)

target_link_libraries(imgui
    glfw
)

target_link_libraries(jleg
    glfw
    glad
    stb
    glm
    box2d
    nlohmann_json
    imgui
)



set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(samples/test)
