---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/lucas.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406"
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
  code: "#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_LUCAS_HPP_\n#define EMTHRM_MATH_TWELVEFOLD_WAY_LUCAS_HPP_\n\
    \n#include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\ntemplate <int P>\n\
    MInt<P> lucas(int n, int k) {\n  using ModInt = MInt<P>;\n  if (n < 0 || n < k\
    \ || k < 0) return 0;\n  ModInt::init(P - 1);\n  ModInt binom = 1;\n  for (; n\
    \ > 0 || k > 0; n /= P, k /= P) {\n    binom *= ModInt::nCk(n % P, k % P);\n \
    \ }\n  return binom;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_LUCAS_HPP_\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/lucas.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/lucas.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/lucas.hpp
layout: document
title: "Lucas \u306E\u5B9A\u7406 (Lucas's theorem)"
---

$p \in \mathbb{P},\ n, k \in \mathrm{N}$ に対して，

$$
  \binom{n}{k} \equiv \prod_{i \in \mathbb{N}} \binom{\left\lfloor \frac{n}{p^i} \right\rfloor \bmod{p}}{\left\lfloor \frac{k}{p^i} \right\rfloor \bmod{p}} \pmod{p}
$$

が成り立つ．


## 時間計算量

$O(P + \log_P{N})$


## 使用法

||説明|
|:--:|:--:|
|`lucas<P>(n, k)`|$\binom{n}{k} \bmod{p}$|


## 参考

- https://manabitimes.jp/math/1324


## Verified

https://atcoder.jp/contests/arc117/submissions/21896797
