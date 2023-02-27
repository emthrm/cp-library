---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/binary_trie.hpp
    title: binary trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data_structure/binary_trie.test.cpp\"\n/*\n * @title\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/binary trie\n *\n * verification-helper: PROBLEM\
    \ https://judge.yosupo.jp/problem/set_xor_min\n */\n\n#include <iostream>\n\n\
    #line 1 \"include/emthrm/data_structure/binary_trie.hpp\"\n\n\n\n#include <array>\n\
    #include <cassert>\n#include <cstdint>\n#include <memory>\n#include <optional>\n\
    #include <utility>\n\nnamespace emthrm {\n\ntemplate <int B = 32, typename T =\
    \ std::uint32_t>\nstruct BinaryTrie {\n  struct Node {\n    std::array<std::shared_ptr<Node>,\
    \ 2> nxt;\n    int child;\n\n    Node() : nxt{nullptr, nullptr}, child(0) {}\n\
    \  };\n\n  std::shared_ptr<Node> root;\n\n  BinaryTrie() : root(nullptr) {}\n\n\
    \  void clear() { root.reset(); }\n\n  bool empty() const { return !root; }\n\n\
    \  int size() const { return root ? root->child : 0; }\n\n  void erase(const T&\
    \ x) {\n    if (root) [[likely]] erase(&root, x, B - 1);\n  }\n\n  std::shared_ptr<Node>\
    \ find(const T& x) const {\n    if (!root) [[unlikely]] return nullptr;\n    std::shared_ptr<Node>\
    \ node = root;\n    for (int b = B - 1; b >= 0; --b) {\n      const bool digit\
    \ = x >> b & 1;\n      if (!node->nxt[digit]) return nullptr;\n      node = node->nxt[digit];\n\
    \    }\n    return node;\n  }\n\n  std::pair<std::shared_ptr<Node>, T> operator[](const\
    \ int n) const {\n    return find_nth(n, 0);\n  }\n\n  std::pair<std::shared_ptr<Node>,\
    \ T> find_nth(int n, const T& x) const {\n    assert(0 <= n && n < size());\n\
    \    std::shared_ptr<Node> node = root;\n    T res = 0;\n    for (int b = B -\
    \ 1; b >= 0; --b) {\n      bool digit = x >> b & 1;\n      const int l_child =\
    \ (node->nxt[digit] ? node->nxt[digit]->child : 0);\n      if (n >= l_child) {\n\
    \        n -= l_child;\n        digit = !digit;\n      }\n      node = node->nxt[digit];\n\
    \      if (digit) res |= static_cast<T>(1) << b;\n    }\n    return {node, res};\n\
    \  }\n\n  std::shared_ptr<Node> insert(const T& x) {\n    if (!root) [[unlikely]]\
    \ root = std::make_shared<Node>();\n    std::shared_ptr<Node> node = root;\n \
    \   ++node->child;\n    for (int b = B - 1; b >= 0; --b) {\n      const bool digit\
    \ = x >> b & 1;\n      if (!node->nxt[digit]) node->nxt[digit] = std::make_shared<Node>();\n\
    \      node = node->nxt[digit];\n      ++node->child;\n    }\n    return node;\n\
    \  }\n\n  int less_than(const T& x) const {\n    int res = 0;\n    std::shared_ptr<Node>\
    \ node = root;\n    for (int b = B - 1; node && b >= 0; --b) {\n      const bool\
    \ digit = x >> b & 1;\n      if (digit && node->nxt[0]) res += node->nxt[0]->child;\n\
    \      node = node->nxt[digit];\n    }\n    return res;\n  }\n\n  int count(const\
    \ T& l, const T& r) const {\n    return less_than(r) - less_than(l);\n  }\n\n\
    \  int count(const T& x) const {\n    const std::shared_ptr<Node> ptr = find(x);\n\
    \    return ptr ? ptr->child : 0;\n  }\n\n  std::pair<std::shared_ptr<Node>, std::optional<T>>\
    \ lower_bound(\n      const T& x) const {\n    const int lt = less_than(x);\n\
    \    if (lt == size()) return std::make_pair(nullptr, std::nullopt);\n    const\
    \ auto [node, value] = find_nth(lt, 0);\n    return std::make_pair(node, std::make_optional(value));\n\
    \  }\n\n  std::pair<std::shared_ptr<Node>, std::optional<T>> upper_bound(\n  \
    \    const T& x) const {\n    return lower_bound(x + 1);\n  }\n\n  std::pair<std::shared_ptr<Node>,\
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
    \n}  // namespace emthrm\n\n\n#line 10 \"test/data_structure/binary_trie.test.cpp\"\
    \n\nint main() {\n  constexpr int B = 30;\n  emthrm::BinaryTrie<B> binary_trie;\n\
    \  int q;\n  std::cin >> q;\n  while (q--) {\n    int type, x;\n    std::cin >>\
    \ type >> x;\n    if (type == 0) {\n      if (!binary_trie.find(x)) binary_trie.insert(x);\n\
    \    } else if (type == 1) {\n      binary_trie.erase(x);\n    } else if (type\
    \ == 2) {\n      std::cout << (binary_trie.min_element(x).second ^ x) << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/binary trie\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/set_xor_min\n */\n\n#include <iostream>\n\
    \n#include \"emthrm/data_structure/binary_trie.hpp\"\n\nint main() {\n  constexpr\
    \ int B = 30;\n  emthrm::BinaryTrie<B> binary_trie;\n  int q;\n  std::cin >> q;\n\
    \  while (q--) {\n    int type, x;\n    std::cin >> type >> x;\n    if (type ==\
    \ 0) {\n      if (!binary_trie.find(x)) binary_trie.insert(x);\n    } else if\
    \ (type == 1) {\n      binary_trie.erase(x);\n    } else if (type == 2) {\n  \
    \    std::cout << (binary_trie.min_element(x).second ^ x) << '\\n';\n    }\n \
    \ }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/binary_trie.hpp
  isVerificationFile: true
  path: test/data_structure/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/binary_trie.test.cpp
- /verify/test/data_structure/binary_trie.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
---
