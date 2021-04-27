---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dynamic_programming/cumulative_sum.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/cumulative_sum.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename T>\nstruct CumulativeSum {\n  CumulativeSum(int\
    \ h, int w) : CumulativeSum(std::vector<std::vector<T>>(h, std::vector<T>(w, 0)))\
    \ {}\n\n  template <typename U>\n  CumulativeSum(const std::vector<std::vector<U>>\
    \ &a) : h(a.size()), w(a.front().size()) {\n    dat.assign(h + 1, std::vector<T>(w\
    \ + 1, 0));\n    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) dat[i\
    \ + 1][j + 1] = a[i][j];\n  }\n\n  void add(int y, int x, T val) {\n    assert(!is_built);\n\
    \    dat[y + 1][x + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n\
    \    is_built = true;\n    for (int i = 0; i < h; ++i) for (int j = 0; j < w;\
    \ ++j) dat[i + 1][j + 1] += dat[i + 1][j];\n    for (int j = 1; j <= w; ++j) for\
    \ (int i = 1; i < h; ++i) dat[i + 1][j] += dat[i][j];\n  }\n\n  T query(int y1,\
    \ int x1, int y2, int x2) const {\n    assert(is_built);\n    return y1 <= y2\
    \ && x1 <= x2 ? dat[y2 + 1][x2 + 1] - dat[y2 + 1][x1] - dat[y1][x2 + 1] + dat[y1][x1]\
    \ : 0;\n  }\n\nprivate:\n  bool is_built = false;\n  int h, w;\n  std::vector<std::vector<T>>\
    \ dat;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstruct CumulativeSum {\n  CumulativeSum(int h, int w) : CumulativeSum(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w, 0))) {}\n\n  template <typename U>\n  CumulativeSum(const\
    \ std::vector<std::vector<U>> &a) : h(a.size()), w(a.front().size()) {\n    dat.assign(h\
    \ + 1, std::vector<T>(w + 1, 0));\n    for (int i = 0; i < h; ++i) for (int j\
    \ = 0; j < w; ++j) dat[i + 1][j + 1] = a[i][j];\n  }\n\n  void add(int y, int\
    \ x, T val) {\n    assert(!is_built);\n    dat[y + 1][x + 1] += val;\n  }\n\n\
    \  void build() {\n    assert(!is_built);\n    is_built = true;\n    for (int\
    \ i = 0; i < h; ++i) for (int j = 0; j < w; ++j) dat[i + 1][j + 1] += dat[i +\
    \ 1][j];\n    for (int j = 1; j <= w; ++j) for (int i = 1; i < h; ++i) dat[i +\
    \ 1][j] += dat[i][j];\n  }\n\n  T query(int y1, int x1, int y2, int x2) const\
    \ {\n    assert(is_built);\n    return y1 <= y2 && x1 <= x2 ? dat[y2 + 1][x2 +\
    \ 1] - dat[y2 + 1][x1] - dat[y1][x2 + 1] + dat[y1][x1] : 0;\n  }\n\nprivate:\n\
    \  bool is_built = false;\n  int h, w;\n  std::vector<std::vector<T>> dat;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/dynamic_programming/cumulative_sum.test.cpp
documentation_of: dynamic_programming/cumulative_sum.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---


## 時間計算量

$O(HW)$


## 使用法

||説明|
|:--:|:--:|
|`CumulativeSum<T>(h, w)`|高さ $H$, 幅 $W$ の2次元累積和を考える．|
|`CumulativeSum<T>(a)`|$A$ の2次元累積和を考える．|
|`add(y, x, val)`|$A_{yx} += \mathrm{val}$|
|`build()`|構築する．|
|`query(y1, x1, y2, x2)`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## Verified

https://atcoder.jp/contests/wupc2012/submissions/9238603
