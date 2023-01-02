#ifndef __6502_H__
#define __6502_H__
#include <stdint.h>
#include <6502-emu/bus.h>
enum ADDRSSING_MODES
{
    CPU_AM_IMM,
    CPU_AM_IMP,
    CPU_AM_IND,
    CPU_AM_INDX,
    CPU_AM_INDY,
    CPU_AM_ABS,
    CPU_AM_ABSX,
    CPU_AM_ABSY,
    CPU_AM_REL,
    CPU_AM_ACC,
    CPU_AM_ZP,
    CPU_AM_ZPX,
    CPU_AM_ZPY

};
enum CPU_FLAG {
    CPU_FLAG_N = (1 << 7),
    CPU_FLAG_V = (1 << 6),
    CPU_FLAG_U = (1 << 5),
    CPU_FLAG_B = (1 << 4),
    CPU_FLAG_D = (1 << 3),
    CPU_FLAG_I = (1 << 2),
    CPU_FLAG_Z = (1 << 1),
    CPU_FLAG_C = (1 << 0)
};

struct CPU_State
{
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t sp;
    uint16_t pc;
    uint8_t flags;
    
};
struct Instruction{
    uint8_t addressing_mode;
    void (*callback)();
    uint8_t cycles;
}

class CPU
{

private:
    Instruction* instructions[255];
    CPU_State state;
    void fetch(uint8_t addressingMode);
    void execute();
    bus ConnectedBus;
    uint8_t ticks;
    uint8_t TicksNeeded;
public:
    CPU(bus _bus,uint16_t startAddress);
    ~CPU();
    void clocktick();
    
};








#endif // __6502_H__