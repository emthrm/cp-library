/*
 * @brief その他/Mo's algorithm
 */
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "../../data_structure/bit/bit.hpp"
#include "../../misc/mo.hpp"

std::vector<int> a;
long long inv = 0;
int l = 0, r = 0, m;
BIT<int> bit(100000);

void Mo::add(int idx) const {
  if (idx + 1 == l) {
    inv += bit.sum(0, a[idx]);
    --l;
  } else if (idx == r) {
    inv += bit.sum(a[idx] + 1, m);
    ++r;
  }
  bit.add(a[idx], 1);
}

void Mo::del(int idx) const {
  if (idx == l) {
    inv -= bit.sum(0, a[idx]);
    ++l;
  } else if (idx + 1 == r) {
    inv -= bit.sum(a[idx] + 1, m);
    --r;
  }
  bit.add(a[idx], -1);
}

int main() {
  int n, q;
  std::cin >> n >> q;
  a.resize(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::vector<int> tmp(a);
  std::sort(tmp.begin(), tmp.end());
  tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
  m = tmp.size();
  for (int i = 0; i < n; ++i) {
    a[i] = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), a[i]));
  }
  std::vector<int> left(q), right(q);
  for (int i = 0; i < q; ++i) std::cin >> left[i] >> right[i];
  Mo mo(left, right);
  std::vector<long long> ans(q);
  for (int i = 0; i < q; ++i) {
    int idx = mo.process();
    ans[idx] = inv;
  }
  for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
  return 0;
}
