---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/dynamic_programming/2d_cumulative_sum.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/2d_cumulative_sum.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <numeric>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    struct CumulativeSum2D {\n  explicit CumulativeSum2D(const int h, const int w)\n\
    \      : CumulativeSum2D(std::vector<std::vector<T>>(h, std::vector<T>(w, 0)))\
    \ {}\n\n  template <typename U>\n  explicit CumulativeSum2D(const std::vector<std::vector<U>>&\
    \ a)\n      : is_built(false), h(a.size()), w(a.front().size()),\n        data(h\
    \ + 1, std::vector<T>(w + 1, 0)) {\n    for (int i = 0; i < h; ++i) {\n      std::copy(a[i].begin(),\
    \ a[i].end(), std::next(data[i + 1].begin()));\n    }\n  }\n\n  void add(const\
    \ int y, const int x, const T val) {\n    assert(!is_built);\n    data[y + 1][x\
    \ + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    for (int i = 0; i < h; ++i) {\n      std::partial_sum(data[i +\
    \ 1].begin(), data[i + 1].end(),\n                       data[i + 1].begin());\n\
    \    }\n    for (int j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i)\
    \ {\n        data[i + 1][j] += data[i][j];\n      }\n    }\n  }\n\n  T query(const\
    \ int y1, const int x1, const int y2, const int x2) const {\n    assert(is_built);\n\
    \    return y1 > y2 || x1 > x2 ? 0 : data[y2 + 1][x2 + 1] - data[y2 + 1][x1]\n\
    \                                    - data[y1][x2 + 1] + data[y1][x1];\n  }\n\
    \n private:\n  bool is_built;\n  const int h, w;\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_2D_CUMULATIVE_SUM_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_2D_CUMULATIVE_SUM_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <numeric>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct CumulativeSum2D\
    \ {\n  explicit CumulativeSum2D(const int h, const int w)\n      : CumulativeSum2D(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w, 0))) {}\n\n  template <typename U>\n  explicit CumulativeSum2D(const\
    \ std::vector<std::vector<U>>& a)\n      : is_built(false), h(a.size()), w(a.front().size()),\n\
    \        data(h + 1, std::vector<T>(w + 1, 0)) {\n    for (int i = 0; i < h; ++i)\
    \ {\n      std::copy(a[i].begin(), a[i].end(), std::next(data[i + 1].begin()));\n\
    \    }\n  }\n\n  void add(const int y, const int x, const T val) {\n    assert(!is_built);\n\
    \    data[y + 1][x + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n\
    \    is_built = true;\n    for (int i = 0; i < h; ++i) {\n      std::partial_sum(data[i\
    \ + 1].begin(), data[i + 1].end(),\n                       data[i + 1].begin());\n\
    \    }\n    for (int j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i)\
    \ {\n        data[i + 1][j] += data[i][j];\n      }\n    }\n  }\n\n  T query(const\
    \ int y1, const int x1, const int y2, const int x2) const {\n    assert(is_built);\n\
    \    return y1 > y2 || x1 > x2 ? 0 : data[y2 + 1][x2 + 1] - data[y2 + 1][x1]\n\
    \                                    - data[y1][x2 + 1] + data[y1][x1];\n  }\n\
    \n private:\n  bool is_built;\n  const int h, w;\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_2D_CUMULATIVE_SUM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
  requiredBy: []
  timestamp: '2023-02-21 03:04:07+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/dynamic_programming/2d_cumulative_sum.test.cpp
documentation_of: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---


## 時間計算量

$O(HW)$


## 仕様

```cpp
template <typename T>
struct CumulativeSum2D;
```

- `T`：要素型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit CumulativeSum2D(const int h, const int w);`|高さ $H$、幅 $W$ のオブジェクトを構築する。|
|`template <typename U>`<br>`explicit CumulativeSum2D(const std::vector<std::vector<U>>& a);`|$A$ に対してオブジェクトを構築する。|
|`void add(const int y, const int x, const T val);`|$A_{yx} \gets A_{yx} + \mathrm{val}$|
|`void build();`|構築する。|
|`T query(const int y1, const int x1, const int y2, const int x2) const;`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## Submissons

https://atcoder.jp/contests/abc086/submissions/26008164
