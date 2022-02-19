---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/longest_increasing_subsequence.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dynamic_programming/longest_increasing_subsequence.md
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dynamic_programming/longest_increasing_subsequence.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/**\r\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\r\n * @docs docs/dynamic_programming/longest_increasing_subsequence.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <iterator>\r\n#include\
    \ <limits>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T>\
    \ longest_increasing_subsequence(\r\n    const std::vector<T>& a, const bool is_strict\
    \ = true) {\r\n  const T inf = std::numeric_limits<T>::max();\r\n  const int n\
    \ = a.size();\r\n  std::vector<int> idx(n);\r\n  std::vector<T> tmp(n, inf);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    if (is_strict) {\r\n      idx[i] = std::distance(tmp.begin(),\r\
    \n                             std::lower_bound(tmp.begin(), tmp.end(), a[i]));\r\
    \n    } else {\r\n      idx[i] = std::distance(tmp.begin(),\r\n              \
    \               std::upper_bound(tmp.begin(), tmp.end(), a[i]));\r\n    }\r\n\
    \    tmp[idx[i]] = a[i];\r\n  }\r\n  int res_size =\r\n      std::distance(tmp.begin(),\
    \ std::lower_bound(tmp.begin(), tmp.end(), inf));\r\n  std::vector<T> res(res_size--);\r\
    \n  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {\r\n    if (idx[i] == res_size)\
    \ res[res_size--] = a[i];\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2022-02-12 20:37:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/longest_increasing_subsequence.test.cpp
documentation_of: dynamic_programming/longest_increasing_subsequence.hpp
layout: document
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (longest increasing subsequence)"
---

$i < j$ を満たす任意の $i, j$ に対して $A_i < A_j$ を満たす部分列 $A$ の内，最長のものである．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`longest_increasing_subsequence(a, 広義単調増加か? = true)`|$A$ の最長増加部分列|


## 参考

- http://www.prefield.com/algorithm/dp/lis_fast.html
- http://noshi91.hatenablog.com/entry/2018/02/03/204950


## ToDo

- longest Zig-Zag subsequence
  - https://github.com/spaghetti-source/algorithm/blob/master/dynamic_programming/longest_zigzag_subsequence.cc
- range longest increasing subsequence query
  - https://twitter.com/noshi91/status/1388201116148539393
  - https://judge.yosupo.jp/problem/static_range_lis_query


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_D/review/4082142/emthrm/C++14
