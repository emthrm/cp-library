---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932
    document_title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932
  bundledCode: "#line 1 \"test/math/divisor.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u7D04\u6570\u5217\u6319\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"math/divisor.hpp\"\
    \n#include <algorithm>\r\n#line 4 \"math/divisor.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<T> divisor(const T n) {\r\n  std::vector<T> res;\r\n  T i\
    \ = 1;\r\n  for (; i * i < n; ++i) {\r\n    if (n % i == 0) {\r\n      res.emplace_back(i);\r\
    \n      res.emplace_back(n / i);\r\n    }\r\n  }\r\n  if (i * i == n && n % i\
    \ == 0) res.emplace_back(i);\r\n  std::sort(res.begin(), res.end());\r\n  return\
    \ res;\r\n}\r\n#line 10 \"test/math/divisor.test.cpp\"\n\r\nint main() {\r\n \
    \ long long n;\r\n  std::cin >> n;\r\n  std::vector<long long> d = divisor(n);\r\
    \n  d.pop_back();\r\n  int ans1 = 0;\r\n  const int ans2 = d.size();\r\n  while\
    \ (!d.empty()) {\r\n    ++ans1;\r\n    std::vector<long long> nxt;\r\n    for\
    \ (const long long e : d) {\r\n      if (d.back() % e != 0) nxt.emplace_back(e);\r\
    \n    }\r\n    d = nxt;\r\n  }\r\n  std::cout << ans1 << ' ' << ans2 << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\n#include \"../../math/divisor.hpp\"\r\
    \n\r\nint main() {\r\n  long long n;\r\n  std::cin >> n;\r\n  std::vector<long\
    \ long> d = divisor(n);\r\n  d.pop_back();\r\n  int ans1 = 0;\r\n  const int ans2\
    \ = d.size();\r\n  while (!d.empty()) {\r\n    ++ans1;\r\n    std::vector<long\
    \ long> nxt;\r\n    for (const long long e : d) {\r\n      if (d.back() % e !=\
    \ 0) nxt.emplace_back(e);\r\n    }\r\n    d = nxt;\r\n  }\r\n  std::cout << ans1\
    \ << ' ' << ans2 << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/divisor.hpp
  isVerificationFile: true
  path: test/math/divisor.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/divisor.test.cpp
- /verify/test/math/divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
