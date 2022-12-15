---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/z_algorithm.test.cpp
    title: "\u6587\u5B57\u5217/Z algorithm"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/z_algorithm.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    std::vector<int> z_algorithm(const T &s) {\n  const int n = s.size();\n  std::vector<int>\
    \ res(n, 0);\n  for (int i = 1, j = 0; i < n; ++i) {\n    if (i + res[i - j] <\
    \ j + res[j]) {\n      res[i] = res[i - j];\n    } else {\n      res[i] = std::max(j\
    \ + res[j] - i, 0);\n      while (i + res[i] < n && s[i + res[i]] == s[res[i]])\
    \ ++res[i];\n      j = i;\n    }\n  }\n  res[0] = n;\n  return res;\n}\n\n}  //\
    \ namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_Z_ALGORITHM_HPP_\n#define EMTHRM_STRING_Z_ALGORITHM_HPP_\n\
    \n#include <algorithm>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T>\nstd::vector<int> z_algorithm(const T &s) {\n  const int n = s.size();\n\
    \  std::vector<int> res(n, 0);\n  for (int i = 1, j = 0; i < n; ++i) {\n    if\
    \ (i + res[i - j] < j + res[j]) {\n      res[i] = res[i - j];\n    } else {\n\
    \      res[i] = std::max(j + res[j] - i, 0);\n      while (i + res[i] < n && s[i\
    \ + res[i]] == s[res[i]]) ++res[i];\n      j = i;\n    }\n  }\n  res[0] = n;\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_Z_ALGORITHM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/z_algorithm.test.cpp
documentation_of: include/emthrm/string/z_algorithm.hpp
layout: document
title: Z algorithm
---

文字列 $S$ に対して $S$ と `S[i:]` の最長共通接頭辞の長さを求めるアルゴリズムである．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`z_algorithm(s)`|$S$ と `S[i:]` の最長共通接頭辞の長さ|


## 参考

- https://snuke.hatenablog.com/entry/2014/12/03/214243
- https://sen-comp.hatenablog.com/entry/2020/01/16/174230


## TODO

- 動的 Z algorithm
  - https://heno239.hatenablog.com/entry/2020/07/07/140651


## Verified

https://judge.yosupo.jp/submission/27816
