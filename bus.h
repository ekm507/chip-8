#pragma once

#include "cpu.h"

#include <cstdint>

class Bus
{
public:
    //define the CPU
    Cpu cpu;

    //Bus constructor
    Bus();

    //main memory.
    uint8_t memory[4096];

    //read from memory
    uint8_t read(uint16_t address);

    //write to memory
    void write(uint16_t address, uint8_t value);
};
