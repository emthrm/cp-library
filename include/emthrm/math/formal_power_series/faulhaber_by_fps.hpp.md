---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/formal_power_series/bernoulli_number.hpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
  - icon: ':question:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n\n#line 1 \"include/emthrm/math/formal_power_series/bernoulli_number.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/formal_power_series/bernoulli_number.hpp\"\
    \n\n#line 1 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n#include <functional>\n#include <initializer_list>\n#include <iterator>\n#include\
    \ <numeric>\n#line 11 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct FormalPowerSeries {\n\
    \  std::vector<T> coef;\n\n  explicit FormalPowerSeries(const int deg = 0) : coef(deg\
    \ + 1, 0) {}\n  explicit FormalPowerSeries(const std::vector<T>& coef) : coef(coef)\
    \ {}\n  FormalPowerSeries(const std::initializer_list<T> init)\n      : coef(init.begin(),\
    \ init.end()) {}\n  template <typename InputIter>\n  explicit FormalPowerSeries(const\
    \ InputIter first, const InputIter last)\n      : coef(first, last) {}\n\n  inline\
    \ const T& operator[](const int term) const { return coef[term]; }\n  inline T&\
    \ operator[](const int term) { return coef[term]; }\n\n  using Mult = std::function<std::vector<T>(const\
    \ std::vector<T>&,\n                                            const std::vector<T>&)>;\n\
    \  using Sqrt = std::function<bool(const T&, T*)>;\n  static void set_mult(const\
    \ Mult mult) { get_mult() = mult; }\n  static void set_sqrt(const Sqrt sqrt) {\
    \ get_sqrt() = sqrt; }\n\n  void resize(const int deg) { coef.resize(deg + 1,\
    \ 0); }\n  void shrink() {\n    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\n\
    \  }\n  int degree() const { return std::ssize(coef) - 1; }\n\n  FormalPowerSeries&\
    \ operator=(const std::vector<T>& coef_) {\n    coef = coef_;\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator=(const FormalPowerSeries& x) = default;\n\n\
    \  FormalPowerSeries& operator+=(const FormalPowerSeries& x) {\n    const int\
    \ deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n    for (int\
    \ i = 0; i <= deg_x; ++i) {\n      coef[i] += x[i];\n    }\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator-=(const FormalPowerSeries& x) {\n    const\
    \ int deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n    for (int\
    \ i = 0; i <= deg_x; ++i) {\n      coef[i] -= x[i];\n    }\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator*=(const T x) {\n    for (T& e : coef) e *=\
    \ x;\n    return *this;\n  }\n  FormalPowerSeries& operator*=(const FormalPowerSeries&\
    \ x) {\n    return *this = get_mult()(coef, x.coef);\n  }\n  FormalPowerSeries&\
    \ operator/=(const T x) {\n    assert(x != 0);\n    return *this *= static_cast<T>(1)\
    \ / x;\n  }\n  FormalPowerSeries& operator/=(const FormalPowerSeries& x) {\n \
    \   const int n = degree() - x.degree() + 1;\n    if (n <= 0) return *this = FormalPowerSeries();\n\
    \    const std::vector<T> tmp = get_mult()(\n        std::vector<T>(coef.rbegin(),\
    \ std::next(coef.rbegin(), n)),\n        FormalPowerSeries(\n            x.coef.rbegin(),\n\
    \            std::next(x.coef.rbegin(), std::min(x.degree() + 1, n)))\n      \
    \  .inv(n - 1).coef);\n    return *this = FormalPowerSeries(std::prev(tmp.rend(),\
    \ n), tmp.rend());\n  }\n  FormalPowerSeries& operator%=(const FormalPowerSeries&\
    \ x) {\n    if (x.degree() == 0) return *this = FormalPowerSeries{0};\n    *this\
    \ -= *this / x * x;\n    resize(x.degree() - 1);\n    return *this;\n  }\n  FormalPowerSeries&\
    \ operator<<=(const int n) {\n    coef.insert(coef.begin(), n, 0);\n    return\
    \ *this;\n  }\n  FormalPowerSeries& operator>>=(const int n) {\n    if (degree()\
    \ < n) return *this = FormalPowerSeries();\n    coef.erase(coef.begin(), coef.begin()\
    \ + n);\n    return *this;\n  }\n\n  bool operator==(FormalPowerSeries x) const\
    \ {\n    x.shrink();\n    FormalPowerSeries y = *this;\n    y.shrink();\n    return\
    \ x.coef == y.coef;\n  }\n\n  FormalPowerSeries operator+() const { return *this;\
    \ }\n  FormalPowerSeries operator-() const {\n    FormalPowerSeries res = *this;\n\
    \    for (T& e : res.coef) e = -e;\n    return res;\n  }\n\n  FormalPowerSeries\
    \ operator+(const FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this)\
    \ += x;\n  }\n  FormalPowerSeries operator-(const FormalPowerSeries& x) const\
    \ {\n    return FormalPowerSeries(*this) -= x;\n  }\n  FormalPowerSeries operator*(const\
    \ T x) const {\n    return FormalPowerSeries(*this) *= x;\n  }\n  FormalPowerSeries\
    \ operator*(const FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this)\
    \ *= x;\n  }\n  FormalPowerSeries operator/(const T x) const {\n    return FormalPowerSeries(*this)\
    \ /= x;\n  }\n  FormalPowerSeries operator/(const FormalPowerSeries& x) const\
    \ {\n    return FormalPowerSeries(*this) /= x;\n  }\n  FormalPowerSeries operator%(const\
    \ FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this) %= x;\n \
    \ }\n  FormalPowerSeries operator<<(const int n) const {\n    return FormalPowerSeries(*this)\
    \ <<= n;\n  }\n  FormalPowerSeries operator>>(const int n) const {\n    return\
    \ FormalPowerSeries(*this) >>= n;\n  }\n\n  T horner(const T x) const {\n    return\
    \ std::accumulate(\n        coef.rbegin(), coef.rend(), static_cast<T>(0),\n \
    \       [x](const T l, const T r) -> T { return l * x + r; });\n  }\n\n  FormalPowerSeries\
    \ differential() const {\n    const int deg = degree();\n    assert(deg >= 0);\n\
    \    FormalPowerSeries res(std::max(deg - 1, 0));\n    for (int i = 1; i <= deg;\
    \ ++i) {\n      res[i - 1] = coef[i] * i;\n    }\n    return res;\n  }\n\n  FormalPowerSeries\
    \ exp(const int deg) const {\n    assert(coef[0] == 0);\n    const int n = coef.size();\n\
    \    const FormalPowerSeries one{1};\n    FormalPowerSeries res = one;\n    for\
    \ (int i = 1; i <= deg; i <<= 1) {\n      res *= FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             - res.log((i << 1) - 1) + one;\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n  FormalPowerSeries exp()\
    \ const { return exp(degree()); }\n\n  FormalPowerSeries inv(const int deg) const\
    \ {\n    assert(coef[0] != 0);\n    const int n = coef.size();\n    FormalPowerSeries\
    \ res{static_cast<T>(1) / coef[0]};\n    for (int i = 1; i <= deg; i <<= 1) {\n\
    \      res = res + res - res * res * FormalPowerSeries(\n          coef.begin(),\
    \ std::next(coef.begin(), std::min(n, i << 1)));\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n  FormalPowerSeries inv()\
    \ const { return inv(degree()); }\n\n  FormalPowerSeries log(const int deg) const\
    \ {\n    assert(coef[0] == 1);\n    FormalPowerSeries integrand = differential()\
    \ * inv(deg - 1);\n    integrand.resize(deg);\n    for (int i = deg; i > 0; --i)\
    \ {\n      integrand[i] = integrand[i - 1] / i;\n    }\n    integrand[0] = 0;\n\
    \    return integrand;\n  }\n  FormalPowerSeries log() const { return log(degree());\
    \ }\n\n  FormalPowerSeries pow(long long exponent, const int deg) const {\n  \
    \  const int n = coef.size();\n    if (exponent == 0) {\n      FormalPowerSeries\
    \ res(deg);\n      if (deg != -1) [[unlikely]] res[0] = 1;\n      return res;\n\
    \    }\n    assert(deg >= 0);\n    for (int i = 0; i < n; ++i) {\n      if (coef[i]\
    \ == 0) continue;\n      if (i > deg / exponent) break;\n      const long long\
    \ shift = exponent * i;\n      T tmp = 1, base = coef[i];\n      for (long long\
    \ e = exponent; e > 0; e >>= 1) {\n        if (e & 1) tmp *= base;\n        base\
    \ *= base;\n      }\n      const FormalPowerSeries res = ((*this >> i) / coef[i]).log(deg\
    \ - shift);\n      return ((res * exponent).exp(deg - shift) * tmp) << shift;\n\
    \    }\n    return FormalPowerSeries(deg);\n  }\n  FormalPowerSeries pow(const\
    \ long long exponent) const {\n    return pow(exponent, degree());\n  }\n\n  FormalPowerSeries\
    \ mod_pow(long long exponent,\n                            const FormalPowerSeries&\
    \ md) const {\n    const int deg = md.degree() - 1;\n    if (deg < 0) [[unlikely]]\
    \ return FormalPowerSeries(-1);\n    const FormalPowerSeries inv_rev_md =\n  \
    \      FormalPowerSeries(md.coef.rbegin(), md.coef.rend()).inv();\n    const auto\
    \ mod_mult = [&md, &inv_rev_md, deg](\n        FormalPowerSeries* multiplicand,\
    \ const FormalPowerSeries& multiplier)\n        -> void {\n      *multiplicand\
    \ *= multiplier;\n      if (deg < multiplicand->degree()) {\n        const int\
    \ n = multiplicand->degree() - deg;\n        const FormalPowerSeries quotient\
    \ =\n            FormalPowerSeries(multiplicand->coef.rbegin(),\n            \
    \                  std::next(multiplicand->coef.rbegin(), n))\n            * FormalPowerSeries(\n\
    \                  inv_rev_md.coef.begin(),\n                  std::next(inv_rev_md.coef.begin(),\
    \ std::min(deg + 2, n)));\n        *multiplicand -=\n            FormalPowerSeries(std::prev(quotient.coef.rend(),\
    \ n),\n                              quotient.coef.rend()) * md;\n        multiplicand->resize(deg);\n\
    \      }\n      multiplicand->shrink();\n    };\n    FormalPowerSeries res{1},\
    \ base = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) mod_mult(&res, base);\n      mod_mult(&base, base);\n    }\n    return\
    \ res;\n  }\n\n  FormalPowerSeries sqrt(const int deg) const {\n    const int\
    \ n = coef.size();\n    if (coef[0] == 0) {\n      for (int i = 1; i < n; ++i)\
    \ {\n        if (coef[i] == 0) continue;\n        if (i & 1) return FormalPowerSeries(-1);\n\
    \        const int shift = i >> 1;\n        if (deg < shift) break;\n        FormalPowerSeries\
    \ res = (*this >> i).sqrt(deg - shift);\n        if (res.coef.empty()) return\
    \ FormalPowerSeries(-1);\n        res <<= shift;\n        res.resize(deg);\n \
    \       return res;\n      }\n      return FormalPowerSeries(deg);\n    }\n  \
    \  T s;\n    if (!get_sqrt()(coef.front(), &s)) return FormalPowerSeries(-1);\n\
    \    FormalPowerSeries res{s};\n    const T half = static_cast<T>(1) / 2;\n  \
    \  for (int i = 1; i <= deg; i <<= 1) {\n      res = (FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             * res.inv((i << 1) - 1) + res) * half;\n    }\n    res.resize(deg);\n\
    \    return res;\n  }\n  FormalPowerSeries sqrt() const { return sqrt(degree());\
    \ }\n\n  FormalPowerSeries translate(const T c) const {\n    const int n = coef.size();\n\
    \    std::vector<T> fact(n, 1), inv_fact(n, 1);\n    for (int i = 1; i < n; ++i)\
    \ {\n      fact[i] = fact[i - 1] * i;\n    }\n    inv_fact[n - 1] = static_cast<T>(1)\
    \ / fact[n - 1];\n    for (int i = n - 1; i > 0; --i) {\n      inv_fact[i - 1]\
    \ = inv_fact[i] * i;\n    }\n    std::vector<T> g(n), ex(n);\n    for (int i =\
    \ 0; i < n; ++i) {\n      g[i] = coef[i] * fact[i];\n    }\n    std::reverse(g.begin(),\
    \ g.end());\n    T pow_c = 1;\n    for (int i = 0; i < n; ++i) {\n      ex[i]\
    \ = pow_c * inv_fact[i];\n      pow_c *= c;\n    }\n    const std::vector<T> conv\
    \ = get_mult()(g, ex);\n    FormalPowerSeries res(n - 1);\n    for (int i = 0;\
    \ i < n; ++i) {\n      res[i] = conv[n - 1 - i] * inv_fact[i];\n    }\n    return\
    \ res;\n  }\n\n private:\n  static Mult& get_mult() {\n    static Mult mult =\
    \ [](const std::vector<T>& a, const std::vector<T>& b)\n        -> std::vector<T>\
    \ {\n      const int n = a.size(), m = b.size();\n      std::vector<T> res(n +\
    \ m - 1, 0);\n      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j <\
    \ m; ++j) {\n          res[i + j] += a[i] * b[j];\n        }\n      }\n      return\
    \ res;\n    };\n    return mult;\n  }\n  static Sqrt& get_sqrt() {\n    static\
    \ Sqrt sqrt = [](const T&, T*) -> bool { return false; };\n    return sqrt;\n\
    \  }\n};\n\n}  // namespace emthrm\n\n\n#line 7 \"include/emthrm/math/formal_power_series/bernoulli_number.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> bernoulli_number(const\
    \ int n) {\n  FormalPowerSeries<T> bernoulli(n);\n  bernoulli[0] = 1;\n  for (int\
    \ i = 1; i <= n; ++i) {\n    bernoulli[i] = bernoulli[i - 1] / (i + 1);\n  }\n\
    \  bernoulli = bernoulli.inv(n);\n  T fact = 1;\n  for (int i = 0; i <= n; ++i)\
    \ {\n    bernoulli[i] *= fact;\n    fact *= i + 1;\n  }\n  return bernoulli.coef;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\
    \n\n#ifndef ARBITRARY_MODINT\n#line 6 \"include/emthrm/math/modint.hpp\"\n#endif\n\
    #include <compare>\n#include <iostream>\n// #include <numeric>\n#include <utility>\n\
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
    }  // namespace emthrm\n\n\n#line 9 \"include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <unsigned int T>\nMInt<T> faulhaber_by_fps(const\
    \ long long n, const int k) {\n  using ModInt = MInt<T>;\n  if (n <= 1) [[unlikely]]\
    \ return 0;\n  if (k == 0) [[unlikely]] return n - 1;\n  ModInt::init(k + 1);\n\
    \  const std::vector<ModInt> bernoulli = bernoulli_number<ModInt>(k);\n  ModInt\
    \ res = 0, p = 1;\n  for (int i = k; i >= 0; --i) {\n    p *= n;\n    res += ModInt::nCk(k\
    \ + 1, i) * bernoulli[i] * p;\n  }\n  return res / (k + 1);\n}\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_\n#define EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_\n\
    \n#include <cassert>\n#include <vector>\n\n#include \"emthrm/math/formal_power_series/bernoulli_number.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\ntemplate <unsigned\
    \ int T>\nMInt<T> faulhaber_by_fps(const long long n, const int k) {\n  using\
    \ ModInt = MInt<T>;\n  if (n <= 1) [[unlikely]] return 0;\n  if (k == 0) [[unlikely]]\
    \ return n - 1;\n  ModInt::init(k + 1);\n  const std::vector<ModInt> bernoulli\
    \ = bernoulli_number<ModInt>(k);\n  ModInt res = 0, p = 1;\n  for (int i = k;\
    \ i >= 0; --i) {\n    p *= n;\n    res += ModInt::nCk(k + 1, i) * bernoulli[i]\
    \ * p;\n  }\n  return res / (k + 1);\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/bernoulli_number.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
  requiredBy: []
  timestamp: '2023-05-13 18:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
documentation_of: include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
layout: document
title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F (Faulhaber's\
  \ formula) \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
---

# ファウルハーバーの公式 (Faulhaber's formula)

$$
  S_k(n) \mathrel{:=} \sum_{i = 1}^{n - 1} i^k
$$

と定義すると

$$
  S_k(n + 1) = \dfrac{1}{k + 1} \sum_{i = 0}^k \binom{k + 1}{i} B_i n^{k + 1 - i}
$$

が成り立つ。ここで $B$ は[ベルヌーイ数](bernoulli_number)である。


## 時間計算量

||時間計算量|
|:--|:--|
|形式的冪級数版|$O(K\log{K})$|
|ラグランジュ補間版|$O(K \log{\max{\lbrace K, M \rbrace}})$|


## 仕様

### 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <unsigned int T>`<br>`MInt<T> faulhaber_by_fps(const long long n, const int k);`|$S_k(n)$|


### ラグランジュ補間版

|名前|戻り値|
|:--|:--|
|`template <unsigned int T>`<br>`MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k);`|$S_k(n)$|


## 参考文献

- Jacob Bernoulli: Ars Conjectandi (1713).
- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Submissons

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
