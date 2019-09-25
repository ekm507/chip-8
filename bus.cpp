#include "bus.h"

Bus::Bus()
{
    cpu.connect(this);
}

uint8_t Bus::read(uint16_t address)
{
    if(address >= 0x000 && address <= 0xFFF)
        return memory[address];
}

void Bus::write(uint16_t address, uint8_t value)
{
    if(address >= 0x000 && address <= 0xFFF )
        memory[address] = value;
}