set(MATH_HEADERS
    vec2.hpp
)

set(MATH_SOURCES
    vec2.cpp
)

target_sources(jleg PUBLIC
    ${MATH_HEADERS}
    ${MATH_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
