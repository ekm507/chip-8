# How to make a chip-8 emulator

to emulate a machine, first we need to know how it works.  
so let's take a look at wiki first.

## chip-8 system

based on wikipedia, chip-8 consists of these parts:

### Memory

a 4 KB memory of 8-bit random accessible bytes. from `0x000` to `0xFFF`.  
usually 512 bytes from the begining are not usable because  
emulator takes that much memory in usual systems.  
also last 256 bytes from `0xF00` to `0xFFF` are reserved for display memory.  
and 96 bytes below that from `0xEA0` to `0xEFF` are reserved for
the call stack,  
internal use and other variables.

### CPU

as the name represents, chip-8 has an 8-bit CPU.
consisting of  
parts below.

#### registers

chip-8 has 16 8-bit data registers named V0 to VF.  
The program counter, I register, opcode placeholder, and a stack pointer, all have a size of 16 bits.  

#### stack

A minimal of 16 level stack pointer is required and it is used to store return locations from the program counter register.

#### timers

There are two timers both countdown from 60 to 0.  
Delay timer is used for program events and its value can be set and read. And a sound timer which plays a beep whenever it reaches 0. After every operation execution, both timers get subtracted by 1.

timers count at 60 Hz.

#### opcodes

Chip-8 has 35 opcodes which are all two bytes long.

use link below to see a complete list of the opcodes.  
<https://en.wikipedia.org/wiki/CHIP-8#Opcode_table>

### graphics

The chip 8 has one instruction that draws sprite to the screen. Drawing is done in XOR mode and if a pixel is turned off as a result of drawing, the VF register is set. This is used for collision detection.

The graphics of the Chip 8 are black and white and the screen has a total of 2048 pixels (64 x 32).

### inputs

chip-8 has a keypad consisting of 16 keys numbered from `0x0`
to `0xF`.

## Main loop

now that we know how this machine workd, we can start emulating it.

main loop (also aka. super loop) seems to be a good approach.
