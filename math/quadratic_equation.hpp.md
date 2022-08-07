---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/quadratic_equation.test.cpp
    title: "\u6570\u5B66/\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/quadratic_equation.hpp\"\n#include <cassert>\n#include\
    \ <cmath>\n#include <vector>\n\nstd::vector<double> quadratic_equation(double\
    \ a, double b, double c,\n                                       const double\
    \ eps = 1e-8) {\n  if (std::abs(a) < eps) {\n    if (std::abs(b) < eps) {\n  \
    \    assert(std::abs(c) >= eps);\n      return {};\n    }\n    return {-c / b};\n\
    \  }\n  double d = b * b - 4 * a * c;\n  if (d <= -eps) return {};\n  if (d <\
    \ eps) return {-0.5 * b / a};\n  d = std::sqrt(d);\n  const double x1 = -0.5 *\
    \ (b >= 0 ? b + d : b - d) / a, x2 = c / (x1 * a);\n  return x1 > x2 ? std::vector<double>{x2,\
    \ x1} : std::vector<double>{x1, x2};\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <vector>\n\n\
    std::vector<double> quadratic_equation(double a, double b, double c,\n       \
    \                                const double eps = 1e-8) {\n  if (std::abs(a)\
    \ < eps) {\n    if (std::abs(b) < eps) {\n      assert(std::abs(c) >= eps);\n\
    \      return {};\n    }\n    return {-c / b};\n  }\n  double d = b * b - 4 *\
    \ a * c;\n  if (d <= -eps) return {};\n  if (d < eps) return {-0.5 * b / a};\n\
    \  d = std::sqrt(d);\n  const double x1 = -0.5 * (b >= 0 ? b + d : b - d) / a,\
    \ x2 = c / (x1 * a);\n  return x1 > x2 ? std::vector<double>{x2, x1} : std::vector<double>{x1,\
    \ x2};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quadratic_equation.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/quadratic_equation.test.cpp
documentation_of: math/quadratic_equation.hpp
layout: document
title: "\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F (quadratic equation)"
---

$$
  ax^2 + bx + c = 0
$$


## 時間計算量

$O(1)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`quadratic_equation(a, b, c, ε = 1e-8)`|$ax^2 + bx + c = 0$ を満たす $x$|$a, b, c$ のいずれかは非零でなければならない．|


## 参考

- https://yukicoder.me/problems/no/955/editorial


## ToDo

- 三次方程式 (cubic equation)
  - https://ja.wikipedia.org/wiki/%E4%B8%89%E6%AC%A1%E6%96%B9%E7%A8%8B%E5%BC%8F
  - https://tubo28.me/compprog/algorithm/cubic/
  - https://cafecoder.top/contests/test003/tasks/test003_b


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/1039/review/4338571/emthrm/C++14
