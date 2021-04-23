/*
 * @brief データ構造/Fenwick tree/区間加算クエリ対応2次元 Fenwick tree
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1200/D"

#include <algorithm>
#include <iostream>
#include <vector>
#include "../../../data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp"

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<char>> cf(n, std::vector<char>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) std::cin >> cf[i][j];
  FenwickTree2DSupportingRangeAddQuery<int> bit(n, n);
  for (int i = 0; i < n; ++i) {
    int mn = n, mx = -1;
    for (int j = 0; j < n; ++j) {
      if (cf[i][j] == 'B') {
        if (j < mn) mn = j;
        if (j > mx) mx = j;
      }
    }
    if (mx == -1) {
      bit.add(0, 0, n - 1, n - 1, 1);
      continue;
    }
    if (mx - mn + 1 > k) continue;
    bit.add(std::max(i - k + 1, 0), std::max(mx - k + 1, 0), i, mn, 1);
  }
  for (int j = 0; j < n; ++j) {
    int mn = n, mx = -1;
    for (int i = 0; i < n; ++i) {
      if (cf[i][j] == 'B') {
        if (i < mn) mn = i;
        if (i > mx) mx = i;
      }
    }
    if (mx == -1) {
      bit.add(0, 0, n - 1, n - 1, 1);
      continue;
    }
    if (mx - mn + 1 > k) continue;
    bit.add(std::max(mx - k + 1, 0), std::max(j - k + 1, 0), mn, j, 1);
  }
  int ans = 0;
  for (int i = 0; i + k <= n; ++i) for (int j = 0; j + k <= n; ++j) {
    int sum = bit.sum(i, j, i, j);
    if (sum > ans) ans = sum;
  }
  std::cout << ans << '\n';
  return 0;
}
