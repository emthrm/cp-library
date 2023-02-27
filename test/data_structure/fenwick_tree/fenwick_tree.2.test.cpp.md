---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree (binary indexed tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/arc033/tasks/arc033_3
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))"
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_3
  bundledCode: "#line 1 \"test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))\n\
    \ *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc033/tasks/arc033_3\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\n\n\n#include <bit>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ Abelian>\nstruct FenwickTree {\n  explicit FenwickTree(const int n, const Abelian\
    \ ID = 0)\n      : n(n), ID(ID), data(n, ID) {}\n\n  void add(int idx, const Abelian\
    \ val) {\n    for (; idx < n; idx |= idx + 1) {\n      data[idx] += val;\n   \
    \ }\n  }\n\n  Abelian sum(int idx) const {\n    Abelian res = ID;\n    for (--idx;\
    \ idx >= 0; idx = (idx & (idx + 1)) - 1) {\n      res += data[idx];\n    }\n \
    \   return res;\n  }\n\n  Abelian sum(const int left, const int right) const {\n\
    \    return left < right ? sum(right) - sum(left) : ID;\n  }\n\n  Abelian operator[](const\
    \ int idx) const { return sum(idx, idx + 1); }\n\n  int lower_bound(Abelian val)\
    \ const {\n    if (val <= ID) [[unlikely]] return 0;\n    int res = 0;\n    for\
    \ (int mask = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;\n        \
    \ mask > 0; mask >>= 1) {\n      const int idx = res + mask - 1;\n      if (idx\
    \ < n && data[idx] < val) {\n        val -= data[idx];\n        res += mask;\n\
    \      }\n    }\n    return res;\n  }\n\n private:\n  const int n;\n  const Abelian\
    \ ID;\n  std::vector<Abelian> data;\n};\n\n}  // namespace emthrm\n\n\n#line 11\
    \ \"test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp\"\n\nint main() {\n\
    \  constexpr int M = 200000;\n  emthrm::FenwickTree<int> bit(M + 1);\n  int q;\n\
    \  std::cin >> q;\n  while (q--) {\n    int t, x;\n    std::cin >> t >> x;\n \
    \   if (t == 1) {\n      bit.add(x, 1);\n    } else if (t == 2) {\n      const\
    \ int ans = bit.lower_bound(x);\n      std::cout << ans << '\\n';\n      bit.add(ans,\
    \ -1);\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))\n\
    \ *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc033/tasks/arc033_3\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nint main() {\n  constexpr int M = 200000;\n  emthrm::FenwickTree<int> bit(M\
    \ + 1);\n  int q;\n  std::cin >> q;\n  while (q--) {\n    int t, x;\n    std::cin\
    \ >> t >> x;\n    if (t == 1) {\n      bit.add(x, 1);\n    } else if (t == 2)\
    \ {\n      const int ans = bit.lower_bound(x);\n      std::cout << ans << '\\\
    n';\n      bit.add(ans, -1);\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))"
---
