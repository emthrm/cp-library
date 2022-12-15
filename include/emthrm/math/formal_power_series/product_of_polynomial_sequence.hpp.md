---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/formal_power_series/product_of_polynomial_sequence.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u5217\
      \u306E\u76F8\u4E57"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/formal_power_series/product_of_polynomial_sequence.hpp\"\
    \n\n\n\n#include <queue>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <template <typename> class C, typename T>\nC<T> product_of_polynomial_sequence(std::vector<C<T>>\
    \ a) {\n  const int n = a.size();\n  if (n == 0) return C<T>{1};\n  for (int i\
    \ = 0; i < n; ++i) {\n    a[i].shrink();\n  }\n  const auto compare = [&a](const\
    \ int l, const int r) -> bool {\n    return a[l].degree() > a[r].degree();\n \
    \ };\n  std::priority_queue<int, std::vector<int>, decltype(compare)> que(compare);\n\
    \  for (int i = 0; i < n; ++i) {\n    que.emplace(i);\n  }\n  while (que.size()\
    \ > 1) {\n    const int i = que.top();\n    que.pop();\n    const int j = que.top();\n\
    \    que.pop();\n    a[j] *= a[i];\n    a[j].shrink();\n    a[i].coef.clear();\n\
    \    a[i].coef.shrink_to_fit();\n    que.emplace(j);\n  }\n  return a[que.top()];\n\
    }\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_\n\n\
    #include <queue>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <template\
    \ <typename> class C, typename T>\nC<T> product_of_polynomial_sequence(std::vector<C<T>>\
    \ a) {\n  const int n = a.size();\n  if (n == 0) return C<T>{1};\n  for (int i\
    \ = 0; i < n; ++i) {\n    a[i].shrink();\n  }\n  const auto compare = [&a](const\
    \ int l, const int r) -> bool {\n    return a[l].degree() > a[r].degree();\n \
    \ };\n  std::priority_queue<int, std::vector<int>, decltype(compare)> que(compare);\n\
    \  for (int i = 0; i < n; ++i) {\n    que.emplace(i);\n  }\n  while (que.size()\
    \ > 1) {\n    const int i = que.top();\n    que.pop();\n    const int j = que.top();\n\
    \    que.pop();\n    a[j] *= a[i];\n    a[j].shrink();\n    a[i].coef.clear();\n\
    \    a[i].coef.shrink_to_fit();\n    que.emplace(j);\n  }\n  return a[que.top()];\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/product_of_polynomial_sequence.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/formal_power_series/product_of_polynomial_sequence.test.cpp
documentation_of: include/emthrm/math/formal_power_series/product_of_polynomial_sequence.hpp
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
