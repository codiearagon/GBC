#pragma once

#include <string>

#include "cpu.h"
#include "bus.h"
#include "wram.h"

class GBC {
    public:
        GBC();
        ~GBC();
        
        void load_rom(std::string file_name);
    private:
        CPU cpu;
        WRAM wram;
        Bus bus;
};