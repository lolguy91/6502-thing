#include <6502-emu/6502.h>

CPU::CPU(bus _bus,uint16_t startAddress)
{
    ConnectedBus = _bus;
    state.pc = startAddress;

    //TODO: initialize instructions here
}


void CPU::clocktick()
{
    if(ticks == 0)
    {
        execute();
        ticks++;
    }
    if(ticks >= TicksNeeded){
        ticks = 0;
    }
}
void CPU::fetch(uint8_t addressingMode)
{
        switch (addressingMode)
    {
    case CPU_AM_ABS:
        break;
    
    case CPU_AM_ABSX:
        break;
    
    case CPU_AM_ABSY:
        break;
    
    case CPU_AM_IND:
        break;
    
    case CPU_AM_INDX:
        break;
    
    case CPU_AM_INDY:
        break;
    
    case CPU_AM_IMM:
        break;
    
    case CPU_AM_IMP:
        break;
    
    case CPU_AM_ZP:
        break;
    
    case CPU_AM_ZPX:
        break;

    case CPU_AM_ZPY:
        break;

    case CPU_AM_REL:
        break;
    
    case CPU_AM_ACC:
        break;
    
    default:

        break;
    }
}

void CPU::execute()
{
    uint8_t instruction = ConnectedBus.read(state.pc);
    pc++;
    fetch();
    
    //TODO: implement instruction handling

}
