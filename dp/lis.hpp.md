---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dp/lis.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/lis.md
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dp/lis.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\r\n * @docs docs/dp/lis.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <iterator>\r\n#include\
    \ <limits>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T>\
    \ lis(const std::vector<T> &a, bool is_strict = true) {\r\n  const T inf = std::numeric_limits<T>::max();\r\
    \n  int n = a.size();\r\n  std::vector<T> check(n, inf);\r\n  std::vector<int>\
    \ idx(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    if (is_strict) {\r\n     \
    \ idx[i] = std::distance(check.begin(), std::lower_bound(check.begin(), check.end(),\
    \ a[i]));\r\n    } else {\r\n      idx[i] = std::distance(check.begin(), std::upper_bound(check.begin(),\
    \ check.end(), a[i]));\r\n    }\r\n    check[idx[i]] = a[i];\r\n  }\r\n  int res_sz\
    \ = std::distance(check.begin(), std::lower_bound(check.begin(), check.end(),\
    \ inf));\r\n  std::vector<T> res(res_sz--);\r\n  for (int i = n - 1; res_sz >=\
    \ 0 && i >= 0; --i) {\r\n    if (idx[i] == res_sz) res[res_sz--] = a[i];\r\n \
    \ }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/lis.hpp
  requiredBy: []
  timestamp: '2021-03-04 19:21:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dp/lis.test.cpp
documentation_of: dp/lis.hpp
layout: document
redirect_from:
- /library/dp/lis.hpp
- /library/dp/lis.hpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
# 最長増加部分列 (longest increasing subsequence)

任意の $i < j$ について $A_i < A_j$ を満たす部分列 $A$ の内，最長のものである．


## 時間計算量

$O(N\log{N})$


## 使用法

- 最長増加部分列

||説明|
|:--:|:--:|
|`lis(a, 広義単調増加か? = true)`|$A$ の最長増加部分列|

- 2次元 LIS

||説明|
|:--:|:--:|
|`lis_2d(a)`|2次元配列 $A$ の最長増加部分列|


## 参考

- http://www.prefield.com/algorithm/dp/lis_fast.html
- http://noshi91.hatenablog.com/entry/2018/02/03/204950


## ToDo

- longest Zig-Zag subsequence
  - https://github.com/spaghetti-source/algorithm/blob/master/dynamic_programming/longest_zigzag_subsequence.cc


## Verified

- [最長増加部分列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_D/review/4082142/emthrm/C++14)
- [2次元 LIS](https://atcoder.jp/contests/abc038/submissions/9237792)
