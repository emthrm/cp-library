---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree (binary indexed tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/inversion_number.test.cpp
    title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/misc/inversion_number.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <iterator>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\n\n\n#include <bit>\n#line 6 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Abelian>\nstruct FenwickTree {\n\
    \  explicit FenwickTree(const int n, const Abelian ID = 0)\n      : n(n), ID(ID),\
    \ data(n, ID) {}\n\n  void add(int idx, const Abelian val) {\n    for (; idx <\
    \ n; idx |= idx + 1) {\n      data[idx] += val;\n    }\n  }\n\n  Abelian sum(int\
    \ idx) const {\n    Abelian res = ID;\n    for (--idx; idx >= 0; idx = (idx &\
    \ (idx + 1)) - 1) {\n      res += data[idx];\n    }\n    return res;\n  }\n\n\
    \  Abelian sum(const int left, const int right) const {\n    return left < right\
    \ ? sum(right) - sum(left) : ID;\n  }\n\n  Abelian operator[](const int idx) const\
    \ { return sum(idx, idx + 1); }\n\n  int lower_bound(Abelian val) const {\n  \
    \  if (val <= ID) [[unlikely]] return 0;\n    int res = 0;\n    for (int mask\
    \ = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;\n         mask > 0;\
    \ mask >>= 1) {\n      const int idx = res + mask - 1;\n      if (idx < n && data[idx]\
    \ < val) {\n        val -= data[idx];\n        res += mask;\n      }\n    }\n\
    \    return res;\n  }\n\n private:\n  const int n;\n  const Abelian ID;\n  std::vector<Abelian>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 9 \"include/emthrm/misc/inversion_number.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nlong long inversion_number(const\
    \ std::vector<T>& a) {\n  const int n = a.size();\n  std::vector<T> b = a;\n \
    \ std::sort(b.begin(), b.end());\n  b.erase(std::unique(b.begin(), b.end()), b.end());\n\
    \  FenwickTree<int> bit(b.size());\n  long long res = 0;\n  for (int i = 0; i\
    \ < n; ++i) {\n    const int idx = std::distance(\n        b.begin(), std::lower_bound(b.begin(),\
    \ b.end(), a[i]));\n    res += i - bit.sum(idx + 1);\n    bit.add(idx, 1);\n \
    \ }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MISC_INVERSION_NUMBER_HPP_\n#define EMTHRM_MISC_INVERSION_NUMBER_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <vector>\n\n#include \"\
    emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\n\nnamespace emthrm {\n\n\
    template <typename T>\nlong long inversion_number(const std::vector<T>& a) {\n\
    \  const int n = a.size();\n  std::vector<T> b = a;\n  std::sort(b.begin(), b.end());\n\
    \  b.erase(std::unique(b.begin(), b.end()), b.end());\n  FenwickTree<int> bit(b.size());\n\
    \  long long res = 0;\n  for (int i = 0; i < n; ++i) {\n    const int idx = std::distance(\n\
    \        b.begin(), std::lower_bound(b.begin(), b.end(), a[i]));\n    res += i\
    \ - bit.sum(idx + 1);\n    bit.add(idx, 1);\n  }\n  return res;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MISC_INVERSION_NUMBER_HPP_\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: false
  path: include/emthrm/misc/inversion_number.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/inversion_number.test.cpp
documentation_of: include/emthrm/misc/inversion_number.hpp
layout: document
title: "\u8EE2\u5012\u6570 (inversion number)"
---

数列 $A$ に対して $A_i > A_j$ を満たす組 $(i, j)$ ($i < j$) の個数である。

バブルソートに必要な交換回数に等しい。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`long long inversion_number(const std::vector<T>& a);`|$A$ の転倒数|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.162-163，マイナビ出版（2012）


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_5_D/review/4087800/emthrm/C++14
