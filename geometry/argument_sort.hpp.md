---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/argument_sort.test.cpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/argument_sort.hpp\"\n#include <algorithm>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\nvoid argument_sort(std::vector<std::pair<int,\
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
    \n  }\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\nvoid argument_sort(std::vector<std::pair<int, int>> &ps) {\r\n  using Point\
    \ = std::pair<int, int>;\r\n  std::vector<Point> orthant[4];\r\n  for (const Point\
    \ &p : ps) {\r\n    if (p.second >= 0) {\r\n      orthant[p.first >= 0 ? 2 : 3].emplace_back(p);\r\
    \n    } else {\r\n      orthant[p.first >= 0].emplace_back(p);\r\n    }\r\n  }\r\
    \n  ps.clear();\r\n  for (int i = 0; i < 4; ++i) {\r\n    if (i == 2) {\r\n  \
    \    std::sort(orthant[i].begin(), orthant[i].end(), [](const Point &a, const\
    \ Point &b) -> bool {\r\n        if (a.first == 0 && a.second == 0) return !(b.first\
    \ == 0 && b.second == 0);\r\n        if (b.first == 0 && b.second == 0) return\
    \ false;\r\n        return static_cast<long long>(a.first) * b.second - static_cast<long\
    \ long>(a.second) * b.first > 0;\r\n      });\r\n    } else {\r\n      std::sort(orthant[i].begin(),\
    \ orthant[i].end(), [](const Point &a, const Point &b) -> bool {\r\n        return\
    \ static_cast<long long>(a.first) * b.second - static_cast<long long>(a.second)\
    \ * b.first > 0;\r\n      });\r\n    }\r\n    for (const Point &p : orthant[i])\
    \ ps.emplace_back(p);\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/argument_sort.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/argument_sort.test.cpp
documentation_of: geometry/argument_sort.hpp
layout: document
title: "\u504F\u89D2\u30BD\u30FC\u30C8"
---


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`argument_sort(ps)`|点集合 $\mathrm{ps}$ に対して偏角ソートを行う．|$\begin{cases} -\pi < arg(x + iy) \leq \pi \\\\ \arg(0) = 0 \\\\ arg(x) = \pi & (x < 0) \end{cases}$|


## 参考

- https://betrue12.hateblo.jp/entry/2020/01/05/151244
- https://github.com/beet-aizu/library/blob/master/geometry/argsort.cpp


## Verified

https://judge.yosupo.jp/submission/6794
