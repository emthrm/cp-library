---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: "\u30C8\u30E9\u30A4\u6728 (trie)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho-corasick.test.cpp
    title: "\u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho-corasick.hpp\"\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#include <iterator>\r\n#include <map>\r\n#include <queue>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#line 2 \"string/trie.hpp\"\n#include <cstring>\r\
    \n#line 5 \"string/trie.hpp\"\n\r\ntemplate <size_t char_sz = 26>\r\nstruct Trie\
    \ {\r\n  struct Node {\r\n    char c;\r\n    int nx[char_sz];\r\n    std::vector<int>\
    \ tails;\r\n    Node(char c) : c(c) { std::memset(nx, -1, sizeof(nx)); }\r\n \
    \ };\r\n\r\n  std::vector<Node> nodes;\r\n\r\n  Trie(const char basis = 'a') :\
    \ basis(basis) { nodes.emplace_back('$'); }\r\n\r\n  void add(const std::string\
    \ &s, int id = -1, int pos = 0) {\r\n    for (char c : s) {\r\n      int now =\
    \ convert(c);\r\n      if (nodes[pos].nx[now] == -1) {\r\n        int nx_pos =\
    \ nodes.size();\r\n        nodes[pos].nx[now] = nx_pos;\r\n        nodes.emplace_back(c);\r\
    \n        pos = nx_pos;\r\n      } else {\r\n        pos = nodes[pos].nx[now];\r\
    \n      }\r\n    }\r\n    nodes[pos].tails.emplace_back(id);\r\n  }\r\n\r\n  int\
    \ find(const std::string &t, int pos = 0) const {\r\n    for (char c : t) {\r\n\
    \      int now = convert(c);\r\n      if (nodes[pos].nx[now] == -1) return -1;\r\
    \n      pos = nodes[pos].nx[now];\r\n    }\r\n    return pos;\r\n  }\r\n\r\n \
    \ int convert(char c) const { return c - basis; }\r\n\r\nprivate:\r\n  const char\
    \ basis;\r\n};\r\n#line 10 \"string/aho-corasick.hpp\"\n\r\ntemplate <size_t char_sz\
    \ = 26>\r\nstruct AhoCorasick : Trie<char_sz + 1> {\r\n  using Trie<char_sz +\
    \ 1>::Trie;\r\n\r\n  std::vector<int> cnt;\r\n\r\n  void build(bool heavy = false)\
    \ {\r\n    is_built = true;\r\n    is_heavy = heavy;\r\n    auto &vertices = this->nodes;\r\
    \n    int n = vertices.size();\r\n    cnt.resize(n);\r\n    for (int i = 0; i\
    \ < n; ++i) {\r\n      if (heavy) std::sort(vertices[i].tails.begin(), vertices[i].tails.end());\r\
    \n      cnt[i] = vertices[i].tails.size();\r\n    }\r\n    std::queue<int> que;\r\
    \n    for (int i = 0; i < char_sz; ++i) {\r\n      if (vertices[0].nx[i] == -1)\
    \ {\r\n        vertices[0].nx[i] = 0;\r\n      } else {\r\n        vertices[vertices[0].nx[i]].nx[char_sz]\
    \ = 0;\r\n        que.emplace(vertices[0].nx[i]);\r\n      }\r\n    }\r\n    while\
    \ (!que.empty()) {\r\n      const auto &node = vertices[que.front()];\r\n    \
    \  cnt[que.front()] += cnt[node.nx[char_sz]];\r\n      que.pop();\r\n      for\
    \ (int i = 0; i < char_sz; ++i) {\r\n        if (node.nx[i] == -1) continue;\r\
    \n        int on_failure = node.nx[char_sz];\r\n        while (vertices[on_failure].nx[i]\
    \ == -1) on_failure = vertices[on_failure].nx[char_sz];\r\n        vertices[node.nx[i]].nx[char_sz]\
    \ = vertices[on_failure].nx[i];\r\n        if (heavy) {\r\n          std::vector<int>\
    \ &ver = vertices[node.nx[i]].tails, tmp;\r\n          std::set_union(ver.begin(),\
    \ ver.end(), vertices[vertices[on_failure].nx[i]].tails.begin(), vertices[vertices[on_failure].nx[i]].tails.end(),\
    \ std::back_inserter(tmp));\r\n          ver.resize(tmp.size());\r\n         \
    \ std::copy(tmp.begin(), tmp.end(), ver.begin());\r\n        }\r\n        que.emplace(node.nx[i]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  int move(char c, int pos) const {\r\n    //\
    \ assert(is_built);\r\n    int now = this->convert(c);\r\n    while (this->nodes[pos].nx[now]\
    \ == -1) pos = this->nodes[pos].nx[char_sz];\r\n    return pos = this->nodes[pos].nx[now];\r\
    \n  }\r\n\r\n  int match(const std::string &t, int pos = 0) const {\r\n    assert(is_built);\r\
    \n    int total = 0;\r\n    for (char c : t) {\r\n      pos = move(c, pos);\r\n\
    \      total += cnt[pos];\r\n    }\r\n    return total;\r\n  }\r\n\r\n  std::map<int,\
    \ int> match_heavy(const std::string &t, int pos = 0) const {\r\n    assert(is_built\
    \ && is_heavy);\r\n    std::map<int, int> mp;\r\n    for (char c : t) {\r\n  \
    \    pos = move(c, pos);\r\n      for (int e : this->nodes[pos].tails) ++mp[e];\r\
    \n    }\r\n    return mp;\r\n  }\r\n\r\nprivate:\r\n  bool is_built = false, is_heavy\
    \ = false;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <iterator>\r\
    \n#include <map>\r\n#include <queue>\r\n#include <string>\r\n#include <vector>\r\
    \n#include \"trie.hpp\"\r\n\r\ntemplate <size_t char_sz = 26>\r\nstruct AhoCorasick\
    \ : Trie<char_sz + 1> {\r\n  using Trie<char_sz + 1>::Trie;\r\n\r\n  std::vector<int>\
    \ cnt;\r\n\r\n  void build(bool heavy = false) {\r\n    is_built = true;\r\n \
    \   is_heavy = heavy;\r\n    auto &vertices = this->nodes;\r\n    int n = vertices.size();\r\
    \n    cnt.resize(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (heavy)\
    \ std::sort(vertices[i].tails.begin(), vertices[i].tails.end());\r\n      cnt[i]\
    \ = vertices[i].tails.size();\r\n    }\r\n    std::queue<int> que;\r\n    for\
    \ (int i = 0; i < char_sz; ++i) {\r\n      if (vertices[0].nx[i] == -1) {\r\n\
    \        vertices[0].nx[i] = 0;\r\n      } else {\r\n        vertices[vertices[0].nx[i]].nx[char_sz]\
    \ = 0;\r\n        que.emplace(vertices[0].nx[i]);\r\n      }\r\n    }\r\n    while\
    \ (!que.empty()) {\r\n      const auto &node = vertices[que.front()];\r\n    \
    \  cnt[que.front()] += cnt[node.nx[char_sz]];\r\n      que.pop();\r\n      for\
    \ (int i = 0; i < char_sz; ++i) {\r\n        if (node.nx[i] == -1) continue;\r\
    \n        int on_failure = node.nx[char_sz];\r\n        while (vertices[on_failure].nx[i]\
    \ == -1) on_failure = vertices[on_failure].nx[char_sz];\r\n        vertices[node.nx[i]].nx[char_sz]\
    \ = vertices[on_failure].nx[i];\r\n        if (heavy) {\r\n          std::vector<int>\
    \ &ver = vertices[node.nx[i]].tails, tmp;\r\n          std::set_union(ver.begin(),\
    \ ver.end(), vertices[vertices[on_failure].nx[i]].tails.begin(), vertices[vertices[on_failure].nx[i]].tails.end(),\
    \ std::back_inserter(tmp));\r\n          ver.resize(tmp.size());\r\n         \
    \ std::copy(tmp.begin(), tmp.end(), ver.begin());\r\n        }\r\n        que.emplace(node.nx[i]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  int move(char c, int pos) const {\r\n    //\
    \ assert(is_built);\r\n    int now = this->convert(c);\r\n    while (this->nodes[pos].nx[now]\
    \ == -1) pos = this->nodes[pos].nx[char_sz];\r\n    return pos = this->nodes[pos].nx[now];\r\
    \n  }\r\n\r\n  int match(const std::string &t, int pos = 0) const {\r\n    assert(is_built);\r\
    \n    int total = 0;\r\n    for (char c : t) {\r\n      pos = move(c, pos);\r\n\
    \      total += cnt[pos];\r\n    }\r\n    return total;\r\n  }\r\n\r\n  std::map<int,\
    \ int> match_heavy(const std::string &t, int pos = 0) const {\r\n    assert(is_built\
    \ && is_heavy);\r\n    std::map<int, int> mp;\r\n    for (char c : t) {\r\n  \
    \    pos = move(c, pos);\r\n      for (int e : this->nodes[pos].tails) ++mp[e];\r\
    \n    }\r\n    return mp;\r\n  }\r\n\r\nprivate:\r\n  bool is_built = false, is_heavy\
    \ = false;\r\n};\r\n"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho-corasick.test.cpp
documentation_of: string/aho-corasick.hpp
layout: document
title: "\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5 (Aho-Corasick algorithm)"
---

トライ木を用いてパターンマッチングを行うアルゴリズムである．


## 時間計算量

検索する文字列の長さを $N$, トライ木に追加する文字列の長さを $M$ とおくと $\langle O(\sum{M}), O(N + \sum{M}) \rangle$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`AhoCorasick<種類数 = 26>(基準 = 'a')`|エイホ-コラシック法を考える．||
|`cnt[i]`|ノード $i$ が保有する文字列の数||
|`build(重量版か? = false)`|オートマトンを構築する．||
|`move(c, pos)`|ノード $\mathrm{pos}$ から辿った文字 $c$ に対応するノードのインデックス||
|`match(t, pos = 0)`|ノード $\mathrm{pos}$ から見た文字列 $T$ のパターンマッチングの回数||
|`match_heavy(t, pos = 0)`|ノード $\mathrm{pos}$ から見た文字列 $T$ の追加した各文字列におけるパターンマッチングの回数|重量版のみ|


## 参考

- https://naoya-2.hatenadiary.org/entry/20090405/aho_corasick
- https://ei1333.github.io/luzhiled/snippets/string/aho-corasick.html
- https://github.com/beet-aizu/library/blob/master/string/ahocorasick.cpp


## Verified

https://yukicoder.me/submissions/575927
