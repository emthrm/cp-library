---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    document_title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217"
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/math/matrix/matrix.test.cpp\"\n/*\n * @title \u6570\
    \u5B66/\u884C\u5217/\u884C\u5217\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_product\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\n\n\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct\
    \ Matrix {\n  explicit Matrix(const int m, const int n, const T def = 0)\n   \
    \   : data(m, std::vector<T>(n, def)) {}\n\n  int nrow() const { return data.size();\
    \ }\n  int ncol() const { return data.front().size(); }\n\n  Matrix pow(long long\
    \ exponent) const {\n    const int n = nrow();\n    Matrix<T> res(n, n, 0), tmp\
    \ = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i][i] = 1;\n    }\n \
    \   for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res *= tmp;\n\
    \      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline const std::vector<T>&\
    \ operator[](const int i) const { return data[i]; }\n  inline std::vector<T>&\
    \ operator[](const int i) { return data[i]; }\n\n  Matrix& operator=(const Matrix&\
    \ x) = default;\n\n  Matrix& operator+=(const Matrix& x) {\n    const int m =\
    \ nrow(), n = ncol();\n    for (int i = 0; i < m; ++i) {\n      for (int j = 0;\
    \ j < n; ++j) {\n        data[i][j] += x[i][j];\n      }\n    }\n    return *this;\n\
    \  }\n\n  Matrix& operator-=(const Matrix& x) {\n    const int m = nrow(), n =\
    \ ncol();\n    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j)\
    \ {\n        data[i][j] -= x[i][j];\n      }\n    }\n    return *this;\n  }\n\n\
    \  Matrix& operator*=(const Matrix& x) {\n    const int m = nrow(), l = ncol(),\
    \ n = x.ncol();\n    std::vector<std::vector<T>> res(m, std::vector<T>(n, 0));\n\
    \    for (int i = 0; i < m; ++i) {\n      for (int k = 0; k < l; ++k) {\n    \
    \    for (int j = 0; j < n; ++j) {\n          res[i][j] += data[i][k] * x[k][j];\n\
    \        }\n      }\n    }\n    data.swap(res);\n    return *this;\n  }\n\n  Matrix\
    \ operator+(const Matrix& x) const { return Matrix(*this) += x; }\n  Matrix operator-(const\
    \ Matrix& x) const { return Matrix(*this) -= x; }\n  Matrix operator*(const Matrix&\
    \ x) const { return Matrix(*this) *= x; }\n\n private:\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/modint.hpp\"\
    \n\n\n\n#ifndef ARBITRARY_MODINT\n# include <cassert>\n#endif\n#include <compare>\n\
    #line 9 \"include/emthrm/math/modint.hpp\"\n// #include <numeric>\n#include <utility>\n\
    #line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\n\
    template <unsigned int M>\nstruct MInt {\n  unsigned int v;\n\n  constexpr MInt()\
    \ : v(0) {}\n  constexpr MInt(const long long x) : v(x >= 0 ? x % M : x % M +\
    \ M) {}\n  static constexpr MInt raw(const int x) {\n    MInt x_;\n    x_.v =\
    \ x;\n    return x_;\n  }\n\n  static constexpr int get_mod() { return M; }\n\
    \  static constexpr void set_mod(const int divisor) {\n    assert(std::cmp_equal(divisor,\
    \ M));\n  }\n\n  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n\
    \    fact_inv(x);\n  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const\
    \ int n) {\n    // assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static\
    \ std::vector<MInt> inverse{0, 1};\n    const int prev = inverse.size();\n   \
    \ if (n < prev) return inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"\
    n!\" and \"M\" must be disjoint.\n      inverse.resize(n + 1);\n      for (int\
    \ i = prev; i <= n; ++i) {\n        inverse[i] = -inverse[M % i] * raw(M / i);\n\
    \      }\n      return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned\
    \ int a = n, b = M; b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
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
    }  // namespace emthrm\n\n\n#line 11 \"test/math/matrix/matrix.test.cpp\"\n\n\
    int main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, m, k;\n  std::cin\
    \ >> n >> m >> k;\n  emthrm::Matrix<ModInt> a(n, m), b(m, k);\n  for (int i =\
    \ 0; i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      std::cin >> a[i][j];\n\
    \    }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0; j < k; ++j)\
    \ {\n      std::cin >> b[i][j];\n    }\n  }\n  const emthrm::Matrix<ModInt> c\
    \ = a * b;\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < k; ++j) {\n\
    \      std::cout << c[i][j] << \" \\n\"[j + 1 == k];\n    }\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u6570\u5B66/\u884C\u5217/\u884C\u5217\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/matrix_product\n */\n\n#include <iostream>\n\
    \n#include \"emthrm/math/matrix/matrix.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, m, k;\n\
    \  std::cin >> n >> m >> k;\n  emthrm::Matrix<ModInt> a(n, m), b(m, k);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      std::cin\
    \ >> a[i][j];\n    }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0;\
    \ j < k; ++j) {\n      std::cin >> b[i][j];\n    }\n  }\n  const emthrm::Matrix<ModInt>\
    \ c = a * b;\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < k; ++j)\
    \ {\n      std::cout << c[i][j] << \" \\n\"[j + 1 == k];\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/matrix/matrix.test.cpp
  requiredBy: []
  timestamp: '2023-05-13 18:14:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/matrix.test.cpp
- /verify/test/math/matrix/matrix.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217"
---
