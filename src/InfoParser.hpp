#pragma once

#include <cstdint>
#include <fstream>

/*
 *  The structure contains information about an individual CPU thread.
 *  user: normal processes executing in user mode
 *  system: processes executing in kernel mode
 *  nice: niced processes executing in user mode
 *  idle: twiddling thumbs
 *  iowait: iowait stands for waiting for I/O to complete
 *  irq: servicing interrupts
 *  softirq: servicing softirqs
 *  steal: involuntary wait
 *  guest: running a normal guest
 *  guest_nice: running a niced guest
 */
struct CpuCoresInfo {
    uint32_t user = 0;
    uint32_t nice = 0;
    uint32_t system = 0;
    uint32_t idle = 0;
    uint32_t iowait = 0;
    uint32_t irq = 0;
    uint32_t softirq = 0;
    uint32_t steal = 0;
    uint32_t guest = 0;
    uint32_t guest_nice = 0;
};


class CpuParser {
private:
    std::ifstream reader;
    int siblings = 0;
public:
    CpuParser();
    ~CpuParser();

    void fillCCI(CpuCoresInfo& cci);
    int findAmountOfSiblings();
    int getSiblings() {
        return siblings;
    }
};

class MemParser {

};
