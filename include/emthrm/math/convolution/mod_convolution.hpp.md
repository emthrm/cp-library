---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/convolution/mod_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\
      \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/formal_power_series.5.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (mod_pow(exponend, md))"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/convolution/number_theoretic_transform.md
    document_title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\
      \u307F"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/convolution/mod_convolution.hpp: line 14: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\
    \u8FBC\u307F\n * @docs docs/math/convolution/number_theoretic_transform.md\n */\n\
    \n#ifndef EMTHRM_MATH_CONVOLUTION_MOD_CONVOLUTION_HPP_\n#define EMTHRM_MATH_CONVOLUTION_MOD_CONVOLUTION_HPP_\n\
    \n#include <algorithm>\n#include <bit>\n#include <cmath>\n#include <vector>\n\n\
    #include \"emthrm/math/convolution/fast_fourier_transform.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int PRECISION = 15, int T>\nstd::vector<MInt<T>>\
    \ mod_convolution(const std::vector<MInt<T>>& a,\n                           \
    \          const std::vector<MInt<T>>& b) {\n  using ModInt = MInt<T>;\n  const\
    \ int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;\n  const\
    \ int n = std::max(std::bit_ceil(static_cast<unsigned int>(c_size)), 2U);\n  constexpr\
    \ int mask = (1 << PRECISION) - 1;\n  std::vector<fast_fourier_transform::Complex>\
    \ x(n), y(n);\n  std::transform(\n      a.begin(), a.end(), x.begin(),\n     \
    \ [mask](const MInt<T>& x) -> fast_fourier_transform::Complex {\n        return\
    \ fast_fourier_transform::Complex(x.v & mask, x.v >> PRECISION);\n      });\n\
    \  fast_fourier_transform::dft(&x);\n  std::transform(\n      b.begin(), b.end(),\
    \ y.begin(),\n      [mask](const MInt<T>& y) -> fast_fourier_transform::Complex\
    \ {\n        return fast_fourier_transform::Complex(y.v & mask, y.v >> PRECISION);\n\
    \      });\n  fast_fourier_transform::dft(&y);\n  const int half = n >> 1;\n \
    \ fast_fourier_transform::Complex tmp_a = x.front(), tmp_b = y.front();\n  x.front()\
    \ =\n      fast_fourier_transform::Complex(tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im);\n\
    \  y.front() =\n      fast_fourier_transform::Complex(\n          tmp_a.re * tmp_b.im\
    \ + tmp_a.im * tmp_b.re, 0);\n  for (int i = 1; i < half; ++i) {\n    const int\
    \ j = n - i;\n    const fast_fourier_transform::Complex a_l_i =\n        (x[i]\
    \ + x[j].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex a_h_i\
    \ =\n        (x[j].conj() - x[i]).mul_pin(0.5);\n    const fast_fourier_transform::Complex\
    \ b_l_i =\n        (y[i] + y[j].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex\
    \ b_h_i =\n        (y[j].conj() - y[i]).mul_pin(0.5);\n    const fast_fourier_transform::Complex\
    \ a_l_j =\n        (x[j] + x[i].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex\
    \ a_h_j =\n        (x[i].conj() - x[j]).mul_pin(0.5);\n    const fast_fourier_transform::Complex\
    \ b_l_j =\n        (y[j] + y[i].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex\
    \ b_h_j =\n        (y[i].conj() - y[j]).mul_pin(0.5);\n    x[i] = a_l_i * b_l_i\
    \ + (a_h_i * b_h_i).mul_pin(1);\n    y[i] = a_l_i * b_h_i + a_h_i * b_l_i;\n \
    \   x[j] = a_l_j * b_l_j + (a_h_j * b_h_j).mul_pin(1);\n    y[j] = a_l_j * b_h_j\
    \ + a_h_j * b_l_j;\n  }\n  tmp_a = x[half];\n  tmp_b = y[half];\n  x[half] = fast_fourier_transform::Complex(\n\
    \      tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im);\n  y[half] = fast_fourier_transform::Complex(\n\
    \      tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0);\n  fast_fourier_transform::idft(&x);\n\
    \  fast_fourier_transform::idft(&y);\n  std::vector<ModInt> res(c_size);\n  const\
    \ ModInt tmp1 = 1 << PRECISION, tmp2 = 1LL << (PRECISION << 1);\n  for (int i\
    \ = 0; i < c_size; ++i) {\n    res[i] = tmp1 * std::llround(y[i].re) + tmp2 *\
    \ std::llround(x[i].im)\n             + std::llround(x[i].re);\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_MOD_CONVOLUTION_HPP_\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_fourier_transform.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/convolution/mod_convolution.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/convolution/mod_convolution.test.cpp
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
  - test/math/formal_power_series/formal_power_series.5.test.cpp
documentation_of: include/emthrm/math/convolution/mod_convolution.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/convolution/mod_convolution.hpp
- /library/include/emthrm/math/convolution/mod_convolution.hpp.html
title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
---
# 数論変換 (number theoretic transform) / 高速剰余変換 (fast modulo transform)

剰余環 $\mathbb{Z} / m\mathbb{Z}$ 上で離散フーリエ変換を高速に行うアルゴリズムである。

特に $2^x \geq n$ を満たす $x, k \in \mathbb{N}$ を用いて表される素数 $p = 2^x k + 1$ は、$p$ の原始根 $\omega$ に対して

$$
  \omega^{p - 1} \equiv 1 \pmod{p}
$$

すなわち

$$
  (\omega^k)^{2^x} \equiv 1 \pmod{p}
$$

が成り立つので、条件を満たす。


## 時間計算量

$O(N\log{N})$


## 仕様

```cpp
template <int T>
struct NumberTheoreticTransform;
```

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`NumberTheoreticTransform();`|コンストラクタ||
|`template <typename U>`<br>`std::vector<ModInt> dft(const std::vector<U>& a);`|整数列 $A$ に対して数論変換を行ったもの||
|`void idft(std::vector<ModInt>* a);`|$A$ に対して数論変換の逆変換を行う。||
|`template <typename U>`<br>`std::vector<ModInt> convolution(const std::vector<U>& a, const std::vector<U>& b);`|整数列 $A$ と $B$ の畳み込み|$\max_i{C_i} \leq (\max_i{A_i})(\max_i{B_i})(\min \lbrace \lvert A \rvert, \lvert B \rvert \rbrace)$|

#### メンバ型

|名前|説明|
|:--|:--|
|`ModInt`|`MInt<T>`|


### 任意の法の下での畳み込み

|名前|戻り値|要件|備考|
|:--|:--|:--|:--|
|`template <int PRECISION = 15, int T>`<br>`std::vector<MInt<T>> mod_convolution(const std::vector<MInt<T>>& a, const std::vector<MInt<T>>& b);`|$A$ と $B$ の畳み込み|$(\text{精度}) \geq \log_2{\sqrt{m}}$ でなければならない。|`PRECISION` は精度を表す。|

e.g. $(\text{精度}) = 15$ のとき $m \leq 2^{30} = 1073741824$


## 参考文献

- https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html
- ~~https://lumakernel.github.io/ecasdqina/math/FFT/NumberTheoreticTransform~~
- http://xn--w6q13e505b.jp/method/fft/modular.html
- http://www.cs.t-kougei.ac.jp/nsim/method/fmtbase.htm

任意の法の下での畳み込み
- ~~https://min-25.hatenablog.com/entry/2017/09/23/085053~~
- https://ei1333.github.io/luzhiled/snippets/math/arbitrary-mod-convolution.html
- https://sotanishy.github.io/cp-library-cpp/convolution/arbitrary_mod_convolution.hpp


## TODO

- 数論変換を用いた任意の法の下での畳み込み
  - https://math314.hateblo.jp/entry/2015/05/07/014908
  - https://naoyat.hatenablog.jp/entry/DFT-and-NTT
  - https://ei1333.github.io/algorithm/fft.html
  - ~~https://lumakernel.github.io/ecasdqina/math/FFT/NumberTheoreticTransform~~
  - https://github.com/spaghetti-source/algorithm/blob/master/math/fast_modulo_transform.cc
  - https://satanic0258.github.io/snippets/math/NTT.html
  - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  - https://github.com/yosupo06/library-checker-problems/issues/664
  - https://judge.yosupo.jp/problem/convolution_mod_2_64
  - https://judge.yosupo.jp/problem/convolution_mod_large
  - https://judge.yosupo.jp/problem/mul_mod2n_convolution
  - https://github.com/yosupo06/library-checker-problems/issues/728


## Submissons

- [数論変換](https://judge.yosupo.jp/submission/3591)
- [任意の法の下での畳み込み](https://atcoder.jp/contests/atc001/submissions/25084524)
