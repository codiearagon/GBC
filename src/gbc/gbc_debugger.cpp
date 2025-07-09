#include <iostream>

#include "gbc_debugger.h"

GBCDebugger::GBCDebugger() {
    window = SDL_CreateWindow("GBC Debugger", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEBUGGER_WIDTH, DEBUGGER_HEIGHT, SDL_WINDOW_HIDDEN);
    if(!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

    window_id = SDL_GetWindowID(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

}

GBCDebugger::~GBCDebugger() {}

void GBCDebugger::show_debugger() {
    SDL_ShowWindow(window);
}

void GBCDebugger::hide_debugger() {
    SDL_HideWindow(window);
}

void GBCDebugger::draw() {
    SDL_RenderPresent(renderer);
}