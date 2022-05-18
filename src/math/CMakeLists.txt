set(MATH_HEADERS
    math.hpp
    vec2.hpp
    vec2i.hpp
)

set(MATH_SOURCES
    math.cpp
    vec2.cpp
    vec2i.cpp
)

target_sources(jleg PUBLIC
    ${MATH_HEADERS}
    ${MATH_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
