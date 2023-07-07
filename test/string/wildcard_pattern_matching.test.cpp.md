---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB (number theoretic transform) / \u9AD8\u901F\u5270\
      \u4F59\u5909\u63DB (fast modulo transform)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: include/emthrm/string/wildcard_pattern_matching.hpp
    title: "\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9 ? \u3092\u7528\u3044\u305F\u30D1\
      \u30BF\u30FC\u30F3\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc305/tasks/abc305_h
    document_title: "\u6587\u5B57\u5217/\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9\
      \ ? \u3092\u7528\u3044\u305F\u30D1\u30BF\u30FC\u30F3\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
    links:
    - https://atcoder.jp/contests/abc305/tasks/abc305_h
  bundledCode: "#line 1 \"test/string/wildcard_pattern_matching.test.cpp\"\n/*\n *\
    \ @title \u6587\u5B57\u5217/\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9 ? \u3092\
    \u7528\u3044\u305F\u30D1\u30BF\u30FC\u30F3\u30DE\u30C3\u30C1\u30F3\u30B0\n *\n\
    \ * verification-helper: PROBLEM https://atcoder.jp/contests/abc305/tasks/abc305_h\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/string/wildcard_pattern_matching.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <map>\n#include <numeric>\n\
    #line 9 \"include/emthrm/string/wildcard_pattern_matching.hpp\"\n#include <tuple>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n\n\n\n#if __has_include(<atcoder/convolution>)\n# include <atcoder/convolution>\n\
    # include <atcoder/modint>\n#else\n#line 9 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n# include <bit>\n#line 11 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n# include <iterator>\n#line 13 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n# include <utility>\n#endif\n#line 16 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    #line 6 \"include/emthrm/math/modint.hpp\"\n#endif\n#include <compare>\n#line\
    \ 9 \"include/emthrm/math/modint.hpp\"\n// #include <numeric>\n#include <utility>\n\
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
    }  // namespace emthrm\n\n\n#line 18 \"include/emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n\nnamespace emthrm {\n\n#if __has_include(<atcoder/convolution>)\n\ntemplate\
    \ <unsigned int T>\nstruct NumberTheoreticTransform {\n  using ModInt = MInt<T>;\n\
    \n  NumberTheoreticTransform() = default;\n\n  template <typename U>\n  std::vector<ModInt>\
    \ dft(const std::vector<U>& a);\n\n  void idft(std::vector<ModInt>* a);\n\n  template\
    \ <typename U>\n  std::vector<ModInt> convolution(\n      const std::vector<U>&\
    \ a, const std::vector<U>& b) const {\n    const int a_size = a.size(), b_size\
    \ = b.size();\n    std::vector<atcoder::static_modint<T>> c(a_size), d(b_size);\n\
    \    for (int i = 0; i < a_size; ++i) {\n      c[i] = atcoder::static_modint<T>::raw(ModInt(a[i]).v);\n\
    \    }\n    for (int i = 0; i < b_size; ++i) {\n      d[i] = atcoder::static_modint<T>::raw(ModInt(b[i]).v);\n\
    \    }\n    c = atcoder::convolution(c, d);\n    const int c_size = c.size();\n\
    \    std::vector<ModInt> res(c_size);\n    for (int i = 0; i < c_size; ++i) {\n\
    \      res[i] = ModInt::raw(c[i].val());\n    }\n    return res;\n  }\n};\n\n\
    #else  // __has_include(<atcoder/convolution>)\n\ntemplate <unsigned int T>\n\
    struct NumberTheoreticTransform {\n  using ModInt = MInt<T>;\n\n  NumberTheoreticTransform()\n\
    \      : n_max(1 << init().first), root(ModInt::raw(init().second)) {}\n\n  template\
    \ <typename U>\n  std::vector<ModInt> dft(const std::vector<U>& a) {\n    std::vector<ModInt>\
    \ b(std::bit_ceil(a.size()), 0);\n    std::ranges::copy(a, b.begin());\n    calc(&b);\n\
    \    return b;\n  }\n\n  void idft(std::vector<ModInt>* a) {\n    assert(std::has_single_bit(a->size()));\n\
    \    calc(a);\n    std::reverse(std::next(a->begin()), a->end());\n    const int\
    \ n = a->size();\n    const ModInt inv_n = ModInt::inv(n);\n    for (int i = 0;\
    \ i < n; ++i) {\n      (*a)[i] *= inv_n;\n    }\n  }\n\n  template <typename U>\n\
    \  std::vector<ModInt> convolution(\n      const std::vector<U>& a, const std::vector<U>&\
    \ b) const {\n    const int a_size = a.size(), b_size = b.size();\n    const int\
    \ c_size = a_size + b_size - 1;\n    if (std::min(a_size, b_size) <= 60) {\n \
    \     std::vector<ModInt> c(c_size, 0);\n      if (a_size > b_size) {\n      \
    \  for (int i = 0; i < a_size; ++i) {\n          for (int j = 0; j < b_size; ++j)\
    \ {\n            c[i + j] += ModInt(a[i]) * b[j];\n          }\n        }\n  \
    \    } else {\n        for (int j = 0; j < b_size; ++j) {\n          for (int\
    \ i = 0; i < a_size; ++i) {\n            c[i + j] += ModInt(b[j]) * a[i];\n  \
    \        }\n        }\n      }\n      return c;\n    }\n    const int n = std::bit_ceil(static_cast<unsigned\
    \ int>(c_size));\n    std::vector<ModInt> c(n, 0), d(n, 0);\n    std::ranges::copy(a,\
    \ c.begin());\n    calc(&c);\n    std::ranges::copy(b, d.begin());\n    calc(&d);\n\
    \    for (int i = 0; i < n; ++i) {\n      c[i] *= d[i];\n    }\n    idft(&c);\n\
    \    c.resize(c_size);\n    return c;\n  }\n\n private:\n  static std::pair<int,\
    \ int> init() {\n    static const std::map<int, std::pair<int, int>> primes{\n\
    \        {16957441, {14, 102066830}},  // 329\n        {17006593, {15, 608991743}},\
    \  // 26\n        {19529729, {17, 927947839}},  // 770\n        {167772161, {25,\
    \ 243}},  // 3\n        {469762049, {26, 2187}},  // 3\n        {645922817, {23,\
    \ 680782677}},  // 3\n        {897581057, {23, 126991183}},  // 3\n        {924844033,\
    \ {21, 480100938}},  // 5\n        {935329793, {22, 945616399}},  // 3\n     \
    \   {943718401, {22, 39032610}},  // 7\n        {950009857, {21, 912960248}},\
    \  // 7\n        {962592769, {21, 762567211}},  // 7\n        {975175681, {21,\
    \ 973754139}},  // 17\n        {976224257, {20, 168477898}},  // 3\n        {985661441,\
    \ {22, 157780640}},  // 3\n        {998244353, {23, 15311432}},  // 3\n      \
    \  {1004535809, {21, 840453100}},  // 3\n        {1007681537, {20, 283888334}},\
    \  // 3\n        {1012924417, {21, 428116421}},  // 5\n        {1045430273, {20,\
    \ 328125745}},  // 3\n        {1051721729, {20, 234350985}},  // 6\n        {1053818881,\
    \ {20, 309635616}},  // 7\n        {1224736769, {24, 304180829}}};  // 3\n   \
    \ return primes.at(T);\n  }\n\n  const int n_max;\n  const ModInt root;\n\n  std::vector<int>\
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
    \  }\n  }\n};\n\n#endif  // __has_include(<atcoder/convolution>)\n\n}  // namespace\
    \ emthrm\n\n\n#line 13 \"include/emthrm/string/wildcard_pattern_matching.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T = std::string>\nrequires requires\
    \ { typename T::value_type; }\nstd::vector<int> wildcard_pattern_matching(\n \
    \   const T& text, const T& pattern, const typename T::value_type wildcard) {\n\
    \  if (text.size() < pattern.size()) [[unlikely]] return {};\n  const auto generate\
    \ = [wildcard](const T& str)\n      -> std::tuple<std::vector<long long>,\n  \
    \                  std::vector<long long>,\n                    std::vector<long\
    \ long>> {\n    using Char = T::value_type;\n    static std::map<Char, int> characters{{wildcard,\
    \ 0}};\n    std::vector<long long> v1(str.size());\n    std::ranges::transform(\n\
    \        str, v1.begin(),\n        [](const Char c) -> int {\n          if (const\
    \ auto it = characters.find(c); it != characters.end()) {\n            return\
    \ it->second;\n          }\n          const int next_index = characters.size();\n\
    \          assert(characters.emplace(c, next_index).second);\n          return\
    \ next_index;\n        });\n    std::vector<long long> v2 = v1;\n    std::ranges::transform(\n\
    \        v2, v2.begin(),\n        [](const long long ch) -> long long { return\
    \ ch * ch; });\n    std::vector<long long> v3 = v1;\n    std::ranges::transform(\n\
    \        v3, v3.begin(),\n        [](const long long ch) -> long long { return\
    \ ch * ch * ch; });\n    return {v1, v2, v3};\n  };\n  const auto [t1, t2, t3]\
    \ = generate(text);\n  auto [p1, p2, p3] = generate(pattern);\n  std::ranges::reverse(p1);\n\
    \  std::ranges::reverse(p2);\n  std::ranges::reverse(p3);\n  const int l = text.size()\
    \ - pattern.size() + 1;\n  std::vector<int> ans(l);\n  std::iota(ans.begin(),\
    \ ans.end(), 0);\n  const auto check = [&pattern, &t1, &t2, &t3, &p1, &p2, &p3,\
    \ l, &ans]\n      <unsigned int M>(const NumberTheoreticTransform<M>& ntt) ->\
    \ void {\n    using ModInt = NumberTheoreticTransform<M>::ModInt;\n    static\
    \ const int offset = pattern.size() - 1;\n    const std::vector<ModInt> t3p1 =\
    \ ntt.convolution(t3, p1);\n    const std::vector<ModInt> t2p2 = ntt.convolution(t2,\
    \ p2);\n    const std::vector<ModInt> t1p3 = ntt.convolution(t1, p3);\n    std::vector<int>\
    \ next_ans;\n    next_ans.reserve(ans.size());\n    for (const int i : ans) {\n\
    \      const ModInt wmatch = t3p1[i + offset] - t2p2[i + offset] * ModInt::raw(2)\n\
    \                            + t1p3[i + offset];\n      if (wmatch == 0) next_ans.emplace_back(i);\n\
    \    }\n    ans.swap(next_ans);\n  };\n  check(NumberTheoreticTransform<998244353>());\n\
    \  check(NumberTheoreticTransform<1004535809>());\n  check(NumberTheoreticTransform<1007681537>());\n\
    \  return ans;\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"test/string/wildcard_pattern_matching.test.cpp\"\
    \n\nint main() {\n  int l, w;\n  std::string s, p;\n  std::cin >> l >> w >> s\
    \ >> p;\n  s = s + std::string(w - 1, '.') + s;\n  if (l == w) {\n    s.pop_back();\n\
    \  } else {\n    s += std::string(w - (l + 1), '.');\n  }\n  std::cout << emthrm::wildcard_pattern_matching(s,\
    \ p, '_').size() << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9\
    \ ? \u3092\u7528\u3044\u305F\u30D1\u30BF\u30FC\u30F3\u30DE\u30C3\u30C1\u30F3\u30B0\
    \n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc305/tasks/abc305_h\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/wildcard_pattern_matching.hpp\"\
    \n\nint main() {\n  int l, w;\n  std::string s, p;\n  std::cin >> l >> w >> s\
    \ >> p;\n  s = s + std::string(w - 1, '.') + s;\n  if (l == w) {\n    s.pop_back();\n\
    \  } else {\n    s += std::string(w - (l + 1), '.');\n  }\n  std::cout << emthrm::wildcard_pattern_matching(s,\
    \ p, '_').size() << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/wildcard_pattern_matching.hpp
  - include/emthrm/math/convolution/number_theoretic_transform.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/string/wildcard_pattern_matching.test.cpp
  requiredBy: []
  timestamp: '2023-07-07 12:32:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/wildcard_pattern_matching.test.cpp
layout: document
redirect_from:
- /verify/test/string/wildcard_pattern_matching.test.cpp
- /verify/test/string/wildcard_pattern_matching.test.cpp.html
title: "\u6587\u5B57\u5217/\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9 ? \u3092\u7528\
  \u3044\u305F\u30D1\u30BF\u30FC\u30F3\u30DE\u30C3\u30C1\u30F3\u30B0"
---
