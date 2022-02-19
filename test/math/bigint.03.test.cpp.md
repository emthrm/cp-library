---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B
    document_title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B
  bundledCode: "#line 1 \"test/math/bigint.03.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97)\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"math/bigint.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <cmath>\r\n#include <iomanip>\r\n#line 7 \"math/bigint.hpp\"\
    \n#include <iterator>\r\n#include <limits>\r\n#include <sstream>\r\n#include <string>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <int LogB = 9, int B\
    \ = 1000000000>  // B = 10^{LogB}\r\nstruct BigInt {\r\n  int sgn;\r\n  std::vector<int>\
    \ data;\r\n  BigInt(const long long val = 0) { *this = val; }\r\n  BigInt(const\
    \ std::string& s) { *this = s; }\r\n  std::vector<long long> convert_base(const\
    \ int next_log_b,\r\n                                      const int next_b) const\
    \ {\r\n    assert(next_b == static_cast<int>(std::round(std::pow(10, next_log_b))));\r\
    \n    const int max_base = std::max(LogB, next_log_b);\r\n    std::vector<long\
    \ long> p(max_base + 1, 1);\r\n    for (int i = 1; i <= max_base; ++i) {\r\n \
    \     p[i] = p[i - 1] * 10;\r\n    }\r\n    std::vector<long long> res;\r\n  \
    \  long long cur_val = 0;\r\n    int cur_log_b = 0;\r\n    for (const int e :\
    \ data) {\r\n      cur_val += p[cur_log_b] * e;\r\n      cur_log_b += LogB;\r\n\
    \      for (; cur_log_b >= next_log_b; cur_log_b -= next_log_b) {\r\n        res.emplace_back(cur_val\
    \ % next_b);\r\n        cur_val /= next_b;\r\n      }\r\n    }\r\n    res.emplace_back(cur_val);\r\
    \n    while (!res.empty() && res.back() == 0) res.pop_back();\r\n    return res;\r\
    \n  }\r\n  int digit_sum() const {\r\n    assert(sgn == 1);\r\n    int res = 0;\r\
    \n    for (char c : to_string()) res += c - '0';\r\n    return res;\r\n  }\r\n\
    \  int length() const {\r\n    if (data.empty()) return 0;\r\n    int res = LogB\
    \ * (data.size() - 1);\r\n    for (int tmp = data.back(); tmp > 0; tmp /= 10)\
    \ {\r\n      ++res;\r\n    }\r\n    return res;\r\n  }\r\n  BigInt pow(BigInt\
    \ exponent) const {\r\n    BigInt res = 1, tmp = *this;\r\n    for (; exponent\
    \ > 0; exponent /= 2) {\r\n      if (exponent.data.front() & 1) res *= tmp;\r\n\
    \      tmp *= tmp;\r\n    }\r\n    return res;\r\n  }\r\n  long long to_llong()\
    \ const {\r\n    assert(*this >= std::numeric_limits<long long>::min() &&\r\n\
    \           *this <= std::numeric_limits<long long>::max());\r\n    long long\
    \ res = 0;\r\n    for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i)\
    \ {\r\n      res = res * B + data[i];\r\n    }\r\n    return res;\r\n  }\r\n \
    \ std::string to_string() const {\r\n    std::stringstream ss;\r\n    ss << *this;\r\
    \n    std::string res;\r\n    ss >> res;\r\n    return res;\r\n  }\r\n  void trim()\
    \ {\r\n    while (!data.empty() && data.back() == 0) data.pop_back();\r\n    if\
    \ (data.empty()) sgn = 1;\r\n  }\r\n  BigInt& operator=(long long val) {\r\n \
    \   if (val < 0) {\r\n      sgn = -1;\r\n      val = -val;\r\n    } else {\r\n\
    \      sgn = 1;\r\n    }\r\n    data.clear();\r\n    for (; val > 0; val /= B)\
    \ {\r\n      data.emplace_back(val % B);\r\n    }\r\n    return *this;\r\n  }\r\
    \n  BigInt& operator=(const std::string& s) {\r\n    sgn = 1;\r\n    data.clear();\r\
    \n    if (!s.empty()) {\r\n      int tail = 0;\r\n      if (s.front() == '-')\
    \ {\r\n        sgn = -1;\r\n        tail = 1;\r\n      } else if (s.front() ==\
    \ '+') {\r\n        tail = 1;\r\n      }\r\n      for (int i = s.length() - 1;\
    \ i >= tail; i -= LogB) {\r\n        int val = 0;\r\n        for (int j = std::max(tail,\
    \ i - LogB + 1); j <= i; ++j) {\r\n          val = val * 10 + (s[j] - '0');\r\n\
    \        }\r\n        data.emplace_back(val);\r\n      }\r\n    }\r\n    trim();\r\
    \n    return *this;\r\n  }\r\n  BigInt& operator=(const BigInt& x) = default;\r\
    \n  BigInt& operator+=(const BigInt& x) {\r\n    if (sgn != x.sgn) return *this\
    \ -= -x;\r\n    if (data.size() < x.data.size()) data.resize(x.data.size(), 0);\r\
    \n    bool carry = false;\r\n    for (int i = 0; i < x.data.size() || carry; ++i)\
    \ {\r\n      if (i == data.size()) data.emplace_back(0);\r\n      data[i] += (i\
    \ < x.data.size() ? x.data[i] : 0) + carry;\r\n      if (data[i] >= B) {\r\n \
    \       carry = true;\r\n        data[i] -= B;\r\n      } else {\r\n        carry\
    \ = false;\r\n      }\r\n    }\r\n    return *this;\r\n  }\r\n  BigInt& operator-=(const\
    \ BigInt& x) {\r\n    if (sgn != x.sgn) return *this += -x;\r\n    if ((sgn ==\
    \ 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\r\n      return *this = -(x -\
    \ *this);\r\n    }\r\n    bool carry = false;\r\n    for (int i = 0; i < data.size()\
    \ || carry; ++i) {\r\n      data[i] -= (i < x.data.size() ? x.data[i] : 0) + carry;\r\
    \n      if (data[i] < 0) {\r\n        carry = true;\r\n        data[i] += B;\r\
    \n      } else {\r\n        carry = false;\r\n      }\r\n    }\r\n    trim();\r\
    \n    return *this;\r\n  }\r\n  BigInt& operator*=(const BigInt& x) {\r\n    constexpr\
    \ int next_log_b = 6, next_b = 1000000;\r\n    std::vector<long long> this6 =\
    \ convert_base(next_log_b, next_b);\r\n    std::vector<long long> x6 = x.convert_base(next_log_b,\
    \ next_b);\r\n    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),\r\
    \n                                           &x6, 0, x6.size());\r\n    for (int\
    \ i = 0; i < res.size(); ++i) {\r\n      const long long quo = res[i] / next_b;\r\
    \n      if (quo > 0) {\r\n        if (i + 1 == res.size()) {\r\n          res.emplace_back(quo);\r\
    \n        } else {\r\n          res[i + 1] += quo;\r\n        }\r\n        res[i]\
    \ %= next_b;\r\n      }\r\n    }\r\n    std::string s = (sgn * x.sgn == 1 ? \"\
    +\" : \"-\");\r\n    for (int i = static_cast<int>(res.size()) - 1; i >= 0; --i)\
    \ {\r\n      const std::string tmp = std::to_string(res[i]);\r\n      s += std::string(next_log_b\
    \ - tmp.length(), '0') + tmp;\r\n    }\r\n    return *this = s;\r\n  }\r\n  BigInt&\
    \ operator/=(int x) { return *this = divide(x).first; }\r\n  BigInt& operator/=(const\
    \ BigInt& x) { return *this = divide(x).first; }\r\n  BigInt& operator%=(int x)\
    \ { return *this = divide(x).second; }\r\n  BigInt& operator%=(const BigInt& x)\
    \ { return *this = divide(x).second; }\r\n  bool operator==(const BigInt& x) const\
    \ {\r\n    if (sgn != x.sgn || data.size() != x.data.size()) return false;\r\n\
    \    const int n = data.size();\r\n    for (int i = 0; i < n; ++i) {\r\n     \
    \ if (data[i] != x.data[i]) return false;\r\n    }\r\n    return true;\r\n  }\r\
    \n  bool operator!=(const BigInt& x) const { return !(*this == x); }\r\n  bool\
    \ operator<(const BigInt& x) const {\r\n    if (sgn != x.sgn) return sgn < x.sgn;\r\
    \n    if (data.size() != x.data.size()) {\r\n      return sgn * data.size() <\
    \ x.sgn * x.data.size();\r\n    }\r\n    for (int i = static_cast<int>(data.size())\
    \ - 1; i >= 0; --i) {\r\n      if (data[i] != x.data[i]) return data[i] * sgn\
    \ < x.data[i] * x.sgn;\r\n    }\r\n    return false;\r\n  }\r\n  bool operator<=(const\
    \ BigInt& x) const { return !(x < *this); }\r\n  bool operator>(const BigInt&\
    \ x) const { return x < *this; }\r\n  bool operator>=(const BigInt& x) const {\
    \ return !(*this < x); }\r\n  BigInt& operator++() { return *this += 1; }\r\n\
    \  BigInt operator++(int) {\r\n    const BigInt res = *this;\r\n    ++*this;\r\
    \n    return res;\r\n  }\r\n  BigInt& operator--() { return *this -= 1; }\r\n\
    \  BigInt operator--(int) {\r\n    const BigInt res = *this;\r\n    --*this;\r\
    \n    return res;\r\n  }\r\n  BigInt operator+() const { return *this; }\r\n \
    \ BigInt operator-() const {\r\n    BigInt res = *this;\r\n    res.sgn = -res.sgn;\r\
    \n    return res;\r\n  }\r\n  BigInt operator+(const BigInt& x) const { return\
    \ BigInt(*this) += x; }\r\n  BigInt operator-(const BigInt& x) const { return\
    \ BigInt(*this) -= x; }\r\n  BigInt operator*(const BigInt& x) const { return\
    \ BigInt(*this) *= x; }\r\n  BigInt operator/(int x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator/(const BigInt& x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator%(int x) const { return BigInt(*this) %= x; }\r\n\
    \  BigInt operator%(const BigInt& x) const { return BigInt(*this) %= x; }\r\n\
    \  friend std::ostream& operator<<(std::ostream& os, const BigInt& x) {\r\n  \
    \  if (x.sgn == -1) os << '-';\r\n    os << (x.data.empty() ? 0 : x.data.back());\r\
    \n    for (int i = static_cast<int>(x.data.size()) - 2; i >= 0; --i) {\r\n   \
    \   os << std::setw(LogB) << std::setfill('0') << x.data[i];\r\n    }\r\n    return\
    \ os;\r\n  }\r\n  friend std::istream& operator>>(std::istream& is, BigInt& x)\
    \ {\r\n    std::string s;\r\n    is >> s;\r\n    x = s;\r\n    return is;\r\n\
    \  }\r\n private:\r\n  std::vector<long long> karatsuba(\r\n      std::vector<long\
    \ long>* a, const int a_l, const int a_r,\r\n      std::vector<long long>* b,\
    \ const int b_l, const int b_r) const {\r\n    const int a_len = a_r - a_l, b_len\
    \ = b_r - b_l;\r\n    if (a_len < b_len) return karatsuba(b, b_l, b_r, a, a_l,\
    \ a_r);\r\n    std::vector<long long> res(a_len + b_len, 0);\r\n    if (b_len\
    \ <= 32) {\r\n      for (int i = a_l; i < a_r; ++i) {\r\n        for (int j =\
    \ b_l; j < b_r; ++j) {\r\n          res[(i - a_l) + (j - b_l)] += (*a)[i] * (*b)[j];\r\
    \n        }\r\n      }\r\n    } else {\r\n      const int mid = (a_len + 1) /\
    \ 2, n = std::min(a_len, mid);\r\n      for (int i = a_l; i + mid < a_r; ++i)\
    \ {\r\n        (*a)[i] += (*a)[i + mid];\r\n      }\r\n      for (int i = b_l;\
    \ i + mid < b_r; ++i) {\r\n        (*b)[i] += (*b)[i + mid];\r\n      }\r\n  \
    \    std::vector<long long> tmp =\r\n          karatsuba(a, a_l, a_l + mid, b,\
    \ b_l, b_l + n);\r\n      std::copy(tmp.begin(), tmp.end(), std::next(res.begin(),\
    \ mid));\r\n      for (int i = a_l; i + mid < a_r; ++i) {\r\n        (*a)[i] -=\
    \ (*a)[i + mid];\r\n      }\r\n      for (int i = b_l; i + mid < b_r; ++i) {\r\
    \n        (*b)[i] -= (*b)[i + mid];\r\n      }\r\n      tmp = karatsuba(a, a_l,\
    \ a_l + mid, b, b_l, b_l + n);\r\n      for (int i = 0; i < tmp.size(); ++i) {\r\
    \n        res[i] += tmp[i];\r\n        res[mid + i] -= tmp[i];\r\n      }\r\n\
    \      tmp = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);\r\n      for (int\
    \ i = 0; i < tmp.size(); ++i) {\r\n        res[mid + i] -= tmp[i];\r\n       \
    \ res[(mid << 1) + i] += tmp[i];\r\n      }\r\n    }\r\n    while (!res.empty()\
    \ && res.back() == 0) res.pop_back();\r\n    return res;\r\n  }\r\n  std::pair<BigInt,\
    \ int> divide(int x) const {\r\n    assert(x != 0);\r\n    BigInt dividend = *this;\r\
    \n    if (x < 0) {\r\n      dividend.sgn = -dividend.sgn;\r\n      x = -x;\r\n\
    \    }\r\n    long long rem = 0;\r\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\r\n      const long long tmp = rem * B + dividend.data[i];\r\
    \n      dividend.data[i] = tmp / x;\r\n      rem = tmp % x;\r\n    }\r\n    dividend.trim();\r\
    \n    return {dividend, static_cast<int>(rem)};\r\n  }\r\n  std::pair<BigInt,\
    \ BigInt> divide(const BigInt& x) const {\r\n    assert(!x.data.empty());\r\n\
    \    const int k = B / (x.data.back() + 1);\r\n    const BigInt dividend = (sgn\
    \ == 1 ? *this : -*this) * k;\r\n    const BigInt divisor = (x.sgn == 1 ? x :\
    \ -x) * k;\r\n    BigInt quo, rem = 0;\r\n    quo.data.resize(dividend.data.size());\r\
    \n    const int n = divisor.data.size();\r\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\r\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\r\
    \n      quo.data[i] =\r\n          ((n < rem.data.size() ? static_cast<long long>(rem.data[n])\
    \ * B : 0)\r\n           + (n - 1 < rem.data.size() ? rem.data[n - 1] : 0))\r\n\
    \          / divisor.data.back();\r\n      rem -= divisor * quo.data[i];\r\n \
    \     while (rem.sgn == -1) {\r\n        rem += divisor;\r\n        --quo.data[i];\r\
    \n      }\r\n    }\r\n    quo.sgn = sgn * x.sgn;\r\n    quo.trim();\r\n    rem.sgn\
    \ = sgn;\r\n    rem.trim();\r\n    return {quo, rem / k};\r\n  }\r\n};\r\nnamespace\
    \ std {\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> __gcd(BigInt<LogB, B>\
    \ a, BigInt<LogB, B> b) {\r\n  while (!b.data.empty()) std::swap(a %= b, b);\r\
    \n  return a;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> __lcm(const\
    \ BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\r\n  return a / std::__gcd(a,\
    \ b) * b;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> abs(const BigInt<LogB,\
    \ B>& x) { return x.sgn == 1 ? x : -x; }\r\ntemplate <int LogB, int B>\r\nBigInt<LogB,\
    \ B> max(const BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\r\n  return a <\
    \ b ? b : a;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> min(const BigInt<LogB,\
    \ B>& a, const BigInt<LogB, B>& b) {\r\n  return a < b ? a : b;\r\n}\r\n}  //\
    \ namespace std\r\n#line 9 \"test/math/bigint.03.test.cpp\"\n\r\nint main() {\r\
    \n  BigInt<> a, b;\r\n  std::cin >> a >> b;\r\n  std::cout << a - b << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97\
    )\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../math/bigint.hpp\"\r\n\r\n\
    int main() {\r\n  BigInt<> a, b;\r\n  std::cin >> a >> b;\r\n  std::cout << a\
    \ - b << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/bigint.hpp
  isVerificationFile: true
  path: test/math/bigint.03.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 23:06:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/bigint.03.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.03.test.cpp
- /verify/test/math/bigint.03.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97)"
---
