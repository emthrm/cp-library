---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mod_log.test.cpp
    title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/mod_pow.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_MOD_LOG_HPP_\n#define EMTHRM_MATH_MOD_LOG_HPP_\n\n#include\
    \ <map>\n\n#include \"emthrm/math/mod_pow.hpp\"\n\nnamespace emthrm {\n\nint mod_log(long\
    \ long g, long long y, const int m) {\n  if (m == 1) return 0;\n  if ((g %= m)\
    \ < 0) g += m;\n  if ((y %= m) < 0) y += m;\n  if (g == 0) {\n    if (y == 1)\
    \ return 0;\n    if (y == 0) return 1;\n    return -1;\n  }\n  int root = 1;\n\
    \  while (root * root < m) ++root;\n  std::map<long long, int> baby;\n  long long\
    \ p = 1;\n  for (int i = 0; i < root; ++i) {\n    if (p == y) return i;\n    baby[p\
    \ * y % m] = i;\n    p = (p * g) % m;\n  }\n  long long brute_force = p;\n  for\
    \ (int i = root; i < 100; ++i) {\n    if (i == m) return -1;\n    if (brute_force\
    \ == y) return i;\n    brute_force = (brute_force * g) % m;\n  }\n  long long\
    \ giant = p;\n  for (int i = 1; i <= root; ++i) {\n    if (baby.count(giant) ==\
    \ 1) {\n      const int ans = static_cast<long long>(i) * root - baby[giant];\n\
    \      if (mod_pow(g, ans, m) == y) return ans;\n    }\n    giant = (giant * p)\
    \ % m;\n  }\n  return -1;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOD_LOG_HPP_\n"
  dependsOn:
  - include/emthrm/math/mod_pow.hpp
  isVerificationFile: false
  path: include/emthrm/math/mod_log.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mod_log.test.cpp
documentation_of: include/emthrm/math/mod_log.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
---

$g^x \equiv y \pmod{p}$ ($g = \text{const.},\ y \in \mathbb{Z},\ p \in \mathbb{P}$) を満たす $x$ を求める問題である。


## 時間計算量

$O(\sqrt{P} \log{P})$


## 仕様

### baby-step giant-step

|名前|戻り値|
|:--|:--|
|`int mod_log(long long g, long long y, const int m);`|$g^x \equiv y \pmod{m}$ を満たす最小の非負整数 $x$。ただし存在しないときは $-1$ を返す。|


## 参考文献

- http://sonickun.hatenablog.com/entry/2016/11/20/192743


## TODO

- Pohlig–Hellman algorithm
  - http://sonickun.hatenablog.com/entry/2016/11/20/192743
  - https://yukicoder.me/problems/no/950
  - https://twitter.com/nuo_chocorusk/status/1205509988912783360
  - https://twitter.com/maspy_stars/status/1205499459993362432


## Submissons

https://judge.yosupo.jp/submission/3457
