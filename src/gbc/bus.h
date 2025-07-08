#pragma once

#include <cstdint>

#include "cpu.h"

// forward declarations
class CPU;
class WRAM;

class Bus {
    public:
        Bus();
        ~Bus();

        void connect_components(CPU *_cpu, WRAM *_wram);
        void read(uint16_t addr);
        void write(uint16_t addr, uint8_t value);
    private:
        CPU *cpu;
        WRAM *wram;
};