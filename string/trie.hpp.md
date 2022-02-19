---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/aho-corasick.hpp
    title: "\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5 (Aho-Corasick\
      \ algorithm)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/aho-corasick.test.cpp
    title: "\u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include <algorithm>\r\n#include <functional>\r\
    \n#include <string>\r\n#include <vector>\r\n\r\ntemplate <size_t Sigma = 26>\r\
    \nstruct Trie {\r\n  struct Node {\r\n    char c;\r\n    int nxt[Sigma];\r\n \
    \   std::vector<int> tails;\r\n    explicit Node(const char c) : c(c) { std::fill(nxt,\
    \ nxt + Sigma, -1); }\r\n  };\r\n\r\n  const std::function<int(const char)> convert;\r\
    \n  std::vector<Node> nodes;\r\n\r\n  explicit Trie(const std::function<int(const\
    \ char)> convert =\r\n                    [](const char c) -> int { return c -\
    \ 'a'; })\r\n      : convert(convert) { nodes.emplace_back('$'); }\r\n\r\n  void\
    \ add(const std::string& s, const int id = -1, int pos = 0) {\r\n    for (const\
    \ char c : s) {\r\n      const int c_int = convert(c);\r\n      if (nodes[pos].nxt[c_int]\
    \ == -1) {\r\n        const int nxt_pos = nodes.size();\r\n        nodes[pos].nxt[c_int]\
    \ = nxt_pos;\r\n        nodes.emplace_back(c);\r\n        pos = nxt_pos;\r\n \
    \     } else {\r\n        pos = nodes[pos].nxt[c_int];\r\n      }\r\n    }\r\n\
    \    nodes[pos].tails.emplace_back(id);\r\n  }\r\n\r\n  int find(const std::string&\
    \ t, int pos = 0) const {\r\n    for (const char c : t) {\r\n      const int c_int\
    \ = convert(c);\r\n      if (nodes[pos].nxt[c_int] == -1) return -1;\r\n     \
    \ pos = nodes[pos].nxt[c_int];\r\n    }\r\n    return pos;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <functional>\r\n#include\
    \ <string>\r\n#include <vector>\r\n\r\ntemplate <size_t Sigma = 26>\r\nstruct\
    \ Trie {\r\n  struct Node {\r\n    char c;\r\n    int nxt[Sigma];\r\n    std::vector<int>\
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
    \ pos = nodes[pos].nxt[c_int];\r\n    }\r\n    return pos;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/aho-corasick.hpp
  timestamp: '2022-02-08 18:47:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/aho-corasick.test.cpp
documentation_of: string/trie.hpp
layout: document
title: "\u30C8\u30E9\u30A4\u6728 (trie)"
---

複数の文字列を高速に検索できる木である．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Trie<σ = 26>(convert)`|トライ木||
|`convert(c)`|数に変換した文字 $c$||
|`nodes`|トライ木の頂点||
|`add(s, id = -1, pos = 0)`|$\mathrm{pos}$ 番目のノードから ID $\mathrm{id}$ の文字列 $S$ を追加する．||
|`find(t, pos = 0)`|$\mathrm{pos}$ 番目のノードを起点としたときに文字列 $T$ と対応するノードのインデックス|存在しないときは $-1$ となる．|


## 参考

- https://github.com/beet-aizu/library/blob/2ecdc969043f5276c3782a7752592bd3fe856524/string/trie.cpp


## ToDo

- 永続 trie
  - https://ei1333.github.io/luzhiled/snippets/structure/binary-trie.html


## Verified

https://yukicoder.me/submissions/413744
