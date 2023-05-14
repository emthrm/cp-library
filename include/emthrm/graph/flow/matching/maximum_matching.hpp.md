---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/maximum_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
      \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/matching/maximum_matching.hpp\"\
    \n\n\n\n#include <random>\n#include <vector>\n\n#line 1 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\
    \n\n\n\n#include <utility>\n\n#line 1 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/matrix/matrix.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstruct Matrix {\n  explicit Matrix(const int m,\
    \ const int n, const T def = 0)\n      : data(m, std::vector<T>(n, def)) {}\n\n\
    \  int nrow() const { return data.size(); }\n  int ncol() const { return data.front().size();\
    \ }\n\n  Matrix pow(long long exponent) const {\n    const int n = nrow();\n \
    \   Matrix<T> res(n, n, 0), tmp = *this;\n    for (int i = 0; i < n; ++i) {\n\
    \      res[i][i] = 1;\n    }\n    for (; exponent > 0; exponent >>= 1) {\n   \
    \   if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n\
    \  }\n\n  inline const std::vector<T>& operator[](const int i) const { return\
    \ data[i]; }\n  inline std::vector<T>& operator[](const int i) { return data[i];\
    \ }\n\n  Matrix& operator=(const Matrix& x) = default;\n\n  Matrix& operator+=(const\
    \ Matrix& x) {\n    const int m = nrow(), n = ncol();\n    for (int i = 0; i <\
    \ m; ++i) {\n      for (int j = 0; j < n; ++j) {\n        data[i][j] += x[i][j];\n\
    \      }\n    }\n    return *this;\n  }\n\n  Matrix& operator-=(const Matrix&\
    \ x) {\n    const int m = nrow(), n = ncol();\n    for (int i = 0; i < m; ++i)\
    \ {\n      for (int j = 0; j < n; ++j) {\n        data[i][j] -= x[i][j];\n   \
    \   }\n    }\n    return *this;\n  }\n\n  Matrix& operator*=(const Matrix& x)\
    \ {\n    const int m = nrow(), l = ncol(), n = x.ncol();\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\n    for (int i = 0; i < m; ++i) {\n      for\
    \ (int k = 0; k < l; ++k) {\n        for (int j = 0; j < n; ++j) {\n         \
    \ res[i][j] += data[i][k] * x[k][j];\n        }\n      }\n    }\n    data.swap(res);\n\
    \    return *this;\n  }\n\n  Matrix operator+(const Matrix& x) const { return\
    \ Matrix(*this) += x; }\n  Matrix operator-(const Matrix& x) const { return Matrix(*this)\
    \ -= x; }\n  Matrix operator*(const Matrix& x) const { return Matrix(*this) *=\
    \ x; }\n\n private:\n  std::vector<std::vector<T>> data;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 7 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <bool IS_EXTENDED = false, typename T>\nint gauss_jordan(Matrix<T>*\
    \ a, const T eps = 1e-8) {\n  const int m = a->nrow(), n = a->ncol();\n  int rank\
    \ = 0;\n  for (int col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {\n    int\
    \ pivot = -1;\n    T mx = eps;\n    for (int row = rank; row < m; ++row) {\n \
    \     const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col]);\n\
    \      if (abs > mx) {\n        pivot = row;\n        mx = abs;\n      }\n   \
    \ }\n    if (pivot == -1) continue;\n    std::swap((*a)[rank], (*a)[pivot]);\n\
    \    T tmp = (*a)[rank][col];\n    for (int col2 = 0; col2 < n; ++col2) {\n  \
    \    (*a)[rank][col2] /= tmp;\n    }\n    for (int row = 0; row < m; ++row) {\n\
    \      if (row != rank &&\n          ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col])\
    \ > eps) {\n        tmp = (*a)[row][col];\n        for (int col2 = 0; col2 < n;\
    \ ++col2) {\n          (*a)[row][col2] -= (*a)[rank][col2] * tmp;\n        }\n\
    \      }\n    }\n    ++rank;\n  }\n  return rank;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#include <iostream>\n// #include\
    \ <numeric>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\
    \n#ifndef ARBITRARY_MODINT\ntemplate <unsigned int M>\nstruct MInt {\n  unsigned\
    \ int v;\n\n  constexpr MInt() : v(0) {}\n  constexpr MInt(const long long x)\
    \ : v(x >= 0 ? x % M : x % M + M) {}\n  static constexpr MInt raw(const int x)\
    \ {\n    MInt x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static constexpr int\
    \ get_mod() { return M; }\n  static constexpr void set_mod(const int divisor)\
    \ {\n    assert(std::cmp_equal(divisor, M));\n  }\n\n  static void init(const\
    \ int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template\
    \ <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n    // assert(0 <=\
    \ n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt> inverse{0,\
    \ 1};\n    const int prev = inverse.size();\n    if (n < prev) return inverse[n];\n\
    \    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n\
    \      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n     \
    \   inverse[i] = -inverse[M % i] * raw(M / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = M; b;) {\n   \
    \   const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
    \ -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const int n)\
    \ {\n    static std::vector<MInt> factorial{1};\n    if (const int prev = factorial.size();\
    \ n >= prev) {\n      factorial.resize(n + 1);\n      for (int i = prev; i <=\
    \ n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n      }\n    }\n  \
    \  return factorial[n];\n  }\n\n  static MInt fact_inv(const int n) {\n    static\
    \ std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size(); n >= prev)\
    \ {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n      for (int\
    \ i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n      }\n   \
    \ }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const int k)\
    \ {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n    return\
    \ fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n                   \
    \               fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  constexpr MInt pow(long long exponent) const {\n    MInt res\
    \ = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  constexpr\
    \ MInt& operator+=(const MInt& x) {\n    if ((v += x.v) >= M) v -= M;\n    return\
    \ *this;\n  }\n  constexpr MInt& operator-=(const MInt& x) {\n    if ((v += M\
    \ - x.v) >= M) v -= M;\n    return *this;\n  }\n  constexpr MInt& operator*=(const\
    \ MInt& x) {\n    v = (unsigned long long){v} * x.v % M;\n    return *this;\n\
    \  }\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }\n\n  constexpr\
    \ auto operator<=>(const MInt& x) const = default;\n\n  constexpr MInt& operator++()\
    \ {\n    if (++v == M) [[unlikely]] v = 0;\n    return *this;\n  }\n  constexpr\
    \ MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n    return\
    \ res;\n  }\n  constexpr MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  constexpr MInt operator--(int) {\n    const MInt res\
    \ = *this;\n    --*this;\n    return res;\n  }\n\n  constexpr MInt operator+()\
    \ const { return *this; }\n  constexpr MInt operator-() const { return raw(v ?\
    \ M - v : 0); }\n\n  constexpr MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  constexpr MInt operator-(const MInt& x) const { return MInt(*this)\
    \ -= x; }\n  constexpr MInt operator*(const MInt& x) const { return MInt(*this)\
    \ *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }\n\
    \n  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\n    return\
    \ os << x.v;\n  }\n  friend std::istream& operator>>(std::istream& is, MInt& x)\
    \ {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return is;\n  }\n};\n\
    #else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n  unsigned int v;\n\
    \n  constexpr MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\n  static constexpr MInt raw(const int x) {\n    MInt\
    \ x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const unsigned int divisor) { mod() = divisor; }\n\n\
    \  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * raw(mod() / i);\n      }\n   \
    \   return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a\
    \ = n, b = mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
    \ -= q * b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n\
    \  static MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n\
    \    if (const int prev = factorial.size(); n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size();\
    \ n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n   \
    \ return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n            \
    \                      fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  MInt pow(long long exponent) const {\n    MInt res = 1, tmp =\
    \ *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1)\
    \ res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  MInt& operator+=(const\
    \ MInt& x) {\n    if ((v += x.v) >= mod()) v -= mod();\n    return *this;\n  }\n\
    \  MInt& operator-=(const MInt& x) {\n    if ((v += mod() - x.v) >= mod()) v -=\
    \ mod();\n    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v =\
    \ (unsigned long long){v} * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (++v == mod()) [[unlikely]]\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return raw(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static unsigned int& mod() {\n    static unsigned int\
    \ divisor = 0;\n    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n\
    }  // namespace emthrm\n\n\n#line 10 \"include/emthrm/graph/flow/matching/maximum_matching.hpp\"\
    \n\nnamespace emthrm {\n\nint maximum_matching(const std::vector<std::vector<int>>&\
    \ graph) {\n  constexpr unsigned int P = 1000000007;\n  using ModInt = MInt<P>;\n\
    \  ModInt::set_mod(P);\n  static std::mt19937_64 engine(std::random_device {}\
    \ ());\n  static std::uniform_int_distribution<> dist(1, P - 1);\n  const int\
    \ n = graph.size();\n  Matrix<ModInt> tutte_matrix(n, n, 0);\n  for (int i = 0;\
    \ i < n; ++i) {\n    for (const int j : graph[i]) {\n      if (j > i) {\n    \
    \    const ModInt x = ModInt::raw(dist(engine));\n        tutte_matrix[i][j] =\
    \ x;\n        tutte_matrix[j][i] = -x;\n      }\n    }\n  }\n  return gauss_jordan(&tutte_matrix,\
    \ ModInt(0)) / 2;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_\n#define EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_\n\
    \n#include <random>\n#include <vector>\n\n#include \"emthrm/math/matrix/gauss_jordan.hpp\"\
    \n#include \"emthrm/math/matrix/matrix.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nnamespace emthrm {\n\nint maximum_matching(const std::vector<std::vector<int>>&\
    \ graph) {\n  constexpr unsigned int P = 1000000007;\n  using ModInt = MInt<P>;\n\
    \  ModInt::set_mod(P);\n  static std::mt19937_64 engine(std::random_device {}\
    \ ());\n  static std::uniform_int_distribution<> dist(1, P - 1);\n  const int\
    \ n = graph.size();\n  Matrix<ModInt> tutte_matrix(n, n, 0);\n  for (int i = 0;\
    \ i < n; ++i) {\n    for (const int j : graph[i]) {\n      if (j > i) {\n    \
    \    const ModInt x = ModInt::raw(dist(engine));\n        tutte_matrix[i][j] =\
    \ x;\n        tutte_matrix[j][i] = -x;\n      }\n    }\n  }\n  return gauss_jordan(&tutte_matrix,\
    \ ModInt(0)) / 2;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/gauss_jordan.hpp
  - include/emthrm/math/matrix/matrix.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/graph/flow/matching/maximum_matching.hpp
  requiredBy: []
  timestamp: '2023-05-13 18:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/matching/maximum_matching.test.cpp
documentation_of: include/emthrm/graph/flow/matching/maximum_matching.hpp
layout: document
title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
  \ (maximum matching)"
---

### マッチング (matching)

互いに端点を共有しない辺集合である。


### 辺被覆 (edge cover)

任意の頂点がいずれかの端点となっている辺集合である。


### 独立集合 (independent set) / 安定集合 (stable set)

互いに隣接していない頂点集合である。


### 頂点被覆 (vertex cover)

任意の辺に対して少なくとも一方の端点を含む頂点集合である。


### クリーク (clique)

無向グラフに対して完全グラフな部分グラフである。


## 性質

1. 孤立点のないグラフに対して (最大マッチングのサイズ) + (最小辺被覆のサイズ) = (頂点数) が成り立つ。

2. (最大独立集合のサイズ) + (最小頂点被覆のサイズ) = (頂点数)

3. 二部グラフ $(U, V, E)$ に対して $\lvert U \rvert = \lvert V \rvert \implies (\text{完全二部マッチングの個数}) \equiv \lvert A \rvert \pmod{2}$ が成り立つ。ただし $A$ は $a_{ij} = \begin{cases} 1 & (\lbrace U_i, V_j \rbrace \in E), \\\\ 0 & (\text{otherwise}) \end{cases}$ を満たす $\lvert U \rvert \times \lvert V \rvert$ 型行列である。

4. 二部グラフに対して、最大マッチングのサイズは最小頂点被覆のサイズに等しい。

5. 有向非巡回グラフの最小パス被覆は二部グラフの最大マッチングに帰着できる。


### Hall's theorem

二部グラフ $(U, V, E)$ に対して、以下は同値である。

- $U$ の元をすべて被覆するマッチングが存在する。
- $\forall S \subseteq U,\ \lvert S \rvert \leq \lvert \Gamma(S) \rvert$.


### Dilworth's theorem

任意の有限な半順序集合に対して、反鎖 (antichain) の最大サイズは共通部分のない鎖 (chain) に分解したときの最小サイズに等しい。

特に有向非巡回グラフ $G$ では、$\forall u, v \in V(G)$ に対して

$$
  u \leq v \iff u \text{ から } v \text{ に到達可能である。}
$$

と定義すると、$(V(G), \leq)$ は半順序集合である。$(V(G), \leq)$ に対して、共通部分のない鎖に分解したときの最小サイズは最小パス被覆のサイズを意味する。


## 時間計算量

||時間計算量|
|:--|:--|
|二部グラフの最大マッチング|$O(\lvert V \rvert \lvert E \rvert)$|
|Hopcroft–Karp algorithm|$O(\lvert E \rvert \sqrt{\lvert V \rvert})$|
|二部グラフの重み付き最大マッチング|$O(\lvert E \rvert \lvert V \rvert \log{\lvert V \rvert})$|
|一般グラフの最大マッチング|$O({\lvert V \rvert}^3 + \lvert E \rvert)$|


## 仕様

### 二部グラフの最大マッチング

```cpp
struct BipartiteMatching;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> match`|マッチした相手。ただし存在しないときは $-1$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit BipartiteMatching(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`int solve();`|最大マッチングのサイズ|
|`void fix(const int ver);`|頂点 $\mathrm{ver}$ に対するマッチングを固定する。|
|`int activate(const int ver);`|頂点 $\mathrm{ver}$ を有効にしたのち、最大マッチングのサイズの変化量を返す。|
|`int deactivate(const int ver);`|頂点 $\mathrm{ver}$ を無効にしたのち、最大マッチングのサイズの変化量を返す。|


### Hopcroft–Karp algorithm

```cpp
struct HopcroftKarp;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> match`|マッチした相手。ただし存在しないときは $-1$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit HopcroftKarp(const int left, const int right);`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフに対してオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`int solve();`|最大マッチングのサイズ|


### 二部グラフの重み付き最大マッチング

```cpp
template <typename T>
struct WeightedBipartiteMatching;
```

- `T`：重みを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit WeightedBipartiteMatching(const int left, const int right);`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフに対してオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const T cost);`|重み $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。||
|`T solve();`|重み付き最大マッチングの重み||
|`std::vector<int> matching() const;`|マッチした相手。ただし存在しないときは $-1$ が格納される。|


### 一般グラフの最大マッチング

|名前|戻り値|
|:--|:--|
|`int maximum_matching(const std::vector<std::vector<int>>& graph);`|無向グラフ $\mathrm{graph}$ の最大マッチングのサイズ|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.195-199，マイナビ出版（2012）

性質3
- https://pekempey.hatenablog.com/entry/2016/11/29/200605

性質5・Dilworth's theorem
- Robert P. Dilworth: A Decomposition Theorem for Partially Ordered Sets, *Annals of Mathematics*, Vol. 51, No. 1, pp. 161–166 (1950). https://doi.org/10.2307/1969503
- https://en.wikipedia.org/wiki/Dilworth%27s_theorem
- ~~https://lumakernel.github.io/ecasdqina/math/dilworth-theorem~~
- https://anta1.hatenadiary.org/entry/20120816/1345046832

Hall's theorem
- Philip Hall: On Representatives of Subsets, *Journal of the London Mathematical Society*, Vol. s1-10, No. 1, pp. 26–30 (1935). https://doi.org/10.1112/jlms/s1-10.37.26
- https://mathtrain.jp/hall

二部グラフの最大マッチング
- https://ei1333.github.io/algorithm/bipartite-matching.html

Hopcroft–Karp algorithm
- John E. Hopcroft and Richard M. Karp: An $n^{5/2}$ Algorithm for Maximum Matchings in Bipartite Graphs, *SIAM Journal on Computing*, Vol. 2, No. 4, pp. 225–231 (1973). https://doi.org/10.1137/0202019
- https://tiramister.net/blog/posts/hopcroft-karp/
- https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html

二部グラフの重み付き最大マッチング
- https://qiita.com/drken/items/e805e3f514acceb87602

一般グラフの最大マッチング
- W. T. Tutte: The Factorization of Linear Graphs, *Journal of the London Mathematical Society*, Vol. s1-22, No. 2, pp. 107–111 (1947). https://doi.org/10.1112/jlms/s1-22.2.107
- https://kopricky.github.io/code/Academic/maximum_matching_memo.html


## TODO

- https://www.slideshare.net/wata_orz/ss-12131479
- https://drive.google.com/file/d/1RD66csuDTAYXPmuCsiPi3HWBwtLg95T5
- 一般グラフの最大マッチング
  - ~~https://min-25.hatenablog.com/entry/2016/11/21/222625~~
  - https://judge.yosupo.jp/problem/general_matching
  - Edmonds' Algorithm
    - ~~http://www.prefield.com/algorithm/graph/maximum_matching.html~~
    - https://github.com/spaghetti-source/algorithm/blob/master/graph/gabow_edmonds.cc
    - https://www.dropbox.com/sh/7uhazzp6wvx9mi7/AACpEgmn--Grp9nVD3NOD9Hia
    - https://www.slideshare.net/hcpc_hokudai/ss-120540096
    - https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf
- 一般グラフの重み付き最大マッチング
  - ~~https://min-25.hatenablog.com/entry/2016/11/21/222625~~
  - ~~http://www.prefield.com/algorithm/graph/minimum_weight_matching.html~~
  - https://judge.yosupo.jp/problem/general_weighted_matching
- 木の最小辺被覆
  - https://twitter.com/Ymgch_K/status/964058288747831296
- 最大独立集合
  - https://37zigen.com/maximum-independent-set-algorithm/
  - https://drive.google.com/drive/folders/1MlboOgOEnu_zx55pGhZK80IT3hN6H-Ji
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-independent-set.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-independent-set.hpp
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MaximumIndependentSet.cpp
  - https://mugen1337.github.io/procon/Graph2/WeightedMaximumIndependentSet.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/maximum_independent_set.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/maximum_weight_independent_set.hpp
  - https://judge.yosupo.jp/problem/maximum_independent_set
- 木上の独立集合
  - https://github.com/noshi91/blog/tree/master/codes/typical90/
  - https://atcoder.jp/contests/typical90/tasks/typical90_z
  - https://twitter.com/noshi91/status/1387447778167513088
  - https://twitter.com/noshi91/status/1387448827838353411
  - https://twitter.com/noshi91/status/1387456359587729411
- 二部グラフの最小頂点被覆
  - https://www.slideshare.net/drken1215/2-86838670
- 最大クリーク
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximal_cliques.cc
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-clique.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-clique.hpp
  - https://www.t3nro.net/2017/04/maximum-clique-problem/
- ハンガリアン法 (Hungarian method)
  - https://ei1333.github.io/algorithm/hungarian.html
  - https://ei1333.github.io/luzhiled/snippets/graph/hungarian.html
  - ~~http://www.prefield.com/algorithm/math/hungarian.html~~
  - https://github.com/primenumber/ProconLib/blob/master/Graph/Hungarian.cpp
  - https://judge.yosupo.jp/problem/assignment
- 安定マッチング (stable matching)
  - https://ja.wikipedia.org/wiki/%E5%AE%89%E5%AE%9A%E7%B5%90%E5%A9%9A%E5%95%8F%E9%A1%8C
  - https://mathtrain.jp/galeshapley
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!StableMatching.cpp~~
  - https://sotanishy.github.io/cp-library-cpp/misc/stable_matching.hpp
- FKT algorithm
  - https://en.wikipedia.org/wiki/FKT_algorithm
  - https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
- クリークの列挙
  - https://sotanishy.github.io/cp-library-cpp/graph/enumerate_cliques.cpp
  - https://judge.yosupo.jp/problem/enumerate_cliques


## Submissons

- [二部グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_7_A/review/5876417/emthrm/C++17)
- [Hopcroft–Karp algorithm](https://judge.yosupo.jp/submission/2723)
- [二部グラフの重み付き最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2429/review/4092692/emthrm/C++14)
- [一般グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3032/review/5853683/emthrm/C++17)
