---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/chinese_remainder_theorem.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/mod_inv.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_CHINESE_REMAINDER_THEOREM_HPP_\n#define EMTHRM_MATH_CHINESE_REMAINDER_THEOREM_HPP_\n\
    \n#if __cplusplus >= 201703L\n#include <numeric>\n#else\n#include <algorithm>\n\
    #endif\n#include <utility>\n#include <vector>\n\n#include \"emthrm/math/mod_inv.hpp\"\
    \n\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::pair<T, T> chinese_remainder_theorem(std::vector<T>\
    \ b, std::vector<T> m) {\n  const int n = b.size();\n  T x = 0, md = 1;\n  for\
    \ (int i = 0; i < n; ++i) {\n    if ((b[i] %= m[i]) < 0) b[i] += m[i];\n    if\
    \ (md < m[i]) {\n      std::swap(x, b[i]);\n      std::swap(md, m[i]);\n    }\n\
    \    if (md % m[i] == 0) {\n      if (x % m[i] != b[i]) return {0, 0};\n     \
    \ continue;\n    }\n#if __cplusplus >= 201703L\n    const T g = std::gcd(md, m[i]);\n\
    #else\n    const T g = std::__gcd(md, m[i]);\n#endif\n    if ((b[i] - x) % g !=\
    \ 0) return {0, 0};\n    const T u_i = m[i] / g;\n    x += (b[i] - x) / g % u_i\
    \ * mod_inv(md / g, u_i) % u_i * md;\n    md *= u_i;\n    if (x < 0) x += md;\n\
    \  }\n  return {x, md};\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CHINESE_REMAINDER_THEOREM_HPP_\n"
  dependsOn:
  - include/emthrm/math/mod_inv.hpp
  isVerificationFile: false
  path: include/emthrm/math/chinese_remainder_theorem.hpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/chinese_remainder_theorem.test.cpp
documentation_of: include/emthrm/math/chinese_remainder_theorem.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
---

連立合同式 $x \equiv b_i \pmod{m_i}$ ($i = 1, 2,\ldots, n$) が与えられる。

任意の $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $m_i \perp m_j$ が成り立つならば、連立合同式を満たす $x \bmod{\prod_{i = 1}^n m_i}$ が一意に存在する。

これを任意の $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $b_i \equiv b_j \pmod{\gcd(m_i, m_j)}$ が成り立つときに拡張すると、連立合同式を満たす $x \bmod{\mathrm{lcm}(m_1, m_2,..., m_n)}$ が一意に存在する。


## 時間計算量

$O(N \log{\mathrm{lcm}(m_1, m_2, \ldots, m_N)})$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename T> std::pair<T, T> chinese_remainder_theorem(std::vector<T> b, std::vector<T> m);`|$x \equiv b_i \pmod{m_i}$ を満たす $x$ と $\mathrm{lcm}(m_1, m_2,..., m_n)$ の組。ただし存在しないときは $(0, 0)$ を返す。|$0 \leq x < \mathrm{lcm}(m_1, m_2,..., m_n)$|


## 参考文献

- https://rsk0315.hatenablog.com/entry/2021/01/18/065720#crt
- https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp#L33-L80
- https://qiita.com/drken/items/ae02240cd1f8edfc86fd
- https://mathtrain.jp/remainder


## TODO

- Garner のアルゴリズム
  - https://qiita.com/drken/items/ae02240cd1f8edfc86fd
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/garner.cpp
  - https://www.creativ.xyz/ect-gcd-crt-garner-927/
  - http://kirika-comp.hatenablog.com/entry/2017/12/18/143923
  - ~~http://sugarknri.hatenablog.com/entry/2018/06/28/144407~~
  - ~~https://lumakernel.github.io/ecasdqina/math/number-theory/Garner~~
  - https://mugen1337.github.io/procon/Math/Garner.cpp
  - https://sotanishy.github.io/cp-library-cpp/math/garner.cpp
  - https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
  - http://flex.phys.tohoku.ac.jp/~maru/implementations/garner.php


## Submissons

https://yukicoder.me/submissions/630411
