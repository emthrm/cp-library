---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/convex_hull_trick.hpp
    title: convex hull trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/dp/tasks/dp_z
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_z
  bundledCode: "#line 1 \"test/dynamic_programming/convex_hull_trick.1.test.cpp\"\n\
    /*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))\r\n\
    \ */\r\n#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_z\"\r\n\r\n\
    #include <iostream>\r\n\r\n#line 2 \"dynamic_programming/convex_hull_trick.hpp\"\
    \n// #include <cassert>\r\n#include <deque>\r\n#include <utility>\r\n\r\ntemplate\
    \ <typename T, bool IS_MINIMIZED = true>\r\nstruct ConvexHullTrick {\r\n  ConvexHullTrick()\
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
    \ Line& l, const T x) const { return l.first * x + l.second; }\r\n};\r\n#line\
    \ 9 \"test/dynamic_programming/convex_hull_trick.1.test.cpp\"\n\r\nint main()\
    \ {\r\n  int n;\r\n  long long c;\r\n  std::cin >> n >> c;\r\n  ConvexHullTrick<long\
    \ long> convex_hull_trick;\r\n  for (int i = 0; i < n; ++i) {\r\n    int h;\r\n\
    \    std::cin >> h;\r\n    if (i == 0) {\r\n      convex_hull_trick.add(-2 * h,\
    \ static_cast<long long>(h) * h);\r\n    } else {\r\n      const long long dp\
    \ =\r\n          convex_hull_trick.query(h) + static_cast<long long>(h) * h +\
    \ c;\r\n      if (i + 1 == n) {\r\n        std::cout << dp << '\\n';\r\n     \
    \ } else {\r\n        convex_hull_trick.add(-2 * h, dp + static_cast<long long>(h)\
    \ * h);\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))\r\
    \n */\r\n#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_z\"\r\n\r\n\
    #include <iostream>\r\n\r\n#include \"../../dynamic_programming/convex_hull_trick.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  long long c;\r\n  std::cin >> n >> c;\r\n\
    \  ConvexHullTrick<long long> convex_hull_trick;\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    int h;\r\n    std::cin >> h;\r\n    if (i == 0) {\r\n      convex_hull_trick.add(-2\
    \ * h, static_cast<long long>(h) * h);\r\n    } else {\r\n      const long long\
    \ dp =\r\n          convex_hull_trick.query(h) + static_cast<long long>(h) * h\
    \ + c;\r\n      if (i + 1 == n) {\r\n        std::cout << dp << '\\n';\r\n   \
    \   } else {\r\n        convex_hull_trick.add(-2 * h, dp + static_cast<long long>(h)\
    \ * h);\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/convex_hull_trick.hpp
  isVerificationFile: true
  path: test/dynamic_programming/convex_hull_trick.1.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/convex_hull_trick.1.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/convex_hull_trick.1.test.cpp
- /verify/test/dynamic_programming/convex_hull_trick.1.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
---
