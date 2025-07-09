#include <iostream>
#include "gbc.h"

int main (int argc, char **argv) {
    std::cout << "Main" << std::endl;
    GBC gameboy;
    // gameboy.load_rom("assets/test.gbc");
    gameboy.run();
    return 0;
}