---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/math/osa_k.test.cpp
    title: "\u6570\u5B66/osa_k \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/osa_k.hpp\"\n\n\n\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\n\n\n\n#include\
    \ <numeric>\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const int\
    \ n) {\n  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/osa_k.hpp\"\n\n\
    namespace emthrm {\n\nstruct OsaK {\n  const std::vector<int> smallest_prime_factor;\n\
    \n  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve<false>(n))\
    \ {}\n\n  std::vector<std::pair<int, int>> query(int n) const {\n    std::vector<std::pair<int,\
    \ int>> res;\n    while (n > 1) {\n      const int prime = smallest_prime_factor[n];\n\
    \      int exponent = 0;\n      for (; smallest_prime_factor[n] == prime; n /=\
    \ prime) {\n        ++exponent;\n      }\n      res.emplace_back(prime, exponent);\n\
    \    }\n    return res;\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_OSA_K_HPP_\n#define EMTHRM_MATH_OSA_K_HPP_\n\n#include\
    \ <utility>\n#include <vector>\n\n#include \"emthrm/math/prime_sieve.hpp\"\n\n\
    namespace emthrm {\n\nstruct OsaK {\n  const std::vector<int> smallest_prime_factor;\n\
    \n  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve<false>(n))\
    \ {}\n\n  std::vector<std::pair<int, int>> query(int n) const {\n    std::vector<std::pair<int,\
    \ int>> res;\n    while (n > 1) {\n      const int prime = smallest_prime_factor[n];\n\
    \      int exponent = 0;\n      for (; smallest_prime_factor[n] == prime; n /=\
    \ prime) {\n        ++exponent;\n      }\n      res.emplace_back(prime, exponent);\n\
    \    }\n    return res;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_OSA_K_HPP_\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/osa_k.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/math/osa_k.test.cpp
documentation_of: include/emthrm/math/osa_k.hpp
layout: document
title: "osa_k \u6CD5"
---

[prime sieve](prime_sieve.md) を用いた[素因数分解](prime_factorization.md)である。


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 仕様

```cpp
struct OsaK;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`const std::vector<int> smallest_prime_factor`|$i$ の最小素因数|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit OsaK(const int n);`|$n$ 以下に対するオブジェクトを構築する。|
|`std::vector<std::pair<int, int>> query(int n) const;`|$n$ の素因数分解|


## 参考文献

- http://www.osak.jp/diary/diary_201310.html#20131017


## Submissons

https://atcoder.jp/contests/abc177/submissions/20504644
