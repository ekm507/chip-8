#include "cpu.h"

#include "bus.h"

//connect to bus
void Cpu::connect(Bus *b)
{
    bus = b;
}

//read from memory
uint8_t Cpu::read(uint16_t address)
{
    return bus -> read(address);
}


//write to memory
void Cpu::write(uint16_t address, uint8_t value)
{
    bus -> write(address, value);
}