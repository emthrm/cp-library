---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/rational.hpp
    title: "\u6709\u7406\u6570 (rational number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
    document_title: "\u6570\u5B66/\u6709\u7406\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
  bundledCode: "#line 1 \"test/math/rational.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u6709\u7406\u6570\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <string>\r\n#include\
    \ <vector>\r\n\r\n#line 3 \"math/rational.hpp\"\n// #include <cassert>\r\n#include\
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
    \n  }\r\n};\r\n}  // namespace std\r\n#line 12 \"test/math/rational.test.cpp\"\
    \n\r\nint main() {\r\n  using rational = Rational<>;\r\n  constexpr int OCCURRENCE\
    \ = 20;\r\n  int p[OCCURRENCE + 1]{};\r\n  std::fill(p, p + (OCCURRENCE + 1),\
    \ 1);\r\n  for (int i = 1; i <= OCCURRENCE; ++i) {\r\n    p[i] = p[i - 1] * 2;\r\
    \n  }\r\n  while (true) {\r\n    std::string s;\r\n    std::cin >> s;\r\n    if\
    \ (s == \"#\") break;\r\n    const int n = s.length();\r\n    std::vector<int>\
    \ dir;\r\n    for (int i = 0; i < n;) {\r\n      if (s[i] == 'n') {\r\n      \
    \  dir.emplace_back(0);\r\n        i += 5;\r\n      } else {\r\n        dir.emplace_back(90);\r\
    \n        i += 4;\r\n      }\r\n    }\r\n    std::reverse(dir.begin(), dir.end());\r\
    \n    rational ans = dir.front();\r\n    for (int i = 1; i < dir.size(); ++i)\
    \ {\r\n      ans += rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);\r\n    }\r\n\
    \    std::cout << ans << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u6709\u7406\u6570\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\n#include \"../../math/rational.hpp\"\r\n\r\nint main() {\r\n  using rational\
    \ = Rational<>;\r\n  constexpr int OCCURRENCE = 20;\r\n  int p[OCCURRENCE + 1]{};\r\
    \n  std::fill(p, p + (OCCURRENCE + 1), 1);\r\n  for (int i = 1; i <= OCCURRENCE;\
    \ ++i) {\r\n    p[i] = p[i - 1] * 2;\r\n  }\r\n  while (true) {\r\n    std::string\
    \ s;\r\n    std::cin >> s;\r\n    if (s == \"#\") break;\r\n    const int n =\
    \ s.length();\r\n    std::vector<int> dir;\r\n    for (int i = 0; i < n;) {\r\n\
    \      if (s[i] == 'n') {\r\n        dir.emplace_back(0);\r\n        i += 5;\r\
    \n      } else {\r\n        dir.emplace_back(90);\r\n        i += 4;\r\n     \
    \ }\r\n    }\r\n    std::reverse(dir.begin(), dir.end());\r\n    rational ans\
    \ = dir.front();\r\n    for (int i = 1; i < dir.size(); ++i) {\r\n      ans +=\
    \ rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);\r\n    }\r\n    std::cout << ans\
    \ << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/rational.hpp
  isVerificationFile: true
  path: test/math/rational.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/rational.test.cpp
layout: document
redirect_from:
- /verify/test/math/rational.test.cpp
- /verify/test/math/rational.test.cpp.html
title: "\u6570\u5B66/\u6709\u7406\u6570"
---
