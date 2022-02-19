#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "./trie.hpp"

template <size_t Sigma = 26>
struct AhoCorasick : Trie<Sigma + 1> {
  using Trie<Sigma + 1>::Trie;

  std::vector<int> nums;

  void build(const bool is_full_ver_ = false) {
    is_full_ver = is_full_ver_;
    auto& vertices = this->nodes;
    const int n = vertices.size();
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
      if (is_full_ver) {
        std::sort(vertices[i].tails.begin(), vertices[i].tails.end());
      }
      nums[i] = vertices[i].tails.size();
    }
    std::queue<int> que;
    for (int i = 0; i < Sigma; ++i) {
      if (vertices.front().nxt[i] == -1) {
        vertices.front().nxt[i] = 0;
      } else {
        vertices[vertices.front().nxt[i]].nxt[Sigma] = 0;
        que.emplace(vertices.front().nxt[i]);
      }
    }
    while (!que.empty()) {
      const auto& node = vertices[que.front()];
      nums[que.front()] += nums[node.nxt[Sigma]];
      que.pop();
      for (int i = 0; i < Sigma; ++i) {
        if (node.nxt[i] == -1) continue;
        int on_failure = node.nxt[Sigma];
        while (vertices[on_failure].nxt[i] == -1) {
          on_failure = vertices[on_failure].nxt[Sigma];
        }
        vertices[node.nxt[i]].nxt[Sigma] = vertices[on_failure].nxt[i];
        if (is_full_ver) {
          std::vector<int>& ids = vertices[node.nxt[i]].tails;
          std::vector<int> tmp;
          std::set_union(ids.begin(), ids.end(),
                         vertices[vertices[on_failure].nxt[i]].tails.begin(),
                         vertices[vertices[on_failure].nxt[i]].tails.end(),
                         std::back_inserter(tmp));
          ids.resize(tmp.size());
          std::copy(tmp.begin(), tmp.end(), ids.begin());
        }
        que.emplace(node.nxt[i]);
      }
    }
  }

  int move(char c, int pos) const {
    const int c_int = this->convert(c);
    while (this->nodes[pos].nxt[c_int] == -1) pos = this->nodes[pos].nxt[Sigma];
    return pos = this->nodes[pos].nxt[c_int];
  }

  int match(const std::string& t, int pos = 0) const {
    int total = 0;
    for (const char c : t) {
      pos = move(c, pos);
      total += nums[pos];
    }
    return total;
  }

  std::map<int, int> match_fully(const std::string& t, int pos = 0) const {
    assert(is_full_ver);
    std::map<int, int> mp;
    for (const char c : t) {
      pos = move(c, pos);
      for (const int id : this->nodes[pos].tails) ++mp[id];
    }
    return mp;
  }

 private:
  bool is_full_ver = false;
};
