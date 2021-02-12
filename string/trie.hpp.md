---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/aho-corasick.hpp
    title: "\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5 (Aho-Corasick\
      \ algorithm)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho-corasick.test.cpp
    title: "\u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include <cstring>\r\n#include <string>\r\
    \n#include <vector>\r\n\r\ntemplate <size_t char_sz = 26>\r\nstruct Trie {\r\n\
    \  struct Node {\r\n    char c;\r\n    int nx[char_sz];\r\n    std::vector<int>\
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
    \ basis;\r\n};\r\n"
  code: "#pragma once\r\n#include <cstring>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\ntemplate <size_t char_sz = 26>\r\nstruct Trie {\r\n  struct Node {\r\n \
    \   char c;\r\n    int nx[char_sz];\r\n    std::vector<int> tails;\r\n    Node(char\
    \ c) : c(c) { std::memset(nx, -1, sizeof(nx)); }\r\n  };\r\n\r\n  std::vector<Node>\
    \ nodes;\r\n\r\n  Trie(const char basis = 'a') : basis(basis) { nodes.emplace_back('$');\
    \ }\r\n\r\n  void add(const std::string &s, int id = -1, int pos = 0) {\r\n  \
    \  for (char c : s) {\r\n      int now = convert(c);\r\n      if (nodes[pos].nx[now]\
    \ == -1) {\r\n        int nx_pos = nodes.size();\r\n        nodes[pos].nx[now]\
    \ = nx_pos;\r\n        nodes.emplace_back(c);\r\n        pos = nx_pos;\r\n   \
    \   } else {\r\n        pos = nodes[pos].nx[now];\r\n      }\r\n    }\r\n    nodes[pos].tails.emplace_back(id);\r\
    \n  }\r\n\r\n  int find(const std::string &t, int pos = 0) const {\r\n    for\
    \ (char c : t) {\r\n      int now = convert(c);\r\n      if (nodes[pos].nx[now]\
    \ == -1) return -1;\r\n      pos = nodes[pos].nx[now];\r\n    }\r\n    return\
    \ pos;\r\n  }\r\n\r\n  int convert(char c) const { return c - basis; }\r\n\r\n\
    private:\r\n  const char basis;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/aho-corasick.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho-corasick.test.cpp
documentation_of: string/trie.hpp
layout: document
title: "\u30C8\u30E9\u30A4\u6728 (trie)"
---

複数の文字列を高速に検索することが可能になる木である．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Trie<種類数 = 26>(基準 = 'a')`|トライ木||
|`nodes`|木の頂点||
|`add(s, id = -1, pos = 0)`|ノード $\mathrm{pos}$ からID $\mathrm{id}$ の文字列 $S$ を追加する．||
|`find(t, pos = 0)`|ノード $\mathrm{pos}$ から辿った文字列 $T$ に対応するノードのインデックス|存在しない場合は $-1$ となる．|
|`convert(c)`|数に変換した文字 $c$||


## 参考

- https://github.com/beet-aizu/library/blob/master/string/trie.cpp


## ToDo

- 永続 trie
  - https://ei1333.github.io/luzhiled/snippets/structure/binary-trie.html


## Verified

https://yukicoder.me/submissions/413744
