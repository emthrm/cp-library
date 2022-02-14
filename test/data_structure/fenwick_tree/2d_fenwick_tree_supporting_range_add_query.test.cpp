/*
 * @brief データ構造/Fenwick tree/区間加算クエリ対応2次元 Fenwick tree
 */
#define PROBLEM "https://yukicoder.me/problems/no/1490"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../../data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp"

int main() {
  int h, w, n, m;
  std::cin >> h >> w >> n >> m;
  std::vector<int> t(n), u(n), l(n), r(n), a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i] >> u[i] >> l[i] >> r[i] >> a[i];
    --t[i]; --u[i];
    --l[i]; --r[i];
  }
  FenwickTree2DSupportingRangeAddQuery<long long> bit(h, w);
  while (m--) {
    int x, y, b, c;
    std::cin >> x >> y >> b >> c;
    --x; --y;
    bit.add(std::max(x - b, 0), std::max(y - b, 0),
            std::min(x + b, h - 1), std::min(y + b, w - 1), c);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += bit.sum(t[i], l[i], u[i], r[i]) < a[i];
  }
  std::cout << ans << '\n';
  return 0;
}
