#pragma once
#include <deque>
#include <vector>

template <typename T>
std::vector<T> slide_min(const std::vector<T> &a, int len, bool is_minimized = true) {
  int n = a.size();
  std::vector<T> res(n - len + 1);
  std::deque<T> deq;
  for (int i = 0; i < n; ++i) {
    while (!deq.empty() && !(is_minimized ? a[deq.back()] < a[i] : a[deq.back()] > a[i])) deq.pop_back();
    deq.emplace_back(i);
    if (i + 1 >= len) {
      int left = i + 1 - len;
      res[left] = a[deq.front()];
      if (deq.front() == left) deq.pop_front();
    }
  }
  return res;
}
