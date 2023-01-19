#ifndef EMTHRM_STRING_TRIE_HPP_
#define EMTHRM_STRING_TRIE_HPP_

#include <algorithm>
#include <array>
#include <functional>
#include <string>
#include <vector>

namespace emthrm {

template <int Sigma = 26>
struct Trie {
  struct Node {
    char c;
    std::array<int, Sigma> nxt;
    std::vector<int> tails;

    explicit Node(const char c) : c(c) {
      std::fill(nxt.begin(), nxt.end(), -1);
    }
  };

  const std::function<int(const char)> convert;
  std::vector<Node> nodes;

  explicit Trie(const std::function<int(const char)> convert =
                    [](const char c) -> int { return c - 'a'; })
      : convert(convert) { nodes.emplace_back('$'); }

  void add(const std::string& s, const int id = -1, int pos = 0) {
    for (const char c : s) {
      const int c_int = convert(c);
      if (nodes[pos].nxt[c_int] == -1) {
        const int nxt_pos = nodes.size();
        nodes[pos].nxt[c_int] = nxt_pos;
        nodes.emplace_back(c);
        pos = nxt_pos;
      } else {
        pos = nodes[pos].nxt[c_int];
      }
    }
    nodes[pos].tails.emplace_back(id);
  }

  int find(const std::string& t, int pos = 0) const {
    for (const char c : t) {
      const int c_int = convert(c);
      if (nodes[pos].nxt[c_int] == -1) return -1;
      pos = nodes[pos].nxt[c_int];
    }
    return pos;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_STRING_TRIE_HPP_
