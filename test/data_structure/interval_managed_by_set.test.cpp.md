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
    /*\r\n * @brief \u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\
    \u3059\u308B\u3084\u3064\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <numeric>\r\n\
    #include <vector>\r\n\r\n#line 2 \"data_structure/interval_managed_by_set.hpp\"\
    \n#include <cassert>\r\n#line 4 \"data_structure/interval_managed_by_set.hpp\"\
    \n#include <iterator>\r\n#include <limits>\r\n#include <set>\r\n#include <tuple>\r\
    \n#include <utility>\r\n\r\ntemplate <typename T>\r\nstruct IntervalManagedBySet\
    \ {\r\n  using IntervalType = std::set<std::pair<T, T>>;\r\n  IntervalType intervals{\r\
    \n      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},\r\
    \n      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};\r\n\r\
    \n  IntervalManagedBySet() = default;\r\n\r\n  bool contains(const T x) const\
    \ { return contains(x, x); }\r\n\r\n  bool contains(const T left, const T right)\
    \ const {\r\n    typename IntervalType::const_iterator it =\r\n        intervals.lower_bound({left,\
    \ left});\r\n    if (left < it->first) it = std::prev(it);\r\n    return it->first\
    \ <= left && right <= it->second;\r\n  }\r\n\r\n  std::pair<typename IntervalType::const_iterator,\
    \ bool> erase(const T x) {\r\n    typename IntervalType::const_iterator it = intervals.lower_bound({x,\
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
    \n      os << ' ';\r\n    }\r\n    return os;\r\n  }\r\n};\r\n#line 12 \"test/data_structure/interval_managed_by_set.test.cpp\"\
    \n\r\nint main() {\r\n  int n, m, q;\r\n  std::cin >> n >> m >> q;\r\n  std::vector<int>\
    \ d(m), a(m), b(m), e(q), s(q), t(q);\r\n  for (int i = 0; i < m; ++i) {\r\n \
    \   std::cin >> d[i] >> a[i] >> b[i];\r\n  }\r\n  for (int i = 0; i < q; ++i)\
    \ {\r\n    std::cin >> e[i] >> s[i] >> t[i];\r\n  }\r\n  std::vector<int> order(m\
    \ + q);\r\n  std::iota(order.begin(), order.end(), 0);\r\n  std::sort(order.begin(),\
    \ order.end(), [m, &d, &e](const int a, const int b) {\r\n    const int t_a =\
    \ (a < m ? d[a] : e[a - m]), t_b = (b < m ? d[b] : e[b - m]);\r\n    return t_a\
    \ != t_b ? t_a < t_b : (a < m) < (b < m);\r\n  });\r\n  std::vector<bool> ans(q,\
    \ false);\r\n  IntervalManagedBySet<int> intervals;\r\n  for (int i : order) {\r\
    \n    if (i < m) {\r\n      intervals.insert(a[i], b[i] - 1);\r\n    } else {\r\
    \n      i -= m;\r\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i], t[i]\
    \ - 1);\r\n    }\r\n  }\r\n  for (int i = 0; i < q; ++i) {\r\n    std::cout <<\
    \ (ans[i] ? \"Yes\\n\" : \"No\\n\");\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\
    \u7406\u3059\u308B\u3084\u3064\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <numeric>\r\n\
    #include <vector>\r\n\r\n#include \"../../data_structure/interval_managed_by_set.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m, q;\r\n  std::cin >> n >> m >> q;\r\n  std::vector<int>\
    \ d(m), a(m), b(m), e(q), s(q), t(q);\r\n  for (int i = 0; i < m; ++i) {\r\n \
    \   std::cin >> d[i] >> a[i] >> b[i];\r\n  }\r\n  for (int i = 0; i < q; ++i)\
    \ {\r\n    std::cin >> e[i] >> s[i] >> t[i];\r\n  }\r\n  std::vector<int> order(m\
    \ + q);\r\n  std::iota(order.begin(), order.end(), 0);\r\n  std::sort(order.begin(),\
    \ order.end(), [m, &d, &e](const int a, const int b) {\r\n    const int t_a =\
    \ (a < m ? d[a] : e[a - m]), t_b = (b < m ? d[b] : e[b - m]);\r\n    return t_a\
    \ != t_b ? t_a < t_b : (a < m) < (b < m);\r\n  });\r\n  std::vector<bool> ans(q,\
    \ false);\r\n  IntervalManagedBySet<int> intervals;\r\n  for (int i : order) {\r\
    \n    if (i < m) {\r\n      intervals.insert(a[i], b[i] - 1);\r\n    } else {\r\
    \n      i -= m;\r\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i], t[i]\
    \ - 1);\r\n    }\r\n  }\r\n  for (int i = 0; i < q; ++i) {\r\n    std::cout <<\
    \ (ans[i] ? \"Yes\\n\" : \"No\\n\");\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/interval_managed_by_set.hpp
  isVerificationFile: true
  path: test/data_structure/interval_managed_by_set.test.cpp
  requiredBy: []
  timestamp: '2022-02-28 01:05:32+09:00'
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
