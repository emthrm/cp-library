---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dynamic_programming/convex_hull_trick.1.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
  - icon: ':x:'
    path: test/dynamic_programming/convex_hull_trick.2.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotone_inc_query(x))"
  - icon: ':x:'
    path: test/dynamic_programming/convex_hull_trick.3.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotone_dec_query(x))"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/convex_hull_trick.hpp\"\n#include <deque>\r\
    \n#include <utility>\r\n\r\ntemplate <typename T>\r\nstruct ConvexHullTrick {\r\
    \n  ConvexHullTrick(bool is_minimized = true) : is_minimized(is_minimized) {}\r\
    \n\r\n  void add(T a, T b) {\r\n    Line now(a, b);\r\n    if (deq.empty()) {\r\
    \n      deq.emplace_back(now);\r\n    } else if (deq.back().first <= a) {\r\n\
    \      if (deq.back().first == a) {\r\n        if (is_minimized) {\r\n       \
    \   if (b >= deq.back().second) return;\r\n          deq.pop_back();\r\n     \
    \   } else {\r\n          if (b <= deq.back().second) return;\r\n          deq.pop_back();\r\
    \n        }\r\n      }\r\n      while (deq.size() >= 2 && !is_necessary(deq[deq.size()\
    \ - 2], deq.back(), now)) deq.pop_back();\r\n      deq.emplace_back(now);\r\n\
    \    } else {\r\n      if (deq.front().first == a) {\r\n        if (is_minimized)\
    \ {\r\n          if (b >= deq.front().second) return;\r\n          deq.pop_front();\r\
    \n        } else {\r\n          if (b <= deq.front().second) return;\r\n     \
    \     deq.pop_front();\r\n        }\r\n      }\r\n      while (deq.size() >= 2\
    \ && !is_necessary(now, deq[0], deq[1])) deq.pop_front();\r\n      deq.emplace_front(now);\r\
    \n    }\r\n  }\r\n\r\n  T query(T x) const {\r\n    int lb = -1, ub = deq.size()\
    \ - 1;\r\n    while (ub - lb > 1) {\r\n      int mid = (lb + ub) >> 1;\r\n   \
    \   if (is_minimized) {\r\n        (f(deq[mid], x) < f(deq[mid + 1], x) ? ub :\
    \ lb) = mid;\r\n      } else {\r\n        (f(deq[mid], x) > f(deq[mid + 1], x)\
    \ ? ub : lb) = mid;\r\n      }\r\n    }\r\n    return f(deq[ub], x);\r\n  }\r\n\
    \r\n  T monotone_inc_query(T x) {\r\n    if (is_minimized) {\r\n      while (deq.size()\
    \ >= 2 && f(deq[deq.size() - 2], x) <= f(deq.back(), x)) deq.pop_back();\r\n \
    \     return f(deq.back(), x);\r\n    } else {\r\n      while (deq.size() >= 2\
    \ && f(deq[0], x) <= f(deq[1], x)) deq.pop_front();\r\n      return f(deq.front(),\
    \ x);\r\n    }\r\n  }\r\n\r\n  T monotone_dec_query(T x) {\r\n    if (is_minimized)\
    \ {\r\n      while (deq.size() >= 2 && f(deq[0], x) >= f(deq[1], x)) deq.pop_front();\r\
    \n      return f(deq.front(), x);\r\n    } else {\r\n      while (deq.size() >=\
    \ 2 && f(deq[deq.size() - 2], x) >= f(deq.back(), x)) deq.pop_back();\r\n    \
    \  return f(deq.back(), x);\r\n    }\r\n  }\r\n\r\nprivate:\r\n  using Line =\
    \ std::pair<T, T>;\r\n\r\n  bool is_minimized;\r\n  std::deque<Line> deq;\r\n\r\
    \n  using Real = long double;\r\n  bool is_necessary(const Line &l1, const Line\
    \ &l2, const Line &l3) const {\r\n    Real lhs = static_cast<Real>(l3.second -\
    \ l2.second) / (l2.first - l3.first);\r\n    Real rhs = static_cast<Real>(l2.second\
    \ - l1.second) / (l1.first - l2.first);\r\n    return is_minimized ? lhs < rhs\
    \ : lhs > rhs;\r\n    // T lhs_num = l3.second - l2.second, lhs_den = l2.first\
    \ - l3.first;\r\n    // if (lhs_den < 0) {\r\n    //   lhs_num = -lhs_num;\r\n\
    \    //   lhs_den = -lhs_den;\r\n    // }\r\n    // T rhs_num = l2.second - l1.second,\
    \ rhs_den = l1.first - l2.first;\r\n    // if (rhs_den < 0) {\r\n    //   rhs_num\
    \ = -rhs_num;\r\n    //   rhs_den = -rhs_den;\r\n    // }\r\n    // return is_minimized\
    \ ? lhs_num * rhs_den < rhs_num * lhs_den : lhs_num * rhs_den > rhs_num * lhs_den;\r\
    \n  }\r\n\r\n  T f(const Line &l, T x) const { return l.first * x + l.second;\
    \ }\r\n};\r\n"
  code: "#pragma once\r\n#include <deque>\r\n#include <utility>\r\n\r\ntemplate <typename\
    \ T>\r\nstruct ConvexHullTrick {\r\n  ConvexHullTrick(bool is_minimized = true)\
    \ : is_minimized(is_minimized) {}\r\n\r\n  void add(T a, T b) {\r\n    Line now(a,\
    \ b);\r\n    if (deq.empty()) {\r\n      deq.emplace_back(now);\r\n    } else\
    \ if (deq.back().first <= a) {\r\n      if (deq.back().first == a) {\r\n     \
    \   if (is_minimized) {\r\n          if (b >= deq.back().second) return;\r\n \
    \         deq.pop_back();\r\n        } else {\r\n          if (b <= deq.back().second)\
    \ return;\r\n          deq.pop_back();\r\n        }\r\n      }\r\n      while\
    \ (deq.size() >= 2 && !is_necessary(deq[deq.size() - 2], deq.back(), now)) deq.pop_back();\r\
    \n      deq.emplace_back(now);\r\n    } else {\r\n      if (deq.front().first\
    \ == a) {\r\n        if (is_minimized) {\r\n          if (b >= deq.front().second)\
    \ return;\r\n          deq.pop_front();\r\n        } else {\r\n          if (b\
    \ <= deq.front().second) return;\r\n          deq.pop_front();\r\n        }\r\n\
    \      }\r\n      while (deq.size() >= 2 && !is_necessary(now, deq[0], deq[1]))\
    \ deq.pop_front();\r\n      deq.emplace_front(now);\r\n    }\r\n  }\r\n\r\n  T\
    \ query(T x) const {\r\n    int lb = -1, ub = deq.size() - 1;\r\n    while (ub\
    \ - lb > 1) {\r\n      int mid = (lb + ub) >> 1;\r\n      if (is_minimized) {\r\
    \n        (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;\r\n      } else\
    \ {\r\n        (f(deq[mid], x) > f(deq[mid + 1], x) ? ub : lb) = mid;\r\n    \
    \  }\r\n    }\r\n    return f(deq[ub], x);\r\n  }\r\n\r\n  T monotone_inc_query(T\
    \ x) {\r\n    if (is_minimized) {\r\n      while (deq.size() >= 2 && f(deq[deq.size()\
    \ - 2], x) <= f(deq.back(), x)) deq.pop_back();\r\n      return f(deq.back(),\
    \ x);\r\n    } else {\r\n      while (deq.size() >= 2 && f(deq[0], x) <= f(deq[1],\
    \ x)) deq.pop_front();\r\n      return f(deq.front(), x);\r\n    }\r\n  }\r\n\r\
    \n  T monotone_dec_query(T x) {\r\n    if (is_minimized) {\r\n      while (deq.size()\
    \ >= 2 && f(deq[0], x) >= f(deq[1], x)) deq.pop_front();\r\n      return f(deq.front(),\
    \ x);\r\n    } else {\r\n      while (deq.size() >= 2 && f(deq[deq.size() - 2],\
    \ x) >= f(deq.back(), x)) deq.pop_back();\r\n      return f(deq.back(), x);\r\n\
    \    }\r\n  }\r\n\r\nprivate:\r\n  using Line = std::pair<T, T>;\r\n\r\n  bool\
    \ is_minimized;\r\n  std::deque<Line> deq;\r\n\r\n  using Real = long double;\r\
    \n  bool is_necessary(const Line &l1, const Line &l2, const Line &l3) const {\r\
    \n    Real lhs = static_cast<Real>(l3.second - l2.second) / (l2.first - l3.first);\r\
    \n    Real rhs = static_cast<Real>(l2.second - l1.second) / (l1.first - l2.first);\r\
    \n    return is_minimized ? lhs < rhs : lhs > rhs;\r\n    // T lhs_num = l3.second\
    \ - l2.second, lhs_den = l2.first - l3.first;\r\n    // if (lhs_den < 0) {\r\n\
    \    //   lhs_num = -lhs_num;\r\n    //   lhs_den = -lhs_den;\r\n    // }\r\n\
    \    // T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;\r\n\
    \    // if (rhs_den < 0) {\r\n    //   rhs_num = -rhs_num;\r\n    //   rhs_den\
    \ = -rhs_den;\r\n    // }\r\n    // return is_minimized ? lhs_num * rhs_den <\
    \ rhs_num * lhs_den : lhs_num * rhs_den > rhs_num * lhs_den;\r\n  }\r\n\r\n  T\
    \ f(const Line &l, T x) const { return l.first * x + l.second; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/dynamic_programming/convex_hull_trick.1.test.cpp
  - test/dynamic_programming/convex_hull_trick.2.test.cpp
  - test/dynamic_programming/convex_hull_trick.3.test.cpp
documentation_of: dynamic_programming/convex_hull_trick.hpp
layout: document
title: convex hull trick
---

$xy$ 平面上の直線集合 $L$ を考える．

- $L$ に直線 $f(x) = ax + b$ を追加する．
- ある $x$ について $\min \lbrace f(x) \mid f \in L \rbrace$ を答える．

上記のクエリを高速に処理できるものである．


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|追加クエリ|$O(N)$|
|解答クエリ|$O(Q\log{N})$|
|$x$ に単調性のある解答クエリ|$O(Q + N)$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`ConvexHullTrick<T>(is_minimized = true)`|convex hull trick||
|`add(a, b)`|直線 $f(x) = ax + b$ を追加する．|傾きには単調性が必要である．|
|`query(x)`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$||
|`monotone_inc_query(x)`|$x$ が単調増加している場合の `query(x)`||
|`monotone_dec_query(x)`|$x$ が単調減少している場合の `query(x)`||


## 参考

- http://satanic0258.hatenablog.com/entry/2016/08/16/181331
- https://ei1333.github.io/luzhiled/snippets/structure/convex-hull-trick-add-monotone.html


## ToDo

- 直線の削除可能
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/RemovableCHT
  - https://codeforces.com/blog/entry/60514
- 追加する直線の傾きに単調性が不必要である．
  - https://sune2.hatenadiary.org/entry/20140310/1394440369
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/CHT-Ex
- $x \in \mathbb{Z}$
  - https://noshi91.hatenablog.com/entry/2021/03/23/200810
  - https://judge.yosupo.jp/submission/35152
- 永続 convex full trick
  - https://codeforces.com/blog/entry/51684


## Verified

- [`query(x)`](https://atcoder.jp/contests/colopl2018-final-open/submissions/9239248)
- [`monotone_inc_query(x)`](https://atcoder.jp/contests/colopl2018-final-open/submissions/9239153)
- [`monotone_dec_query(x)`](https://atcoder.jp/contests/colopl2018-final-open/submissions/9239293)
