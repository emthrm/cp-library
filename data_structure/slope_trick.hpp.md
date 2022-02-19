---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/slope_trick.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/slope_trick.hpp\"\n#include <cassert>\r\n\
    #include <functional>\r\n#include <limits>\r\n#include <numeric>\r\n#include <queue>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct\
    \ SlopeTrick {\r\n  const T inf;\r\n\r\n  explicit SlopeTrick(\r\n      const\
    \ T min_f = 0, const T inf = std::numeric_limits<T>::max())\r\n      : added_l(0),\
    \ added_r(0), min_f(min_f), inf(inf) {}\r\n\r\n  T min() const { return min_f;\
    \ }\r\n  std::pair<T, T> argmin() const { return {top_l(), top_r()}; }\r\n\r\n\
    \  template <typename U>\r\n  U f(const U x) {\r\n    U f_x = min_f;\r\n    std::vector<T>\
    \ tmp;\r\n    for (; top_l() > x; l.pop()) {\r\n      const T t = top_l();\r\n\
    \      f_x += t - x;\r\n      tmp.emplace_back(t);\r\n    }\r\n    for (; !tmp.empty();\
    \ tmp.pop_back()) {\r\n      emplace_l(tmp.back());\r\n    }\r\n    for (; top_r()\
    \ < x; r.pop()) {\r\n      const T t = top_r();\r\n      f_x += x - t;\r\n   \
    \   tmp.emplace_back(t);\r\n    }\r\n    for (; !tmp.empty(); tmp.pop_back())\
    \ {\r\n      emplace_r(tmp.back());\r\n    }\r\n    return f_x;\r\n  }\r\n\r\n\
    \  void constant_function(const T c) { min_f += c; }\r\n\r\n  void x_minus_a(const\
    \ T a) {\r\n    const T t = top_l();\r\n    if (t <= a) {\r\n      emplace_r(a);\r\
    \n    } else {\r\n      min_f += t - a;\r\n      emplace_l(a);\r\n      l.pop();\r\
    \n      emplace_r(t);\r\n    }\r\n  }\r\n\r\n  void a_minus_x(const T a) {\r\n\
    \    const T t = top_r();\r\n    if (a <= t) {\r\n      emplace_l(a);\r\n    }\
    \ else {\r\n      min_f += a - t;\r\n      emplace_r(a);\r\n      r.pop();\r\n\
    \      emplace_l(t);\r\n    }\r\n  }\r\n\r\n  void abs_x_minus_a(const T a) {\r\
    \n    x_minus_a(a);\r\n    a_minus_x(a);\r\n  }\r\n\r\n  void cumulative_min()\
    \ {\r\n    while (!r.empty()) r.pop();\r\n    added_r = 0;\r\n  }\r\n\r\n  void\
    \ rcumulative_min() {\r\n    while (!l.empty()) l.pop();\r\n    added_l = 0;\r\
    \n  }\r\n\r\n  void translate(const T a) { sliding_window_minimum(a, a); }\r\n\
    \r\n  void sliding_window_minimum(const T a, const T b) {\r\n    assert(a <= b);\r\
    \n    added_l += a;\r\n    added_r += b;\r\n  }\r\n\r\n private:\r\n  T added_l,\
    \ added_r, min_f;\r\n  std::priority_queue<T> l;\r\n  std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> r;\r\n\r\n  void emplace_l(const T a) { l.emplace(a - added_l);\
    \ }\r\n  void emplace_r(const T a) { r.emplace(a - added_r); }\r\n\r\n  T top_l()\
    \ const { return l.empty() ? -inf : l.top() + added_l; }\r\n  T top_r() const\
    \ { return r.empty() ? inf : r.top() + added_r; }\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <functional>\r\n#include <limits>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstruct SlopeTrick {\r\n  const T inf;\r\n\r\n \
    \ explicit SlopeTrick(\r\n      const T min_f = 0, const T inf = std::numeric_limits<T>::max())\r\
    \n      : added_l(0), added_r(0), min_f(min_f), inf(inf) {}\r\n\r\n  T min() const\
    \ { return min_f; }\r\n  std::pair<T, T> argmin() const { return {top_l(), top_r()};\
    \ }\r\n\r\n  template <typename U>\r\n  U f(const U x) {\r\n    U f_x = min_f;\r\
    \n    std::vector<T> tmp;\r\n    for (; top_l() > x; l.pop()) {\r\n      const\
    \ T t = top_l();\r\n      f_x += t - x;\r\n      tmp.emplace_back(t);\r\n    }\r\
    \n    for (; !tmp.empty(); tmp.pop_back()) {\r\n      emplace_l(tmp.back());\r\
    \n    }\r\n    for (; top_r() < x; r.pop()) {\r\n      const T t = top_r();\r\n\
    \      f_x += x - t;\r\n      tmp.emplace_back(t);\r\n    }\r\n    for (; !tmp.empty();\
    \ tmp.pop_back()) {\r\n      emplace_r(tmp.back());\r\n    }\r\n    return f_x;\r\
    \n  }\r\n\r\n  void constant_function(const T c) { min_f += c; }\r\n\r\n  void\
    \ x_minus_a(const T a) {\r\n    const T t = top_l();\r\n    if (t <= a) {\r\n\
    \      emplace_r(a);\r\n    } else {\r\n      min_f += t - a;\r\n      emplace_l(a);\r\
    \n      l.pop();\r\n      emplace_r(t);\r\n    }\r\n  }\r\n\r\n  void a_minus_x(const\
    \ T a) {\r\n    const T t = top_r();\r\n    if (a <= t) {\r\n      emplace_l(a);\r\
    \n    } else {\r\n      min_f += a - t;\r\n      emplace_r(a);\r\n      r.pop();\r\
    \n      emplace_l(t);\r\n    }\r\n  }\r\n\r\n  void abs_x_minus_a(const T a) {\r\
    \n    x_minus_a(a);\r\n    a_minus_x(a);\r\n  }\r\n\r\n  void cumulative_min()\
    \ {\r\n    while (!r.empty()) r.pop();\r\n    added_r = 0;\r\n  }\r\n\r\n  void\
    \ rcumulative_min() {\r\n    while (!l.empty()) l.pop();\r\n    added_l = 0;\r\
    \n  }\r\n\r\n  void translate(const T a) { sliding_window_minimum(a, a); }\r\n\
    \r\n  void sliding_window_minimum(const T a, const T b) {\r\n    assert(a <= b);\r\
    \n    added_l += a;\r\n    added_r += b;\r\n  }\r\n\r\n private:\r\n  T added_l,\
    \ added_r, min_f;\r\n  std::priority_queue<T> l;\r\n  std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> r;\r\n\r\n  void emplace_l(const T a) { l.emplace(a - added_l);\
    \ }\r\n  void emplace_r(const T a) { r.emplace(a - added_r); }\r\n\r\n  T top_l()\
    \ const { return l.empty() ? -inf : l.top() + added_l; }\r\n  T top_r() const\
    \ { return r.empty() ? inf : r.top() + added_r; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/slope_trick.test.cpp
documentation_of: data_structure/slope_trick.hpp
layout: document
title: slope trick
---

各区分の傾きが整数な凸区分線形関数 (convex piecewise linear function) を管理するテクニック


## 時間計算量

区分の数を $N$ とおく．

||時間計算量|
|:--:|:--:|
|最小値の取得|$O(1)$|
|$\mathrm{argmin}_x f(x)$|$O(1)$|
|$f(x)$|$O(N)$|
|定数の加算|$O(1)$|
|$(x - a)^+$ の加算|$O(\log{N})$|
|$(a - x)^+$ の加算|$O(\log{N})$|
|$\lvert x - a \rvert$ の加算|$O(\log{N})$|
|累積 $\min$|amortized $O(1)$|
|逆側累積 $\min$|amortized $O(1)$|
|平行移動|$O(1)$|
|スライド最小値|$O(1)$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`inf`|$\infty$||
|`SlopeTrick<T>(min_f = 0, ∞)`|$f(x) = \mathrm{min\_f}$ を管理する．||
|`min()`|$\min_x f(x)$||
|`argmin()`|$\mathrm{argmin}_x f(x)$||
|`f(x)`|$f(x)$|
|`constant_function(c)`|$f(x) \gets f(x) + c$||
|`x_minus_a(a)`|$f(x) \gets f(x) + (x - a)^+$||
|`a_minus_x(a)`|$f(x) \gets f(x) + (a - x)^+$||
|`abs_x_minus_a(a)`|$f(x) \gets f(x) + \lvert x - a \rvert$||
|`cumulative_min()`|$f(x) \gets \min_{y \leq x} f(y)$||
|`rumulative_min()`|$f(x) \gets \min_{y \geq x} f(y)$||
|`translate(a)`|$f(x) \gets f(x - a)$||
|`sliding_window_minimum(a, b)`|$f(x) \gets \min_{y \in \lbrack x - b, x - a \rbrack} f(y)$|$a \leq b$ でなければならない．|


## 参考

- https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
- https://github.com/ei1333/library/blob/6c2f9fa7ff07da182f3832f827c0c84d52e2e8d8/structure/others/slope-trick.cpp


## ToDo

- 一般化
  - https://github.com/ei1333/library/blob/af69da96544930d59e797c12ca977918df5e2a58/structure/others/generalized-slope-trick.cpp


## Verified

https://atcoder.jp/contests/arc123/submissions/24994392
