#include "cpu.h"

#include "bus.h"

void Cpu::connect(Bus *b)
{
    bus = b;
}