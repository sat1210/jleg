set(VISUALS_SOURCES
    visuals.cpp
    shader.cpp
    sprite_drawer.cpp
    texture.cpp
)

set(VISUALS_HEADERS
    visuals.hpp
    shader.hpp
    sprite_drawer.hpp
    texture.hpp
)

target_sources(jleg PUBLIC
    ${VISUALS_HEADERS}
    ${VISUALS_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
