---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/math/segmented_sieve.test.cpp
    title: "\u6570\u5B66/segmented sieve"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/segmented_sieve.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iterator>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\nstd::vector<bool> segmented_sieve(const long long low, const long\
    \ long high) {\n  long long root = 1;\n  while ((root + 1) * (root + 1) < high)\
    \ ++root;\n  std::vector<bool> is_prime(root + 1, true);\n  is_prime[0] = false;\n\
    \  is_prime[1] = false;\n  std::vector<bool> res(high - low, true);\n  if (low\
    \ < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);\n  for\
    \ (long long i = 2; i <= root; ++i) {\n    if (is_prime[i]) [[unlikely]] {\n \
    \     for (long long j = i * i; j <= root; j += i) {\n        is_prime[j] = false;\n\
    \      }\n      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high;\n\
    \           j += i) {\n        res[j - low] = false;\n      }\n    }\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_SEGMENTED_SIEVE_HPP_\n#define EMTHRM_MATH_SEGMENTED_SIEVE_HPP_\n\
    \n#include <algorithm>\n#include <cmath>\n#include <iterator>\n#include <vector>\n\
    \nnamespace emthrm {\n\nstd::vector<bool> segmented_sieve(const long long low,\
    \ const long long high) {\n  long long root = 1;\n  while ((root + 1) * (root\
    \ + 1) < high) ++root;\n  std::vector<bool> is_prime(root + 1, true);\n  is_prime[0]\
    \ = false;\n  is_prime[1] = false;\n  std::vector<bool> res(high - low, true);\n\
    \  if (low < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);\n\
    \  for (long long i = 2; i <= root; ++i) {\n    if (is_prime[i]) [[unlikely]]\
    \ {\n      for (long long j = i * i; j <= root; j += i) {\n        is_prime[j]\
    \ = false;\n      }\n      for (long long j = std::max((low + i - 1) / i, 2LL)\
    \ * i; j < high;\n           j += i) {\n        res[j - low] = false;\n      }\n\
    \    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_SEGMENTED_SIEVE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/segmented_sieve.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/math/segmented_sieve.test.cpp
documentation_of: include/emthrm/math/segmented_sieve.hpp
layout: document
title: segmented sieve
---


## 時間計算量

$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?


## 仕様

|名前|戻り値|
|:--|:--|
|`std::vector<bool> segmented_sieve(const long long low, const long long high);`|$i$ ($\mathrm{low} \leq i < \mathrm{high}$) が素数であるか。|


## 参考文献

- http://www.prefield.com/algorithm/math/segment_sieve.html


## TODO

- https://uwitenpen.hatenadiary.org/entries/2011/12/03


## Submissons

https://atcoder.jp/contests/math-and-algorithm/submissions/29613055
