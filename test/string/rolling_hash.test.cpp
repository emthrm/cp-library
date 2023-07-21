/*
 * @title 文字列/rolling hash
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc141/tasks/abc141_e
 */

#include <iostream>
#include <set>
#include <string>

#include "emthrm/string/rolling_hash.hpp"

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  emthrm::RollingHash<> rolling_hash(s);
  for (int len = n - 1; len >= 1; --len) {
    std::set<std::int64_t> hashes;
    for (int i = len; i + len <= n; ++i) {
      hashes.emplace(rolling_hash.get(i - len, i));
      if (hashes.contains(rolling_hash.get(i, i + len))) {
        std::cout << len << '\n';
        return 0;
      }
    }
  }
  std::cout << 0 << '\n';
  return 0;
}
