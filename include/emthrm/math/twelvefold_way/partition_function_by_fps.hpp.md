---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/partition_function_by_fps.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570 $n = m$ \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/partition_function.md
    document_title: "\u5206\u5272\u6570 $n = m$ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/twelvefold_way/partition_function_by_fps.hpp: line 11: unable\
    \ to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u5206\u5272\u6570 $n = m$ \u7248\n * @docs docs/math/twelvefold_way/partition_function.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_PARTITION_FUNCTION_BY_FPS_HPP_\n#define\
    \ EMTHRM_MATH_TWELVEFOLD_WAY_PARTITION_FUNCTION_BY_FPS_HPP_\n\n#include <vector>\n\
    \n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nstd::vector<T> partition_function_by_fps(const\
    \ int n) {\n  FormalPowerSeries<T> fps(n);\n  fps[0] = 1;\n  for (int i = 1; i\
    \ <= n; ++i) {\n    int idx = (3 * i - 1) * i / 2;\n    if (idx > n) break;\n\
    \    fps[idx] = (i & 1 ? -1 : 1);\n    idx = (3 * i + 1) * i / 2;\n    if (idx\
    \ <= n) fps[idx] = (i & 1 ? -1 : 1);\n  }\n  return fps.inv(n).coef;\n}\n\n} \
    \ // namespace emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_PARTITION_FUNCTION_BY_FPS_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/partition_function_by_fps.hpp
  requiredBy: []
  timestamp: '2023-01-16 17:06:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/partition_function_by_fps.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/partition_function_by_fps.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/twelvefold_way/partition_function_by_fps.hpp
- /library/include/emthrm/math/twelvefold_way/partition_function_by_fps.hpp.html
title: "\u5206\u5272\u6570 $n = m$ \u7248"
---
# 分割数 (partition function)

自然数 $n$ を $m$ 個以下の正の整数の和で表す方法の総数の内、$n = m$ を満たすもの。

和の順序は問わず、$2 + 1 + 1$ と $1 + 2 + 1$ を区別しない。

分割数 $p(n)$ の母関数は

$$
  \sum_{n = 0}^\infty p(n) x^n = \prod_{n = 1}^{\infty} \dfrac{1}{1 - x^n}
$$

である。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(NM)$|
|$n = m$ 版|$O(N\log{N})$|


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T> std::vector<std::vector<T>> partition_function(const int n, const int m);`|分割数の数表|


### $n = m$ 版

|名前|戻り値|
|:--|:--|
|`template <typename T> std::vector<T> partition_function_by_fps(const int n);`|$n = m$ のときの分割数の数表|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.66-67，マイナビ出版（2012）
- https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%E4%BA%94%E8%A7%92%E6%95%B0%E5%AE%9A%E7%90%86


## TODO

- オイラーの五角数定理 (Euler's pentagonal number theorem)
  - https://en.wikipedia.org/wiki/Pentagonal_number_theorem
  - https://atcoder.jp/contests/abc279/tasks/abc279_h
- $O(N\sqrt{N})$ で求める。
  - http://degwer.hatenablog.com/entries/2017/08/29
  - https://qiita.com/drken/items/f2ea4b58b0d21621bd51
  - https://judge.yosupo.jp/problem/partition_function


## Submissons

- https://yukicoder.me/submissions/701499
- [$n = m$ 版](https://judge.yosupo.jp/submission/3791)
