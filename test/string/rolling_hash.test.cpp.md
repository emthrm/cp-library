---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/string/rolling_hash.hpp
    title: rolling hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc141/tasks/abc141_e
    document_title: "\u6587\u5B57\u5217/rolling hash"
    links:
    - https://atcoder.jp/contests/abc141/tasks/abc141_e
  bundledCode: "#line 1 \"test/string/rolling_hash.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/rolling hash\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc141/tasks/abc141_e\n */\n\n#include <iostream>\n\
    #include <set>\n#include <string>\n\n#line 1 \"include/emthrm/string/rolling_hash.hpp\"\
    \n\n\n\n#include <cassert>\n#include <cstdint>\n#include <random>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T = char>\nstruct RollingHash {\n \
    \ const std::int64_t base;\n  std::vector<T> str;\n\n  template <typename U>\n\
    \  explicit RollingHash(const U& str_, const std::int64_t base = generate_base())\n\
    \      : base(base), hashes({0}), powers({1}) {\n    const int n = str_.size();\n\
    \    str.reserve(n);\n    hashes.reserve(n + 1);\n    powers.reserve(n + 1);\n\
    \    for (const auto ch : str_) add(ch);\n  }\n\n  void add(const T ch) {\n  \
    \  assert(0 <= ch && ch < MOD);\n    str.emplace_back(ch);\n    const std::int64_t\
    \ h = mul(hashes.back(), base) + ch;\n    hashes.emplace_back(h >= MOD ? h - MOD\
    \ : h);\n    const std::int64_t p = mul(powers.back(), base);\n    powers.emplace_back(p);\n\
    \  }\n\n  std::int64_t get(const int left, const int right) const {\n    const\
    \ std::int64_t res =\n        hashes[right] - mul(hashes[left], powers[right -\
    \ left]);\n    return res < 0 ? res + MOD : res;\n  }\n\n private:\n  static constexpr\
    \ int MOD_WIDTH = 61;\n  static constexpr std::int64_t MOD = (INT64_C(1) << MOD_WIDTH)\
    \ - 1;\n\n  std::vector<std::int64_t> hashes, powers;\n\n  static std::int64_t\
    \ generate_base() {\n    static std::mt19937_64 engine(std::random_device {} ());\n\
    \    static std::uniform_int_distribution<std::int64_t> dist(0, MOD - 1);\n  \
    \  return dist(engine);\n  }\n\n  static std::int64_t mul(const std::int64_t a,\
    \ const std::int64_t b) {\n    const std::int64_t au = a >> 31, ad = a & ((UINT32_C(1)\
    \ << 31) - 1);\n    const std::int32_t bu = b >> 31, bd = b & ((UINT32_C(1) <<\
    \ 31) - 1);\n    const std::int64_t mid = au * bd + ad * bu;\n    std::int64_t\
    \ res = au * bu * 2 + ad * bd + (mid >> 30)\n                       + ((mid &\
    \ ((UINT32_C(1) << 30) - 1)) << 31);\n    res = (res >> MOD_WIDTH) + (res & MOD);\n\
    \    return res >= MOD ? res - MOD : res;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 13 \"test/string/rolling_hash.test.cpp\"\n\nint main() {\n  int n;\n\
    \  std::string s;\n  std::cin >> n >> s;\n  emthrm::RollingHash<> rolling_hash(s);\n\
    \  for (int len = n - 1; len >= 1; --len) {\n    std::set<std::int64_t> hashes;\n\
    \    for (int i = len; i + len <= n; ++i) {\n      hashes.emplace(rolling_hash.get(i\
    \ - len, i));\n      if (hashes.contains(rolling_hash.get(i, i + len))) {\n  \
    \      std::cout << len << '\\n';\n        return 0;\n      }\n    }\n  }\n  std::cout\
    \ << 0 << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/rolling hash\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc141/tasks/abc141_e\n\
    \ */\n\n#include <iostream>\n#include <set>\n#include <string>\n\n#include \"\
    emthrm/string/rolling_hash.hpp\"\n\nint main() {\n  int n;\n  std::string s;\n\
    \  std::cin >> n >> s;\n  emthrm::RollingHash<> rolling_hash(s);\n  for (int len\
    \ = n - 1; len >= 1; --len) {\n    std::set<std::int64_t> hashes;\n    for (int\
    \ i = len; i + len <= n; ++i) {\n      hashes.emplace(rolling_hash.get(i - len,\
    \ i));\n      if (hashes.contains(rolling_hash.get(i, i + len))) {\n        std::cout\
    \ << len << '\\n';\n        return 0;\n      }\n    }\n  }\n  std::cout << 0 <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/rolling_hash.hpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 12:14:05+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: "\u6587\u5B57\u5217/rolling hash"
---
