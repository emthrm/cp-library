---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/convex_hull_trick.1.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/convex_hull_trick.2.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotonically_increasing_query(x))"
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/convex_hull_trick.3.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotonically_decreasing_query(x))"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/convex_hull_trick.hpp\"\n// #include\
    \ <cassert>\r\n#include <deque>\r\n#include <utility>\r\n\r\ntemplate <typename\
    \ T, bool IS_MINIMIZED = true>\r\nstruct ConvexHullTrick {\r\n  ConvexHullTrick()\
    \ = default;\r\n\r\n  void add(T a, T b) {\r\n    if (!IS_MINIMIZED) {\r\n   \
    \   a = -a;\r\n      b = -b;\r\n    }\r\n    const Line line(a, b);\r\n    if\
    \ (deq.empty()) {\r\n      deq.emplace_back(line);\r\n    } else if (deq.back().first\
    \ >= a) {\r\n      if (deq.back().first == a) {\r\n        if (b >= deq.back().second)\
    \ return;\r\n        deq.pop_back();\r\n      }\r\n      for (int i = static_cast<int>(deq.size())\
    \ - 2; i >= 0; --i) {\r\n        if (!must_pop(deq[i], deq[i + 1], line)) break;\r\
    \n        deq.pop_back();\r\n      }\r\n      deq.emplace_back(line);\r\n    }\
    \ else {\r\n      if (deq.front().first == a) {\r\n        if (b >= deq.front().second)\
    \ return;\r\n        deq.pop_front();\r\n      }\r\n      while (deq.size() >=\
    \ 2 && must_pop(line, deq.front(), deq[1])) {\r\n        deq.pop_front();\r\n\
    \      }\r\n      deq.emplace_front(line);\r\n    }\r\n  }\r\n\r\n  T query(const\
    \ T x) const {\r\n    // assert(!deq.empty());\r\n    int lb = -1, ub = deq.size()\
    \ - 1;\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >> 1;\r\
    \n      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;\r\n    }\r\n  \
    \  return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);\r\n  }\r\n\r\n  T monotonically_increasing_query(const\
    \ T x) {\r\n    while (deq.size() >= 2 && f(deq.front(), x) >= f(deq[1], x)) {\r\
    \n      deq.pop_front();\r\n    }\r\n    return IS_MINIMIZED ? f(deq.front(),\
    \ x) : -f(deq.front(), x);\r\n  }\r\n\r\n  T monotonically_decreasing_query(const\
    \ T x) {\r\n    for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {\r\
    \n      if (f(deq[i], x) > f(deq[i + 1], x)) break;\r\n      deq.pop_back();\r\
    \n    }\r\n    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(), x);\r\n\
    \  }\r\n\r\n private:\r\n  using Line = std::pair<T, T>;\r\n\r\n  std::deque<Line>\
    \ deq;\r\n\r\n  using Real = long double;\r\n  bool must_pop(const Line& l1, const\
    \ Line& l2, const Line& l3) const {\r\n    const Real lhs =\r\n        static_cast<Real>(l3.second\
    \ - l2.second) / (l2.first - l3.first);\r\n    const Real rhs =\r\n        static_cast<Real>(l2.second\
    \ - l1.second) / (l1.first - l2.first);\r\n    return lhs <= rhs;\r\n    // const\
    \ T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;\r\n    //\
    \ const T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;\r\n\
    \    // return lhs_num * rhs_den <= rhs_num * lhs_den;\r\n  }\r\n\r\n  T f(const\
    \ Line& l, const T x) const { return l.first * x + l.second; }\r\n};\r\n"
  code: "#pragma once\r\n// #include <cassert>\r\n#include <deque>\r\n#include <utility>\r\
    \n\r\ntemplate <typename T, bool IS_MINIMIZED = true>\r\nstruct ConvexHullTrick\
    \ {\r\n  ConvexHullTrick() = default;\r\n\r\n  void add(T a, T b) {\r\n    if\
    \ (!IS_MINIMIZED) {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    const Line\
    \ line(a, b);\r\n    if (deq.empty()) {\r\n      deq.emplace_back(line);\r\n \
    \   } else if (deq.back().first >= a) {\r\n      if (deq.back().first == a) {\r\
    \n        if (b >= deq.back().second) return;\r\n        deq.pop_back();\r\n \
    \     }\r\n      for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {\r\
    \n        if (!must_pop(deq[i], deq[i + 1], line)) break;\r\n        deq.pop_back();\r\
    \n      }\r\n      deq.emplace_back(line);\r\n    } else {\r\n      if (deq.front().first\
    \ == a) {\r\n        if (b >= deq.front().second) return;\r\n        deq.pop_front();\r\
    \n      }\r\n      while (deq.size() >= 2 && must_pop(line, deq.front(), deq[1]))\
    \ {\r\n        deq.pop_front();\r\n      }\r\n      deq.emplace_front(line);\r\
    \n    }\r\n  }\r\n\r\n  T query(const T x) const {\r\n    // assert(!deq.empty());\r\
    \n    int lb = -1, ub = deq.size() - 1;\r\n    while (ub - lb > 1) {\r\n     \
    \ const int mid = (lb + ub) >> 1;\r\n      (f(deq[mid], x) < f(deq[mid + 1], x)\
    \ ? ub : lb) = mid;\r\n    }\r\n    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub],\
    \ x);\r\n  }\r\n\r\n  T monotonically_increasing_query(const T x) {\r\n    while\
    \ (deq.size() >= 2 && f(deq.front(), x) >= f(deq[1], x)) {\r\n      deq.pop_front();\r\
    \n    }\r\n    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);\r\
    \n  }\r\n\r\n  T monotonically_decreasing_query(const T x) {\r\n    for (int i\
    \ = static_cast<int>(deq.size()) - 2; i >= 0; --i) {\r\n      if (f(deq[i], x)\
    \ > f(deq[i + 1], x)) break;\r\n      deq.pop_back();\r\n    }\r\n    return IS_MINIMIZED\
    \ ? f(deq.back(), x) : -f(deq.back(), x);\r\n  }\r\n\r\n private:\r\n  using Line\
    \ = std::pair<T, T>;\r\n\r\n  std::deque<Line> deq;\r\n\r\n  using Real = long\
    \ double;\r\n  bool must_pop(const Line& l1, const Line& l2, const Line& l3) const\
    \ {\r\n    const Real lhs =\r\n        static_cast<Real>(l3.second - l2.second)\
    \ / (l2.first - l3.first);\r\n    const Real rhs =\r\n        static_cast<Real>(l2.second\
    \ - l1.second) / (l1.first - l2.first);\r\n    return lhs <= rhs;\r\n    // const\
    \ T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;\r\n    //\
    \ const T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;\r\n\
    \    // return lhs_num * rhs_den <= rhs_num * lhs_den;\r\n  }\r\n\r\n  T f(const\
    \ Line& l, const T x) const { return l.first * x + l.second; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/convex_hull_trick.1.test.cpp
  - test/dynamic_programming/convex_hull_trick.3.test.cpp
  - test/dynamic_programming/convex_hull_trick.2.test.cpp
documentation_of: dynamic_programming/convex_hull_trick.hpp
layout: document
title: convex hull trick
---

$xy$ 平面上の直線集合 $L$ を考える．

- $L$ に直線 $f(x) = ax + b$ を追加する．
- ある $x$ に対して $\min \lbrace f(x) \mid f \in L \rbrace$ を答える．

上のクエリを高速に処理できるテクニックである．


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|追加クエリ|amortized $O(1)$|
|解答クエリ|$O(\log{N})$|
|$x$ に単調性のある解答クエリ|amortized $O(1)$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`ConvexHullTrick<T, IS_MINIMIZED>()`|convex hull trick||
|`add(a, b)`|直線 $f(x) = ax + b$ を追加する．|傾きには単調性が必要である．|
|`query(x)`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$||
|`monotonically_increasing_query(x)`|`query(x)`|$x$ は単調増加しなければならない．|
|`monotonically_decreasing_query(x)`|`query(x)`|$x$ は単調減少しなければならない．|


## 参考

- http://satanic0258.hatenablog.com/entry/2016/08/16/181331
- https://ei1333.github.io/luzhiled/snippets/structure/convex-hull-trick-add-monotone.html


## ToDo

- 直線を削除できる．
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/RemovableCHT~~
  - https://codeforces.com/blog/entry/60514
- 追加する直線の傾きに単調性が必要ない．
  - https://sune2.hatenadiary.org/entry/20140310/1394440369
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/CHT-Ex~~
- $x \in \mathbb{Z}$
  - https://noshi91.hatenablog.com/entry/2021/03/23/200810
  - https://judge.yosupo.jp/submission/35152
- 永続 convex full trick
  - https://codeforces.com/blog/entry/51684


## Verified

- [`query(x)`](https://atcoder.jp/contests/dp/submissions/26064258)
- [`monotonically_increasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064281)
- [`monotonically_decreasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064320)
