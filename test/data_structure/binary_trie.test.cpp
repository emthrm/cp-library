/*
 * @brief データ構造/binary trie
 */
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "../../data_structure/binary_trie.hpp"

int main() {
  BinaryTrie<30> bt;
  int q;
  std::cin >> q;
  while (q--) {
    int type, x;
    std::cin >> type >> x;
    if (type == 0) {
      if (!bt.find(x)) bt.insert(x);
    } else if (type == 1) {
      bt.erase(x);
    } else if (type == 2) {
      std::cout << (bt.min_element(x).second ^ x) << '\n';
    }
  }
  return 0;
}
