#pragma once
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

struct Mo {
  Mo(const std::vector<int> &left, const std::vector<int> &right) : left(left), right(right) {
    n = left.size();
    int width = std::sqrt(n);
    order.resize(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int a, int b) -> bool {
      return left[a] / width != left[b] / width ? left[a] < left[b] : ((left[a] / width) & 1 ? right[a] < right[b] : right[a] > right[b]);
    });
  }

  int process() {
    if (ptr == n) return -1;
    int idx = order[ptr++];
    while (left[idx] < nl) add(--nl);
    while (nr < right[idx]) add(nr++);
    while (nl < left[idx]) del(nl++);
    while (right[idx] < nr) del(--nr);
    return idx;
  }

  void add(int idx) const;

  void del(int idx) const;

private:
  std::vector<int> left, right, order;
  int n, ptr = 0, nl = 0, nr = 0;
};
