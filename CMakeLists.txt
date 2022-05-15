cmake_minimum_required(VERSION 3.22)

project(jleg VERSION 0.1)

add_library(jleg include/jleg/jleg.hpp)

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

target_link_libraries(jleg
    glfw
    glad
    stb
    glm
    box2d
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(samples/test)


# add_subdirectory(
#     lib/imgui
# )

# target_link_libraries(imgui glfw)
# target_include_directories(imgui PUBLIC "${PROJECT_BINARY_DIR}" lib/glfw/include/)

# cmake_minimum_required(VERSION 3.22)
#
# project(nurengine VERSION 0.1)
#
# add_library(nurengine
#     include/nurengine/nurengine.hpp
# )
#
# target_include_directories(nurengine PUBLIC "${PROJECT_BINARY_DIR}" include/)
#
# #GLFW
# set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#
# add_subdirectory(lib/glfw)
#
# #glad
# add_subdirectory(lib/glad)
#
# #stb_image
# add_subdirectory(lib/stb)
#
# #box2d-lite
# add_subdirectory(lib/box2d)
#
# #glm
# add_subdirectory(lib/glm)
#
# #rendering
# add_subdirectory(src/rendering)
#
# #math
# # add_subdirectory(src/math)
#
# #link libraries
# target_link_libraries(nurengine
#     glad
#     glfw
#     stb
#     box2d
#     glm
# )
#
# #samples
# add_subdirectory(samples/testproject)
#
# configure_file(config.hpp.in config.hpp)
#
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
