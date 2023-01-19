---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.01.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.02.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u52A0\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.03.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.04.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.05.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u9664\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.06.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u5270\u4F59\u6F14\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.07.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u5927\u5C0F\u6BD4\u8F03)"
  - icon: ':x:'
    path: test/math/bigint.08.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u51AA\u6F14\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.09.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C)"
  - icon: ':x:'
    path: test/math/bigint.10.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u6570)"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/bigint.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <sstream>\n#include <string>\n\
    #include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <int LogB\
    \ = 9, int B = 1000000000>  // B = 10^{LogB}\nstruct BigInt {\n  int sgn;\n  std::vector<int>\
    \ data;\n  BigInt(const long long val = 0) { *this = val; }\n  BigInt(const std::string&\
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
    \   for (int i = 0; i < static_cast<int>(x.data.size()) || carry; ++i) {\n   \
    \   if (i == static_cast<int>(data.size())) data.emplace_back(0);\n      data[i]\
    \ += (i < static_cast<int>(x.data.size()) ? x.data[i] : 0) + carry;\n      if\
    \ (data[i] >= B) {\n        carry = true;\n        data[i] -= B;\n      } else\
    \ {\n        carry = false;\n      }\n    }\n    return *this;\n  }\n  BigInt&\
    \ operator-=(const BigInt& x) {\n    if (sgn != x.sgn) return *this += -x;\n \
    \   if ((sgn == 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\n      return *this\
    \ = -(x - *this);\n    }\n    bool carry = false;\n    for (int i = 0; i < static_cast<int>(data.size())\
    \ || carry; ++i) {\n      data[i] -= (i < static_cast<int>(x.data.size()) ? x.data[i]\
    \ : 0) + carry;\n      if (data[i] < 0) {\n        carry = true;\n        data[i]\
    \ += B;\n      } else {\n        carry = false;\n      }\n    }\n    trim();\n\
    \    return *this;\n  }\n  BigInt& operator*=(const BigInt& x) {\n    constexpr\
    \ int next_log_b = 6, next_b = 1000000;\n    std::vector<long long> this6 = convert_base(next_log_b,\
    \ next_b);\n    std::vector<long long> x6 = x.convert_base(next_log_b, next_b);\n\
    \    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),\n       \
    \                                    &x6, 0, x6.size());\n    for (int i = 0;\
    \ i < static_cast<int>(res.size()); ++i) {\n      const long long quo = res[i]\
    \ / next_b;\n      if (quo > 0) {\n        if (i + 1 == static_cast<int>(res.size()))\
    \ {\n          res.emplace_back(quo);\n        } else {\n          res[i + 1]\
    \ += quo;\n        }\n        res[i] %= next_b;\n      }\n    }\n    std::string\
    \ s = (sgn * x.sgn == 1 ? \"+\" : \"-\");\n    for (int i = static_cast<int>(res.size())\
    \ - 1; i >= 0; --i) {\n      const std::string tmp = std::to_string(res[i]);\n\
    \      s += std::string(next_log_b - tmp.length(), '0') + tmp;\n    }\n    return\
    \ *this = s;\n  }\n  BigInt& operator/=(int x) { return *this = divide(x).first;\
    \ }\n  BigInt& operator/=(const BigInt& x) { return *this = divide(x).first; }\n\
    \  BigInt& operator%=(int x) { return *this = divide(x).second; }\n  BigInt& operator%=(const\
    \ BigInt& x) { return *this = divide(x).second; }\n  bool operator==(const BigInt&\
    \ x) const {\n    if (sgn != x.sgn || data.size() != x.data.size()) return false;\n\
    \    const int n = data.size();\n    for (int i = 0; i < n; ++i) {\n      if (data[i]\
    \ != x.data[i]) return false;\n    }\n    return true;\n  }\n  bool operator!=(const\
    \ BigInt& x) const { return !(*this == x); }\n  bool operator<(const BigInt& x)\
    \ const {\n    if (sgn != x.sgn) return sgn < x.sgn;\n    if (data.size() != x.data.size())\
    \ {\n      return sgn * data.size() < x.sgn * x.data.size();\n    }\n    for (int\
    \ i = static_cast<int>(data.size()) - 1; i >= 0; --i) {\n      if (data[i] !=\
    \ x.data[i]) return data[i] * sgn < x.data[i] * x.sgn;\n    }\n    return false;\n\
    \  }\n  bool operator<=(const BigInt& x) const { return !(x < *this); }\n  bool\
    \ operator>(const BigInt& x) const { return x < *this; }\n  bool operator>=(const\
    \ BigInt& x) const { return !(*this < x); }\n  BigInt& operator++() { return *this\
    \ += 1; }\n  BigInt operator++(int) {\n    const BigInt res = *this;\n    ++*this;\n\
    \    return res;\n  }\n  BigInt& operator--() { return *this -= 1; }\n  BigInt\
    \ operator--(int) {\n    const BigInt res = *this;\n    --*this;\n    return res;\n\
    \  }\n  BigInt operator+() const { return *this; }\n  BigInt operator-() const\
    \ {\n    BigInt res = *this;\n    res.sgn = -res.sgn;\n    return res;\n  }\n\
    \  BigInt operator+(const BigInt& x) const { return BigInt(*this) += x; }\n  BigInt\
    \ operator-(const BigInt& x) const { return BigInt(*this) -= x; }\n  BigInt operator*(const\
    \ BigInt& x) const { return BigInt(*this) *= x; }\n  BigInt operator/(int x) const\
    \ { return BigInt(*this) /= x; }\n  BigInt operator/(const BigInt& x) const {\
    \ return BigInt(*this) /= x; }\n  BigInt operator%(int x) const { return BigInt(*this)\
    \ %= x; }\n  BigInt operator%(const BigInt& x) const { return BigInt(*this) %=\
    \ x; }\n  friend std::ostream& operator<<(std::ostream& os, const BigInt& x) {\n\
    \    if (x.sgn == -1) os << '-';\n    os << (x.data.empty() ? 0 : x.data.back());\n\
    \    for (int i = static_cast<int>(x.data.size()) - 2; i >= 0; --i) {\n      os\
    \ << std::setw(LogB) << std::setfill('0') << x.data[i];\n    }\n    return os;\n\
    \  }\n  friend std::istream& operator>>(std::istream& is, BigInt& x) {\n    std::string\
    \ s;\n    is >> s;\n    x = s;\n    return is;\n  }\n private:\n  std::vector<long\
    \ long> karatsuba(\n      std::vector<long long>* a, const int a_l, const int\
    \ a_r,\n      std::vector<long long>* b, const int b_l, const int b_r) const {\n\
    \    const int a_len = a_r - a_l, b_len = b_r - b_l;\n    if (a_len < b_len) return\
    \ karatsuba(b, b_l, b_r, a, a_l, a_r);\n    std::vector<long long> res(a_len +\
    \ b_len, 0);\n    if (b_len <= 32) {\n      for (int i = a_l; i < a_r; ++i) {\n\
    \        for (int j = b_l; j < b_r; ++j) {\n          res[(i - a_l) + (j - b_l)]\
    \ += (*a)[i] * (*b)[j];\n        }\n      }\n    } else {\n      const int mid\
    \ = (a_len + 1) / 2, n = std::min(a_len, mid);\n      for (int i = a_l; i + mid\
    \ < a_r; ++i) {\n        (*a)[i] += (*a)[i + mid];\n      }\n      for (int i\
    \ = b_l; i + mid < b_r; ++i) {\n        (*b)[i] += (*b)[i + mid];\n      }\n \
    \     std::vector<long long> tmp =\n          karatsuba(a, a_l, a_l + mid, b,\
    \ b_l, b_l + n);\n      std::copy(tmp.begin(), tmp.end(), std::next(res.begin(),\
    \ mid));\n      for (int i = a_l; i + mid < a_r; ++i) {\n        (*a)[i] -= (*a)[i\
    \ + mid];\n      }\n      for (int i = b_l; i + mid < b_r; ++i) {\n        (*b)[i]\
    \ -= (*b)[i + mid];\n      }\n      tmp = karatsuba(a, a_l, a_l + mid, b, b_l,\
    \ b_l + n);\n      for (int i = 0; i < static_cast<int>(tmp.size()); ++i) {\n\
    \        res[i] += tmp[i];\n        res[mid + i] -= tmp[i];\n      }\n      tmp\
    \ = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);\n      for (int i = 0; i <\
    \ static_cast<int>(tmp.size()); ++i) {\n        res[mid + i] -= tmp[i];\n    \
    \    res[(mid << 1) + i] += tmp[i];\n      }\n    }\n    while (!res.empty() &&\
    \ res.back() == 0) res.pop_back();\n    return res;\n  }\n  std::pair<BigInt,\
    \ int> divide(int x) const {\n    assert(x != 0);\n    BigInt dividend = *this;\n\
    \    if (x < 0) {\n      dividend.sgn = -dividend.sgn;\n      x = -x;\n    }\n\
    \    long long rem = 0;\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\n      const long long tmp = rem * B + dividend.data[i];\n\
    \      dividend.data[i] = tmp / x;\n      rem = tmp % x;\n    }\n    dividend.trim();\n\
    \    return {dividend, static_cast<int>(rem)};\n  }\n  std::pair<BigInt, BigInt>\
    \ divide(const BigInt& x) const {\n    assert(!x.data.empty());\n    const int\
    \ k = B / (x.data.back() + 1);\n    const BigInt dividend = (sgn == 1 ? *this\
    \ : -*this) * k;\n    const BigInt divisor = (x.sgn == 1 ? x : -x) * k;\n    BigInt\
    \ quo, rem = 0;\n    quo.data.resize(dividend.data.size());\n    const int n =\
    \ divisor.data.size();\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\n\
    \      quo.data[i] =\n          ((n < static_cast<int>(rem.data.size()) ?\n  \
    \          static_cast<long long>(rem.data[n]) * B : 0)\n           + (n - 1 <\
    \ static_cast<int>(rem.data.size()) ? rem.data[n - 1] : 0))\n          / divisor.data.back();\n\
    \      rem -= divisor * quo.data[i];\n      while (rem.sgn == -1) {\n        rem\
    \ += divisor;\n        --quo.data[i];\n      }\n    }\n    quo.sgn = sgn * x.sgn;\n\
    \    quo.trim();\n    rem.sgn = sgn;\n    rem.trim();\n    return {quo, rem /\
    \ k};\n  }\n};\n\n}  // namespace emthrm\n\nnamespace std {\n\n#if __cplusplus\
    \ >= 201703L\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B> gcd(emthrm::BigInt<LogB,\
    \ B> a,\n                            emthrm::BigInt<LogB, B> b) {\n  while (!b.data.empty())\
    \ std::swap(a %= b, b);\n  return a;\n}\n#else\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB,\
    \ B> __gcd(emthrm::BigInt<LogB, B> a,\n                              emthrm::BigInt<LogB,\
    \ B> b) {\n  while (!b.data.empty()) std::swap(a %= b, b);\n  return a;\n}\n#endif\n\
    #if __cplusplus >= 201703L\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B>\
    \ lcm(const emthrm::BigInt<LogB, B>& a,\n                            const emthrm::BigInt<LogB,\
    \ B>& b) {\n  return a / std::__gcd(a, b) * b;\n}\n#else\ntemplate <int LogB,\
    \ int B>\nemthrm::BigInt<LogB, B> __lcm(const emthrm::BigInt<LogB, B>& a,\n  \
    \                            const emthrm::BigInt<LogB, B>& b) {\n  return a /\
    \ std::__gcd(a, b) * b;\n}\n#endif\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB,\
    \ B> abs(const emthrm::BigInt<LogB, B>& x) {\n  return x.sgn == 1 ? x : -x;\n\
    }\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B> max(const emthrm::BigInt<LogB,\
    \ B>& a,\n                            const emthrm::BigInt<LogB, B>& b) {\n  return\
    \ a < b ? b : a;\n}\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B> min(const\
    \ emthrm::BigInt<LogB, B>& a,\n                            const emthrm::BigInt<LogB,\
    \ B>& b) {\n  return a < b ? a : b;\n}\n\n}  // namespace std\n\n\n"
  code: "#ifndef EMTHRM_MATH_BIGINT_HPP_\n#define EMTHRM_MATH_BIGINT_HPP_\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <limits>\n#include <sstream>\n#include\
    \ <string>\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <int LogB = 9, int B = 1000000000>  // B = 10^{LogB}\nstruct BigInt {\n  int\
    \ sgn;\n  std::vector<int> data;\n  BigInt(const long long val = 0) { *this =\
    \ val; }\n  BigInt(const std::string& s) { *this = s; }\n  std::vector<long long>\
    \ convert_base(const int next_log_b,\n                                      const\
    \ int next_b) const {\n    assert(next_b == static_cast<int>(std::round(std::pow(10,\
    \ next_log_b))));\n    const int max_base = std::max(LogB, next_log_b);\n    std::vector<long\
    \ long> p(max_base + 1, 1);\n    for (int i = 1; i <= max_base; ++i) {\n     \
    \ p[i] = p[i - 1] * 10;\n    }\n    std::vector<long long> res;\n    long long\
    \ cur_val = 0;\n    int cur_log_b = 0;\n    for (const int e : data) {\n     \
    \ cur_val += p[cur_log_b] * e;\n      cur_log_b += LogB;\n      for (; cur_log_b\
    \ >= next_log_b; cur_log_b -= next_log_b) {\n        res.emplace_back(cur_val\
    \ % next_b);\n        cur_val /= next_b;\n      }\n    }\n    res.emplace_back(cur_val);\n\
    \    while (!res.empty() && res.back() == 0) res.pop_back();\n    return res;\n\
    \  }\n  int digit_sum() const {\n    assert(sgn == 1);\n    int res = 0;\n   \
    \ for (char c : to_string()) res += c - '0';\n    return res;\n  }\n  int length()\
    \ const {\n    if (data.empty()) return 0;\n    int res = LogB * (data.size()\
    \ - 1);\n    for (int tmp = data.back(); tmp > 0; tmp /= 10) {\n      ++res;\n\
    \    }\n    return res;\n  }\n  BigInt pow(BigInt exponent) const {\n    BigInt\
    \ res = 1, tmp = *this;\n    for (; exponent > 0; exponent /= 2) {\n      if (exponent.data.front()\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n  long long\
    \ to_llong() const {\n    assert(*this >= std::numeric_limits<long long>::min()\
    \ &&\n           *this <= std::numeric_limits<long long>::max());\n    long long\
    \ res = 0;\n    for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i) {\n\
    \      res = res * B + data[i];\n    }\n    return res;\n  }\n  std::string to_string()\
    \ const {\n    std::stringstream ss;\n    ss << *this;\n    std::string res;\n\
    \    ss >> res;\n    return res;\n  }\n  void trim() {\n    while (!data.empty()\
    \ && data.back() == 0) data.pop_back();\n    if (data.empty()) sgn = 1;\n  }\n\
    \  BigInt& operator=(long long val) {\n    if (val < 0) {\n      sgn = -1;\n \
    \     val = -val;\n    } else {\n      sgn = 1;\n    }\n    data.clear();\n  \
    \  for (; val > 0; val /= B) {\n      data.emplace_back(val % B);\n    }\n   \
    \ return *this;\n  }\n  BigInt& operator=(const std::string& s) {\n    sgn = 1;\n\
    \    data.clear();\n    if (!s.empty()) {\n      int tail = 0;\n      if (s.front()\
    \ == '-') {\n        sgn = -1;\n        tail = 1;\n      } else if (s.front()\
    \ == '+') {\n        tail = 1;\n      }\n      for (int i = s.length() - 1; i\
    \ >= tail; i -= LogB) {\n        int val = 0;\n        for (int j = std::max(tail,\
    \ i - LogB + 1); j <= i; ++j) {\n          val = val * 10 + (s[j] - '0');\n  \
    \      }\n        data.emplace_back(val);\n      }\n    }\n    trim();\n    return\
    \ *this;\n  }\n  BigInt& operator=(const BigInt& x) = default;\n  BigInt& operator+=(const\
    \ BigInt& x) {\n    if (sgn != x.sgn) return *this -= -x;\n    if (data.size()\
    \ < x.data.size()) data.resize(x.data.size(), 0);\n    bool carry = false;\n \
    \   for (int i = 0; i < static_cast<int>(x.data.size()) || carry; ++i) {\n   \
    \   if (i == static_cast<int>(data.size())) data.emplace_back(0);\n      data[i]\
    \ += (i < static_cast<int>(x.data.size()) ? x.data[i] : 0) + carry;\n      if\
    \ (data[i] >= B) {\n        carry = true;\n        data[i] -= B;\n      } else\
    \ {\n        carry = false;\n      }\n    }\n    return *this;\n  }\n  BigInt&\
    \ operator-=(const BigInt& x) {\n    if (sgn != x.sgn) return *this += -x;\n \
    \   if ((sgn == 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\n      return *this\
    \ = -(x - *this);\n    }\n    bool carry = false;\n    for (int i = 0; i < static_cast<int>(data.size())\
    \ || carry; ++i) {\n      data[i] -= (i < static_cast<int>(x.data.size()) ? x.data[i]\
    \ : 0) + carry;\n      if (data[i] < 0) {\n        carry = true;\n        data[i]\
    \ += B;\n      } else {\n        carry = false;\n      }\n    }\n    trim();\n\
    \    return *this;\n  }\n  BigInt& operator*=(const BigInt& x) {\n    constexpr\
    \ int next_log_b = 6, next_b = 1000000;\n    std::vector<long long> this6 = convert_base(next_log_b,\
    \ next_b);\n    std::vector<long long> x6 = x.convert_base(next_log_b, next_b);\n\
    \    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),\n       \
    \                                    &x6, 0, x6.size());\n    for (int i = 0;\
    \ i < static_cast<int>(res.size()); ++i) {\n      const long long quo = res[i]\
    \ / next_b;\n      if (quo > 0) {\n        if (i + 1 == static_cast<int>(res.size()))\
    \ {\n          res.emplace_back(quo);\n        } else {\n          res[i + 1]\
    \ += quo;\n        }\n        res[i] %= next_b;\n      }\n    }\n    std::string\
    \ s = (sgn * x.sgn == 1 ? \"+\" : \"-\");\n    for (int i = static_cast<int>(res.size())\
    \ - 1; i >= 0; --i) {\n      const std::string tmp = std::to_string(res[i]);\n\
    \      s += std::string(next_log_b - tmp.length(), '0') + tmp;\n    }\n    return\
    \ *this = s;\n  }\n  BigInt& operator/=(int x) { return *this = divide(x).first;\
    \ }\n  BigInt& operator/=(const BigInt& x) { return *this = divide(x).first; }\n\
    \  BigInt& operator%=(int x) { return *this = divide(x).second; }\n  BigInt& operator%=(const\
    \ BigInt& x) { return *this = divide(x).second; }\n  bool operator==(const BigInt&\
    \ x) const {\n    if (sgn != x.sgn || data.size() != x.data.size()) return false;\n\
    \    const int n = data.size();\n    for (int i = 0; i < n; ++i) {\n      if (data[i]\
    \ != x.data[i]) return false;\n    }\n    return true;\n  }\n  bool operator!=(const\
    \ BigInt& x) const { return !(*this == x); }\n  bool operator<(const BigInt& x)\
    \ const {\n    if (sgn != x.sgn) return sgn < x.sgn;\n    if (data.size() != x.data.size())\
    \ {\n      return sgn * data.size() < x.sgn * x.data.size();\n    }\n    for (int\
    \ i = static_cast<int>(data.size()) - 1; i >= 0; --i) {\n      if (data[i] !=\
    \ x.data[i]) return data[i] * sgn < x.data[i] * x.sgn;\n    }\n    return false;\n\
    \  }\n  bool operator<=(const BigInt& x) const { return !(x < *this); }\n  bool\
    \ operator>(const BigInt& x) const { return x < *this; }\n  bool operator>=(const\
    \ BigInt& x) const { return !(*this < x); }\n  BigInt& operator++() { return *this\
    \ += 1; }\n  BigInt operator++(int) {\n    const BigInt res = *this;\n    ++*this;\n\
    \    return res;\n  }\n  BigInt& operator--() { return *this -= 1; }\n  BigInt\
    \ operator--(int) {\n    const BigInt res = *this;\n    --*this;\n    return res;\n\
    \  }\n  BigInt operator+() const { return *this; }\n  BigInt operator-() const\
    \ {\n    BigInt res = *this;\n    res.sgn = -res.sgn;\n    return res;\n  }\n\
    \  BigInt operator+(const BigInt& x) const { return BigInt(*this) += x; }\n  BigInt\
    \ operator-(const BigInt& x) const { return BigInt(*this) -= x; }\n  BigInt operator*(const\
    \ BigInt& x) const { return BigInt(*this) *= x; }\n  BigInt operator/(int x) const\
    \ { return BigInt(*this) /= x; }\n  BigInt operator/(const BigInt& x) const {\
    \ return BigInt(*this) /= x; }\n  BigInt operator%(int x) const { return BigInt(*this)\
    \ %= x; }\n  BigInt operator%(const BigInt& x) const { return BigInt(*this) %=\
    \ x; }\n  friend std::ostream& operator<<(std::ostream& os, const BigInt& x) {\n\
    \    if (x.sgn == -1) os << '-';\n    os << (x.data.empty() ? 0 : x.data.back());\n\
    \    for (int i = static_cast<int>(x.data.size()) - 2; i >= 0; --i) {\n      os\
    \ << std::setw(LogB) << std::setfill('0') << x.data[i];\n    }\n    return os;\n\
    \  }\n  friend std::istream& operator>>(std::istream& is, BigInt& x) {\n    std::string\
    \ s;\n    is >> s;\n    x = s;\n    return is;\n  }\n private:\n  std::vector<long\
    \ long> karatsuba(\n      std::vector<long long>* a, const int a_l, const int\
    \ a_r,\n      std::vector<long long>* b, const int b_l, const int b_r) const {\n\
    \    const int a_len = a_r - a_l, b_len = b_r - b_l;\n    if (a_len < b_len) return\
    \ karatsuba(b, b_l, b_r, a, a_l, a_r);\n    std::vector<long long> res(a_len +\
    \ b_len, 0);\n    if (b_len <= 32) {\n      for (int i = a_l; i < a_r; ++i) {\n\
    \        for (int j = b_l; j < b_r; ++j) {\n          res[(i - a_l) + (j - b_l)]\
    \ += (*a)[i] * (*b)[j];\n        }\n      }\n    } else {\n      const int mid\
    \ = (a_len + 1) / 2, n = std::min(a_len, mid);\n      for (int i = a_l; i + mid\
    \ < a_r; ++i) {\n        (*a)[i] += (*a)[i + mid];\n      }\n      for (int i\
    \ = b_l; i + mid < b_r; ++i) {\n        (*b)[i] += (*b)[i + mid];\n      }\n \
    \     std::vector<long long> tmp =\n          karatsuba(a, a_l, a_l + mid, b,\
    \ b_l, b_l + n);\n      std::copy(tmp.begin(), tmp.end(), std::next(res.begin(),\
    \ mid));\n      for (int i = a_l; i + mid < a_r; ++i) {\n        (*a)[i] -= (*a)[i\
    \ + mid];\n      }\n      for (int i = b_l; i + mid < b_r; ++i) {\n        (*b)[i]\
    \ -= (*b)[i + mid];\n      }\n      tmp = karatsuba(a, a_l, a_l + mid, b, b_l,\
    \ b_l + n);\n      for (int i = 0; i < static_cast<int>(tmp.size()); ++i) {\n\
    \        res[i] += tmp[i];\n        res[mid + i] -= tmp[i];\n      }\n      tmp\
    \ = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);\n      for (int i = 0; i <\
    \ static_cast<int>(tmp.size()); ++i) {\n        res[mid + i] -= tmp[i];\n    \
    \    res[(mid << 1) + i] += tmp[i];\n      }\n    }\n    while (!res.empty() &&\
    \ res.back() == 0) res.pop_back();\n    return res;\n  }\n  std::pair<BigInt,\
    \ int> divide(int x) const {\n    assert(x != 0);\n    BigInt dividend = *this;\n\
    \    if (x < 0) {\n      dividend.sgn = -dividend.sgn;\n      x = -x;\n    }\n\
    \    long long rem = 0;\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\n      const long long tmp = rem * B + dividend.data[i];\n\
    \      dividend.data[i] = tmp / x;\n      rem = tmp % x;\n    }\n    dividend.trim();\n\
    \    return {dividend, static_cast<int>(rem)};\n  }\n  std::pair<BigInt, BigInt>\
    \ divide(const BigInt& x) const {\n    assert(!x.data.empty());\n    const int\
    \ k = B / (x.data.back() + 1);\n    const BigInt dividend = (sgn == 1 ? *this\
    \ : -*this) * k;\n    const BigInt divisor = (x.sgn == 1 ? x : -x) * k;\n    BigInt\
    \ quo, rem = 0;\n    quo.data.resize(dividend.data.size());\n    const int n =\
    \ divisor.data.size();\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\n\
    \      quo.data[i] =\n          ((n < static_cast<int>(rem.data.size()) ?\n  \
    \          static_cast<long long>(rem.data[n]) * B : 0)\n           + (n - 1 <\
    \ static_cast<int>(rem.data.size()) ? rem.data[n - 1] : 0))\n          / divisor.data.back();\n\
    \      rem -= divisor * quo.data[i];\n      while (rem.sgn == -1) {\n        rem\
    \ += divisor;\n        --quo.data[i];\n      }\n    }\n    quo.sgn = sgn * x.sgn;\n\
    \    quo.trim();\n    rem.sgn = sgn;\n    rem.trim();\n    return {quo, rem /\
    \ k};\n  }\n};\n\n}  // namespace emthrm\n\nnamespace std {\n\n#if __cplusplus\
    \ >= 201703L\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B> gcd(emthrm::BigInt<LogB,\
    \ B> a,\n                            emthrm::BigInt<LogB, B> b) {\n  while (!b.data.empty())\
    \ std::swap(a %= b, b);\n  return a;\n}\n#else\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB,\
    \ B> __gcd(emthrm::BigInt<LogB, B> a,\n                              emthrm::BigInt<LogB,\
    \ B> b) {\n  while (!b.data.empty()) std::swap(a %= b, b);\n  return a;\n}\n#endif\n\
    #if __cplusplus >= 201703L\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B>\
    \ lcm(const emthrm::BigInt<LogB, B>& a,\n                            const emthrm::BigInt<LogB,\
    \ B>& b) {\n  return a / std::__gcd(a, b) * b;\n}\n#else\ntemplate <int LogB,\
    \ int B>\nemthrm::BigInt<LogB, B> __lcm(const emthrm::BigInt<LogB, B>& a,\n  \
    \                            const emthrm::BigInt<LogB, B>& b) {\n  return a /\
    \ std::__gcd(a, b) * b;\n}\n#endif\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB,\
    \ B> abs(const emthrm::BigInt<LogB, B>& x) {\n  return x.sgn == 1 ? x : -x;\n\
    }\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B> max(const emthrm::BigInt<LogB,\
    \ B>& a,\n                            const emthrm::BigInt<LogB, B>& b) {\n  return\
    \ a < b ? b : a;\n}\ntemplate <int LogB, int B>\nemthrm::BigInt<LogB, B> min(const\
    \ emthrm::BigInt<LogB, B>& a,\n                            const emthrm::BigInt<LogB,\
    \ B>& b) {\n  return a < b ? a : b;\n}\n\n}  // namespace std\n\n#endif  // EMTHRM_MATH_BIGINT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/bigint.hpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/bigint.03.test.cpp
  - test/math/bigint.06.test.cpp
  - test/math/bigint.09.test.cpp
  - test/math/bigint.07.test.cpp
  - test/math/bigint.04.test.cpp
  - test/math/bigint.05.test.cpp
  - test/math/bigint.01.test.cpp
  - test/math/bigint.10.test.cpp
  - test/math/bigint.02.test.cpp
  - test/math/bigint.08.test.cpp
documentation_of: include/emthrm/math/bigint.hpp
layout: document
title: "\u591A\u500D\u9577\u6574\u6570"
---


## 時間計算量

|アルゴリズム|時間計算量|
|:--|:--|
|カラツバ法 (Karatsuba algorithm)|$O(N^{\log 3}) \sim O(N^{1.585})$|
|Knuth's Algorithm D|$O(N^2)$|


## 参考文献

- https://lumakernel.github.io/ecasdqina/misc/BigInteger
- https://github.com/spaghetti-source/algorithm/blob/b9b6e0b7c50600d985b2c0114fb569ee2d3102dc/math/bigint.cc

カラツバ法
- http://xn--w6q13e505b.jp/method/karatsuba.html

Knuth's Algorithm D
- http://yamatyuu.net/computer/program/long/div/index.html


## TODO

- https://qiita.com/square1001/items/1aa12e04934b6e749962
- http://xn--w6q13e505b.jp/method/
- http://poset.jp/ompa/node3.html
- 乗算の高速化
  - http://xn--w6q13e505b.jp/method/mult.html
  - http://fussy.web.fc2.com/algo/math3_mult.htm
  - ショーンハーゲ・ストラッセン法 (Schönhage–Strassen algorithm)
    - https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%A7%E3%83%BC%E3%83%B3%E3%83%8F%E3%83%BC%E3%82%B2%E3%83%BB%E3%82%B9%E3%83%88%E3%83%A9%E3%83%83%E3%82%BB%E3%83%B3%E6%B3%95
    - https://qiita.com/peria/items/fbdd52768b4659823d88
    - http://poset.jp/ompa/node5.html
    - https://qiita.com/peria/items/19e37b192cb62bdbc3a1
    - https://cookies.hatenablog.jp/entry/2018/12/18/092106
    - https://pisan-dub.jp/doc/2011/20110201001/2000/20000819001/0.pdf
  - Toom–Cook 法 (Toom-3)
    - https://en.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication
    - http://xn--w6q13e505b.jp/method/toomcook.html
    - https://azapen6.hatenablog.com/entry/2014/04/11/235315
    - https://www.mk-mode.com/blog/2013/04/29/cpp-big-multiply-toom-cook-3/
    - http://poset.jp/ompa/node4.html#SECTION00044000000000000000
- 階乗
  - http://fussy.web.fc2.com/algo/math2_bignum.htm
- ニュートン・ラプソン除算 (Newton–Raphson division)
  - https://ja.wikipedia.org/wiki/%E9%99%A4%E7%AE%97_(%E3%83%87%E3%82%B8%E3%82%BF%E3%83%AB)#%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3-%E3%83%A9%E3%83%97%E3%82%BD%E3%83%B3%E9%99%A4%E7%AE%97
  - https://wiki2.org/en/Division_algorithm#Fast_division_methods
  - http://xn--w6q13e505b.jp/method/newton.html
  - http://www.hundredsoft.jp/win7blog/log/eid99.html
- 平方根
  - https://codeforces.com/blog/entry/22566
  - http://poset.jp/ompa/node2.html#SECTION00024000000000000000
  - http://www.prefield.com/algorithm/math/bignum.html


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2679/review/4092735/emthrm/C++14
- [加算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_A/review/4092738/emthrm/C++14)
- [減算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_B/review/4092740/emthrm/C++14)
- [乗算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_F/review/4092742/emthrm/C++14)
- [除算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_D/review/4092743/emthrm/C++14)
- [剰余演算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_E/review/4092744/emthrm/C++14)
- [大小比較](https://atcoder.jp/contests/abc059/submissions/9334290)
- [冪演算](https://codeforces.com/problemsets/acmsguru/submission/99999/68307060)
- [桁和](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP1_8_B/review/4967090/emthrm/C++17)
- [桁数](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0015/review/4092752/emthrm/C++14)
