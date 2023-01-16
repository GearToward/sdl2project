#include "window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include "draw.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

bool init(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    SDL_Surface* surface;

    SDL_Texture* texture;

    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow("Game" VERSION_DEV,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINWNH,
                              SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Window could not be created: %s\n", SDL_GetError());
    } else {
        renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    }

    surface = IMG_Load("../assets/tenshi.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

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
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
  }

}

void cleanup(){
    SDL_DestroyWindow(window);
}
