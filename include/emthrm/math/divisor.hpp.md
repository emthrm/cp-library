---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/divisor.test.cpp
    title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/divisor.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T>\
    \ divisor(const T n) {\n  std::vector<T> res;\n  T i = 1;\n  for (; i * i < n;\
    \ ++i) {\n    if (n % i == 0) [[unlikely]] {\n      res.emplace_back(i);\n   \
    \   res.emplace_back(n / i);\n    }\n  }\n  if (i * i == n && n % i == 0) res.emplace_back(i);\n\
    \  std::sort(res.begin(), res.end());\n  return res;\n}\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_MATH_DIVISOR_HPP_\n#define EMTHRM_MATH_DIVISOR_HPP_\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    std::vector<T> divisor(const T n) {\n  std::vector<T> res;\n  T i = 1;\n  for\
    \ (; i * i < n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      res.emplace_back(i);\n\
    \      res.emplace_back(n / i);\n    }\n  }\n  if (i * i == n && n % i == 0) res.emplace_back(i);\n\
    \  std::sort(res.begin(), res.end());\n  return res;\n}\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_MATH_DIVISOR_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/divisor.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/divisor.test.cpp
documentation_of: include/emthrm/math/divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---


## 時間計算量

$O(\sqrt{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> divisor(const T n);`|$n$ の約数|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，p.111，マイナビ出版（2012）


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2932/review/4088339/emthrm/C++14
