---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/rational.hpp
    title: "\u6709\u7406\u6570 (rational number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
    document_title: "\u6570\u5B66/\u6709\u7406\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
  bundledCode: "#line 1 \"test/math/rational.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u6709\u7406\u6570\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/math/rational.hpp\"\
    \n\n\n\n// #include <cassert>\n#include <compare>\n#include <limits>\n#include\
    \ <numeric>\n#include <ostream>\n\nnamespace emthrm {\n\ntemplate <typename T\
    \ = long long>\nstruct Rational {\n  T num, den;\n\n  Rational() : num(0), den(1)\
    \ {}\n  Rational(const T num, const T den = 1) : num(num), den(den) {\n    //\
    \ assert(den != 0);\n    reduce();\n  }\n\n  template <typename Real = long double>\n\
    \  Real to_real() const { return static_cast<Real>(num) / den; }\n\n  Rational&\
    \ operator+=(const Rational& x) {\n    const T g = std::gcd(den, x.den);\n   \
    \ num = num * (x.den / g) + x.num * (den / g);\n    den *= x.den / g;\n    reduce();\n\
    \    return *this;\n  }\n  Rational& operator-=(const Rational& x) { return *this\
    \ += -x; }\n\n  Rational& operator*=(const Rational& x) {\n    const T g1 = std::gcd(num,\
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
    \  }\n};\n\n}  // namespace std\n\n\n#line 14 \"test/math/rational.test.cpp\"\n\
    \nint main() {\n  using rational = emthrm::Rational<>;\n  constexpr int OCCURRENCE\
    \ = 20;\n  int p[OCCURRENCE + 1]{};\n  std::fill(p, p + (OCCURRENCE + 1), 1);\n\
    \  for (int i = 1; i <= OCCURRENCE; ++i) {\n    p[i] = p[i - 1] * 2;\n  }\n  while\
    \ (true) {\n    std::string s;\n    std::cin >> s;\n    if (s == \"#\") break;\n\
    \    const int n = s.length();\n    std::vector<int> dir;\n    for (int i = 0;\
    \ i < n;) {\n      if (s[i] == 'n') {\n        dir.emplace_back(0);\n        i\
    \ += 5;\n      } else {\n        dir.emplace_back(90);\n        i += 4;\n    \
    \  }\n    }\n    std::reverse(dir.begin(), dir.end());\n    rational ans = dir.front();\n\
    \    for (int i = 1; std::cmp_less(i, dir.size()); ++i) {\n      ans += rational(90,\
    \ p[i]) * (dir[i] == 0 ? -1 : 1);\n    }\n    std::cout << ans << '\\n';\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u6709\u7406\u6570\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/math/rational.hpp\"\n\nint main() {\n \
    \ using rational = emthrm::Rational<>;\n  constexpr int OCCURRENCE = 20;\n  int\
    \ p[OCCURRENCE + 1]{};\n  std::fill(p, p + (OCCURRENCE + 1), 1);\n  for (int i\
    \ = 1; i <= OCCURRENCE; ++i) {\n    p[i] = p[i - 1] * 2;\n  }\n  while (true)\
    \ {\n    std::string s;\n    std::cin >> s;\n    if (s == \"#\") break;\n    const\
    \ int n = s.length();\n    std::vector<int> dir;\n    for (int i = 0; i < n;)\
    \ {\n      if (s[i] == 'n') {\n        dir.emplace_back(0);\n        i += 5;\n\
    \      } else {\n        dir.emplace_back(90);\n        i += 4;\n      }\n   \
    \ }\n    std::reverse(dir.begin(), dir.end());\n    rational ans = dir.front();\n\
    \    for (int i = 1; std::cmp_less(i, dir.size()); ++i) {\n      ans += rational(90,\
    \ p[i]) * (dir[i] == 0 ? -1 : 1);\n    }\n    std::cout << ans << '\\n';\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/rational.hpp
  isVerificationFile: true
  path: test/math/rational.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/rational.test.cpp
layout: document
redirect_from:
- /verify/test/math/rational.test.cpp
- /verify/test/math/rational.test.cpp.html
title: "\u6570\u5B66/\u6709\u7406\u6570"
---
