---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5 (rolling hash)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
      \u30B7\u30E5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/rolling_hash.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\r\n */\r\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#line 2 \"string/rolling_hash.hpp\"\
    \n#include <algorithm>\r\n#line 4 \"string/rolling_hash.hpp\"\n#include <vector>\r\
    \n\r\ntemplate <typename T = std::string>\r\nstruct RollingHash {\r\n  T s;\r\n\
    \r\n  explicit RollingHash(const T& s, const int base = 10007,\r\n           \
    \            const int mod = 1000000007)\r\n      : base(base), mod(mod), hash({0}),\
    \ power({1}) {\r\n    const int n = s.size();\r\n    this->s.reserve(n);\r\n \
    \   hash.reserve(n + 1);\r\n    power.reserve(n + 1);\r\n    add(s);\r\n  }\r\n\
    \r\n  long long get(const int left, const int right) const {\r\n    const long\
    \ long res =\r\n        hash[right] - hash[left] * power[right - left] % mod;\r\
    \n    return res < 0 ? res + mod : res;\r\n  }\r\n\r\n  void add(const T& t) {\r\
    \n    for (const auto c : t) {\r\n      s.push_back(c);\r\n      const int hash_nxt\
    \ = (hash.back() * base % mod + c) % mod;\r\n      hash.emplace_back(hash_nxt);\r\
    \n      const int power_nxt = power.back() * base % mod;\r\n      power.emplace_back(power_nxt);\r\
    \n    }\r\n  }\r\n\r\n  int longest_common_prefix(const int i, const int j) const\
    \ {\r\n    const int n = s.size();\r\n    int lb = 0, ub = n + 1 - std::max(i,\
    \ j);\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >> 1;\r\n\
    \      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\n    return\
    \ lb;\r\n  }\r\n\r\n  template <typename U>\r\n  int longest_common_prefix(const\
    \ RollingHash<U>& t,\r\n                            const int i, const int j)\
    \ const {\r\n    int lb = 0;\r\n    int ub = std::min(static_cast<int>(s.size())\
    \ - i,\r\n                      static_cast<int>(t.str.size()) - j)\r\n      \
    \       + 1;\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >>\
    \ 1;\r\n      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\
    \n    return lb;\r\n  }\r\n\r\n private:\r\n  const int base, mod;\r\n  std::vector<long\
    \ long> hash, power;\r\n};\r\n#line 10 \"test/string/rolling_hash.test.cpp\"\n\
    \r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  const int\
    \ t_size = t.length(), p_size = p.length();\r\n  RollingHash<> rolling_hash_t(t),\
    \ rolling_hash_p(p);\r\n  for (int i = 0; i < t_size; ++i) {\r\n    if (i + p_size\
    \ <= t_size &&\r\n        rolling_hash_t.get(i, i + p_size) == rolling_hash_p.get(0,\
    \ p_size)) {\r\n      std::cout << i << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\
    \n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
    \u30B7\u30E5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#include \"../../string/rolling_hash.hpp\"\
    \r\n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  const\
    \ int t_size = t.length(), p_size = p.length();\r\n  RollingHash<> rolling_hash_t(t),\
    \ rolling_hash_p(p);\r\n  for (int i = 0; i < t_size; ++i) {\r\n    if (i + p_size\
    \ <= t_size &&\r\n        rolling_hash_t.get(i, i + p_size) == rolling_hash_p.get(0,\
    \ p_size)) {\r\n      std::cout << i << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 17:10:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
