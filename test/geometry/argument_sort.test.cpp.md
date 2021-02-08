---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/argument_sort.hpp
    title: "\u504F\u89D2\u30BD\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8"
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/geometry/argument_sort.test.cpp\"\n/*\r\n * @brief\
    \ \u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\r\n\r\n\
    #include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n#line 2 \"geometry/argument_sort.hpp\"\
    \n#include <algorithm>\r\n#line 5 \"geometry/argument_sort.hpp\"\n\r\nvoid argument_sort(std::vector<std::pair<int,\
    \ int>> &ps) {\r\n  using Point = std::pair<int, int>;\r\n  std::vector<Point>\
    \ orthant[4];\r\n  for (const Point &p : ps) {\r\n    if (p.second >= 0) {\r\n\
    \      orthant[p.first >= 0 ? 2 : 3].emplace_back(p);\r\n    } else {\r\n    \
    \  orthant[p.first >= 0].emplace_back(p);\r\n    }\r\n  }\r\n  ps.clear();\r\n\
    \  for (int i = 0; i < 4; ++i) {\r\n    if (i == 2) {\r\n      std::sort(orthant[i].begin(),\
    \ orthant[i].end(), [](const Point &a, const Point &b) -> bool {\r\n        if\
    \ (a.first == 0 && a.second == 0) return !(b.first == 0 && b.second == 0);\r\n\
    \        if (b.first == 0 && b.second == 0) return false;\r\n        return static_cast<long\
    \ long>(a.first) * b.second - static_cast<long long>(a.second) * b.first > 0;\r\
    \n      });\r\n    } else {\r\n      std::sort(orthant[i].begin(), orthant[i].end(),\
    \ [](const Point &a, const Point &b) -> bool {\r\n        return static_cast<long\
    \ long>(a.first) * b.second - static_cast<long long>(a.second) * b.first > 0;\r\
    \n      });\r\n    }\r\n    for (const Point &p : orthant[i]) ps.emplace_back(p);\r\
    \n  }\r\n}\r\n#line 10 \"test/geometry/argument_sort.test.cpp\"\n\r\nint main()\
    \ {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::pair<int, int>> ps(n);\r\
    \n  for (int i = 0; i < n; ++i) std::cin >> ps[i].first >> ps[i].second;\r\n \
    \ argument_sort(ps);\r\n  for (int i = 0; i < n; ++i) std::cout << ps[i].first\
    \ << ' ' << ps[i].second << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8\
    \r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n#include\
    \ \"../../geometry/argument_sort.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::vector<std::pair<int, int>> ps(n);\r\n  for (int i = 0; i <\
    \ n; ++i) std::cin >> ps[i].first >> ps[i].second;\r\n  argument_sort(ps);\r\n\
    \  for (int i = 0; i < n; ++i) std::cout << ps[i].first << ' ' << ps[i].second\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - geometry/argument_sort.hpp
  isVerificationFile: true
  path: test/geometry/argument_sort.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/argument_sort.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/argument_sort.test.cpp
- /verify/test/geometry/argument_sort.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8"
---
