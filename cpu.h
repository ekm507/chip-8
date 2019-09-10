#pragma once

class Bus;

class Cpu
{
public:
    Bus *bus;

    void connect(Bus *b);
};
