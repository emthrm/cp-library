---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/lagrange_interpolation2.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u72482"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\
      \u88DC\u9593\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series/faulhaber.md
    document_title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F\
      \ \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp:\
    \ line 11: unable to process #include in #if / #ifdef / #ifndef other than include\
    \ guards\n"
  code: "/**\n * @brief \u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\
    \u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248\n * @docs docs/math/formal_power_series/faulhaber.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_LAGRANGE_INTERPOLATION_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_LAGRANGE_INTERPOLATION_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/lagrange_interpolation2.hpp\"\n\
    #include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\ntemplate <int T>\n\
    MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k) {\n\
    \  using ModInt = MInt<T>;\n  if (n < 1) return 0;\n  std::vector<ModInt> y(k\
    \ + 2, 0);\n  for (int i = 1; i < k + 2; ++i) {\n    y[i] = y[i - 1] + ModInt(i).pow(k);\n\
    \  }\n  return n - 1 < k + 2 ? y[n - 1] : lagrange_interpolation(y, ModInt(n -\
    \ 1));\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_LAGRANGE_INTERPOLATION_HPP_\n"
  dependsOn:
  - include/emthrm/math/lagrange_interpolation2.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
documentation_of: include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
- /library/include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp.html
title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\
  \u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
---
# ファウルハーバーの公式 (Faulhaber's formula)

$$
  S_k(n) \mathrel{:=} \sum_{i = 1}^{n - 1} i^k
$$

と定義すると

$$
  S_k(n + 1) = \dfrac{1}{k + 1} \sum_{i = 0}^k \binom{k + 1}{i} B_i n^{k + 1 - i}
$$

が成り立つ。ここで $B$ は[ベルヌーイ数](bernoulli_number)である。


## 時間計算量

||時間計算量|
|:--|:--|
|形式的冪級数版|$O(K\log{K})$|
|ラグランジュ補間版|$O(K \log{\max{\lbrace K, M \rbrace}})$|


## 仕様

### 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <int T> MInt<T> faulhaber_by_fps(const long long n, const int k);`|$S_k(n)$|


### ラグランジュ補間版

|名前|戻り値|
|:--|:--|
|`template <int T> MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k);`|$S_k(n)$|


## 参考文献

- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Submissons

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
