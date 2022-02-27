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
  bundledCode: "#line 2 \"math/segmented_sieve.hpp\"\n#include <algorithm>\r\n#include\
    \ <cmath>\r\n#include <iterator>\r\n#include <vector>\r\n\r\nstd::vector<bool>\
    \ segmented_sieve(const long long low, const long long high) {\r\n  long long\
    \ root = 1;\r\n  while ((root + 1) * (root + 1) < high) ++root;\r\n  std::vector<bool>\
    \ is_prime(root + 1, true);\r\n  is_prime[0] = false;\r\n  is_prime[1] = false;\r\
    \n  std::vector<bool> res(high - low, true);\r\n  if (low < 2) std::fill(res.begin(),\
    \ std::next(res.begin(), 2 - low), false);\r\n  for (long long i = 2; i <= root;\
    \ ++i) {\r\n    if (is_prime[i]) {\r\n      for (long long j = i * i; j <= root;\
    \ j += i) {\r\n        is_prime[j] = false;\r\n      }\r\n      for (long long\
    \ j = std::max((low + i - 1) / i, 2LL) * i; j < high;\r\n           j += i) {\r\
    \n        res[j - low] = false;\r\n      }\r\n    }\r\n  }\r\n  return res;\r\n\
    }\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <iterator>\r\
    \n#include <vector>\r\n\r\nstd::vector<bool> segmented_sieve(const long long low,\
    \ const long long high) {\r\n  long long root = 1;\r\n  while ((root + 1) * (root\
    \ + 1) < high) ++root;\r\n  std::vector<bool> is_prime(root + 1, true);\r\n  is_prime[0]\
    \ = false;\r\n  is_prime[1] = false;\r\n  std::vector<bool> res(high - low, true);\r\
    \n  if (low < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);\r\
    \n  for (long long i = 2; i <= root; ++i) {\r\n    if (is_prime[i]) {\r\n    \
    \  for (long long j = i * i; j <= root; j += i) {\r\n        is_prime[j] = false;\r\
    \n      }\r\n      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j\
    \ < high;\r\n           j += i) {\r\n        res[j - low] = false;\r\n      }\r\
    \n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/segmented_sieve.hpp
  requiredBy: []
  timestamp: '2022-02-24 04:47:48+09:00'
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
