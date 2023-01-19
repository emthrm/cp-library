---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/aho-corasick.hpp
    title: "Aho\u2013Corasick algorithm"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho-corasick.test.cpp
    title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/trie.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#include <functional>\n#include <string>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <int Sigma = 26>\nstruct Trie {\n  struct Node\
    \ {\n    char c;\n    std::array<int, Sigma> nxt;\n    std::vector<int> tails;\n\
    \n    explicit Node(const char c) : c(c) {\n      std::fill(nxt.begin(), nxt.end(),\
    \ -1);\n    }\n  };\n\n  const std::function<int(const char)> convert;\n  std::vector<Node>\
    \ nodes;\n\n  explicit Trie(const std::function<int(const char)> convert =\n \
    \                   [](const char c) -> int { return c - 'a'; })\n      : convert(convert)\
    \ { nodes.emplace_back('$'); }\n\n  void add(const std::string& s, const int id\
    \ = -1, int pos = 0) {\n    for (const char c : s) {\n      const int c_int =\
    \ convert(c);\n      if (nodes[pos].nxt[c_int] == -1) {\n        const int nxt_pos\
    \ = nodes.size();\n        nodes[pos].nxt[c_int] = nxt_pos;\n        nodes.emplace_back(c);\n\
    \        pos = nxt_pos;\n      } else {\n        pos = nodes[pos].nxt[c_int];\n\
    \      }\n    }\n    nodes[pos].tails.emplace_back(id);\n  }\n\n  int find(const\
    \ std::string& t, int pos = 0) const {\n    for (const char c : t) {\n      const\
    \ int c_int = convert(c);\n      if (nodes[pos].nxt[c_int] == -1) return -1;\n\
    \      pos = nodes[pos].nxt[c_int];\n    }\n    return pos;\n  }\n};\n\n}  //\
    \ namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_TRIE_HPP_\n#define EMTHRM_STRING_TRIE_HPP_\n\n#include\
    \ <algorithm>\n#include <array>\n#include <functional>\n#include <string>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <int Sigma = 26>\nstruct Trie {\n\
    \  struct Node {\n    char c;\n    std::array<int, Sigma> nxt;\n    std::vector<int>\
    \ tails;\n\n    explicit Node(const char c) : c(c) {\n      std::fill(nxt.begin(),\
    \ nxt.end(), -1);\n    }\n  };\n\n  const std::function<int(const char)> convert;\n\
    \  std::vector<Node> nodes;\n\n  explicit Trie(const std::function<int(const char)>\
    \ convert =\n                    [](const char c) -> int { return c - 'a'; })\n\
    \      : convert(convert) { nodes.emplace_back('$'); }\n\n  void add(const std::string&\
    \ s, const int id = -1, int pos = 0) {\n    for (const char c : s) {\n      const\
    \ int c_int = convert(c);\n      if (nodes[pos].nxt[c_int] == -1) {\n        const\
    \ int nxt_pos = nodes.size();\n        nodes[pos].nxt[c_int] = nxt_pos;\n    \
    \    nodes.emplace_back(c);\n        pos = nxt_pos;\n      } else {\n        pos\
    \ = nodes[pos].nxt[c_int];\n      }\n    }\n    nodes[pos].tails.emplace_back(id);\n\
    \  }\n\n  int find(const std::string& t, int pos = 0) const {\n    for (const\
    \ char c : t) {\n      const int c_int = convert(c);\n      if (nodes[pos].nxt[c_int]\
    \ == -1) return -1;\n      pos = nodes[pos].nxt[c_int];\n    }\n    return pos;\n\
    \  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_TRIE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/trie.hpp
  requiredBy:
  - include/emthrm/string/aho-corasick.hpp
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho-corasick.test.cpp
documentation_of: include/emthrm/string/trie.hpp
layout: document
title: "\u30C8\u30E9\u30A4\u6728 (trie)"
---

複数の文字列を高速に検索できる木である。


## 時間計算量

$O(\lvert S \rvert)$


## 仕様

```cpp
template <int Sigma = 26>
struct Trie;
```

- `Sigma`：アルファベットサイズ

#### メンバ変数

|名前|説明|
|:--|:--|
|`const std::function<int(const char)> convert`|文字を数に変換する関数|
|`std::vector<Node> nodes`|トライ木の頂点|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit Trie(const std::function<int(const char)> convert = [](const char c) -> int { return c - 'a'; });`|コンストラクタ||
|`void add(const std::string& s, const int id = -1, int pos = 0);`|$\mathrm{pos}$ 番目のノードから ID $\mathrm{id}$ の文字列 $S$ を追加する。||
|`int find(const std::string& t, int pos = 0) const;`|$\mathrm{pos}$ 番目のノードから見たとき、文字列 $T$ に対応するノードのインデックス。ただし存在しないときは $-1$ を返す。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Node`|ノードを表す構造体|

```cpp
struct Node
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`char c`|そのノードが表す文字|
|`std::array<int, Sigma> nxt`|子のインデックス|
|`std::vector<int> tails`|そのノードを末尾とする文字列の ID 集合|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Node(const char c)`|コンストラクタ|


## 参考文献

- https://github.com/beet-aizu/library/blob/2ecdc969043f5276c3782a7752592bd3fe856524/string/trie.cpp


## TODO

- 永続 trie
  - https://ei1333.github.io/luzhiled/snippets/structure/binary-trie.html


## Submissons

https://yukicoder.me/submissions/413744
