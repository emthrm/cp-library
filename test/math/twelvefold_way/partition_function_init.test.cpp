/*
 * @brief 数学/写像12相/分割数
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/twelvefold_way/partition_function_init.hpp"

int main() {
  ModInt::set_mod(1000000007);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a, b;
  int killa = 0, killb = 0, same = 1;
  int now;
  std::cin >> now;
  killa += now;
  for (int i = 1; i < n; ++i) {
    int tmp;
    std::cin >> tmp;
    killa += tmp;
    if (tmp == now) {
      ++same;
    } else {
      a.emplace_back(same);
      same = 1;
    }
    now = tmp;
  }
  a.emplace_back(same);
  std::cin >> now;
  killb += now;
  same = 1;
  for (int i = 1; i < m; ++i) {
    int tmp;
    std::cin >> tmp;
    killb += tmp;
    if (tmp == now) {
      ++same;
    } else {
      b.emplace_back(same);
      same = 1;
    }
    now = tmp;
  }
  b.emplace_back(same);
  std::vector<std::vector<ModInt>> pf = partition_function_init<ModInt>(100, 1000);
  std::vector<std::vector<ModInt>> dpa(a.size() + 1, std::vector<ModInt>(killb + 1, 0));
  for (int j = 0; j <= killb; ++j) {
    dpa[0][j] = 1;
    dpa[1][j] = pf[a[0]][j];
  }
  for (int i = 1; i < a.size(); ++i) for (int j = 0; j <= killb; ++j) {
    for (int k = 0; k <= j; ++k) {
      dpa[i + 1][j] += dpa[i][j - k] * pf[a[i]][k];
    }
  }
  std::vector<std::vector<ModInt>> dpb(b.size() + 1, std::vector<ModInt>(killa + 1, 0));
  for (int j = 0; j <= killa; ++j) {
    dpb[0][j] = 1;
    dpb[1][j] = pf[b[0]][j];
  }
  for (int i = 1; i < b.size(); ++i) for (int j = 0; j <= killa; ++j) {
    for (int k = 0; k <= j; ++k) {
      dpb[i + 1][j] += dpb[i][j - k] * pf[b[i]][k];
    }
  }
  std::cout << dpa[a.size()][killb] * dpb[b.size()][killa] << '\n';
  return 0;
}
