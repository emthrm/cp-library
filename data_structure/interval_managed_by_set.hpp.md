---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/interval_managed_by_set.test.cpp
    title: "\u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\
      \u308B\u3084\u3064"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/interval_managed_by_set.hpp\"\n#include <cassert>\r\
    \n#include <iostream>\r\n#include <iterator>\r\n#include <limits>\r\n#include\
    \ <set>\r\n#include <tuple>\r\n#include <utility>\r\n\r\ntemplate <typename T>\r\
    \nstruct IntervalManagedBySet {\r\n  using IntervalType = std::set<std::pair<T,\
    \ T>>;\r\n  IntervalType intervals{\r\n      {std::numeric_limits<T>::lowest(),\
    \ std::numeric_limits<T>::lowest()},\r\n      {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::max()}};\r\n\r\n  IntervalManagedBySet() = default;\r\
    \n\r\n  bool contains(const T x) const { return contains(x, x); }\r\n\r\n  bool\
    \ contains(const T left, const T right) const {\r\n    typename IntervalType::const_iterator\
    \ it =\r\n        intervals.lower_bound({left, left});\r\n    if (left < it->first)\
    \ it = std::prev(it);\r\n    return it->first <= left && right <= it->second;\r\
    \n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator, bool> erase(const\
    \ T x) {\r\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
    \ x});\r\n    if (it->first == x) {\r\n      const T right = it->second;\r\n \
    \     it = intervals.erase(it);\r\n      if (x + 1 <= right) it = intervals.emplace(x\
    \ + 1, right).first;\r\n    } else {\r\n      it = std::prev(it);\r\n      T left,\
    \ right;\r\n      std::tie(left, right) = *it;\r\n      if (right < x) return\
    \ {std::next(it), false};\r\n      intervals.erase(it);\r\n      it = std::next(intervals.emplace(left,\
    \ x - 1).first);\r\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\r\
    \n    }\r\n    return {it, true};\r\n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator,\
    \ T> erase(\r\n      const T left, const T right) {\r\n    assert(left <= right);\r\
    \n    typename IntervalType::const_iterator it =\r\n        intervals.lower_bound({left,\
    \ left});\r\n    T res = 0;\r\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\r\n      res += it->second - it->first + 1;\r\n    }\r\n    if (it->first\
    \ <= right) {\r\n      res += right - it->first + 1;\r\n      const T r = it->second;\r\
    \n      intervals.erase(it);\r\n      it = intervals.emplace(right + 1, r).first;\r\
    \n    }\r\n    if (left < std::prev(it)->second) {\r\n      it = std::prev(it);\r\
    \n      res += it->second - left + 1;\r\n      const T l = it->first;\r\n    \
    \  intervals.erase(it);\r\n      it = std::next(intervals.emplace(l, left - 1).first);\r\
    \n    }\r\n    return {it, res};\r\n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator,\
    \ bool> insert(const T x) {\r\n    typename IntervalType::const_iterator it =\
    \ intervals.lower_bound({x, x});\r\n    if (it->first == x) return {it, false};\r\
    \n    if (x <= std::prev(it)->second) return {std::prev(it), false};\r\n    T\
    \ left = x, right = x;\r\n    if (x + 1 == it->first) {\r\n      right = it->second;\r\
    \n      it = intervals.erase(it);\r\n    }\r\n    if (std::prev(it)->second ==\
    \ x - 1) {\r\n      it = std::prev(it);\r\n      left = it->first;\r\n      intervals.erase(it);\r\
    \n    }\r\n    return {intervals.emplace(left, right).first, true};\r\n  }\r\n\
    \r\n  std::pair<typename IntervalType::const_iterator, T> insert(T left, T right)\
    \ {\r\n    assert(left <= right);\r\n    typename IntervalType::const_iterator\
    \ it =\r\n        intervals.lower_bound({left, left});\r\n    if (left <= std::prev(it)->second)\
    \ {\r\n      it = std::prev(it);\r\n      left = it->first;\r\n    }\r\n    T\
    \ res = 0;\r\n    if (left == it->first && right <= it->second) return {it, res};\r\
    \n    for (; it->second <= right; it = intervals.erase(it)) {\r\n      res -=\
    \ it->second - it->first + 1;\r\n    }\r\n    if (it->first <= right) {\r\n  \
    \    res -= it->second - it->first + 1;\r\n      right = it->second;\r\n     \
    \ it = intervals.erase(it);\r\n    }\r\n    res += right - left + 1;\r\n    if\
    \ (right + 1 == it->first) {\r\n      right = it->second;\r\n      it = intervals.erase(it);\r\
    \n    }\r\n    if (std::prev(it)->second == left - 1) {\r\n      it = std::prev(it);\r\
    \n      left = it->first;\r\n      intervals.erase(it);\r\n    }\r\n    return\
    \ {intervals.emplace(left, right).first, res};\r\n  }\r\n\r\n  T mex(const T x\
    \ = 0) const {\r\n    auto it = intervals.lower_bound({x, x});\r\n    if (x <=\
    \ std::prev(it)->second) it = std::prev(it);\r\n    return x < it->first ? x :\
    \ it->second + 1;\r\n  }\r\n\r\n  friend std::ostream &operator<<(std::ostream\
    \ &os,\r\n                                  const IntervalManagedBySet& x) {\r\
    \n    if (x.intervals.size() == 2) return os;\r\n    auto it = next(x.intervals.begin());\r\
    \n    while (true) {\r\n      os << '[' << it->first << \", \" << it->second <<\
    \ ']';\r\n      it = next(it);\r\n      if (next(it) == x.intervals.end()) break;\r\
    \n      os << ' ';\r\n    }\r\n    return os;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <iostream>\r\n#include <iterator>\r\
    \n#include <limits>\r\n#include <set>\r\n#include <tuple>\r\n#include <utility>\r\
    \n\r\ntemplate <typename T>\r\nstruct IntervalManagedBySet {\r\n  using IntervalType\
    \ = std::set<std::pair<T, T>>;\r\n  IntervalType intervals{\r\n      {std::numeric_limits<T>::lowest(),\
    \ std::numeric_limits<T>::lowest()},\r\n      {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::max()}};\r\n\r\n  IntervalManagedBySet() = default;\r\
    \n\r\n  bool contains(const T x) const { return contains(x, x); }\r\n\r\n  bool\
    \ contains(const T left, const T right) const {\r\n    typename IntervalType::const_iterator\
    \ it =\r\n        intervals.lower_bound({left, left});\r\n    if (left < it->first)\
    \ it = std::prev(it);\r\n    return it->first <= left && right <= it->second;\r\
    \n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator, bool> erase(const\
    \ T x) {\r\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
    \ x});\r\n    if (it->first == x) {\r\n      const T right = it->second;\r\n \
    \     it = intervals.erase(it);\r\n      if (x + 1 <= right) it = intervals.emplace(x\
    \ + 1, right).first;\r\n    } else {\r\n      it = std::prev(it);\r\n      T left,\
    \ right;\r\n      std::tie(left, right) = *it;\r\n      if (right < x) return\
    \ {std::next(it), false};\r\n      intervals.erase(it);\r\n      it = std::next(intervals.emplace(left,\
    \ x - 1).first);\r\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\r\
    \n    }\r\n    return {it, true};\r\n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator,\
    \ T> erase(\r\n      const T left, const T right) {\r\n    assert(left <= right);\r\
    \n    typename IntervalType::const_iterator it =\r\n        intervals.lower_bound({left,\
    \ left});\r\n    T res = 0;\r\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\r\n      res += it->second - it->first + 1;\r\n    }\r\n    if (it->first\
    \ <= right) {\r\n      res += right - it->first + 1;\r\n      const T r = it->second;\r\
    \n      intervals.erase(it);\r\n      it = intervals.emplace(right + 1, r).first;\r\
    \n    }\r\n    if (left < std::prev(it)->second) {\r\n      it = std::prev(it);\r\
    \n      res += it->second - left + 1;\r\n      const T l = it->first;\r\n    \
    \  intervals.erase(it);\r\n      it = std::next(intervals.emplace(l, left - 1).first);\r\
    \n    }\r\n    return {it, res};\r\n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator,\
    \ bool> insert(const T x) {\r\n    typename IntervalType::const_iterator it =\
    \ intervals.lower_bound({x, x});\r\n    if (it->first == x) return {it, false};\r\
    \n    if (x <= std::prev(it)->second) return {std::prev(it), false};\r\n    T\
    \ left = x, right = x;\r\n    if (x + 1 == it->first) {\r\n      right = it->second;\r\
    \n      it = intervals.erase(it);\r\n    }\r\n    if (std::prev(it)->second ==\
    \ x - 1) {\r\n      it = std::prev(it);\r\n      left = it->first;\r\n      intervals.erase(it);\r\
    \n    }\r\n    return {intervals.emplace(left, right).first, true};\r\n  }\r\n\
    \r\n  std::pair<typename IntervalType::const_iterator, T> insert(T left, T right)\
    \ {\r\n    assert(left <= right);\r\n    typename IntervalType::const_iterator\
    \ it =\r\n        intervals.lower_bound({left, left});\r\n    if (left <= std::prev(it)->second)\
    \ {\r\n      it = std::prev(it);\r\n      left = it->first;\r\n    }\r\n    T\
    \ res = 0;\r\n    if (left == it->first && right <= it->second) return {it, res};\r\
    \n    for (; it->second <= right; it = intervals.erase(it)) {\r\n      res -=\
    \ it->second - it->first + 1;\r\n    }\r\n    if (it->first <= right) {\r\n  \
    \    res -= it->second - it->first + 1;\r\n      right = it->second;\r\n     \
    \ it = intervals.erase(it);\r\n    }\r\n    res += right - left + 1;\r\n    if\
    \ (right + 1 == it->first) {\r\n      right = it->second;\r\n      it = intervals.erase(it);\r\
    \n    }\r\n    if (std::prev(it)->second == left - 1) {\r\n      it = std::prev(it);\r\
    \n      left = it->first;\r\n      intervals.erase(it);\r\n    }\r\n    return\
    \ {intervals.emplace(left, right).first, res};\r\n  }\r\n\r\n  T mex(const T x\
    \ = 0) const {\r\n    auto it = intervals.lower_bound({x, x});\r\n    if (x <=\
    \ std::prev(it)->second) it = std::prev(it);\r\n    return x < it->first ? x :\
    \ it->second + 1;\r\n  }\r\n\r\n  friend std::ostream &operator<<(std::ostream\
    \ &os,\r\n                                  const IntervalManagedBySet& x) {\r\
    \n    if (x.intervals.size() == 2) return os;\r\n    auto it = next(x.intervals.begin());\r\
    \n    while (true) {\r\n      os << '[' << it->first << \", \" << it->second <<\
    \ ']';\r\n      it = next(it);\r\n      if (next(it) == x.intervals.end()) break;\r\
    \n      os << ' ';\r\n    }\r\n    return os;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/interval_managed_by_set.hpp
  requiredBy: []
  timestamp: '2022-02-27 20:23:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/interval_managed_by_set.test.cpp
documentation_of: data_structure/interval_managed_by_set.hpp
layout: document
title: "\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
---

閉区間を `std::set` によって管理するデータ構造である．


## 時間計算量

amortized $O(\log{N})$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`IntervalManagedBySet<T>`|区間を std::set で管理するやつ||
|`intervals`|閉区間の集合||
|`contains(x)`|$x$ は集合に含まれるか．||
|`contains(left, right)`|$\lbrack \mathrm{left}, \mathrm{right} \rbrack$ は集合に含まれるか．||
|`erase(x)`|集合から $x$ を削除する．|返り値は削除された要素の次を指すイテレータと実際に削除したかである．|
|`erase(left, right)`|集合から $x \in \lbrack \mathrm{left}, \mathrm{right} \rbrack$ を削除する．|返り値は削除された要素の次を指すイテレータと削除した要素数である．|
|`insert(x)`|集合に $x$ を挿入する．|返り値は要素へのイテレータと挿入されたかどうかである．|
|`insert(left, right)`|集合に $x \in \lbrack \mathrm{left}, \mathrm{right} \rbrack$ を挿入する．|返り値は要素へのイテレータと挿入した要素数である．|
|`mex(x = 0)`|mex||


## 参考

- https://mugen1337.hatenablog.com/entry/2020/10/14/134022


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2880/review/5242323/emthrm/C++17
