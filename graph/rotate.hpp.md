---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/rotate.test.cpp
    title: "\u30B0\u30E9\u30D5/\u56DE\u8EE2"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/rotate.hpp\"\n#include <cassert>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstd::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>\
    \ &grid, int angle, T basis = ' ') {\r\n  int h = grid.size(), w = grid.front().size();\r\
    \n  std::vector<std::vector<T>> rotated_grid;\r\n  if (angle == 45) {\r\n    rotated_grid.assign(h\
    \ + w - 1, std::vector<T>(h + w - 1, basis));\r\n    for (int i = 0; i < h; ++i)\
    \ for (int j = 0; j < w; ++j) rotated_grid[i + j][i - j + w - 1] = grid[i][j];\r\
    \n  } else if (angle == 90) {\r\n    rotated_grid.assign(w, std::vector<T>(h));\r\
    \n    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) rotated_grid[w -\
    \ 1 - j][i] = grid[i][j];\r\n  } else {\r\n    assert(false);\r\n  }\r\n  return\
    \ rotated_grid;\r\n}\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<std::vector<T>> rotate(const std::vector<std::vector<T>> &grid,\
    \ int angle, T basis = ' ') {\r\n  int h = grid.size(), w = grid.front().size();\r\
    \n  std::vector<std::vector<T>> rotated_grid;\r\n  if (angle == 45) {\r\n    rotated_grid.assign(h\
    \ + w - 1, std::vector<T>(h + w - 1, basis));\r\n    for (int i = 0; i < h; ++i)\
    \ for (int j = 0; j < w; ++j) rotated_grid[i + j][i - j + w - 1] = grid[i][j];\r\
    \n  } else if (angle == 90) {\r\n    rotated_grid.assign(w, std::vector<T>(h));\r\
    \n    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) rotated_grid[w -\
    \ 1 - j][i] = grid[i][j];\r\n  } else {\r\n    assert(false);\r\n  }\r\n  return\
    \ rotated_grid;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/rotate.hpp
  requiredBy: []
  timestamp: '2021-02-10 22:43:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/rotate.test.cpp
documentation_of: graph/rotate.hpp
layout: document
title: "\u56DE\u8EE2 (rotation)"
---

点の回転は

- $45^\circ$ の場合，$(x, y) \rightarrow (x - y, x + y)$
- $90^\circ$ の場合，$(x, y) \rightarrow (-y, x)$

と変換すればよい．


## 時間計算量

$O(WH)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`rotate(grid, angle, 基準 = ' ')`|グリッド $\mathrm{grid}$ を $\mathrm{angle}$ 度だけ回転させたもの|$\mathrm{angle} \in \{45, 90\}$|


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2953/review/4082725/emthrm/C++14