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
    #include <utility>\r\n\r\ntemplate <int B = 32, typename T = int>\r\nstruct BinaryTrie\
    \ {\r\n  struct Node {\r\n    Node *nxt[2];\r\n    int child;\r\n    Node() :\
    \ nxt{nullptr, nullptr}, child(0) {}\r\n  };\r\n\r\n  Node *root;\r\n\r\n  BinaryTrie()\
    \ : root(nullptr) {}\r\n  ~BinaryTrie() { if (root) free(&root); }\r\n\r\n  void\
    \ clear() {\r\n    if (root) {\r\n      free(&root);\r\n      root = nullptr;\r\
    \n    }\r\n  }\r\n\r\n  bool empty() const { return !root; }\r\n\r\n  int size()\
    \ const { return root ? root->child : 0; }\r\n\r\n  void erase(const T &x) {\r\
    \n    if (root) erase(&root, x, B - 1);\r\n  }\r\n\r\n  Node* find(const T &x)\
    \ const {\r\n    if (!root) return nullptr;\r\n    Node *node = root;\r\n    for\
    \ (int b = B - 1; b >= 0; --b) {\r\n      bool digit = x >> b & 1;\r\n      if\
    \ (!node->nxt[digit]) return nullptr;\r\n      node = node->nxt[digit];\r\n  \
    \  }\r\n    return node;\r\n  }\r\n\r\n  std::pair<Node*, T> operator[](const\
    \ int n) const { return find_nth(n, 0); }\r\n\r\n  std::pair<Node*, T> find_nth(int\
    \ n, const T &x) const {\r\n    assert(0 <= n && n < size());\r\n    Node *node\
    \ = root;\r\n    T res = 0;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n    \
    \  bool digit = x >> b & 1;\r\n      int l_child = node->nxt[digit] ? node->nxt[digit]->child\
    \ : 0;\r\n      if (n >= l_child) {\r\n        n -= l_child;\r\n        digit\
    \ = !digit;\r\n      }\r\n      node = node->nxt[digit];\r\n      if (digit) res\
    \ |= static_cast<T>(1) << b;\r\n    }\r\n    return {node, res};\r\n  }\r\n\r\n\
    \  Node* insert(const T &x) {\r\n    if (!root) root = new Node();\r\n    Node\
    \ *node = root;\r\n    ++node->child;\r\n    for (int b = B - 1; b >= 0; --b)\
    \ {\r\n      bool digit = x >> b & 1;\r\n      if (!node->nxt[digit]) node->nxt[digit]\
    \ = new Node();\r\n      node = node->nxt[digit];\r\n      ++node->child;\r\n\
    \    }\r\n    return node;\r\n  }\r\n\r\n  int less_than(const T &x) const {\r\
    \n    if (!root) return 0;\r\n    Node *node = root;\r\n    int res = 0;\r\n \
    \   for (int b = B - 1; b >= 0; --b) {\r\n      bool digit = x >> b & 1;\r\n \
    \     if (digit && node->nxt[0]) res += node->nxt[0]->child;\r\n      node = node->nxt[digit];\r\
    \n      if (!node) return res;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int\
    \ count(const T &l, const T &r) const { return less_than(r) - less_than(l); }\r\
    \n\r\n  int count(const T &x) const {\r\n    auto ptr = find(x);\r\n    return\
    \ ptr ? ptr->child : 0;\r\n  }\r\n\r\n  std::pair<Node*, T> lower_bound(const\
    \ T &x) const {\r\n    int lt = less_than(x);\r\n    return lt == size() ? std::make_pair(static_cast<Node*>(nullptr),\
    \ -1) : (*this)[lt];\r\n  }\r\n\r\n  std::pair<Node*, T> upper_bound(const T &x)\
    \ const { return lower_bound(x + 1); }\r\n\r\n  std::pair<Node*, T> max_element(const\
    \ T &x = 0) const {\r\n    return min_element(~x);\r\n  }\r\n\r\n  std::pair<Node*,\
    \ T> min_element(const T &x = 0) const {\r\n    assert(root);\r\n    Node *node\
    \ = root;\r\n    T res = 0;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n    \
    \  bool digit = x >> b & 1;\r\n      if (!node->nxt[digit]) digit = !digit;\r\n\
    \      node = node->nxt[digit];\r\n      if (digit) res |= static_cast<T>(1) <<\
    \ b;\r\n    }\r\n    return {node, res};\r\n  }\r\n\r\nprivate:\r\n  void free(Node\
    \ **node) {\r\n    for (int i = 0; i < 2; ++i) {\r\n      if ((*node)->nxt[i])\
    \ free(&(*node)->nxt[i]);\r\n    }\r\n    delete *node;\r\n  }\r\n\r\n  void erase(Node\
    \ **node, const T &x, int b) {\r\n    if (b == -1) {\r\n      if (--(*node)->child\
    \ == 0) {\r\n        delete *node;\r\n        *node = nullptr;\r\n      }\r\n\
    \      return;\r\n    }\r\n    bool digit = x >> b & 1;\r\n    if (!(*node)->nxt[digit])\
    \ return;\r\n    (*node)->child -= (*node)->nxt[digit]->child;\r\n    erase(&(*node)->nxt[digit],\
    \ x, b - 1);\r\n    if ((*node)->nxt[digit]) {\r\n      (*node)->child += (*node)->nxt[digit]->child;\r\
    \n    } else if ((*node)->child == 0) {\r\n      delete *node;\r\n      *node\
    \ = nullptr;\r\n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <utility>\r\n\r\ntemplate\
    \ <int B = 32, typename T = int>\r\nstruct BinaryTrie {\r\n  struct Node {\r\n\
    \    Node *nxt[2];\r\n    int child;\r\n    Node() : nxt{nullptr, nullptr}, child(0)\
    \ {}\r\n  };\r\n\r\n  Node *root;\r\n\r\n  BinaryTrie() : root(nullptr) {}\r\n\
    \  ~BinaryTrie() { if (root) free(&root); }\r\n\r\n  void clear() {\r\n    if\
    \ (root) {\r\n      free(&root);\r\n      root = nullptr;\r\n    }\r\n  }\r\n\r\
    \n  bool empty() const { return !root; }\r\n\r\n  int size() const { return root\
    \ ? root->child : 0; }\r\n\r\n  void erase(const T &x) {\r\n    if (root) erase(&root,\
    \ x, B - 1);\r\n  }\r\n\r\n  Node* find(const T &x) const {\r\n    if (!root)\
    \ return nullptr;\r\n    Node *node = root;\r\n    for (int b = B - 1; b >= 0;\
    \ --b) {\r\n      bool digit = x >> b & 1;\r\n      if (!node->nxt[digit]) return\
    \ nullptr;\r\n      node = node->nxt[digit];\r\n    }\r\n    return node;\r\n\
    \  }\r\n\r\n  std::pair<Node*, T> operator[](const int n) const { return find_nth(n,\
    \ 0); }\r\n\r\n  std::pair<Node*, T> find_nth(int n, const T &x) const {\r\n \
    \   assert(0 <= n && n < size());\r\n    Node *node = root;\r\n    T res = 0;\r\
    \n    for (int b = B - 1; b >= 0; --b) {\r\n      bool digit = x >> b & 1;\r\n\
    \      int l_child = node->nxt[digit] ? node->nxt[digit]->child : 0;\r\n     \
    \ if (n >= l_child) {\r\n        n -= l_child;\r\n        digit = !digit;\r\n\
    \      }\r\n      node = node->nxt[digit];\r\n      if (digit) res |= static_cast<T>(1)\
    \ << b;\r\n    }\r\n    return {node, res};\r\n  }\r\n\r\n  Node* insert(const\
    \ T &x) {\r\n    if (!root) root = new Node();\r\n    Node *node = root;\r\n \
    \   ++node->child;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n      bool digit\
    \ = x >> b & 1;\r\n      if (!node->nxt[digit]) node->nxt[digit] = new Node();\r\
    \n      node = node->nxt[digit];\r\n      ++node->child;\r\n    }\r\n    return\
    \ node;\r\n  }\r\n\r\n  int less_than(const T &x) const {\r\n    if (!root) return\
    \ 0;\r\n    Node *node = root;\r\n    int res = 0;\r\n    for (int b = B - 1;\
    \ b >= 0; --b) {\r\n      bool digit = x >> b & 1;\r\n      if (digit && node->nxt[0])\
    \ res += node->nxt[0]->child;\r\n      node = node->nxt[digit];\r\n      if (!node)\
    \ return res;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int count(const T &l,\
    \ const T &r) const { return less_than(r) - less_than(l); }\r\n\r\n  int count(const\
    \ T &x) const {\r\n    auto ptr = find(x);\r\n    return ptr ? ptr->child : 0;\r\
    \n  }\r\n\r\n  std::pair<Node*, T> lower_bound(const T &x) const {\r\n    int\
    \ lt = less_than(x);\r\n    return lt == size() ? std::make_pair(static_cast<Node*>(nullptr),\
    \ -1) : (*this)[lt];\r\n  }\r\n\r\n  std::pair<Node*, T> upper_bound(const T &x)\
    \ const { return lower_bound(x + 1); }\r\n\r\n  std::pair<Node*, T> max_element(const\
    \ T &x = 0) const {\r\n    return min_element(~x);\r\n  }\r\n\r\n  std::pair<Node*,\
    \ T> min_element(const T &x = 0) const {\r\n    assert(root);\r\n    Node *node\
    \ = root;\r\n    T res = 0;\r\n    for (int b = B - 1; b >= 0; --b) {\r\n    \
    \  bool digit = x >> b & 1;\r\n      if (!node->nxt[digit]) digit = !digit;\r\n\
    \      node = node->nxt[digit];\r\n      if (digit) res |= static_cast<T>(1) <<\
    \ b;\r\n    }\r\n    return {node, res};\r\n  }\r\n\r\nprivate:\r\n  void free(Node\
    \ **node) {\r\n    for (int i = 0; i < 2; ++i) {\r\n      if ((*node)->nxt[i])\
    \ free(&(*node)->nxt[i]);\r\n    }\r\n    delete *node;\r\n  }\r\n\r\n  void erase(Node\
    \ **node, const T &x, int b) {\r\n    if (b == -1) {\r\n      if (--(*node)->child\
    \ == 0) {\r\n        delete *node;\r\n        *node = nullptr;\r\n      }\r\n\
    \      return;\r\n    }\r\n    bool digit = x >> b & 1;\r\n    if (!(*node)->nxt[digit])\
    \ return;\r\n    (*node)->child -= (*node)->nxt[digit]->child;\r\n    erase(&(*node)->nxt[digit],\
    \ x, b - 1);\r\n    if ((*node)->nxt[digit]) {\r\n      (*node)->child += (*node)->nxt[digit]->child;\r\
    \n    } else if ((*node)->child == 0) {\r\n      delete *node;\r\n      *node\
    \ = nullptr;\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
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
|`BinaryTrie<ビット幅 = 32, T = int>()`|binary trie $S$ を考える．||
|`~BinaryTrie()`|||
|`root`|根のポインタ||
|`clear()`|すべての要素を削除する．||
|`empty()`|$S$ は空集合であるか．||
|`size()`|$\#{S}$||
|`erase(x)`|$x$ を削除する．|存在しない場合は何もしない．|
|`find(x)`|$x$ を指すノード|存在しない場合は `nullptr` を返す．|
|`operator()[n]`|$n$ 番目 (0-based) の要素を指すノードと値||
|`find_nth(n, x)`|$\{s \oplus x \mid s \in S \}$ を考えたときの $n$ 番目 (0-based) の要素を指すノードと値||
|`insert(x)`|$x$ を挿入する．|返り値は $x$ を指すノードである．|
|`less_than(x)`|$\#\{s \in S \mid s < x \}$||
|`count(l, r)`|$\#\{s \in S \mid l \leq x < r \}$||
|`count(x)`|$\#\{s \in S \mid s = x \}$||
|`lower_bound(x)`|$x$ より小さくない最初の要素を指すノードと値|存在しない場合は `{nullptr, -1}` を返す．|
|`upper_bound(x)`|$x$ より大きい最初の要素を指すノードと値|存在しない場合は `{nullptr, -1}` を返す．|
|`max_element(x)`|$\argmax\{s \oplus x \mid s \in S\}$||
|`min_element(x)`|$\argmin\{s \oplus x \mid s \in S\}$||


## 参考

- https://kazuma8128.hatenablog.com/entry/2018/05/06/022654


## ToDo

- 永続 binary trie
  - https://kazuma8128.hatenablog.com/entry/2018/02/17/224151


## Verified

https://judge.yosupo.jp/submission/33239
