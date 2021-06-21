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
    \ {\r\n  using MUL = std::function<std::vector<T>(const std::vector<T>&, const\
    \ std::vector<T>&)>;\r\n  std::vector<T> co;\r\n  Polynomial(int deg = 0) : co(deg\
    \ + 1, 0) {}\r\n  Polynomial(const std::vector<T> &co) : co(co) {}\r\n  Polynomial(std::initializer_list<T>\
    \ init) : co(init.begin(), init.end()) {}\r\n  template <typename InputIter> Polynomial(InputIter\
    \ first, InputIter last) : co(first, last) {}\r\n  inline const T &operator[](int\
    \ term) const { return co[term]; }\r\n  inline T &operator[](int term) { return\
    \ co[term]; }\r\n  static void set_mul(MUL mul) { get_mul() = mul; }\r\n  void\
    \ shrink() { while (co.size() > 1 && co.back() == 0) co.pop_back(); }\r\n  int\
    \ degree() const { return static_cast<int>(co.size()) - 1; }\r\n  Polynomial &operator=(const\
    \ std::vector<T> &new_co) {\r\n    co.resize(new_co.size());\r\n    std::copy(new_co.begin(),\
    \ new_co.end(), co.begin());\r\n    return *this;\r\n  }\r\n  Polynomial &operator=(const\
    \ Polynomial &x) {\r\n    co.resize(x.co.size());\r\n    std::copy(x.co.begin(),\
    \ x.co.end(), co.begin());\r\n    return *this;\r\n  }\r\n  Polynomial &operator+=(const\
    \ Polynomial &x) {\r\n    int n = x.co.size();\r\n    if (n > co.size()) co.resize(n,\
    \ 0);\r\n    for (int i = 0; i < n; ++i) co[i] += x.co[i];\r\n    return *this;\r\
    \n  }\r\n  Polynomial &operator-=(const Polynomial &x) {\r\n    int n = x.co.size();\r\
    \n    if (n > co.size()) co.resize(n, 0);\r\n    for (int i = 0; i < n; ++i) co[i]\
    \ -= x.co[i];\r\n    return *this;\r\n  }\r\n  Polynomial &operator*=(T x) {\r\
    \n    for (T &e : co) e *= x;\r\n    return *this;\r\n  }\r\n  Polynomial &operator*=(const\
    \ Polynomial &x) { return *this = get_mul()(co, x.co); }\r\n  Polynomial &operator/=(T\
    \ x) {\r\n    assert(x != 0);\r\n    T inv_x = static_cast<T>(1) / x;\r\n    for\
    \ (T &e : co) e *= inv_x;\r\n    return *this;\r\n  }\r\n  std::pair<Polynomial,\
    \ Polynomial> divide(const Polynomial &x) const {\r\n    Polynomial p(x);\r\n\
    \    p.shrink();\r\n    int n = co.size(), m = p.co.size(), sz = n - m + 1;\r\n\
    \    if (sz <= 0) return {Polynomial({0}), *this};\r\n    Polynomial quo(sz -\
    \ 1), rem = *this;\r\n    for (int i = 0; i < sz; ++i) {\r\n      quo.co[sz -\
    \ 1 - i] = rem.co[n - 1 - i] / p.co.back();\r\n      for (int j = 0; j < m; ++j)\
    \ rem[n - 1 - i - j] -= p.co[m - 1 - j] * quo.co[sz - 1 - i];\r\n    }\r\n   \
    \ rem.co.resize(sz);\r\n    return {quo, rem};\r\n  }\r\n  Polynomial &operator/=(const\
    \ Polynomial &x) { return *this = divide(x).first; }\r\n  Polynomial &operator%=(const\
    \ Polynomial &x) { return *this = divide(x).second; };\r\n  Polynomial &operator<<=(int\
    \ n) {\r\n    co.insert(co.begin(), n, 0);\r\n    return *this;\r\n  }\r\n  bool\
    \ operator==(const Polynomial &x) const {\r\n    Polynomial a(*this), b(x);\r\n\
    \    a.shrink(); b.shrink();\r\n    int n = a.co.size();\r\n    if (n != b.co.size())\
    \ return false;\r\n    for (int i = 0; i < n; ++i) if (a.co[i] != b.co[i]) return\
    \ false;\r\n    return true;\r\n  }\r\n  bool operator!=(const Polynomial &x)\
    \ const { return !(*this == x); }\r\n  Polynomial operator+() const { return *this;\
    \ }\r\n  Polynomial operator-() const {\r\n    Polynomial res(*this);\r\n    for\
    \ (T &e : res.co) e = -e;\r\n    return res;\r\n  }\r\n  Polynomial operator+(const\
    \ Polynomial &x) const { return Polynomial(*this) += x; }\r\n  Polynomial operator-(const\
    \ Polynomial &x) const { return Polynomial(*this) -= x; }\r\n  Polynomial operator*(T\
    \ x) const { return Polynomial(*this) *= x; }\r\n  Polynomial operator*(const\
    \ Polynomial &x) const { return Polynomial(*this) *= x; }\r\n  Polynomial operator/(T\
    \ x) const { return Polynomial(*this) /= x; }\r\n  Polynomial operator/(const\
    \ Polynomial &x) const { return Polynomial(*this) /= x; }\r\n  Polynomial operator%(const\
    \ Polynomial &x) const { return Polynomial(*this) %= x; }\r\n  Polynomial operator<<(int\
    \ n) const { return Polynomial(*this) <<= n; }\r\n  T horner(T x) const {\r\n\
    \    T res = static_cast<T>(0);\r\n    for (int i = static_cast<int>(co.size())\
    \ - 1; i >= 0; --i) (res *= x) += co[i];\r\n    return res;\r\n  }\r\n  Polynomial\
    \ differential() const {\r\n    int n = co.size();\r\n    assert(n >= 1);\r\n\
    \    Polynomial res(n - 1);\r\n    for (int i = 1; i < n; ++i) res.co[i - 1] =\
    \ co[i] * i;\r\n    return res;\r\n  }\r\n  Polynomial integral() const {\r\n\
    \    int n = co.size();\r\n    Polynomial res(n + 1);\r\n    for (int i = 0; i\
    \ < n; ++i) res[i + 1] = co[i] / (i + 1);\r\n    return res;\r\n  }\r\n  Polynomial\
    \ pow(int exponent) const {\r\n    Polynomial res({1}), base = *this;\r\n    while\
    \ (exponent > 0) {\r\n      if (exponent & 1) res *= base;\r\n      base *= base;\r\
    \n      exponent >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  Polynomial translate(T\
    \ c) const {\r\n    int n = co.size();\r\n    std::vector<T> fact(n, 1), inv_fact(n,\
    \ 1);\r\n    for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\r\n    inv_fact[n\
    \ - 1] = static_cast<T>(1) / fact[n - 1];\r\n    for (int i = n - 1; i > 0; --i)\
    \ inv_fact[i - 1] = inv_fact[i] * i;\r\n    std::vector<T> g(n), ex(n);\r\n  \
    \  for (int i = 0; i < n; ++i) g[n - 1 - i] = co[i] * fact[i];\r\n    T pow_c\
    \ = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c * inv_fact[i];\r\
    \n      pow_c *= c;\r\n    }\r\n    std::vector<T> conv = get_mul()(g, ex);\r\n\
    \    Polynomial res(n - 1);\r\n    for (int i = 0; i < n; ++i) res[i] = conv[n\
    \ - 1 - i] * inv_fact[i];\r\n    return res;\r\n  }\r\nprivate:\r\n  static MUL\
    \ &get_mul() {\r\n    static MUL mul = [](const std::vector<T> &a, const std::vector<T>\
    \ &b) -> std::vector<T> {\r\n      int n = a.size(), m = b.size();\r\n      std::vector<T>\
    \ res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i) for (int j = 0; j <\
    \ m; ++j) res[i + j] += a[i] * b[j];\r\n      return res;\r\n    };\r\n    return\
    \ mul;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\
    \n#include <initializer_list>\r\n#include <utility>\r\n#include <vector>\r\n\r\
    \ntemplate <typename T>\r\nstruct Polynomial {\r\n  using MUL = std::function<std::vector<T>(const\
    \ std::vector<T>&, const std::vector<T>&)>;\r\n  std::vector<T> co;\r\n  Polynomial(int\
    \ deg = 0) : co(deg + 1, 0) {}\r\n  Polynomial(const std::vector<T> &co) : co(co)\
    \ {}\r\n  Polynomial(std::initializer_list<T> init) : co(init.begin(), init.end())\
    \ {}\r\n  template <typename InputIter> Polynomial(InputIter first, InputIter\
    \ last) : co(first, last) {}\r\n  inline const T &operator[](int term) const {\
    \ return co[term]; }\r\n  inline T &operator[](int term) { return co[term]; }\r\
    \n  static void set_mul(MUL mul) { get_mul() = mul; }\r\n  void shrink() { while\
    \ (co.size() > 1 && co.back() == 0) co.pop_back(); }\r\n  int degree() const {\
    \ return static_cast<int>(co.size()) - 1; }\r\n  Polynomial &operator=(const std::vector<T>\
    \ &new_co) {\r\n    co.resize(new_co.size());\r\n    std::copy(new_co.begin(),\
    \ new_co.end(), co.begin());\r\n    return *this;\r\n  }\r\n  Polynomial &operator=(const\
    \ Polynomial &x) {\r\n    co.resize(x.co.size());\r\n    std::copy(x.co.begin(),\
    \ x.co.end(), co.begin());\r\n    return *this;\r\n  }\r\n  Polynomial &operator+=(const\
    \ Polynomial &x) {\r\n    int n = x.co.size();\r\n    if (n > co.size()) co.resize(n,\
    \ 0);\r\n    for (int i = 0; i < n; ++i) co[i] += x.co[i];\r\n    return *this;\r\
    \n  }\r\n  Polynomial &operator-=(const Polynomial &x) {\r\n    int n = x.co.size();\r\
    \n    if (n > co.size()) co.resize(n, 0);\r\n    for (int i = 0; i < n; ++i) co[i]\
    \ -= x.co[i];\r\n    return *this;\r\n  }\r\n  Polynomial &operator*=(T x) {\r\
    \n    for (T &e : co) e *= x;\r\n    return *this;\r\n  }\r\n  Polynomial &operator*=(const\
    \ Polynomial &x) { return *this = get_mul()(co, x.co); }\r\n  Polynomial &operator/=(T\
    \ x) {\r\n    assert(x != 0);\r\n    T inv_x = static_cast<T>(1) / x;\r\n    for\
    \ (T &e : co) e *= inv_x;\r\n    return *this;\r\n  }\r\n  std::pair<Polynomial,\
    \ Polynomial> divide(const Polynomial &x) const {\r\n    Polynomial p(x);\r\n\
    \    p.shrink();\r\n    int n = co.size(), m = p.co.size(), sz = n - m + 1;\r\n\
    \    if (sz <= 0) return {Polynomial({0}), *this};\r\n    Polynomial quo(sz -\
    \ 1), rem = *this;\r\n    for (int i = 0; i < sz; ++i) {\r\n      quo.co[sz -\
    \ 1 - i] = rem.co[n - 1 - i] / p.co.back();\r\n      for (int j = 0; j < m; ++j)\
    \ rem[n - 1 - i - j] -= p.co[m - 1 - j] * quo.co[sz - 1 - i];\r\n    }\r\n   \
    \ rem.co.resize(sz);\r\n    return {quo, rem};\r\n  }\r\n  Polynomial &operator/=(const\
    \ Polynomial &x) { return *this = divide(x).first; }\r\n  Polynomial &operator%=(const\
    \ Polynomial &x) { return *this = divide(x).second; };\r\n  Polynomial &operator<<=(int\
    \ n) {\r\n    co.insert(co.begin(), n, 0);\r\n    return *this;\r\n  }\r\n  bool\
    \ operator==(const Polynomial &x) const {\r\n    Polynomial a(*this), b(x);\r\n\
    \    a.shrink(); b.shrink();\r\n    int n = a.co.size();\r\n    if (n != b.co.size())\
    \ return false;\r\n    for (int i = 0; i < n; ++i) if (a.co[i] != b.co[i]) return\
    \ false;\r\n    return true;\r\n  }\r\n  bool operator!=(const Polynomial &x)\
    \ const { return !(*this == x); }\r\n  Polynomial operator+() const { return *this;\
    \ }\r\n  Polynomial operator-() const {\r\n    Polynomial res(*this);\r\n    for\
    \ (T &e : res.co) e = -e;\r\n    return res;\r\n  }\r\n  Polynomial operator+(const\
    \ Polynomial &x) const { return Polynomial(*this) += x; }\r\n  Polynomial operator-(const\
    \ Polynomial &x) const { return Polynomial(*this) -= x; }\r\n  Polynomial operator*(T\
    \ x) const { return Polynomial(*this) *= x; }\r\n  Polynomial operator*(const\
    \ Polynomial &x) const { return Polynomial(*this) *= x; }\r\n  Polynomial operator/(T\
    \ x) const { return Polynomial(*this) /= x; }\r\n  Polynomial operator/(const\
    \ Polynomial &x) const { return Polynomial(*this) /= x; }\r\n  Polynomial operator%(const\
    \ Polynomial &x) const { return Polynomial(*this) %= x; }\r\n  Polynomial operator<<(int\
    \ n) const { return Polynomial(*this) <<= n; }\r\n  T horner(T x) const {\r\n\
    \    T res = static_cast<T>(0);\r\n    for (int i = static_cast<int>(co.size())\
    \ - 1; i >= 0; --i) (res *= x) += co[i];\r\n    return res;\r\n  }\r\n  Polynomial\
    \ differential() const {\r\n    int n = co.size();\r\n    assert(n >= 1);\r\n\
    \    Polynomial res(n - 1);\r\n    for (int i = 1; i < n; ++i) res.co[i - 1] =\
    \ co[i] * i;\r\n    return res;\r\n  }\r\n  Polynomial integral() const {\r\n\
    \    int n = co.size();\r\n    Polynomial res(n + 1);\r\n    for (int i = 0; i\
    \ < n; ++i) res[i + 1] = co[i] / (i + 1);\r\n    return res;\r\n  }\r\n  Polynomial\
    \ pow(int exponent) const {\r\n    Polynomial res({1}), base = *this;\r\n    while\
    \ (exponent > 0) {\r\n      if (exponent & 1) res *= base;\r\n      base *= base;\r\
    \n      exponent >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  Polynomial translate(T\
    \ c) const {\r\n    int n = co.size();\r\n    std::vector<T> fact(n, 1), inv_fact(n,\
    \ 1);\r\n    for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\r\n    inv_fact[n\
    \ - 1] = static_cast<T>(1) / fact[n - 1];\r\n    for (int i = n - 1; i > 0; --i)\
    \ inv_fact[i - 1] = inv_fact[i] * i;\r\n    std::vector<T> g(n), ex(n);\r\n  \
    \  for (int i = 0; i < n; ++i) g[n - 1 - i] = co[i] * fact[i];\r\n    T pow_c\
    \ = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c * inv_fact[i];\r\
    \n      pow_c *= c;\r\n    }\r\n    std::vector<T> conv = get_mul()(g, ex);\r\n\
    \    Polynomial res(n - 1);\r\n    for (int i = 0; i < n; ++i) res[i] = conv[n\
    \ - 1 - i] * inv_fact[i];\r\n    return res;\r\n  }\r\nprivate:\r\n  static MUL\
    \ &get_mul() {\r\n    static MUL mul = [](const std::vector<T> &a, const std::vector<T>\
    \ &b) -> std::vector<T> {\r\n      int n = a.size(), m = b.size();\r\n      std::vector<T>\
    \ res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i) for (int j = 0; j <\
    \ m; ++j) res[i + j] += a[i] * b[j];\r\n      return res;\r\n    };\r\n    return\
    \ mul;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/polynomial.hpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
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
|形式微積分|$O(N)$|
|冪乗||
|`translate(c)`|$O(N\log{N})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Polynomial<T>(deg = 0)`|次数 $\mathrm{deg}$ の多項式||
|`Polynomial<T>(co)`|係数を $\mathrm{co}$ とする多項式||
|`co`|係数||
|`operator()[term]`|${\lbrack x^{\mathrm{term}} \rbrack}f$||
|`set_mul(mul)`|乗算を定義する．||
|`shrink()`|正規化を行う．||
|`degree()`|次数||
|`operator=(new_co)`|数列 $\mathrm{new\_co}$ を代入する．||
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
|`integral()`|$\int{f}$||
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
- DKA 法
  - https://drive.google.com/file/d/1Fb5TPXzEQVKzYDwhNN2XZpWZWa49aCIY
