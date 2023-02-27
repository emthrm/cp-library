---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/intervals_managed_by_set.hpp
    title: "\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set \u3067\
      \u7BA1\u7406\u3059\u308B\u3084\u3064"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
  bundledCode: "#line 1 \"test/data_structure/intervals_managed_by_set.test.cpp\"\n\
    /*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set \u3067\
    \u7BA1\u7406\u3059\u308B\u3084\u3064\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/data_structure/intervals_managed_by_set.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"include/emthrm/data_structure/intervals_managed_by_set.hpp\"\
    \n#include <iterator>\n#include <limits>\n#include <set>\n#include <utility>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nstruct IntervalsManagedBySet {\n\
    \  using IntervalsType = std::set<std::pair<T, T>>;\n  IntervalsType intervals{\n\
    \      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},\n\
    \      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};\n\n  IntervalsManagedBySet()\
    \ = default;\n\n  bool contains(const T x) const { return contains(x, x); }\n\n\
    \  bool contains(const T left, const T right) const {\n    return find(left, right)\
    \ != intervals.end();\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ bool> erase(const T x) {\n    typename IntervalsType::const_iterator it = intervals.lower_bound({x,\
    \ x});\n    if (it->first == x) {\n      const T right = it->second;\n      it\
    \ = intervals.erase(it);\n      if (x + 1 <= right) it = intervals.emplace(x +\
    \ 1, right).first;\n    } else {\n      it = std::prev(it);\n      const auto\
    \ [left, right] = *it;\n      if (right < x) return {std::next(it), false};\n\
    \      intervals.erase(it);\n      it = std::next(intervals.emplace(left, x -\
    \ 1).first);\n      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;\n\
    \    }\n    return {it, true};\n  }\n\n  std::pair<typename IntervalsType::const_iterator,\
    \ T> erase(\n      const T left, const T right) {\n    assert(left <= right);\n\
    \    typename IntervalsType::const_iterator it =\n        intervals.lower_bound({left,\
    \ left});\n    T res = 0;\n    for (; it->second <= right; it = intervals.erase(it))\
    \ {\n      res += it->second - it->first + 1;\n    }\n    if (it->first <= right)\
    \ {\n      res += right - it->first + 1;\n      const T r = it->second;\n    \
    \  intervals.erase(it);\n      it = intervals.emplace(right + 1, r).first;\n \
    \   }\n    if (left <= std::prev(it)->second) {\n      it = std::prev(it);\n \
    \     const auto [l, r] = *it;\n      intervals.erase(it);\n      if (right <\
    \ r) {\n        res += right - left + 1;\n        intervals.emplace(right + 1,\
    \ r);\n      } else {\n        res += r - left + 1;\n      }\n      it = std::next(intervals.emplace(l,\
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
    \    }\n    return os;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 13 \"test/data_structure/intervals_managed_by_set.test.cpp\"\
    \n\nint main() {\n  int n, m, q;\n  std::cin >> n >> m >> q;\n  std::vector<int>\
    \ d(m), a(m), b(m), e(q), s(q), t(q);\n  for (int i = 0; i < m; ++i) {\n    std::cin\
    \ >> d[i] >> a[i] >> b[i];\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cin\
    \ >> e[i] >> s[i] >> t[i];\n  }\n  std::vector<int> order(m + q);\n  std::iota(order.begin(),\
    \ order.end(), 0);\n  std::sort(order.begin(), order.end(), [m, &d, &e](const\
    \ int a, const int b) {\n    const int t_a = (a < m ? d[a] : e[a - m]), t_b =\
    \ (b < m ? d[b] : e[b - m]);\n    return t_a != t_b ? t_a < t_b : (a < m) < (b\
    \ < m);\n  });\n  std::vector<bool> ans(q, false);\n  emthrm::IntervalsManagedBySet<int>\
    \ intervals;\n  for (int i : order) {\n    if (i < m) {\n      intervals.insert(a[i],\
    \ b[i] - 1);\n    } else {\n      i -= m;\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i],\
    \ t[i] - 1);\n    }\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cout << (ans[i]\
    \ ? \"Yes\\n\" : \"No\\n\");\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set\
    \ \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\n */\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\n\
    #include \"emthrm/data_structure/intervals_managed_by_set.hpp\"\n\nint main()\
    \ {\n  int n, m, q;\n  std::cin >> n >> m >> q;\n  std::vector<int> d(m), a(m),\
    \ b(m), e(q), s(q), t(q);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> d[i]\
    \ >> a[i] >> b[i];\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cin >> e[i]\
    \ >> s[i] >> t[i];\n  }\n  std::vector<int> order(m + q);\n  std::iota(order.begin(),\
    \ order.end(), 0);\n  std::sort(order.begin(), order.end(), [m, &d, &e](const\
    \ int a, const int b) {\n    const int t_a = (a < m ? d[a] : e[a - m]), t_b =\
    \ (b < m ? d[b] : e[b - m]);\n    return t_a != t_b ? t_a < t_b : (a < m) < (b\
    \ < m);\n  });\n  std::vector<bool> ans(q, false);\n  emthrm::IntervalsManagedBySet<int>\
    \ intervals;\n  for (int i : order) {\n    if (i < m) {\n      intervals.insert(a[i],\
    \ b[i] - 1);\n    } else {\n      i -= m;\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i],\
    \ t[i] - 1);\n    }\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cout << (ans[i]\
    \ ? \"Yes\\n\" : \"No\\n\");\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/intervals_managed_by_set.hpp
  isVerificationFile: true
  path: test/data_structure/intervals_managed_by_set.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/intervals_managed_by_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/intervals_managed_by_set.test.cpp
- /verify/test/data_structure/intervals_managed_by_set.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\
  \u3059\u308B\u3084\u3064"
---
