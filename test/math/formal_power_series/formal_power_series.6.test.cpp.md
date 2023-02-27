---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB (number theoretic transform) / \u9AD8\u901F\u5270\
      \u4F59\u5909\u63DB (fast modulo transform)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59 (quadratic residue)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570\uFF08\u5E73\u65B9\u6839\uFF09"
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
  bundledCode: "#line 1 \"test/math/formal_power_series/formal_power_series.6.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570\uFF08\u5E73\u65B9\u6839\uFF09\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n */\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #include <utility>\n#line 10 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    #line 6 \"include/emthrm/math/modint.hpp\"\n#endif\n#include <compare>\n#line\
    \ 9 \"include/emthrm/math/modint.hpp\"\n// #include <numeric>\n#line 12 \"include/emthrm/math/modint.hpp\"\
    \n\nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate <int M>\nstruct MInt\
    \ {\n  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x\
    \ >= 0 ? x % M : x % M + M) {}\n\n  static constexpr int get_mod() { return M;\
    \ }\n  static void set_mod(const int divisor) { assert(divisor == M); }\n\n  static\
    \ void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[M % i] * (M / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = M; b;) {\n   \
    \   const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
    \ -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const int n)\
    \ {\n    static std::vector<MInt> factorial{1};\n    const int prev = factorial.size();\n\
    \    if (n >= prev) {\n      factorial.resize(n + 1);\n      for (int i = prev;\
    \ i <= n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n      }\n    }\n\
    \    return factorial[n];\n  }\n\n  static MInt fact_inv(const int n) {\n    static\
    \ std::vector<MInt> f_inv{1};\n    const int prev = f_inv.size();\n    if (n >=\
    \ prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n    \
    \  for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n  \
    \    }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fact(n) * (n\
    \ - k < k ? fact_inv(k) * fact_inv(n - k) :\n                                \
    \  fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const int n, const\
    \ int k) {\n    return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n\
    \  }\n  static MInt nHk(const int n, const int k) {\n    return n < 0 || k < 0\
    \ ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n  static MInt large_nCk(long\
    \ long n, const int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n\
    \    MInt res = 1;\n    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) *\
    \ n--;\n    }\n    return res;\n  }\n\n  MInt pow(long long exponent) const {\n\
    \    MInt res = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n\
    \      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n\
    \  }\n\n  MInt& operator+=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += x.v, M)) v -= M;\n    return *this;\n  }\n  MInt& operator-=(const MInt&\
    \ x) {\n    if (std::cmp_greater_equal(v += M - x.v, M)) v -= M;\n    return *this;\n\
    \  }\n  MInt& operator*=(const MInt& x) {\n    v = static_cast<unsigned long long>(v)\
    \ * x.v % M;\n    return *this;\n  }\n  MInt& operator/=(const MInt& x) { return\
    \ *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x) const = default;\n\
    \n  MInt& operator++() {\n    if (std::cmp_equal(++v, M)) v = 0;\n    return *this;\n\
    \  }\n  MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n  \
    \  return res;\n  }\n  MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  MInt operator--(int) {\n    const MInt res = *this;\n\
    \    --*this;\n    return res;\n  }\n\n  MInt operator+() const { return *this;\
    \ }\n  MInt operator-() const { return MInt(v ? M - v : 0); }\n\n  MInt operator+(const\
    \ MInt& x) const { return MInt(*this) += x; }\n  MInt operator-(const MInt& x)\
    \ const { return MInt(*this) -= x; }\n  MInt operator*(const MInt& x) const {\
    \ return MInt(*this) *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this)\
    \ /= x; }\n\n  friend std::ostream& operator<<(std::ostream& os, const MInt& x)\
    \ {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n};\n#else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n\
    \  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0\
    \ ? x % mod() : x % mod() + mod()) {}\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const int divisor) { mod() = divisor; }\n\n  static\
    \ void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * (mod() / i);\n      }\n      return\
    \ inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b =\
    \ mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a -= q *\
    \ b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n  static\
    \ MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n    const\
    \ int prev = factorial.size();\n    if (n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    const int prev = f_inv.size();\n\
    \    if (n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fact(n) * (n\
    \ - k < k ? fact_inv(k) * fact_inv(n - k) :\n                                \
    \  fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const int n, const\
    \ int k) {\n    return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n\
    \  }\n  static MInt nHk(const int n, const int k) {\n    return n < 0 || k < 0\
    \ ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n  static MInt large_nCk(long\
    \ long n, const int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n\
    \    MInt res = 1;\n    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) *\
    \ n--;\n    }\n    return res;\n  }\n\n  MInt pow(long long exponent) const {\n\
    \    MInt res = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n\
    \      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n\
    \  }\n\n  MInt& operator+=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += x.v, mod())) v -= mod();\n    return *this;\n  }\n  MInt& operator-=(const\
    \ MInt& x) {\n    if (std::cmp_greater_equal(v += mod() - x.v, mod())) v -= mod();\n\
    \    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v = static_cast<unsigned\
    \ long long>(v) * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (std::cmp_equal(++v, mod()))\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return MInt(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static int& mod() {\n    static int divisor = 0;\n\
    \    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n}  // namespace\
    \ emthrm\n\n\n#line 12 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int T>\nstruct NumberTheoreticTransform {\n\
    \  using ModInt = MInt<T>;\n\n  NumberTheoreticTransform() {\n    for (int i =\
    \ 0; i < 23; ++i) {\n      if (primes[i][0] == ModInt::get_mod()) [[unlikely]]\
    \ {\n        n_max = 1 << primes[i][2];\n        root = ModInt(primes[i][1]).pow((primes[i][0]\
    \ - 1) >> primes[i][2]);\n        return;\n      }\n    }\n    assert(false);\n\
    \  }\n\n  template <typename U>\n  std::vector<ModInt> dft(const std::vector<U>&\
    \ a) {\n    std::vector<ModInt> b(std::bit_ceil(a.size()), 0);\n    std::copy(a.begin(),\
    \ a.end(), b.begin());\n    calc(&b);\n    return b;\n  }\n\n  void idft(std::vector<ModInt>*\
    \ a) {\n    assert(std::has_single_bit(a->size()));\n    calc(a);\n    std::reverse(std::next(a->begin()),\
    \ a->end());\n    const int n = a->size();\n    const ModInt inv_n = ModInt::inv(n);\n\
    \    for (int i = 0; i < n; ++i) {\n      (*a)[i] *= inv_n;\n    }\n  }\n\n  template\
    \ <typename U>\n  std::vector<ModInt> convolution(const std::vector<U>& a,\n \
    \                                 const std::vector<U>& b) {\n    const int a_size\
    \ = a.size(), b_size = b.size();\n    const int c_size = a_size + b_size - 1;\n\
    \    const int n = std::bit_ceil(static_cast<unsigned int>(c_size));\n    std::vector<ModInt>\
    \ c(n, 0), d(n, 0);\n    std::copy(a.begin(), a.end(), c.begin());\n    calc(&c);\n\
    \    std::copy(b.begin(), b.end(), d.begin());\n    calc(&d);\n    for (int i\
    \ = 0; i < n; ++i) {\n      c[i] *= d[i];\n    }\n    idft(&c);\n    c.resize(c_size);\n\
    \    return c;\n  }\n\n private:\n  const int primes[23][3]{\n    {16957441, 329,\
    \ 14},\n    {17006593, 26, 15},\n    {19529729, 770, 17},\n    {167772161, 3,\
    \ 25},\n    {469762049, 3, 26},\n    {645922817, 3, 23},\n    {897581057, 3, 23},\n\
    \    {924844033, 5, 21},\n    {935329793, 3, 22},\n    {943718401, 7, 22},\n \
    \   {950009857, 7, 21},\n    {962592769, 7, 21},\n    {975175681, 17, 21},\n \
    \   {976224257, 3, 20},\n    {985661441, 3, 22},\n    {998244353, 3, 23},\n  \
    \  {1004535809, 3, 21},\n    {1007681537, 3, 20},\n    {1012924417, 5, 21},\n\
    \    {1045430273, 3, 20},\n    {1051721729, 6, 20},\n    {1053818881, 7, 20},\n\
    \    {1224736769, 3, 24}\n  };\n\n  int n_max;\n  ModInt root;\n  std::vector<int>\
    \ butterfly{0};\n  std::vector<std::vector<ModInt>> omega{{1}};\n\n  void calc(std::vector<ModInt>*\
    \ a) {\n    const int n = a->size(), prev_n = butterfly.size();\n    if (n > prev_n)\
    \ {\n      assert(n <= n_max);\n      butterfly.resize(n);\n      const int prev_lg\
    \ = omega.size(), lg = std::countr_zero(a->size());\n      for (int i = 1; i <\
    \ prev_n; ++i) {\n        butterfly[i] <<= lg - prev_lg;\n      }\n      for (int\
    \ i = prev_n; i < n; ++i) {\n        butterfly[i] = (butterfly[i >> 1] >> 1) |\
    \ ((i & 1) << (lg - 1));\n      }\n      omega.resize(lg);\n      for (int i =\
    \ prev_lg; i < lg; ++i) {\n        omega[i].resize(1 << i);\n        const ModInt\
    \ tmp = root.pow((ModInt::get_mod() - 1) >> (i + 1));\n        for (int j = 0;\
    \ j < (1 << (i - 1)); ++j) {\n          omega[i][j << 1] = omega[i - 1][j];\n\
    \          omega[i][(j << 1) + 1] = omega[i - 1][j] * tmp;\n        }\n      }\n\
    \    }\n    const int shift =\n        std::countr_zero(butterfly.size()) - std::countr_zero(a->size());\n\
    \    for (int i = 0; i < n; ++i) {\n      const int j = butterfly[i] >> shift;\n\
    \      if (i < j) std::swap((*a)[i], (*a)[j]);\n    }\n    for (int block = 1,\
    \ den = 0; block < n; block <<= 1, ++den) {\n      for (int i = 0; i < n; i +=\
    \ (block << 1)) {\n        for (int j = 0; j < block; ++j) {\n          const\
    \ ModInt tmp = (*a)[i + j + block] * omega[den][j];\n          (*a)[i + j + block]\
    \ = (*a)[i + j] - tmp;\n          (*a)[i + j] += tmp;\n        }\n      }\n  \
    \  }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n#include <functional>\n#include <initializer_list>\n#line 9 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n#include <numeric>\n#line 11 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
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
    \  }\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/mod_sqrt.hpp\"\
    \n\n\n\n#include <random>\n\n#line 1 \"include/emthrm/math/mod_pow.hpp\"\n\n\n\
    \nnamespace emthrm {\n\nlong long mod_pow(long long x, long long n, const int\
    \ m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>=\
    \ 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 7 \"include/emthrm/math/mod_sqrt.hpp\"\
    \n\nnamespace emthrm {\n\nlong long mod_sqrt(long long a, const int p) {\n  if\
    \ ((a %= p) < 0) a += p;\n  if (a == 0) [[unlikely]] return 0;\n  if (p == 2)\
    \ [[unlikely]] return 1;\n  if (mod_pow(a, (p - 1) >> 1, p) == p - 1) return -1;\n\
    \  if (p % 4 == 3) return mod_pow(a, (p + 1) >> 2, p);\n  int s = 1, q = (p -\
    \ 1) >> 1;\n  for (; !(q & 1); q >>= 1) {\n    ++s;\n  }\n  static std::mt19937_64\
    \ engine(std::random_device {} ());\n  std::uniform_int_distribution<> dist(2,\
    \ p - 1);\n  long long z;\n  do {\n    z = dist(engine);\n  } while (mod_pow(z,\
    \ (p - 1) >> 1, p) == 1);\n  int m = s;\n  long long c = mod_pow(z, q, p), r =\
    \ mod_pow(a, (q - 1) >> 1, p);\n  long long t = a * r % p * r % p;\n  r = (r *\
    \ a) % p;\n  while (t != 1) {\n    long long t2 = t * t % p;\n    for (int i =\
    \ 1; i < m; ++i) {\n      if (t2 == 1) {\n        const long long b = mod_pow(c,\
    \ 1 << (m - i - 1), p);\n        m = i;\n        r = (r * b) % p;\n        c =\
    \ b * b % p;\n        t = (t * c) % p;\n        break;\n      }\n      t2 = (t2\
    \ * t2) % p;\n    }\n  }\n  return r;\n}\n\n}  // namespace emthrm\n\n\n#line\
    \ 14 \"test/math/formal_power_series/formal_power_series.6.test.cpp\"\n\nint main()\
    \ {\n  constexpr int MOD = 998244353;\n  using ModInt = emthrm::MInt<MOD>;\n \
    \ emthrm::FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>&\
    \ a, const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n     \
    \   static emthrm::NumberTheoreticTransform<MOD> ntt;\n        return ntt.convolution(a,\
    \ b);\n      });\n  emthrm::FormalPowerSeries<ModInt>::set_sqrt(\n      [](const\
    \ ModInt& a, ModInt* res) -> bool {\n        const long long ans = emthrm::mod_sqrt(a.v,\
    \ ModInt::get_mod());\n        if (ans == -1) {\n          return false;\n   \
    \     } else {\n          *res = ans;\n          return true;\n        }\n   \
    \   });\n  int n;\n  std::cin >> n;\n  emthrm::FormalPowerSeries<ModInt> a(n -\
    \ 1);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  a = a.sqrt(n\
    \ - 1);\n  if (a.coef.empty()) {\n    std::cout << \"-1\\n\";\n  } else {\n  \
    \  for (int i = 0; i < n; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1 ==\
    \ n];\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570\uFF08\u5E73\u65B9\u6839\uFF09\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n */\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"emthrm/math/mod_sqrt.hpp\"\n#include \"emthrm/math/modint.hpp\"\n\nint main()\
    \ {\n  constexpr int MOD = 998244353;\n  using ModInt = emthrm::MInt<MOD>;\n \
    \ emthrm::FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>&\
    \ a, const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n     \
    \   static emthrm::NumberTheoreticTransform<MOD> ntt;\n        return ntt.convolution(a,\
    \ b);\n      });\n  emthrm::FormalPowerSeries<ModInt>::set_sqrt(\n      [](const\
    \ ModInt& a, ModInt* res) -> bool {\n        const long long ans = emthrm::mod_sqrt(a.v,\
    \ ModInt::get_mod());\n        if (ans == -1) {\n          return false;\n   \
    \     } else {\n          *res = ans;\n          return true;\n        }\n   \
    \   });\n  int n;\n  std::cin >> n;\n  emthrm::FormalPowerSeries<ModInt> a(n -\
    \ 1);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  a = a.sqrt(n\
    \ - 1);\n  if (a.coef.empty()) {\n    std::cout << \"-1\\n\";\n  } else {\n  \
    \  for (int i = 0; i < n; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1 ==\
    \ n];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/number_theoretic_transform.hpp
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  - include/emthrm/math/mod_sqrt.hpp
  - include/emthrm/math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.6.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 16:57:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/formal_power_series.6.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/formal_power_series.6.test.cpp
- /verify/test/math/formal_power_series/formal_power_series.6.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570\uFF08\u5E73\u65B9\u6839\uFF09"
---
