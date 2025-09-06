/*
 * @title 文字列/Aho–Corasick algorithm
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/aho_corasick
 */

#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "emthrm/string/aho-corasick.hpp"

int main() {
  int n;
  std::cin >> n;
  emthrm::AhoCorasick aho_corasick;
  std::vector<int> v(n);
  for (const int i : std::views::iota(0, n)) {
    std::string s;
    std::cin >> s;
    aho_corasick.add(s, i);
    v[i] = aho_corasick.find(s);
  }
  const int ans = std::ranges::ssize(aho_corasick.nodes);
  std::vector<int> p(ans, -1);
  for (const int i : std::views::iota(0, ans)) {
    for (const int nxt : aho_corasick.nodes[i].nxt) {
      if (nxt != -1) p[nxt] = i;
    }
  }
  aho_corasick.build();
  std::cout << ans << '\n';
  for (const int i : std::views::iota(1, ans)) {
    std::cout << p[i] << ' ' << aho_corasick.nodes[i].nxt.back() << '\n';
  }
  for (const int i : std::views::iota(0, n)) {
    std::cout << v[i] << " \n"[i + 1 == n];
  }
  return 0;
}
