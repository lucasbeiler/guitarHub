#include <iostream>
#include <SDL2/SDL.h>

#include "headers/controles.h"

using namespace std;

int controle(){
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    SDL_PumpEvents();

    if (state[SDL_SCANCODE_F1] || state[SDL_SCANCODE_1]) {
        return 1;
    }
    if (state[SDL_SCANCODE_F2] || state[SDL_SCANCODE_2]) {
        return 2;
    }
    if (state[SDL_SCANCODE_F3] || state[SDL_SCANCODE_3]) {
        return 3;
    }
    if (state[SDL_SCANCODE_F4] || state[SDL_SCANCODE_4]) {
        return 4;
    }
    if (state[SDL_SCANCODE_F5] || state[SDL_SCANCODE_5]) {
        return 5;
    }

    return 0;

}
