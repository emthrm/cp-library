---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/fast_mobius_transform.hpp
    title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
  - icon: ':heavy_check_mark:'
    path: math/convolution/fast_zeta_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/convolution/convolution.md
    document_title: "\u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/or_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F\
    \n * @docs docs/math/convolution/convolution.md\n */\n\n#pragma once\n#include\
    \ <algorithm>\n#include <vector>\n\n#include \"./fast_mobius_transform.hpp\"\n\
    #include \"./fast_zeta_transform.hpp\"\n\ntemplate <typename T>\nstd::vector<T>\
    \ or_convolution(std::vector<T> a, std::vector<T> b,\n                       \
    \       const T id = 0) {\n  int n = std::max(a.size(), b.size());\n  a.resize(n,\
    \ id);\n  a = fast_zeta_transform(a, false, id);\n  b.resize(n, id);\n  b = fast_zeta_transform(b,\
    \ false, id);\n  n = a.size();\n  for (int i = 0; i < n; ++i) {\n    a[i] *= b[i];\n\
    \  }\n  return fast_mobius_transform(a, false);\n}\n"
  dependsOn:
  - math/convolution/fast_mobius_transform.hpp
  - math/convolution/fast_zeta_transform.hpp
  isVerificationFile: false
  path: math/convolution/or_convolution.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/or_convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/or_convolution.hpp
- /library/math/convolution/or_convolution.hpp.html
title: "\u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F"
---
- 添え字 and での畳み込み

  $$
    C_k = \sum_{k = i \land j} A_i B_j
  $$

- 添え字 or での畳み込み

  $$
    C_k = \sum_{k = i \lor j} A_i B_j
  $$

- 添え字 xor での畳み込み

  $$
    C_k = \sum_{k = i \oplus j} A_i B_j
  $$

- 添え字 gcd での畳み込み

  $$
    C_k = \sum_{k = \gcd(i, j)} A_i B_j
  $$

- 添え字 lcm での畳み込み

  $$
    C_k = \sum_{k = \mathrm{lcm}(i, j)} A_i B_j
  $$

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

- 添え字 lcm での畳み込み

||説明|
|:--:|:--:|
|`lcm_convolution(a, b, n = -1)`|$A, B$ に対する添え字 lcm での畳み込み|


## 参考

- https://leaf1415.hatenablog.com/entry/2021/08/04/125751
- https://codeforces.com/blog/entry/48417
- http://kazuma8128.hatenablog.com/entry/2018/05/31/144519
- https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform

高速ウォルシュ・アダマール変換
- https://sapphire15.hatenablog.com/entry/2021/09/13/114900
- https://cympfh.cc/aiura/hadamard-xor-convolution
- https://pctprobability.hatenadiary.com/entry/2022/01/10/185418
- https://twitter.com/maspy_stars/status/1350467886775603200

添え字 gcd での畳み込み
- https://noshi91.hatenablog.com/entry/2019/09/23/002445
- https://aprilganmo.hatenablog.com/entry/2020/07/24/190816

添え字 lcm での畳み込み
- https://aprilganmo.hatenablog.com/entry/2020/07/24/190816
- https://yukicoder.me/problems/no/1760


## ToDo

- https://noshi91.hatenablog.com/entry/2020/10/27/175112
- 添え字 gcd での畳み込みを $O(N\log{\log{N}})$ に高速化する．
  - http://noshi91.hatenablog.com/entry/2018/12/27/121649
  - https://github.com/drken1215/algorithm/blob/master/MathAlgebra/fast_gcd_convolution.cpp
- 添え字 xor での畳み込みにおける逆元
  - https://yukicoder.me/problems/no/1753/editorial
- subset convolution
  - https://github.com/yosupo06/library-checker-problems/issues/297
  - https://judge.yosupo.jp/problem/subset_convolution
  - https://twitter.com/noshi91/status/1315347967990140928
  - https://twitter.com/noshi91/status/1315504267927584768
  - ~~https://twitter.com/beet_aizu/status/1339049679728779264~~
  - https://twitter.com/noshi91/status/1339077655715430401
  - https://ngtkana.hatenablog.com/entry/2021/04/25/135636
  - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
  - https://hos-lyric.hatenablog.com/entry/2021/01/14/201231
  - https://twitter.com/heno_code/status/1342124587849400320
  - https://twitter.com/tpyneriver/status/1356095139035242497
  - https://twitter.com/gmm_tea/status/1355754279751938053
  - https://twitter.com/Ryuhei_Mori/status/1356074005447340035
  - https://twitter.com/noshi91/status/1356075579896811523
  - https://atcoder.jp/contests/abc213/tasks/abc213_g
  - https://twitter.com/tpyneriver/status/1425483346927177736
  - https://twitter.com/_su1sen/status/1425871066916790281
  - https://atcoder.jp/contests/abc213/submissions/24925408
  - https://atcoder.jp/contests/abc213/submissions/24953805
  - https://sotanishy.github.io/cp-library-cpp/convolution/subset_convolution.hpp
  - https://atcoder.jp/contests/abc236/tasks/abc236_h
  - https://twitter.com/noshi91/status/1485246655419260939
  - https://yukicoder.me/problems/no/1901
  - https://atcoder.jp/contests/abc253/editorial/4028
- 凸性のある畳み込み
  - https://twitter.com/hotmanww/status/1482185138125832192
- relaxed multiplication
  - https://hly1204.github.io/library/math/formal_power_series/relaxed_convolution.hpp
  - https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c
  - https://atcoder.jp/contests/abc230/tasks/abc230_h
  - https://atcoder.jp/contests/abc230/editorial/3036
  - https://twitter.com/noshi91/status/1466764432961585166


## Verified

- [添え字 and での畳み込み](https://judge.yosupo.jp/submission/32176)
- 添え字 or での畳み込み
- [添え字 xor での畳み込み](https://judge.yosupo.jp/submission/32459)
- [添え字 gcd での畳み込み](https://judge.yosupo.jp/submission/79257)
- [添え字 lcm での畳み込み](https://judge.yosupo.jp/submission/79261)
