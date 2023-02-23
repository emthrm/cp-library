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
    \ a) {\n  const int n = a.size();\n  if (n == 0) [[unlikely]] return C<T>{1};\n\
    \  for (int i = 0; i < n; ++i) {\n    a[i].shrink();\n  }\n  const auto compare\
    \ = [&a](const int l, const int r) -> bool {\n    return a[l].degree() > a[r].degree();\n\
    \  };\n  std::priority_queue<int, std::vector<int>, decltype(compare)> que(compare);\n\
    \  for (int i = 0; i < n; ++i) {\n    que.emplace(i);\n  }\n  while (que.size()\
    \ > 1) {\n    const int i = que.top();\n    que.pop();\n    const int j = que.top();\n\
    \    que.pop();\n    a[j] *= a[i];\n    a[j].shrink();\n    a[i].coef.clear();\n\
    \    a[i].coef.shrink_to_fit();\n    que.emplace(j);\n  }\n  return a[que.top()];\n\
    }\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_\n\n\
    #include <queue>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <template\
    \ <typename> class C, typename T>\nC<T> product_of_polynomial_sequence(std::vector<C<T>>\
    \ a) {\n  const int n = a.size();\n  if (n == 0) [[unlikely]] return C<T>{1};\n\
    \  for (int i = 0; i < n; ++i) {\n    a[i].shrink();\n  }\n  const auto compare\
    \ = [&a](const int l, const int r) -> bool {\n    return a[l].degree() > a[r].degree();\n\
    \  };\n  std::priority_queue<int, std::vector<int>, decltype(compare)> que(compare);\n\
    \  for (int i = 0; i < n; ++i) {\n    que.emplace(i);\n  }\n  while (que.size()\
    \ > 1) {\n    const int i = que.top();\n    que.pop();\n    const int j = que.top();\n\
    \    que.pop();\n    a[j] *= a[i];\n    a[j].shrink();\n    a[i].coef.clear();\n\
    \    a[i].coef.shrink_to_fit();\n    que.emplace(j);\n  }\n  return a[que.top()];\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/product_of_polynomial_sequence.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
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


## 仕様

|名前|戻り値|備考|
|:--|:--|:--|
|`template <template <typename> class C, typename T>`<br>`C<T> product_of_polynomial_sequence(std::vector<C<T>> a);`|$\prod_i f_i(x)$|`C` は冪級数を表す構造体である。|


## Submissons

https://judge.yosupo.jp/submission/113024
