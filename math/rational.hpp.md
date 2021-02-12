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
  bundledCode: "#line 2 \"math/rational.hpp\"\n#include <algorithm>\r\n#include <cassert>\r\
    \n#include <limits>\r\n#include <ostream>\r\n\r\ntemplate <typename T = long long>\r\
    \nstruct Rational {\r\n  T num, den;\r\n  Rational(): num(0), den(1) {}\r\n  Rational(T\
    \ num, T den = 1) : num(num), den(den) { assert(den != 0); reduce(); }\r\n  template\
    \ <typename Real = long double> Real to_real() const { return static_cast<Real>(num)\
    \ / den; }\r\n  Rational &operator+=(const Rational &x) {\r\n    T g = std::__gcd(den,\
    \ x.den);\r\n    num = num * (x.den / g) + x.num * (den / g); den *= x.den / g;\r\
    \n    reduce();\r\n    return *this;\r\n  }\r\n  Rational &operator-=(const Rational\
    \ &x) { return *this += -x; }\r\n  Rational &operator*=(const Rational &x) {\r\
    \n    T g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);\r\n    num =\
    \ (num / g1) * (x.num / g2); den = (den / g2) * (x.den / g1);\r\n    reduce();\r\
    \n    return *this;\r\n  }\r\n  Rational &operator/=(const Rational &x) { return\
    \ *this *= Rational(x.den, x.num); }\r\n  bool operator==(const Rational &x) const\
    \ { return num == x.num && den == x.den; }\r\n  bool operator!=(const Rational\
    \ &x) const { return !(*this == x); }\r\n  bool operator<(const Rational &x) const\
    \ { return (x - *this).num > 0; }\r\n  bool operator<=(const Rational &x) const\
    \ { return !(x < *this); }\r\n  bool operator>(const Rational &x) const { return\
    \ x < *this; }\r\n  bool operator>=(const Rational &x) const { return !(*this\
    \ < x); }\r\n  Rational &operator++() { if ((num += den) == 0) den = 1; return\
    \ *this; }\r\n  Rational operator++(int) { Rational res = *this; ++*this; return\
    \ res; }\r\n  Rational &operator--() { if ((num -= den) == 0) den = 1; return\
    \ *this; }\r\n  Rational operator--(int) { Rational res = *this; --*this; return\
    \ res; }\r\n  Rational operator+() const { return *this; }\r\n  Rational operator-()\
    \ const { return Rational(-num, den); }\r\n  Rational operator+(const Rational\
    \ &x) const { return Rational(*this) += x; }\r\n  Rational operator-(const Rational\
    \ &x) const { return Rational(*this) -= x; }\r\n  Rational operator*(const Rational\
    \ &x) const { return Rational(*this) *= x; }\r\n  Rational operator/(const Rational\
    \ &x) const { return Rational(*this) /= x; }\r\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const Rational &x) {\r\n    if (x.den == 1) return os << x.num;\r\n   \
    \ return os << x.num << '/' << x.den;\r\n  }\r\nprivate:\r\n  void reduce() {\
    \ T g = std::__gcd(num, den); num /= g; den /= g; if (den < 0) { num = -num; den\
    \ = -den; } }\r\n};\r\nnamespace std {\r\ntemplate <typename T> Rational<T> abs(const\
    \ Rational<T> &x) {Rational<T> res = x; if (res.num < 0) res.num = -res.num; return\
    \ res; }\r\ntemplate <typename T> Rational<T> max(const Rational<T> &a, const\
    \ Rational<T> &b) { return a < b ? b : a; }\r\ntemplate <typename T> Rational<T>\
    \ min(const Rational<T> &a, const Rational<T> &b) { return a < b ? a : b; }\r\n\
    template <typename T> struct numeric_limits<Rational<T>> {\r\n  static constexpr\
    \ Rational<T> max() { return std::numeric_limits<T>::max(); }\r\n  static constexpr\
    \ Rational<T> lowest() { return std::numeric_limits<T>::lowest(); }\r\n};\r\n\
    }  // std\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <limits>\r\
    \n#include <ostream>\r\n\r\ntemplate <typename T = long long>\r\nstruct Rational\
    \ {\r\n  T num, den;\r\n  Rational(): num(0), den(1) {}\r\n  Rational(T num, T\
    \ den = 1) : num(num), den(den) { assert(den != 0); reduce(); }\r\n  template\
    \ <typename Real = long double> Real to_real() const { return static_cast<Real>(num)\
    \ / den; }\r\n  Rational &operator+=(const Rational &x) {\r\n    T g = std::__gcd(den,\
    \ x.den);\r\n    num = num * (x.den / g) + x.num * (den / g); den *= x.den / g;\r\
    \n    reduce();\r\n    return *this;\r\n  }\r\n  Rational &operator-=(const Rational\
    \ &x) { return *this += -x; }\r\n  Rational &operator*=(const Rational &x) {\r\
    \n    T g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);\r\n    num =\
    \ (num / g1) * (x.num / g2); den = (den / g2) * (x.den / g1);\r\n    reduce();\r\
    \n    return *this;\r\n  }\r\n  Rational &operator/=(const Rational &x) { return\
    \ *this *= Rational(x.den, x.num); }\r\n  bool operator==(const Rational &x) const\
    \ { return num == x.num && den == x.den; }\r\n  bool operator!=(const Rational\
    \ &x) const { return !(*this == x); }\r\n  bool operator<(const Rational &x) const\
    \ { return (x - *this).num > 0; }\r\n  bool operator<=(const Rational &x) const\
    \ { return !(x < *this); }\r\n  bool operator>(const Rational &x) const { return\
    \ x < *this; }\r\n  bool operator>=(const Rational &x) const { return !(*this\
    \ < x); }\r\n  Rational &operator++() { if ((num += den) == 0) den = 1; return\
    \ *this; }\r\n  Rational operator++(int) { Rational res = *this; ++*this; return\
    \ res; }\r\n  Rational &operator--() { if ((num -= den) == 0) den = 1; return\
    \ *this; }\r\n  Rational operator--(int) { Rational res = *this; --*this; return\
    \ res; }\r\n  Rational operator+() const { return *this; }\r\n  Rational operator-()\
    \ const { return Rational(-num, den); }\r\n  Rational operator+(const Rational\
    \ &x) const { return Rational(*this) += x; }\r\n  Rational operator-(const Rational\
    \ &x) const { return Rational(*this) -= x; }\r\n  Rational operator*(const Rational\
    \ &x) const { return Rational(*this) *= x; }\r\n  Rational operator/(const Rational\
    \ &x) const { return Rational(*this) /= x; }\r\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const Rational &x) {\r\n    if (x.den == 1) return os << x.num;\r\n   \
    \ return os << x.num << '/' << x.den;\r\n  }\r\nprivate:\r\n  void reduce() {\
    \ T g = std::__gcd(num, den); num /= g; den /= g; if (den < 0) { num = -num; den\
    \ = -den; } }\r\n};\r\nnamespace std {\r\ntemplate <typename T> Rational<T> abs(const\
    \ Rational<T> &x) {Rational<T> res = x; if (res.num < 0) res.num = -res.num; return\
    \ res; }\r\ntemplate <typename T> Rational<T> max(const Rational<T> &a, const\
    \ Rational<T> &b) { return a < b ? b : a; }\r\ntemplate <typename T> Rational<T>\
    \ min(const Rational<T> &a, const Rational<T> &b) { return a < b ? a : b; }\r\n\
    template <typename T> struct numeric_limits<Rational<T>> {\r\n  static constexpr\
    \ Rational<T> max() { return std::numeric_limits<T>::max(); }\r\n  static constexpr\
    \ Rational<T> lowest() { return std::numeric_limits<T>::lowest(); }\r\n};\r\n\
    }  // std\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/rational.hpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/rational.test.cpp
documentation_of: math/rational.hpp
layout: document
title: "\u6709\u7406\u6570 (rational number)"
---


## 参考

- https://github.com/spaghetti-source/algorithm/blob/master/math/rational.cc
- https://github.com/eandbsoftware/libraryCPP/blob/master/!Ratio.cpp


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
