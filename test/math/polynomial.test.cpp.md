---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/polynomial.hpp
    title: "\u591A\u9805\u5F0F (polynomial)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u591A\u9805\u5F0F"
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "#line 1 \"test/math/polynomial.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u591A\u9805\u5F0F\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n\r\n#line 2 \"math/modint.hpp\"\
    \n// #include <algorithm>\r\n// #include <cassert>\r\n#line 5 \"math/modint.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\n// template <int M>\r\n// struct\
    \ MInt {\r\n//   unsigned int v;\r\n//   MInt() : v(0) {}\r\n//   MInt(const long\
    \ long x) : v(x >= 0 ? x % M : x % M + M) {}\r\n//   static constexpr int get_mod()\
    \ { return M; }\r\n//   static void set_mod(const int divisor) { assert(divisor\
    \ == M); }\r\n//   static void init(const int x = 10000000) {\r\n//     inv(x,\
    \ true);\r\n//     fact(x);\r\n//     fact_inv(x);\r\n//   }\r\n//   static MInt\
    \ inv(const int n, const bool init = false) {\r\n//     // assert(0 <= n && n\
    \ < M && std::__gcd(n, M) == 1);\r\n//     static std::vector<MInt> inverse{0,\
    \ 1};\r\n//     const int prev = inverse.size();\r\n//     if (n < prev) {\r\n\
    //       return inverse[n];\r\n//     } else if (init) {\r\n//       // \"n!\"\
    \ and \"M\" must be disjoint.\r\n//       inverse.resize(n + 1);\r\n//       for\
    \ (int i = prev; i <= n; ++i) {\r\n//         inverse[i] = -inverse[M % i] * (M\
    \ / i);\r\n//       }\r\n//       return inverse[n];\r\n//     }\r\n//     int\
    \ u = 1, v = 0;\r\n//     for (unsigned int a = n, b = M; b;) {\r\n//       const\
    \ unsigned int q = a / b;\r\n//       std::swap(a -= q * b, b);\r\n//       std::swap(u\
    \ -= q * v, v);\r\n//     }\r\n//     return u;\r\n//   }\r\n//   static MInt\
    \ fact(const int n) {\r\n//     static std::vector<MInt> factorial{1};\r\n// \
    \    const int prev = factorial.size();\r\n//     if (n >= prev) {\r\n//     \
    \  factorial.resize(n + 1);\r\n//       for (int i = prev; i <= n; ++i) {\r\n\
    //         factorial[i] = factorial[i - 1] * i;\r\n//       }\r\n//     }\r\n\
    //     return factorial[n];\r\n//   }\r\n//   static MInt fact_inv(const int n)\
    \ {\r\n//     static std::vector<MInt> f_inv{1};\r\n//     const int prev = f_inv.size();\r\
    \n//     if (n >= prev) {\r\n//       f_inv.resize(n + 1);\r\n//       f_inv[n]\
    \ = inv(fact(n).v);\r\n//       for (int i = n; i > prev; --i) {\r\n//       \
    \  f_inv[i - 1] = f_inv[i] * i;\r\n//       }\r\n//     }\r\n//     return f_inv[n];\r\
    \n//   }\r\n//   static MInt nCk(const int n, const int k) {\r\n//     if (n <\
    \ 0 || n < k || k < 0) return 0;\r\n//     return fact(n) * (n - k < k ? fact_inv(k)\
    \ * fact_inv(n - k) :\r\n//                                   fact_inv(n - k)\
    \ * fact_inv(k));\r\n//   }\r\n//   static MInt nPk(const int n, const int k)\
    \ {\r\n//     return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\r\
    \n//   }\r\n//   static MInt nHk(const int n, const int k) {\r\n//     return\
    \ n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\r\n//   }\r\n//   static\
    \ MInt large_nCk(long long n, const int k) {\r\n//     if (n < 0 || n < k || k\
    \ < 0) return 0;\r\n//     inv(k, true);\r\n//     MInt res = 1;\r\n//     for\
    \ (int i = 1; i <= k; ++i) {\r\n//       res *= inv(i) * n--;\r\n//     }\r\n\
    //     return res;\r\n//   }\r\n//   MInt pow(long long exponent) const {\r\n\
    //     MInt res = 1, tmp = *this;\r\n//     for (; exponent > 0; exponent >>=\
    \ 1) {\r\n//       if (exponent & 1) res *= tmp;\r\n//       tmp *= tmp;\r\n//\
    \     }\r\n//     return res;\r\n//   }\r\n//   MInt& operator+=(const MInt& x)\
    \ {\r\n//     if ((v += x.v) >= M) v -= M;\r\n//     return *this;\r\n//   }\r\
    \n//   MInt& operator-=(const MInt& x) {\r\n//     if ((v += M - x.v) >= M) v\
    \ -= M;\r\n//     return *this;\r\n//   }\r\n//   MInt& operator*=(const MInt&\
    \ x) {\r\n//     v = static_cast<unsigned long long>(v) * x.v % M;\r\n//     return\
    \ *this;\r\n//   }\r\n//   MInt& operator/=(const MInt& x) { return *this *= inv(x.v);\
    \ }\r\n//   bool operator==(const MInt& x) const { return v == x.v; }\r\n//  \
    \ bool operator!=(const MInt& x) const { return v != x.v; }\r\n//   bool operator<(const\
    \ MInt& x) const { return v < x.v; }\r\n//   bool operator<=(const MInt& x) const\
    \ { return v <= x.v; }\r\n//   bool operator>(const MInt& x) const { return v\
    \ > x.v; }\r\n//   bool operator>=(const MInt& x) const { return v >= x.v; }\r\
    \n//   MInt& operator++() {\r\n//     if (++v == M) v = 0;\r\n//     return *this;\r\
    \n//   }\r\n//   MInt operator++(int) {\r\n//     const MInt res = *this;\r\n\
    //     ++*this;\r\n//     return res;\r\n//   }\r\n//   MInt& operator--() {\r\
    \n//     v = (v == 0 ? M - 1 : v - 1);\r\n//     return *this;\r\n//   }\r\n//\
    \   MInt operator--(int) {\r\n//     const MInt res = *this;\r\n//     --*this;\r\
    \n//     return res;\r\n//   }\r\n//   MInt operator+() const { return *this;\
    \ }\r\n//   MInt operator-() const { return MInt(v ? M - v : 0); }\r\n//   MInt\
    \ operator+(const MInt& x) const { return MInt(*this) += x; }\r\n//   MInt operator-(const\
    \ MInt& x) const { return MInt(*this) -= x; }\r\n//   MInt operator*(const MInt&\
    \ x) const { return MInt(*this) *= x; }\r\n//   MInt operator/(const MInt& x)\
    \ const { return MInt(*this) /= x; }\r\n//   friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\r\n//     return os << x.v;\r\n//   }\r\n//   friend std::istream&\
    \ operator>>(std::istream& is, MInt& x) {\r\n//     long long v;\r\n//     is\
    \ >> v;\r\n//     x = MInt(v);\r\n//     return is;\r\n//   }\r\n// };\r\n\r\n\
    template <int ID>\r\nstruct MInt {\r\n  unsigned int v;\r\n  MInt() : v(0) {}\r\
    \n  MInt(const long long x) : v(x >= 0 ? x % mod() : x % mod() + mod()) {}\r\n\
    \  static int get_mod() { return mod(); }\r\n  static void set_mod(const int divisor)\
    \ { mod() = divisor; }\r\n  static void init(const int x = 10000000) {\r\n   \
    \ inv(x, true);\r\n    fact(x);\r\n    fact_inv(x);\r\n  }\r\n  static MInt inv(const\
    \ int n, const bool init = false) {\r\n    // assert(0 <= n && n < mod() && std::__gcd(x,\
    \ mod()) == 1);\r\n    static std::vector<MInt> inverse{0, 1};\r\n    const int\
    \ prev = inverse.size();\r\n    if (n < prev) {\r\n      return inverse[n];\r\n\
    \    } else if (init) {\r\n      // \"n!\" and \"mod()\" must be disjoint.\r\n\
    \      inverse.resize(n + 1);\r\n      for (int i = prev; i <= n; ++i) {\r\n \
    \       inverse[i] = -inverse[mod() % i] * (mod() / i);\r\n      }\r\n      return\
    \ inverse[n];\r\n    }\r\n    int u = 1, v = 0;\r\n    for (unsigned int a = n,\
    \ b = mod(); b;) {\r\n      const unsigned int q = a / b;\r\n      std::swap(a\
    \ -= q * b, b);\r\n      std::swap(u -= q * v, v);\r\n    }\r\n    return u;\r\
    \n  }\r\n  static MInt fact(const int n) {\r\n    static std::vector<MInt> factorial{1};\r\
    \n    const int prev = factorial.size();\r\n    if (n >= prev) {\r\n      factorial.resize(n\
    \ + 1);\r\n      for (int i = prev; i <= n; ++i) {\r\n        factorial[i] = factorial[i\
    \ - 1] * i;\r\n      }\r\n    }\r\n    return factorial[n];\r\n  }\r\n  static\
    \ MInt fact_inv(const int n) {\r\n    static std::vector<MInt> f_inv{1};\r\n \
    \   const int prev = f_inv.size();\r\n    if (n >= prev) {\r\n      f_inv.resize(n\
    \ + 1);\r\n      f_inv[n] = inv(fact(n).v);\r\n      for (int i = n; i > prev;\
    \ --i) {\r\n        f_inv[i - 1] = f_inv[i] * i;\r\n      }\r\n    }\r\n    return\
    \ f_inv[n];\r\n  }\r\n  static MInt nCk(const int n, const int k) {\r\n    if\
    \ (n < 0 || n < k || k < 0) return 0;\r\n    return fact(n) * (n - k < k ? fact_inv(k)\
    \ * fact_inv(n - k) :\r\n                                  fact_inv(n - k) * fact_inv(k));\r\
    \n  }\r\n  static MInt nPk(const int n, const int k) {\r\n    return n < 0 ||\
    \ n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\r\n  }\r\n  static MInt nHk(const\
    \ int n, const int k) {\r\n    return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n\
    \ + k - 1, k));\r\n  }\r\n  static MInt large_nCk(long long n, const int k) {\r\
    \n    if (n < 0 || n < k || k < 0) return 0;\r\n    inv(k, true);\r\n    MInt\
    \ res = 1;\r\n    for (int i = 1; i <= k; ++i) {\r\n      res *= inv(i) * n--;\r\
    \n    }\r\n    return res;\r\n  }\r\n  MInt pow(long long exponent) const {\r\n\
    \    MInt res = 1, tmp = *this;\r\n    for (; exponent > 0; exponent >>= 1) {\r\
    \n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n    }\r\n    return\
    \ res;\r\n  }\r\n  MInt& operator+=(const MInt& x) {\r\n    if ((v += x.v) >=\
    \ mod()) v -= mod();\r\n    return *this;\r\n  }\r\n  MInt& operator-=(const MInt&\
    \ x) {\r\n    if ((v += mod() - x.v) >= mod()) v -= mod();\r\n    return *this;\r\
    \n  }\r\n  MInt& operator*=(const MInt& x) {\r\n    v = static_cast<unsigned long\
    \ long>(v) * x.v % mod();\r\n    return *this;\r\n    }\r\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\r\n  bool operator==(const MInt& x) const\
    \ { return v == x.v; }\r\n  bool operator!=(const MInt& x) const { return v !=\
    \ x.v; }\r\n  bool operator<(const MInt& x) const { return v < x.v; }\r\n  bool\
    \ operator<=(const MInt& x) const { return v <= x.v; }\r\n  bool operator>(const\
    \ MInt& x) const { return v > x.v; }\r\n  bool operator>=(const MInt& x) const\
    \ { return v >= x.v; }\r\n  MInt& operator++() {\r\n    if (++v == mod()) v =\
    \ 0;\r\n    return *this;\r\n  }\r\n  MInt operator++(int) {\r\n    const MInt\
    \ res = *this;\r\n    ++*this;\r\n    return res;\r\n  }\r\n  MInt& operator--()\
    \ {\r\n    v = (v == 0 ? mod() - 1 : v - 1);\r\n    return *this;\r\n  }\r\n \
    \ MInt operator--(int) {\r\n    const MInt res = *this;\r\n    --*this;\r\n  \
    \  return res;\r\n  }\r\n  MInt operator+() const { return *this; }\r\n  MInt\
    \ operator-() const { return MInt(v ? mod() - v : 0); }\r\n  MInt operator+(const\
    \ MInt& x) const { return MInt(*this) += x; }\r\n  MInt operator-(const MInt&\
    \ x) const { return MInt(*this) -= x; }\r\n  MInt operator*(const MInt& x) const\
    \ { return MInt(*this) *= x; }\r\n  MInt operator/(const MInt& x) const { return\
    \ MInt(*this) /= x; }\r\n  friend std::ostream& operator<<(std::ostream& os, const\
    \ MInt& x) {\r\n    return os << x.v;\r\n  }\r\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\r\n    long long v;\r\n    is >> v;\r\n    x = MInt(v);\r\n \
    \   return is;\r\n  }\r\n private:\r\n  static int& mod() {\r\n    static int\
    \ divisor = 0;\r\n    return divisor;\r\n  }\r\n};\r\n#line 2 \"math/polynomial.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n#include\
    \ <initializer_list>\r\n#line 8 \"math/polynomial.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstruct Polynomial {\r\n  std::vector<T> coef;\r\n\r\n  explicit Polynomial(const\
    \ int deg = 0) : coef(deg + 1, 0) {}\r\n  explicit Polynomial(const std::vector<T>&\
    \ coef) : coef(coef) {}\r\n  Polynomial(const std::initializer_list<T> init)\r\
    \n      : coef(init.begin(), init.end()) {}\r\n  template <typename InputIter>\r\
    \n  explicit Polynomial(const InputIter first, const InputIter last)\r\n     \
    \ : coef(first, last) {}\r\n\r\n  inline const T& operator[](const int term) const\
    \ { return coef[term]; }\r\n  inline T& operator[](const int term) { return coef[term];\
    \ }\r\n\r\n  using MULT = std::function<std::vector<T>(const std::vector<T>&,\r\
    \n                                            const std::vector<T>&)>;\r\n  static\
    \ void set_mult(const MULT mult) { get_mult() = mult; }\r\n\r\n  void shrink()\
    \ {\r\n    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\r\n  }\r\
    \n  int degree() const { return static_cast<int>(coef.size()) - 1; }\r\n\r\n \
    \ Polynomial& operator=(const std::vector<T>& coef_) {\r\n    coef = coef_;\r\n\
    \    return *this;\r\n  }\r\n  Polynomial& operator=(const Polynomial& x) = default;\r\
    \n\r\n  Polynomial& operator+=(const Polynomial& x) {\r\n    const int deg_x =\
    \ x.degree();\r\n    if (deg_x > degree()) coef.resize(deg_x + 1, 0);\r\n    for\
    \ (int i = 0; i <= deg_x; ++i) {\r\n      coef[i] += x[i];\r\n    }\r\n    return\
    \ *this;\r\n  }\r\n  Polynomial& operator-=(const Polynomial& x) {\r\n    const\
    \ int deg_x = x.degree();\r\n    if (deg_x > degree()) coef.resize(deg_x + 1,\
    \ 0);\r\n    for (int i = 0; i <= deg_x; ++i) {\r\n      coef[i] -= x[i];\r\n\
    \    }\r\n    return *this;\r\n  }\r\n  Polynomial& operator*=(const T x) {\r\n\
    \    for (T& e : coef) e *= x;\r\n    return *this;\r\n  }\r\n  Polynomial& operator*=(const\
    \ Polynomial& x) {\r\n    return *this = get_mult()(coef, x.coef);\r\n  }\r\n\
    \  Polynomial& operator/=(const T x) {\r\n    assert(x != 0);\r\n    return *this\
    \ *= static_cast<T>(1) / x;\r\n  }\r\n  std::pair<Polynomial, Polynomial> divide(Polynomial\
    \ x) const {\r\n    x.shrink();\r\n    Polynomial rem = *this;\r\n    const int\
    \ n = rem.degree(), m = x.degree(), deg = n - m;\r\n    if (deg < 0) return {Polynomial{0},\
    \ rem};\r\n    Polynomial quo(deg);\r\n    for (int i = 0; i <= deg; ++i) {\r\n\
    \      quo[deg - i] = rem[n - i] / x[m];\r\n      for (int j = 0; j <= m; ++j)\
    \ {\r\n        rem[n - i - j] -= x[m - j] * quo[deg - i];\r\n      }\r\n    }\r\
    \n    rem.coef.resize(deg + 1);\r\n    return {quo, rem};\r\n  }\r\n  Polynomial&\
    \ operator/=(const Polynomial& x) {\r\n    return *this = divide(x).first;\r\n\
    \  }\r\n  Polynomial& operator%=(const Polynomial& x) {\r\n    return *this =\
    \ divide(x).second;\r\n  }\r\n  Polynomial& operator<<=(const int n) {\r\n   \
    \ coef.insert(coef.begin(), n, 0);\r\n    return *this;\r\n  }\r\n\r\n  bool operator==(Polynomial\
    \ x) const {\r\n    x.shrink();\r\n    Polynomial y = *this;\r\n    y.shrink();\r\
    \n    return x.coef == y.coef;\r\n  }\r\n  bool operator!=(const Polynomial& x)\
    \ const { return !(*this == x); }\r\n\r\n  Polynomial operator+() const { return\
    \ *this; }\r\n  Polynomial operator-() const {\r\n    Polynomial res = *this;\r\
    \n    for (T& e : res.coef) e = -e;\r\n    return res;\r\n  }\r\n\r\n  Polynomial\
    \ operator+(const Polynomial& x) const {\r\n    return Polynomial(*this) += x;\r\
    \n  }\r\n  Polynomial operator-(const Polynomial& x) const {\r\n    return Polynomial(*this)\
    \ -= x;\r\n  }\r\n  Polynomial operator*(const T x) const {\r\n    return Polynomial(*this)\
    \ *= x;\r\n  }\r\n  Polynomial operator*(const Polynomial& x) const {\r\n    return\
    \ Polynomial(*this) *= x;\r\n  }\r\n  Polynomial operator/(const T x) const {\
    \ return Polynomial(*this) /= x; }\r\n  Polynomial operator/(const Polynomial&\
    \ x) const {\r\n    return Polynomial(*this) /= x;\r\n  }\r\n  Polynomial operator%(const\
    \ Polynomial& x) const {\r\n    return Polynomial(*this) %= x;\r\n  }\r\n  Polynomial\
    \ operator<<(const int n) const { return Polynomial(*this) <<= n; }\r\n\r\n  T\
    \ horner(const T x) const {\r\n    T res = 0;\r\n    for (int i = degree(); i\
    \ >= 0; --i) {\r\n      res = res * x + coef[i];\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\n  Polynomial differential() const {\r\n    const int deg = degree();\r\
    \n    assert(deg >= 0);\r\n    Polynomial res(std::max(deg - 1, 0));\r\n    for\
    \ (int i = 1; i <= deg; ++i) {\r\n      res[i - 1] = coef[i] * i;\r\n    }\r\n\
    \    return res;\r\n  }\r\n\r\n  Polynomial pow(int exponent) const {\r\n    Polynomial\
    \ res{1}, base = *this;\r\n    for (; exponent > 0; exponent >>= 1) {\r\n    \
    \  if (exponent & 1) res *= base;\r\n      base *= base;\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  Polynomial translate(const T c) const {\r\n    const int\
    \ n = coef.size();\r\n    std::vector<T> fact(n, 1), inv_fact(n, 1);\r\n    for\
    \ (int i = 1; i < n; ++i) {\r\n      fact[i] = fact[i - 1] * i;\r\n    }\r\n \
    \   inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];\r\n    for (int i = n -\
    \ 1; i > 0; --i) {\r\n      inv_fact[i - 1] = inv_fact[i] * i;\r\n    }\r\n  \
    \  std::vector<T> g(n), ex(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      g[i]\
    \ = coef[i] * fact[i];\r\n    }\r\n    std::reverse(g.begin(), g.end());\r\n \
    \   T pow_c = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c *\
    \ inv_fact[i];\r\n      pow_c *= c;\r\n    }\r\n    const std::vector<T> conv\
    \ = get_mult()(g, ex);\r\n    Polynomial res(n - 1);\r\n    for (int i = 0; i\
    \ < n; ++i) {\r\n      res[i] = conv[n - 1 - i] * inv_fact[i];\r\n    }\r\n  \
    \  return res;\r\n  }\r\n\r\n private:\r\n  static MULT& get_mult() {\r\n    static\
    \ MULT mult = [](const std::vector<T>& a, const std::vector<T>& b)\r\n       \
    \ -> std::vector<T> {\r\n      const int n = a.size(), m = b.size();\r\n     \
    \ std::vector<T> res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i) {\r\n\
    \        for (int j = 0; j < m; ++j) {\r\n          res[i + j] += a[i] * b[j];\r\
    \n        }\r\n      }\r\n      return res;\r\n    };\r\n    return mult;\r\n\
    \  }\r\n};\r\n#line 12 \"test/math/polynomial.test.cpp\"\n\r\nint main() {\r\n\
    \  using ModInt = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  int n, m;\r\n\
    \  std::cin >> n >> m;\r\n  Polynomial<ModInt> f(n - 1), g(m - 1);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    std::cin >> f[i];\r\n  }\r\n  for (int i = 0; i\
    \ < m; ++i) {\r\n    std::cin >> g[i];\r\n  }\r\n  Polynomial<ModInt> q, r;\r\n\
    \  std::tie(q, r) = f.divide(g);\r\n  q.shrink();\r\n  r.shrink();\r\n  const\
    \ int u = (q == Polynomial<ModInt>{0} ? 0 : q.degree() + 1);\r\n  const int v\
    \ = (r == Polynomial<ModInt>{0} ? 0 : r.degree() + 1);\r\n  std::cout << u <<\
    \ ' ' << v << '\\n';\r\n  for (int i = 0; i < u; ++i) {\r\n    std::cout << q[i];\r\
    \n    if (i + 1 < u) std::cout << ' ';\r\n  }\r\n  std::cout << '\\n';\r\n  for\
    \ (int i = 0; i < v; ++i) {\r\n    std::cout << r[i];\r\n    if (i + 1 < v) std::cout\
    \ << ' ';\r\n  }\r\n  std::cout << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u591A\u9805\u5F0F\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\r\
    \n\r\n#include <iostream>\r\n#include <tuple>\r\n\r\n#include \"../../math/modint.hpp\"\
    \r\n#include \"../../math/polynomial.hpp\"\r\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  int n, m;\r\n  std::cin >>\
    \ n >> m;\r\n  Polynomial<ModInt> f(n - 1), g(m - 1);\r\n  for (int i = 0; i <\
    \ n; ++i) {\r\n    std::cin >> f[i];\r\n  }\r\n  for (int i = 0; i < m; ++i) {\r\
    \n    std::cin >> g[i];\r\n  }\r\n  Polynomial<ModInt> q, r;\r\n  std::tie(q,\
    \ r) = f.divide(g);\r\n  q.shrink();\r\n  r.shrink();\r\n  const int u = (q ==\
    \ Polynomial<ModInt>{0} ? 0 : q.degree() + 1);\r\n  const int v = (r == Polynomial<ModInt>{0}\
    \ ? 0 : r.degree() + 1);\r\n  std::cout << u << ' ' << v << '\\n';\r\n  for (int\
    \ i = 0; i < u; ++i) {\r\n    std::cout << q[i];\r\n    if (i + 1 < u) std::cout\
    \ << ' ';\r\n  }\r\n  std::cout << '\\n';\r\n  for (int i = 0; i < v; ++i) {\r\
    \n    std::cout << r[i];\r\n    if (i + 1 < v) std::cout << ' ';\r\n  }\r\n  std::cout\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/polynomial.hpp
  isVerificationFile: true
  path: test/math/polynomial.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/polynomial.test.cpp
- /verify/test/math/polynomial.test.cpp.html
title: "\u6570\u5B66/\u591A\u9805\u5F0F"
---
