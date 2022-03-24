---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/knuth_yao_speedup.hpp
    title: "Knuth\u2013Yao speedup"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
  bundledCode: "#line 1 \"test/dynamic_programming/knuth_yao_speedup.test.cpp\"\n\
    /*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup\r\n */\r\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\
    \r\n\r\n#include <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n\r\n\
    #line 2 \"dynamic_programming/knuth_yao_speedup.hpp\"\n#include <algorithm>\r\n\
    #line 4 \"dynamic_programming/knuth_yao_speedup.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<std::vector<T>> knuth_yao_speedup(\r\n    const std::vector<std::vector<T>>&\
    \ w, const T inf) {\r\n  const int n = w.size();\r\n  std::vector<std::vector<T>>\
    \ dp(n, std::vector<T>(n, inf));\r\n  if (n == 0) return dp;\r\n  std::vector<std::vector<int>>\
    \ argmin(n, std::vector<int>(n, -1));\r\n  for (int j = 0; j < n; ++j) {\r\n \
    \   dp[j][j] = 0;\r\n    argmin[j][j] = j;\r\n    for (int i = j - 1; i >= 0;\
    \ --i) {\r\n      const int right = std::min(j - 1, argmin[i + 1][j]);\r\n   \
    \   for (int k = argmin[i][j - 1]; k <= right; ++k) {\r\n        const T tmp =\
    \ dp[i][k] + dp[k + 1][j];\r\n        if (tmp < dp[i][j]) {\r\n          dp[i][j]\
    \ = tmp;\r\n          argmin[i][j] = k;\r\n        }\r\n      }\r\n      dp[i][j]\
    \ += w[i][j];\r\n    }\r\n  }\r\n  return dp;\r\n}\r\n#line 11 \"test/dynamic_programming/knuth_yao_speedup.test.cpp\"\
    \n\r\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N\
    \ w_i * depth(i) \u306E\u6700\u5C0F\u5024\r\nint main() {\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::vector<std::vector<long long>> w(n, std::vector<long long>(n));\r\
    \n  for (int j = 0; j < n; ++j) {\r\n    std::cin >> w.front()[j];\r\n    if (j\
    \ > 0) w.front()[j] += w.front()[j - 1];\r\n  }\r\n  for (int i = 1; i < n; ++i)\
    \ {\r\n    for (int j = i; j < n; ++j) {\r\n      w[i][j] = w.front()[j] - w.front()[i\
    \ - 1];\r\n    }\r\n  }\r\n  std::cout << knuth_yao_speedup(\r\n             \
    \      w, std::numeric_limits<long long>::max())[0][n - 1]\r\n            << '\\\
    n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup\r\n\
    \ */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\
    \r\n\r\n#include <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n\r\n\
    #include \"../../dynamic_programming/knuth_yao_speedup.hpp\"\r\n\r\n// \u4E8C\u5206\
    \u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N w_i * depth(i) \u306E\
    \u6700\u5C0F\u5024\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<long\
    \ long>> w(n, std::vector<long long>(n));\r\n  for (int j = 0; j < n; ++j) {\r\
    \n    std::cin >> w.front()[j];\r\n    if (j > 0) w.front()[j] += w.front()[j\
    \ - 1];\r\n  }\r\n  for (int i = 1; i < n; ++i) {\r\n    for (int j = i; j < n;\
    \ ++j) {\r\n      w[i][j] = w.front()[j] - w.front()[i - 1];\r\n    }\r\n  }\r\
    \n  std::cout << knuth_yao_speedup(\r\n                   w, std::numeric_limits<long\
    \ long>::max())[0][n - 1]\r\n            << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/knuth_yao_speedup.hpp
  isVerificationFile: true
  path: test/dynamic_programming/knuth_yao_speedup.test.cpp
  requiredBy: []
  timestamp: '2022-03-23 02:29:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/knuth_yao_speedup.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
---
