---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/interval_managed_by_set.hpp
    title: "\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
    document_title: "\u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\
      \u3059\u308B\u3084\u3064"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
  bundledCode: "#line 1 \"test/data_structure/interval_managed_by_set.test.cpp\"\n\
    /*\n * @brief \u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\
    \u3059\u308B\u3084\u3064\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    \n#line 2 \"data_structure/interval_managed_by_set.hpp\"\n#include <cassert>\n\
    #line 4 \"data_structure/interval_managed_by_set.hpp\"\n#include <iterator>\n\
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
    \    }\n    return os;\n  }\n};\n#line 12 \"test/data_structure/interval_managed_by_set.test.cpp\"\
    \n\nint main() {\n  int n, m, q;\n  std::cin >> n >> m >> q;\n  std::vector<int>\
    \ d(m), a(m), b(m), e(q), s(q), t(q);\n  for (int i = 0; i < m; ++i) {\n    std::cin\
    \ >> d[i] >> a[i] >> b[i];\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cin\
    \ >> e[i] >> s[i] >> t[i];\n  }\n  std::vector<int> order(m + q);\n  std::iota(order.begin(),\
    \ order.end(), 0);\n  std::sort(order.begin(), order.end(), [m, &d, &e](const\
    \ int a, const int b) {\n    const int t_a = (a < m ? d[a] : e[a - m]), t_b =\
    \ (b < m ? d[b] : e[b - m]);\n    return t_a != t_b ? t_a < t_b : (a < m) < (b\
    \ < m);\n  });\n  std::vector<bool> ans(q, false);\n  IntervalManagedBySet<int>\
    \ intervals;\n  for (int i : order) {\n    if (i < m) {\n      intervals.insert(a[i],\
    \ b[i] - 1);\n    } else {\n      i -= m;\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i],\
    \ t[i] - 1);\n    }\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cout << (ans[i]\
    \ ? \"Yes\\n\" : \"No\\n\");\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\
    \u7406\u3059\u308B\u3084\u3064\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    \n#include \"../../data_structure/interval_managed_by_set.hpp\"\n\nint main()\
    \ {\n  int n, m, q;\n  std::cin >> n >> m >> q;\n  std::vector<int> d(m), a(m),\
    \ b(m), e(q), s(q), t(q);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> d[i]\
    \ >> a[i] >> b[i];\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cin >> e[i]\
    \ >> s[i] >> t[i];\n  }\n  std::vector<int> order(m + q);\n  std::iota(order.begin(),\
    \ order.end(), 0);\n  std::sort(order.begin(), order.end(), [m, &d, &e](const\
    \ int a, const int b) {\n    const int t_a = (a < m ? d[a] : e[a - m]), t_b =\
    \ (b < m ? d[b] : e[b - m]);\n    return t_a != t_b ? t_a < t_b : (a < m) < (b\
    \ < m);\n  });\n  std::vector<bool> ans(q, false);\n  IntervalManagedBySet<int>\
    \ intervals;\n  for (int i : order) {\n    if (i < m) {\n      intervals.insert(a[i],\
    \ b[i] - 1);\n    } else {\n      i -= m;\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i],\
    \ t[i] - 1);\n    }\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cout << (ans[i]\
    \ ? \"Yes\\n\" : \"No\\n\");\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/interval_managed_by_set.hpp
  isVerificationFile: true
  path: test/data_structure/interval_managed_by_set.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/interval_managed_by_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/interval_managed_by_set.test.cpp
- /verify/test/data_structure/interval_managed_by_set.test.cpp.html
title: "\u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\u308B\
  \u3084\u3064"
---
