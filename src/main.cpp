#include <format>
#include <iostream>
#include <ostream>

#include "InfoParser.hpp"

void bench_first();
void bench_second();

int main() {
  std::cout << std::flush;
  CpuCoresInfo cci{};
  CpuParser cpu_parser{};
  cpu_parser.fillCCI(cci);
  std::cout << std::format(
      "user: {}  nice: {}  system: {}\nidle: {}  iowait: {}  irq: {}  softirq: "
      "{}\nsteal: {}  guest: {}  guest_nice: {}\n",
      cci.user, cci.nice, cci.system, cci.idle, cci.iowait, cci.irq,
      cci.softirq, cci.steal, cci.guest, cci.guest_nice);

  cpu_parser.findAmountOfSiblings();
  std::cout << cpu_parser.getSiblings() << '\n';

  MemInfo mi{};
  MemParser mem_parser{};
  mem_parser.fillUMap();
  mem_parser.fillMI(mi);
  std::cout << std::format(
      "MemTotal: {}   MemFree: {}   MemAvailable: {}  Cached: {}  SwapCached: {} \
            SwapTotal: {} SwapFree: {}\n",
      mi.mem_total, mi.mem_free, mi.mem_available, mi.cached, mi.swap_cached,
      mi.swap_total, mi.swap_free);

  bench_first();
  bench_second();
}
