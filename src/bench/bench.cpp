#include "../InfoParser.hpp"

#include <chrono>
#include <iostream>

void bench_first() {
    auto start = std::chrono::steady_clock::now();
    CpuCoresInfo cci{};
    CpuParser cpu_parser{};
    cpu_parser.fillCCI(cci);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Время выполнения: " << elapsed.count() << " uс\n";
}

void bench_second() {
    auto start = std::chrono::steady_clock::now();
    MemInfo mi{};
    MemParser mem_parser{};
    mem_parser.fillUMap();
    mem_parser.fillMI(mi); 
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Время выполнения: " << elapsed.count() << " uс\n";
}
