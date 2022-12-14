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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dynamic_programming/longest_increasing_subsequence.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n * @docs docs/dynamic_programming/longest_increasing_subsequence.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <iterator>\n#include <limits>\n\
    #include <vector>\n\ntemplate <typename T>\nstd::vector<T> longest_increasing_subsequence(\n\
    \    const std::vector<T>& a, const bool is_strict = true) {\n  const T inf =\
    \ std::numeric_limits<T>::max();\n  const int n = a.size();\n  std::vector<int>\
    \ idx(n);\n  std::vector<T> tmp(n, inf);\n  for (int i = 0; i < n; ++i) {\n  \
    \  if (is_strict) {\n      idx[i] = std::distance(tmp.begin(),\n             \
    \                std::lower_bound(tmp.begin(), tmp.end(), a[i]));\n    } else\
    \ {\n      idx[i] = std::distance(tmp.begin(),\n                             std::upper_bound(tmp.begin(),\
    \ tmp.end(), a[i]));\n    }\n    tmp[idx[i]] = a[i];\n  }\n  int res_size =\n\
    \      std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), inf));\n\
    \  std::vector<T> res(res_size--);\n  for (int i = n - 1; res_size >= 0 && i >=\
    \ 0; --i) {\n    if (idx[i] == res_size) res[res_size--] = a[i];\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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

https://judge.yosupo.jp/submission/99391
