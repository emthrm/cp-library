---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/subset_convolution.hpp
    title: subset convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/convolution/exp_of_set_power_series.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u96C6\u5408\u51AA\u7D1A\u6570\u306E\
      \u6307\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/convolution/exp_of_set_power_series.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/math/convolution/subset_convolution.hpp\"\
    \n\n\n\n#include <array>\n#line 7 \"include/emthrm/math/convolution/subset_convolution.hpp\"\
    \n#include <utility>\n#line 9 \"include/emthrm/math/convolution/subset_convolution.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T> subset_convolution(\n\
    \    const std::vector<T>& f, const std::vector<T>& g) {\n  using Polynomial =\
    \ std::array<T, MaxN + 1>;\n  assert(std::has_single_bit(f.size()) && f.size()\
    \ == g.size());\n  const int n = std::countr_zero(f.size());\n  assert(n <= MaxN);\n\
    \  const int domain_size = 1 << n;\n  const auto ranked_zeta_transform =\n   \
    \   [n, domain_size](const std::vector<T>& f) -> std::vector<Polynomial> {\n \
    \   std::vector a(domain_size, Polynomial{});\n    for (int i = 0; i < domain_size;\
    \ ++i) {\n      a[i][std::popcount(static_cast<unsigned int>(i))] = f[i];\n  \
    \  }\n    for (int bit = 1; bit < domain_size; bit <<= 1) {\n      for (int i\
    \ = 0; i < domain_size; ++i) {\n        if ((i & bit) == 0) {\n          for (int\
    \ degree = 0; degree <= n; ++degree) {\n            a[i | bit][degree] += a[i][degree];\n\
    \          }\n        }\n      }\n    }\n    return a;\n  };\n  std::vector<Polynomial>\
    \ a = ranked_zeta_transform(f);\n  const std::vector<Polynomial> b = ranked_zeta_transform(g);\n\
    \  for (int i = 0; i < domain_size; ++i) {\n    // Hadamard product\n    for (int\
    \ degree_of_a = n; degree_of_a >= 0; --degree_of_a) {\n      const T tmp = std::exchange(a[i][degree_of_a],\
    \ T{});\n      for (int degree_of_b = 0; degree_of_a + degree_of_b <= n; ++degree_of_b)\
    \ {\n        a[i][degree_of_a + degree_of_b] += tmp * b[i][degree_of_b];\n   \
    \   }\n    }\n  }\n  for (int bit = 1; bit < domain_size; bit <<= 1) {\n    for\
    \ (int i = 0; i < domain_size; ++i) {\n      if ((i & bit) == 0) {\n        for\
    \ (int degree = 0; degree <= n; ++degree) {\n          a[i | bit][degree] -= a[i][degree];\n\
    \        }\n      }\n    }\n  }\n  std::vector<T> c(domain_size);\n  for (int\
    \ i = 0; i < domain_size; ++i) {\n    c[i] = a[i][std::popcount(static_cast<unsigned\
    \ int>(i))];\n  }\n  return c;\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"include/emthrm/math/convolution/exp_of_set_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T> exp_of_set_power_series(const\
    \ std::vector<T>& f) {\n  assert(std::has_single_bit(f.size()) && f[0] == 0);\n\
    \  const int n = std::countr_zero(f.size());\n  assert(n <= MaxN);\n  std::vector<T>\
    \ exponential{1};\n  exponential.reserve(1 << n);\n  for (int i = 0; i < n; ++i)\
    \ {\n    std::ranges::copy(subset_convolution<MaxN>(\n                       \
    \   exponential,\n                          std::vector(std::next(f.begin(), 1\
    \ << i),\n                                      std::next(f.begin(), 1 << (i +\
    \ 1)))),\n                      std::back_inserter(exponential));\n  }\n  return\
    \ exponential;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_EXP_OF_SET_POWER_SERIES_HPP_\n#define EMTHRM_MATH_CONVOLUTION_EXP_OF_SET_POWER_SERIES_HPP_\n\
    \n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #include <vector>\n\n#include \"emthrm/math/convolution/subset_convolution.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T> exp_of_set_power_series(const\
    \ std::vector<T>& f) {\n  assert(std::has_single_bit(f.size()) && f[0] == 0);\n\
    \  const int n = std::countr_zero(f.size());\n  assert(n <= MaxN);\n  std::vector<T>\
    \ exponential{1};\n  exponential.reserve(1 << n);\n  for (int i = 0; i < n; ++i)\
    \ {\n    std::ranges::copy(subset_convolution<MaxN>(\n                       \
    \   exponential,\n                          std::vector(std::next(f.begin(), 1\
    \ << i),\n                                      std::next(f.begin(), 1 << (i +\
    \ 1)))),\n                      std::back_inserter(exponential));\n  }\n  return\
    \ exponential;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_EXP_OF_SET_POWER_SERIES_HPP_\n"
  dependsOn:
  - include/emthrm/math/convolution/subset_convolution.hpp
  isVerificationFile: false
  path: include/emthrm/math/convolution/exp_of_set_power_series.hpp
  requiredBy: []
  timestamp: '2023-08-15 15:09:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/convolution/exp_of_set_power_series.test.cpp
documentation_of: include/emthrm/math/convolution/exp_of_set_power_series.hpp
layout: document
title: "\u96C6\u5408\u51AA\u7D1A\u6570 (set power series) \u306E\u6307\u6570"
---

[集合冪級数](./subset_convolution.md) $(\lbrace f \in 2^{\lbrack n \rbrack} \to K \rbrace, +, \ast)$ を考える。$f(\emptyset) = 0$ を満たす $f \in 2^{\lbrack n \rbrack} \to K$ に対して

$$
  \exp{f} \mathrel{:=} \sum_{k = 0}^\infty \frac{f^k}{k!}
$$

で定義される $\exp$ である。


## 時間計算量

$O(2^N N^2)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <int MaxN, typename T>`<br>`std::vector<T> exp_of_set_power_series(const std::vector<T>& f);`|$\exp{f}$|$n \leq \mathrm{MaxN}$<br>$f(\emptyset) = 0$|


## 参考文献

- https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318
- https://nyaannyaan.github.io/library/set-function/exp-of-set-power-series.hpp


## TODO

- 集合冪級数
  - https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0
  - 多項式との合成
    - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90
    - https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318
    - https://nyaannyaan.github.io/library/set-function/polynomial-composite-set-power-series.hpp
    - https://judge.yosupo.jp/problem/polynomial_composite_set_power_series
    - https://judge.yosupo.jp/problem/power_projection_of_set_power_series
    - 問題例 "[We Love Forest](https://atcoder.jp/contests/abc253/tasks/abc253_h)"
      - https://atcoder.jp/contests/abc253/editorial/4028
  - 対数
    - 問題例 "[Lights Out on Connected Graph](https://atcoder.jp/contests/arc105/tasks/arc105_f)"
      - https://twitter.com/noshi91/status/1315347967990140928
      - https://twitter.com/noshi91/status/1315504267927584768
      - https://twitter.com/noshi91/status/1339077655715430401
      - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b#toc3
      - https://nyaannyaan.github.io/library/set-function/subset-convolution.hpp.html
    - 問題例 "[Connectivity 2](https://atcoder.jp/contests/abc213/tasks/abc213_g)"
      - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b#toc2
      - https://atcoder.jp/contests/abc213/submissions/24925408
    - 問題例 "[Electric Circuit](https://atcoder.jp/contests/abc321/tasks/abc321_g)"
      - https://atcoder.jp/contests/abc321/tasks/abc321_g
  - 累乗
    - https://twitter.com/_su1sen/status/1425871066916790281
    - 問題例 "[K-Coloring](https://atcoder.jp/contests/abc294/tasks/abc294_h)"
      - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b#toc5
      - https://twitter.com/noshi91/status/1637451650402234373
  - 平方根
    - 問題例 "[Hierarchical Phylogeny](https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h)"
      - https://hos-lyric.hatenablog.com/entry/2021/01/14/201231
      - https://twitter.com/heno_code/status/1342124587849400320
      - https://twitter.com/tpyneriver/status/1356095139035242497
  - 高速化
    - https://37zigen.com/subset-convolution/#i-2
    - https://twitter.com/tpyneriver/status/1425483346927177736


## Submissons

https://judge.yosupo.jp/problem/exp_of_set_power_series
