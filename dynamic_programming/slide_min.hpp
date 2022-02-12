#pragma once
#include <deque>
#include <vector>

template <bool IS_MINIMIZED = true, typename T>
std::vector<T> slide_min(const std::vector<T>& a, const int len) {
  const int n = a.size();
  std::vector<T> res(n - len + 1);
  std::deque<T> deq;
  for (int i = 0; i < n; ++i) {
    while (!deq.empty() &&
           !(IS_MINIMIZED ? a[deq.back()] < a[i] : a[deq.back()] > a[i])) {
      deq.pop_back();
    }
    deq.emplace_back(i);
    if (i + 1 >= len) {
      const int left = i + 1 - len;
      res[left] = a[deq.front()];
      if (deq.front() == left) deq.pop_front();
    }
  }
  return res;
}
