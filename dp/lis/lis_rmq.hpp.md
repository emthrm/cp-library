---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dp/lis/lis_rmq.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/LIS/\u6700\u9577\u5897\u52A0\u90E8\u5206\
      \u5217 RMQ \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/lis/lis.md
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 RMQ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dp/lis/lis_rmq.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 RMQ \u7248\r\n\
    \ * @docs docs/dp/lis/lis.md\r\n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\
    \n#include <limits>\r\n#include <vector>\r\n#include \"../../data_structure/segment_tree/segment_tree.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nint lis_rmq(const std::vector<T> &a, const T\
    \ TINF) {\r\n  int n = a.size();\r\n  std::vector<T> b(a);\r\n  std::sort(b.begin(),\
    \ b.end());\r\n  b.erase(std::unique(b.begin(), b.end()), b.end());\r\n  static\
    \ T tinf = TINF;\r\n  struct Node {\r\n    using Monoid = T;\r\n    static constexpr\
    \ T unity() { return tinf; }\r\n    static T merge(const T &a, const T &b) { return\
    \ std::min(a, b); }\r\n  };\r\n  SegmentTree<Node> rmq(b.size() + 1);\r\n  rmq.set(0,\
    \ 0);\r\n  for (int i = 0; i < n; ++i) {\r\n    int idx = std::lower_bound(b.begin(),\
    \ b.end(), a[i]) - b.begin() + 1;\r\n    rmq.set(idx, rmq.get(0, idx) - 1);\r\n\
    \  }\r\n  return -rmq.get(0, b.size() + 1);\r\n}\r\n"
  dependsOn:
  - data_structure/segment_tree/segment_tree.hpp
  isVerificationFile: false
  path: dp/lis/lis_rmq.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dp/lis/lis_rmq.test.cpp
documentation_of: dp/lis/lis_rmq.hpp
layout: document
redirect_from:
- /library/dp/lis/lis_rmq.hpp
- /library/dp/lis/lis_rmq.hpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 RMQ \u7248"
---
# 最長増加部分列 (longest increasing subsequence)

任意の $i < j$ について $A_i < A_j$ を満たす部分列 $A$ の内，最長のものである．


## 時間計算量

$O(N\log{N})$


## 使用法

- 最長増加部分列

||説明|
|:--:|:--:|
|`lis(a, ∞)`|$A$ の最長増加部分列|

最長非減少部分列を求めるには `lower_bound` → `upper_bound`，最長減少部分列を求めるには元の列を逆にしたものの最長増加部分列を求めればよい．

- 2次元 LIS

||説明|
|:--:|:--:|
|`lis_2d(a, ∞)`|2次元配列 $A$ の最長増加部分列|

- 最長増加部分列 RMQ 版

||説明|
|:--:|:--:|
|`lis_rmq(a, ∞)`|$A$ の最長増加部分列長|


## 参考

- http://www.prefield.com/algorithm/dp/lis_fast.html

最長増加部分列 RMQ 版
- http://noshi91.hatenablog.com/entry/2018/02/03/204950


## ToDo

- longest Zig-Zag subsequence
  - https://github.com/spaghetti-source/algorithm/blob/master/dynamic_programming/longest_zigzag_subsequence.cc


## Verified

- [最長増加部分列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_D/review/4082142/emthrm/C++14)
- [2次元 LIS](https://atcoder.jp/contests/abc038/submissions/9237792)
- [最長増加部分列 RMQ 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_D/review/4084204/emthrm/C++14)
