---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: test/math/prime_factorization.test.cpp
    title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime_factorization.hpp\"\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<std::pair<T, int>> prime_factorization(T\
    \ n) {\r\n  std::vector<std::pair<T, int>> res;\r\n  for (T i = 2; i * i <= n;\
    \ ++i) {\r\n    if (n % i != 0) continue;\r\n    int exponent = 0;\r\n    while\
    \ (n % i == 0) {\r\n      ++exponent;\r\n      n /= i;\r\n    }\r\n    res.emplace_back(i,\
    \ exponent);\r\n  }\r\n  if (n != 1) res.emplace_back(n, 1);\r\n  return res;\r\
    \n}\r\n"
  code: "#pragma once\r\n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<std::pair<T, int>> prime_factorization(T n) {\r\n  std::vector<std::pair<T,\
    \ int>> res;\r\n  for (T i = 2; i * i <= n; ++i) {\r\n    if (n % i != 0) continue;\r\
    \n    int exponent = 0;\r\n    while (n % i == 0) {\r\n      ++exponent;\r\n \
    \     n /= i;\r\n    }\r\n    res.emplace_back(i, exponent);\r\n  }\r\n  if (n\
    \ != 1) res.emplace_back(n, 1);\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorization.hpp
  requiredBy:
  - math/is_primitive_root.hpp
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime_factorization.test.cpp
  - test/math/is_primitive_root.test.cpp
documentation_of: math/prime_factorization.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
---


## 時間計算量

$O(\sqrt{N})$


## 使用法

||説明|
|:--:|:--:|
|`prime_factorization(n)`|$n$ の素因数分解|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] p.111


## ToDo

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
  - https://judge.yosupo.jp/problem/factorize


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_A/review/4088167/emthrm/C++14
