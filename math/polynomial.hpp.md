---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/polynomial.test.cpp
    title: "\u6570\u5B66/\u591A\u9805\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/polynomial.hpp\"\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#include <functional>\r\n#include <initializer_list>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct Polynomial\
    \ {\r\n  std::vector<T> coef;\r\n\r\n  explicit Polynomial(const int deg = 0)\
    \ : coef(deg + 1, 0) {}\r\n  explicit Polynomial(const std::vector<T>& coef) :\
    \ coef(coef) {}\r\n  Polynomial(const std::initializer_list<T> init)\r\n     \
    \ : coef(init.begin(), init.end()) {}\r\n  template <typename InputIter>\r\n \
    \ explicit Polynomial(const InputIter first, const InputIter last)\r\n      :\
    \ coef(first, last) {}\r\n\r\n  inline const T& operator[](const int term) const\
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
    \  }\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\
    \n#include <initializer_list>\r\n#include <utility>\r\n#include <vector>\r\n\r\
    \ntemplate <typename T>\r\nstruct Polynomial {\r\n  std::vector<T> coef;\r\n\r\
    \n  explicit Polynomial(const int deg = 0) : coef(deg + 1, 0) {}\r\n  explicit\
    \ Polynomial(const std::vector<T>& coef) : coef(coef) {}\r\n  Polynomial(const\
    \ std::initializer_list<T> init)\r\n      : coef(init.begin(), init.end()) {}\r\
    \n  template <typename InputIter>\r\n  explicit Polynomial(const InputIter first,\
    \ const InputIter last)\r\n      : coef(first, last) {}\r\n\r\n  inline const\
    \ T& operator[](const int term) const { return coef[term]; }\r\n  inline T& operator[](const\
    \ int term) { return coef[term]; }\r\n\r\n  using MULT = std::function<std::vector<T>(const\
    \ std::vector<T>&,\r\n                                            const std::vector<T>&)>;\r\
    \n  static void set_mult(const MULT mult) { get_mult() = mult; }\r\n\r\n  void\
    \ shrink() {\r\n    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\r\
    \n  }\r\n  int degree() const { return static_cast<int>(coef.size()) - 1; }\r\n\
    \r\n  Polynomial& operator=(const std::vector<T>& coef_) {\r\n    coef = coef_;\r\
    \n    return *this;\r\n  }\r\n  Polynomial& operator=(const Polynomial& x) = default;\r\
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
    \  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/polynomial.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/polynomial.test.cpp
documentation_of: math/polynomial.hpp
layout: document
title: "\u591A\u9805\u5F0F (polynomial)"
---


## 時間計算量

||時間計算量|
|:--:|:--:|
|加減算|$O(N)$|
|スカラー倍|$O(N)$|
|乗算|$O(N\log{N})$|
|除算|$O(N^2)$|
|剰余演算|$O(N^2)$|
|ホーナー法 (Horner's rule)|$O(N)$|
|形式微分|$O(N)$|
|累乗||
|`translate(c)`|$O(N\log{N})$|


## 使用法

||説明|条件|
|:--:|:--:|:--:|
|`Polynomial<T>(deg = 0)`|次数 $\mathrm{deg}$ の多項式||
|`Polynomial<T>(coef)`|係数列を $\mathrm{coef}$ とする多項式||
|`coef`|係数列||
|`operator()[term]`|${\lbrack x^{\mathrm{term}} \rbrack}f$||
|`set_mul(mul)`|乗算を定義する．||
|`shrink()`|正規化を行う．||
|`degree()`|次数||
|`operator=(coef_)`|係数列 $\mathrm{coef\_}$ を代入する．||
|`operator=(x)`|多項式 $x$ を代入する．||
|`operator+=(x)`<br>`operator+(x)`|加算||
|`operator-=(x)`<br>`operator-(x)`|減算||
|`operator*=(x)`<br>`operator*(x)`|乗算||
|`divide(x)`|$x$ で割った商とあまり||
|`operator/=(x)`<br>`operator/(x)`|除算||
|`operator%=(x)`<br>`operator%(x)`|剰余演算||
|`operator<<=(n)`<br>`operator<<(n)`|$x^n f$||
|`operator==(x)`|$f = x$ であるか．||
|`operator!=(x)`|$f \neq x$ であるか．||
|`operator+()`|$+{f}$||
|`operator-()`|$-{f}$||
|`horner(x)`|$f(x)$||
|`differential()`|$f^{\prime}$|$\mathrm{deg}(f) \geq 0$|
|`pow(exponent)`|$f^{\mathrm{exponent}}$||
|`translate(c)`|$f(x + c)$||


## 参考

- https://github.com/beet-aizu/library/blob/29e15f77befa18d06b1f61221c509b5a58f4cb4c/polynomial/polynomial.cpp
- https://github.com/primenumber/ProconLib/blob/dc175741e461e88f69350532b47fa57527b38fa3/Math/Polynomial.cpp


## ToDo

- http://www.math.kobe-u.ac.jp/Asir/ca.pdf
- 除算の高速化
  - https://github.com/spaghetti-source/algorithm/blob/master/math/polynomial_int.cc
  - http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
  - https://judge.yosupo.jp/problem/division_of_polynomials
- DKA 法 (Durand-Kerner-Aberth method)
  - https://drive.google.com/file/d/1Fb5TPXzEQVKzYDwhNN2XZpWZWa49aCIY
- Bairstow's method
  - https://en.wikipedia.org/wiki/Bairstow%27s_method
- 微積分
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/pepsin-amylase/20141208/
