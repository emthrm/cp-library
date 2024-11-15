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
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/slide_min.hpp\"\n\n\n\
    \n#include <deque>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <bool\
    \ IS_MINIMIZED = true, typename T>\nstd::vector<T> slide_min(const std::vector<T>&\
    \ a, const int len) {\n  const int n = a.size();\n  std::vector<T> res(n - len\
    \ + 1);\n  std::deque<T> deq;\n  for (int i = 0; i < n; ++i) {\n    while (!deq.empty()\
    \ &&\n           !(IS_MINIMIZED ? a[deq.back()] < a[i] : a[deq.back()] > a[i]))\
    \ {\n      deq.pop_back();\n    }\n    deq.emplace_back(i);\n    if (i + 1 >=\
    \ len) {\n      const int left = i + 1 - len;\n      res[left] = a[deq.front()];\n\
    \      if (deq.front() == left) deq.pop_front();\n    }\n  }\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_SLIDE_MIN_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_SLIDE_MIN_HPP_\n\
    \n#include <deque>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <bool\
    \ IS_MINIMIZED = true, typename T>\nstd::vector<T> slide_min(const std::vector<T>&\
    \ a, const int len) {\n  const int n = a.size();\n  std::vector<T> res(n - len\
    \ + 1);\n  std::deque<T> deq;\n  for (int i = 0; i < n; ++i) {\n    while (!deq.empty()\
    \ &&\n           !(IS_MINIMIZED ? a[deq.back()] < a[i] : a[deq.back()] > a[i]))\
    \ {\n      deq.pop_back();\n    }\n    deq.emplace_back(i);\n    if (i + 1 >=\
    \ len) {\n      const int left = i + 1 - len;\n      res[left] = a[deq.front()];\n\
    \      if (deq.front() == left) deq.pop_front();\n    }\n  }\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_SLIDE_MIN_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/slide_min.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/slide_min.test.cpp
documentation_of: include/emthrm/dynamic_programming/slide_min.hpp
layout: document
title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <bool IS_MINIMIZED = true, typename T>`<br>`std::vector<T> slide_min(const std::vector<T>& a, const int len);`|$A$ に対する長さ $\mathrm{len}$ のスライド最小値|


## 参考文献

- https://satanic0258.github.io/snippets/data-structure/SlideMinimum.html
- https://ei1333.github.io/luzhiled/snippets/dp/slide-min.html


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_D/review/4967096/emthrm/C++17