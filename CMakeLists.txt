cmake_minimum_required(VERSION 3.25.1)

project(sdl2project
    VERSION 0.0.1
    DESCRIPTION "sdl2 game"
    LANGUAGES C)

add_executable (
    ${PROJECT_NAME}
    src/main.c
    src/window.c
    src/draw.c
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
