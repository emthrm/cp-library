---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/enumerate_quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc230/tasks/abc230_e
    document_title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
    links:
    - https://atcoder.jp/contests/abc230/tasks/abc230_e
  bundledCode: "#line 1 \"test/math/enumerate_quotients.test.cpp\"\n/*\n * @brief\
    \ \u6570\u5B66/\u5546\u306E\u5217\u6319\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc230/tasks/abc230_e\"\
    \n\n#include <iostream>\n#include <tuple>\n\n#line 3 \"math/enumerate_quotients.hpp\"\
    \n#include <vector>\n\ntemplate <typename T>\nstd::vector<std::tuple<T, T, T>>\
    \ enumerate_quotients(const T n) {\n  std::vector<std::tuple<T, T, T>> quotients;\n\
    \  for (T l = 1; l <= n;) {\n    const T quotient = n / l, r = n / quotient +\
    \ 1;\n    quotients.emplace_back(l, r, quotient);\n    l = r;\n  }\n  return quotients;\n\
    }\n#line 10 \"test/math/enumerate_quotients.test.cpp\"\n\nint main() {\n  long\
    \ long n;\n  std::cin >> n;\n  long long ans = 0;\n  for (const std::tuple<long\
    \ long, long long, long long>& lrq\n       : enumerate_quotients(n)) {\n    long\
    \ long l, r, q;\n    std::tie(l, r, q) = lrq;\n    ans += q * (r - l);\n  }\n\
    \  std::cout << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u5546\u306E\u5217\u6319\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc230/tasks/abc230_e\"\n\n#include <iostream>\n\
    #include <tuple>\n\n#include \"../../math/enumerate_quotients.hpp\"\n\nint main()\
    \ {\n  long long n;\n  std::cin >> n;\n  long long ans = 0;\n  for (const std::tuple<long\
    \ long, long long, long long>& lrq\n       : enumerate_quotients(n)) {\n    long\
    \ long l, r, q;\n    std::tie(l, r, q) = lrq;\n    ans += q * (r - l);\n  }\n\
    \  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/math/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_quotients.test.cpp
- /verify/test/math/enumerate_quotients.test.cpp.html
title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
---
