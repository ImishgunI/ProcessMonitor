#pragma once

#include <cstdint>
#include <fstream>
#include <unordered_map>
#include <vector>

class InfoParser;

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

struct MemInfo {
  uint64_t mem_total = 0;
  uint64_t mem_free = 0;
  uint64_t mem_available = 0;
  uint64_t cached = 0;
  uint64_t swap_cached = 0;
  uint64_t swap_total = 0;
  uint64_t swap_free = 0;
};

struct UptimeInfo {
    float system_up = 0.0f;
    float idle = 0.0f;
};

struct LoadAvgInfo {
    float first_min = 0.0f;
    float fifth_min = 0.0f;
    float fifteenth_min = 0.0f;
    uint16_t ready_obj = 0;
    uint32_t amount_of_obj = 0;
    uint32_t last_pid = 0;
};

class CpuParser {
private:
  std::ifstream reader;
  int siblings = 0;
  std::vector<CpuCoresInfo> cci{};

  CpuParser();
  ~CpuParser();

  void fillCCI();
  int findAmountOfSiblings();

  friend class InfoParser;
};

class MemParser {
private:
  std::ifstream reader;
  std::unordered_map<std::string, uint64_t> mp{};
  MemInfo mi{};

  MemParser();
  ~MemParser();

  void fillMI();
  void fillUMap();

  friend class InfoParser;
};

class UptimeParser {
private:
  std::ifstream reader;
  UptimeInfo ui{};

  UptimeParser();
  ~UptimeParser();

  void read();

  friend class InfoParser;
};

class LoadAvgParser {
private:
  std::ifstream reader;
  LoadAvgInfo lai{};

  LoadAvgParser();
  ~LoadAvgParser();

  void read();

  friend class InfoParser;
};

class InfoParser {
private:
    CpuParser cp{};
    MemParser mp{};
    UptimeParser up{};
    LoadAvgParser lap{};

public:
    const std::vector<CpuCoresInfo>& getCCIVector() const {
        return this->cp.cci;
    }

    const MemInfo& getMemInfo() const {
        return this->mp.mi;
    }

    const UptimeInfo& getUptimeInfo() const {
        return this->up.ui;
    }

    const LoadAvgInfo& getLoadAvgInfo() const {
        return this->lap.lai;
    }

    void update();
};
