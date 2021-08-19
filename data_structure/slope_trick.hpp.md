---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/slope_trick.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/slope_trick.hpp\"\n#include <cassert>\r\n\
    #include <functional>\r\n#include <numeric>\r\n#include <queue>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct SlopeTrick {\r\n  const\
    \ T inf;\r\n\r\n  SlopeTrick(T min_f = 0, const T inf = std::numeric_limits<T>::max())\
    \ : min_f(min_f), inf(inf) {}\r\n\r\n  T min() const { return min_f; }\r\n\r\n\
    \  std::pair<T, T> argmin() const { return {top_l(), top_r()}; }\r\n\r\n  template\
    \ <typename U>\r\n  U f(U x) {\r\n    U f_x = min_f;\r\n    std::vector<T> tmp;\r\
    \n    while (top_l() > x) {\r\n      T t = top_l();\r\n      f_x += t - x;\r\n\
    \      tmp.emplace_back(t);\r\n      l.pop();\r\n    }\r\n    while (!tmp.empty())\
    \ {\r\n      emplace_l(tmp.back());\r\n      tmp.pop_back();\r\n    }\r\n    while\
    \ (top_r() < x) {\r\n      T t = top_r();\r\n      f_x += x - t;\r\n      tmp.emplace_back(t);\r\
    \n      r.pop();\r\n    }\r\n    while (!tmp.empty()) {\r\n      emplace_r(tmp.back());\r\
    \n      tmp.pop_back();\r\n    }\r\n    return f_x;\r\n  }\r\n\r\n  void constant_function(T\
    \ c) { min_f += c; }\r\n\r\n  void x_minus_a(T a) {\r\n    T t = top_l();\r\n\
    \    if (t <= a) {\r\n      emplace_r(a);\r\n    } else {\r\n      min_f += t\
    \ - a;\r\n      emplace_l(a);\r\n      l.pop();\r\n      emplace_r(t);\r\n   \
    \ }\r\n  }\r\n\r\n  void a_minus_x(T a) {\r\n    T t = top_r();\r\n    if (a <=\
    \ t) {\r\n      emplace_l(a);\r\n    } else {\r\n      min_f += a - t;\r\n   \
    \   emplace_r(a);\r\n      r.pop();\r\n      emplace_l(t);\r\n    }\r\n  }\r\n\
    \r\n  void abs_x_minus_a(T a) {\r\n    x_minus_a(a);\r\n    a_minus_x(a);\r\n\
    \  }\r\n\r\n  void cumulative_min() {\r\n    while (!r.empty()) r.pop();\r\n \
    \   add_r = 0;\r\n  }\r\n\r\n  void rcumulative_min() {\r\n    while (!l.empty())\
    \ l.pop();\r\n    add_l = 0;\r\n  }\r\n\r\n  void translate(T a) { sliding_window_minimum(a,\
    \ a); }\r\n\r\n  void sliding_window_minimum(T a, T b) {\r\n    assert(a <= b);\r\
    \n    add_l += a;\r\n    add_r += b;\r\n  }\r\n\r\nprivate:\r\n  T add_l = 0,\
    \ add_r = 0, min_f;\r\n  std::priority_queue<T> l;\r\n  std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> r;\r\n\r\n  void emplace_l(T a) { l.emplace(a\
    \ - add_l); }\r\n\r\n  void emplace_r(T a) { r.emplace(a - add_r); }\r\n\r\n \
    \ T top_l() const { return l.empty() ? -inf : l.top() + add_l; }\r\n\r\n  T top_r()\
    \ const { return r.empty() ? inf : r.top() + add_r; }\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <functional>\r\n#include <numeric>\r\
    \n#include <queue>\r\n#include <utility>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstruct SlopeTrick {\r\n  const T inf;\r\n\r\n  SlopeTrick(T\
    \ min_f = 0, const T inf = std::numeric_limits<T>::max()) : min_f(min_f), inf(inf)\
    \ {}\r\n\r\n  T min() const { return min_f; }\r\n\r\n  std::pair<T, T> argmin()\
    \ const { return {top_l(), top_r()}; }\r\n\r\n  template <typename U>\r\n  U f(U\
    \ x) {\r\n    U f_x = min_f;\r\n    std::vector<T> tmp;\r\n    while (top_l()\
    \ > x) {\r\n      T t = top_l();\r\n      f_x += t - x;\r\n      tmp.emplace_back(t);\r\
    \n      l.pop();\r\n    }\r\n    while (!tmp.empty()) {\r\n      emplace_l(tmp.back());\r\
    \n      tmp.pop_back();\r\n    }\r\n    while (top_r() < x) {\r\n      T t = top_r();\r\
    \n      f_x += x - t;\r\n      tmp.emplace_back(t);\r\n      r.pop();\r\n    }\r\
    \n    while (!tmp.empty()) {\r\n      emplace_r(tmp.back());\r\n      tmp.pop_back();\r\
    \n    }\r\n    return f_x;\r\n  }\r\n\r\n  void constant_function(T c) { min_f\
    \ += c; }\r\n\r\n  void x_minus_a(T a) {\r\n    T t = top_l();\r\n    if (t <=\
    \ a) {\r\n      emplace_r(a);\r\n    } else {\r\n      min_f += t - a;\r\n   \
    \   emplace_l(a);\r\n      l.pop();\r\n      emplace_r(t);\r\n    }\r\n  }\r\n\
    \r\n  void a_minus_x(T a) {\r\n    T t = top_r();\r\n    if (a <= t) {\r\n   \
    \   emplace_l(a);\r\n    } else {\r\n      min_f += a - t;\r\n      emplace_r(a);\r\
    \n      r.pop();\r\n      emplace_l(t);\r\n    }\r\n  }\r\n\r\n  void abs_x_minus_a(T\
    \ a) {\r\n    x_minus_a(a);\r\n    a_minus_x(a);\r\n  }\r\n\r\n  void cumulative_min()\
    \ {\r\n    while (!r.empty()) r.pop();\r\n    add_r = 0;\r\n  }\r\n\r\n  void\
    \ rcumulative_min() {\r\n    while (!l.empty()) l.pop();\r\n    add_l = 0;\r\n\
    \  }\r\n\r\n  void translate(T a) { sliding_window_minimum(a, a); }\r\n\r\n  void\
    \ sliding_window_minimum(T a, T b) {\r\n    assert(a <= b);\r\n    add_l += a;\r\
    \n    add_r += b;\r\n  }\r\n\r\nprivate:\r\n  T add_l = 0, add_r = 0, min_f;\r\
    \n  std::priority_queue<T> l;\r\n  std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ r;\r\n\r\n  void emplace_l(T a) { l.emplace(a - add_l); }\r\n\r\n  void emplace_r(T\
    \ a) { r.emplace(a - add_r); }\r\n\r\n  T top_l() const { return l.empty() ? -inf\
    \ : l.top() + add_l; }\r\n\r\n  T top_r() const { return r.empty() ? inf : r.top()\
    \ + add_r; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2021-08-13 20:19:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
|累積 $\min$|$\text{amortized } O(1)$|
|逆側累積 $\min$|$\text{amortized } O(1)$|
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
