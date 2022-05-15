set(IO_HEADERS
    input.hpp
)

set(IO_SOURCES
    input.cpp
)

target_sources(jleg PUBLIC
    ${IO_HEADERS}
    ${IO_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
