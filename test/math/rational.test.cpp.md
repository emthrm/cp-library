---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/rational.hpp
    title: "\u6709\u7406\u6570 (rational number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
    document_title: "\u6570\u5B66/\u6709\u7406\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
  bundledCode: "#line 1 \"test/math/rational.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u6709\u7406\u6570\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <string>\r\n#include\
    \ <vector>\r\n#line 3 \"math/rational.hpp\"\n#include <cassert>\r\n#include <limits>\r\
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
    }  // std\r\n#line 11 \"test/math/rational.test.cpp\"\n\r\nint main() {\r\n  using\
    \ rational = Rational<>;\r\n  constexpr int OCCURRENCE = 20;\r\n  std::vector<int>\
    \ p(OCCURRENCE + 1, 1);\r\n  for (int i = 1; i <= OCCURRENCE; ++i) p[i] = p[i\
    \ - 1] * 2;\r\n  while (true) {\r\n    std::string s;\r\n    std::cin >> s;\r\n\
    \    if (s == \"#\") break;\r\n    int n = s.length();\r\n    std::vector<int>\
    \ dir;\r\n    for (int i = 0; i < n;) {\r\n      if (s[i] == 'n') {\r\n      \
    \  dir.emplace_back(0);\r\n        i += 5;\r\n      } else {\r\n        dir.emplace_back(90);\r\
    \n        i += 4;\r\n      }\r\n    }\r\n    std::reverse(dir.begin(), dir.end());\r\
    \n    rational ans = dir[0];\r\n    for (int i = 1; i < dir.size(); ++i) ans +=\
    \ rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);\r\n    std::cout << ans << '\\\
    n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u6709\u7406\u6570\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\
    \n#include \"../../math/rational.hpp\"\r\n\r\nint main() {\r\n  using rational\
    \ = Rational<>;\r\n  constexpr int OCCURRENCE = 20;\r\n  std::vector<int> p(OCCURRENCE\
    \ + 1, 1);\r\n  for (int i = 1; i <= OCCURRENCE; ++i) p[i] = p[i - 1] * 2;\r\n\
    \  while (true) {\r\n    std::string s;\r\n    std::cin >> s;\r\n    if (s ==\
    \ \"#\") break;\r\n    int n = s.length();\r\n    std::vector<int> dir;\r\n  \
    \  for (int i = 0; i < n;) {\r\n      if (s[i] == 'n') {\r\n        dir.emplace_back(0);\r\
    \n        i += 5;\r\n      } else {\r\n        dir.emplace_back(90);\r\n     \
    \   i += 4;\r\n      }\r\n    }\r\n    std::reverse(dir.begin(), dir.end());\r\
    \n    rational ans = dir[0];\r\n    for (int i = 1; i < dir.size(); ++i) ans +=\
    \ rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);\r\n    std::cout << ans << '\\\
    n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/rational.hpp
  isVerificationFile: true
  path: test/math/rational.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/rational.test.cpp
layout: document
redirect_from:
- /verify/test/math/rational.test.cpp
- /verify/test/math/rational.test.cpp.html
title: "\u6570\u5B66/\u6709\u7406\u6570"
---
