---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fft.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/convolution/mod_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\
      \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: test/math/fps/faulhaber_with_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  - icon: ':x:'
    path: test/math/fps/fps.5.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (mod_pow(exponend, md))"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/convolution/ntt.md
    document_title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\
      \u307F"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/mod_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\
    \u8FBC\u307F\r\n * @docs docs/math/convolution/ntt.md\r\n */\r\n\r\n#pragma once\r\
    \n#include <vector>\r\n#include \"../modint.hpp\"\r\n#include \"fft.hpp\"\r\n\r\
    \ntemplate <int T>\r\nstd::vector<MInt<T>> mod_convolution(const std::vector<MInt<T>>\
    \ &a, const std::vector<MInt<T>> &b, const int pre = 15) {\r\n  using ModInt =\
    \ MInt<T>;\r\n  int a_sz = a.size(), b_sz = b.size(), sz = a_sz + b_sz - 1, lg\
    \ = 1;\r\n  while ((1 << lg) < sz) ++lg;\r\n  int n = 1 << lg;\r\n  std::vector<fft::Complex>\
    \ A(n), B(n);\r\n  for (int i = 0; i < a_sz; ++i) {\r\n    int ai = a[i].val;\r\
    \n    A[i] = fft::Complex(ai & ((1 << pre) - 1), ai >> pre);\r\n  }\r\n  for (int\
    \ i = 0; i < b_sz; ++i) {\r\n    int bi = b[i].val;\r\n    B[i] = fft::Complex(bi\
    \ & ((1 << pre) - 1), bi >> pre);\r\n  }\r\n  fft::sub_dft(A);\r\n  fft::sub_dft(B);\r\
    \n  int half = n >> 1;\r\n  fft::Complex tmp_a = A[0], tmp_b = B[0];\r\n  A[0]\
    \ = {tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im};\r\n  B[0] = {tmp_a.re * tmp_b.im\
    \ + tmp_a.im * tmp_b.re, 0};\r\n  for (int i = 1; i < half; ++i) {\r\n    int\
    \ j = n - i;\r\n    fft::Complex a_l_i = (A[i] + A[j].conj()).mul_real(0.5), a_h_i\
    \ = (A[j].conj() - A[i]).mul_pin(0.5);\r\n    fft::Complex b_l_i = (B[i] + B[j].conj()).mul_real(0.5),\
    \ b_h_i = (B[j].conj() - B[i]).mul_pin(0.5);\r\n    fft::Complex a_l_j = (A[j]\
    \ + A[i].conj()).mul_real(0.5), a_h_j = (A[i].conj() - A[j]).mul_pin(0.5);\r\n\
    \    fft::Complex b_l_j = (B[j] + B[i].conj()).mul_real(0.5), b_h_j = (B[i].conj()\
    \ - B[j]).mul_pin(0.5);\r\n    A[i] = a_l_i * b_l_i + (a_h_i * b_h_i).mul_pin(1);\r\
    \n    B[i] = a_l_i * b_h_i + a_h_i * b_l_i;\r\n    A[j] = a_l_j * b_l_j + (a_h_j\
    \ * b_h_j).mul_pin(1);\r\n    B[j] = a_l_j * b_h_j + a_h_j * b_l_j;\r\n  }\r\n\
    \  tmp_a = A[half]; tmp_b = B[half];\r\n  A[half] = {tmp_a.re * tmp_b.re, tmp_a.im\
    \ * tmp_b.im};\r\n  B[half] = {tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0};\r\
    \n  fft::idft(A);\r\n  fft::idft(B);\r\n  std::vector<ModInt> res(sz);\r\n  ModInt\
    \ tmp1 = 1 << pre, tmp2 = 1LL << (pre << 1);\r\n  for (int i = 0; i < sz; ++i)\
    \ {\r\n    res[i] += static_cast<long long>(A[i].re + 0.5);\r\n    res[i] += tmp1\
    \ * static_cast<long long>(B[i].re + 0.5);\r\n    res[i] += tmp2 * static_cast<long\
    \ long>(A[i].im + 0.5);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/convolution/fft.hpp
  isVerificationFile: false
  path: math/convolution/mod_convolution.hpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/fps/fps.5.test.cpp
  - test/math/fps/faulhaber_with_fps.test.cpp
  - test/math/convolution/mod_convolution.test.cpp
documentation_of: math/convolution/mod_convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/mod_convolution.hpp
- /library/math/convolution/mod_convolution.hpp.html
title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
---
# 数論変換 (number theoretic transform) / 高速剰余変換 (fast modulo transform)

$n$ の逆元と位数 $n$ の元が存在する剰余環 $\mathbb{Z} / m \mathbb{Z}$ 上で離散フーリエ変換を高速に行うアルゴリズムである．

特に $2^x \geq n$ を満たす $x, k \in \mathbb{N}$ を用いて表される素数 $p = 2^x k + 1$ は，$p$ の原始根 $\omega$ について

$$\omega^{p - 1} \equiv 1 \pmod{p}$$

すなわち

$$(\omega^k)^{2^x} \equiv 1 \pmod{p}$$

が成り立つので，条件を満たす．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`NTT<T>()`|数論変換を考える．||
|`sub_dft(a)`|$A$ に対して数論変換を行う．||
|`dft(a)`|整数列 $A$ に対して数論変換を行ったもの||
|`idft(a)`|$A$ に対して数論変換の逆変換を行う||
|`convolution(a, b)`|整数列 $A$ と $B$ の畳み込み|$\max_i{C_i} \leq (\max_i{A_i})(\max_i{B_i})(\min \lbrace \lvert A \rvert, \lvert B \rvert \rbrace)$|

- 任意の法の下での畳み込み

||説明|備考|
|:--:|:--:|:--:|
|`mod_convolution(a, b, 精度 = 15)`|$A$ と $B$ の畳み込み|$\text{精度} \geq \log \sqrt{m}$ でなければならない．|

e.g. $\text{精度} = 15$ のとき $m \leq 2^{30} = 1073741824$．


## 参考

- https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html
- https://lumakernel.github.io/ecasdqina/math/FFT/NTT
- http://xn--w6q13e505b.jp/method/fft/modular.html
- http://www.cs.t-kougei.ac.jp/nsim/method/fmtbase.htm

任意の法の下での畳み込み
- https://min-25.hatenablog.com/entry/2017/09/23/085053
- https://ei1333.github.io/luzhiled/snippets/math/arbitrary-mod-convolution.html


## ToDo

- 数論変換を用いた任意の法の下での畳み込み
  - https://math314.hateblo.jp/entry/2015/05/07/014908
  - https://naoyat.hatenablog.jp/entry/DFT-and-NTT
  - https://ei1333.github.io/algorithm/fft.html
  - https://lumakernel.github.io/ecasdqina/math/FFT/NTT
  - https://github.com/spaghetti-source/algorithm/blob/master/math/fast_modulo_transform.cc
  - https://satanic0258.github.io/snippets/math/NTT.html
  - https://judge.yosupo.jp/problem/convolution_mod_1000000007


## Verified

- [数論変換](https://judge.yosupo.jp/submission/3591)
- [任意の法の下での畳み込み](https://atcoder.jp/contests/atc001/submissions/9314050)
