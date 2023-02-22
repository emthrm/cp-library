---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: include/emthrm/math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/game/nim.test.cpp
    title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
  - icon: ':x:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: test/math/prime_factorization.test.cpp
    title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/prime_factorization.hpp\"\n\n\n\n#include\
    \ <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    std::vector<std::pair<T, int>> prime_factorization(T n) {\n  std::vector<std::pair<T,\
    \ int>> res;\n  for (T i = 2; i * i <= n; ++i) {\n    if (n % i == 0) {\n    \
    \  int exponent = 0;\n      for (; n % i == 0; n /= i) {\n        ++exponent;\n\
    \      }\n      res.emplace_back(i, exponent);\n    }\n  }\n  if (n > 1) res.emplace_back(n,\
    \ 1);\n  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_PRIME_FACTORIZATION_HPP_\n#define EMTHRM_MATH_PRIME_FACTORIZATION_HPP_\n\
    \n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T>\nstd::vector<std::pair<T, int>> prime_factorization(T n) {\n  std::vector<std::pair<T,\
    \ int>> res;\n  for (T i = 2; i * i <= n; ++i) {\n    if (n % i == 0) {\n    \
    \  int exponent = 0;\n      for (; n % i == 0; n /= i) {\n        ++exponent;\n\
    \      }\n      res.emplace_back(i, exponent);\n    }\n  }\n  if (n > 1) res.emplace_back(n,\
    \ 1);\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_PRIME_FACTORIZATION_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/prime_factorization.hpp
  requiredBy:
  - include/emthrm/math/is_primitive_root.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/prime_factorization.test.cpp
  - test/math/is_primitive_root.test.cpp
  - test/game/nim.test.cpp
documentation_of: include/emthrm/math/prime_factorization.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
---


## 時間計算量

$O(\sqrt{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::pair<T, int>> prime_factorization(T n);`|$n$ の素因数分解|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，p.111，マイナビ出版（2012）


## TODO

- ポラード・ロー素因数分解法 (Pollard's rho algorithm)
  - https://ja.wikipedia.org/wiki/%E3%83%9D%E3%83%A9%E3%83%BC%E3%83%89%E3%83%BB%E3%83%AD%E3%83%BC%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3%E6%B3%95
  - https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98
  - https://mathtrain.jp/rhoalgorithm
  - http://joisino.hatenablog.com/entry/2017/08/03/210000
  - http://idm.s9.xrea.com/factorization/rho.html
  - https://wacchoz.hatenablog.com/entry/2019/01/05/230128
  - https://gist.github.com/vintersnow/b0fa0faeef7597eba33400d2e615ad0e
  - http://orolog.hatenablog.jp/entry/20100804/1280943541
  - https://qiita.com/gushwell/items/561afde2e00bf3380c98
  - https://github.com/ei1333/library/blob/master/math/fast-prime-factorization.cpp
  - https://mugen1337.github.io/procon/Math/PollardRho.cpp
  - https://sotanishy.github.io/cp-library-cpp/math/fast_prime.cpp
  - https://judge.yosupo.jp/problem/factorize


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_A/review/4088167/emthrm/C++14
