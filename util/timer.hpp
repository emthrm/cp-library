#pragma once
#include <chrono>

struct Timer {
  Timer() { reset(); }
  void reset() { beg = std::chrono::high_resolution_clock::now(); }
  template <typename PeriodType = std::chrono::milliseconds>
  long long elapsed() const {
    std::chrono::high_resolution_clock::time_point en = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<PeriodType>(en - beg).count();
  }
private:
  std::chrono::high_resolution_clock::time_point beg;
} timer;
