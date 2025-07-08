#pragma once

#include <cstdint>

#include "cpu.h"

class CPU;

class Bus {
    public:
        Bus();
        ~Bus();

        void connect_components(CPU *_cpu);
        void read(uint16_t addr);
        void write(uint16_t addr, uint8_t value);
    private:
        CPU *cpu;
};