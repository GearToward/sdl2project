#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <stdbool.h>

#define VERSION " v0.0.1"
#define VERSION_DEV " v0.0.x dev"

#define WINWNH 960, 720

bool init();
void GameLoop();
void cleanup();

#endif // WINDOW_H_
