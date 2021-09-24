---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dynamic_programming/2d_cumulative_sum.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/2d_cumulative_sum.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename T>\nstruct CumulativeSum2D {\n  CumulativeSum2D(const\
    \ int h, const int w)\n  : CumulativeSum2D(std::vector<std::vector<T>>(h, std::vector<T>(w,\
    \ 0))) {}\n\n  template <typename U>\n  CumulativeSum2D(const std::vector<std::vector<U>>\
    \ &a) : h(a.size()), w(a.front().size()) {\n    dat.assign(h + 1, std::vector<T>(w\
    \ + 1, 0));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j)\
    \ {\n        dat[i + 1][j + 1] = a[i][j];\n      }\n    }\n  }\n\n  void add(const\
    \ int y, const int x, const T val) {\n    assert(!is_built);\n    dat[y + 1][x\
    \ + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j)\
    \ {\n        dat[i + 1][j + 1] += dat[i + 1][j];\n      }\n    }\n    for (int\
    \ j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i) {\n        dat[i +\
    \ 1][j] += dat[i][j];\n      }\n    }\n  }\n\n  T query(const int y1, const int\
    \ x1, const int y2, const int x2) const {\n    assert(is_built);\n    return y1\
    \ <= y2 && x1 <= x2 ? dat[y2 + 1][x2 + 1] - dat[y2 + 1][x1] - dat[y1][x2 + 1]\
    \ + dat[y1][x1] : 0;\n  }\n\nprivate:\n  bool is_built = false;\n  const int h,\
    \ w;\n  std::vector<std::vector<T>> dat;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstruct CumulativeSum2D {\n  CumulativeSum2D(const int h, const int w)\n\
    \  : CumulativeSum2D(std::vector<std::vector<T>>(h, std::vector<T>(w, 0))) {}\n\
    \n  template <typename U>\n  CumulativeSum2D(const std::vector<std::vector<U>>\
    \ &a) : h(a.size()), w(a.front().size()) {\n    dat.assign(h + 1, std::vector<T>(w\
    \ + 1, 0));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j)\
    \ {\n        dat[i + 1][j + 1] = a[i][j];\n      }\n    }\n  }\n\n  void add(const\
    \ int y, const int x, const T val) {\n    assert(!is_built);\n    dat[y + 1][x\
    \ + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j)\
    \ {\n        dat[i + 1][j + 1] += dat[i + 1][j];\n      }\n    }\n    for (int\
    \ j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i) {\n        dat[i +\
    \ 1][j] += dat[i][j];\n      }\n    }\n  }\n\n  T query(const int y1, const int\
    \ x1, const int y2, const int x2) const {\n    assert(is_built);\n    return y1\
    \ <= y2 && x1 <= x2 ? dat[y2 + 1][x2 + 1] - dat[y2 + 1][x1] - dat[y1][x2 + 1]\
    \ + dat[y1][x1] : 0;\n  }\n\nprivate:\n  bool is_built = false;\n  const int h,\
    \ w;\n  std::vector<std::vector<T>> dat;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/2d_cumulative_sum.hpp
  requiredBy: []
  timestamp: '2021-09-20 16:05:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/dynamic_programming/2d_cumulative_sum.test.cpp
documentation_of: dynamic_programming/2d_cumulative_sum.hpp
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
|`add(y, x, val)`|$A_{yx} += \mathrm{val}$|
|`build()`|構築する．|
|`query(y1, x1, y2, x2)`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## Verified

https://atcoder.jp/contests/abc086/submissions/26008164
