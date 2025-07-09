#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "gbc_debugger.h"
#include "cpu.h"
#include "bus.h"
#include "wram.h"

class GBC {
    public:
        GBC();
        ~GBC();
        
        static bool is_debugging();

        void load_rom(std::string file_name);
        void open_debugger();
        void close_debugger();

        void run(); // main loop
    private:
        inline static bool debugging_enabled;

        GBCDebugger gbc_debugger;
        CPU cpu;
        WRAM wram;
        Bus bus;
};