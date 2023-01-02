#include <6502-emu/bus.h>

bool bus::read(uint16_t addr)
{
    bool shouldreturn = false;
    uint8_t result = 0;
    for (size_t i = 0; i < m_callbacks.size() && !shouldreturn ; i++)
    {
        // !! a device might set the result even if its out of range
       shouldreturn = m_callbacks[i](addr, &result,false);
    }
    return result;
}

bool bus::write(uint16_t addr, uint8_t data)
{
    bool shouldreturn = false;
    for (size_t i = 0; i < m_callbacks.size() && !shouldreturn; i++)
    {
       shouldreturn = m_callbacks[i](addr, &data,true);
    }
    
}

void bus::RegisterDevice(bool (*callback)(uint16_t,uint8_t,bool))
{
    m_callbacks.push_back(callback);
}