---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/rational.test.cpp
    title: "\u6570\u5B66/\u6709\u7406\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rational.hpp\"\n#include <algorithm>\r\n// #include\
    \ <cassert>\r\n#include <limits>\r\n#include <ostream>\r\n\r\ntemplate <typename\
    \ T = long long>\r\nstruct Rational {\r\n  T num, den;\r\n  Rational() : num(0),\
    \ den(1) {}\r\n  Rational(const T num, const T den = 1) : num(num), den(den) {\r\
    \n    // assert(den != 0);\r\n    reduce();\r\n  }\r\n  template <typename Real\
    \ = long double>\r\n  Real to_real() const { return static_cast<Real>(num) / den;\
    \ }\r\n  Rational& operator+=(const Rational& x) {\r\n    const T g = std::__gcd(den,\
    \ x.den);\r\n    num = num * (x.den / g) + x.num * (den / g);\r\n    den *= x.den\
    \ / g;\r\n    reduce();\r\n    return *this;\r\n  }\r\n  Rational& operator-=(const\
    \ Rational& x) { return *this += -x; }\r\n  Rational& operator*=(const Rational&\
    \ x) {\r\n    const T g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);\r\
    \n    num = (num / g1) * (x.num / g2);\r\n    den = (den / g2) * (x.den / g1);\r\
    \n    reduce();\r\n    return *this;\r\n  }\r\n  Rational& operator/=(const Rational&\
    \ x) {\r\n    return *this *= Rational(x.den, x.num);\r\n  }\r\n  bool operator==(const\
    \ Rational& x) const {\r\n    return num == x.num && den == x.den;\r\n  }\r\n\
    \  bool operator!=(const Rational& x) const { return !(*this == x); }\r\n  bool\
    \ operator<(const Rational& x) const { return (x - *this).num > 0; }\r\n  bool\
    \ operator<=(const Rational& x) const { return !(x < *this); }\r\n  bool operator>(const\
    \ Rational& x) const { return x < *this; }\r\n  bool operator>=(const Rational&\
    \ x) const { return !(*this < x); }\r\n  Rational& operator++() {\r\n    if ((num\
    \ += den) == 0) den = 1;\r\n    return *this;\r\n  }\r\n  Rational operator++(int)\
    \ {\r\n    const Rational res = *this;\r\n    ++*this;\r\n    return res;\r\n\
    \  }\r\n  Rational& operator--() {\r\n    if ((num -= den) == 0) den = 1;\r\n\
    \    return *this;\r\n  }\r\n  Rational operator--(int) {\r\n    const Rational\
    \ res = *this;\r\n    --*this;\r\n    return res;\r\n  }\r\n  Rational operator+()\
    \ const { return *this; }\r\n  Rational operator-() const { return Rational(-num,\
    \ den); }\r\n  Rational operator+(const Rational& x) const { return Rational(*this)\
    \ += x; }\r\n  Rational operator-(const Rational& x) const { return Rational(*this)\
    \ -= x; }\r\n  Rational operator*(const Rational& x) const { return Rational(*this)\
    \ *= x; }\r\n  Rational operator/(const Rational& x) const { return Rational(*this)\
    \ /= x; }\r\n  friend std::ostream& operator<<(std::ostream& os, const Rational&\
    \ x) {\r\n    if (x.den == 1) return os << x.num;\r\n    return os << x.num <<\
    \ '/' << x.den;\r\n  }\r\n private:\r\n  void reduce() {\r\n    const T g = std::__gcd(num,\
    \ den);\r\n    num /= g;\r\n    den /= g;\r\n    if (den < 0) {\r\n      num =\
    \ -num;\r\n      den = -den;\r\n    }\r\n  }\r\n};\r\nnamespace std {\r\ntemplate\
    \ <typename T>\r\nRational<T> abs(Rational<T> x) {\r\n  if (x.num < 0) x.num =\
    \ -x.num;\r\n  return x;\r\n}\r\ntemplate <typename T>\r\nRational<T> max(const\
    \ Rational<T>& a, const Rational<T>& b) {\r\n  return a < b ? b : a;\r\n}\r\n\
    template <typename T>\r\nRational<T> min(const Rational<T>& a, const Rational<T>&\
    \ b) {\r\n  return a < b ? a : b;\r\n}\r\ntemplate <typename T> struct numeric_limits<Rational<T>>\
    \ {\r\n  static constexpr Rational<T> max() { return std::numeric_limits<T>::max();\
    \ }\r\n  static constexpr Rational<T> lowest() {\r\n    return std::numeric_limits<T>::lowest();\r\
    \n  }\r\n};\r\n}  // namespace std\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n// #include <cassert>\r\n#include\
    \ <limits>\r\n#include <ostream>\r\n\r\ntemplate <typename T = long long>\r\n\
    struct Rational {\r\n  T num, den;\r\n  Rational() : num(0), den(1) {}\r\n  Rational(const\
    \ T num, const T den = 1) : num(num), den(den) {\r\n    // assert(den != 0);\r\
    \n    reduce();\r\n  }\r\n  template <typename Real = long double>\r\n  Real to_real()\
    \ const { return static_cast<Real>(num) / den; }\r\n  Rational& operator+=(const\
    \ Rational& x) {\r\n    const T g = std::__gcd(den, x.den);\r\n    num = num *\
    \ (x.den / g) + x.num * (den / g);\r\n    den *= x.den / g;\r\n    reduce();\r\
    \n    return *this;\r\n  }\r\n  Rational& operator-=(const Rational& x) { return\
    \ *this += -x; }\r\n  Rational& operator*=(const Rational& x) {\r\n    const T\
    \ g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);\r\n    num = (num\
    \ / g1) * (x.num / g2);\r\n    den = (den / g2) * (x.den / g1);\r\n    reduce();\r\
    \n    return *this;\r\n  }\r\n  Rational& operator/=(const Rational& x) {\r\n\
    \    return *this *= Rational(x.den, x.num);\r\n  }\r\n  bool operator==(const\
    \ Rational& x) const {\r\n    return num == x.num && den == x.den;\r\n  }\r\n\
    \  bool operator!=(const Rational& x) const { return !(*this == x); }\r\n  bool\
    \ operator<(const Rational& x) const { return (x - *this).num > 0; }\r\n  bool\
    \ operator<=(const Rational& x) const { return !(x < *this); }\r\n  bool operator>(const\
    \ Rational& x) const { return x < *this; }\r\n  bool operator>=(const Rational&\
    \ x) const { return !(*this < x); }\r\n  Rational& operator++() {\r\n    if ((num\
    \ += den) == 0) den = 1;\r\n    return *this;\r\n  }\r\n  Rational operator++(int)\
    \ {\r\n    const Rational res = *this;\r\n    ++*this;\r\n    return res;\r\n\
    \  }\r\n  Rational& operator--() {\r\n    if ((num -= den) == 0) den = 1;\r\n\
    \    return *this;\r\n  }\r\n  Rational operator--(int) {\r\n    const Rational\
    \ res = *this;\r\n    --*this;\r\n    return res;\r\n  }\r\n  Rational operator+()\
    \ const { return *this; }\r\n  Rational operator-() const { return Rational(-num,\
    \ den); }\r\n  Rational operator+(const Rational& x) const { return Rational(*this)\
    \ += x; }\r\n  Rational operator-(const Rational& x) const { return Rational(*this)\
    \ -= x; }\r\n  Rational operator*(const Rational& x) const { return Rational(*this)\
    \ *= x; }\r\n  Rational operator/(const Rational& x) const { return Rational(*this)\
    \ /= x; }\r\n  friend std::ostream& operator<<(std::ostream& os, const Rational&\
    \ x) {\r\n    if (x.den == 1) return os << x.num;\r\n    return os << x.num <<\
    \ '/' << x.den;\r\n  }\r\n private:\r\n  void reduce() {\r\n    const T g = std::__gcd(num,\
    \ den);\r\n    num /= g;\r\n    den /= g;\r\n    if (den < 0) {\r\n      num =\
    \ -num;\r\n      den = -den;\r\n    }\r\n  }\r\n};\r\nnamespace std {\r\ntemplate\
    \ <typename T>\r\nRational<T> abs(Rational<T> x) {\r\n  if (x.num < 0) x.num =\
    \ -x.num;\r\n  return x;\r\n}\r\ntemplate <typename T>\r\nRational<T> max(const\
    \ Rational<T>& a, const Rational<T>& b) {\r\n  return a < b ? b : a;\r\n}\r\n\
    template <typename T>\r\nRational<T> min(const Rational<T>& a, const Rational<T>&\
    \ b) {\r\n  return a < b ? a : b;\r\n}\r\ntemplate <typename T> struct numeric_limits<Rational<T>>\
    \ {\r\n  static constexpr Rational<T> max() { return std::numeric_limits<T>::max();\
    \ }\r\n  static constexpr Rational<T> lowest() {\r\n    return std::numeric_limits<T>::lowest();\r\
    \n  }\r\n};\r\n}  // namespace std\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/rational.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/rational.test.cpp
documentation_of: math/rational.hpp
layout: document
title: "\u6709\u7406\u6570 (rational number)"
---


## 参考

- https://github.com/spaghetti-source/algorithm/blob/208bcfd781e9c37aedee117ce45d5a4a5bab5fa1/math/rational.cc
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!Ratio.cpp~~


## ToDo

- Stern-Brocot tree
  - https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree
  - http://satashun.hatenablog.com/entry/2018/12/13/163524
  - http://blue-jam.hatenablog.com/entry/20110306/1299415086
  - http://www.prefield.com/algorithm/math/stern_brocot_tree.html
  - https://tjkendev.github.io/procon-library/python/math/stern-brocot-tree.html
  - https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146184
- ファレイ数列 (Farey sequence)
  - https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%83%AC%E3%82%A4%E6%95%B0%E5%88%97
  - https://mathtrain.jp/farey
  - http://kagamiz.hatenablog.com/entry/2012/12/01/225751
- 連分数 (continued fraction)
  - https://ja.wikipedia.org/wiki/%E9%80%A3%E5%88%86%E6%95%B0
  - https://mathtrain.jp/renbunsu
  - https://github.com/spaghetti-source/algorithm/blob/master/math/continued_fraction.cc


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2589/review/4088153/emthrm/C++14
