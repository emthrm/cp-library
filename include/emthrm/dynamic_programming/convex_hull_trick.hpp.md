---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/convex_hull_trick.1.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick"
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/convex_hull_trick.2.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick\uFF08$x$ \u304C\u5358\
      \u8ABF\u5897\u52A0\u3059\u308B\u89E3\u7B54\u30AF\u30A8\u30EA\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/convex_hull_trick.3.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick\uFF08$x$ \u304C\u5358\
      \u8ABF\u6E1B\u5C11\u3059\u308B\u89E3\u7B54\u30AF\u30A8\u30EA\uFF09"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/convex_hull_trick.hpp\"\
    \n\n\n\n#include <cassert>\n#include <deque>\n#include <iterator>\n#include <numeric>\n\
    #include <utility>\n\nnamespace emthrm {\n\ntemplate <typename T, bool IS_MINIMIZED\
    \ = true>\nstruct ConvexHullTrick {\n  ConvexHullTrick() = default;\n\n  void\
    \ add(T a, T b) {\n    if constexpr (!IS_MINIMIZED) {\n      a = -a;\n      b\
    \ = -b;\n    }\n    const Line line(a, b);\n    if (deq.empty()) [[unlikely]]\
    \ {\n      deq.emplace_back(line);\n    } else if (deq.back().first >= a) {\n\
    \      if (deq.back().first == a) {\n        if (b >= deq.back().second) return;\n\
    \        deq.pop_back();\n      }\n      for (int i = std::ssize(deq) - 2; i >=\
    \ 0; --i) {\n        if (!must_pop(deq[i], deq[i + 1], line)) break;\n       \
    \ deq.pop_back();\n      }\n      deq.emplace_back(line);\n    } else {\n    \
    \  if (deq.front().first == a) {\n        if (b >= deq.front().second) return;\n\
    \        deq.pop_front();\n      }\n      while (deq.size() >= 2 && must_pop(line,\
    \ deq.front(), deq[1])) {\n        deq.pop_front();\n      }\n      deq.emplace_front(line);\n\
    \    }\n  }\n\n  T query(const T x) const {\n    assert(!deq.empty());\n    int\
    \ lb = -1, ub = deq.size() - 1;\n    while (ub - lb > 1) {\n      const int mid\
    \ = std::midpoint(lb, ub);\n      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub :\
    \ lb) = mid;\n    }\n    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);\n\
    \  }\n\n  T monotonically_increasing_query(const T x) {\n    while (deq.size()\
    \ >= 2 && f(deq.front(), x) >= f(deq[1], x)) {\n      deq.pop_front();\n    }\n\
    \    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);\n  }\n\n  T\
    \ monotonically_decreasing_query(const T x) {\n    for (int i = std::ssize(deq)\
    \ - 2; i >= 0; --i) {\n      if (f(deq[i], x) > f(deq[i + 1], x)) break;\n   \
    \   deq.pop_back();\n    }\n    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(),\
    \ x);\n  }\n\n private:\n  using Line = std::pair<T, T>;\n\n  std::deque<Line>\
    \ deq;\n\n  bool must_pop(const Line& l1, const Line& l2, const Line& l3) const\
    \ {\n#ifdef __SIZEOF_INT128__\n    const T lhs_num = l3.second - l2.second, lhs_den\
    \ = l2.first - l3.first;\n    const T rhs_num = l2.second - l1.second, rhs_den\
    \ = l1.first - l2.first;\n    return __int128{lhs_num} * rhs_den <= __int128{rhs_num}\
    \ * lhs_den;\n#else\n    const long double lhs =\n        static_cast<long double>(l3.second\
    \ - l2.second) / (l2.first - l3.first);\n    const long double rhs =\n       \
    \ static_cast<long double>(l2.second - l1.second) / (l1.first - l2.first);\n \
    \   return lhs <= rhs;\n#endif  // __SIZEOF_INT128__\n  }\n\n  T f(const Line&\
    \ l, const T x) const { return l.first * x + l.second; }\n};\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_CONVEX_HULL_TRICK_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_CONVEX_HULL_TRICK_HPP_\n\
    \n#include <cassert>\n#include <deque>\n#include <iterator>\n#include <numeric>\n\
    #include <utility>\n\nnamespace emthrm {\n\ntemplate <typename T, bool IS_MINIMIZED\
    \ = true>\nstruct ConvexHullTrick {\n  ConvexHullTrick() = default;\n\n  void\
    \ add(T a, T b) {\n    if constexpr (!IS_MINIMIZED) {\n      a = -a;\n      b\
    \ = -b;\n    }\n    const Line line(a, b);\n    if (deq.empty()) [[unlikely]]\
    \ {\n      deq.emplace_back(line);\n    } else if (deq.back().first >= a) {\n\
    \      if (deq.back().first == a) {\n        if (b >= deq.back().second) return;\n\
    \        deq.pop_back();\n      }\n      for (int i = std::ssize(deq) - 2; i >=\
    \ 0; --i) {\n        if (!must_pop(deq[i], deq[i + 1], line)) break;\n       \
    \ deq.pop_back();\n      }\n      deq.emplace_back(line);\n    } else {\n    \
    \  if (deq.front().first == a) {\n        if (b >= deq.front().second) return;\n\
    \        deq.pop_front();\n      }\n      while (deq.size() >= 2 && must_pop(line,\
    \ deq.front(), deq[1])) {\n        deq.pop_front();\n      }\n      deq.emplace_front(line);\n\
    \    }\n  }\n\n  T query(const T x) const {\n    assert(!deq.empty());\n    int\
    \ lb = -1, ub = deq.size() - 1;\n    while (ub - lb > 1) {\n      const int mid\
    \ = std::midpoint(lb, ub);\n      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub :\
    \ lb) = mid;\n    }\n    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);\n\
    \  }\n\n  T monotonically_increasing_query(const T x) {\n    while (deq.size()\
    \ >= 2 && f(deq.front(), x) >= f(deq[1], x)) {\n      deq.pop_front();\n    }\n\
    \    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);\n  }\n\n  T\
    \ monotonically_decreasing_query(const T x) {\n    for (int i = std::ssize(deq)\
    \ - 2; i >= 0; --i) {\n      if (f(deq[i], x) > f(deq[i + 1], x)) break;\n   \
    \   deq.pop_back();\n    }\n    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(),\
    \ x);\n  }\n\n private:\n  using Line = std::pair<T, T>;\n\n  std::deque<Line>\
    \ deq;\n\n  bool must_pop(const Line& l1, const Line& l2, const Line& l3) const\
    \ {\n#ifdef __SIZEOF_INT128__\n    const T lhs_num = l3.second - l2.second, lhs_den\
    \ = l2.first - l3.first;\n    const T rhs_num = l2.second - l1.second, rhs_den\
    \ = l1.first - l2.first;\n    return __int128{lhs_num} * rhs_den <= __int128{rhs_num}\
    \ * lhs_den;\n#else\n    const long double lhs =\n        static_cast<long double>(l3.second\
    \ - l2.second) / (l2.first - l3.first);\n    const long double rhs =\n       \
    \ static_cast<long double>(l2.second - l1.second) / (l1.first - l2.first);\n \
    \   return lhs <= rhs;\n#endif  // __SIZEOF_INT128__\n  }\n\n  T f(const Line&\
    \ l, const T x) const { return l.first * x + l.second; }\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_CONVEX_HULL_TRICK_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/convex_hull_trick.1.test.cpp
  - test/dynamic_programming/convex_hull_trick.2.test.cpp
  - test/dynamic_programming/convex_hull_trick.3.test.cpp
documentation_of: include/emthrm/dynamic_programming/convex_hull_trick.hpp
layout: document
title: convex hull trick
---

$xy$ 平面上の直線集合 $L$ を考える。

- $L$ に直線 $f(x) = ax + b$ を追加する。
- ある $x$ に対して $\min \lbrace f(x) \mid f \in L \rbrace$ を答える。

上のクエリを高速に処理できるテクニックである。


## 時間計算量

|クエリ|時間計算量|
|:--|:--|
|追加クエリ|amortized $O(1)$|
|解答クエリ|$O(\log{N})$|
|$x$ に単調性のある解答クエリ|amortized $O(1)$|


## 仕様

```cpp
template <typename T, bool IS_MINIMIZED = true>
struct ConvexHullTrick
```

- `T`
- `IS_MINIMIZED`：最小化するかを表す変数

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`ConvexHullTrick();`|デフォルトコンストラクタ||
|`void add(T a, T b);`|直線 $f(x) = ax + b$ を追加する。|傾きには単調性がある。|
|`T query(const T x) const;`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$||
|`T monotonically_increasing_query(const T x);`|`query(x)`|$x$ は単調増加する。|
|`T monotonically_decreasing_query(const T x);`|`query(x)`|$x$ は単調減少する。|


## 参考文献

- http://satanic0258.hatenablog.com/entry/2016/08/16/181331
- https://ei1333.github.io/luzhiled/snippets/structure/convex-hull-trick-add-monotone.html


## TODO

- 直線を削除できる。
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/RemovableCHT~~
  - https://codeforces.com/blog/entry/60514
  - オフライン版
    - https://mugen1337.github.io/procon/DataStructure/DeletableLiChaoTreeOffline.cpp
    - https://sotanishy.github.io/cp-library-cpp/data-structure/cht/offline_deletable_convex_hull_trick.cpp.html
- 追加する直線の傾きに単調性が必要ない。
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


## Submissons

- [`query(x)`](https://atcoder.jp/contests/dp/submissions/26064258)
- [`monotonically_increasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064281)
- [`monotonically_decreasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064320)
