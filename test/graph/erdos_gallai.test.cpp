/*
 * @brief グラフ/エルデシュ・ガライの定理
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/yahoo-procon2018-qual/tasks/yahoo_procon2018_qual_e"

#include <algorithm>
#include <iostream>
#include <vector>
#include "../../graph/erdos_gallai.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> d(n);
  for (int i = 0; i < n; ++i) std::cin >> d[i];
  if (erdos_gallai(d)) {
    std::cout << "YES\n";
    return 0;
  }
  ++(*std::min_element(d.begin(), d.end()));
  std::cout << (erdos_gallai(d) ? "NO\n" : "ABSOLUTELY NO\n");
  return 0;
}
