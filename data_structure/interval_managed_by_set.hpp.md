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
  bundledCode: "#line 2 \"data_structure/interval_managed_by_set.hpp\"\n#include <cassert>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <set>\n\
    #include <tuple>\n#include <utility>\n\ntemplate <typename T>\nstruct IntervalManagedBySet\
    \ {\n  using IntervalType = std::set<std::pair<T, T>>;\n  IntervalType intervals{\n\
    \      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},\n\
    \      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};\n\n  IntervalManagedBySet()\
    \ = default;\n\n  bool contains(const T x) const { return contains(x, x); }\n\n\
    \  bool contains(const T left, const T right) const {\n    typename IntervalType::const_iterator\
    \ it =\n        intervals.lower_bound({left, left});\n    if (left < it->first)\
    \ it = std::prev(it);\n    return it->first <= left && right <= it->second;\n\
    \  }\n\n  std::pair<typename IntervalType::const_iterator, bool> erase(const T\
    \ x) {\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) {\n      const T right = it->second;\n      it\
    \ = intervals.erase(it);\n      if (x + 1 <= right) it = intervals.emplace(x +\
    \ 1, right).first;\n    } else {\n      it = std::prev(it);\n      T left, right;\n\
    \      std::tie(left, right) = *it;\n      if (right < x) return {std::next(it),\
    \ false};\n      intervals.erase(it);\n      it = std::next(intervals.emplace(left,\
    \ x - 1).first);\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\n\
    \    }\n    return {it, true};\n  }\n\n  std::pair<typename IntervalType::const_iterator,\
    \ T> erase(\n      const T left, const T right) {\n    assert(left <= right);\n\
    \    typename IntervalType::const_iterator it =\n        intervals.lower_bound({left,\
    \ left});\n    T res = 0;\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\n      res += it->second - it->first + 1;\n    }\n    if (it->first <= right)\
    \ {\n      res += right - it->first + 1;\n      const T r = it->second;\n    \
    \  intervals.erase(it);\n      it = intervals.emplace(right + 1, r).first;\n \
    \   }\n    if (left < std::prev(it)->second) {\n      it = std::prev(it);\n  \
    \    res += it->second - left + 1;\n      const T l = it->first;\n      intervals.erase(it);\n\
    \      it = std::next(intervals.emplace(l, left - 1).first);\n    }\n    return\
    \ {it, res};\n  }\n\n  std::pair<typename IntervalType::const_iterator, bool>\
    \ insert(const T x) {\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) return {it, false};\n    if (x <= std::prev(it)->second)\
    \ return {std::prev(it), false};\n    T left = x, right = x;\n    if (x + 1 ==\
    \ it->first) {\n      right = it->second;\n      it = intervals.erase(it);\n \
    \   }\n    if (std::prev(it)->second == x - 1) {\n      it = std::prev(it);\n\
    \      left = it->first;\n      intervals.erase(it);\n    }\n    return {intervals.emplace(left,\
    \ right).first, true};\n  }\n\n  std::pair<typename IntervalType::const_iterator,\
    \ T> insert(T left, T right) {\n    assert(left <= right);\n    typename IntervalType::const_iterator\
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
    \ + 1;\n  }\n\n  friend std::ostream &operator<<(std::ostream &os,\n         \
    \                         const IntervalManagedBySet& x) {\n    if (x.intervals.size()\
    \ == 2) return os;\n    auto it = next(x.intervals.begin());\n    while (true)\
    \ {\n      os << '[' << it->first << \", \" << it->second << ']';\n      it =\
    \ next(it);\n      if (next(it) == x.intervals.end()) break;\n      os << ' ';\n\
    \    }\n    return os;\n  }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <set>\n#include <tuple>\n#include <utility>\n\ntemplate\
    \ <typename T>\nstruct IntervalManagedBySet {\n  using IntervalType = std::set<std::pair<T,\
    \ T>>;\n  IntervalType intervals{\n      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},\n\
    \      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};\n\n  IntervalManagedBySet()\
    \ = default;\n\n  bool contains(const T x) const { return contains(x, x); }\n\n\
    \  bool contains(const T left, const T right) const {\n    typename IntervalType::const_iterator\
    \ it =\n        intervals.lower_bound({left, left});\n    if (left < it->first)\
    \ it = std::prev(it);\n    return it->first <= left && right <= it->second;\n\
    \  }\n\n  std::pair<typename IntervalType::const_iterator, bool> erase(const T\
    \ x) {\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) {\n      const T right = it->second;\n      it\
    \ = intervals.erase(it);\n      if (x + 1 <= right) it = intervals.emplace(x +\
    \ 1, right).first;\n    } else {\n      it = std::prev(it);\n      T left, right;\n\
    \      std::tie(left, right) = *it;\n      if (right < x) return {std::next(it),\
    \ false};\n      intervals.erase(it);\n      it = std::next(intervals.emplace(left,\
    \ x - 1).first);\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\n\
    \    }\n    return {it, true};\n  }\n\n  std::pair<typename IntervalType::const_iterator,\
    \ T> erase(\n      const T left, const T right) {\n    assert(left <= right);\n\
    \    typename IntervalType::const_iterator it =\n        intervals.lower_bound({left,\
    \ left});\n    T res = 0;\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\n      res += it->second - it->first + 1;\n    }\n    if (it->first <= right)\
    \ {\n      res += right - it->first + 1;\n      const T r = it->second;\n    \
    \  intervals.erase(it);\n      it = intervals.emplace(right + 1, r).first;\n \
    \   }\n    if (left < std::prev(it)->second) {\n      it = std::prev(it);\n  \
    \    res += it->second - left + 1;\n      const T l = it->first;\n      intervals.erase(it);\n\
    \      it = std::next(intervals.emplace(l, left - 1).first);\n    }\n    return\
    \ {it, res};\n  }\n\n  std::pair<typename IntervalType::const_iterator, bool>\
    \ insert(const T x) {\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) return {it, false};\n    if (x <= std::prev(it)->second)\
    \ return {std::prev(it), false};\n    T left = x, right = x;\n    if (x + 1 ==\
    \ it->first) {\n      right = it->second;\n      it = intervals.erase(it);\n \
    \   }\n    if (std::prev(it)->second == x - 1) {\n      it = std::prev(it);\n\
    \      left = it->first;\n      intervals.erase(it);\n    }\n    return {intervals.emplace(left,\
    \ right).first, true};\n  }\n\n  std::pair<typename IntervalType::const_iterator,\
    \ T> insert(T left, T right) {\n    assert(left <= right);\n    typename IntervalType::const_iterator\
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
    \ + 1;\n  }\n\n  friend std::ostream &operator<<(std::ostream &os,\n         \
    \                         const IntervalManagedBySet& x) {\n    if (x.intervals.size()\
    \ == 2) return os;\n    auto it = next(x.intervals.begin());\n    while (true)\
    \ {\n      os << '[' << it->first << \", \" << it->second << ']';\n      it =\
    \ next(it);\n      if (next(it) == x.intervals.end()) break;\n      os << ' ';\n\
    \    }\n    return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/interval_managed_by_set.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
