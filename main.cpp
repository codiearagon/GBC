#include <iostream>
#include "gbc.h"

int main (int argc, char **argv) {
    GBC gameboy;

    gameboy.load_rom("assets/test.gbc");
    return 0;
}