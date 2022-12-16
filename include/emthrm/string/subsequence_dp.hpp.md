---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/subsequence_dp.test.cpp
    title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/subsequence_dp.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <string>\n#include <vector>\n\nnamespace emthrm {\n\n\
    std::vector<std::vector<int>> subsequence_dp(\n    const std::string& s, const\
    \ char basis = 'a', const int sigma = 26) {\n  const int n = s.length();\n  std::vector<std::vector<int>>\
    \ nx(n, std::vector<int>(sigma, n));\n  nx[n - 1][s[n - 1] - basis] = n - 1;\n\
    \  for (int i = n - 2; i >= 0; --i) {\n    std::copy(nx[i + 1].begin(), nx[i +\
    \ 1].end(), nx[i].begin());\n    nx[i][s[i] - basis] = i;\n  }\n  return nx;\n\
    }\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_SUBSEQUENCE_DP_HPP_\n#define EMTHRM_STRING_SUBSEQUENCE_DP_HPP_\n\
    \n#include <algorithm>\n#include <string>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\nstd::vector<std::vector<int>> subsequence_dp(\n    const std::string& s,\
    \ const char basis = 'a', const int sigma = 26) {\n  const int n = s.length();\n\
    \  std::vector<std::vector<int>> nx(n, std::vector<int>(sigma, n));\n  nx[n -\
    \ 1][s[n - 1] - basis] = n - 1;\n  for (int i = n - 2; i >= 0; --i) {\n    std::copy(nx[i\
    \ + 1].begin(), nx[i + 1].end(), nx[i].begin());\n    nx[i][s[i] - basis] = i;\n\
    \  }\n  return nx;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_SUBSEQUENCE_DP_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/subsequence_dp.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/subsequence_dp.test.cpp
documentation_of: include/emthrm/string/subsequence_dp.hpp
layout: document
title: "\u90E8\u5206\u5217 DP"
---


## 時間計算量

$O(\sigma \lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`subsequence_dp(s, 基準 = 'a', σ = 26)`|$S$ の $i$ 文字目以降 (inclusive) で最初に文字 $c$ が現れるインデックス|


## 参考

- https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd


## Verified

https://atcoder.jp/contests/arc081/submissions/26043202
