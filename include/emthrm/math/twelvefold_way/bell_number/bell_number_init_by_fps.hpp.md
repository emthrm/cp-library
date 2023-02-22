---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/bell_number/bell_number.md
    document_title: "\u30D9\u30EB\u6570\u306E\u6570\u8868 $n = k$ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp:\
    \ line 11: unable to process #include in #if / #ifdef / #ifndef other than include\
    \ guards\n"
  code: "/**\n * @brief \u30D9\u30EB\u6570\u306E\u6570\u8868 $n = k$ \u7248\n * @docs\
    \ docs/math/twelvefold_way/bell_number/bell_number.md\n */\n\n#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_BY_FPS_HPP_\n\
    #define EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_BY_FPS_HPP_\n\n\
    #include <vector>\n\n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> bell_number_init_by_fps(const\
    \ int n) {\n  FormalPowerSeries<T> b(n);\n  b[1] = 1;\n  b = b.exp(n);\n  b[0]\
    \ -= 1;\n  b = b.exp(n);\n  T fact = 1;\n  for (int i = 0; i <= n; ++i) {\n  \
    \  b[i] *= fact;\n    fact *= i + 1;\n  }\n  return b.coef;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_BY_FPS_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp
  requiredBy: []
  timestamp: '2023-02-21 03:04:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp
- /library/include/emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp.html
title: "\u30D9\u30EB\u6570\u306E\u6570\u8868 $n = k$ \u7248"
---
# ベル数 (Bell number)

区別された $n$ 個を $k$ グループ以下に分割する場合の数を $B(n, k)$ とおくと

$$
  B(n,k) = \sum_{j = 0}^k S(n, j) = \sum_{i = 0}^k \frac{i^n}{i!} \sum_{j = 0}^{k - i} \frac{(-1)^j}{j!}
$$

が成り立つ。ここで $S$ は[第2種スターリング数](../stirling_number/stirling_number.md)である。

$n = k$ を満たす $B(n, k)$ をベル数 $B_n$ と呼ぶ。

漸化式は

$$
  B_{n + 1} = \sum_{k = 0}^n \binom{n}{k} B_k
$$

であり、指数型母関数は

$$
  \sum_{n = 0}^\infty B_n \frac{x^n}{n!} = e^{e^x - 1}
$$

である。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(\min \lbrace N, K \rbrace \log{N})$|
|数表|$O(NK)$|
|数表 $n = k$ 版|$O(N\log{N})$|


## 仕様

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> bell_number(const int n, int k);`|$B(n, k)$|


### 数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> bell_number_init(const int n, const int k);`|$B(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 数表 $n = k$ 版

|名前|戻り値|
|:--|:--|
|`template <typename T> std::vector<T>`<br>`bell_number_init_by_fps(const int n);`|ベル数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考文献

- https://qiita.com/drken/items/f2ea4b58b0d21621bd51
- https://ja.wikipedia.org/wiki/ベル数


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088882/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088892/emthrm/C++14)
- 数表 $n = k$ 版
