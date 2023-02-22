---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/convolution/kronecker_power-vector_multiplication.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\
      \u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/matrix/matrix.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_\n\
    #define EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_\n\n\
    #include <cassert>\n#include <cmath>\n#include <vector>\n\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> kronecker_power_vector_multiplication(const\
    \ Matrix<T>& g,\n                                                     std::vector<T>\
    \ v) {\n  const int d = g.nrow(), n = v.size();\n  assert(std::llround(std::pow(d,\
    \ std::log(n) / std::log(d))) == n);\n  Matrix<T> tmp(d, 1);\n  for (int block\
    \ = 1; block < n; block *= d) {\n    for (int i = 0; i < n; i += block * d) {\n\
    \      for (int j = 0; j < block; ++j) {\n        for (int x = 0; x < d; ++x)\
    \ {\n          tmp[x][0] = v[i + j + block * x];\n        }\n        tmp = g *\
    \ tmp;\n        for (int x = 0; x < d; ++x) {\n          v[i + j + block * x]\
    \ = tmp[x][0];\n        }\n      }\n    }\n  }\n  return v;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
  requiredBy: []
  timestamp: '2023-02-23 00:46:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/convolution/kronecker_power-vector_multiplication.test.cpp
documentation_of: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
layout: document
title: "\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\u51AA (Kronecker power) \u3068\u30D9\u30AF\
  \u30C8\u30EB\u306E\u7A4D"
---

$G \in K^{d \times d},\ \boldsymbol{v} \in K^{d^n}$ に対して $G^{\otimes n} \boldsymbol{v}$ を求める。ここで
$$
A \otimes B \mathrel{:=}
\begin{pmatrix}
  a_{11} B & \cdots & a_{1n} B \\
  \vdots   & \ddots & \vdots   \\
  a_{m1} B & \cdots & a_{mn} B
\end{pmatrix}
\quad (A \in K^{m \times n})
$$
はクロネッカー積である。


## 時間計算量

$O(N D^{N + 1})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> kronecker_power_vector_multiplication(const Matrix<T>& g, std::vector<T> v);`|$G^{\otimes n} \boldsymbol{v}$|


## 参考文献

- http://q.c.titech.ac.jp/docs/progs/kronecker.html
- https://suisen-cp.github.io/cp-library-cpp/library/transform/kronecker_power.hpp


## Submissons

https://atcoder.jp/contests/abc288/submissions/39117221
