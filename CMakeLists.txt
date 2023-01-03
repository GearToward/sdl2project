cmake_minimum_required(VERSION 3.25.1)

project(sdl2project)

add_executable (
    ${PROJECT_NAME}
    source/main.c
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
