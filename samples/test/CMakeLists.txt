project(test)

set(GAME_HEADERS
    player.hpp
)

set(GAME_SOURCES
    main.cpp
    player.cpp
)

add_executable(test
    ${GAME_HEADERS}
    ${GAME_SOURCES}
)

target_include_directories(jleg PUBLIC ./)

target_link_libraries(test jleg)
