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
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#line 2 \"string/rolling_hash.hpp\"\
    \n#include <algorithm>\r\n#line 4 \"string/rolling_hash.hpp\"\n#include <vector>\r\
    \n\r\ntemplate <typename T = std::string>\r\nstruct RollingHash {\r\n  T str;\r\
    \n\r\n  RollingHash(const T &s, const int base = 10007, const int md = 1000000007)\
    \ : str(s), base(base), md(md) {\r\n    int n = str.size();\r\n    hash_val.resize(n\
    \ + 1);\r\n    hash_val[0] = 0;\r\n    power.resize(n + 1);\r\n    power[0] =\
    \ 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      hash_val[i + 1] = (hash_val[i]\
    \ * base % md + str[i]) % md;\r\n      power[i + 1] = power[i] * base % md;\r\n\
    \    }\r\n  }\r\n\r\n  long long get(int left, int right) const {\r\n    long\
    \ long res = hash_val[right] - hash_val[left] * power[right - left] % md;\r\n\
    \    return res < 0 ? res + md : res;\r\n  }\r\n\r\n  void add(const T &t) {\r\
    \n    for (auto c : t) {\r\n      hash_val.emplace_back((hash_val.back() * base\
    \ % md + c) % md);\r\n      power.emplace_back(power.back() * base % md);\r\n\
    \    }\r\n  }\r\n\r\n  int lcp(int i, int j) const {\r\n    int n = str.size(),\
    \ lb = 0, ub = n + 1 - std::max(i, j);\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1;\r\n      (get(i, i + mid) == get(j, j + mid) ? lb : ub)\
    \ = mid;\r\n    }\r\n    return lb;\r\n  }\r\n\r\n  template <typename U>\r\n\
    \  int lcp(const RollingHash<U> &t, int i, int j) const {\r\n    int lb = 0, ub\
    \ = std::min(static_cast<int>(str.size()) - i, static_cast<int>(t.str.size())\
    \ - j) + 1;\r\n    while (ub - lb > 1) {\r\n      int mid = (lb + ub) >> 1;\r\n\
    \      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\n  \
    \  return lb;\r\n  }\r\n\r\nprivate:\r\n  int base, md;\r\n  std::vector<long\
    \ long> hash_val, power;\r\n};\r\n#line 9 \"test/string/rolling_hash.test.cpp\"\
    \n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  RollingHash<>\
    \ rh_t(t), rh_p(p);\r\n  for (int i = 0; i < t.length(); ++i) {\r\n    if (i +\
    \ p.length() <= t.length() && rh_t.get(i, i + p.length()) == rh_p.get(0, p.length()))\
    \ {\r\n      std::cout << i << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
    \u30B7\u30E5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../string/rolling_hash.hpp\"\
    \r\n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  RollingHash<>\
    \ rh_t(t), rh_p(p);\r\n  for (int i = 0; i < t.length(); ++i) {\r\n    if (i +\
    \ p.length() <= t.length() && rh_t.get(i, i + p.length()) == rh_p.get(0, p.length()))\
    \ {\r\n      std::cout << i << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
