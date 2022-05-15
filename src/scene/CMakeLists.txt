set(SCENE_HEADERS
    node.hpp
    camera.hpp
    sprite.hpp
    character_body.hpp
    static_body.hpp
    scene_graph.hpp
)

set(SCENE_SOURCES
    node.cpp
    camera.cpp
    sprite.cpp
    character_body.cpp
    static_body.cpp
    scene_graph.cpp
)

target_sources(jleg PUBLIC
    ${SCENE_HEADERS}
    ${SCENE_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
