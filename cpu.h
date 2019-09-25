#pragma once

class Bus;

class Cpu
{
public:
    //Bus defines CPU
    Bus *bus;

    //CPU connects to bus after created.
    void connect(Bus *b);

    //read from memory
    uint8_t read(uint16_t address);

    //write to memory
    void write(uint16_t address, uint8_t value);

    //registers
    uint8_t V[16];

    //address register
    union {
        uint16_t I;
        struct _Parts
        {
            uint8_t IH : 8;
            uint8_t IL : 8;
        };
    };

    //program counter
    uint16_t PC = 0;

    //stack pointer
    uint16_t stkp;

    /*
    HOW STACK WORKS

    we have a stack pointer that contains the uppermost value
    of the stack.
    stack array will contain the address of PC.
    when pushing to stack:
    stack[++stkn] = sth;
    when popping from stack:
    sth = stack[stkn--];
    */

    //stack memory;
    uint16_t stack[24];

    //stack counter
    uint8_t stkn = 0;

    
};
