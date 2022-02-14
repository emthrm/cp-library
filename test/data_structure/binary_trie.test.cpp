/*
 * @brief データ構造/binary trie
 */
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>

#include "../../data_structure/binary_trie.hpp"

int main() {
  constexpr int B = 30;
  BinaryTrie<B> binary_trie;
  int q;
  std::cin >> q;
  while (q--) {
    int type, x;
    std::cin >> type >> x;
    if (type == 0) {
      if (!binary_trie.find(x)) binary_trie.insert(x);
    } else if (type == 1) {
      binary_trie.erase(x);
    } else if (type == 2) {
      std::cout << (binary_trie.min_element(x).second ^ x) << '\n';
    }
  }
  return 0;
}
