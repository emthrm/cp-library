---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_trie.hpp
    title: binary trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data_structure/binary_trie.test.cpp\"\n/*\r\n * @brief\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/binary trie\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/binary_trie.hpp\"\n\
    #include <cassert>\r\n#include <cstdint>\r\n#include <memory>\r\n#include <utility>\r\
    \n\r\ntemplate <int B = 32, typename T = std::uint32_t>\r\nstruct BinaryTrie {\r\
    \n  struct Node {\r\n    std::shared_ptr<Node> nxt[2];\r\n    int child;\r\n \
    \   Node() : nxt{nullptr, nullptr}, child(0) {}\r\n  };\r\n\r\n  std::shared_ptr<Node>\
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
    \ }\r\n};\r\n#line 9 \"test/data_structure/binary_trie.test.cpp\"\n\r\nint main()\
    \ {\r\n  constexpr int B = 30;\r\n  BinaryTrie<B> binary_trie;\r\n  int q;\r\n\
    \  std::cin >> q;\r\n  while (q--) {\r\n    int type, x;\r\n    std::cin >> type\
    \ >> x;\r\n    if (type == 0) {\r\n      if (!binary_trie.find(x)) binary_trie.insert(x);\r\
    \n    } else if (type == 1) {\r\n      binary_trie.erase(x);\r\n    } else if\
    \ (type == 2) {\r\n      std::cout << (binary_trie.min_element(x).second ^ x)\
    \ << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/binary trie\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#include <iostream>\r\
    \n\r\n#include \"../../data_structure/binary_trie.hpp\"\r\n\r\nint main() {\r\n\
    \  constexpr int B = 30;\r\n  BinaryTrie<B> binary_trie;\r\n  int q;\r\n  std::cin\
    \ >> q;\r\n  while (q--) {\r\n    int type, x;\r\n    std::cin >> type >> x;\r\
    \n    if (type == 0) {\r\n      if (!binary_trie.find(x)) binary_trie.insert(x);\r\
    \n    } else if (type == 1) {\r\n      binary_trie.erase(x);\r\n    } else if\
    \ (type == 2) {\r\n      std::cout << (binary_trie.min_element(x).second ^ x)\
    \ << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/binary_trie.hpp
  isVerificationFile: true
  path: test/data_structure/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2022-02-23 16:46:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/binary_trie.test.cpp
- /verify/test/data_structure/binary_trie.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
---
