---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/enumerate_quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc230/tasks/abc230_e
    document_title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
    links:
    - https://atcoder.jp/contests/abc230/tasks/abc230_e
  bundledCode: "#line 1 \"test/math/enumerate_quotients.test.cpp\"\n/*\n * @title\
    \ \u6570\u5B66/\u5546\u306E\u5217\u6319\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc230/tasks/abc230_e\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/math/enumerate_quotients.hpp\"\
    \n\n\n\n#include <tuple>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <typename T>\nstd::vector<std::tuple<T, T, T>> enumerate_quotients(const T n)\
    \ {\n  std::vector<std::tuple<T, T, T>> quotients;\n  for (T l = 1; l <= n;) {\n\
    \    const T quotient = n / l, r = n / quotient + 1;\n    quotients.emplace_back(l,\
    \ r, quotient);\n    l = r;\n  }\n  return quotients;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 10 \"test/math/enumerate_quotients.test.cpp\"\n\nint main() {\n  long\
    \ long n;\n  std::cin >> n;\n  long long ans = 0;\n  for (const auto& [l, r, q]\
    \ : emthrm::enumerate_quotients(n)) {\n    ans += q * (r - l);\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5546\u306E\u5217\u6319\n *\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc230/tasks/abc230_e\n */\n\n#include <iostream>\n\
    \n#include \"emthrm/math/enumerate_quotients.hpp\"\n\nint main() {\n  long long\
    \ n;\n  std::cin >> n;\n  long long ans = 0;\n  for (const auto& [l, r, q] : emthrm::enumerate_quotients(n))\
    \ {\n    ans += q * (r - l);\n  }\n  std::cout << ans << '\\n';\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/math/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_quotients.test.cpp
- /verify/test/math/enumerate_quotients.test.cpp.html
title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
---
