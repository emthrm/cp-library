---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/largest_rectangle.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\
      \u306E\u6700\u5927\u9577\u65B9\u5F62"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/largest_rectangle.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <stack>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nlong long largest_rectangle(const std::vector<T>&\
    \ height) {\n  const int n = height.size();\n  std::vector<int> left(n);\n  std::stack<T>\
    \ st;\n  long long res = 0;\n  for (int i = 0; i < n; ++i) {\n    while (!st.empty()\
    \ && height[st.top()] >= height[i]) {\n      res = std::max(\n          res, static_cast<long\
    \ long>(height[st.top()]) * (i - left[st.top()]));\n      st.pop();\n    }\n \
    \   left[i] = (st.empty() ? 0 : st.top() + 1);\n    st.emplace(i);\n  }\n  while\
    \ (!st.empty()) {\n    res = std::max(\n        res, static_cast<long long>(height[st.top()])\
    \ * (n - left[st.top()]));\n    st.pop();\n  }\n  return res;\n}\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_LARGEST_RECTANGLE_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_LARGEST_RECTANGLE_HPP_\n\
    \n#include <algorithm>\n#include <stack>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nlong long largest_rectangle(const std::vector<T>&\
    \ height) {\n  const int n = height.size();\n  std::vector<int> left(n);\n  std::stack<T>\
    \ st;\n  long long res = 0;\n  for (int i = 0; i < n; ++i) {\n    while (!st.empty()\
    \ && height[st.top()] >= height[i]) {\n      res = std::max(\n          res, static_cast<long\
    \ long>(height[st.top()]) * (i - left[st.top()]));\n      st.pop();\n    }\n \
    \   left[i] = (st.empty() ? 0 : st.top() + 1);\n    st.emplace(i);\n  }\n  while\
    \ (!st.empty()) {\n    res = std::max(\n        res, static_cast<long long>(height[st.top()])\
    \ * (n - left[st.top()]));\n    st.pop();\n  }\n  return res;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_LARGEST_RECTANGLE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/largest_rectangle.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/largest_rectangle.test.cpp
documentation_of: include/emthrm/dynamic_programming/largest_rectangle.hpp
layout: document
title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62\
  \ (largest rectangle in a histogram)"
---


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`largest_rectangle(height)`|高さ $\mathrm{height}$ で表されるヒストグラム中の長方形の最大面積|


## 参考

- https://ei1333.github.io/luzhiled/snippets/dp/largest-rectangle.html


## TODO

- http://algorithms.blog55.fc2.com/blog-entry-133.html
- 最大正方形
  - https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_A
- 最大長方形
  - https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_B


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/4082202/emthrm/C++14
