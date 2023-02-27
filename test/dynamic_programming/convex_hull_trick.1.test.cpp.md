---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/convex_hull_trick.hpp
    title: convex hull trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/dp/tasks/dp_z
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_z
  bundledCode: "#line 1 \"test/dynamic_programming/convex_hull_trick.1.test.cpp\"\n\
    /*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))\n *\n\
    \ * verification-helper: PROBLEM https://atcoder.jp/contests/dp/tasks/dp_z\n */\n\
    \n#include <iostream>\n\n#line 1 \"include/emthrm/dynamic_programming/convex_hull_trick.hpp\"\
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
    \ emthrm\n\n\n#line 10 \"test/dynamic_programming/convex_hull_trick.1.test.cpp\"\
    \n\nint main() {\n  int n;\n  long long c;\n  std::cin >> n >> c;\n  emthrm::ConvexHullTrick<long\
    \ long> convex_hull_trick;\n  for (int i = 0; i < n; ++i) {\n    int h;\n    std::cin\
    \ >> h;\n    if (i == 0) [[unlikely]] {\n      convex_hull_trick.add(-2 * h, static_cast<long\
    \ long>(h) * h);\n    } else {\n      const long long dp =\n          convex_hull_trick.query(h)\
    \ + static_cast<long long>(h) * h + c;\n      if (i + 1 == n) [[unlikely]] {\n\
    \        std::cout << dp << '\\n';\n      } else {\n        convex_hull_trick.add(-2\
    \ * h, dp + static_cast<long long>(h) * h);\n      }\n    }\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))\n\
    \ *\n * verification-helper: PROBLEM https://atcoder.jp/contests/dp/tasks/dp_z\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/dynamic_programming/convex_hull_trick.hpp\"\
    \n\nint main() {\n  int n;\n  long long c;\n  std::cin >> n >> c;\n  emthrm::ConvexHullTrick<long\
    \ long> convex_hull_trick;\n  for (int i = 0; i < n; ++i) {\n    int h;\n    std::cin\
    \ >> h;\n    if (i == 0) [[unlikely]] {\n      convex_hull_trick.add(-2 * h, static_cast<long\
    \ long>(h) * h);\n    } else {\n      const long long dp =\n          convex_hull_trick.query(h)\
    \ + static_cast<long long>(h) * h + c;\n      if (i + 1 == n) [[unlikely]] {\n\
    \        std::cout << dp << '\\n';\n      } else {\n        convex_hull_trick.add(-2\
    \ * h, dp + static_cast<long long>(h) * h);\n      }\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/dynamic_programming/convex_hull_trick.hpp
  isVerificationFile: true
  path: test/dynamic_programming/convex_hull_trick.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/convex_hull_trick.1.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/convex_hull_trick.1.test.cpp
- /verify/test/dynamic_programming/convex_hull_trick.1.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
---
