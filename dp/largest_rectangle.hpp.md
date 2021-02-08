---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dp/largest_rectangle.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\
      \u306E\u6700\u5927\u9577\u65B9\u5F62"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/largest_rectangle.hpp\"\n#include <stack>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nlong long largest_rectangle(const std::vector<T>\
    \ &height) {\r\n  int n = height.size();\r\n  std::vector<int> left(n);\r\n  std::stack<T>\
    \ st;\r\n  long long res = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    while\
    \ (!st.empty() && height[st.top()] >= height[i]) {\r\n      long long tmp = static_cast<long\
    \ long>(height[st.top()]) * (i - left[st.top()]);\r\n      if (tmp > res) res\
    \ = tmp;\r\n      st.pop();\r\n    }\r\n    left[i] = st.empty() ? 0 : st.top()\
    \ + 1;\r\n    st.emplace(i);\r\n  }\r\n  while (!st.empty()) {\r\n    long long\
    \ tmp = static_cast<long long>(height[st.top()]) * (n - left[st.top()]);\r\n \
    \   if (tmp > res) res = tmp;\r\n    st.pop();\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <stack>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nlong long largest_rectangle(const std::vector<T> &height) {\r\n  int n\
    \ = height.size();\r\n  std::vector<int> left(n);\r\n  std::stack<T> st;\r\n \
    \ long long res = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    while (!st.empty()\
    \ && height[st.top()] >= height[i]) {\r\n      long long tmp = static_cast<long\
    \ long>(height[st.top()]) * (i - left[st.top()]);\r\n      if (tmp > res) res\
    \ = tmp;\r\n      st.pop();\r\n    }\r\n    left[i] = st.empty() ? 0 : st.top()\
    \ + 1;\r\n    st.emplace(i);\r\n  }\r\n  while (!st.empty()) {\r\n    long long\
    \ tmp = static_cast<long long>(height[st.top()]) * (n - left[st.top()]);\r\n \
    \   if (tmp > res) res = tmp;\r\n    st.pop();\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/largest_rectangle.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dp/largest_rectangle.test.cpp
documentation_of: dp/largest_rectangle.hpp
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


## ToDo

- http://algorithms.blog55.fc2.com/blog-entry-133.html
- 最大正方形
  - https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_A
- 最大長方形
  - https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_B


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/4082202/emthrm/C++14
