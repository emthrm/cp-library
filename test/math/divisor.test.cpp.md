---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/math/divisor.test.cpp\"\n/*\n * @brief \u6570\u5B66\
    /\u7D04\u6570\u5217\u6319\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"math/divisor.hpp\"\n#include\
    \ <algorithm>\n#line 4 \"math/divisor.hpp\"\n\ntemplate <typename T>\nstd::vector<T>\
    \ divisor(const T n) {\n  std::vector<T> res;\n  T i = 1;\n  for (; i * i < n;\
    \ ++i) {\n    if (n % i == 0) {\n      res.emplace_back(i);\n      res.emplace_back(n\
    \ / i);\n    }\n  }\n  if (i * i == n && n % i == 0) res.emplace_back(i);\n  std::sort(res.begin(),\
    \ res.end());\n  return res;\n}\n#line 10 \"test/math/divisor.test.cpp\"\n\nint\
    \ main() {\n  long long n;\n  std::cin >> n;\n  std::vector<long long> d = divisor(n);\n\
    \  d.pop_back();\n  int ans1 = 0;\n  const int ans2 = d.size();\n  while (!d.empty())\
    \ {\n    ++ans1;\n    std::vector<long long> nxt;\n    for (const long long e\
    \ : d) {\n      if (d.back() % e != 0) nxt.emplace_back(e);\n    }\n    d = nxt;\n\
    \  }\n  std::cout << ans1 << ' ' << ans2 << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../math/divisor.hpp\"\n\nint\
    \ main() {\n  long long n;\n  std::cin >> n;\n  std::vector<long long> d = divisor(n);\n\
    \  d.pop_back();\n  int ans1 = 0;\n  const int ans2 = d.size();\n  while (!d.empty())\
    \ {\n    ++ans1;\n    std::vector<long long> nxt;\n    for (const long long e\
    \ : d) {\n      if (d.back() % e != 0) nxt.emplace_back(e);\n    }\n    d = nxt;\n\
    \  }\n  std::cout << ans1 << ' ' << ans2 << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/divisor.hpp
  isVerificationFile: true
  path: test/math/divisor.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/divisor.test.cpp
- /verify/test/math/divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
