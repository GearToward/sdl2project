#include "window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdbool.h>
#include <stdio.h>
#include "draw.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

bool init(){
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Game" VERSION_DEV,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINWNH,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created: %s\n", SDL_GetError());
    } else {
        renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    return false;

}

void GameLoop(){
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
    SDL_RenderClear(renderer);
  }

}

void cleanup(){
    SDL_DestroyWindow(window);
}
