---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/rotate.test.cpp
    title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/misc/rotate.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ rotate(const std::vector<std::vector<T>>& grid,\n                          \
    \         const int angle, const T space = ' ') {\n  const int h = grid.size(),\
    \ w = grid.front().size();\n  std::vector<std::vector<T>> rotated_grid;\n  if\
    \ (angle == 45) {\n    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1,\
    \ space));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j)\
    \ {\n        rotated_grid[i + j][i - j + w - 1] = grid[i][j];\n      }\n    }\n\
    \  } else if (angle == 90) {\n    rotated_grid.assign(w, std::vector<T>(h));\n\
    \    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j) {\n    \
    \    rotated_grid[w - 1 - j][i] = grid[i][j];\n      }\n    }\n  } else {\n  \
    \  assert(false);\n  }\n  return rotated_grid;\n}\n\n}  // namespace emthrm\n\n\
    \n"
  code: "#ifndef EMTHRM_MISC_ROTATE_HPP_\n#define EMTHRM_MISC_ROTATE_HPP_\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid,\n\
    \                                   const int angle, const T space = ' ') {\n\
    \  const int h = grid.size(), w = grid.front().size();\n  std::vector<std::vector<T>>\
    \ rotated_grid;\n  if (angle == 45) {\n    rotated_grid.assign(h + w - 1, std::vector<T>(h\
    \ + w - 1, space));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        rotated_grid[i + j][i - j + w - 1] = grid[i][j];\n  \
    \    }\n    }\n  } else if (angle == 90) {\n    rotated_grid.assign(w, std::vector<T>(h));\n\
    \    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j) {\n    \
    \    rotated_grid[w - 1 - j][i] = grid[i][j];\n      }\n    }\n  } else {\n  \
    \  assert(false);\n  }\n  return rotated_grid;\n}\n\n}  // namespace emthrm\n\n\
    #endif  // EMTHRM_MISC_ROTATE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/misc/rotate.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/rotate.test.cpp
documentation_of: include/emthrm/misc/rotate.hpp
layout: document
title: "\u56DE\u8EE2 (rotation)"
---

点の回転は

- $45^\circ$ のとき $(x, y) \rightarrow (x - y, x + y)$、
- $90^\circ$ のとき $(x, y) \rightarrow (-y, x)$

と変換すればよい。


## 時間計算量

$O(HW)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid, const int angle, const T space = ' ');`|グリッド $\mathrm{grid}$ を $\mathrm{angle}$ 度だけ回転させたもの|$\mathrm{angle} \in \lbrace 45, 90 \rbrace$|


## 参考文献

- https://kagamiz.hatenablog.com/entry/2014/12/21/213931


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2953/review/4082725/emthrm/C++14
