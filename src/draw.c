#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include "window.h"

void DrawInit(){

    if(IMG_Init(IMG_INIT_PNG) !=0){
        printf("Initization png failed: %s", SDL_GetError() );
    }

    SDL_Surface* surface;
    SDL_Texture* texture;

    surface = IMG_Load("../assets/tenshi.png");

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
}


