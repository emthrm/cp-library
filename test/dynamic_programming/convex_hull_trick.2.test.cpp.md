---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dynamic_programming/convex_hull_trick.hpp
    title: convex hull trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotone_inc_query(x))"
    links:
    - https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
  bundledCode: "#line 1 \"test/dynamic_programming/convex_hull_trick.2.test.cpp\"\n\
    /*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotone_inc_query(x))\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"dynamic_programming/convex_hull_trick.hpp\"\
    \n#include <deque>\r\n#include <utility>\r\n\r\ntemplate <typename T>\r\nstruct\
    \ ConvexHullTrick {\r\n  ConvexHullTrick(bool is_minimized = true) : is_minimized(is_minimized)\
    \ {}\r\n\r\n  void add(T a, T b) {\r\n    Line now(a, b);\r\n    if (deq.empty())\
    \ {\r\n      deq.emplace_back(now);\r\n    } else if (deq.back().first <= a) {\r\
    \n      if (deq.back().first == a) {\r\n        if (is_minimized) {\r\n      \
    \    if (b >= deq.back().second) return;\r\n          deq.pop_back();\r\n    \
    \    } else {\r\n          if (b <= deq.back().second) return;\r\n          deq.pop_back();\r\
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
    \ }\r\n};\r\n#line 9 \"test/dynamic_programming/convex_hull_trick.2.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  ConvexHullTrick<long long>\
    \ cht;\r\n  for (int j = 1; j <= n; ++j) {\r\n    long long a;\r\n    std::cin\
    \ >> a;\r\n    cht.add(-2 * j, a + static_cast<long long>(j) * j);\r\n  }\r\n\
    \  for (int i = 1; i <= n; ++i) std::cout << cht.monotone_inc_query(i) + static_cast<long\
    \ long>(i) * i << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotone_inc_query(x))\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../dynamic_programming/convex_hull_trick.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  ConvexHullTrick<long\
    \ long> cht;\r\n  for (int j = 1; j <= n; ++j) {\r\n    long long a;\r\n    std::cin\
    \ >> a;\r\n    cht.add(-2 * j, a + static_cast<long long>(j) * j);\r\n  }\r\n\
    \  for (int i = 1; i <= n; ++i) std::cout << cht.monotone_inc_query(i) + static_cast<long\
    \ long>(i) * i << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/convex_hull_trick.hpp
  isVerificationFile: true
  path: test/dynamic_programming/convex_hull_trick.2.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dynamic_programming/convex_hull_trick.2.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/convex_hull_trick.2.test.cpp
- /verify/test/dynamic_programming/convex_hull_trick.2.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotone_inc_query(x))"
---
