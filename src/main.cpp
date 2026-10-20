#include <format>
#include <iostream>

#include "InfoParser.hpp"

int main() {
    CpuCoresInfo cci{};
    CpuParser cpu_parser{};
    cpu_parser.fillCCI(cci);
    std::cout << std::format("user: {}  nice: {}  system: {}\nidle: {}  iowait: {}  irq: {}  softirq: {}\nsteal: {}  guest: {}  guest_nice: {}\n",
            cci.user, cci.nice, cci.system, cci.idle, cci.iowait, cci.irq, cci.softirq, cci.steal, cci.guest, cci.guest_nice);
    
    cpu_parser.findAmountOfSiblings();
    std::cout << cpu_parser.getSiblings();
}
