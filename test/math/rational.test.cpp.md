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
  bundledCode: "#line 1 \"test/math/rational.test.cpp\"\n/*\n * @brief \u6570\u5B66\
    /\u6709\u7406\u6570\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <vector>\n\
    \n#line 3 \"math/rational.hpp\"\n// #include <cassert>\n#include <limits>\n#include\
    \ <ostream>\n\ntemplate <typename T = long long>\nstruct Rational {\n  T num,\
    \ den;\n  Rational() : num(0), den(1) {}\n  Rational(const T num, const T den\
    \ = 1) : num(num), den(den) {\n    // assert(den != 0);\n    reduce();\n  }\n\
    \  template <typename Real = long double>\n  Real to_real() const { return static_cast<Real>(num)\
    \ / den; }\n  Rational& operator+=(const Rational& x) {\n    const T g = std::__gcd(den,\
    \ x.den);\n    num = num * (x.den / g) + x.num * (den / g);\n    den *= x.den\
    \ / g;\n    reduce();\n    return *this;\n  }\n  Rational& operator-=(const Rational&\
    \ x) { return *this += -x; }\n  Rational& operator*=(const Rational& x) {\n  \
    \  const T g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);\n    num\
    \ = (num / g1) * (x.num / g2);\n    den = (den / g2) * (x.den / g1);\n    reduce();\n\
    \    return *this;\n  }\n  Rational& operator/=(const Rational& x) {\n    return\
    \ *this *= Rational(x.den, x.num);\n  }\n  bool operator==(const Rational& x)\
    \ const {\n    return num == x.num && den == x.den;\n  }\n  bool operator!=(const\
    \ Rational& x) const { return !(*this == x); }\n  bool operator<(const Rational&\
    \ x) const { return (x - *this).num > 0; }\n  bool operator<=(const Rational&\
    \ x) const { return !(x < *this); }\n  bool operator>(const Rational& x) const\
    \ { return x < *this; }\n  bool operator>=(const Rational& x) const { return !(*this\
    \ < x); }\n  Rational& operator++() {\n    if ((num += den) == 0) den = 1;\n \
    \   return *this;\n  }\n  Rational operator++(int) {\n    const Rational res =\
    \ *this;\n    ++*this;\n    return res;\n  }\n  Rational& operator--() {\n   \
    \ if ((num -= den) == 0) den = 1;\n    return *this;\n  }\n  Rational operator--(int)\
    \ {\n    const Rational res = *this;\n    --*this;\n    return res;\n  }\n  Rational\
    \ operator+() const { return *this; }\n  Rational operator-() const { return Rational(-num,\
    \ den); }\n  Rational operator+(const Rational& x) const { return Rational(*this)\
    \ += x; }\n  Rational operator-(const Rational& x) const { return Rational(*this)\
    \ -= x; }\n  Rational operator*(const Rational& x) const { return Rational(*this)\
    \ *= x; }\n  Rational operator/(const Rational& x) const { return Rational(*this)\
    \ /= x; }\n  friend std::ostream& operator<<(std::ostream& os, const Rational&\
    \ x) {\n    if (x.den == 1) return os << x.num;\n    return os << x.num << '/'\
    \ << x.den;\n  }\n private:\n  void reduce() {\n    const T g = std::__gcd(num,\
    \ den);\n    num /= g;\n    den /= g;\n    if (den < 0) {\n      num = -num;\n\
    \      den = -den;\n    }\n  }\n};\nnamespace std {\ntemplate <typename T>\nRational<T>\
    \ abs(Rational<T> x) {\n  if (x.num < 0) x.num = -x.num;\n  return x;\n}\ntemplate\
    \ <typename T>\nRational<T> max(const Rational<T>& a, const Rational<T>& b) {\n\
    \  return a < b ? b : a;\n}\ntemplate <typename T>\nRational<T> min(const Rational<T>&\
    \ a, const Rational<T>& b) {\n  return a < b ? a : b;\n}\ntemplate <typename T>\
    \ struct numeric_limits<Rational<T>> {\n  static constexpr Rational<T> max() {\
    \ return std::numeric_limits<T>::max(); }\n  static constexpr Rational<T> lowest()\
    \ {\n    return std::numeric_limits<T>::lowest();\n  }\n};\n}  // namespace std\n\
    #line 12 \"test/math/rational.test.cpp\"\n\nint main() {\n  using rational = Rational<>;\n\
    \  constexpr int OCCURRENCE = 20;\n  int p[OCCURRENCE + 1]{};\n  std::fill(p,\
    \ p + (OCCURRENCE + 1), 1);\n  for (int i = 1; i <= OCCURRENCE; ++i) {\n    p[i]\
    \ = p[i - 1] * 2;\n  }\n  while (true) {\n    std::string s;\n    std::cin >>\
    \ s;\n    if (s == \"#\") break;\n    const int n = s.length();\n    std::vector<int>\
    \ dir;\n    for (int i = 0; i < n;) {\n      if (s[i] == 'n') {\n        dir.emplace_back(0);\n\
    \        i += 5;\n      } else {\n        dir.emplace_back(90);\n        i +=\
    \ 4;\n      }\n    }\n    std::reverse(dir.begin(), dir.end());\n    rational\
    \ ans = dir.front();\n    for (int i = 1; i < dir.size(); ++i) {\n      ans +=\
    \ rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);\n    }\n    std::cout << ans <<\
    \ '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u6709\u7406\u6570\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <vector>\n\
    \n#include \"../../math/rational.hpp\"\n\nint main() {\n  using rational = Rational<>;\n\
    \  constexpr int OCCURRENCE = 20;\n  int p[OCCURRENCE + 1]{};\n  std::fill(p,\
    \ p + (OCCURRENCE + 1), 1);\n  for (int i = 1; i <= OCCURRENCE; ++i) {\n    p[i]\
    \ = p[i - 1] * 2;\n  }\n  while (true) {\n    std::string s;\n    std::cin >>\
    \ s;\n    if (s == \"#\") break;\n    const int n = s.length();\n    std::vector<int>\
    \ dir;\n    for (int i = 0; i < n;) {\n      if (s[i] == 'n') {\n        dir.emplace_back(0);\n\
    \        i += 5;\n      } else {\n        dir.emplace_back(90);\n        i +=\
    \ 4;\n      }\n    }\n    std::reverse(dir.begin(), dir.end());\n    rational\
    \ ans = dir.front();\n    for (int i = 1; i < dir.size(); ++i) {\n      ans +=\
    \ rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);\n    }\n    std::cout << ans <<\
    \ '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/rational.hpp
  isVerificationFile: true
  path: test/math/rational.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/rational.test.cpp
layout: document
redirect_from:
- /verify/test/math/rational.test.cpp
- /verify/test/math/rational.test.cpp.html
title: "\u6570\u5B66/\u6709\u7406\u6570"
---
