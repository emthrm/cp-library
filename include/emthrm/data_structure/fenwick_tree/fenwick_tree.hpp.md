---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/misc/inversion_number.hpp
    title: "\u8EE2\u5012\u6570 (inversion number)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree"
  - icon: ':warning:'
    path: test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree\uFF08\u4E8C\u5206\
      \u63A2\u7D22\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/misc/inversion_number.test.cpp
    title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: test/misc/mo.test.cpp
    title: "\u305D\u306E\u4ED6/Mo's algorithm"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\n\n\n#include <bit>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ Abelian>\nstruct FenwickTree {\n  explicit FenwickTree(const int n, const Abelian\
    \ ID = 0)\n      : n(n), ID(ID), data(n, ID) {}\n\n  void add(int idx, const Abelian\
    \ val) {\n    for (; idx < n; idx |= idx + 1) {\n      data[idx] += val;\n   \
    \ }\n  }\n\n  Abelian sum(int idx) const {\n    Abelian res = ID;\n    for (--idx;\
    \ idx >= 0; idx = (idx & (idx + 1)) - 1) {\n      res += data[idx];\n    }\n \
    \   return res;\n  }\n\n  Abelian sum(const int left, const int right) const {\n\
    \    return left < right ? sum(right) - sum(left) : ID;\n  }\n\n  Abelian operator[](const\
    \ int idx) const { return sum(idx, idx + 1); }\n\n  int lower_bound(Abelian val)\
    \ const {\n    if (val <= ID) [[unlikely]] return 0;\n    int res = 0;\n    for\
    \ (int mask = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;\n        \
    \ mask > 0; mask >>= 1) {\n      const int idx = res + mask - 1;\n      if (idx\
    \ < n && data[idx] < val) {\n        val -= data[idx];\n        res += mask;\n\
    \      }\n    }\n    return res;\n  }\n\n private:\n  const int n;\n  const Abelian\
    \ ID;\n  std::vector<Abelian> data;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_HPP_\n#define EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_HPP_\n\
    \n#include <bit>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ Abelian>\nstruct FenwickTree {\n  explicit FenwickTree(const int n, const Abelian\
    \ ID = 0)\n      : n(n), ID(ID), data(n, ID) {}\n\n  void add(int idx, const Abelian\
    \ val) {\n    for (; idx < n; idx |= idx + 1) {\n      data[idx] += val;\n   \
    \ }\n  }\n\n  Abelian sum(int idx) const {\n    Abelian res = ID;\n    for (--idx;\
    \ idx >= 0; idx = (idx & (idx + 1)) - 1) {\n      res += data[idx];\n    }\n \
    \   return res;\n  }\n\n  Abelian sum(const int left, const int right) const {\n\
    \    return left < right ? sum(right) - sum(left) : ID;\n  }\n\n  Abelian operator[](const\
    \ int idx) const { return sum(idx, idx + 1); }\n\n  int lower_bound(Abelian val)\
    \ const {\n    if (val <= ID) [[unlikely]] return 0;\n    int res = 0;\n    for\
    \ (int mask = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;\n        \
    \ mask > 0; mask >>= 1) {\n      const int idx = res + mask - 1;\n      if (idx\
    \ < n && data[idx] < val) {\n        val -= data[idx];\n        res += mask;\n\
    \      }\n    }\n    return res;\n  }\n\n private:\n  const int n;\n  const Abelian\
    \ ID;\n  std::vector<Abelian> data;\n};\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  requiredBy:
  - include/emthrm/misc/inversion_number.hpp
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
  - test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
  - test/misc/inversion_number.test.cpp
  - test/misc/mo.test.cpp
documentation_of: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
layout: document
title: Fenwick tree (binary indexed tree)
---

# Fenwick tree (binary indexed tree)


## 時間計算量

||時間計算量|
|:--|:--|
|Fenwick tree|$\langle O(N), O(\log{N}) \rangle$|
|2次元 Fenwick tree|$\langle O(HW), O((\log{H})(\log{W})) \rangle$|


## 仕様

### Fenwick tree

```cpp
template <typename Abelian>
struct FenwickTree;
```

- `Abelian`：[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)である要素型

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit FenwickTree(const int n, const Abelian ID = 0);`|要素数 $N$、単位元 $\mathrm{id}$ のオブジェクトを構築する。||
|`void add(int idx, const Abelian val);`|$A_{\mathrm{idx}} \gets A_{\mathrm{idx}} + \mathrm{val}$||
|`Abelian sum(int idx) const;`|$\sum_{i = 0}^{\mathrm{idx} - 1} A_i$||
|`Abelian sum(const int left, const int right) const;`|$\sum_{i = \mathrm{left}}^{\mathrm{right} - 1} A_i$||
|`Abelian operator[](const int idx) const;`|$A_{\mathrm{idx}}$||
|`int lower_bound(Abelian val) const;`|$\min \lbrace\,k \mid \sum_{i = 0}^k A_i \geq \mathrm{val} \rbrace$|$A_i \geq (\text{単位元})$ ($i = 0,\ldots, N - 1$)|


### 区間加算クエリ対応 Fenwick tree

```cpp
template <typename Abelian>
struct FenwickTreeSupportingRangeAddQuery;
```

- `Abelian`：[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)である要素型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit FenwickTreeSupportingRangeAddQuery(const int n_, const Abelian ID = 0);`|要素数 $N$、単位元 $\mathrm{id}$ のオブジェクトを構築する。|
|`void add(int left, const int right, const Abelian val);`|$A_i \gets A_i + \mathrm{val}$ ($i = \mathrm{left},\ldots, \mathrm{right} - 1$)|
|`Abelian sum(const int idx) const;`|$\sum_{i = 0}^{\mathrm{idx} - 1} A_i$|
|`Abelian sum(const int left, const int right) const;`|$\sum_{i = \mathrm{left}}^{\mathrm{right} - 1} A_i$|
|`Abelian operator[](const int idx) const;`|$A_{\mathrm{idx}}$|


### 2次元 Fenwick tree

```cpp
template <typename Abelian>
struct FenwickTreeSupportingRangeAddQuery;
```

- `Abelian`：[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)である要素型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit FenwickTree2D(const int height_, const int width_, const Abelian ID = 0);`|要素数 $\mathrm{height} \times \mathrm{width}$、単位元 $\mathrm{id}$ のオブジェクトを構築する。|
|`void add(int y, int x, const Abelian val);`|$A_{yx} \gets A_{yx} + \mathrm{val}$|
|`Abelian sum(int y, int x) const;`|$\sum_{i = 0}^y \sum_{j = 0}^x A_{ij}$|
|`Abelian sum(const int y1, const int x1, const int y2, const int x2) const;`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|
|`Abelian get(const int y, const int x) const;`|$A_{yx}$|


### 区間加算クエリ対応2次元 Fenwick tree

```cpp
template <typename Abelian>
struct FenwickTree2DSupportingRangeAddQuery;
```

- `Abelian`：[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)である要素型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit FenwickTree2DSupportingRangeAddQuery(const int height_, const int width_, const Abelian ID = 0);`|要素数 $\mathrm{height} \times \mathrm{width}$、単位元 $\mathrm{id}$ のオブジェクトを構築する。|
|`void add(int y1, int x1, int y2, int x2, const Abelian val);`|$A_{ij} \gets A_{ij} + \mathrm{val}$ ($y_1 \leq i \leq y_2,\ x_1 \leq j \leq x_2$)|
|`Abelian sum(int y, int x) const;`|$\sum_{i = 0}^y \sum_{j = 0}^x A_{ij}$|
|`Abelian sum(const int y1, const int x1, const int y2, const int x2) const;`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## 区間加算クエリ対応2次元 Fenwick tree の実装

$A_{ij} \gets A_{ij} + v$ ($y_1 \leq i \leq y_2,\ x_1 \leq j \leq x_2$) を考える。

$S \mathrel{:=} \sum_{i = 1}^y \sum_{j = 1}^x A_{ij}$ とおき、加算前の $S$ を $S_b$、加算後の $S$ を $S_a$ とすると

- $y_1 \leq y \leq y_2,\ x_1 \leq x \leq x_2$ のとき

  $$
    \begin{aligned}
      S_a - S_b &= v(y - y_1 + 1)(x - x_1 + 1) \\
                &= vyx - v(x_1 - 1)y - v(y_1 - 1)x + v(y_1 - 1)(x_1 - 1)
    \end{aligned}
  $$

  が成り立つ。$S_1 \mathrel{:=} vyx - v(x_1 - 1)y - v(y_1 - 1)x + v(y_1 - 1)(x_1 - 1)$ とおく。

- $y_1 \leq y \leq y_2,\ x_2 < x$ のとき

  $$
    \begin{aligned}
      S_a - S_b &= v(y - y_1 + 1)(x_2 - x_1 + 1) \\
                &= -v(x_1 - 1)y + v(y_1 - 1)(x_1 - 1) + vx_2y - v(y_1 - 1)x_2 \\
                &= S_1 - vyx + v(y_1 - 1)x + vx_2y - v(y_1 - 1)x_2
    \end{aligned}
  $$

  が成り立つ。$S_2 \mathrel{:=} - vyx + v(y_1 - 1)x + vx_2y - v(y_1 - 1)x_2$ とおく。

- $y_2 < y,\ x_1 \leq x \leq x_2$ のとき

  $$
    \begin{aligned}
      S_a - S_b &= v(y_2 - y_1 + 1)(x - x_1 + 1) \\
                &= -v(y_1 - 1)x + v(y_1 - 1)(x_1 - 1) + vy_2x - vy_2(x_1 - 1) \\
                &= S_1 - vyx + v(x_1 - 1)y + vy_2x - vy_2(x_1 - 1)
    \end{aligned}
  $$

  が成り立つ。$S_3 \mathrel{:=} - vyx + v(x_1 - 1)y + vy_2x - vy_2(x_1 - 1)$ とおく。

- $y_2 < y,\ x_2 < x$ のとき

  $$
    \begin{aligned}
      S_a - S_b &= v(y_2 - y_1 + 1)(x_2 - x_1 + 1) \\
                &= v(y_1 - 1)(x_1 - 1) - v(y_1 - 1) x_2 - vy_2(x_1 - 1) + v y_2 x_2 \\
                &= S_1 + S_2 + S_3 + vyx - vy_2x - vx_2y + vy_2x_2
    \end{aligned}
  $$

  が成り立つ。

- $\text{otherwise}$

  $$
    S_a - S_b = 0
  $$

  が成り立つ。


## 参考文献

- http://hos.ac/slides/20140319_bit.pdf


## TODO

- https://www.hamayanhamayan.com/entry/2017/07/08/173120
- 定数倍高速化
  - https://scrapbox.io/ecasdqina-cp/BIT_%E3%81%AE%E5%AE%9A%E6%95%B0%E5%80%8D%E9%AB%98%E9%80%9F%E5%8C%96%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6
- 単調非減少な一点変更、区間最大値のクエリを処理できる Fenwick tree
  - http://hos.ac/slides/20140319_bit.pdf
- $d$ 次元Fenwick tree
  - https://suisen-kyopro.hatenablog.com/entry/2022/09/09/013334


## Submissons

- Fenwick tree
  - [`sum(left, right)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_B/review/4084050/emthrm/C++14)
  - [`lower_bound(val)`](https://atcoder.jp/contests/arc033/submissions/9261672)
- [区間加算クエリ対応 Fenwick tree](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4191837/emthrm/C++14)
- [2次元 Fenwick tree](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2842/review/5903562/emthrm/C++17)
- [区間加算クエリ対応2次元 Fenwick tree](https://yukicoder.me/submissions/651161)
