---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/aho-corasick.hpp
    title: "Aho\u2013Corasick algorithm"
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
    document_title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"test/string/aho-corasick.test.cpp\"\n/*\n * @brief \u6587\
    \u5B57\u5217/Aho\u2013Corasick algorithm\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/430\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"string/aho-corasick.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <map>\n\
    #include <queue>\n#line 8 \"string/aho-corasick.hpp\"\n#include <vector>\n\n#line\
    \ 3 \"string/trie.hpp\"\n#include <functional>\n#line 6 \"string/trie.hpp\"\n\n\
    template <size_t Sigma = 26>\nstruct Trie {\n  struct Node {\n    char c;\n  \
    \  int nxt[Sigma];\n    std::vector<int> tails;\n    explicit Node(const char\
    \ c) : c(c) { std::fill(nxt, nxt + Sigma, -1); }\n  };\n\n  const std::function<int(const\
    \ char)> convert;\n  std::vector<Node> nodes;\n\n  explicit Trie(const std::function<int(const\
    \ char)> convert =\n                    [](const char c) -> int { return c - 'a';\
    \ })\n      : convert(convert) { nodes.emplace_back('$'); }\n\n  void add(const\
    \ std::string& s, const int id = -1, int pos = 0) {\n    for (const char c : s)\
    \ {\n      const int c_int = convert(c);\n      if (nodes[pos].nxt[c_int] == -1)\
    \ {\n        const int nxt_pos = nodes.size();\n        nodes[pos].nxt[c_int]\
    \ = nxt_pos;\n        nodes.emplace_back(c);\n        pos = nxt_pos;\n      }\
    \ else {\n        pos = nodes[pos].nxt[c_int];\n      }\n    }\n    nodes[pos].tails.emplace_back(id);\n\
    \  }\n\n  int find(const std::string& t, int pos = 0) const {\n    for (const\
    \ char c : t) {\n      const int c_int = convert(c);\n      if (nodes[pos].nxt[c_int]\
    \ == -1) return -1;\n      pos = nodes[pos].nxt[c_int];\n    }\n    return pos;\n\
    \  }\n};\n#line 11 \"string/aho-corasick.hpp\"\n\ntemplate <size_t Sigma = 26>\n\
    struct AhoCorasick : Trie<Sigma + 1> {\n  using Trie<Sigma + 1>::Trie;\n\n  std::vector<int>\
    \ nums;\n\n  void build(const bool is_full_ver_ = false) {\n    is_full_ver =\
    \ is_full_ver_;\n    auto& vertices = this->nodes;\n    const int n = vertices.size();\n\
    \    nums.resize(n);\n    for (int i = 0; i < n; ++i) {\n      if (is_full_ver)\
    \ {\n        std::sort(vertices[i].tails.begin(), vertices[i].tails.end());\n\
    \      }\n      nums[i] = vertices[i].tails.size();\n    }\n    std::queue<int>\
    \ que;\n    for (int i = 0; i < Sigma; ++i) {\n      if (vertices.front().nxt[i]\
    \ == -1) {\n        vertices.front().nxt[i] = 0;\n      } else {\n        vertices[vertices.front().nxt[i]].nxt[Sigma]\
    \ = 0;\n        que.emplace(vertices.front().nxt[i]);\n      }\n    }\n    while\
    \ (!que.empty()) {\n      const auto& node = vertices[que.front()];\n      nums[que.front()]\
    \ += nums[node.nxt[Sigma]];\n      que.pop();\n      for (int i = 0; i < Sigma;\
    \ ++i) {\n        if (node.nxt[i] == -1) continue;\n        int on_failure = node.nxt[Sigma];\n\
    \        while (vertices[on_failure].nxt[i] == -1) {\n          on_failure = vertices[on_failure].nxt[Sigma];\n\
    \        }\n        vertices[node.nxt[i]].nxt[Sigma] = vertices[on_failure].nxt[i];\n\
    \        if (is_full_ver) {\n          std::vector<int>& ids = vertices[node.nxt[i]].tails;\n\
    \          std::vector<int> tmp;\n          std::set_union(ids.begin(), ids.end(),\n\
    \                         vertices[vertices[on_failure].nxt[i]].tails.begin(),\n\
    \                         vertices[vertices[on_failure].nxt[i]].tails.end(),\n\
    \                         std::back_inserter(tmp));\n          ids.resize(tmp.size());\n\
    \          std::copy(tmp.begin(), tmp.end(), ids.begin());\n        }\n      \
    \  que.emplace(node.nxt[i]);\n      }\n    }\n  }\n\n  int move(char c, int pos)\
    \ const {\n    const int c_int = this->convert(c);\n    while (this->nodes[pos].nxt[c_int]\
    \ == -1) pos = this->nodes[pos].nxt[Sigma];\n    return pos = this->nodes[pos].nxt[c_int];\n\
    \  }\n\n  int match(const std::string& t, int pos = 0) const {\n    int total\
    \ = 0;\n    for (const char c : t) {\n      pos = move(c, pos);\n      total +=\
    \ nums[pos];\n    }\n    return total;\n  }\n\n  std::map<int, int> match_fully(const\
    \ std::string& t, int pos = 0) const {\n    assert(is_full_ver);\n    std::map<int,\
    \ int> mp;\n    for (const char c : t) {\n      pos = move(c, pos);\n      for\
    \ (const int id : this->nodes[pos].tails) ++mp[id];\n    }\n    return mp;\n \
    \ }\n\n private:\n  bool is_full_ver = false;\n};\n#line 10 \"test/string/aho-corasick.test.cpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  AhoCorasick<> aho([](const\
    \ char c) -> int { return c - 'A'; });\n  int m;\n  std::cin >> m;\n  for (int\
    \ i = 0; i < m; ++i) {\n    std::string p;\n    std::cin >> p;\n    aho.add(p,\
    \ i);\n  }\n  aho.build();\n  std::cout << aho.match(s) << '\\n';\n  return 0;\n\
    }\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/Aho\u2013Corasick algorithm\n */\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/430\"\n\n#include <iostream>\n#include\
    \ <string>\n\n#include \"../../string/aho-corasick.hpp\"\n\nint main() {\n  std::string\
    \ s;\n  std::cin >> s;\n  AhoCorasick<> aho([](const char c) -> int { return c\
    \ - 'A'; });\n  int m;\n  std::cin >> m;\n  for (int i = 0; i < m; ++i) {\n  \
    \  std::string p;\n    std::cin >> p;\n    aho.add(p, i);\n  }\n  aho.build();\n\
    \  std::cout << aho.match(s) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - string/aho-corasick.hpp
  - string/trie.hpp
  isVerificationFile: true
  path: test/string/aho-corasick.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho-corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho-corasick.test.cpp
- /verify/test/string/aho-corasick.test.cpp.html
title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
---
