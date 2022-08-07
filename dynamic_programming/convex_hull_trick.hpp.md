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
    \ <cassert>\n#include <deque>\n#include <utility>\n\ntemplate <typename T, bool\
    \ IS_MINIMIZED = true>\nstruct ConvexHullTrick {\n  ConvexHullTrick() = default;\n\
    \n  void add(T a, T b) {\n    if (!IS_MINIMIZED) {\n      a = -a;\n      b = -b;\n\
    \    }\n    const Line line(a, b);\n    if (deq.empty()) {\n      deq.emplace_back(line);\n\
    \    } else if (deq.back().first >= a) {\n      if (deq.back().first == a) {\n\
    \        if (b >= deq.back().second) return;\n        deq.pop_back();\n      }\n\
    \      for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {\n       \
    \ if (!must_pop(deq[i], deq[i + 1], line)) break;\n        deq.pop_back();\n \
    \     }\n      deq.emplace_back(line);\n    } else {\n      if (deq.front().first\
    \ == a) {\n        if (b >= deq.front().second) return;\n        deq.pop_front();\n\
    \      }\n      while (deq.size() >= 2 && must_pop(line, deq.front(), deq[1]))\
    \ {\n        deq.pop_front();\n      }\n      deq.emplace_front(line);\n    }\n\
    \  }\n\n  T query(const T x) const {\n    // assert(!deq.empty());\n    int lb\
    \ = -1, ub = deq.size() - 1;\n    while (ub - lb > 1) {\n      const int mid =\
    \ (lb + ub) >> 1;\n      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;\n\
    \    }\n    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);\n  }\n\n  T\
    \ monotonically_increasing_query(const T x) {\n    while (deq.size() >= 2 && f(deq.front(),\
    \ x) >= f(deq[1], x)) {\n      deq.pop_front();\n    }\n    return IS_MINIMIZED\
    \ ? f(deq.front(), x) : -f(deq.front(), x);\n  }\n\n  T monotonically_decreasing_query(const\
    \ T x) {\n    for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {\n\
    \      if (f(deq[i], x) > f(deq[i + 1], x)) break;\n      deq.pop_back();\n  \
    \  }\n    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(), x);\n  }\n\n\
    \ private:\n  using Line = std::pair<T, T>;\n\n  std::deque<Line> deq;\n\n  using\
    \ Real = long double;\n  bool must_pop(const Line& l1, const Line& l2, const Line&\
    \ l3) const {\n    const Real lhs =\n        static_cast<Real>(l3.second - l2.second)\
    \ / (l2.first - l3.first);\n    const Real rhs =\n        static_cast<Real>(l2.second\
    \ - l1.second) / (l1.first - l2.first);\n    return lhs <= rhs;\n    // const\
    \ T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;\n    // const\
    \ T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;\n    // return\
    \ lhs_num * rhs_den <= rhs_num * lhs_den;\n  }\n\n  T f(const Line& l, const T\
    \ x) const { return l.first * x + l.second; }\n};\n"
  code: "#pragma once\n// #include <cassert>\n#include <deque>\n#include <utility>\n\
    \ntemplate <typename T, bool IS_MINIMIZED = true>\nstruct ConvexHullTrick {\n\
    \  ConvexHullTrick() = default;\n\n  void add(T a, T b) {\n    if (!IS_MINIMIZED)\
    \ {\n      a = -a;\n      b = -b;\n    }\n    const Line line(a, b);\n    if (deq.empty())\
    \ {\n      deq.emplace_back(line);\n    } else if (deq.back().first >= a) {\n\
    \      if (deq.back().first == a) {\n        if (b >= deq.back().second) return;\n\
    \        deq.pop_back();\n      }\n      for (int i = static_cast<int>(deq.size())\
    \ - 2; i >= 0; --i) {\n        if (!must_pop(deq[i], deq[i + 1], line)) break;\n\
    \        deq.pop_back();\n      }\n      deq.emplace_back(line);\n    } else {\n\
    \      if (deq.front().first == a) {\n        if (b >= deq.front().second) return;\n\
    \        deq.pop_front();\n      }\n      while (deq.size() >= 2 && must_pop(line,\
    \ deq.front(), deq[1])) {\n        deq.pop_front();\n      }\n      deq.emplace_front(line);\n\
    \    }\n  }\n\n  T query(const T x) const {\n    // assert(!deq.empty());\n  \
    \  int lb = -1, ub = deq.size() - 1;\n    while (ub - lb > 1) {\n      const int\
    \ mid = (lb + ub) >> 1;\n      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb)\
    \ = mid;\n    }\n    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);\n \
    \ }\n\n  T monotonically_increasing_query(const T x) {\n    while (deq.size()\
    \ >= 2 && f(deq.front(), x) >= f(deq[1], x)) {\n      deq.pop_front();\n    }\n\
    \    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);\n  }\n\n  T\
    \ monotonically_decreasing_query(const T x) {\n    for (int i = static_cast<int>(deq.size())\
    \ - 2; i >= 0; --i) {\n      if (f(deq[i], x) > f(deq[i + 1], x)) break;\n   \
    \   deq.pop_back();\n    }\n    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(),\
    \ x);\n  }\n\n private:\n  using Line = std::pair<T, T>;\n\n  std::deque<Line>\
    \ deq;\n\n  using Real = long double;\n  bool must_pop(const Line& l1, const Line&\
    \ l2, const Line& l3) const {\n    const Real lhs =\n        static_cast<Real>(l3.second\
    \ - l2.second) / (l2.first - l3.first);\n    const Real rhs =\n        static_cast<Real>(l2.second\
    \ - l1.second) / (l1.first - l2.first);\n    return lhs <= rhs;\n    // const\
    \ T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;\n    // const\
    \ T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;\n    // return\
    \ lhs_num * rhs_den <= rhs_num * lhs_den;\n  }\n\n  T f(const Line& l, const T\
    \ x) const { return l.first * x + l.second; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/convex_hull_trick.2.test.cpp
  - test/dynamic_programming/convex_hull_trick.3.test.cpp
  - test/dynamic_programming/convex_hull_trick.1.test.cpp
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
  - オフライン版
    - https://mugen1337.github.io/procon/DataStructure/DeletableLiChaoTreeOffline.cpp
    - https://sotanishy.github.io/cp-library-cpp/data-structure/cht/offline_deletable_convex_hull_trick.cpp.html
- 追加する直線の傾きに単調性が必要ない．
  - https://sune2.hatenadiary.org/entry/20140310/1394440369
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/CHT-Ex~~
- $x \in \mathbb{Z}$
  - https://noshi91.hatenablog.com/entry/2021/03/23/200810
  - https://judge.yosupo.jp/submission/35152
- 永続 convex full trick
  - https://codeforces.com/blog/entry/51684
- $\min_i \lbrace A_i x + B_i y \rbrace$
  - https://twitter.com/maspy_stars/status/1502589106039123970
  - 第41回TechFUL Coding Battle「最大値はいくつ？」
  - https://atcoder.jp/contests/abc244/tasks/abc244_h


## Verified

- [`query(x)`](https://atcoder.jp/contests/dp/submissions/26064258)
- [`monotonically_increasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064281)
- [`monotonically_decreasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064320)
