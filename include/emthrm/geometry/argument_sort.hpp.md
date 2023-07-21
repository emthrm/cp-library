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
  bundledCode: "#line 1 \"include/emthrm/geometry/argument_sort.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <iterator>\n#include <utility>\n#include <vector>\n\n\
    namespace emthrm {\n\nvoid argument_sort(std::vector<std::pair<int, int>>* ps)\
    \ {\n  using Point = std::pair<int, int>;\n  std::vector<Point> orthant[4]{};\n\
    \  for (const Point& p : *ps) {\n    if (p.second >= 0) {\n      orthant[p.first\
    \ >= 0 ? 2 : 3].emplace_back(p);\n    } else {\n      orthant[p.first >= 0].emplace_back(p);\n\
    \    }\n  }\n  ps->clear();\n  for (int i = 0; i < 4; ++i) {\n    if (i == 2)\
    \ {\n      std::sort(orthant[i].begin(), orthant[i].end(),\n                [](const\
    \ Point& a, const Point& b) -> bool {\n                  if (a.first == 0 && a.second\
    \ == 0) {\n                    return !(b.first == 0 && b.second == 0);\n    \
    \              }\n                  if (b.first == 0 && b.second == 0) return\
    \ false;\n                  return static_cast<long long>(a.first) * b.second\
    \ -\n                         static_cast<long long>(a.second) * b.first > 0;\n\
    \                });\n    } else {\n      std::sort(orthant[i].begin(), orthant[i].end(),\n\
    \                [](const Point& a, const Point& b) -> bool {\n              \
    \    return static_cast<long long>(a.first) * b.second -\n                   \
    \      static_cast<long long>(a.second) * b.first > 0;\n                });\n\
    \    }\n    std::copy(orthant[i].begin(), orthant[i].end(), std::back_inserter(*ps));\n\
    \  }\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GEOMETRY_ARGUMENT_SORT_HPP_\n#define EMTHRM_GEOMETRY_ARGUMENT_SORT_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \nnamespace emthrm {\n\nvoid argument_sort(std::vector<std::pair<int, int>>* ps)\
    \ {\n  using Point = std::pair<int, int>;\n  std::vector<Point> orthant[4]{};\n\
    \  for (const Point& p : *ps) {\n    if (p.second >= 0) {\n      orthant[p.first\
    \ >= 0 ? 2 : 3].emplace_back(p);\n    } else {\n      orthant[p.first >= 0].emplace_back(p);\n\
    \    }\n  }\n  ps->clear();\n  for (int i = 0; i < 4; ++i) {\n    if (i == 2)\
    \ {\n      std::sort(orthant[i].begin(), orthant[i].end(),\n                [](const\
    \ Point& a, const Point& b) -> bool {\n                  if (a.first == 0 && a.second\
    \ == 0) {\n                    return !(b.first == 0 && b.second == 0);\n    \
    \              }\n                  if (b.first == 0 && b.second == 0) return\
    \ false;\n                  return static_cast<long long>(a.first) * b.second\
    \ -\n                         static_cast<long long>(a.second) * b.first > 0;\n\
    \                });\n    } else {\n      std::sort(orthant[i].begin(), orthant[i].end(),\n\
    \                [](const Point& a, const Point& b) -> bool {\n              \
    \    return static_cast<long long>(a.first) * b.second -\n                   \
    \      static_cast<long long>(a.second) * b.first > 0;\n                });\n\
    \    }\n    std::copy(orthant[i].begin(), orthant[i].end(), std::back_inserter(*ps));\n\
    \  }\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GEOMETRY_ARGUMENT_SORT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/geometry/argument_sort.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/argument_sort.test.cpp
documentation_of: include/emthrm/geometry/argument_sort.hpp
layout: document
title: "\u504F\u89D2\u30BD\u30FC\u30C8"
---


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|効果|備考|
|:--|:--|:--|
|`void argument_sort(std::vector<std::pair<int, int>>* ps);`|点集合 $\mathrm{ps}$ に対して偏角ソートを行う。|$\arg(x) = \pi$ ($x < 0$), $\arg(0) = 0$ とする。|


## 参考文献

- https://betrue12.hateblo.jp/entry/2020/01/05/151244
- https://github.com/beet-aizu/library/blob/78fef02c3ce4f982525361a55adbfc78faabfb93/geometry/argsort.cpp


## Submissons

https://judge.yosupo.jp/submission/6794