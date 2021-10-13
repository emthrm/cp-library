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
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#line 2 \"math/modint.hpp\"\
    \n// #include <algorithm>\r\n// #include <cassert>\r\n#line 5 \"math/modint.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\n// template <int M>\r\n// struct\
    \ MInt {\r\n//   unsigned int val;\r\n//   MInt(): val(0) {}\r\n//   MInt(long\
    \ long x) : val(x >= 0 ? x % M : x % M + M) {}\r\n//   static constexpr int get_mod()\
    \ { return M; }\r\n//   static void set_mod(int divisor) { assert(divisor == M);\
    \ }\r\n//   static void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x);\
    \ }\r\n//   static MInt inv(int x, bool init = false) {\r\n//     // assert(0\
    \ <= x && x < M && std::__gcd(x, M) == 1);\r\n//     static std::vector<MInt>\
    \ inverse{0, 1};\r\n//     int prev = inverse.size();\r\n//     if (init && x\
    \ >= prev) {\r\n//       // \"x!\" and \"M\" must be disjoint.\r\n//       inverse.resize(x\
    \ + 1);\r\n//       for (int i = prev; i <= x; ++i) inverse[i] = -inverse[M %\
    \ i] * (M / i);\r\n//     }\r\n//     if (x < inverse.size()) return inverse[x];\r\
    \n//     unsigned int a = x, b = M; int u = 1, v = 0;\r\n//     while (b) {\r\n\
    //       unsigned int q = a / b;\r\n//       std::swap(a -= q * b, b);\r\n// \
    \      std::swap(u -= q * v, v);\r\n//     }\r\n//     return u;\r\n//   }\r\n\
    //   static MInt fact(int x) {\r\n//     static std::vector<MInt> f{1};\r\n//\
    \     int prev = f.size();\r\n//     if (x >= prev) {\r\n//       f.resize(x +\
    \ 1);\r\n//       for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n// \
    \    }\r\n//     return f[x];\r\n//   }\r\n//   static MInt fact_inv(int x) {\r\
    \n//     static std::vector<MInt> finv{1};\r\n//     int prev = finv.size();\r\
    \n//     if (x >= prev) {\r\n//       finv.resize(x + 1);\r\n//       finv[x]\
    \ = inv(fact(x).val);\r\n//       for (int i = x; i > prev; --i) finv[i - 1] =\
    \ finv[i] * i;\r\n//     }\r\n//     return finv[x];\r\n//   }\r\n//   static\
    \ MInt nCk(int n, int k) {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n\
    //     if (n - k > k) k = n - k;\r\n//     return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n//   }\r\n//   static MInt nPk(int n, int k) { return n < 0 || n <\
    \ k || k < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n//   static MInt nHk(int n,\
    \ int k) { return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n\
    //   static MInt large_nCk(long long n, int k) {\r\n//     if (n < 0 || n < k\
    \ || k < 0) return 0;\r\n//     inv(k, true);\r\n//     MInt res = 1;\r\n//  \
    \   for (int i = 1; i <= k; ++i) res *= inv(i) * n--;\r\n//     return res;\r\n\
    //   }\r\n//   MInt pow(long long exponent) const {\r\n//     MInt tmp = *this,\
    \ res = 1;\r\n//     while (exponent > 0) {\r\n//       if (exponent & 1) res\
    \ *= tmp;\r\n//       tmp *= tmp;\r\n//       exponent >>= 1;\r\n//     }\r\n\
    //     return res;\r\n//   }\r\n//   MInt &operator+=(const MInt &x) { if((val\
    \ += x.val) >= M) val -= M; return *this; }\r\n//   MInt &operator-=(const MInt\
    \ &x) { if((val += M - x.val) >= M) val -= M; return *this; }\r\n//   MInt &operator*=(const\
    \ MInt &x) { val = static_cast<unsigned long long>(val) * x.val % M; return *this;\
    \ }\r\n//   MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }\r\n\
    //   bool operator==(const MInt &x) const { return val == x.val; }\r\n//   bool\
    \ operator!=(const MInt &x) const { return val != x.val; }\r\n//   bool operator<(const\
    \ MInt &x) const { return val < x.val; }\r\n//   bool operator<=(const MInt &x)\
    \ const { return val <= x.val; }\r\n//   bool operator>(const MInt &x) const {\
    \ return val > x.val; }\r\n//   bool operator>=(const MInt &x) const { return\
    \ val >= x.val; }\r\n//   MInt &operator++() { if (++val == M) val = 0; return\
    \ *this; }\r\n//   MInt operator++(int) { MInt res = *this; ++*this; return res;\
    \ }\r\n//   MInt &operator--() { val = (val == 0 ? M : val) - 1; return *this;\
    \ }\r\n//   MInt operator--(int) { MInt res = *this; --*this; return res; }\r\n\
    //   MInt operator+() const { return *this; }\r\n//   MInt operator-() const {\
    \ return MInt(val ? M - val : 0); }\r\n//   MInt operator+(const MInt &x) const\
    \ { return MInt(*this) += x; }\r\n//   MInt operator-(const MInt &x) const { return\
    \ MInt(*this) -= x; }\r\n//   MInt operator*(const MInt &x) const { return MInt(*this)\
    \ *= x; }\r\n//   MInt operator/(const MInt &x) const { return MInt(*this) /=\
    \ x; }\r\n//   friend std::ostream &operator<<(std::ostream &os, const MInt &x)\
    \ { return os << x.val; }\r\n//   friend std::istream &operator>>(std::istream\
    \ &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\n//\
    \ };\r\n// namespace std { template <int M> MInt<M> abs(const MInt<M> &x) { return\
    \ x; } }\r\n\r\ntemplate <int ID>\r\nstruct MInt {\r\n  unsigned int val;\r\n\
    \  MInt(): val(0) {}\r\n  MInt(long long x) : val(x >= 0 ? x % mod() : x % mod()\
    \ + mod()) {}\r\n  static int get_mod() { return mod(); }\r\n  static void set_mod(int\
    \ divisor) { mod() = divisor; }\r\n  static void init(int x = 10000000) { inv(x,\
    \ true); fact(x); fact_inv(x); }\r\n  static MInt inv(int x, bool init = false)\
    \ {\r\n    // assert(0 <= x && x < mod() && std::__gcd(x, mod()) == 1);\r\n  \
    \  static std::vector<MInt> inverse{0, 1};\r\n    int prev = inverse.size();\r\
    \n    if (init && x >= prev) {\r\n      // \"x!\" and \"mod()\" must be disjoint.\r\
    \n      inverse.resize(x + 1);\r\n      for (int i = prev; i <= x; ++i) inverse[i]\
    \ = -inverse[mod() % i] * (mod() / i);\r\n    }\r\n    if (x < inverse.size())\
    \ return inverse[x];\r\n    unsigned int a = x, b = mod(); int u = 1, v = 0;\r\
    \n    while (b) {\r\n      unsigned int q = a / b;\r\n      std::swap(a -= q *\
    \ b, b);\r\n      std::swap(u -= q * v, v);\r\n    }\r\n    return u;\r\n  }\r\
    \n  static MInt fact(int x) {\r\n    static std::vector<MInt> f{1};\r\n    int\
    \ prev = f.size();\r\n    if (x >= prev) {\r\n      f.resize(x + 1);\r\n     \
    \ for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n    }\r\n    return\
    \ f[x];\r\n  }\r\n  static MInt fact_inv(int x) {\r\n    static std::vector<MInt>\
    \ finv{1};\r\n    int prev = finv.size();\r\n    if (x >= prev) {\r\n      finv.resize(x\
    \ + 1);\r\n      finv[x] = inv(fact(x).val);\r\n      for (int i = x; i > prev;\
    \ --i) finv[i - 1] = finv[i] * i;\r\n    }\r\n    return finv[x];\r\n  }\r\n \
    \ static MInt nCk(int n, int k) {\r\n    if (n < 0 || n < k || k < 0) return 0;\r\
    \n    if (n - k > k) k = n - k;\r\n    return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n  }\r\n  static MInt nPk(int n, int k) { return n < 0 || n < k || k\
    \ < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n  static MInt nHk(int n, int k) {\
    \ return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n  static\
    \ MInt large_nCk(long long n, int k) {\r\n    if (n < 0 || n < k || k < 0) return\
    \ 0;\r\n    inv(k, true);\r\n    MInt res = 1;\r\n    for (int i = 1; i <= k;\
    \ ++i) res *= inv(i) * n--;\r\n    return res;\r\n  }\r\n  MInt pow(long long\
    \ exponent) const {\r\n    MInt tmp = *this, res = 1;\r\n    while (exponent >\
    \ 0) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent\
    \ >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  MInt &operator+=(const MInt &x)\
    \ { if((val += x.val) >= mod()) val -= mod(); return *this; }\r\n  MInt &operator-=(const\
    \ MInt &x) { if((val += mod() - x.val) >= mod()) val -= mod(); return *this; }\r\
    \n  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val)\
    \ * x.val % mod(); return *this; }\r\n  MInt &operator/=(const MInt &x) { return\
    \ *this *= inv(x.val); }\r\n  bool operator==(const MInt &x) const { return val\
    \ == x.val; }\r\n  bool operator!=(const MInt &x) const { return val != x.val;\
    \ }\r\n  bool operator<(const MInt &x) const { return val < x.val; }\r\n  bool\
    \ operator<=(const MInt &x) const { return val <= x.val; }\r\n  bool operator>(const\
    \ MInt &x) const { return val > x.val; }\r\n  bool operator>=(const MInt &x) const\
    \ { return val >= x.val; }\r\n  MInt &operator++() { if (++val == mod()) val =\
    \ 0; return *this; }\r\n  MInt operator++(int) { MInt res = *this; ++*this; return\
    \ res; }\r\n  MInt &operator--() { val = (val == 0 ? mod() : val) - 1; return\
    \ *this; }\r\n  MInt operator--(int) { MInt res = *this; --*this; return res;\
    \ }\r\n  MInt operator+() const { return *this; }\r\n  MInt operator-() const\
    \ { return MInt(val ? mod() - val : 0); }\r\n  MInt operator+(const MInt &x) const\
    \ { return MInt(*this) += x; }\r\n  MInt operator-(const MInt &x) const { return\
    \ MInt(*this) -= x; }\r\n  MInt operator*(const MInt &x) const { return MInt(*this)\
    \ *= x; }\r\n  MInt operator/(const MInt &x) const { return MInt(*this) /= x;\
    \ }\r\n  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return\
    \ os << x.val; }\r\n  friend std::istream &operator>>(std::istream &is, MInt &x)\
    \ { long long val; is >> val; x = MInt(val); return is; }\r\nprivate:\r\n  static\
    \ int &mod() { static int divisor = 0; return divisor; }\r\n};\r\nnamespace std\
    \ { template <int ID> MInt<ID> abs(const MInt<ID> &x) { return x; } }\r\n#line\
    \ 2 \"math/polynomial.hpp\"\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n#include <initializer_list>\r\n#line 8 \"math/polynomial.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct Polynomial {\r\n  std::vector<T> coef;\r\
    \n\r\n  explicit Polynomial(const int deg = 0) : coef(deg + 1, 0) {}\r\n  explicit\
    \ Polynomial(const std::vector<T>& coef) : coef(coef) {}\r\n  Polynomial(std::initializer_list<T>\
    \ init) : coef(init.begin(), init.end()) {}\r\n  template <typename InputIter>\r\
    \n  explicit Polynomial(InputIter first, InputIter last) : coef(first, last) {}\r\
    \n\r\n  inline const T& operator[](int term) const { return coef[term]; }\r\n\
    \  inline T& operator[](int term) { return coef[term]; }\r\n\r\n  using MUL =\
    \ std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>;\r\
    \n  static void set_mul(const MUL mul) { get_mul() = mul; }\r\n\r\n  void shrink()\
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
    \ Polynomial& x) { return *this = get_mul()(coef, x.coef); }\r\n  Polynomial&\
    \ operator/=(const T x) {\r\n    assert(x != 0);\r\n    const T inv_x = static_cast<T>(1)\
    \ / x;\r\n    for (T& e : coef) e *= inv_x;\r\n    return *this;\r\n  }\r\n  std::pair<Polynomial,\
    \ Polynomial> divide(const Polynomial& x) const {\r\n    Polynomial p(x);\r\n\
    \    p.shrink();\r\n    const int n = degree(), m = p.degree(), deg = n - m;\r\
    \n    if (deg < 0) return {Polynomial{0}, *this};\r\n    Polynomial quo(deg),\
    \ rem(*this);\r\n    for (int i = 0; i <= deg; ++i) {\r\n      quo[deg - i] =\
    \ rem[n - i] / p[m];\r\n      for (int j = 0; j <= m; ++j) {\r\n        rem[n\
    \ - i - j] -= p[m - j] * quo[deg - i];\r\n      }\r\n    }\r\n    rem.coef.resize(deg\
    \ + 1);\r\n    return {quo, rem};\r\n  }\r\n  Polynomial& operator/=(const Polynomial&\
    \ x) { return *this = divide(x).first; }\r\n  Polynomial& operator%=(const Polynomial&\
    \ x) { return *this = divide(x).second; };\r\n  Polynomial& operator<<=(const\
    \ int n) {\r\n    coef.insert(coef.begin(), n, 0);\r\n    return *this;\r\n  }\r\
    \n\r\n  bool operator==(const Polynomial& x) const {\r\n    Polynomial a(*this),\
    \ b(x);\r\n    a.shrink();\r\n    b.shrink();\r\n    const int deg = a.degree();\r\
    \n    if (deg != b.degree()) return false;\r\n    for (int i = 0; i <= deg; ++i)\
    \ {\r\n      if (a[i] != b[i]) return false;\r\n    }\r\n    return true;\r\n\
    \  }\r\n  bool operator!=(const Polynomial& x) const { return !(*this == x); }\r\
    \n\r\n  Polynomial operator+() const { return *this; }\r\n  Polynomial operator-()\
    \ const {\r\n    Polynomial res(*this);\r\n    for (T& e : res.coef) e = -e;\r\
    \n    return res;\r\n  }\r\n\r\n  Polynomial operator+(const Polynomial& x) const\
    \ { return Polynomial(*this) += x; }\r\n  Polynomial operator-(const Polynomial&\
    \ x) const { return Polynomial(*this) -= x; }\r\n  Polynomial operator*(const\
    \ T x) const { return Polynomial(*this) *= x; }\r\n  Polynomial operator*(const\
    \ Polynomial& x) const { return Polynomial(*this) *= x; }\r\n  Polynomial operator/(const\
    \ T x) const { return Polynomial(*this) /= x; }\r\n  Polynomial operator/(const\
    \ Polynomial& x) const { return Polynomial(*this) /= x; }\r\n  Polynomial operator%(const\
    \ Polynomial& x) const { return Polynomial(*this) %= x; }\r\n  Polynomial operator<<(const\
    \ int n) const { return Polynomial(*this) <<= n; }\r\n\r\n  T horner(const T x)\
    \ const {\r\n    T res = 0;\r\n    for (int i = degree(); i >= 0; --i) {\r\n \
    \     res = res * x + coef[i];\r\n    }\r\n    return res;\r\n  }\r\n\r\n  Polynomial\
    \ differential() const {\r\n    const int deg = degree();\r\n    assert(deg >=\
    \ 0);\r\n    Polynomial res(std::max(deg - 1, 0));\r\n    for (int i = 1; i <=\
    \ deg; ++i) {\r\n      res[i - 1] = coef[i] * i;\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\n  Polynomial pow(int exponent) const {\r\n    Polynomial res{1},\
    \ base = *this;\r\n    for (; exponent > 0; exponent >>= 1) {\r\n      if (exponent\
    \ & 1) res *= base;\r\n      base *= base;\r\n    }\r\n    return res;\r\n  }\r\
    \n\r\n  Polynomial translate(const T c) const {\r\n    const int n = coef.size();\r\
    \n    std::vector<T> fact(n, 1), inv_fact(n, 1);\r\n    for (int i = 1; i < n;\
    \ ++i) {\r\n      fact[i] = fact[i - 1] * i;\r\n    }\r\n    inv_fact[n - 1] =\
    \ static_cast<T>(1) / fact[n - 1];\r\n    for (int i = n - 1; i > 0; --i) {\r\n\
    \      inv_fact[i - 1] = inv_fact[i] * i;\r\n    }\r\n    std::vector<T> g(n),\
    \ ex(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      g[n - 1 - i] = coef[i]\
    \ * fact[i];\r\n    }\r\n    T pow_c = 1;\r\n    for (int i = 0; i < n; ++i) {\r\
    \n      ex[i] = pow_c * inv_fact[i];\r\n      pow_c *= c;\r\n    }\r\n    const\
    \ std::vector<T> conv = get_mul()(g, ex);\r\n    Polynomial res(n - 1);\r\n  \
    \  for (int i = 0; i < n; ++i) {\r\n      res[i] = conv[n - 1 - i] * inv_fact[i];\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  static MUL& get_mul() {\r\
    \n    static MUL mul = [](const std::vector<T>& a, const std::vector<T>& b) ->\
    \ std::vector<T> {\r\n      const int n = a.size(), m = b.size();\r\n      std::vector<T>\
    \ res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i) {\r\n        for (int\
    \ j = 0; j < m; ++j) {\r\n          res[i + j] += a[i] * b[j];\r\n        }\r\n\
    \      }\r\n      return res;\r\n    };\r\n    return mul;\r\n  }\r\n};\r\n#line\
    \ 11 \"test/math/polynomial.test.cpp\"\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\
    \n  ModInt::set_mod(998244353);\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  Polynomial<ModInt>\
    \ f(n - 1), g(m - 1);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> f[i];\r\
    \n  }\r\n  for (int i = 0; i < m; ++i) {\r\n    std::cin >> g[i];\r\n  }\r\n \
    \ Polynomial<ModInt> q, r;\r\n  std::tie(q, r) = f.divide(g);\r\n  q.shrink();\r\
    \n  r.shrink();\r\n  const int u = (q == Polynomial<ModInt>{0} ? 0 : q.degree()\
    \ + 1);\r\n  const int v = (r == Polynomial<ModInt>{0} ? 0 : r.degree() + 1);\r\
    \n  std::cout << u << ' ' << v << '\\n';\r\n  for (int i = 0; i < u; ++i) {\r\n\
    \    std::cout << q[i];\r\n    if (i + 1 < u) {\r\n      std::cout << ' ';\r\n\
    \    }\r\n  }\r\n  std::cout << '\\n';\r\n  for (int i = 0; i < v; ++i) {\r\n\
    \    std::cout << r[i];\r\n    if (i + 1 < v) {\r\n      std::cout << ' ';\r\n\
    \    }\r\n  }\r\n  std::cout << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u591A\u9805\u5F0F\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\r\
    \n\r\n#include <iostream>\r\n#include <tuple>\r\n#include \"../../math/modint.hpp\"\
    \r\n#include \"../../math/polynomial.hpp\"\r\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  int n, m;\r\n  std::cin >>\
    \ n >> m;\r\n  Polynomial<ModInt> f(n - 1), g(m - 1);\r\n  for (int i = 0; i <\
    \ n; ++i) {\r\n    std::cin >> f[i];\r\n  }\r\n  for (int i = 0; i < m; ++i) {\r\
    \n    std::cin >> g[i];\r\n  }\r\n  Polynomial<ModInt> q, r;\r\n  std::tie(q,\
    \ r) = f.divide(g);\r\n  q.shrink();\r\n  r.shrink();\r\n  const int u = (q ==\
    \ Polynomial<ModInt>{0} ? 0 : q.degree() + 1);\r\n  const int v = (r == Polynomial<ModInt>{0}\
    \ ? 0 : r.degree() + 1);\r\n  std::cout << u << ' ' << v << '\\n';\r\n  for (int\
    \ i = 0; i < u; ++i) {\r\n    std::cout << q[i];\r\n    if (i + 1 < u) {\r\n \
    \     std::cout << ' ';\r\n    }\r\n  }\r\n  std::cout << '\\n';\r\n  for (int\
    \ i = 0; i < v; ++i) {\r\n    std::cout << r[i];\r\n    if (i + 1 < v) {\r\n \
    \     std::cout << ' ';\r\n    }\r\n  }\r\n  std::cout << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/polynomial.hpp
  isVerificationFile: true
  path: test/math/polynomial.test.cpp
  requiredBy: []
  timestamp: '2021-10-13 18:06:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/polynomial.test.cpp
- /verify/test/math/polynomial.test.cpp.html
title: "\u6570\u5B66/\u591A\u9805\u5F0F"
---
