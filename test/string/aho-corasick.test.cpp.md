---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/aho-corasick.hpp
    title: "Aho\u2013Corasick algorithm"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/trie.hpp
    title: "\u30C8\u30E9\u30A4\u6728 (trie)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/430
    document_title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"test/string/aho-corasick.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/Aho\u2013Corasick algorithm\n *\n * verification-helper: PROBLEM\
    \ https://yukicoder.me/problems/no/430\n */\n\n#include <iostream>\n#include <string>\n\
    \n#line 1 \"include/emthrm/string/aho-corasick.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iterator>\n#include <map>\n#include <queue>\n#line\
    \ 10 \"include/emthrm/string/aho-corasick.hpp\"\n#include <vector>\n\n#line 1\
    \ \"include/emthrm/string/trie.hpp\"\n\n\n\n#line 5 \"include/emthrm/string/trie.hpp\"\
    \n#include <array>\n#include <functional>\n#line 9 \"include/emthrm/string/trie.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int Sigma = 26>\nstruct Trie {\n  struct Node\
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
    \ namespace emthrm\n\n\n#line 13 \"include/emthrm/string/aho-corasick.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <int Sigma = 26, bool IS_FULL_VER = false>\nstruct\
    \ AhoCorasick : Trie<Sigma + 1> {\n  using Trie<Sigma + 1>::Trie;\n\n  std::vector<int>\
    \ nums;\n\n  void build() {\n    auto& vertices = this->nodes;\n    const int\
    \ n = vertices.size();\n    nums.resize(n);\n    for (int i = 0; i < n; ++i) {\n\
    \      if constexpr (IS_FULL_VER) {\n        std::sort(vertices[i].tails.begin(),\
    \ vertices[i].tails.end());\n      }\n      nums[i] = vertices[i].tails.size();\n\
    \    }\n    std::queue<int> que;\n    for (int i = 0; i < Sigma; ++i) {\n    \
    \  if (vertices.front().nxt[i] == -1) {\n        vertices.front().nxt[i] = 0;\n\
    \      } else {\n        vertices[vertices.front().nxt[i]].nxt[Sigma] = 0;\n \
    \       que.emplace(vertices.front().nxt[i]);\n      }\n    }\n    while (!que.empty())\
    \ {\n      const auto& node = vertices[que.front()];\n      nums[que.front()]\
    \ += nums[node.nxt[Sigma]];\n      que.pop();\n      for (int i = 0; i < Sigma;\
    \ ++i) {\n        if (node.nxt[i] == -1) continue;\n        int on_failure = node.nxt[Sigma];\n\
    \        while (vertices[on_failure].nxt[i] == -1) {\n          on_failure = vertices[on_failure].nxt[Sigma];\n\
    \        }\n        vertices[node.nxt[i]].nxt[Sigma] = vertices[on_failure].nxt[i];\n\
    \        if constexpr (IS_FULL_VER) {\n          std::vector<int>& ids = vertices[node.nxt[i]].tails;\n\
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
    \ std::string& t, int pos = 0) const {\n    static_assert(IS_FULL_VER);\n    std::map<int,\
    \ int> mp;\n    for (const char c : t) {\n      pos = move(c, pos);\n      for\
    \ (const int id : this->nodes[pos].tails) ++mp[id];\n    }\n    return mp;\n \
    \ }\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"test/string/aho-corasick.test.cpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  emthrm::AhoCorasick<>\
    \ aho([](const char c) -> int { return c - 'A'; });\n  int m;\n  std::cin >> m;\n\
    \  for (int i = 0; i < m; ++i) {\n    std::string p;\n    std::cin >> p;\n   \
    \ aho.add(p, i);\n  }\n  aho.build();\n  std::cout << aho.match(s) << '\\n';\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/Aho\u2013Corasick algorithm\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/430\n */\n\n#include <iostream>\n#include\
    \ <string>\n\n#include \"emthrm/string/aho-corasick.hpp\"\n\nint main() {\n  std::string\
    \ s;\n  std::cin >> s;\n  emthrm::AhoCorasick<> aho([](const char c) -> int {\
    \ return c - 'A'; });\n  int m;\n  std::cin >> m;\n  for (int i = 0; i < m; ++i)\
    \ {\n    std::string p;\n    std::cin >> p;\n    aho.add(p, i);\n  }\n  aho.build();\n\
    \  std::cout << aho.match(s) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/aho-corasick.hpp
  - include/emthrm/string/trie.hpp
  isVerificationFile: true
  path: test/string/aho-corasick.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho-corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho-corasick.test.cpp
- /verify/test/string/aho-corasick.test.cpp.html
title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
---
