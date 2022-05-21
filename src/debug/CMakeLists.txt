set(DEBUG_HEADERS
    log.hpp
)

set(DEBUG_SOURCES
    log.cpp
)

target_sources(jleg PUBLIC
    ${DEBUG_HEADERS}
    ${DEBUG_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
