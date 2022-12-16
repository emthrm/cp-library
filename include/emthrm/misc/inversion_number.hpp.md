---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/fenwick_tree/fenwick_tree.hpp:\
    \ line -1: no such header\n"
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
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/inversion_number.test.cpp
documentation_of: include/emthrm/misc/inversion_number.hpp
layout: document
title: "\u8EE2\u5012\u6570 (inversion number)"
---

数列 $A$ に対して $A_i > A_j$ を満たす組 $(i, j)$ ($i < j$) の個数である．

バブルソートに必要な交換回数に等しい．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`inversion_number(a)`|$A$ の転倒数|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.162-163，マイナビ出版（2012）


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_5_D/review/4087800/emthrm/C++14
