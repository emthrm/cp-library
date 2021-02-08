/*
 * @brief 動的計画法/Li Chao tree (最小値)
 */
#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <vector>
#include "../../dp/li_chao_tree.hpp"

int main() {
  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
  int n, q;
  std::cin >> n >> q;
  std::vector<int> query(q), l(n + q), r(n + q), a(n + q), p(q);
  std::vector<long long> b(n + q), xs;
  for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i] >> a[i] >> b[i];
  for (int i = 0; i < q; ++i) {
    std::cin >> query[i];
    if (query[i] == 0) {
      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n + i];
    } else if (query[i] == 1) {
      std::cin >> p[i];
      xs.emplace_back(p[i]);
    }
  }
  if (xs.empty()) return 0;
  LiChaoTree<long long> lct(xs, LINF);
  for (int i = 0; i < n; ++i) lct.add(a[i], b[i], l[i], r[i]);
  for (int i = 0; i < q; ++i) {
    if (query[i] == 0) {
      lct.add(a[n + i], b[n + i], l[n + i], r[n + i]);
    } else if (query[i] == 1) {
      long long ans = lct.query(p[i]);
      if (ans == LINF) {
        std::cout << "INFINITY\n";
      } else {
        std::cout << ans << '\n';
      }
    }
  }
  return 0;
}
