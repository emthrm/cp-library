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
  bundledCode: "#line 1 \"include/emthrm/data_structure/slope_trick.hpp\"\n\n\n\n\
    #include <cassert>\n#include <functional>\n#include <limits>\n#include <numeric>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\
    \ntemplate <typename T>\nstruct SlopeTrick {\n  const T inf;\n\n  explicit SlopeTrick(\n\
    \      const T min_f = 0, const T inf = std::numeric_limits<T>::max())\n     \
    \ : inf(inf), added_l(0), added_r(0), min_f(min_f) {}\n\n  T min() const { return\
    \ min_f; }\n  std::pair<T, T> argmin() const { return {top_l(), top_r()}; }\n\n\
    \  template <typename U>\n  U f(const U x) {\n    U f_x = min_f;\n    std::vector<T>\
    \ tmp;\n    for (; top_l() > x; l.pop()) {\n      const T t = top_l();\n     \
    \ f_x += t - x;\n      tmp.emplace_back(t);\n    }\n    for (; !tmp.empty(); tmp.pop_back())\
    \ {\n      emplace_l(tmp.back());\n    }\n    for (; top_r() < x; r.pop()) {\n\
    \      const T t = top_r();\n      f_x += x - t;\n      tmp.emplace_back(t);\n\
    \    }\n    for (; !tmp.empty(); tmp.pop_back()) {\n      emplace_r(tmp.back());\n\
    \    }\n    return f_x;\n  }\n\n  void constant_function(const T c) { min_f +=\
    \ c; }\n\n  void x_minus_a(const T a) {\n    const T t = top_l();\n    if (t <=\
    \ a) {\n      emplace_r(a);\n    } else {\n      min_f += t - a;\n      emplace_l(a);\n\
    \      l.pop();\n      emplace_r(t);\n    }\n  }\n\n  void a_minus_x(const T a)\
    \ {\n    const T t = top_r();\n    if (a <= t) {\n      emplace_l(a);\n    } else\
    \ {\n      min_f += a - t;\n      emplace_r(a);\n      r.pop();\n      emplace_l(t);\n\
    \    }\n  }\n\n  void abs_x_minus_a(const T a) {\n    x_minus_a(a);\n    a_minus_x(a);\n\
    \  }\n\n  void cumulative_min() {\n    while (!r.empty()) r.pop();\n    added_r\
    \ = 0;\n  }\n\n  void rcumulative_min() {\n    while (!l.empty()) l.pop();\n \
    \   added_l = 0;\n  }\n\n  void translate(const T a) { sliding_window_minimum(a,\
    \ a); }\n\n  void sliding_window_minimum(const T a, const T b) {\n    assert(a\
    \ <= b);\n    added_l += a;\n    added_r += b;\n  }\n\n private:\n  T added_l,\
    \ added_r, min_f;\n  std::priority_queue<T> l;\n  std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> r;\n\n  void emplace_l(const T a) { l.emplace(a - added_l);\
    \ }\n  void emplace_r(const T a) { r.emplace(a - added_r); }\n\n  T top_l() const\
    \ { return l.empty() ? -inf : l.top() + added_l; }\n  T top_r() const { return\
    \ r.empty() ? inf : r.top() + added_r; }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_SLOPE_TRICK_HPP_\n#define EMTHRM_DATA_STRUCTURE_SLOPE_TRICK_HPP_\n\
    \n#include <cassert>\n#include <functional>\n#include <limits>\n#include <numeric>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\
    \ntemplate <typename T>\nstruct SlopeTrick {\n  const T inf;\n\n  explicit SlopeTrick(\n\
    \      const T min_f = 0, const T inf = std::numeric_limits<T>::max())\n     \
    \ : inf(inf), added_l(0), added_r(0), min_f(min_f) {}\n\n  T min() const { return\
    \ min_f; }\n  std::pair<T, T> argmin() const { return {top_l(), top_r()}; }\n\n\
    \  template <typename U>\n  U f(const U x) {\n    U f_x = min_f;\n    std::vector<T>\
    \ tmp;\n    for (; top_l() > x; l.pop()) {\n      const T t = top_l();\n     \
    \ f_x += t - x;\n      tmp.emplace_back(t);\n    }\n    for (; !tmp.empty(); tmp.pop_back())\
    \ {\n      emplace_l(tmp.back());\n    }\n    for (; top_r() < x; r.pop()) {\n\
    \      const T t = top_r();\n      f_x += x - t;\n      tmp.emplace_back(t);\n\
    \    }\n    for (; !tmp.empty(); tmp.pop_back()) {\n      emplace_r(tmp.back());\n\
    \    }\n    return f_x;\n  }\n\n  void constant_function(const T c) { min_f +=\
    \ c; }\n\n  void x_minus_a(const T a) {\n    const T t = top_l();\n    if (t <=\
    \ a) {\n      emplace_r(a);\n    } else {\n      min_f += t - a;\n      emplace_l(a);\n\
    \      l.pop();\n      emplace_r(t);\n    }\n  }\n\n  void a_minus_x(const T a)\
    \ {\n    const T t = top_r();\n    if (a <= t) {\n      emplace_l(a);\n    } else\
    \ {\n      min_f += a - t;\n      emplace_r(a);\n      r.pop();\n      emplace_l(t);\n\
    \    }\n  }\n\n  void abs_x_minus_a(const T a) {\n    x_minus_a(a);\n    a_minus_x(a);\n\
    \  }\n\n  void cumulative_min() {\n    while (!r.empty()) r.pop();\n    added_r\
    \ = 0;\n  }\n\n  void rcumulative_min() {\n    while (!l.empty()) l.pop();\n \
    \   added_l = 0;\n  }\n\n  void translate(const T a) { sliding_window_minimum(a,\
    \ a); }\n\n  void sliding_window_minimum(const T a, const T b) {\n    assert(a\
    \ <= b);\n    added_l += a;\n    added_r += b;\n  }\n\n private:\n  T added_l,\
    \ added_r, min_f;\n  std::priority_queue<T> l;\n  std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> r;\n\n  void emplace_l(const T a) { l.emplace(a - added_l);\
    \ }\n  void emplace_r(const T a) { r.emplace(a - added_r); }\n\n  T top_l() const\
    \ { return l.empty() ? -inf : l.top() + added_l; }\n  T top_r() const { return\
    \ r.empty() ? inf : r.top() + added_r; }\n};\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_DATA_STRUCTURE_SLOPE_TRICK_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/slope_trick.test.cpp
documentation_of: include/emthrm/data_structure/slope_trick.hpp
layout: document
title: slope trick
---

各区分の傾きが整数な凸区分線形関数 (convex piecewise linear function) を管理するテクニック


## 時間計算量

区分の数を $N$ とおく。

||時間計算量|
|:--|:--|
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


## 仕様

```cpp
template <typename T>
struct SegmentTree;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`const T inf`|$\infty$|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit SlopeTrick(const T min_f = 0, const T inf = std::numeric_limits<T>::max());`|$f(x) = \mathrm{minF}$ を管理する。||
|`T min() const;`|$\min_x f(x)$||
|`std::pair<T, T> argmin() const;`|$\mathrm{argmin}_x f(x)$||
|`template <typename U>`<br>`U f(const U x);`|$f(x)$|
|`void constant_function(const T c);`|$f(x) \gets f(x) + c$||
|`void x_minus_a(const T a);`|$f(x) \gets f(x) + (x - a)^+$||
|`void a_minus_x(const T a);`|$f(x) \gets f(x) + (a - x)^+$||
|`void abs_x_minus_a(const T a);`|$f(x) \gets f(x) + \lvert x - a \rvert$||
|`void cumulative_min();`|$f(x) \gets \min \lbrace f(y) \mid y \leq x \rbrace$||
|`void rcumulative_min();`|$f(x) \gets \min \lbrace f(y) \mid y \geq x \rbrace$||
|`void translate(const T a);`|$f(x) \gets f(x - a)$||
|`void sliding_window_minimum(const T a, const T b);`|$f(x) \gets \min \lbrace f(y) \mid y \in \lbrack x - b, x - a \rbrack \rbrace$|$a \leq b$|


## 参考文献

- https://codeforces.com/blog/entry/47821
- https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
- https://github.com/ei1333/library/blob/6c2f9fa7ff07da182f3832f827c0c84d52e2e8d8/structure/others/slope-trick.cpp


## TODO

- 一般化
  - https://github.com/ei1333/library/blob/af69da96544930d59e797c12ca977918df5e2a58/structure/others/generalized-slope-trick.cpp


## Submissons

https://atcoder.jp/contests/arc123/submissions/24994392
