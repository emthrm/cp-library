---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/intervals_managed_by_set.test.cpp
    title: "\u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\
      \u308B\u3084\u3064"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/data_structure/intervals_managed_by_set.hpp\"\
    \n\n\n\n#include <cassert>\n#include <iostream>\n#include <iterator>\n#include\
    \ <limits>\n#include <set>\n#if __cplusplus < 201703L\n#include <tuple>\n#endif\n\
    #include <utility>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct IntervalsManagedBySet\
    \ {\n  using IntervalsType = std::set<std::pair<T, T>>;\n  IntervalsType intervals{\n\
    \      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},\n\
    \      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};\n\n  IntervalsManagedBySet()\
    \ = default;\n\n  bool contains(const T x) const { return contains(x, x); }\n\n\
    \  bool contains(const T left, const T right) const {\n    return find(left, right)\
    \ != intervals.end();\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ bool> erase(const T x) {\n    typename IntervalsType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) {\n      const T right = it->second;\n      it\
    \ = intervals.erase(it);\n      if (x + 1 <= right) it = intervals.emplace(x +\
    \ 1, right).first;\n    } else {\n      it = std::prev(it);\n#if __cplusplus >=\
    \ 201703L\n      const auto [left, right] = *it;\n#else\n      T left, right;\n\
    \      std::tie(left, right) = *it;\n#endif\n      if (right < x) return {std::next(it),\
    \ false};\n      intervals.erase(it);\n      it = std::next(intervals.emplace(left,\
    \ x - 1).first);\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\n\
    \    }\n    return {it, true};\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ T> erase(\n      const T left, const T right) {\n    assert(left <= right);\n\
    \    typename IntervalsType::const_iterator it =\n        intervals.lower_bound({left,\
    \ left});\n    T res = 0;\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\n      res += it->second - it->first + 1;\n    }\n    if (it->first <= right)\
    \ {\n      res += right - it->first + 1;\n      const T r = it->second;\n    \
    \  intervals.erase(it);\n      it = intervals.emplace(right + 1, r).first;\n \
    \   }\n    if (left <= std::prev(it)->second) {\n      it = std::prev(it);\n#if\
    \ __cplusplus >= 201703L\n      const auto [l, r] = *it;\n#else\n      T l, r;\n\
    \      std::tie(l, r) = *it;\n#endif\n      intervals.erase(it);\n      if (right\
    \ < r) {\n        res += right - left + 1;\n        intervals.emplace(right +\
    \ 1, r);\n      } else {\n        res += r - left + 1;\n      }\n      it = std::next(intervals.emplace(l,\
    \ left - 1).first);\n    }\n    return {it, res};\n  }\n\n  typename IntervalsType::const_iterator\
    \ find(const T x) const {\n    return find(x, x);\n  }\n\n  typename IntervalsType::const_iterator\
    \ find(\n      const T left, const T right) const {\n    typename IntervalsType::const_iterator\
    \ it =\n        intervals.lower_bound({left, left});\n    if (left < it->first)\
    \ it = std::prev(it);\n    return it->first <= left && right <= it->second ? it\
    \ : intervals.end();\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ bool> insert(const T x) {\n    typename IntervalsType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) return {it, false};\n    if (x <= std::prev(it)->second)\
    \ return {std::prev(it), false};\n    T left = x, right = x;\n    if (x + 1 ==\
    \ it->first) {\n      right = it->second;\n      it = intervals.erase(it);\n \
    \   }\n    if (std::prev(it)->second == x - 1) {\n      it = std::prev(it);\n\
    \      left = it->first;\n      intervals.erase(it);\n    }\n    return {intervals.emplace(left,\
    \ right).first, true};\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ T> insert(T left, T right) {\n    assert(left <= right);\n    typename IntervalsType::const_iterator\
    \ it =\n        intervals.lower_bound({left, left});\n    if (left <= std::prev(it)->second)\
    \ {\n      it = std::prev(it);\n      left = it->first;\n    }\n    T res = 0;\n\
    \    if (left == it->first && right <= it->second) return {it, res};\n    for\
    \ (; it->second <= right; it = intervals.erase(it)) {\n      res -= it->second\
    \ - it->first + 1;\n    }\n    if (it->first <= right) {\n      res -= it->second\
    \ - it->first + 1;\n      right = it->second;\n      it = intervals.erase(it);\n\
    \    }\n    res += right - left + 1;\n    if (right + 1 == it->first) {\n    \
    \  right = it->second;\n      it = intervals.erase(it);\n    }\n    if (std::prev(it)->second\
    \ == left - 1) {\n      it = std::prev(it);\n      left = it->first;\n      intervals.erase(it);\n\
    \    }\n    return {intervals.emplace(left, right).first, res};\n  }\n\n  T mex(const\
    \ T x = 0) const {\n    auto it = intervals.lower_bound({x, x});\n    if (x <=\
    \ std::prev(it)->second) it = std::prev(it);\n    return x < it->first ? x : it->second\
    \ + 1;\n  }\n\n  friend std::ostream& operator<<(std::ostream& os,\n         \
    \                         const IntervalsManagedBySet& x) {\n    if (x.intervals.size()\
    \ == 2) return os;\n    auto it = next(x.intervals.begin());\n    while (true)\
    \ {\n      os << '[' << it->first << \", \" << it->second << ']';\n      it =\
    \ next(it);\n      if (next(it) == x.intervals.end()) break;\n      os << ' ';\n\
    \    }\n    return os;\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_INTERVALS_MANAGED_BY_SET_HPP_\n#define EMTHRM_DATA_STRUCTURE_INTERVALS_MANAGED_BY_SET_HPP_\n\
    \n#include <cassert>\n#include <iostream>\n#include <iterator>\n#include <limits>\n\
    #include <set>\n#if __cplusplus < 201703L\n#include <tuple>\n#endif\n#include\
    \ <utility>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct IntervalsManagedBySet\
    \ {\n  using IntervalsType = std::set<std::pair<T, T>>;\n  IntervalsType intervals{\n\
    \      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},\n\
    \      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};\n\n  IntervalsManagedBySet()\
    \ = default;\n\n  bool contains(const T x) const { return contains(x, x); }\n\n\
    \  bool contains(const T left, const T right) const {\n    return find(left, right)\
    \ != intervals.end();\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ bool> erase(const T x) {\n    typename IntervalsType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) {\n      const T right = it->second;\n      it\
    \ = intervals.erase(it);\n      if (x + 1 <= right) it = intervals.emplace(x +\
    \ 1, right).first;\n    } else {\n      it = std::prev(it);\n#if __cplusplus >=\
    \ 201703L\n      const auto [left, right] = *it;\n#else\n      T left, right;\n\
    \      std::tie(left, right) = *it;\n#endif\n      if (right < x) return {std::next(it),\
    \ false};\n      intervals.erase(it);\n      it = std::next(intervals.emplace(left,\
    \ x - 1).first);\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\n\
    \    }\n    return {it, true};\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ T> erase(\n      const T left, const T right) {\n    assert(left <= right);\n\
    \    typename IntervalsType::const_iterator it =\n        intervals.lower_bound({left,\
    \ left});\n    T res = 0;\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\n      res += it->second - it->first + 1;\n    }\n    if (it->first <= right)\
    \ {\n      res += right - it->first + 1;\n      const T r = it->second;\n    \
    \  intervals.erase(it);\n      it = intervals.emplace(right + 1, r).first;\n \
    \   }\n    if (left <= std::prev(it)->second) {\n      it = std::prev(it);\n#if\
    \ __cplusplus >= 201703L\n      const auto [l, r] = *it;\n#else\n      T l, r;\n\
    \      std::tie(l, r) = *it;\n#endif\n      intervals.erase(it);\n      if (right\
    \ < r) {\n        res += right - left + 1;\n        intervals.emplace(right +\
    \ 1, r);\n      } else {\n        res += r - left + 1;\n      }\n      it = std::next(intervals.emplace(l,\
    \ left - 1).first);\n    }\n    return {it, res};\n  }\n\n  typename IntervalsType::const_iterator\
    \ find(const T x) const {\n    return find(x, x);\n  }\n\n  typename IntervalsType::const_iterator\
    \ find(\n      const T left, const T right) const {\n    typename IntervalsType::const_iterator\
    \ it =\n        intervals.lower_bound({left, left});\n    if (left < it->first)\
    \ it = std::prev(it);\n    return it->first <= left && right <= it->second ? it\
    \ : intervals.end();\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ bool> insert(const T x) {\n    typename IntervalsType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) return {it, false};\n    if (x <= std::prev(it)->second)\
    \ return {std::prev(it), false};\n    T left = x, right = x;\n    if (x + 1 ==\
    \ it->first) {\n      right = it->second;\n      it = intervals.erase(it);\n \
    \   }\n    if (std::prev(it)->second == x - 1) {\n      it = std::prev(it);\n\
    \      left = it->first;\n      intervals.erase(it);\n    }\n    return {intervals.emplace(left,\
    \ right).first, true};\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ T> insert(T left, T right) {\n    assert(left <= right);\n    typename IntervalsType::const_iterator\
    \ it =\n        intervals.lower_bound({left, left});\n    if (left <= std::prev(it)->second)\
    \ {\n      it = std::prev(it);\n      left = it->first;\n    }\n    T res = 0;\n\
    \    if (left == it->first && right <= it->second) return {it, res};\n    for\
    \ (; it->second <= right; it = intervals.erase(it)) {\n      res -= it->second\
    \ - it->first + 1;\n    }\n    if (it->first <= right) {\n      res -= it->second\
    \ - it->first + 1;\n      right = it->second;\n      it = intervals.erase(it);\n\
    \    }\n    res += right - left + 1;\n    if (right + 1 == it->first) {\n    \
    \  right = it->second;\n      it = intervals.erase(it);\n    }\n    if (std::prev(it)->second\
    \ == left - 1) {\n      it = std::prev(it);\n      left = it->first;\n      intervals.erase(it);\n\
    \    }\n    return {intervals.emplace(left, right).first, res};\n  }\n\n  T mex(const\
    \ T x = 0) const {\n    auto it = intervals.lower_bound({x, x});\n    if (x <=\
    \ std::prev(it)->second) it = std::prev(it);\n    return x < it->first ? x : it->second\
    \ + 1;\n  }\n\n  friend std::ostream& operator<<(std::ostream& os,\n         \
    \                         const IntervalsManagedBySet& x) {\n    if (x.intervals.size()\
    \ == 2) return os;\n    auto it = next(x.intervals.begin());\n    while (true)\
    \ {\n      os << '[' << it->first << \", \" << it->second << ']';\n      it =\
    \ next(it);\n      if (next(it) == x.intervals.end()) break;\n      os << ' ';\n\
    \    }\n    return os;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DATA_STRUCTURE_INTERVALS_MANAGED_BY_SET_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/intervals_managed_by_set.hpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/intervals_managed_by_set.test.cpp
documentation_of: include/emthrm/data_structure/intervals_managed_by_set.hpp
layout: document
title: "\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
---

閉区間を `std::set` によって管理するデータ構造である。


## 時間計算量

amortized $O(\log{N})$ ?


## 仕様

```cpp
template <typename T>
struct IntervalsManagedBySet;
```

- `T`：要素型

#### メンバ変数

|名前|説明|備考|
|:--|:--|:--|
|`IntervalsType intervals`|区間の集合|番兵 $\lbrack -\infty, -\infty \rbrack, \lbrack \infty, \infty \rbrack$ を含む。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`IntervalsManagedBySet();`|デフォルトコンストラクタ。集合 $S \mathrel{:=} \emptyset$ を表すオブジェクトを構築する。|
|`bool contains(const T x) const;`|$x \in S$ を満たすか。|
|`bool contains(const T left, const T right) const;`|任意の $x \in \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ に対して $x \in S$ を満たすか。|
|`std::pair<IntervalsType::const_iterator, bool> erase(const T x);`|$S \gets S \setminus \lbrace x \rbrace$ の操作後、削除された要素の次を指すイテレータと実際に削除したかを返す。|
|`std::pair<IntervalsType::const_iterator, T> erase(const T left, const T right);`|$S \gets S \setminus \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ の操作後、削除された要素の次を指すイテレータと削除した要素数を返す。|
|`IntervalsType::const_iterator find(const T x) const;`|$x$ を含む区間へのイテレータ。ただし $x \notin S$ を満たすときは `intervals.end()` を返す。|
|`IntervalsType::const_iterator find(const T left, const T right) const;`|$\lbrack \mathrm{left}, \mathrm{right} \rbrack$ を含む区間へのイテレータ。ただし $x \notin S$ を満たす $x \in \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ が存在するときは `intervals.end()` を返す。|
|`std::pair<IntervalsType::const_iterator, bool> insert(const T x);`|$S \gets S \cup \lbrace x \rbrace$ の操作後、要素へのイテレータと実際に挿入されたかどうかを返す。|
|`std::pair<IntervalsType::const_iterator, T> insert(T left, T right);`|$S \gets S \cup \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ の操作後、要素へのイテレータと実際に挿入した要素数を返す。|
|`T mex(const T x = 0) const;`|$\mathrm{mex}(S)$|
|`friend std::ostream& operator<<(std::ostream& os, const IntervalsManagedBySet& x)`||

#### メンバ型

|名前|説明|
|:--|:--|
|`IntervalsType`|`std::set<std::pair<T, T>>`|


## 参考文献

- https://mugen1337.hatenablog.com/entry/2020/10/14/134022


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2880/review/5242323/emthrm/C++17
