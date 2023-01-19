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
  bundledCode: "#line 1 \"include/emthrm/data_structure/binary_trie.hpp\"\n\n\n\n\
    #include <cassert>\n#include <cstdint>\n#include <memory>\n#include <utility>\n\
    \nnamespace emthrm {\n\ntemplate <int B = 32, typename T = std::uint32_t>\nstruct\
    \ BinaryTrie {\n  struct Node {\n    std::shared_ptr<Node> nxt[2];\n    int child;\n\
    \    Node() : nxt{nullptr, nullptr}, child(0) {}\n  };\n\n  std::shared_ptr<Node>\
    \ root;\n\n  BinaryTrie() : root(nullptr) {}\n\n  void clear() { root.reset();\
    \ }\n\n  bool empty() const { return !root; }\n\n  int size() const { return root\
    \ ? root->child : 0; }\n\n  void erase(const T& x) {\n    if (root) erase(&root,\
    \ x, B - 1);\n  }\n\n  std::shared_ptr<Node> find(const T& x) const {\n    if\
    \ (!root) return nullptr;\n    std::shared_ptr<Node> node = root;\n    for (int\
    \ b = B - 1; b >= 0; --b) {\n      const bool digit = x >> b & 1;\n      if (!node->nxt[digit])\
    \ return nullptr;\n      node = node->nxt[digit];\n    }\n    return node;\n \
    \ }\n\n  std::pair<std::shared_ptr<Node>, T> operator[](const int n) const {\n\
    \    return find_nth(n, 0);\n  }\n\n  std::pair<std::shared_ptr<Node>, T> find_nth(int\
    \ n, const T& x) const {\n    assert(0 <= n && n < size());\n    std::shared_ptr<Node>\
    \ node = root;\n    T res = 0;\n    for (int b = B - 1; b >= 0; --b) {\n     \
    \ bool digit = x >> b & 1;\n      const int l_child = (node->nxt[digit] ? node->nxt[digit]->child\
    \ : 0);\n      if (n >= l_child) {\n        n -= l_child;\n        digit = !digit;\n\
    \      }\n      node = node->nxt[digit];\n      if (digit) res |= static_cast<T>(1)\
    \ << b;\n    }\n    return {node, res};\n  }\n\n  std::shared_ptr<Node> insert(const\
    \ T& x) {\n    if (!root) root = std::make_shared<Node>();\n    std::shared_ptr<Node>\
    \ node = root;\n    ++node->child;\n    for (int b = B - 1; b >= 0; --b) {\n \
    \     const bool digit = x >> b & 1;\n      if (!node->nxt[digit]) node->nxt[digit]\
    \ = std::make_shared<Node>();\n      node = node->nxt[digit];\n      ++node->child;\n\
    \    }\n    return node;\n  }\n\n  int less_than(const T& x) const {\n    int\
    \ res = 0;\n    std::shared_ptr<Node> node = root;\n    for (int b = B - 1; node\
    \ && b >= 0; --b) {\n      const bool digit = x >> b & 1;\n      if (digit &&\
    \ node->nxt[0]) res += node->nxt[0]->child;\n      node = node->nxt[digit];\n\
    \    }\n    return res;\n  }\n\n  int count(const T& l, const T& r) const {\n\
    \    return less_than(r) - less_than(l);\n  }\n\n  int count(const T& x) const\
    \ {\n    const std::shared_ptr<Node> ptr = find(x);\n    return ptr ? ptr->child\
    \ : 0;\n  }\n\n  std::pair<std::shared_ptr<Node>, T> lower_bound(const T& x) const\
    \ {\n    const int lt = less_than(x);\n    return lt == size() ? std::make_pair(nullptr,\
    \ -1) : find_nth(lt, 0);\n  }\n\n  std::pair<std::shared_ptr<Node>, T> upper_bound(const\
    \ T& x) const {\n    return lower_bound(x + 1);\n  }\n\n  std::pair<std::shared_ptr<Node>,\
    \ T> max_element(const T& x = 0) const {\n    return min_element(~x);\n  }\n\n\
    \  std::pair<std::shared_ptr<Node>, T> min_element(const T& x = 0) const {\n \
    \   assert(root);\n    std::shared_ptr<Node> node = root;\n    T res = 0;\n  \
    \  for (int b = B - 1; b >= 0; --b) {\n      bool digit = x >> b & 1;\n      if\
    \ (!node->nxt[digit]) digit = !digit;\n      node = node->nxt[digit];\n      if\
    \ (digit) res |= static_cast<T>(1) << b;\n    }\n    return {node, res};\n  }\n\
    \n private:\n  void erase(std::shared_ptr<Node>* node, const T& x, int b) {\n\
    \    if (b == -1) {\n      if (--(*node)->child == 0) node->reset();\n      return;\n\
    \    }\n    const bool digit = x >> b & 1;\n    if (!(*node)->nxt[digit]) return;\n\
    \    (*node)->child -= (*node)->nxt[digit]->child;\n    erase(&(*node)->nxt[digit],\
    \ x, b - 1);\n    if ((*node)->nxt[digit]) {\n      (*node)->child += (*node)->nxt[digit]->child;\n\
    \    } else if ((*node)->child == 0) {\n      node->reset();\n    }\n  }\n};\n\
    \n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_BINARY_TRIE_HPP_\n#define EMTHRM_DATA_STRUCTURE_BINARY_TRIE_HPP_\n\
    \n#include <cassert>\n#include <cstdint>\n#include <memory>\n#include <utility>\n\
    \nnamespace emthrm {\n\ntemplate <int B = 32, typename T = std::uint32_t>\nstruct\
    \ BinaryTrie {\n  struct Node {\n    std::shared_ptr<Node> nxt[2];\n    int child;\n\
    \    Node() : nxt{nullptr, nullptr}, child(0) {}\n  };\n\n  std::shared_ptr<Node>\
    \ root;\n\n  BinaryTrie() : root(nullptr) {}\n\n  void clear() { root.reset();\
    \ }\n\n  bool empty() const { return !root; }\n\n  int size() const { return root\
    \ ? root->child : 0; }\n\n  void erase(const T& x) {\n    if (root) erase(&root,\
    \ x, B - 1);\n  }\n\n  std::shared_ptr<Node> find(const T& x) const {\n    if\
    \ (!root) return nullptr;\n    std::shared_ptr<Node> node = root;\n    for (int\
    \ b = B - 1; b >= 0; --b) {\n      const bool digit = x >> b & 1;\n      if (!node->nxt[digit])\
    \ return nullptr;\n      node = node->nxt[digit];\n    }\n    return node;\n \
    \ }\n\n  std::pair<std::shared_ptr<Node>, T> operator[](const int n) const {\n\
    \    return find_nth(n, 0);\n  }\n\n  std::pair<std::shared_ptr<Node>, T> find_nth(int\
    \ n, const T& x) const {\n    assert(0 <= n && n < size());\n    std::shared_ptr<Node>\
    \ node = root;\n    T res = 0;\n    for (int b = B - 1; b >= 0; --b) {\n     \
    \ bool digit = x >> b & 1;\n      const int l_child = (node->nxt[digit] ? node->nxt[digit]->child\
    \ : 0);\n      if (n >= l_child) {\n        n -= l_child;\n        digit = !digit;\n\
    \      }\n      node = node->nxt[digit];\n      if (digit) res |= static_cast<T>(1)\
    \ << b;\n    }\n    return {node, res};\n  }\n\n  std::shared_ptr<Node> insert(const\
    \ T& x) {\n    if (!root) root = std::make_shared<Node>();\n    std::shared_ptr<Node>\
    \ node = root;\n    ++node->child;\n    for (int b = B - 1; b >= 0; --b) {\n \
    \     const bool digit = x >> b & 1;\n      if (!node->nxt[digit]) node->nxt[digit]\
    \ = std::make_shared<Node>();\n      node = node->nxt[digit];\n      ++node->child;\n\
    \    }\n    return node;\n  }\n\n  int less_than(const T& x) const {\n    int\
    \ res = 0;\n    std::shared_ptr<Node> node = root;\n    for (int b = B - 1; node\
    \ && b >= 0; --b) {\n      const bool digit = x >> b & 1;\n      if (digit &&\
    \ node->nxt[0]) res += node->nxt[0]->child;\n      node = node->nxt[digit];\n\
    \    }\n    return res;\n  }\n\n  int count(const T& l, const T& r) const {\n\
    \    return less_than(r) - less_than(l);\n  }\n\n  int count(const T& x) const\
    \ {\n    const std::shared_ptr<Node> ptr = find(x);\n    return ptr ? ptr->child\
    \ : 0;\n  }\n\n  std::pair<std::shared_ptr<Node>, T> lower_bound(const T& x) const\
    \ {\n    const int lt = less_than(x);\n    return lt == size() ? std::make_pair(nullptr,\
    \ -1) : find_nth(lt, 0);\n  }\n\n  std::pair<std::shared_ptr<Node>, T> upper_bound(const\
    \ T& x) const {\n    return lower_bound(x + 1);\n  }\n\n  std::pair<std::shared_ptr<Node>,\
    \ T> max_element(const T& x = 0) const {\n    return min_element(~x);\n  }\n\n\
    \  std::pair<std::shared_ptr<Node>, T> min_element(const T& x = 0) const {\n \
    \   assert(root);\n    std::shared_ptr<Node> node = root;\n    T res = 0;\n  \
    \  for (int b = B - 1; b >= 0; --b) {\n      bool digit = x >> b & 1;\n      if\
    \ (!node->nxt[digit]) digit = !digit;\n      node = node->nxt[digit];\n      if\
    \ (digit) res |= static_cast<T>(1) << b;\n    }\n    return {node, res};\n  }\n\
    \n private:\n  void erase(std::shared_ptr<Node>* node, const T& x, int b) {\n\
    \    if (b == -1) {\n      if (--(*node)->child == 0) node->reset();\n      return;\n\
    \    }\n    const bool digit = x >> b & 1;\n    if (!(*node)->nxt[digit]) return;\n\
    \    (*node)->child -= (*node)->nxt[digit]->child;\n    erase(&(*node)->nxt[digit],\
    \ x, b - 1);\n    if ((*node)->nxt[digit]) {\n      (*node)->child += (*node)->nxt[digit]->child;\n\
    \    } else if ((*node)->child == 0) {\n      node->reset();\n    }\n  }\n};\n\
    \n}  // namespace emthrm\n\n#endif  // EMTHRM_DATA_STRUCTURE_BINARY_TRIE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/binary_trie.test.cpp
documentation_of: include/emthrm/data_structure/binary_trie.hpp
layout: document
title: binary trie
---

非負整数を管理する[トライ木](../string/trie.md)である。


## 時間計算量

$O(B)$


## 仕様

```cpp
template <int B = 32, typename T = std::uint32_t>
struct BinaryTrie;
```

- `B`：ビット幅
- `T`：要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::shared_ptr<Node> root;`|根のポインタ|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`BinaryTrie();`|集合 $S \mathrel{:=} \emptyset$ を表すオブジェクトを構築する||
|`void clear();`|$S \gets \emptyset$||
|`bool empty() const;`|$S = \emptyset$ を満たすか。||
|`int size() const;`|$\lvert S \rvert$||
|`void erase(const T& x);`|$S \gets S \setminus \lbrace x \rbrace$|$x \notin S$ を満たすときは何もしない。|
|`std::shared_ptr<Node> find(const T& x) const;`|$x$ を指すノード。ただし $x \notin S$ を満たすときは `nullptr` を返す。|
|`std::pair<std::shared_ptr<Node>, T> operator[](const int n) const;`|$n$ 番目 (0-based) の要素を指すノードと値||
|`std::pair<std::shared_ptr<Node>, T> find_nth(int n, const T& x) const;`|$\lbrace s \oplus x \mid s \in S \rbrace$ における $n$ 番目 (0-based) の要素を表すノードと値||
|`std::shared_ptr<Node> insert(const T& x);`|$S \gets S \cup \lbrace x \rbrace$ の操作後、$x$ を表すノードを返す。|
|`int less_than(const T& x) const;`|$\lvert \lbrace s \in S \mid s < x \rbrace \rvert$||
|`int count(const T& l, const T& r) const;`|$\lvert \lbrace s \in S \mid l \leq x < r \rbrace \rvert$||
|`int count(const T& x) const;`|$\lvert \lbrace s \in S \mid s = x \rbrace \rvert$||
|`std::pair<std::shared_ptr<Node>, T> lower_bound(const T& x) const;`|$x$ より小さくない最初の要素を表すノードと値。ただしそのような要素が存在しないときは (`nullptr`, $-1$) を返す。|
|`std::pair<std::shared_ptr<Node>, T> upper_bound(const T& x) const;`|$x$ より大きい最初の要素を表すノードと値。ただし存在しないときは (`nullptr`, $-1$) を返す。||
|`std::pair<std::shared_ptr<Node>, T> max_element(const T& x = 0) const;`|$\mathrm{argmax} \lbrace s \oplus x \mid s \in S \rbrace$||
|`std::pair<std::shared_ptr<Node>, T> min_element(const T& x = 0) const;`|$\mathrm{argmin} \lbrace s \oplus x \mid s \in S \rbrace$||

#### メンバ型

|名前|説明|
|:--|:--|
|`Node`|ノードを表す構造体|

```cpp
struct Node;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::shared_ptr<Node> nxt[2]`|子のポインタ|
|`int child`|部分木に属する要素の個数|

#### メンバ関数

|名前|効果|
|:--|:--|
|`Node();`|コンストラクタ|


## 参考文献

- https://kazuma8128.hatenablog.com/entry/2018/05/06/022654


## TODO

- 永続 binary trie
  - https://kazuma8128.hatenablog.com/entry/2018/02/17/224151
- a powerful representation of integer sets
  - https://codeforces.com/blog/entry/83969
  - https://twitter.com/keijak/status/1488232021394702336


## Submissons

https://judge.yosupo.jp/submission/33239
