---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932
    document_title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932
  bundledCode: "#line 1 \"test/math/divisor.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u7D04\u6570\u5217\u6319\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"math/divisor.hpp\"\
    \n#include <algorithm>\r\n#line 4 \"math/divisor.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<T> divisor(T val) {\r\n  std::vector<T> res;\r\n  for (T i\
    \ = 1; i * i <= val; ++i) {\r\n    if (val % i == 0) {\r\n      res.emplace_back(i);\r\
    \n      if (i * i != val) res.emplace_back(val / i);\r\n    }\r\n  }\r\n  std::sort(res.begin(),\
    \ res.end());\r\n  return res;\r\n}\r\n#line 9 \"test/math/divisor.test.cpp\"\n\
    \r\nint main() {\r\n  long long n;\r\n  std::cin >> n;\r\n  std::vector<long long>\
    \ d = divisor(n);\r\n  d.pop_back();\r\n  int cnt = 0, m = d.size();\r\n  while\
    \ (!d.empty()) {\r\n    ++cnt;\r\n    std::vector<long long> tmp;\r\n    for (long\
    \ long e : d) {\r\n      if (d.back() % e != 0) tmp.emplace_back(e);\r\n    }\r\
    \n    d = tmp;\r\n  }\r\n  std::cout << cnt << ' ' << m << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include \"../../math/divisor.hpp\"\r\n\r\
    \nint main() {\r\n  long long n;\r\n  std::cin >> n;\r\n  std::vector<long long>\
    \ d = divisor(n);\r\n  d.pop_back();\r\n  int cnt = 0, m = d.size();\r\n  while\
    \ (!d.empty()) {\r\n    ++cnt;\r\n    std::vector<long long> tmp;\r\n    for (long\
    \ long e : d) {\r\n      if (d.back() % e != 0) tmp.emplace_back(e);\r\n    }\r\
    \n    d = tmp;\r\n  }\r\n  std::cout << cnt << ' ' << m << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - math/divisor.hpp
  isVerificationFile: true
  path: test/math/divisor.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/divisor.test.cpp
- /verify/test/math/divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
