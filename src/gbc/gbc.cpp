#include "gbc.h"

#include <fstream>
#include <iostream>

GBC::GBC() {
    debugging_enabled = false;

    std::cout << "Opened gbc" << std::endl;

    // initialize sdl2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! " << SDL_GetError() << std::endl;
        return;
    }

    cpu.connect_bus(&bus);
    wram.connect_bus(&bus);
    bus.connect_components(&cpu, &wram);
}

GBC::~GBC() {
}

bool GBC::is_debugging() {
    return debugging_enabled;
}

void GBC::load_rom(std::string file_name) {
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);

    if(!file) {
        std::cerr << "Failed to open file\n";
        return;
    }
    
    std::streamsize size = file.tellg();
    char* buffer = new char[size];
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close();

    for(long i = 0; i < size; ++i) {
    }

    delete[] buffer;
}

void GBC::open_debugger() {
    debugging_enabled = true;
    gbc_debugger.show_debugger();
}

void GBC::close_debugger() {
    debugging_enabled = false;
    gbc_debugger.hide_debugger();
}

void GBC::run() {
    bool running = true;

    SDL_Event event;
    
    while(running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }
        
        if(debugging_enabled) gbc_debugger.draw(); // only trigger debugger drawing if it debugger is open
    }
}