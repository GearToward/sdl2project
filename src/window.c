#include "window.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include <stdio.h>
#include "draw.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

#define WINW 960
#define WINH 720

bool init(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);


    window = SDL_CreateWindow("Game" VERSION_DEV,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINW,
                              WINH,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Window could not be created!\n", SDL_GetError());
    } else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    } else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    }

    bool running = true;
    while (running) {
      while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;
        /* case SDL_MOUSEMOTION: */
        /*   printf("benis\n"); */
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
