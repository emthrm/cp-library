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
    \ <string>\r\n#include <vector>\r\n\r\n#line 3 \"string/trie.hpp\"\n#include <functional>\r\
    \n#line 6 \"string/trie.hpp\"\n\r\ntemplate <size_t Sigma = 26>\r\nstruct Trie\
    \ {\r\n  struct Node {\r\n    char c;\r\n    int nxt[Sigma];\r\n    std::vector<int>\
    \ tails;\r\n    explicit Node(const char c) : c(c) { std::fill(nxt, nxt + Sigma,\
    \ -1); }\r\n  };\r\n\r\n  const std::function<int(const char)> convert;\r\n  std::vector<Node>\
    \ nodes;\r\n\r\n  explicit Trie(const std::function<int(const char)> convert =\r\
    \n                    [](const char c) -> int { return c - 'a'; })\r\n      :\
    \ convert(convert) { nodes.emplace_back('$'); }\r\n\r\n  void add(const std::string&\
    \ s, const int id = -1, int pos = 0) {\r\n    for (const char c : s) {\r\n   \
    \   const int c_int = convert(c);\r\n      if (nodes[pos].nxt[c_int] == -1) {\r\
    \n        const int nxt_pos = nodes.size();\r\n        nodes[pos].nxt[c_int] =\
    \ nxt_pos;\r\n        nodes.emplace_back(c);\r\n        pos = nxt_pos;\r\n   \
    \   } else {\r\n        pos = nodes[pos].nxt[c_int];\r\n      }\r\n    }\r\n \
    \   nodes[pos].tails.emplace_back(id);\r\n  }\r\n\r\n  int find(const std::string&\
    \ t, int pos = 0) const {\r\n    for (const char c : t) {\r\n      const int c_int\
    \ = convert(c);\r\n      if (nodes[pos].nxt[c_int] == -1) return -1;\r\n     \
    \ pos = nodes[pos].nxt[c_int];\r\n    }\r\n    return pos;\r\n  }\r\n};\r\n#line\
    \ 11 \"string/aho-corasick.hpp\"\n\r\ntemplate <size_t Sigma = 26>\r\nstruct AhoCorasick\
    \ : Trie<Sigma + 1> {\r\n  using Trie<Sigma + 1>::Trie;\r\n\r\n  std::vector<int>\
    \ nums;\r\n\r\n  void build(const bool is_full_ver_ = false) {\r\n    is_full_ver\
    \ = is_full_ver_;\r\n    auto& vertices = this->nodes;\r\n    const int n = vertices.size();\r\
    \n    nums.resize(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (is_full_ver)\
    \ {\r\n        std::sort(vertices[i].tails.begin(), vertices[i].tails.end());\r\
    \n      }\r\n      nums[i] = vertices[i].tails.size();\r\n    }\r\n    std::queue<int>\
    \ que;\r\n    for (int i = 0; i < Sigma; ++i) {\r\n      if (vertices.front().nxt[i]\
    \ == -1) {\r\n        vertices.front().nxt[i] = 0;\r\n      } else {\r\n     \
    \   vertices[vertices.front().nxt[i]].nxt[Sigma] = 0;\r\n        que.emplace(vertices.front().nxt[i]);\r\
    \n      }\r\n    }\r\n    while (!que.empty()) {\r\n      const auto& node = vertices[que.front()];\r\
    \n      nums[que.front()] += nums[node.nxt[Sigma]];\r\n      que.pop();\r\n  \
    \    for (int i = 0; i < Sigma; ++i) {\r\n        if (node.nxt[i] == -1) continue;\r\
    \n        int on_failure = node.nxt[Sigma];\r\n        while (vertices[on_failure].nxt[i]\
    \ == -1) {\r\n          on_failure = vertices[on_failure].nxt[Sigma];\r\n    \
    \    }\r\n        vertices[node.nxt[i]].nxt[Sigma] = vertices[on_failure].nxt[i];\r\
    \n        if (is_full_ver) {\r\n          std::vector<int>& ids = vertices[node.nxt[i]].tails;\r\
    \n          std::vector<int> tmp;\r\n          std::set_union(ids.begin(), ids.end(),\r\
    \n                         vertices[vertices[on_failure].nxt[i]].tails.begin(),\r\
    \n                         vertices[vertices[on_failure].nxt[i]].tails.end(),\r\
    \n                         std::back_inserter(tmp));\r\n          ids.resize(tmp.size());\r\
    \n          std::copy(tmp.begin(), tmp.end(), ids.begin());\r\n        }\r\n \
    \       que.emplace(node.nxt[i]);\r\n      }\r\n    }\r\n  }\r\n\r\n  int move(char\
    \ c, int pos) const {\r\n    const int c_int = this->convert(c);\r\n    while\
    \ (this->nodes[pos].nxt[c_int] == -1) pos = this->nodes[pos].nxt[Sigma];\r\n \
    \   return pos = this->nodes[pos].nxt[c_int];\r\n  }\r\n\r\n  int match(const\
    \ std::string& t, int pos = 0) const {\r\n    int total = 0;\r\n    for (const\
    \ char c : t) {\r\n      pos = move(c, pos);\r\n      total += nums[pos];\r\n\
    \    }\r\n    return total;\r\n  }\r\n\r\n  std::map<int, int> match_fully(const\
    \ std::string& t, int pos = 0) const {\r\n    assert(is_full_ver);\r\n    std::map<int,\
    \ int> mp;\r\n    for (const char c : t) {\r\n      pos = move(c, pos);\r\n  \
    \    for (const int id : this->nodes[pos].tails) ++mp[id];\r\n    }\r\n    return\
    \ mp;\r\n  }\r\n\r\n private:\r\n  bool is_full_ver = false;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <iterator>\r\
    \n#include <map>\r\n#include <queue>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\n#include \"trie.hpp\"\r\n\r\ntemplate <size_t Sigma = 26>\r\nstruct AhoCorasick\
    \ : Trie<Sigma + 1> {\r\n  using Trie<Sigma + 1>::Trie;\r\n\r\n  std::vector<int>\
    \ nums;\r\n\r\n  void build(const bool is_full_ver_ = false) {\r\n    is_full_ver\
    \ = is_full_ver_;\r\n    auto& vertices = this->nodes;\r\n    const int n = vertices.size();\r\
    \n    nums.resize(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (is_full_ver)\
    \ {\r\n        std::sort(vertices[i].tails.begin(), vertices[i].tails.end());\r\
    \n      }\r\n      nums[i] = vertices[i].tails.size();\r\n    }\r\n    std::queue<int>\
    \ que;\r\n    for (int i = 0; i < Sigma; ++i) {\r\n      if (vertices.front().nxt[i]\
    \ == -1) {\r\n        vertices.front().nxt[i] = 0;\r\n      } else {\r\n     \
    \   vertices[vertices.front().nxt[i]].nxt[Sigma] = 0;\r\n        que.emplace(vertices.front().nxt[i]);\r\
    \n      }\r\n    }\r\n    while (!que.empty()) {\r\n      const auto& node = vertices[que.front()];\r\
    \n      nums[que.front()] += nums[node.nxt[Sigma]];\r\n      que.pop();\r\n  \
    \    for (int i = 0; i < Sigma; ++i) {\r\n        if (node.nxt[i] == -1) continue;\r\
    \n        int on_failure = node.nxt[Sigma];\r\n        while (vertices[on_failure].nxt[i]\
    \ == -1) {\r\n          on_failure = vertices[on_failure].nxt[Sigma];\r\n    \
    \    }\r\n        vertices[node.nxt[i]].nxt[Sigma] = vertices[on_failure].nxt[i];\r\
    \n        if (is_full_ver) {\r\n          std::vector<int>& ids = vertices[node.nxt[i]].tails;\r\
    \n          std::vector<int> tmp;\r\n          std::set_union(ids.begin(), ids.end(),\r\
    \n                         vertices[vertices[on_failure].nxt[i]].tails.begin(),\r\
    \n                         vertices[vertices[on_failure].nxt[i]].tails.end(),\r\
    \n                         std::back_inserter(tmp));\r\n          ids.resize(tmp.size());\r\
    \n          std::copy(tmp.begin(), tmp.end(), ids.begin());\r\n        }\r\n \
    \       que.emplace(node.nxt[i]);\r\n      }\r\n    }\r\n  }\r\n\r\n  int move(char\
    \ c, int pos) const {\r\n    const int c_int = this->convert(c);\r\n    while\
    \ (this->nodes[pos].nxt[c_int] == -1) pos = this->nodes[pos].nxt[Sigma];\r\n \
    \   return pos = this->nodes[pos].nxt[c_int];\r\n  }\r\n\r\n  int match(const\
    \ std::string& t, int pos = 0) const {\r\n    int total = 0;\r\n    for (const\
    \ char c : t) {\r\n      pos = move(c, pos);\r\n      total += nums[pos];\r\n\
    \    }\r\n    return total;\r\n  }\r\n\r\n  std::map<int, int> match_fully(const\
    \ std::string& t, int pos = 0) const {\r\n    assert(is_full_ver);\r\n    std::map<int,\
    \ int> mp;\r\n    for (const char c : t) {\r\n      pos = move(c, pos);\r\n  \
    \    for (const int id : this->nodes[pos].tails) ++mp[id];\r\n    }\r\n    return\
    \ mp;\r\n  }\r\n\r\n private:\r\n  bool is_full_ver = false;\r\n};\r\n"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
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
|`AhoCorasick<σ = 26>(convert)`|エイホ-コラシック法を考える．||
|`nums[i]`|$i$番目のノードが保有する文字列の数||
|`build(完全版か? = false)`|オートマトンを構築する．||
|`move(c, pos)`|$\mathrm{pos}$ 番目のノードを起点としたときに文字 $c$ と対応するノードのインデックス||
|`match(t, pos = 0)`|$\mathrm{pos}$ 番目のノードを起点としたときに文字列 $T$ とマッチした回数||
|`match_fully(t, pos = 0)`|$\mathrm{pos}$ 番目のノードを起点としたとき，文字列 $T$ と追加したそれぞれの文字列がマッチした回数|完全版のみ|


## 参考

- https://naoya-2.hatenadiary.org/entry/20090405/aho_corasick
- https://ei1333.github.io/luzhiled/snippets/string/aho-corasick.html
- https://github.com/beet-aizu/library/blob/02578ddfa9d2a46e3c724df82e84797dd41eabac/string/ahocorasick.cpp


## Verified

https://yukicoder.me/submissions/575927
