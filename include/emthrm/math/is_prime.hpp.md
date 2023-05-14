---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/is_prime.test.cpp
    title: "\u6570\u5B66/\u7D20\u6570\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/is_prime.hpp\"\n\n\n\nnamespace emthrm\
    \ {\n\nbool is_prime(const long long n) {\n  if (n <= 1) [[unlikely]] return false;\n\
    \  for (long long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) return false;\n\
    \  }\n  return true;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_IS_PRIME_HPP_\n#define EMTHRM_MATH_IS_PRIME_HPP_\n\n\
    namespace emthrm {\n\nbool is_prime(const long long n) {\n  if (n <= 1) [[unlikely]]\
    \ return false;\n  for (long long i = 2; i * i <= n; ++i) {\n    if (n % i ==\
    \ 0) return false;\n  }\n  return true;\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_MATH_IS_PRIME_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/is_prime.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/is_prime.test.cpp
documentation_of: include/emthrm/math/is_prime.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A (primality test)"
---


## 時間計算量

$O(\sqrt{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`bool is_prime(const long long n);`|$n$ は素数であるか。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.110-111，マイナビ出版（2012）


## TODO

- https://www.slideshare.net/DEGwer/ss-14119074
- https://qiita.com/srtk86/items/609737d50c9ef5f5dc59
- ミラー-ラビン素数判定法 (Miller–Rabin primality test)
  - https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95
  - https://qiita.com/zu_rin/items/25521b5870389e0f85bf
  - http://joisino.hatenablog.com/entry/2017/08/03/210000
  - ~~http://www.prefield.com/algorithm/math/isprime.html~~
  - https://tubo28.me/compprog/algorithm/miller-rabin/
  - https://sotanishy.github.io/cp-library-cpp/math/fast_prime.cpp
  - https://yukicoder.me/problems/1967
- ガウス素数
  - https://ja.wikipedia.org/wiki/%E3%82%AC%E3%82%A6%E3%82%B9%E6%95%B4%E6%95%B0
  - https://mathtrain.jp/gaussianint
  - http://aozoragakuen.sakura.ne.jp/suuron/node56.html
  - http://arimoto.lolipop.jp/%E3%82%AC%E3%82%A6%E3%82%B9%E3%81%AE%E7%B4%A0%E6%95%B0.pdf
  - ~~http://www.prefield.com/algorithm/math/isgprime.html~~


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_1_C/review/4088317/emthrm/C++14
