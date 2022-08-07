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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_F
    document_title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_F
  bundledCode: "#line 1 \"test/math/bigint.04.test.cpp\"\n/*\n * @brief \u6570\u5B66\
    /\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_F\"\
    \n\n#include <iostream>\n\n#line 2 \"math/bigint.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <iomanip>\n#line 7 \"math/bigint.hpp\"\
    \n#include <iterator>\n#include <limits>\n#include <sstream>\n#include <string>\n\
    #include <utility>\n#include <vector>\n\ntemplate <int LogB = 9, int B = 1000000000>\
    \  // B = 10^{LogB}\nstruct BigInt {\n  int sgn;\n  std::vector<int> data;\n \
    \ BigInt(const long long val = 0) { *this = val; }\n  BigInt(const std::string&\
    \ s) { *this = s; }\n  std::vector<long long> convert_base(const int next_log_b,\n\
    \                                      const int next_b) const {\n    assert(next_b\
    \ == static_cast<int>(std::round(std::pow(10, next_log_b))));\n    const int max_base\
    \ = std::max(LogB, next_log_b);\n    std::vector<long long> p(max_base + 1, 1);\n\
    \    for (int i = 1; i <= max_base; ++i) {\n      p[i] = p[i - 1] * 10;\n    }\n\
    \    std::vector<long long> res;\n    long long cur_val = 0;\n    int cur_log_b\
    \ = 0;\n    for (const int e : data) {\n      cur_val += p[cur_log_b] * e;\n \
    \     cur_log_b += LogB;\n      for (; cur_log_b >= next_log_b; cur_log_b -= next_log_b)\
    \ {\n        res.emplace_back(cur_val % next_b);\n        cur_val /= next_b;\n\
    \      }\n    }\n    res.emplace_back(cur_val);\n    while (!res.empty() && res.back()\
    \ == 0) res.pop_back();\n    return res;\n  }\n  int digit_sum() const {\n   \
    \ assert(sgn == 1);\n    int res = 0;\n    for (char c : to_string()) res += c\
    \ - '0';\n    return res;\n  }\n  int length() const {\n    if (data.empty())\
    \ return 0;\n    int res = LogB * (data.size() - 1);\n    for (int tmp = data.back();\
    \ tmp > 0; tmp /= 10) {\n      ++res;\n    }\n    return res;\n  }\n  BigInt pow(BigInt\
    \ exponent) const {\n    BigInt res = 1, tmp = *this;\n    for (; exponent > 0;\
    \ exponent /= 2) {\n      if (exponent.data.front() & 1) res *= tmp;\n      tmp\
    \ *= tmp;\n    }\n    return res;\n  }\n  long long to_llong() const {\n    assert(*this\
    \ >= std::numeric_limits<long long>::min() &&\n           *this <= std::numeric_limits<long\
    \ long>::max());\n    long long res = 0;\n    for (int i = static_cast<int>(data.size())\
    \ - 1; i >= 0; --i) {\n      res = res * B + data[i];\n    }\n    return res;\n\
    \  }\n  std::string to_string() const {\n    std::stringstream ss;\n    ss <<\
    \ *this;\n    std::string res;\n    ss >> res;\n    return res;\n  }\n  void trim()\
    \ {\n    while (!data.empty() && data.back() == 0) data.pop_back();\n    if (data.empty())\
    \ sgn = 1;\n  }\n  BigInt& operator=(long long val) {\n    if (val < 0) {\n  \
    \    sgn = -1;\n      val = -val;\n    } else {\n      sgn = 1;\n    }\n    data.clear();\n\
    \    for (; val > 0; val /= B) {\n      data.emplace_back(val % B);\n    }\n \
    \   return *this;\n  }\n  BigInt& operator=(const std::string& s) {\n    sgn =\
    \ 1;\n    data.clear();\n    if (!s.empty()) {\n      int tail = 0;\n      if\
    \ (s.front() == '-') {\n        sgn = -1;\n        tail = 1;\n      } else if\
    \ (s.front() == '+') {\n        tail = 1;\n      }\n      for (int i = s.length()\
    \ - 1; i >= tail; i -= LogB) {\n        int val = 0;\n        for (int j = std::max(tail,\
    \ i - LogB + 1); j <= i; ++j) {\n          val = val * 10 + (s[j] - '0');\n  \
    \      }\n        data.emplace_back(val);\n      }\n    }\n    trim();\n    return\
    \ *this;\n  }\n  BigInt& operator=(const BigInt& x) = default;\n  BigInt& operator+=(const\
    \ BigInt& x) {\n    if (sgn != x.sgn) return *this -= -x;\n    if (data.size()\
    \ < x.data.size()) data.resize(x.data.size(), 0);\n    bool carry = false;\n \
    \   for (int i = 0; i < x.data.size() || carry; ++i) {\n      if (i == data.size())\
    \ data.emplace_back(0);\n      data[i] += (i < x.data.size() ? x.data[i] : 0)\
    \ + carry;\n      if (data[i] >= B) {\n        carry = true;\n        data[i]\
    \ -= B;\n      } else {\n        carry = false;\n      }\n    }\n    return *this;\n\
    \  }\n  BigInt& operator-=(const BigInt& x) {\n    if (sgn != x.sgn) return *this\
    \ += -x;\n    if ((sgn == 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\n   \
    \   return *this = -(x - *this);\n    }\n    bool carry = false;\n    for (int\
    \ i = 0; i < data.size() || carry; ++i) {\n      data[i] -= (i < x.data.size()\
    \ ? x.data[i] : 0) + carry;\n      if (data[i] < 0) {\n        carry = true;\n\
    \        data[i] += B;\n      } else {\n        carry = false;\n      }\n    }\n\
    \    trim();\n    return *this;\n  }\n  BigInt& operator*=(const BigInt& x) {\n\
    \    constexpr int next_log_b = 6, next_b = 1000000;\n    std::vector<long long>\
    \ this6 = convert_base(next_log_b, next_b);\n    std::vector<long long> x6 = x.convert_base(next_log_b,\
    \ next_b);\n    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),\n\
    \                                           &x6, 0, x6.size());\n    for (int\
    \ i = 0; i < res.size(); ++i) {\n      const long long quo = res[i] / next_b;\n\
    \      if (quo > 0) {\n        if (i + 1 == res.size()) {\n          res.emplace_back(quo);\n\
    \        } else {\n          res[i + 1] += quo;\n        }\n        res[i] %=\
    \ next_b;\n      }\n    }\n    std::string s = (sgn * x.sgn == 1 ? \"+\" : \"\
    -\");\n    for (int i = static_cast<int>(res.size()) - 1; i >= 0; --i) {\n   \
    \   const std::string tmp = std::to_string(res[i]);\n      s += std::string(next_log_b\
    \ - tmp.length(), '0') + tmp;\n    }\n    return *this = s;\n  }\n  BigInt& operator/=(int\
    \ x) { return *this = divide(x).first; }\n  BigInt& operator/=(const BigInt& x)\
    \ { return *this = divide(x).first; }\n  BigInt& operator%=(int x) { return *this\
    \ = divide(x).second; }\n  BigInt& operator%=(const BigInt& x) { return *this\
    \ = divide(x).second; }\n  bool operator==(const BigInt& x) const {\n    if (sgn\
    \ != x.sgn || data.size() != x.data.size()) return false;\n    const int n = data.size();\n\
    \    for (int i = 0; i < n; ++i) {\n      if (data[i] != x.data[i]) return false;\n\
    \    }\n    return true;\n  }\n  bool operator!=(const BigInt& x) const { return\
    \ !(*this == x); }\n  bool operator<(const BigInt& x) const {\n    if (sgn !=\
    \ x.sgn) return sgn < x.sgn;\n    if (data.size() != x.data.size()) {\n      return\
    \ sgn * data.size() < x.sgn * x.data.size();\n    }\n    for (int i = static_cast<int>(data.size())\
    \ - 1; i >= 0; --i) {\n      if (data[i] != x.data[i]) return data[i] * sgn <\
    \ x.data[i] * x.sgn;\n    }\n    return false;\n  }\n  bool operator<=(const BigInt&\
    \ x) const { return !(x < *this); }\n  bool operator>(const BigInt& x) const {\
    \ return x < *this; }\n  bool operator>=(const BigInt& x) const { return !(*this\
    \ < x); }\n  BigInt& operator++() { return *this += 1; }\n  BigInt operator++(int)\
    \ {\n    const BigInt res = *this;\n    ++*this;\n    return res;\n  }\n  BigInt&\
    \ operator--() { return *this -= 1; }\n  BigInt operator--(int) {\n    const BigInt\
    \ res = *this;\n    --*this;\n    return res;\n  }\n  BigInt operator+() const\
    \ { return *this; }\n  BigInt operator-() const {\n    BigInt res = *this;\n \
    \   res.sgn = -res.sgn;\n    return res;\n  }\n  BigInt operator+(const BigInt&\
    \ x) const { return BigInt(*this) += x; }\n  BigInt operator-(const BigInt& x)\
    \ const { return BigInt(*this) -= x; }\n  BigInt operator*(const BigInt& x) const\
    \ { return BigInt(*this) *= x; }\n  BigInt operator/(int x) const { return BigInt(*this)\
    \ /= x; }\n  BigInt operator/(const BigInt& x) const { return BigInt(*this) /=\
    \ x; }\n  BigInt operator%(int x) const { return BigInt(*this) %= x; }\n  BigInt\
    \ operator%(const BigInt& x) const { return BigInt(*this) %= x; }\n  friend std::ostream&\
    \ operator<<(std::ostream& os, const BigInt& x) {\n    if (x.sgn == -1) os <<\
    \ '-';\n    os << (x.data.empty() ? 0 : x.data.back());\n    for (int i = static_cast<int>(x.data.size())\
    \ - 2; i >= 0; --i) {\n      os << std::setw(LogB) << std::setfill('0') << x.data[i];\n\
    \    }\n    return os;\n  }\n  friend std::istream& operator>>(std::istream& is,\
    \ BigInt& x) {\n    std::string s;\n    is >> s;\n    x = s;\n    return is;\n\
    \  }\n private:\n  std::vector<long long> karatsuba(\n      std::vector<long long>*\
    \ a, const int a_l, const int a_r,\n      std::vector<long long>* b, const int\
    \ b_l, const int b_r) const {\n    const int a_len = a_r - a_l, b_len = b_r -\
    \ b_l;\n    if (a_len < b_len) return karatsuba(b, b_l, b_r, a, a_l, a_r);\n \
    \   std::vector<long long> res(a_len + b_len, 0);\n    if (b_len <= 32) {\n  \
    \    for (int i = a_l; i < a_r; ++i) {\n        for (int j = b_l; j < b_r; ++j)\
    \ {\n          res[(i - a_l) + (j - b_l)] += (*a)[i] * (*b)[j];\n        }\n \
    \     }\n    } else {\n      const int mid = (a_len + 1) / 2, n = std::min(a_len,\
    \ mid);\n      for (int i = a_l; i + mid < a_r; ++i) {\n        (*a)[i] += (*a)[i\
    \ + mid];\n      }\n      for (int i = b_l; i + mid < b_r; ++i) {\n        (*b)[i]\
    \ += (*b)[i + mid];\n      }\n      std::vector<long long> tmp =\n          karatsuba(a,\
    \ a_l, a_l + mid, b, b_l, b_l + n);\n      std::copy(tmp.begin(), tmp.end(), std::next(res.begin(),\
    \ mid));\n      for (int i = a_l; i + mid < a_r; ++i) {\n        (*a)[i] -= (*a)[i\
    \ + mid];\n      }\n      for (int i = b_l; i + mid < b_r; ++i) {\n        (*b)[i]\
    \ -= (*b)[i + mid];\n      }\n      tmp = karatsuba(a, a_l, a_l + mid, b, b_l,\
    \ b_l + n);\n      for (int i = 0; i < tmp.size(); ++i) {\n        res[i] += tmp[i];\n\
    \        res[mid + i] -= tmp[i];\n      }\n      tmp = karatsuba(a, a_l + mid,\
    \ a_r, b, b_l + n, b_r);\n      for (int i = 0; i < tmp.size(); ++i) {\n     \
    \   res[mid + i] -= tmp[i];\n        res[(mid << 1) + i] += tmp[i];\n      }\n\
    \    }\n    while (!res.empty() && res.back() == 0) res.pop_back();\n    return\
    \ res;\n  }\n  std::pair<BigInt, int> divide(int x) const {\n    assert(x != 0);\n\
    \    BigInt dividend = *this;\n    if (x < 0) {\n      dividend.sgn = -dividend.sgn;\n\
    \      x = -x;\n    }\n    long long rem = 0;\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\n      const long long tmp = rem * B + dividend.data[i];\n\
    \      dividend.data[i] = tmp / x;\n      rem = tmp % x;\n    }\n    dividend.trim();\n\
    \    return {dividend, static_cast<int>(rem)};\n  }\n  std::pair<BigInt, BigInt>\
    \ divide(const BigInt& x) const {\n    assert(!x.data.empty());\n    const int\
    \ k = B / (x.data.back() + 1);\n    const BigInt dividend = (sgn == 1 ? *this\
    \ : -*this) * k;\n    const BigInt divisor = (x.sgn == 1 ? x : -x) * k;\n    BigInt\
    \ quo, rem = 0;\n    quo.data.resize(dividend.data.size());\n    const int n =\
    \ divisor.data.size();\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\n\
    \      quo.data[i] =\n          ((n < rem.data.size() ? static_cast<long long>(rem.data[n])\
    \ * B : 0)\n           + (n - 1 < rem.data.size() ? rem.data[n - 1] : 0))\n  \
    \        / divisor.data.back();\n      rem -= divisor * quo.data[i];\n      while\
    \ (rem.sgn == -1) {\n        rem += divisor;\n        --quo.data[i];\n      }\n\
    \    }\n    quo.sgn = sgn * x.sgn;\n    quo.trim();\n    rem.sgn = sgn;\n    rem.trim();\n\
    \    return {quo, rem / k};\n  }\n};\nnamespace std {\ntemplate <int LogB, int\
    \ B>\nBigInt<LogB, B> __gcd(BigInt<LogB, B> a, BigInt<LogB, B> b) {\n  while (!b.data.empty())\
    \ std::swap(a %= b, b);\n  return a;\n}\ntemplate <int LogB, int B>\nBigInt<LogB,\
    \ B> __lcm(const BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\n  return a /\
    \ std::__gcd(a, b) * b;\n}\ntemplate <int LogB, int B>\nBigInt<LogB, B> abs(const\
    \ BigInt<LogB, B>& x) { return x.sgn == 1 ? x : -x; }\ntemplate <int LogB, int\
    \ B>\nBigInt<LogB, B> max(const BigInt<LogB, B>& a, const BigInt<LogB, B>& b)\
    \ {\n  return a < b ? b : a;\n}\ntemplate <int LogB, int B>\nBigInt<LogB, B> min(const\
    \ BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\n  return a < b ? a : b;\n}\n\
    }  // namespace std\n#line 9 \"test/math/bigint.04.test.cpp\"\n\nint main() {\n\
    \  BigInt<> a, b;\n  std::cin >> a >> b;\n  std::cout << a * b << '\\n';\n  return\
    \ 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)\n\
    \ */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_F\"\
    \n\n#include <iostream>\n\n#include \"../../math/bigint.hpp\"\n\nint main() {\n\
    \  BigInt<> a, b;\n  std::cin >> a >> b;\n  std::cout << a * b << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/bigint.hpp
  isVerificationFile: true
  path: test/math/bigint.04.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/bigint.04.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.04.test.cpp
- /verify/test/math/bigint.04.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)"
---
