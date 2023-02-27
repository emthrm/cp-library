---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/matrix_tree_theorem.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <iterator>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/math/matrix/determinant.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/matrix/determinant.hpp\"\n#include <utility>\n\
    \n#line 1 \"include/emthrm/math/matrix/matrix.hpp\"\n\n\n\n#line 5 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Matrix {\n  explicit Matrix(const\
    \ int m, const int n, const T def = 0)\n      : data(m, std::vector<T>(n, def))\
    \ {}\n\n  int nrow() const { return data.size(); }\n  int ncol() const { return\
    \ data.front().size(); }\n\n  Matrix pow(long long exponent) const {\n    const\
    \ int n = nrow();\n    Matrix<T> res(n, n, 0), tmp = *this;\n    for (int i =\
    \ 0; i < n; ++i) {\n      res[i][i] = 1;\n    }\n    for (; exponent > 0; exponent\
    \ >>= 1) {\n      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n  \
    \  return res;\n  }\n\n  inline const std::vector<T>& operator[](const int i)\
    \ const { return data[i]; }\n  inline std::vector<T>& operator[](const int i)\
    \ { return data[i]; }\n\n  Matrix& operator=(const Matrix& x) = default;\n\n \
    \ Matrix& operator+=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n\
    \    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j) {\n    \
    \    data[i][j] += x[i][j];\n      }\n    }\n    return *this;\n  }\n\n  Matrix&\
    \ operator-=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n    for\
    \ (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j) {\n        data[i][j]\
    \ -= x[i][j];\n      }\n    }\n    return *this;\n  }\n\n  Matrix& operator*=(const\
    \ Matrix& x) {\n    const int m = nrow(), l = ncol(), n = x.ncol();\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\n    for (int i = 0; i < m; ++i) {\n      for\
    \ (int k = 0; k < l; ++k) {\n        for (int j = 0; j < n; ++j) {\n         \
    \ res[i][j] += data[i][k] * x[k][j];\n        }\n      }\n    }\n    data.swap(res);\n\
    \    return *this;\n  }\n\n  Matrix operator+(const Matrix& x) const { return\
    \ Matrix(*this) += x; }\n  Matrix operator-(const Matrix& x) const { return Matrix(*this)\
    \ -= x; }\n  Matrix operator*(const Matrix& x) const { return Matrix(*this) *=\
    \ x; }\n\n private:\n  std::vector<std::vector<T>> data;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 8 \"include/emthrm/math/matrix/determinant.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T, typename U>\nU det(const Matrix<T>& a, const\
    \ U eps) {\n  const int n = a.nrow();\n  Matrix<U> b(n, n);\n  for (int i = 0;\
    \ i < n; ++i) {\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\n  }\n\
    \  U res = 1;\n  for (int j = 0; j < n; ++j) {\n    int pivot = -1;\n    U mx\
    \ = eps;\n    for (int i = j; i < n; ++i) {\n      const U abs = (b[i][j] < 0\
    \ ? -b[i][j] : b[i][j]);\n      if (abs > mx) {\n        pivot = i;\n        mx\
    \ = abs;\n      }\n    }\n    if (pivot == -1) return 0;\n    if (pivot != j)\
    \ {\n      std::swap(b[j], b[pivot]);\n      res = -res;\n    }\n    res *= b[j][j];\n\
    \    for (int k = j + 1; k < n; ++k) {\n      b[j][k] /= b[j][j];\n    }\n   \
    \ for (int i = j + 1; i < n; ++i) {\n      for (int k = j + 1; k < n; ++k) {\n\
    \        b[i][k] -= b[i][j] * b[j][k];\n      }\n    }\n  }\n  return res;\n}\n\
    \n}  // namespace emthrm\n\n\n#line 11 \"include/emthrm/graph/matrix_tree_theorem.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename CostType>\nT matrix_tree_theorem(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n                      const\
    \ T eps = 1e-8) {\n  const int n = graph.size();\n  if (n == 1) [[unlikely]] return\
    \ 1;\n  Matrix<int> laplacian(n, n, 0);\n  for (int i = 0; i < n; ++i) {\n   \
    \ for (const Edge<CostType>& e : graph[i]) {\n      ++laplacian[e.src][e.src];\n\
    \      --laplacian[e.src][e.dst];\n    }\n  }\n  Matrix<int> cofactor(n - 1, n\
    \ - 1);\n  for (int i = 0; i < n - 1; ++i) {\n    std::copy(std::next(laplacian[i\
    \ + 1].begin()), laplacian[i + 1].end(),\n              cofactor[i].begin());\n\
    \  }\n  return det(cofactor, eps);\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_MATRIX_TREE_THEOREM_HPP_\n#define EMTHRM_GRAPH_MATRIX_TREE_THEOREM_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <vector>\n\n#include \"\
    emthrm/graph/edge.hpp\"\n#include \"emthrm/math/matrix/determinant.hpp\"\n#include\
    \ \"emthrm/math/matrix/matrix.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T, typename CostType>\nT matrix_tree_theorem(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n                      const T eps = 1e-8) {\n  const int n = graph.size();\n\
    \  if (n == 1) [[unlikely]] return 1;\n  Matrix<int> laplacian(n, n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (const Edge<CostType>& e : graph[i]) {\n\
    \      ++laplacian[e.src][e.src];\n      --laplacian[e.src][e.dst];\n    }\n \
    \ }\n  Matrix<int> cofactor(n - 1, n - 1);\n  for (int i = 0; i < n - 1; ++i)\
    \ {\n    std::copy(std::next(laplacian[i + 1].begin()), laplacian[i + 1].end(),\n\
    \              cofactor[i].begin());\n  }\n  return det(cofactor, eps);\n}\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_MATRIX_TREE_THEOREM_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/math/matrix/determinant.hpp
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/graph/matrix_tree_theorem.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/matrix_tree_theorem.test.cpp
documentation_of: include/emthrm/graph/matrix_tree_theorem.hpp
layout: document
title: "\u884C\u5217\u6728\u5B9A\u7406 (Kirchhoff's matrix tree theorem)"
---

# spectral graph theory


### 行列木定理 (Kirchhoff's matrix tree theorem)

無向グラフ $G$ の全域木の個数は $G$ のラプラシアン行列の任意の余因子に等しい。


### ケイリーの公式 (Cayley's formula)

$N$ 頂点のラベル付きの木の個数は $N^{N - 2}$ である。

行列木定理の特殊なときとして示せる。


### Lindström–Gessel–Viennot lemma

有向非巡回グラフ $G$、頂点集合 $A = \lbrace a_1, a_2, \ldots, a_n \rbrace,\ B = \lbrace b_1, b_2, \ldots, b_n \rbrace$、[可換環](../../.verify-helper/docs/static/algebraic_structure.md) $R$ 上の重み $w \colon E(G) \to R$ が与えられる。ただし有向パス $P$ に対して $\omega(P) \mathrel{:=} \prod_{e \in P} w(e)$ とおき、任意の $s, t \in V(G)$ に対して $e(s, t) \mathrel{:=} \sum_{\text{始点 } s \text{・終点 } t \text{ の有向パス } P} \omega(P)$ が well-defined であるとする。

以下を満たす $n$ 本のパスの組を $(P_1, P_2, \ldots, P_n)$ と記す。

- ある $\lbrace 1, 2, \ldots, n \rbrace$ の置換 $\sigma$ が存在し、任意の $i \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $P_i$ は始点 $a_i$・終点 $b_{\sigma(i)}$ の有向パスである。
- $i \neq j$ を満たす任意の $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $P_i$ と $P_j$ は点素である。

このとき

$$
  \det(M) = \sum_{(P_1, P_2, \ldots, P_n)} \mathrm{sgn}(\sigma) \prod_{i = 1}^n \omega(P_i)
$$

が成り立つ。ただし $M$ は $m_{ij} \mathrel{:=} e(a_i, b_j)$ で定義される $n$ 次正方行列である。

特殊な場合として、任意の $e \in E(G)$ に対して $w(e) = 1$ が成り立つときを考える。このとき $e(s, t)$ は始点 $s$・終点 $t$ の有向パスの本数に等しい。

さらに $i < j,\ k < l$ を満たす任意の $i, j, k, l \in \lbrace 1, 2, \ldots, n \rbrace$ に対して、始点 $a_i$・終点 $b_l$ の有向パスと始点 $a_j$・終点 $b_k$ の有向パスが必ず交差するとき、任意の $(P_1, P_2, \ldots, P_n)$ に対応する置換 $\sigma$ は恒等置換のみとなる。すなわち始点 $a_i$ に対応する終点は必ず $b_i$ となる。


## 時間計算量

- 行列木定理 $O(N^3)$


## 仕様

### 行列木定理

|名前|戻り値|
|:--|:--|
|`template <typename T, typename CostType>`<br>`T matrix_tree_theorem(const std::vector<std::vector<Edge<CostType>>>& graph, const T eps = 1e-8);`|無向グラフ $\mathrm{graph}$ の全域木の個数|


## 参考文献

- https://www.slideshare.net/irrrrr/ss-25911553

行列木定理
- https://mizuwater0.hatenablog.com/entry/2018/11/25/233547
- https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf

ケイリーの公式
- http://joisino.hatenablog.com/entry/2017/08/20/200000

Lindström–Gessel–Viennot lemma
- https://en.wikipedia.org/wiki/Lindstr%C3%B6m%E2%80%93Gessel%E2%80%93Viennot_lemma
- https://suikaba.hatenablog.com/entry/2018/12/19/025636
- https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
- https://twitter.com/kotatsugame_t/status/1411648290546851840
- https://twitter.com/noshi91/status/1432074841675362304
- https://atcoder.jp/contests/abc216/editorial/2561


## Submissons

- [行列木定理](https://atcoder.jp/contests/jsc2021/submissions/21877707)
