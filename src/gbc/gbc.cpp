#include "gbc.h"

#include <fstream>
#include <iostream>

GBC::GBC() {
    cpu.connect_bus(&bus);
    wram.connect_bus(&bus);
    bus.connect_components(&cpu, &wram);
}

GBC::~GBC() {
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