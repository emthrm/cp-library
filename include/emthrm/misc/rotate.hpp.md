---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/rotate.test.cpp
    title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/misc/rotate.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <int ANGLE, typename T>\n\
    std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid,\n\
    \                                   const T space = ' ') {\n  static_assert(ANGLE\
    \ == 45 || ANGLE == 90);\n  const int h = grid.size(), w = grid.front().size();\n\
    \  std::vector<std::vector<T>> rotated_grid;\n  if constexpr (ANGLE == 45) {\n\
    \    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, space));\n    for\
    \ (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j) {\n        rotated_grid[i\
    \ + j][i - j + w - 1] = grid[i][j];\n      }\n    }\n  } else {\n    rotated_grid.assign(w,\
    \ std::vector<T>(h));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        rotated_grid[w - 1 - j][i] = grid[i][j];\n      }\n \
    \   }\n  }\n  return rotated_grid;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MISC_ROTATE_HPP_\n#define EMTHRM_MISC_ROTATE_HPP_\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <int ANGLE, typename\
    \ T>\nstd::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid,\n\
    \                                   const T space = ' ') {\n  static_assert(ANGLE\
    \ == 45 || ANGLE == 90);\n  const int h = grid.size(), w = grid.front().size();\n\
    \  std::vector<std::vector<T>> rotated_grid;\n  if constexpr (ANGLE == 45) {\n\
    \    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, space));\n    for\
    \ (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j) {\n        rotated_grid[i\
    \ + j][i - j + w - 1] = grid[i][j];\n      }\n    }\n  } else {\n    rotated_grid.assign(w,\
    \ std::vector<T>(h));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        rotated_grid[w - 1 - j][i] = grid[i][j];\n      }\n \
    \   }\n  }\n  return rotated_grid;\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_MISC_ROTATE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/misc/rotate.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
|`template <int ANGLE, typename T>`<br>`std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid, const T space = ' ');`|グリッド $\mathrm{grid}$ を $\mathrm{ANGLE}$ 度だけ回転させたもの|$\mathrm{ANGLE} \in \lbrace 45, 90 \rbrace$|


## 参考文献

- https://kagamiz.hatenablog.com/entry/2014/12/21/213931


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2953/review/4082725/emthrm/C++14
