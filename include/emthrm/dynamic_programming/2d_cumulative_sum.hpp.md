---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/2d_cumulative_sum.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/2d_cumulative_sum.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct CumulativeSum2D\
    \ {\n  explicit CumulativeSum2D(const int h, const int w)\n      : CumulativeSum2D(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w, 0))) {}\n\n  template <typename U>\n  explicit CumulativeSum2D(const\
    \ std::vector<std::vector<U>>& a)\n      : is_built(false), h(a.size()), w(a.front().size()),\n\
    \        data(h + 1, std::vector<T>(w + 1, 0)) {\n    for (int i = 0; i < h; ++i)\
    \ {\n      std::copy(a[i].begin(), a[i].end(), std::next(data[i + 1].begin()));\n\
    \    }\n  }\n\n  void add(const int y, const int x, const T val) {\n    assert(!is_built);\n\
    \    data[y + 1][x + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n\
    \    is_built = true;\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        data[i + 1][j + 1] += data[i + 1][j];\n      }\n    }\n\
    \    for (int j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i) {\n   \
    \     data[i + 1][j] += data[i][j];\n      }\n    }\n  }\n\n  T query(const int\
    \ y1, const int x1, const int y2, const int x2) const {\n    assert(is_built);\n\
    \    return y1 > y2 || x1 > x2 ? 0 : data[y2 + 1][x2 + 1] - data[y2 + 1][x1]\n\
    \                                    - data[y1][x2 + 1] + data[y1][x1];\n  }\n\
    \n private:\n  bool is_built;\n  const int h, w;\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_2D_CUMULATIVE_SUM_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_2D_CUMULATIVE_SUM_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nstruct CumulativeSum2D {\n  explicit\
    \ CumulativeSum2D(const int h, const int w)\n      : CumulativeSum2D(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w, 0))) {}\n\n  template <typename U>\n  explicit CumulativeSum2D(const\
    \ std::vector<std::vector<U>>& a)\n      : is_built(false), h(a.size()), w(a.front().size()),\n\
    \        data(h + 1, std::vector<T>(w + 1, 0)) {\n    for (int i = 0; i < h; ++i)\
    \ {\n      std::copy(a[i].begin(), a[i].end(), std::next(data[i + 1].begin()));\n\
    \    }\n  }\n\n  void add(const int y, const int x, const T val) {\n    assert(!is_built);\n\
    \    data[y + 1][x + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n\
    \    is_built = true;\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        data[i + 1][j + 1] += data[i + 1][j];\n      }\n    }\n\
    \    for (int j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i) {\n   \
    \     data[i + 1][j] += data[i][j];\n      }\n    }\n  }\n\n  T query(const int\
    \ y1, const int x1, const int y2, const int x2) const {\n    assert(is_built);\n\
    \    return y1 > y2 || x1 > x2 ? 0 : data[y2 + 1][x2 + 1] - data[y2 + 1][x1]\n\
    \                                    - data[y1][x2 + 1] + data[y1][x1];\n  }\n\
    \n private:\n  bool is_built;\n  const int h, w;\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_2D_CUMULATIVE_SUM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/2d_cumulative_sum.test.cpp
documentation_of: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---


## 時間計算量

$O(HW)$


## 使用法

||説明|
|:--:|:--:|
|`CumulativeSum2D<T>(h, w)`|高さ $H$, 幅 $W$ の2次元累積和を考える．|
|`CumulativeSum2D<T>(a)`|$A$ の2次元累積和を考える．|
|`add(y, x, val)`|$A_{yx} \gets A_{yx} + \mathrm{val}$|
|`build()`|構築する．|
|`query(y1, x1, y2, x2)`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## Verified

https://atcoder.jp/contests/abc086/submissions/26008164
