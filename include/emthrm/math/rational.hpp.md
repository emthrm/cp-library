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
  bundledCode: "#line 1 \"include/emthrm/math/rational.hpp\"\n\n\n\n// #include <cassert>\n\
    #include <compare>\n#include <limits>\n#include <numeric>\n#include <ostream>\n\
    \nnamespace emthrm {\n\ntemplate <typename T = long long>\nstruct Rational {\n\
    \  T num, den;\n\n  Rational() : num(0), den(1) {}\n  Rational(const T num, const\
    \ T den = 1) : num(num), den(den) {\n    // assert(den != 0);\n    reduce();\n\
    \  }\n\n  template <typename Real = long double>\n  Real to_real() const { return\
    \ static_cast<Real>(num) / den; }\n\n  Rational& operator+=(const Rational& x)\
    \ {\n    const T g = std::gcd(den, x.den);\n    num = num * (x.den / g) + x.num\
    \ * (den / g);\n    den *= x.den / g;\n    reduce();\n    return *this;\n  }\n\
    \  Rational& operator-=(const Rational& x) { return *this += -x; }\n\n  Rational&\
    \ operator*=(const Rational& x) {\n    const T g1 = std::gcd(num, x.den), g2 =\
    \ std::gcd(den, x.num);\n    num = (num / g1) * (x.num / g2);\n    den = (den\
    \ / g2) * (x.den / g1);\n    reduce();\n    return *this;\n  }\n  Rational& operator/=(const\
    \ Rational& x) {\n    return *this *= Rational(x.den, x.num);\n  }\n\n  auto operator<=>(const\
    \ Rational& x) const {\n    return num * x.den <=> x.num * den;\n  }\n  bool operator==(const\
    \ Rational& x) const {\n    return num == x.num && den == x.den;\n  }\n\n  Rational&\
    \ operator++() {\n    if ((num += den) == 0) den = 1;\n    return *this;\n  }\n\
    \  Rational operator++(int) {\n    const Rational res = *this;\n    ++*this;\n\
    \    return res;\n  }\n  Rational& operator--() {\n    if ((num -= den) == 0)\
    \ den = 1;\n    return *this;\n  }\n  Rational operator--(int) {\n    const Rational\
    \ res = *this;\n    --*this;\n    return res;\n  }\n\n  Rational operator+() const\
    \ { return *this; }\n  Rational operator-() const { return Rational(-num, den);\
    \ }\n\n  Rational operator+(const Rational& x) const { return Rational(*this)\
    \ += x; }\n  Rational operator-(const Rational& x) const { return Rational(*this)\
    \ -= x; }\n  Rational operator*(const Rational& x) const { return Rational(*this)\
    \ *= x; }\n  Rational operator/(const Rational& x) const { return Rational(*this)\
    \ /= x; }\n\n  friend std::ostream& operator<<(std::ostream& os, const Rational&\
    \ x) {\n    if (x.den == 1) return os << x.num;\n    return os << x.num << '/'\
    \ << x.den;\n  }\n\n private:\n  void reduce() {\n    const T g = std::gcd(num,\
    \ den);\n    num /= g;\n    den /= g;\n    if (den < 0) {\n      num = -num;\n\
    \      den = -den;\n    }\n  }\n};\n\n}  // namespace emthrm\n\nnamespace std\
    \ {\n\ntemplate <typename T>\nemthrm::Rational<T> abs(emthrm::Rational<T> x) {\n\
    \  if (x.num < 0) x.num = -x.num;\n  return x;\n}\n\ntemplate <typename T>\nemthrm::Rational<T>\
    \ max(const emthrm::Rational<T>& a,\n                        const emthrm::Rational<T>&\
    \ b) {\n  return a < b ? b : a;\n}\n\ntemplate <typename T>\nemthrm::Rational<T>\
    \ min(const emthrm::Rational<T>& a,\n                        const emthrm::Rational<T>&\
    \ b) {\n  return a < b ? a : b;\n}\n\ntemplate <typename T> struct numeric_limits<emthrm::Rational<T>>\
    \ {\n  static constexpr emthrm::Rational<T> max() {\n    return std::numeric_limits<T>::max();\n\
    \  }\n  static constexpr emthrm::Rational<T> lowest() {\n    return std::numeric_limits<T>::lowest();\n\
    \  }\n};\n\n}  // namespace std\n\n\n"
  code: "#ifndef EMTHRM_MATH_RATIONAL_HPP_\n#define EMTHRM_MATH_RATIONAL_HPP_\n\n\
    // #include <cassert>\n#include <compare>\n#include <limits>\n#include <numeric>\n\
    #include <ostream>\n\nnamespace emthrm {\n\ntemplate <typename T = long long>\n\
    struct Rational {\n  T num, den;\n\n  Rational() : num(0), den(1) {}\n  Rational(const\
    \ T num, const T den = 1) : num(num), den(den) {\n    // assert(den != 0);\n \
    \   reduce();\n  }\n\n  template <typename Real = long double>\n  Real to_real()\
    \ const { return static_cast<Real>(num) / den; }\n\n  Rational& operator+=(const\
    \ Rational& x) {\n    const T g = std::gcd(den, x.den);\n    num = num * (x.den\
    \ / g) + x.num * (den / g);\n    den *= x.den / g;\n    reduce();\n    return\
    \ *this;\n  }\n  Rational& operator-=(const Rational& x) { return *this += -x;\
    \ }\n\n  Rational& operator*=(const Rational& x) {\n    const T g1 = std::gcd(num,\
    \ x.den), g2 = std::gcd(den, x.num);\n    num = (num / g1) * (x.num / g2);\n \
    \   den = (den / g2) * (x.den / g1);\n    reduce();\n    return *this;\n  }\n\
    \  Rational& operator/=(const Rational& x) {\n    return *this *= Rational(x.den,\
    \ x.num);\n  }\n\n  auto operator<=>(const Rational& x) const {\n    return num\
    \ * x.den <=> x.num * den;\n  }\n  bool operator==(const Rational& x) const {\n\
    \    return num == x.num && den == x.den;\n  }\n\n  Rational& operator++() {\n\
    \    if ((num += den) == 0) den = 1;\n    return *this;\n  }\n  Rational operator++(int)\
    \ {\n    const Rational res = *this;\n    ++*this;\n    return res;\n  }\n  Rational&\
    \ operator--() {\n    if ((num -= den) == 0) den = 1;\n    return *this;\n  }\n\
    \  Rational operator--(int) {\n    const Rational res = *this;\n    --*this;\n\
    \    return res;\n  }\n\n  Rational operator+() const { return *this; }\n  Rational\
    \ operator-() const { return Rational(-num, den); }\n\n  Rational operator+(const\
    \ Rational& x) const { return Rational(*this) += x; }\n  Rational operator-(const\
    \ Rational& x) const { return Rational(*this) -= x; }\n  Rational operator*(const\
    \ Rational& x) const { return Rational(*this) *= x; }\n  Rational operator/(const\
    \ Rational& x) const { return Rational(*this) /= x; }\n\n  friend std::ostream&\
    \ operator<<(std::ostream& os, const Rational& x) {\n    if (x.den == 1) return\
    \ os << x.num;\n    return os << x.num << '/' << x.den;\n  }\n\n private:\n  void\
    \ reduce() {\n    const T g = std::gcd(num, den);\n    num /= g;\n    den /= g;\n\
    \    if (den < 0) {\n      num = -num;\n      den = -den;\n    }\n  }\n};\n\n\
    }  // namespace emthrm\n\nnamespace std {\n\ntemplate <typename T>\nemthrm::Rational<T>\
    \ abs(emthrm::Rational<T> x) {\n  if (x.num < 0) x.num = -x.num;\n  return x;\n\
    }\n\ntemplate <typename T>\nemthrm::Rational<T> max(const emthrm::Rational<T>&\
    \ a,\n                        const emthrm::Rational<T>& b) {\n  return a < b\
    \ ? b : a;\n}\n\ntemplate <typename T>\nemthrm::Rational<T> min(const emthrm::Rational<T>&\
    \ a,\n                        const emthrm::Rational<T>& b) {\n  return a < b\
    \ ? a : b;\n}\n\ntemplate <typename T> struct numeric_limits<emthrm::Rational<T>>\
    \ {\n  static constexpr emthrm::Rational<T> max() {\n    return std::numeric_limits<T>::max();\n\
    \  }\n  static constexpr emthrm::Rational<T> lowest() {\n    return std::numeric_limits<T>::lowest();\n\
    \  }\n};\n\n}  // namespace std\n\n#endif  // EMTHRM_MATH_RATIONAL_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/rational.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/rational.test.cpp
documentation_of: include/emthrm/math/rational.hpp
layout: document
title: "\u6709\u7406\u6570 (rational number)"
---


## 参考文献

- https://github.com/spaghetti-source/algorithm/blob/208bcfd781e9c37aedee117ce45d5a4a5bab5fa1/math/rational.cc
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!Ratio.cpp~~


## TODO

- Stern–Brocot tree
  - https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree
  - http://satashun.hatenablog.com/entry/2018/12/13/163524
  - http://blue-jam.hatenablog.com/entry/20110306/1299415086
  - https://rsk0315.hatenablog.com/entry/2023/04/17/022705
  - ~~http://www.prefield.com/algorithm/math/stern_brocot_tree.html~~
  - https://tjkendev.github.io/procon-library/python/math/stern-brocot-tree.html
  - https://sotanishy.github.io/cp-library-cpp/math/stern_brocot_tree.hpp
  - https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146184
  - https://atcoder.jp/contests/abc273/tasks/abc273_h
  - https://yukicoder.me/problems/no/2266
- ファレイ数列 (Farey sequence)
  - https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%83%AC%E3%82%A4%E6%95%B0%E5%88%97
  - https://mathtrain.jp/farey
  - http://kagamiz.hatenablog.com/entry/2012/12/01/225751
  - https://sotanishy.github.io/cp-library-cpp/math/farey_sequence.hpp
- 連分数 (continued fraction)
  - https://ja.wikipedia.org/wiki/%E9%80%A3%E5%88%86%E6%95%B0
  - https://mathtrain.jp/renbunsu
  - https://github.com/spaghetti-source/algorithm/blob/master/math/continued_fraction.cc


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2589/review/4088153/emthrm/C++14
