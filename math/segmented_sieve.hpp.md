---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/segmented_sieve.hpp\"\n#include <algorithm>\r\n#include\
    \ <cmath>\r\n#include <vector>\r\n\r\nstd::vector<bool> segmented_sieve(long long\
    \ low, long long high) {\r\n  std::vector<bool> is_prime(static_cast<int>(std::ceil(std::sqrt(high))),\
    \ true), res(high - low, true);\r\n  is_prime[0] = false;\r\n  if (is_prime.size()\
    \ >= 2) is_prime[1] = false;\r\n  for (long long i = low; i <= 1; ++i) res[i -\
    \ low] = false;\r\n  for (long long i = 2; i * i < high; ++i) {\r\n    if (is_prime[i])\
    \ {\r\n      for (long long j = i * i; j * j < high; j += i) is_prime[j] = false;\r\
    \n      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high; j +=\
    \ i) res[j - low] = false;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <vector>\r\
    \n\r\nstd::vector<bool> segmented_sieve(long long low, long long high) {\r\n \
    \ std::vector<bool> is_prime(static_cast<int>(std::ceil(std::sqrt(high))), true),\
    \ res(high - low, true);\r\n  is_prime[0] = false;\r\n  if (is_prime.size() >=\
    \ 2) is_prime[1] = false;\r\n  for (long long i = low; i <= 1; ++i) res[i - low]\
    \ = false;\r\n  for (long long i = 2; i * i < high; ++i) {\r\n    if (is_prime[i])\
    \ {\r\n      for (long long j = i * i; j * j < high; j += i) is_prime[j] = false;\r\
    \n      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high; j +=\
    \ i) res[j - low] = false;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/segmented_sieve.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/segmented_sieve.hpp
layout: document
title: segmented sieve
---


## 時間計算量

$O(\sqrt{H}\log{\log{\sqrt{H}}} + \frac{(H - L)\sqrt{H}}{\log{H}})$ ?


## 使用法

||説明|
|:--:|:--:|
|`segmented_sieve(low, high)`|$i \ (\mathrm{low} \leq i < \mathrm{high})$ が素数であるか．|


## 参考

- http://www.prefield.com/algorithm/math/segment_sieve.html


## ToDo

- https://uwitenpen.hatenadiary.org/entries/2011/12/03
