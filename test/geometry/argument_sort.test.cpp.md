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
  bundledCode: "#line 1 \"test/geometry/argument_sort.test.cpp\"\n/*\n * @brief \u8A08\
    \u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"geometry/argument_sort.hpp\"\
    \n#include <algorithm>\n#include <iterator>\n#line 6 \"geometry/argument_sort.hpp\"\
    \n\nvoid argument_sort(std::vector<std::pair<int, int>>* ps) {\n  using Point\
    \ = std::pair<int, int>;\n  std::vector<Point> orthant[4]{};\n  for (const Point&\
    \ p : *ps) {\n    if (p.second >= 0) {\n      orthant[p.first >= 0 ? 2 : 3].emplace_back(p);\n\
    \    } else {\n      orthant[p.first >= 0].emplace_back(p);\n    }\n  }\n  ps->clear();\n\
    \  for (int i = 0; i < 4; ++i) {\n    if (i == 2) {\n      std::sort(orthant[i].begin(),\
    \ orthant[i].end(),\n                [](const Point& a, const Point& b) -> bool\
    \ {\n                  if (a.first == 0 && a.second == 0) {\n                \
    \    return !(b.first == 0 && b.second == 0);\n                  }\n         \
    \         if (b.first == 0 && b.second == 0) return false;\n                 \
    \ return static_cast<long long>(a.first) * b.second -\n                      \
    \   static_cast<long long>(a.second) * b.first > 0;\n                });\n   \
    \ } else {\n      std::sort(orthant[i].begin(), orthant[i].end(),\n          \
    \      [](const Point& a, const Point& b) -> bool {\n                  return\
    \ static_cast<long long>(a.first) * b.second -\n                         static_cast<long\
    \ long>(a.second) * b.first > 0;\n                });\n    }\n    std::copy(orthant[i].begin(),\
    \ orthant[i].end(), std::back_inserter(*ps));\n  }\n}\n#line 11 \"test/geometry/argument_sort.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::pair<int, int>>\
    \ ps(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> ps[i].first >> ps[i].second;\n\
    \  }\n  argument_sort(&ps);\n  for (int i = 0; i < n; ++i) {\n    std::cout <<\
    \ ps[i].first << ' ' << ps[i].second << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8\
    \n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../../geometry/argument_sort.hpp\"\n\nint main() {\n  int n;\n  std::cin >> n;\n\
    \  std::vector<std::pair<int, int>> ps(n);\n  for (int i = 0; i < n; ++i) {\n\
    \    std::cin >> ps[i].first >> ps[i].second;\n  }\n  argument_sort(&ps);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cout << ps[i].first << ' ' << ps[i].second\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - geometry/argument_sort.hpp
  isVerificationFile: true
  path: test/geometry/argument_sort.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/argument_sort.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/argument_sort.test.cpp
- /verify/test/geometry/argument_sort.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8"
---
