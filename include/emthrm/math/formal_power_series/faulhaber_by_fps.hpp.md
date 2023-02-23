---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/bernoulli_number.hpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
  - icon: ':question:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series/faulhaber.md
    document_title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F\
      \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp: line 12: unable\
    \ to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\
    \u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\n * @docs docs/math/formal_power_series/faulhaber.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_\n#define\
    \ EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_\n\n#include <cassert>\n\
    #include <vector>\n\n#include \"emthrm/math/formal_power_series/bernoulli_number.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\ntemplate <int T>\n\
    MInt<T> faulhaber_by_fps(const long long n, const int k) {\n  using ModInt = MInt<T>;\n\
    \  if (n <= 1) [[unlikely]] return 0;\n  if (k == 0) [[unlikely]] return n - 1;\n\
    \  ModInt::init(k + 1);\n  const std::vector<ModInt> bernoulli = bernoulli_number<ModInt>(k);\n\
    \  ModInt res = 0, p = 1;\n  for (int i = k; i >= 0; --i) {\n    p *= n;\n   \
    \ res += ModInt::nCk(k + 1, i) * bernoulli[i] * p;\n  }\n  return res / (k + 1);\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/bernoulli_number.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
documentation_of: include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
- /library/include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp.html
title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\
  \u7684\u51AA\u7D1A\u6570\u7248"
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
|`template <int T>`<br>`MInt<T> faulhaber_by_fps(const long long n, const int k);`|$S_k(n)$|


### ラグランジュ補間版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k);`|$S_k(n)$|


## 参考文献

- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Submissons

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
