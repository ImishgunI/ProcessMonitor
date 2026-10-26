#include "InfoParser.hpp"

#include <fstream>
#include <iostream>
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

MemParser::~MemParser() {
    reader.close();
}

void MemParser::fillMI(MemInfo& mi) {
    
}
