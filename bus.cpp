#include "bus.h"

Bus::Bus()
{
    cpu.connect(this);
}
