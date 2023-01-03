#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <stdbool.h>

#define WINW 960
#define WINH 720

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

   SDL_Window* window = SDL_CreateWindow("lol", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINW, WINH, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

   SDL_Renderer* renderer = SDL_CreateRenderer(window, 1,SDL_RENDERER_ACCELERATED);
   SDL_Surface* image = IMG_Load("../assets/tenshi.png");
   SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

   bool running = true;
   while (running) {
       SDL_Event event;
       while (SDL_PollEvent(&event)) {
           switch (event.type) {
               case SDL_QUIT:
                   running = false;
                   break;
                case SDL_MOUSEMOTION:
                    printf("benis\n");
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_a) {
                        SDL_RenderCopy(renderer, texture, NULL, NULL);
                        printf("yo\n");

                    }
                default:
                    break;
           }
       }
       SDL_RenderPresent(renderer);
   }

   SDL_DestroyTexture(texture);
   SDL_FreeSurface(image);
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
   return 0;
}
