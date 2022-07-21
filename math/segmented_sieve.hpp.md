---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/segmented_sieve.test.cpp
    title: "\u6570\u5B66/segmented sieve"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/segmented_sieve.hpp\"\n#include <algorithm>\n#include\
    \ <cmath>\n#include <iterator>\n#include <vector>\n\nstd::vector<bool> segmented_sieve(const\
    \ long long low, const long long high) {\n  long long root = 1;\n  while ((root\
    \ + 1) * (root + 1) < high) ++root;\n  std::vector<bool> is_prime(root + 1, true);\n\
    \  is_prime[0] = false;\n  is_prime[1] = false;\n  std::vector<bool> res(high\
    \ - low, true);\n  if (low < 2) std::fill(res.begin(), std::next(res.begin(),\
    \ 2 - low), false);\n  for (long long i = 2; i <= root; ++i) {\n    if (is_prime[i])\
    \ {\n      for (long long j = i * i; j <= root; j += i) {\n        is_prime[j]\
    \ = false;\n      }\n      for (long long j = std::max((low + i - 1) / i, 2LL)\
    \ * i; j < high;\n           j += i) {\n        res[j - low] = false;\n      }\n\
    \    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <iterator>\n\
    #include <vector>\n\nstd::vector<bool> segmented_sieve(const long long low, const\
    \ long long high) {\n  long long root = 1;\n  while ((root + 1) * (root + 1) <\
    \ high) ++root;\n  std::vector<bool> is_prime(root + 1, true);\n  is_prime[0]\
    \ = false;\n  is_prime[1] = false;\n  std::vector<bool> res(high - low, true);\n\
    \  if (low < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);\n\
    \  for (long long i = 2; i <= root; ++i) {\n    if (is_prime[i]) {\n      for\
    \ (long long j = i * i; j <= root; j += i) {\n        is_prime[j] = false;\n \
    \     }\n      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high;\n\
    \           j += i) {\n        res[j - low] = false;\n      }\n    }\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/segmented_sieve.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/segmented_sieve.test.cpp
documentation_of: math/segmented_sieve.hpp
layout: document
title: segmented sieve
---


## 時間計算量

$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?


## 使用法

||説明|
|:--:|:--:|
|`segmented_sieve(low, high)`|$i$ ($\mathrm{low} \leq i < \mathrm{high}$) が素数であるか．|


## 参考

- http://www.prefield.com/algorithm/math/segment_sieve.html


## ToDo

- https://uwitenpen.hatenadiary.org/entries/2011/12/03


## Verified

https://atcoder.jp/contests/math-and-algorithm/submissions/29613055
