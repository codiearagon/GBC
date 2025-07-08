#include <iostream>
#include "gbc.h"

int main (int argc, char **argv) {
    GBC gameboy;

    gameboy.load_rom("assets/");
    return 0;
}