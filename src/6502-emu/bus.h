#ifndef __BUS_H__
#define __BUS_H__
#include <stdint.h>
#include <vector>

class bus
{
private:
    std::vector<bool (*)(uint16_t,uint8_t*,bool)> m_callbacks;
public:
    bool read(uint16_t addr);
    bool write(uint16_t addr, uint8_t data);
    void RegisterDevice(bool (*callback)(uint16_t,uint8_t*,bool));
};


#endif // __BUS_H__