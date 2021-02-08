#pragma once
#include <cstring>
#include <string>
#include <vector>

template <size_t char_sz = 26>
struct Trie {
  struct Node {
    char c;
    int nx[char_sz];
    std::vector<int> tails;
    Node(char c) : c(c) { std::memset(nx, -1, sizeof(nx)); }
  };

  std::vector<Node> nodes;

  Trie(const char basis = 'a') : basis(basis) { nodes.emplace_back('$'); }

  void add(const std::string &s, int id = -1, int pos = 0) {
    for (char c : s) {
      int now = convert(c);
      if (nodes[pos].nx[now] == -1) {
        int nx_pos = nodes.size();
        nodes[pos].nx[now] = nx_pos;
        nodes.emplace_back(c);
        pos = nx_pos;
      } else {
        pos = nodes[pos].nx[now];
      }
    }
    nodes[pos].tails.emplace_back(id);
  }

  int find(const std::string &t, int pos = 0) const {
    for (char c : t) {
      int now = convert(c);
      if (nodes[pos].nx[now] == -1) return -1;
      pos = nodes[pos].nx[now];
    }
    return pos;
  }

  int convert(char c) const { return c - basis; }

private:
  const char basis;
};
