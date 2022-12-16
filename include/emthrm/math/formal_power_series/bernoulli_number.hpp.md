---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
      \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/bernoulli_number.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D9\u30EB\u30CC\u30FC\
      \u30A4\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/formal_power_series/formal_power_series.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_BERNOULLI_NUMBER_HPP_\n#define EMTHRM_MATH_FORMAL_POWER_SERIES_BERNOULLI_NUMBER_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> bernoulli_number(const\
    \ int n) {\n  FormalPowerSeries<T> bernoulli(n);\n  bernoulli[0] = 1;\n  for (int\
    \ i = 1; i <= n; ++i) {\n    bernoulli[i] = bernoulli[i - 1] / (i + 1);\n  }\n\
    \  bernoulli = bernoulli.inv(n);\n  T fact = 1;\n  for (int i = 0; i <= n; ++i)\
    \ {\n    bernoulli[i] *= fact;\n    fact *= i + 1;\n  }\n  return bernoulli.coef;\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_BERNOULLI_NUMBER_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/bernoulli_number.hpp
  requiredBy:
  - include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/bernoulli_number.test.cpp
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
documentation_of: include/emthrm/math/formal_power_series/bernoulli_number.hpp
layout: document
title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
---

$$
  \dfrac{x}{e^x - 1} = \sum_{n = 0}^{\infty} B_n \frac{x^n}{n!}
$$

で定義される $B_n$ である．

$$
  \begin{cases}
    B_0 = 1, \\
    B_n = -\dfrac{1}{n + 1} \sum_{k = 0}^{n - 1} \binom{n + 1}{k} B_k
  \end{cases}
$$

という漸化式をもつ．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`bernoulli_number<T>(n)`|ベルヌーイ数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考

- https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0


## Verified

https://judge.yosupo.jp/submission/3792
