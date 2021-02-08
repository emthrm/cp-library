---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/quadratic_equation.test.cpp
    title: "\u6570\u5B66/\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/quadratic_equation.hpp\"\n#include <cassert>\r\n#include\
    \ <cmath>\r\n#include <utility>\r\n#include <vector>\r\n\r\nstd::vector<double>\
    \ quadratic_equation(double a, double b, double c, const double EPS = 1e-8) {\r\
    \n  if (std::abs(a) < EPS) {\r\n    if (std::abs(b) < EPS) {\r\n      assert(std::abs(c)\
    \ >= EPS);\r\n      return {};\r\n    }\r\n    return {-c / b};\r\n  }\r\n  double\
    \ d = b * b - 4 * a * c;\r\n  if (std::abs(d) < EPS) return {-0.5 * b / a};\r\n\
    \  if (d <= -EPS) return {};\r\n  d = std::sqrt(d);\r\n  double x1 = -0.5 * (b\
    \ >= 0 ? b + d : b - d) / a, x2 = c / (x1 * a);\r\n  if (x1 > x2) std::swap(x1,\
    \ x2);\r\n  return {x1, x2};\r\n}\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <cmath>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\nstd::vector<double> quadratic_equation(double a, double\
    \ b, double c, const double EPS = 1e-8) {\r\n  if (std::abs(a) < EPS) {\r\n  \
    \  if (std::abs(b) < EPS) {\r\n      assert(std::abs(c) >= EPS);\r\n      return\
    \ {};\r\n    }\r\n    return {-c / b};\r\n  }\r\n  double d = b * b - 4 * a *\
    \ c;\r\n  if (std::abs(d) < EPS) return {-0.5 * b / a};\r\n  if (d <= -EPS) return\
    \ {};\r\n  d = std::sqrt(d);\r\n  double x1 = -0.5 * (b >= 0 ? b + d : b - d)\
    \ / a, x2 = c / (x1 * a);\r\n  if (x1 > x2) std::swap(x1, x2);\r\n  return {x1,\
    \ x2};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quadratic_equation.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/quadratic_equation.test.cpp
documentation_of: math/quadratic_equation.hpp
layout: document
title: "\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F (quadratic equation)"
---

$$ax^2 + bx + c = 0 \text{．}$$


## 時間計算量

$O(1)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`quadratic_equation(a, b, c, ε = 1e-8)`|$x \text{ s.t. } ax^2 + bx + c = 0$|$a, b, c$ のいずれかは非零でなければならない．|


## 参考

- https://yukicoder.me/problems/no/955/editorial


## ToDo

- 三次方程式 (cubic equation)
  - https://ja.wikipedia.org/wiki/%E4%B8%89%E6%AC%A1%E6%96%B9%E7%A8%8B%E5%BC%8F
  - https://tubo28.me/compprog/algorithm/cubic/


## Verify

https://onlinejudge.u-aizu.ac.jp/solutions/problem/1039/review/4338571/emthrm/C++14
