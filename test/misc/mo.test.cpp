/*
 * @title その他/Mo's algorithm
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "emthrm/data_structure/fenwick_tree/fenwick_tree.hpp"
#include "emthrm/misc/mo.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto& a_i : a) {
    std::cin >> a_i;
  }
  std::vector<int> tmp = a;
  std::ranges::sort(tmp);
  tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
  const int m = tmp.size();
  for (auto& a_i : a) {
    a_i = std::distance(tmp.begin(), std::ranges::lower_bound(tmp, a_i));
  }
  std::vector<int> ls(q), rs(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> ls[i] >> rs[i];
  }
  long long inv = 0;
  emthrm::FenwickTree<int> bit(m);
  emthrm::Mo mo(
      ls, rs,
      [&a, &inv, &bit](const int idx, const int, const int) -> void {
        inv += bit.sum(0, a[idx]);
        bit.add(a[idx], 1);
      },
      [&a, m, &inv, &bit](const int idx, const int, const int) -> void {
        inv += bit.sum(a[idx] + 1, m);
        bit.add(a[idx], 1);
      },
      [&a, &inv, &bit](const int idx, const int, const int) -> void {
        inv -= bit.sum(0, a[idx]);
        bit.add(a[idx], -1);
      },
      [&a, m, &inv, &bit](const int idx, const int, const int) -> void {
        inv -= bit.sum(a[idx] + 1, m);
        bit.add(a[idx], -1);
      });
  std::vector<long long> ans(q);
  for (int i = 0; i < q; ++i) {
    const int idx = mo.process();
    ans[idx] = inv;
  }
  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
