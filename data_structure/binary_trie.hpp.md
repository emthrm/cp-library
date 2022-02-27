---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/binary_trie.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/binary_trie.hpp\"\n#include <cassert>\r\n\
    #include <cstdint>\r\n#include <memory>\r\n#include <utility>\r\n\r\ntemplate\
    \ <int B = 32, typename T = std::uint32_t>\r\nstruct BinaryTrie {\r\n  struct\
    \ Node {\r\n    std::shared_ptr<Node> nxt[2];\r\n    int child;\r\n    Node()\
    \ : nxt{nullptr, nullptr}, child(0) {}\r\n  };\r\n\r\n  std::shared_ptr<Node>\
    \ root;\r\n\r\n  BinaryTrie() : root(nullptr) {}\r\n\r\n  void clear() { root.reset();\
    \ }\r\n\r\n  bool empty() const { return !root; }\r\n\r\n  int size() const {\
    \ return root ? root->child : 0; }\r\n\r\n  void erase(const T& x) {\r\n    if\
    \ (root) erase(&root, x, B - 1);\r\n  }\r\n\r\n  std::shared_ptr<Node> find(const\
    \ T& x) const {\r\n    if (!root) return nullptr;\r\n    std::shared_ptr<Node>\
    \ node = root;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n      const bool digit\
    \ = x >> b & 1;\r\n      if (!node->nxt[digit]) return nullptr;\r\n      node\
    \ = node->nxt[digit];\r\n    }\r\n    return node;\r\n  }\r\n\r\n  std::pair<std::shared_ptr<Node>,\
    \ T> operator[](const int n) const {\r\n    return find_nth(n, 0);\r\n  }\r\n\r\
    \n  std::pair<std::shared_ptr<Node>, T> find_nth(int n, const T& x) const {\r\n\
    \    assert(0 <= n && n < size());\r\n    std::shared_ptr<Node> node = root;\r\
    \n    T res = 0;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n      bool digit\
    \ = x >> b & 1;\r\n      const int l_child = (node->nxt[digit] ? node->nxt[digit]->child\
    \ : 0);\r\n      if (n >= l_child) {\r\n        n -= l_child;\r\n        digit\
    \ = !digit;\r\n      }\r\n      node = node->nxt[digit];\r\n      if (digit) res\
    \ |= static_cast<T>(1) << b;\r\n    }\r\n    return {node, res};\r\n  }\r\n\r\n\
    \  std::shared_ptr<Node> insert(const T& x) {\r\n    if (!root) root = std::make_shared<Node>();\r\
    \n    std::shared_ptr<Node> node = root;\r\n    ++node->child;\r\n    for (int\
    \ b = B - 1; b >= 0; --b) {\r\n      const bool digit = x >> b & 1;\r\n      if\
    \ (!node->nxt[digit]) node->nxt[digit] = std::make_shared<Node>();\r\n      node\
    \ = node->nxt[digit];\r\n      ++node->child;\r\n    }\r\n    return node;\r\n\
    \  }\r\n\r\n  int less_than(const T& x) const {\r\n    int res = 0;\r\n    std::shared_ptr<Node>\
    \ node = root;\r\n    for (int b = B - 1; node && b >= 0; --b) {\r\n      const\
    \ bool digit = x >> b & 1;\r\n      if (digit && node->nxt[0]) res += node->nxt[0]->child;\r\
    \n      node = node->nxt[digit];\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int\
    \ count(const T& l, const T& r) const {\r\n    return less_than(r) - less_than(l);\r\
    \n  }\r\n\r\n  int count(const T& x) const {\r\n    const std::shared_ptr<Node>\
    \ ptr = find(x);\r\n    return ptr ? ptr->child : 0;\r\n  }\r\n\r\n  std::pair<std::shared_ptr<Node>,\
    \ T> lower_bound(const T& x) const {\r\n    const int lt = less_than(x);\r\n \
    \   return lt == size() ? std::make_pair(nullptr, -1) : find_nth(lt, 0);\r\n \
    \ }\r\n\r\n  std::pair<std::shared_ptr<Node>, T> upper_bound(const T& x) const\
    \ {\r\n    return lower_bound(x + 1);\r\n  }\r\n\r\n  std::pair<std::shared_ptr<Node>,\
    \ T> max_element(const T& x = 0) const {\r\n    return min_element(~x);\r\n  }\r\
    \n\r\n  std::pair<std::shared_ptr<Node>, T> min_element(const T& x = 0) const\
    \ {\r\n    assert(root);\r\n    std::shared_ptr<Node> node = root;\r\n    T res\
    \ = 0;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n      bool digit = x >> b\
    \ & 1;\r\n      if (!node->nxt[digit]) digit = !digit;\r\n      node = node->nxt[digit];\r\
    \n      if (digit) res |= static_cast<T>(1) << b;\r\n    }\r\n    return {node,\
    \ res};\r\n  }\r\n\r\n private:\r\n  void erase(std::shared_ptr<Node>* node, const\
    \ T& x, int b) {\r\n    if (b == -1) {\r\n      if (--(*node)->child == 0) node->reset();\r\
    \n      return;\r\n    }\r\n    const bool digit = x >> b & 1;\r\n    if (!(*node)->nxt[digit])\
    \ return;\r\n    (*node)->child -= (*node)->nxt[digit]->child;\r\n    erase(&(*node)->nxt[digit],\
    \ x, b - 1);\r\n    if ((*node)->nxt[digit]) {\r\n      (*node)->child += (*node)->nxt[digit]->child;\r\
    \n    } else if ((*node)->child == 0) {\r\n      node->reset();\r\n    }\r\n \
    \ }\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <cstdint>\r\n#include <memory>\r\
    \n#include <utility>\r\n\r\ntemplate <int B = 32, typename T = std::uint32_t>\r\
    \nstruct BinaryTrie {\r\n  struct Node {\r\n    std::shared_ptr<Node> nxt[2];\r\
    \n    int child;\r\n    Node() : nxt{nullptr, nullptr}, child(0) {}\r\n  };\r\n\
    \r\n  std::shared_ptr<Node> root;\r\n\r\n  BinaryTrie() : root(nullptr) {}\r\n\
    \r\n  void clear() { root.reset(); }\r\n\r\n  bool empty() const { return !root;\
    \ }\r\n\r\n  int size() const { return root ? root->child : 0; }\r\n\r\n  void\
    \ erase(const T& x) {\r\n    if (root) erase(&root, x, B - 1);\r\n  }\r\n\r\n\
    \  std::shared_ptr<Node> find(const T& x) const {\r\n    if (!root) return nullptr;\r\
    \n    std::shared_ptr<Node> node = root;\r\n    for (int b = B - 1; b >= 0; --b)\
    \ {\r\n      const bool digit = x >> b & 1;\r\n      if (!node->nxt[digit]) return\
    \ nullptr;\r\n      node = node->nxt[digit];\r\n    }\r\n    return node;\r\n\
    \  }\r\n\r\n  std::pair<std::shared_ptr<Node>, T> operator[](const int n) const\
    \ {\r\n    return find_nth(n, 0);\r\n  }\r\n\r\n  std::pair<std::shared_ptr<Node>,\
    \ T> find_nth(int n, const T& x) const {\r\n    assert(0 <= n && n < size());\r\
    \n    std::shared_ptr<Node> node = root;\r\n    T res = 0;\r\n    for (int b =\
    \ B - 1; b >= 0; --b) {\r\n      bool digit = x >> b & 1;\r\n      const int l_child\
    \ = (node->nxt[digit] ? node->nxt[digit]->child : 0);\r\n      if (n >= l_child)\
    \ {\r\n        n -= l_child;\r\n        digit = !digit;\r\n      }\r\n      node\
    \ = node->nxt[digit];\r\n      if (digit) res |= static_cast<T>(1) << b;\r\n \
    \   }\r\n    return {node, res};\r\n  }\r\n\r\n  std::shared_ptr<Node> insert(const\
    \ T& x) {\r\n    if (!root) root = std::make_shared<Node>();\r\n    std::shared_ptr<Node>\
    \ node = root;\r\n    ++node->child;\r\n    for (int b = B - 1; b >= 0; --b) {\r\
    \n      const bool digit = x >> b & 1;\r\n      if (!node->nxt[digit]) node->nxt[digit]\
    \ = std::make_shared<Node>();\r\n      node = node->nxt[digit];\r\n      ++node->child;\r\
    \n    }\r\n    return node;\r\n  }\r\n\r\n  int less_than(const T& x) const {\r\
    \n    int res = 0;\r\n    std::shared_ptr<Node> node = root;\r\n    for (int b\
    \ = B - 1; node && b >= 0; --b) {\r\n      const bool digit = x >> b & 1;\r\n\
    \      if (digit && node->nxt[0]) res += node->nxt[0]->child;\r\n      node =\
    \ node->nxt[digit];\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int count(const\
    \ T& l, const T& r) const {\r\n    return less_than(r) - less_than(l);\r\n  }\r\
    \n\r\n  int count(const T& x) const {\r\n    const std::shared_ptr<Node> ptr =\
    \ find(x);\r\n    return ptr ? ptr->child : 0;\r\n  }\r\n\r\n  std::pair<std::shared_ptr<Node>,\
    \ T> lower_bound(const T& x) const {\r\n    const int lt = less_than(x);\r\n \
    \   return lt == size() ? std::make_pair(nullptr, -1) : find_nth(lt, 0);\r\n \
    \ }\r\n\r\n  std::pair<std::shared_ptr<Node>, T> upper_bound(const T& x) const\
    \ {\r\n    return lower_bound(x + 1);\r\n  }\r\n\r\n  std::pair<std::shared_ptr<Node>,\
    \ T> max_element(const T& x = 0) const {\r\n    return min_element(~x);\r\n  }\r\
    \n\r\n  std::pair<std::shared_ptr<Node>, T> min_element(const T& x = 0) const\
    \ {\r\n    assert(root);\r\n    std::shared_ptr<Node> node = root;\r\n    T res\
    \ = 0;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n      bool digit = x >> b\
    \ & 1;\r\n      if (!node->nxt[digit]) digit = !digit;\r\n      node = node->nxt[digit];\r\
    \n      if (digit) res |= static_cast<T>(1) << b;\r\n    }\r\n    return {node,\
    \ res};\r\n  }\r\n\r\n private:\r\n  void erase(std::shared_ptr<Node>* node, const\
    \ T& x, int b) {\r\n    if (b == -1) {\r\n      if (--(*node)->child == 0) node->reset();\r\
    \n      return;\r\n    }\r\n    const bool digit = x >> b & 1;\r\n    if (!(*node)->nxt[digit])\
    \ return;\r\n    (*node)->child -= (*node)->nxt[digit]->child;\r\n    erase(&(*node)->nxt[digit],\
    \ x, b - 1);\r\n    if ((*node)->nxt[digit]) {\r\n      (*node)->child += (*node)->nxt[digit]->child;\r\
    \n    } else if ((*node)->child == 0) {\r\n      node->reset();\r\n    }\r\n \
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-02-23 16:46:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/binary_trie.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
title: binary trie
---

非負整数を管理する[トライ木](../string/trie.md)である．


## 時間計算量

$O(B)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BinaryTrie<ビット幅 = 32, T = std::uint32_t>()`|binary trie $S$ を考える．||
|`root`|根のポインタ||
|`clear()`|すべての要素を削除する．||
|`empty()`|$S$ は空集合であるか．||
|`size()`|$\lvert S \rvert$||
|`erase(x)`|$x$ を削除する．|存在しないときは何もしない．|
|`find(x)`|$x$ を指すノード|存在しないときは `nullptr` を返す．|
|`operator()[n]`|$n$ 番目 (0-based) の要素を指すノードと値||
|`find_nth(n, x)`|$\lbrace s \oplus x \mid s \in S \rbrace$ を考えたときの $n$ 番目 (0-based) の要素を指すノードと値||
|`insert(x)`|$x$ を挿入する．|返り値は $x$ を指すノードである．|
|`less_than(x)`|$\lvert \lbrace s \in S \mid s < x \rbrace \rvert$||
|`count(l, r)`|$\lvert \lbrace s \in S \mid l \leq x < r \rbrace \rvert$||
|`count(x)`|$\lvert \lbrace s \in S \mid s = x \rbrace \rvert$||
|`lower_bound(x)`|$x$ より小さくない最初の要素を指すノードと値|存在しないときは `{nullptr, -1}` を返す．|
|`upper_bound(x)`|$x$ より大きい最初の要素を指すノードと値|存在しないときは `{nullptr, -1}` を返す．|
|`max_element(x)`|$\mathrm{argmax} \lbrace s \oplus x \mid s \in S \rbrace$||
|`min_element(x)`|$\mathrm{argmin} \lbrace s \oplus x \mid s \in S \rbrace$||


## 参考

- https://kazuma8128.hatenablog.com/entry/2018/05/06/022654


## ToDo

- 永続 binary trie
  - https://kazuma8128.hatenablog.com/entry/2018/02/17/224151
- a powerful representation of integer sets
  - https://codeforces.com/blog/entry/83969
  - https://twitter.com/keijak/status/1488232021394702336


## Verified

https://judge.yosupo.jp/submission/33239
