---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/aho-corasick.hpp
    title: "\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5 (Aho-Corasick\
      \ algorithm)"
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: "\u30C8\u30E9\u30A4\u6728 (trie)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    document_title: "\u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\
      \u30AF\u6CD5"
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"test/string/aho-corasick.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5\r\n */\r\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/430\"\r\n\r\n#include <iostream>\r\
    \n#include <string>\r\n#line 2 \"string/aho-corasick.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <iterator>\r\n#include <map>\r\n#include <queue>\r\
    \n#line 8 \"string/aho-corasick.hpp\"\n#include <vector>\r\n#line 2 \"string/trie.hpp\"\
    \n#include <cstring>\r\n#line 5 \"string/trie.hpp\"\n\r\ntemplate <size_t char_sz\
    \ = 26>\r\nstruct Trie {\r\n  struct Node {\r\n    char c;\r\n    int nx[char_sz];\r\
    \n    std::vector<int> tails;\r\n    Node(char c) : c(c) { std::memset(nx, -1,\
    \ sizeof(nx)); }\r\n  };\r\n\r\n  std::vector<Node> nodes;\r\n\r\n  Trie(const\
    \ char basis = 'a') : basis(basis) { nodes.emplace_back('$'); }\r\n\r\n  void\
    \ add(const std::string &s, int id = -1, int pos = 0) {\r\n    for (char c : s)\
    \ {\r\n      int now = convert(c);\r\n      if (nodes[pos].nx[now] == -1) {\r\n\
    \        int nx_pos = nodes.size();\r\n        nodes[pos].nx[now] = nx_pos;\r\n\
    \        nodes.emplace_back(c);\r\n        pos = nx_pos;\r\n      } else {\r\n\
    \        pos = nodes[pos].nx[now];\r\n      }\r\n    }\r\n    nodes[pos].tails.emplace_back(id);\r\
    \n  }\r\n\r\n  int find(const std::string &t, int pos = 0) const {\r\n    for\
    \ (char c : t) {\r\n      int now = convert(c);\r\n      if (nodes[pos].nx[now]\
    \ == -1) return -1;\r\n      pos = nodes[pos].nx[now];\r\n    }\r\n    return\
    \ pos;\r\n  }\r\n\r\n  int convert(char c) const { return c - basis; }\r\n\r\n\
    private:\r\n  const char basis;\r\n};\r\n#line 10 \"string/aho-corasick.hpp\"\n\
    \r\ntemplate <size_t char_sz = 26>\r\nstruct AhoCorasick : Trie<char_sz + 1> {\r\
    \n  using Trie<char_sz + 1>::Trie;\r\n\r\n  std::vector<int> cnt;\r\n\r\n  void\
    \ build(bool heavy = false) {\r\n    is_built = true;\r\n    is_heavy = heavy;\r\
    \n    auto &vertices = this->nodes;\r\n    int n = vertices.size();\r\n    cnt.resize(n);\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      if (heavy) std::sort(vertices[i].tails.begin(),\
    \ vertices[i].tails.end());\r\n      cnt[i] = vertices[i].tails.size();\r\n  \
    \  }\r\n    std::queue<int> que;\r\n    for (int i = 0; i < char_sz; ++i) {\r\n\
    \      if (vertices[0].nx[i] == -1) {\r\n        vertices[0].nx[i] = 0;\r\n  \
    \    } else {\r\n        vertices[vertices[0].nx[i]].nx[char_sz] = 0;\r\n    \
    \    que.emplace(vertices[0].nx[i]);\r\n      }\r\n    }\r\n    while (!que.empty())\
    \ {\r\n      const auto &node = vertices[que.front()];\r\n      cnt[que.front()]\
    \ += cnt[node.nx[char_sz]];\r\n      que.pop();\r\n      for (int i = 0; i < char_sz;\
    \ ++i) {\r\n        if (node.nx[i] == -1) continue;\r\n        int on_failure\
    \ = node.nx[char_sz];\r\n        while (vertices[on_failure].nx[i] == -1) on_failure\
    \ = vertices[on_failure].nx[char_sz];\r\n        vertices[node.nx[i]].nx[char_sz]\
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
    \ = false;\r\n};\r\n#line 9 \"test/string/aho-corasick.test.cpp\"\n\r\nint main()\
    \ {\r\n  std::string s;\r\n  std::cin >> s;\r\n  AhoCorasick<> aho('A');\r\n \
    \ int m;\r\n  std::cin >> m;\r\n  for (int i = 0; i < m; ++i) {\r\n    std::string\
    \ p;\r\n    std::cin >> p;\r\n    aho.add(p, i);\r\n  }\r\n  aho.build();\r\n\
    \  std::cout << aho.match(s) << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\
    \u30AF\u6CD5\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/430\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../string/aho-corasick.hpp\"\
    \r\n\r\nint main() {\r\n  std::string s;\r\n  std::cin >> s;\r\n  AhoCorasick<>\
    \ aho('A');\r\n  int m;\r\n  std::cin >> m;\r\n  for (int i = 0; i < m; ++i) {\r\
    \n    std::string p;\r\n    std::cin >> p;\r\n    aho.add(p, i);\r\n  }\r\n  aho.build();\r\
    \n  std::cout << aho.match(s) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/aho-corasick.hpp
  - string/trie.hpp
  isVerificationFile: true
  path: test/string/aho-corasick.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho-corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho-corasick.test.cpp
- /verify/test/string/aho-corasick.test.cpp.html
title: "\u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5"
---
