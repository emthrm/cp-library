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
  bundledCode: "#line 1 \"include/emthrm/math/polynomial.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <initializer_list>\n#include\
    \ <iterator>\n#include <numeric>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nstruct Polynomial {\n  std::vector<T> coef;\n\
    \n  explicit Polynomial(const int deg = 0) : coef(deg + 1, 0) {}\n  explicit Polynomial(const\
    \ std::vector<T>& coef) : coef(coef) {}\n  Polynomial(const std::initializer_list<T>\
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
    \  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_POLYNOMIAL_HPP_\n#define EMTHRM_MATH_POLYNOMIAL_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <initializer_list>\n\
    #include <iterator>\n#include <numeric>\n#include <utility>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nstruct Polynomial {\n  std::vector<T>\
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
    \  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_POLYNOMIAL_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/polynomial.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/polynomial.test.cpp
documentation_of: include/emthrm/math/polynomial.hpp
layout: document
title: "\u591A\u9805\u5F0F (polynomial)"
---


## 時間計算量

||時間計算量|
|:--|:--|
|加減算|$O(N)$|
|スカラー倍|$O(N)$|
|乗算|$O(N\log{N})$|
|除算|$O(N^2)$|
|剰余演算|$O(N^2)$|
|ホーナー法 (Horner's rule)|$O(N)$|
|形式微分|$O(N)$|
|累乗||
|`translate`|$O(N\log{N})$|


## 仕様

```cpp
template <typename T>
struct Polynomial;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> coef`|係数列|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit Polynomial(const int deg = 0);`|$\mathrm{deg}$ 次まで係数列をもつオブジェクトを構築する。|
|`explicit Polynomial(const std::vector<T>& coef);`|係数列を $\mathrm{coef}$ とするオブジェクトを構築する。|
|`Polynomial(const std::initializer_list<T> init);`|初期化子リストを受け取るコンストラクタ|
|`template <typename InputIter>`<br>`explicit Polynomial(const InputIter first, const InputIter last);`|イテレータ範囲コンストラクタ|
|`inline const T& operator[](const int term) const;`<br>`inline T& operator[](const int term);`|${\lbrack x^{\mathrm{term}} \rbrack}f$|
|`void resize(const int deg);`|$\mathrm{deg}$ 次まで係数列をもつ。|
|`void shrink();`|正規化を行う。|
|`int degree() const;`|現在の次数|
|`Polynomial& operator=(const std::vector<T>& coef_);`<br>`Polynomial& operator=(const Polynomial& x);`|代入演算子|
|`Polynomial& operator+=(const Polynomial& x);`<br>`Polynomial operator+(const Polynomial& x) const;`|加算|
|`Polynomial& operator-=(const Polynomial& x);`<br>`Polynomial operator-(const Polynomial& x) const;`|減算|
|`Polynomial& operator*=(const T x);`<br>`Polynomial& operator*=(const Polynomial& x);`<br>`Polynomial operator*(const T x) const;`<br>`Polynomial operator*(const Polynomial& x) const;`|乗算|
|`Polynomial& operator/=(const T x);`<br>`Polynomial& operator/=(const Polynomial& x);`<br>`Polynomial operator/(const T x) const;`<br>`Polynomial operator/(const Polynomial& x) const;`|除算|
|`Polynomial& operator%=(const Polynomial& x);`<br>`Polynomial operator%(const Polynomial& x) const;`|剰余演算|
|`std::pair<Polynomial, Polynomial> divide(Polynomial x) const;`|$x$ で割った商とあまり|
|`Polynomial& operator<<=(const int n);`<br>`FormalPowerSeries operator<<(const int n) const;`|$x^n f$|
|`bool operator==(Polynomial x) const;`|等値比較|
|`Polynomial operator+() const;`|$+{f}$|
|`Polynomial operator-() const;`|$-{f}$|
|`T horner(const T x) const;`|$f(x)$|
|`Polynomial differential() const;`|$f^{\prime}$|
|`Polynomial pow(int exponent) const;`|$f^{\mathrm{exponent}}$|
|`Polynomial translate(const T c) const;`|$f(x + c)$|

#### 静的メンバ関数

|名前|効果|
|:--|:--|
|`static void set_mult(const Mult mult);`|乗算を定義する。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Mult`|`std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>`|


## 参考文献

- https://github.com/beet-aizu/library/blob/29e15f77befa18d06b1f61221c509b5a58f4cb4c/polynomial/polynomial.cpp
- https://github.com/primenumber/ProconLib/blob/dc175741e461e88f69350532b47fa57527b38fa3/Math/Polynomial.cpp


## TODO

- http://www.math.kobe-u.ac.jp/Asir/ca.pdf
- 除算の高速化
  - https://github.com/spaghetti-source/algorithm/blob/master/math/polynomial_int.cc
  - http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
  - https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae#toc10
  - https://judge.yosupo.jp/problem/division_of_polynomials
- DKA 法 (Durand–Kerner–Aberth method)
  - https://drive.google.com/file/d/1Fb5TPXzEQVKzYDwhNN2XZpWZWa49aCIY
- Bairstow's method
  - https://en.wikipedia.org/wiki/Bairstow%27s_method
- 微積分
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/pepsin-amylase/20141208/
