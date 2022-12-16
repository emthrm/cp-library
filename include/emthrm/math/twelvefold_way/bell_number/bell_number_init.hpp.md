---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570\
      \u306E\u6570\u8868"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/bell_number/bell_number.md
    document_title: "\u30D9\u30EB\u6570\u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp: line 11:\
    \ unable to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u30D9\u30EB\u6570\u306E\u6570\u8868\n * @docs docs/math/twelvefold_way/bell_number/bell_number.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_\n\
    #define EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_\n\n#include\
    \ <vector>\n\n#include \"emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> bell_number_init(const\
    \ int n, const int k) {\n  std::vector<std::vector<T>> b(n + 1, std::vector<T>(k\
    \ + 1));\n  const std::vector<std::vector<T>> s =\n      stirling_number_of_the_second_kind_init<T>(n,\
    \ k);\n  for (int i = 0; i <= n; ++i) {\n    b[i].front() = s[i].front();\n  \
    \  for (int j = 1; j <= k; ++j) {\n      b[i][j] = b[i][j - 1] + s[i][j];\n  \
    \  }\n  }\n  return b;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_\n"
  dependsOn:
  - include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp
- /library/include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp.html
title: "\u30D9\u30EB\u6570\u306E\u6570\u8868"
---
# ベル数 (Bell number)

区別された $n$ 個を $k$ グループ以下に分割する場合の数を $B(n, k)$ とおくと

$$
  B(n,k) = \sum_{j = 0}^k S(n, j) = \sum_{i = 0}^k \frac{i^n}{i!} \sum_{j = 0}^{k - i} \frac{(-1)^j}{j!}
$$

が成り立つ．ここで $S$ は[第2種スターリング数](../stirling_number/stirling_number.md)である．

$n = k$ を満たす $B(n, k)$ をベル数 $B_n$ と呼ぶ．

漸化式は

$$
  B_{n + 1} = \sum_{k = 0}^n \binom{n}{k} B_k
$$

であり，指数型母関数は

$$
  \sum_{n = 0}^\infty B_n \frac{x^n}{n!} = e^{e^x - 1}
$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(\min \lbrace N, K \rbrace \log{N})$|
|数表|$O(NK)$|
|数表 $n = k$ 版|$O(N\log{N})$|


## 使用法

||説明|
|:--:|:--:|
|`bell_number<T>(n, k)`|$B(n, k)$|

- 数表

||説明|
|:--:|:--:|
|`bell_number_init<T>(n, k)`|$B(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|

- 数表 $n = k$ 版

||説明|
|:--:|:--:|
|`bell_number_init_by_fps<T>(n)`|ベル数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考

- https://qiita.com/drken/items/f2ea4b58b0d21621bd51
- https://ja.wikipedia.org/wiki/ベル数


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088882/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088892/emthrm/C++14)
- 数表 $n = k$ 版
