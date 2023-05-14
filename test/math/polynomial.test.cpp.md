---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':question:'
    path: include/emthrm/math/polynomial.hpp
    title: "\u591A\u9805\u5F0F (polynomial)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://judge.yosupo.jp/problem/division_of_polynomials
    document_title: "\u6570\u5B66/\u591A\u9805\u5F0F"
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "#line 1 \"test/math/polynomial.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u591A\u9805\u5F0F\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/division_of_polynomials\n */\n\n#include\
    \ <iostream>\n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\
    \n// #include <numeric>\n#include <utility>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\n#ifndef ARBITRARY_MODINT\ntemplate <unsigned int M>\nstruct MInt {\n  unsigned\
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
    }  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/polynomial.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iterator>\n#include <numeric>\n#line 12 \"include/emthrm/math/polynomial.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Polynomial {\n  std::vector<T>\
    \ coef;\n\n  explicit Polynomial(const int deg = 0) : coef(deg + 1, 0) {}\n  explicit\
    \ Polynomial(const std::vector<T>& coef) : coef(coef) {}\n  Polynomial(const std::initializer_list<T>\
    \ init)\n      : coef(init.begin(), init.end()) {}\n  template <typename InputIter>\n\
    \  explicit Polynomial(const InputIter first, const InputIter last)\n      : coef(first,\
    \ last) {}\n\n  inline const T& operator[](const int term) const { return coef[term];\
    \ }\n  inline T& operator[](const int term) { return coef[term]; }\n\n  using\
    \ Mult = std::function<std::vector<T>(const std::vector<T>&,\n               \
    \                             const std::vector<T>&)>;\n  static void set_mult(const\
    \ Mult mult) { get_mult() = mult; }\n\n  void resize(const int deg) { coef.resize(deg\
    \ + 1, 0); }\n  void shrink() {\n    while (coef.size() > 1 && coef.back() ==\
    \ 0) coef.pop_back();\n  }\n  int degree() const { return std::ssize(coef) - 1;\
    \ }\n\n  Polynomial& operator=(const std::vector<T>& coef_) {\n    coef = coef_;\n\
    \    return *this;\n  }\n  Polynomial& operator=(const Polynomial& x) = default;\n\
    \n  Polynomial& operator+=(const Polynomial& x) {\n    const int deg_x = x.degree();\n\
    \    if (deg_x > degree()) resize(deg_x);\n    for (int i = 0; i <= deg_x; ++i)\
    \ {\n      coef[i] += x[i];\n    }\n    return *this;\n  }\n  Polynomial& operator-=(const\
    \ Polynomial& x) {\n    const int deg_x = x.degree();\n    if (deg_x > degree())\
    \ resize(deg_x);\n    for (int i = 0; i <= deg_x; ++i) {\n      coef[i] -= x[i];\n\
    \    }\n    return *this;\n  }\n  Polynomial& operator*=(const T x) {\n    for\
    \ (T& e : coef) e *= x;\n    return *this;\n  }\n  Polynomial& operator*=(const\
    \ Polynomial& x) {\n    return *this = get_mult()(coef, x.coef);\n  }\n  Polynomial&\
    \ operator/=(const T x) {\n    assert(x != 0);\n    return *this *= static_cast<T>(1)\
    \ / x;\n  }\n  std::pair<Polynomial, Polynomial> divide(Polynomial x) const {\n\
    \    x.shrink();\n    Polynomial rem = *this;\n    const int n = rem.degree(),\
    \ m = x.degree(), deg = n - m;\n    if (deg < 0) return {Polynomial{0}, rem};\n\
    \    Polynomial quo(deg);\n    for (int i = 0; i <= deg; ++i) {\n      quo[deg\
    \ - i] = rem[n - i] / x[m];\n      for (int j = 0; j <= m; ++j) {\n        rem[n\
    \ - i - j] -= x[m - j] * quo[deg - i];\n      }\n    }\n    rem.resize(deg);\n\
    \    return {quo, rem};\n  }\n  Polynomial& operator/=(const Polynomial& x) {\n\
    \    return *this = divide(x).first;\n  }\n  Polynomial& operator%=(const Polynomial&\
    \ x) {\n    return *this = divide(x).second;\n  }\n  Polynomial& operator<<=(const\
    \ int n) {\n    coef.insert(coef.begin(), n, 0);\n    return *this;\n  }\n\n \
    \ bool operator==(Polynomial x) const {\n    x.shrink();\n    Polynomial y = *this;\n\
    \    y.shrink();\n    return x.coef == y.coef;\n  }\n\n  Polynomial operator+()\
    \ const { return *this; }\n  Polynomial operator-() const {\n    Polynomial res\
    \ = *this;\n    for (T& e : res.coef) e = -e;\n    return res;\n  }\n\n  Polynomial\
    \ operator+(const Polynomial& x) const {\n    return Polynomial(*this) += x;\n\
    \  }\n  Polynomial operator-(const Polynomial& x) const {\n    return Polynomial(*this)\
    \ -= x;\n  }\n  Polynomial operator*(const T x) const {\n    return Polynomial(*this)\
    \ *= x;\n  }\n  Polynomial operator*(const Polynomial& x) const {\n    return\
    \ Polynomial(*this) *= x;\n  }\n  Polynomial operator/(const T x) const { return\
    \ Polynomial(*this) /= x; }\n  Polynomial operator/(const Polynomial& x) const\
    \ {\n    return Polynomial(*this) /= x;\n  }\n  Polynomial operator%(const Polynomial&\
    \ x) const {\n    return Polynomial(*this) %= x;\n  }\n  Polynomial operator<<(const\
    \ int n) const { return Polynomial(*this) <<= n; }\n\n  T horner(const T x) const\
    \ {\n    return std::accumulate(\n        coef.rbegin(), coef.rend(), static_cast<T>(0),\n\
    \        [x](const T l, const T r) -> T { return l * x + r; });\n  }\n\n  Polynomial\
    \ differential() const {\n    const int deg = degree();\n    assert(deg >= 0);\n\
    \    Polynomial res(std::max(deg - 1, 0));\n    for (int i = 1; i <= deg; ++i)\
    \ {\n      res[i - 1] = coef[i] * i;\n    }\n    return res;\n  }\n\n  Polynomial\
    \ pow(int exponent) const {\n    Polynomial res{1}, base = *this;\n    for (;\
    \ exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res *= base;\n    \
    \  base *= base;\n    }\n    return res;\n  }\n\n  Polynomial translate(const\
    \ T c) const {\n    const int n = coef.size();\n    std::vector<T> fact(n, 1),\
    \ inv_fact(n, 1);\n    for (int i = 1; i < n; ++i) {\n      fact[i] = fact[i -\
    \ 1] * i;\n    }\n    inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];\n   \
    \ for (int i = n - 1; i > 0; --i) {\n      inv_fact[i - 1] = inv_fact[i] * i;\n\
    \    }\n    std::vector<T> g(n), ex(n);\n    for (int i = 0; i < n; ++i) {\n \
    \     g[i] = coef[i] * fact[i];\n    }\n    std::reverse(g.begin(), g.end());\n\
    \    T pow_c = 1;\n    for (int i = 0; i < n; ++i) {\n      ex[i] = pow_c * inv_fact[i];\n\
    \      pow_c *= c;\n    }\n    const std::vector<T> conv = get_mult()(g, ex);\n\
    \    Polynomial res(n - 1);\n    for (int i = 0; i < n; ++i) {\n      res[i] =\
    \ conv[n - 1 - i] * inv_fact[i];\n    }\n    return res;\n  }\n\n private:\n \
    \ static Mult& get_mult() {\n    static Mult mult = [](const std::vector<T>& a,\
    \ const std::vector<T>& b)\n        -> std::vector<T> {\n      const int n = a.size(),\
    \ m = b.size();\n      std::vector<T> res(n + m - 1, 0);\n      for (int i = 0;\
    \ i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n          res[i + j] +=\
    \ a[i] * b[j];\n        }\n      }\n      return res;\n    };\n    return mult;\n\
    \  }\n};\n\n}  // namespace emthrm\n\n\n#line 12 \"test/math/polynomial.test.cpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, m;\n  std::cin\
    \ >> n >> m;\n  emthrm::Polynomial<ModInt> f(n - 1), g(m - 1);\n  for (int i =\
    \ 0; i < n; ++i) {\n    std::cin >> f[i];\n  }\n  for (int i = 0; i < m; ++i)\
    \ {\n    std::cin >> g[i];\n  }\n  auto [q, r] = f.divide(g);\n  q.shrink();\n\
    \  r.shrink();\n  const int u = (q == emthrm::Polynomial<ModInt>{0} ? 0 : q.degree()\
    \ + 1);\n  const int v = (r == emthrm::Polynomial<ModInt>{0} ? 0 : r.degree()\
    \ + 1);\n  std::cout << u << ' ' << v << '\\n';\n  for (int i = 0; i < u; ++i)\
    \ {\n    std::cout << q[i];\n    if (i + 1 < u) std::cout << ' ';\n  }\n  std::cout\
    \ << '\\n';\n  for (int i = 0; i < v; ++i) {\n    std::cout << r[i];\n    if (i\
    \ + 1 < v) std::cout << ' ';\n  }\n  std::cout << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u591A\u9805\u5F0F\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/division_of_polynomials\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/math/modint.hpp\"\n#include \"\
    emthrm/math/polynomial.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n\
    \  int n, m;\n  std::cin >> n >> m;\n  emthrm::Polynomial<ModInt> f(n - 1), g(m\
    \ - 1);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> f[i];\n  }\n  for (int\
    \ i = 0; i < m; ++i) {\n    std::cin >> g[i];\n  }\n  auto [q, r] = f.divide(g);\n\
    \  q.shrink();\n  r.shrink();\n  const int u = (q == emthrm::Polynomial<ModInt>{0}\
    \ ? 0 : q.degree() + 1);\n  const int v = (r == emthrm::Polynomial<ModInt>{0}\
    \ ? 0 : r.degree() + 1);\n  std::cout << u << ' ' << v << '\\n';\n  for (int i\
    \ = 0; i < u; ++i) {\n    std::cout << q[i];\n    if (i + 1 < u) std::cout <<\
    \ ' ';\n  }\n  std::cout << '\\n';\n  for (int i = 0; i < v; ++i) {\n    std::cout\
    \ << r[i];\n    if (i + 1 < v) std::cout << ' ';\n  }\n  std::cout << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/polynomial.hpp
  isVerificationFile: true
  path: test/math/polynomial.test.cpp
  requiredBy: []
  timestamp: '2023-05-13 18:14:57+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/math/polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/polynomial.test.cpp
- /verify/test/math/polynomial.test.cpp.html
title: "\u6570\u5B66/\u591A\u9805\u5F0F"
---
