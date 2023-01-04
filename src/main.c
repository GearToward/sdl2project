#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <wctype.h>
#include "window.h"

int main(int argc, char *argv[]){
    if(init() !=0){
        fprintf(stderr,"failed to init\n");
    } else {
        fprintf(stderr,"init success\n");
    }

    cleanup();
    SDL_Quit();

    return 0;
}
