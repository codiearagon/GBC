#pragma once

#include "bus.h"

class Bus;

class WRAM {
    public:
        WRAM();
        ~WRAM();

        void connect_bus(Bus *_bus);
    private:
        Bus *bus;

        uint8_t data[32768]; // 32 kb of ram
};