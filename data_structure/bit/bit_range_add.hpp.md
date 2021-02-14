---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/bit/bit_range_add.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/BIT/binary indexed tree \u533A\u9593\u52A0\
      \u7B97\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.1.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/bit/bit.md
    document_title: "binary indexed tree \u533A\u9593\u52A0\u7B97\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/bit/bit_range_add.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief binary indexed tree \u533A\u9593\u52A0\u7B97\u7248\r\n *\
    \ @docs docs/data_structure/bit/bit.md\r\n */\r\n\r\n#pragma once\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename Abelian>\r\nstruct BITRangeAdd {\r\n  BITRangeAdd(int\
    \ n_, const Abelian ID = 0) : n(n_), ID(ID) {\r\n    ++n;\r\n    dat_const.assign(n,\
    \ ID);\r\n    dat_linear.assign(n, ID);\r\n  }\r\n\r\n  void add(int left, int\
    \ right, Abelian val) {\r\n    if (right < ++left) return;\r\n    for (int i =\
    \ left; i < n; i += i & -i) {\r\n      dat_const[i] -= val * (left - 1);\r\n \
    \     dat_linear[i] += val;\r\n    }\r\n    for (int i = right + 1; i < n; i +=\
    \ i & -i) {\r\n      dat_const[i] += val * right;\r\n      dat_linear[i] -= val;\r\
    \n    }\r\n  }\r\n\r\n  Abelian sum(int idx) const {\r\n    Abelian res = ID;\r\
    \n    for (int i = idx; i > 0; i -= i & -i) res += dat_linear[i];\r\n    res *=\
    \ idx;\r\n    for (int i = idx; i > 0; i -= i & -i) res += dat_const[i];\r\n \
    \   return res;\r\n  }\r\n\r\n  Abelian sum(int left, int right) const {\r\n \
    \   return left < right ? sum(right) - sum(left) : ID;\r\n  }\r\n\r\n  Abelian\
    \ operator[](const int idx) const { return sum(idx, idx + 1); }\r\n\r\nprivate:\r\
    \n  int n;\r\n  const Abelian ID;\r\n  std::vector<Abelian> dat_const, dat_linear;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/bit/bit_range_add.hpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/bit/bit_range_add.test.cpp
  - test/graph/tree/hld.1.test.cpp
documentation_of: data_structure/bit/bit_range_add.hpp
layout: document
redirect_from:
- /library/data_structure/bit/bit_range_add.hpp
- /library/data_structure/bit/bit_range_add.hpp.html
title: "binary indexed tree \u533A\u9593\u52A0\u7B97\u7248"
---
# binary indexed tree (フェニック木)


## 時間計算量

|データ構造|時間計算量|
|:--:|:--:|
|binary indexed tree|$\langle O(N), O(\log{N}) \rangle$|
|2次元 BIT|$\langle O(HW), O(\log{H} \log{W}) \rangle$|


## 使用法

- binary indexed tree

||説明|備考|
|:--:|:--:|:--:|
|`BIT<Abelian>(n, 単位元 = 0)`|要素数 $N$ の binary indexed tree||
|`add(idx, val)`|$A_{\mathrm{idx}} += \mathrm{val}$||
|`sum(idx)`|$\sum_{i = 0}^{\mathrm{idx} - 1} A_i$||
|`sum(left, right)`|$\sum_{i = \mathrm{left}}^{\mathrm{right} - 1} A_i$||
|`operator()[idx]`|$A_{\mathrm{idx}}$||
|`lower_bound(val)`|$\min \lbrace\,k \mid \sum_{i = 0}^k A_i \geq \mathrm{val} \rbrace$|$A_i \geq \text{単位元} \ (i = 0,\ldots, N - 1)$ でなければならない．|

- binary indexed tree 区間加算版

||説明|
|:--:|:--:|
|`BIT<Abelian>(n, 単位元 = 0)`|要素数 $N$ の binary indexed tree|
|`add(left, right, val)`|$A_i += \mathrm{val} \ (i = \mathrm{left},\ldots, \mathrm{right} - 1)$|
|`sum(idx)`|$\sum_{i = 0}^{\mathrm{idx} - 1} A_i$|
|`sum(left, right)`|$\sum_{i = \mathrm{left}}^{\mathrm{right} - 1} A_i$|
|`bit[idx]`|$A_{\mathrm{idx}}$|

- 2次元 BIT

||説明|
|:--:|:--:|
|`BIT2D<Abelian>(height, width, 単位元 = 0)`|要素数 $\mathrm{height} \ast \mathrm{width}$ の2次元 BIT|
|`add(y, x, val)`|$A_{yx} += \mathrm{val}$|
|`sum(y, x)`|$\sum_{i = 0}^y \sum_{j = 0}^x A_{ij}$|
|`sum(y1, x1, y2, x2)`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|

- 2次元 BIT 領域加算版

||説明|
|:--:|:--:|
|`BIT2DRangeAdd<Abelian>(height, width, 単位元 = 0)`|要素数 $\mathrm{height} \ast \mathrm{width}$ の2次元 BIT 領域加算版|
|`add(y1, x1, y2, x2, val)`|$A_{ij} += \mathrm{val} \ (y_1 \leq i \leq y_2, x_1 \leq j \leq x_2)$|
|`sum(y, x)`|$\sum_{i = 0}^y \sum_{j = 0}^x A_{ij}$|
|`sum(y1, x1, y2, x2)`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## 2次元 BIT 領域加算版の実装

$A_{ij} += v \ (y_1 \leq i \leq y_2, x_1 \leq j \leq x_2)$ を考える．

$S = \sum_{i = 1}^y \sum_{j = 1}^x A_{ij}$ とおき，加算前の $S$ を $S_b$，加算後の $S$ を $S_a$ とすると

- $y_1 \leq y \leq y_2,\ x_1 \leq x \leq x_2$ のとき

  $$\begin{aligned} S_a - S_b &= v(y - y_1 + 1)(x - x_1 + 1) \\ &= vyx - v(x_1 - 1)y - v(y_1 - 1)x + v(y_1 - 1)(x_1 - 1) \end{aligned}$$

  が成り立つ．$S_1 = vyx - v(x_1 - 1)y - v(y_1 - 1)x + v(y_1 - 1)(x_1 - 1)$ とおく．

- $y_1 \leq y \leq y_2,\ x < x_2$ のとき

  $$\begin{aligned} S_a - S_b &= v(y - y_1 + 1)(x_2 - x_1 + 1) \\ &= v(x_2 - x_1 + 1)y - v(y_1 - 1)(x_2 - x_1 + 1) \\ &= -v(x_1 - 1)y + vx_2y + v(y_1 - 1)(x_1 - 1) - v(y_1 - 1)x_2 \\ &= S_1 - vyx + v(y_1 - 1)x + vx_2y - v(y_1 - 1)x_2 \end{aligned}$$

  が成り立つ．$S_2 = - vyx + v(y_1 - 1)x + vx_2y - v(y_1 - 1)x_2$ とおく．

- $y < y_2,\ x_1 \leq x \leq x_2$ のとき

  $$\begin{aligned} S_a - S_b &= v(y_2 - y_1 + 1)(x - x_1 + 1) \\ &= v(y_2 - y_1 + 1)x - v(y_2 - y_1 + 1)(x_1 - 1) \\ &= -v(y_1 - 1)x + vy_2x + v(y_1 - 1)(x_1 - 1) - vy_2(x_1 - 1) \\ &= S_1 - vyx + v(x_1 - 1)y + vy_2x - vy_2(x_1 - 1) \end{aligned}$$

  が成り立つ．$S_3 = - vyx + v(x_1 - 1)y + vy_2x - vy_2(x_1 - 1)$ とおく．

- $y < y_2,\ x < x_2$ のとき

  $$\begin{aligned} S_a - S_b &= v(y_2 - y_1 + 1)(x_2 - x_1 + 1) \\ &= v(y_1 - 1)(x_1 - 1) - v(y_1 - 1) x_2 - vy_2(x_1 - 1) + v y_2 x_2 \\ &= S_1 + S_2 + S_3 + vyx - vx_2y - vy_2x + vy_2x_2 \end{aligned}$$

  が成り立つ．

- $\text{otherwise}$

  $$S_a - S_b = 0$$

  が成り立つ．


## 参考

- http://hos.ac/slides/20140319_bit.pdf


## ToDo

- https://www.hamayanhamayan.com/entry/2017/07/08/173120
- 単調非減少な一点変更，区間最大値のクエリを処理できる BIT
  - http://hos.ac/slides/20140319_bit.pdf


## Verified

- binary indexed tree
  - [`sum(left, right)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_B/review/4084050/emthrm/C++14)
  - [`lower_bound(val)`](https://atcoder.jp/contests/arc033/submissions/9261672)
- [binary indexed tree 区間加算版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4191837/emthrm/C++14)
- 2次元 BIT
- [2次元 BIT 領域加算版](https://codeforces.com/contest/1200/submission/71571647)