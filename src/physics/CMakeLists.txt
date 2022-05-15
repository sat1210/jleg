set(PHYSICS_HEADERS
    physics.hpp
)

set(PHYSICS_SOURCES
    physics.cpp
)

target_sources(jleg PUBLIC
    ${PHYSICS_HEADERS}
    ${PHYSICS_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
