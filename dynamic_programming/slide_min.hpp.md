---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/slide_min.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/slide_min.hpp\"\n#include <deque>\r\n\
    #include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T> slide_min(const\
    \ std::vector<T> &a, int len, bool is_minimized = true) {\r\n  int n = a.size();\r\
    \n  std::vector<T> res(n - len + 1);\r\n  std::deque<T> deq;\r\n  for (int i =\
    \ 0; i < n; ++i) {\r\n    while (!deq.empty() && !(is_minimized ? a[deq.back()]\
    \ < a[i] : a[deq.back()] > a[i])) deq.pop_back();\r\n    deq.emplace_back(i);\r\
    \n    if (i + 1 >= len) {\r\n      int left = i + 1 - len;\r\n      res[left]\
    \ = a[deq.front()];\r\n      if (deq.front() == left) deq.pop_front();\r\n   \
    \ }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <deque>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<T> slide_min(const std::vector<T> &a, int len, bool is_minimized\
    \ = true) {\r\n  int n = a.size();\r\n  std::vector<T> res(n - len + 1);\r\n \
    \ std::deque<T> deq;\r\n  for (int i = 0; i < n; ++i) {\r\n    while (!deq.empty()\
    \ && !(is_minimized ? a[deq.back()] < a[i] : a[deq.back()] > a[i])) deq.pop_back();\r\
    \n    deq.emplace_back(i);\r\n    if (i + 1 >= len) {\r\n      int left = i +\
    \ 1 - len;\r\n      res[left] = a[deq.front()];\r\n      if (deq.front() == left)\
    \ deq.pop_front();\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/slide_min.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/slide_min.test.cpp
documentation_of: dynamic_programming/slide_min.hpp
layout: document
title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`slide_min(a, len, is_minimized = true)`|$A$ における長さ $\mathrm{len}$ のスライド最小値|


## 参考

- https://satanic0258.github.io/snippets/data-structure/SlideMinimum.html
- https://ei1333.github.io/luzhiled/snippets/dp/slide-min.html


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_D/review/4967096/emthrm/C++17
