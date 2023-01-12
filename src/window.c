#include "window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>
#include <stdio.h>
#include "draw.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

#define WINW 960
#define WINH 720

bool init(int argc, char const *argv[]){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface* surface;

    SDL_Texture* texture;

    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow("Game" VERSION_DEV,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINW,
                              WINH,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Window could not be created: %s\n", SDL_GetError());
    } else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    surface = IMG_Load("../assets/tenshi.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    bool running = true;
    while (running) {
      while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;
        default:
          break;
        }
      }
      SDL_RenderPresent(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderClear(renderer);
    }

    return 0;

}

void cleanup(){
    SDL_DestroyWindow(window);
}
