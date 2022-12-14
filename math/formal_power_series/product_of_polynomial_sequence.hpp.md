---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/math/formal_power_series/product_of_polynomial_sequence.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u5217\
      \u306E\u76F8\u4E57"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/formal_power_series/product_of_polynomial_sequence.hpp\"\
    \n#include <queue>\n#include <vector>\n\ntemplate <template <typename> class C,\
    \ typename T>\nC<T> product_of_polynomial_sequence(std::vector<C<T>> a) {\n  const\
    \ int n = a.size();\n  if (n == 0) return C<T>{1};\n  for (int i = 0; i < n; ++i)\
    \ {\n    a[i].shrink();\n  }\n  const auto compare = [&a](const int l, const int\
    \ r) -> bool {\n    return a[l].degree() > a[r].degree();\n  };\n  std::priority_queue<int,\
    \ std::vector<int>, decltype(compare)> que(compare);\n  for (int i = 0; i < n;\
    \ ++i) {\n    que.emplace(i);\n  }\n  while (que.size() > 1) {\n    const int\
    \ i = que.top();\n    que.pop();\n    const int j = que.top();\n    que.pop();\n\
    \    a[j] *= a[i];\n    a[j].shrink();\n    a[i].coef.clear();\n    a[i].coef.shrink_to_fit();\n\
    \    que.emplace(j);\n  }\n  return a[que.top()];\n}\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\n\ntemplate <template <typename>\
    \ class C, typename T>\nC<T> product_of_polynomial_sequence(std::vector<C<T>>\
    \ a) {\n  const int n = a.size();\n  if (n == 0) return C<T>{1};\n  for (int i\
    \ = 0; i < n; ++i) {\n    a[i].shrink();\n  }\n  const auto compare = [&a](const\
    \ int l, const int r) -> bool {\n    return a[l].degree() > a[r].degree();\n \
    \ };\n  std::priority_queue<int, std::vector<int>, decltype(compare)> que(compare);\n\
    \  for (int i = 0; i < n; ++i) {\n    que.emplace(i);\n  }\n  while (que.size()\
    \ > 1) {\n    const int i = que.top();\n    que.pop();\n    const int j = que.top();\n\
    \    que.pop();\n    a[j] *= a[i];\n    a[j].shrink();\n    a[i].coef.clear();\n\
    \    a[i].coef.shrink_to_fit();\n    que.emplace(j);\n  }\n  return a[que.top()];\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/formal_power_series/product_of_polynomial_sequence.hpp
  requiredBy:
  - test/math/formal_power_series/product_of_polynomial_sequence.cpp
  timestamp: '2022-11-18 19:47:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/formal_power_series/product_of_polynomial_sequence.hpp
layout: document
title: "\u591A\u9805\u5F0F\u5217\u306E\u76F8\u4E57"
---

$$
  \prod_i f_i(x)
$$


## 使用法

||説明|
|:--:|:--:|
|`product_of_polynomial_sequence(f)`|$\prod_i f_i(x)$|


## Verified

https://judge.yosupo.jp/submission/113024
