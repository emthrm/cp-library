---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/convolution/gcd_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 gcd \u3067\u306E\
      \u7573\u307F\u8FBC\u307F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/convolution/convolution.md
    document_title: "\u6DFB\u3048\u5B57 gcd \u3067\u306E\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/gcd_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u6DFB\u3048\u5B57 gcd \u3067\u306E\u7573\u307F\u8FBC\u307F\
    \r\n * @docs docs/math/convolution/convolution.md\r\n */\r\n\r\n#pragma once\r\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T> gcd_convolution(const\
    \ std::vector<T> &a, const std::vector<T> &b) {\r\n  int n = a.size();\r\n  auto\
    \ zeta = [&](std::vector<T> v) -> std::vector<T> {\r\n    for (int i = 1; i <\
    \ n; ++i) {\r\n      for (int j = i << 1; j < n; j += i) v[i] += v[j];\r\n   \
    \ }\r\n    return v;\r\n  };\r\n  std::vector<T> zeta_a = zeta(a), zeta_b = zeta(b);\r\
    \n  for (int i = 1; i < n; ++i) zeta_a[i] *= zeta_b[i];\r\n  for (int i = n -\
    \ 1; i >= 1; --i) {\r\n    for (int j = i << 1; j < n; j += i) zeta_a[i] -= zeta_a[j];\r\
    \n  }\r\n  return zeta_a;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/convolution/gcd_convolution.test.cpp
documentation_of: math/convolution/gcd_convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/gcd_convolution.hpp
- /library/math/convolution/gcd_convolution.hpp.html
title: "\u6DFB\u3048\u5B57 gcd \u3067\u306E\u7573\u307F\u8FBC\u307F"
---
- 添え字 and での畳み込み

  $$C_k = \sum_{k = i \land j} A_i B_j \text{．}$$

- 添え字 or での畳み込み

  $$C_k = \sum_{k = i \lor j} A_i B_j \text{．}$$

- 添え字 xor での畳み込み

  $$C_k = \sum_{k = i \oplus j} A_i B_j \text{．}$$

- 添え字 gcd での畳み込み

  $$C_k = \sum_{k = \gcd(i, j)} A_i B_j \text{．}$$

添え字 xor での畳み込みには「高速ウォルシュ・アダマール変換 (fast Walsh-Hadamard transform)」を用いる．


## 時間計算量

$O(N\log{N})$


## 使用法

- 添え字 and での畳み込み

||説明|
|:--:|:--:|
|`and_convolution(a, b, 単位元 = 0)`|$A, B$ に対する添え字 and での畳み込み|

- 添え字 or での畳み込み

||説明|
|:--:|:--:|
|`or_convolution(a, b, 単位元 = 0)`|$A, B$ に対する添え字 or での畳み込み|

- 添え字 xor での畳み込み

||説明|
|:--:|:--:|
|`xor_convolution(a, b, 単位元 = 0)`|$A, B$ に対する添え字 xor での畳み込み|

- 添え字 gcd での畳み込み

||説明|
|:--:|:--:|
|`gcd_convolution(a, b)`|$A, B$ に対する添え字 gcd での畳み込み|


## 参考

- https://codeforces.com/blog/entry/48417
- https://aprilganmo.hatenablog.com/entry/2020/07/24/190816
- http://kazuma8128.hatenablog.com/entry/2018/05/31/144519
- https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform

添え字 gcd での畳み込み
  - https://noshi91.hatenablog.com/entry/2019/09/23/002445


## ToDo

- https://noshi91.hatenablog.com/entry/2020/10/27/175112
- 添え字 gcd での畳み込みを $O(N\log{\log{N}})$ に高速化する．
  - http://noshi91.hatenablog.com/entry/2018/12/27/121649
  - https://github.com/drken1215/algorithm/blob/master/MathAlgebra/fast_gcd_convolution.cpp
- subset convolution
  - https://github.com/yosupo06/library-checker-problems/issues/297
  - https://judge.yosupo.jp/problem/subset_convolution
  - https://twitter.com/noshi91/status/1315347967990140928
  - https://twitter.com/noshi91/status/1315504267927584768
  - https://twitter.com/beet_aizu/status/1339049679728779264
  - https://twitter.com/noshi91/status/1339077655715430401
  - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
  - https://twitter.com/heno_code/status/1342124587849400320
  - https://twitter.com/tpyneriver/status/1356095139035242497
  - https://twitter.com/gmm_tea/status/1355754279751938053
  - https://twitter.com/Ryuhei_Mori/status/1356074005447340035
  - https://twitter.com/noshi91/status/1356075579896811523


## Verified

- [添え字 and での畳み込み](https://judge.yosupo.jp/submission/32176)
- 添え字 or での畳み込み
- [添え字 xor での畳み込み](https://judge.yosupo.jp/submission/32459)
- [添え字 gcd での畳み込み](https://atcoder.jp/contests/agc038/submissions/9311349)
