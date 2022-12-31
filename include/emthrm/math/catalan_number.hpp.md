---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/catalan_number.test.cpp
    title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_CATALAN_NUMBER_HPP_\n#define EMTHRM_MATH_CATALAN_NUMBER_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <int T>\nstd::vector<MInt<T>> catalan_number(const int n) {\n\
    \  using ModInt = MInt<T>;\n  ModInt::inv(n + 1, true);\n  std::vector<ModInt>\
    \ c(n + 1);\n  c[0] = 1;\n  for (int i = 0; i < n; ++i) {\n    c[i + 1] = c[i]\
    \ * ModInt::inv(i + 2) * 2 * (2 * i + 1);\n  }\n  return c;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MATH_CATALAN_NUMBER_HPP_\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/catalan_number.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/catalan_number.test.cpp
documentation_of: include/emthrm/math/catalan_number.hpp
layout: document
title: "\u30AB\u30BF\u30E9\u30F3\u6570 (Catalan number)"
---

$$
  c_n \mathrel{:=} \dfrac{\binom{2n}{n}}{n + 1} = \dbinom{2n}{n} - \dbinom{2n}{n - 1}
$$

で定義される $c$ である．

$$
  \begin{cases}
    c_0 = 1, \\
    c_{n + 1} = \sum_{i = 0}^n c_i c_{n - i}
  \end{cases}
$$

の特殊解である．

カタラン数 $c_n$ を適用できる例として以下がある．
- 長さ $2n$ の correct bracket sequence の場合の数
- $n \times n$ マスの格子で左下から右上まで対角線をまたがない最短経路の個数
- $n + 1$ 個の葉を持つ二分木の個数
- $n + 1$ 人によるトーナメントの総数
- 凸 $n + 2$ 角形の三角形分割の個数


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`catalan_number<T>(n)`|カタラン数 $c_i$ ($0 \leq i \leq n$) の数表|


## 参考

- https://mathtrain.jp/catalan
- https://noshi91.hatenablog.com/entry/2021/07/10/170943
- https://ei1333.hateblo.jp/entry/2021/12/10/175837
- https://drive.google.com/file/d/1WC7Y2Ni-8elttUgorfbix9tO1fvYN3g3/view


## Verified

https://yukicoder.me/submissions/414045
