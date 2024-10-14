---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/exp_of_set_power_series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570 (set power series) \u306E\u6307\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/convolution/exp_of_set_power_series.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u96C6\u5408\u51AA\u7D1A\u6570\u306E\
      \u6307\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/convolution/subset_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/subset convolution"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/convolution/subset_convolution.hpp\"\
    \n\n\n\n#include <array>\n#include <bit>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T>\
    \ subset_convolution(\n    const std::vector<T>& f, const std::vector<T>& g) {\n\
    \  using Polynomial = std::array<T, MaxN + 1>;\n  assert(std::has_single_bit(f.size())\
    \ && f.size() == g.size());\n  const int n = std::countr_zero(f.size());\n  assert(n\
    \ <= MaxN);\n  const int domain_size = 1 << n;\n  const auto ranked_zeta_transform\
    \ =\n      [n, domain_size](const std::vector<T>& f) -> std::vector<Polynomial>\
    \ {\n    std::vector a(domain_size, Polynomial{});\n    for (int i = 0; i < domain_size;\
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
    \ int>(i))];\n  }\n  return c;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_SUBSET_CONVOLUTION_HPP_\n#define EMTHRM_MATH_CONVOLUTION_SUBSET_CONVOLUTION_HPP_\n\
    \n#include <array>\n#include <bit>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T>\
    \ subset_convolution(\n    const std::vector<T>& f, const std::vector<T>& g) {\n\
    \  using Polynomial = std::array<T, MaxN + 1>;\n  assert(std::has_single_bit(f.size())\
    \ && f.size() == g.size());\n  const int n = std::countr_zero(f.size());\n  assert(n\
    \ <= MaxN);\n  const int domain_size = 1 << n;\n  const auto ranked_zeta_transform\
    \ =\n      [n, domain_size](const std::vector<T>& f) -> std::vector<Polynomial>\
    \ {\n    std::vector a(domain_size, Polynomial{});\n    for (int i = 0; i < domain_size;\
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
    \ int>(i))];\n  }\n  return c;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_SUBSET_CONVOLUTION_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/convolution/subset_convolution.hpp
  requiredBy:
  - include/emthrm/math/convolution/exp_of_set_power_series.hpp
  timestamp: '2023-08-15 15:09:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/convolution/exp_of_set_power_series.test.cpp
  - test/math/convolution/subset_convolution.test.cpp
documentation_of: include/emthrm/math/convolution/subset_convolution.hpp
layout: document
title: subset convolution
---

環 $K$ を終域とする関数 $f, g \colon 2^{\lbrack n \rbrack} \to K$ が与えられるとする。$S \subseteq \lbrack n \rbrack$ すべてに対して
$$
  (f \ast g)(S) \mathrel{:=} \sum_{T \subseteq S} f(T) g(S \setminus T)
$$
を高速に求めるアルゴリズムである。


## 時間計算量

$O(2^N N^2)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <int MaxN, typename T>`<br>`std::vector<T> subset_convolution(const std::vector<T>& f, const std::vector<T>& g);`|$f \ast g$|$n \leq \mathrm{MaxN}$|


## 参考文献

- Andreas Björklund, Thore Husfeldt, Petteri Kaski, and Mikko Koivisto: Fourier meets möbius: fast subset convolution, *STOC '07: Proceedings of the thirty-ninth annual ACM symposium on Theory of computing*, pp. 67–74 (2007). https://doi.org/10.1145/1250790.1250801
- https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-1-%e9%83%a8%e5%88%86%e9%9b%86%e5%90%88%e7%95%b3%e3%81%bf%e8%be%bc%e3%81%bf
- https://www.slideshare.net/wata_orz/ss-12131479
- https://hos-lyric.hatenablog.com/entry/2021/01/14/201231
- https://37zigen.com/subset-convolution/
- https://nyaannyaan.github.io/library/set-function/subset-convolution.hpp.html


## Submissons

https://judge.yosupo.jp/submission/155785
