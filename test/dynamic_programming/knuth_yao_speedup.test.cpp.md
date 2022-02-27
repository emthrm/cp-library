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
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"dynamic_programming/knuth_yao_speedup.hpp\"\
    \n#include <algorithm>\r\n#line 4 \"dynamic_programming/knuth_yao_speedup.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::vector<std::vector<T>> knuth_yao_speedup(\r\
    \n    const std::vector<std::vector<T>>& w, const T inf) {\r\n  const int n =\
    \ w.size();\r\n  std::vector<std::vector<T>> dp(n, std::vector<T>(n, inf));\r\n\
    \  if (n == 0) return dp;\r\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n,\
    \ -1));\r\n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i] = 0;\r\n    argmin[i][i]\
    \ = i;\r\n  }\r\n  for (int width = 2; width <= n; ++width) {\r\n    for (int\
    \ i = 0; ; ++i) {\r\n      const int j = i + width - 1;\r\n      if (j >= n) break;\r\
    \n      const int right = std::min(j - 1, argmin[i + 1][j]);\r\n      for (int\
    \ k = argmin[i][j - 1]; k <= right; ++k) {\r\n        const T tmp = dp[i][k] +\
    \ dp[k + 1][j] + w[i][j];\r\n        if (tmp < dp[i][j]) {\r\n          dp[i][j]\
    \ = tmp;\r\n          argmin[i][j] = k;\r\n        }\r\n      }\r\n    }\r\n \
    \ }\r\n  return dp;\r\n}\r\n#line 10 \"test/dynamic_programming/knuth_yao_speedup.test.cpp\"\
    \n\r\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N\
    \ w_i * depth(i) \u306E\u6700\u5C0F\u5024\r\nint main() {\r\n  constexpr long\
    \ long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<long\
    \ long> w(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> w[i];\r\n\
    \  }\r\n  std::vector<std::vector<long long>> f(n, std::vector<long long>(n, LINF));\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    f[i][i] = w[i];\r\n    for (int j = i\
    \ + 1; j < n; ++j) {\r\n      f[i][j] = f[i][j - 1] + w[j];\r\n    }\r\n  }\r\n\
    \  std::cout << knuth_yao_speedup(f, LINF)[0][n - 1] << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup\r\n\
    \ */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../dynamic_programming/knuth_yao_speedup.hpp\"\
    \r\n\r\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N\
    \ w_i * depth(i) \u306E\u6700\u5C0F\u5024\r\nint main() {\r\n  constexpr long\
    \ long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<long\
    \ long> w(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> w[i];\r\n\
    \  }\r\n  std::vector<std::vector<long long>> f(n, std::vector<long long>(n, LINF));\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    f[i][i] = w[i];\r\n    for (int j = i\
    \ + 1; j < n; ++j) {\r\n      f[i][j] = f[i][j - 1] + w[j];\r\n    }\r\n  }\r\n\
    \  std::cout << knuth_yao_speedup(f, LINF)[0][n - 1] << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - dynamic_programming/knuth_yao_speedup.hpp
  isVerificationFile: true
  path: test/dynamic_programming/knuth_yao_speedup.test.cpp
  requiredBy: []
  timestamp: '2022-02-27 15:05:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/knuth_yao_speedup.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
---
