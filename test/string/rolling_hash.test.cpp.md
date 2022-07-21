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
  bundledCode: "#line 1 \"test/string/rolling_hash.test.cpp\"\n/*\n * @brief \u6587\
    \u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n */\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"string/rolling_hash.hpp\"\
    \n#include <algorithm>\n#line 4 \"string/rolling_hash.hpp\"\n#include <vector>\n\
    \ntemplate <typename T = std::string>\nstruct RollingHash {\n  T s;\n\n  explicit\
    \ RollingHash(const T& s, const int base = 10007,\n                       const\
    \ int mod = 1000000007)\n      : base(base), mod(mod), hash({0}), power({1}) {\n\
    \    const int n = s.size();\n    this->s.reserve(n);\n    hash.reserve(n + 1);\n\
    \    power.reserve(n + 1);\n    add(s);\n  }\n\n  long long get(const int left,\
    \ const int right) const {\n    const long long res =\n        hash[right] - hash[left]\
    \ * power[right - left] % mod;\n    return res < 0 ? res + mod : res;\n  }\n\n\
    \  void add(const T& t) {\n    for (const auto c : t) {\n      s.push_back(c);\n\
    \      const int hash_nxt = (hash.back() * base % mod + c) % mod;\n      hash.emplace_back(hash_nxt);\n\
    \      const int power_nxt = power.back() * base % mod;\n      power.emplace_back(power_nxt);\n\
    \    }\n  }\n\n  int longest_common_prefix(const int i, const int j) const {\n\
    \    const int n = s.size();\n    int lb = 0, ub = n + 1 - std::max(i, j);\n \
    \   while (ub - lb > 1) {\n      const int mid = (lb + ub) >> 1;\n      (get(i,\
    \ i + mid) == get(j, j + mid) ? lb : ub) = mid;\n    }\n    return lb;\n  }\n\n\
    \  template <typename U>\n  int longest_common_prefix(const RollingHash<U>& t,\n\
    \                            const int i, const int j) const {\n    int lb = 0;\n\
    \    int ub = std::min(static_cast<int>(s.size()) - i,\n                     \
    \ static_cast<int>(t.s.size()) - j)\n             + 1;\n    while (ub - lb > 1)\
    \ {\n      const int mid = (lb + ub) >> 1;\n      (get(i, i + mid) == t.get(j,\
    \ j + mid) ? lb : ub) = mid;\n    }\n    return lb;\n  }\n\n private:\n  const\
    \ int base, mod;\n  std::vector<long long> hash, power;\n};\n#line 10 \"test/string/rolling_hash.test.cpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  const int t_size\
    \ = t.length(), p_size = p.length();\n  RollingHash<> rolling_hash_t(t), rolling_hash_p(p);\n\
    \  for (int i = 0; i < t_size; ++i) {\n    if (i + p_size <= t_size &&\n     \
    \   rolling_hash_t.get(i, i + p_size) == rolling_hash_p.get(0, p_size)) {\n  \
    \    std::cout << i << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
    \u30B7\u30E5\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../string/rolling_hash.hpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  const int t_size\
    \ = t.length(), p_size = p.length();\n  RollingHash<> rolling_hash_t(t), rolling_hash_p(p);\n\
    \  for (int i = 0; i < t_size; ++i) {\n    if (i + p_size <= t_size &&\n     \
    \   rolling_hash_t.get(i, i + p_size) == rolling_hash_p.get(0, p_size)) {\n  \
    \    std::cout << i << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2022-07-09 22:36:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
