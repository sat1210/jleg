set(DEBUG_HEADERS
    logger.hpp
)

set(DEBUG_SOURCES
    logger.cpp
)

target_sources(jleg PUBLIC
    ${DEBUG_HEADERS}
    ${DEBUG_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
