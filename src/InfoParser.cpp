#include "InfoParser.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

CpuParser::CpuParser() {
  reader.open("/proc/stat", std::ios::in);
  if (!reader.is_open()) {
    std::cerr << "Failed to open file: /proc/stat\n";
  }
}

CpuParser::~CpuParser() { reader.close(); }

void CpuParser::fillCCI(CpuCoresInfo &cci) {
  std::string line;
  std::getline(reader, line);
  line = line.substr(line.find_first_of(" \t") + 1);
  std::stringstream ss(line);
  ss >> cci.user;
  ss >> cci.nice;
  ss >> cci.system;
  ss >> cci.idle;
  ss >> cci.iowait;
  ss >> cci.irq;
  ss >> cci.softirq;
  ss >> cci.steal;
  ss >> cci.guest;
  ss >> cci.guest_nice;
}

int CpuParser::findAmountOfSiblings() {
  std::ifstream is("/proc/cpuinfo", std::ios::in);
  if (!is.is_open()) {
    std::cerr << "Failed to open file: /proc/cpuinfo\n";
    return -1;
  }
  std::string line;
  for (size_t i = 0; i < 11; i++) {
    std::getline(is, line);
  }
  line = line.substr(line.find_first_of(':') + 2);
  std::istringstream iss(line);
  iss >> siblings;
  is.close();
  return 0;
}

MemParser::MemParser() {
  reader.open("/proc/meminfo", std::ios::in);
  if (!reader.is_open()) {
    std::cerr << "Failed to open file: /proc/meminfo\n";
  }
}

MemParser::~MemParser() { reader.close(); }

void MemParser::fillMI(MemInfo &mi) {
  mi.mem_total = mp.at("MemTotal");
  mi.mem_free = mp.at("MemFree");
  mi.mem_available = mp.at("MemAvailable");
  mi.cached = mp.at("Cached");
  mi.swap_cached = mp.at("SwapCached");
  mi.swap_total = mp.at("SwapTotal");
  mi.swap_free = mp.at("SwapFree");
}

void MemParser::fillUMap() {
  std::string line;
  std::regex re(R"(\d+)");
  std::smatch match;
  int index = 0;
  while (std::getline(reader, line)) {
    switch (index) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 14:
    case 15: {
      std::string name = line.substr(0, line.find_first_of(':'));
      uint64_t number;
      if (std::regex_search(line, match, re)) {
        number = std::strtoul(match.str(0).c_str(), nullptr, 0);
      }
      mp.insert({name, number});
    } break;
    default:
      break;
    }
    index++;
  }
}
