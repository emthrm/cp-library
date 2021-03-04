#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "trie.hpp"

template <size_t Sigma = 26>
struct AhoCorasick : Trie<Sigma + 1> {
  using Trie<Sigma + 1>::Trie;

  std::vector<int> cnt;

  void build(bool heavy = false) {
    is_built = true;
    is_heavy = heavy;
    auto &vertices = this->nodes;
    int n = vertices.size();
    cnt.resize(n);
    for (int i = 0; i < n; ++i) {
      if (heavy) std::sort(vertices[i].tails.begin(), vertices[i].tails.end());
      cnt[i] = vertices[i].tails.size();
    }
    std::queue<int> que;
    for (int i = 0; i < Sigma; ++i) {
      if (vertices[0].nx[i] == -1) {
        vertices[0].nx[i] = 0;
      } else {
        vertices[vertices[0].nx[i]].nx[Sigma] = 0;
        que.emplace(vertices[0].nx[i]);
      }
    }
    while (!que.empty()) {
      const auto &node = vertices[que.front()];
      cnt[que.front()] += cnt[node.nx[Sigma]];
      que.pop();
      for (int i = 0; i < Sigma; ++i) {
        if (node.nx[i] == -1) continue;
        int on_failure = node.nx[Sigma];
        while (vertices[on_failure].nx[i] == -1) on_failure = vertices[on_failure].nx[Sigma];
        vertices[node.nx[i]].nx[Sigma] = vertices[on_failure].nx[i];
        if (heavy) {
          std::vector<int> &ver = vertices[node.nx[i]].tails, tmp;
          std::set_union(ver.begin(), ver.end(), vertices[vertices[on_failure].nx[i]].tails.begin(), vertices[vertices[on_failure].nx[i]].tails.end(), std::back_inserter(tmp));
          ver.resize(tmp.size());
          std::copy(tmp.begin(), tmp.end(), ver.begin());
        }
        que.emplace(node.nx[i]);
      }
    }
  }

  int move(char c, int pos) const {
    // assert(is_built);
    int now = this->convert(c);
    while (this->nodes[pos].nx[now] == -1) pos = this->nodes[pos].nx[Sigma];
    return pos = this->nodes[pos].nx[now];
  }

  int match(const std::string &t, int pos = 0) const {
    assert(is_built);
    int total = 0;
    for (char c : t) {
      pos = move(c, pos);
      total += cnt[pos];
    }
    return total;
  }

  std::map<int, int> match_heavy(const std::string &t, int pos = 0) const {
    assert(is_built && is_heavy);
    std::map<int, int> mp;
    for (char c : t) {
      pos = move(c, pos);
      for (int e : this->nodes[pos].tails) ++mp[e];
    }
    return mp;
  }

private:
  bool is_built = false, is_heavy = false;
};
