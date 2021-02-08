---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/erdos_gallai.hpp
    title: "\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\u30E9\u30A4\u306E\u5B9A\u7406\
      \ (Erd\u0151s\u2013Gallai theorem)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\
      \u30E9\u30A4\u306E\u5B9A\u7406"
    links:
    - https://atcoder.jp/contests/yahoo-procon2018-qual/tasks/yahoo_procon2018_qual_e
  bundledCode: "#line 1 \"test/graph/erdos_gallai.test.cpp\"\n/*\r\n * @brief \u30B0\
    \u30E9\u30D5/\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\u30E9\u30A4\u306E\u5B9A\
    \u7406\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/yahoo-procon2018-qual/tasks/yahoo_procon2018_qual_e\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#line\
    \ 3 \"graph/erdos_gallai.hpp\"\n#include <functional>\r\n#line 5 \"graph/erdos_gallai.hpp\"\
    \n\r\ntemplate <typename T>\r\nbool erdos_gallai(const std::vector<T> &degree)\
    \ {\r\n  int n = degree.size();\r\n  std::vector<T> deg(degree);\r\n  std::sort(deg.begin(),\
    \ deg.end(), std::greater<T>());\r\n  deg.insert(deg.begin(), 0);\r\n  std::vector<long\
    \ long> sum(n + 1, 0);\r\n  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] +\
    \ deg[i];\r\n  if (sum[n] & 1) return false;\r\n  int right = n;\r\n  for (int\
    \ i = 1; i <= n; ++i) {\r\n    if (right < i) right = i;\r\n    while (right >\
    \ i && deg[right] < i) --right;\r\n    if (sum[i] > static_cast<long long>(i)\
    \ * (i - 1) + static_cast<long long>(i) * (right - i) + sum[n] - sum[right]) return\
    \ false;\r\n  }\r\n  return true;\r\n}\r\n#line 11 \"test/graph/erdos_gallai.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> d(n);\r\
    \n  for (int i = 0; i < n; ++i) std::cin >> d[i];\r\n  if (erdos_gallai(d)) {\r\
    \n    std::cout << \"YES\\n\";\r\n    return 0;\r\n  }\r\n  ++(*std::min_element(d.begin(),\
    \ d.end()));\r\n  std::cout << (erdos_gallai(d) ? \"NO\\n\" : \"ABSOLUTELY NO\\\
    n\");\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\
    \u30E9\u30A4\u306E\u5B9A\u7406\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"\
    https://atcoder.jp/contests/yahoo-procon2018-qual/tasks/yahoo_procon2018_qual_e\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ \"../../graph/erdos_gallai.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::vector<int> d(n);\r\n  for (int i = 0; i < n; ++i) std::cin\
    \ >> d[i];\r\n  if (erdos_gallai(d)) {\r\n    std::cout << \"YES\\n\";\r\n   \
    \ return 0;\r\n  }\r\n  ++(*std::min_element(d.begin(), d.end()));\r\n  std::cout\
    \ << (erdos_gallai(d) ? \"NO\\n\" : \"ABSOLUTELY NO\\n\");\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - graph/erdos_gallai.hpp
  isVerificationFile: true
  path: test/graph/erdos_gallai.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/erdos_gallai.test.cpp
layout: document
redirect_from:
- /verify/test/graph/erdos_gallai.test.cpp
- /verify/test/graph/erdos_gallai.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\u30E9\u30A4\u306E\
  \u5B9A\u7406"
---
