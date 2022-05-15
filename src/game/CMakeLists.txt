set(GAME_HEADERS
    game.hpp
)

set(GAME_SOURCES
)

target_sources(jleg PUBLIC
    ${GAME_HEADERS}
    # ${MATH_SOURCES}
)

target_include_directories(jleg PUBLIC ./)
