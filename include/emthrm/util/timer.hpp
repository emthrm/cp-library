#ifndef EMTHRM_UTIL_TIMER_HPP_
#define EMTHRM_UTIL_TIMER_HPP_

#include <chrono>

namespace emthrm {

struct Timer {
  Timer() { reset(); }
  void reset() { bgn = std::chrono::high_resolution_clock::now(); }
  template <typename PeriodType = std::chrono::milliseconds>
  long long elapsed() const {
    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<PeriodType>(end - bgn).count();
  }
 private:
  std::chrono::high_resolution_clock::time_point bgn;
} timer;

}  // namespace emthrm

#endif  // EMTHRM_UTIL_TIMER_HPP_
