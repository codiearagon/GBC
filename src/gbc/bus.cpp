#include "bus.h"

Bus::Bus() {
}

Bus::~Bus() {}

void Bus::connect_components(CPU *_cpu) {
    cpu = _cpu;
}