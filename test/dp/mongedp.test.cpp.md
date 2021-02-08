---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/mongedp.hpp
    title: MongeDP (Knuth-Yao speedup)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/MongeDP"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
  bundledCode: "#line 1 \"test/dp/mongedp.test.cpp\"\n/*\r\n * @brief \u52D5\u7684\
    \u8A08\u753B\u6CD5/MongeDP\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\
    \r\n\r\n#include <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n#line\
    \ 2 \"dp/mongedp.hpp\"\n#include <algorithm>\r\n#line 4 \"dp/mongedp.hpp\"\n\r\
    \ntemplate <typename Fn, typename T>\r\nT mongedp(int n, Fn cost, const T TINF)\
    \ {\r\n  if (n == 0) return 0;\r\n  std::vector<std::vector<T>> dp(n, std::vector<T>(n,\
    \ TINF));\r\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n, -1));\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i] = 0;\r\n    argmin[i][i] = i;\r\
    \n  }\r\n  for (int width = 1; width < n; ++width) {\r\n    for (int i = 0; i\
    \ + width < n; ++i) {\r\n      int j = i + width, right = std::min(j - 1, argmin[i\
    \ + 1][j]);\r\n      for (int k = argmin[i][j - 1]; k <= right; ++k) {\r\n   \
    \     T tmp = dp[i][k] + dp[k + 1][j] + cost(i, k, j);\r\n        if (dp[i][j]\
    \ > tmp) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j] = k;\r\n   \
    \     }\r\n      }\r\n    }\r\n  }\r\n  return dp[0][n - 1];\r\n}\r\n#line 10\
    \ \"test/dp/mongedp.test.cpp\"\n\r\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\
    \u30B9\u30C8: \u03A3a[i] * depth(i) \u306E\u6700\u5C0F\u5024\r\nint main() {\r\
    \n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::vector<long long> w(n);\r\n  for (int i = 0; i < n; ++i) std::cin\
    \ >> w[i];\r\n  std::vector<long long> sum(n + 1, 0);\r\n  std::partial_sum(w.begin(),\
    \ w.end(), sum.begin() + 1);\r\n  auto cost = [&sum](int i, int k, int j) -> long\
    \ long { return sum[j + 1] - sum[i]; };\r\n  std::cout << mongedp(n, cost, LINF)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/MongeDP\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\r\n\
    \r\n#include <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n#include\
    \ \"../../dp/mongedp.hpp\"\r\n\r\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\
    \u30B9\u30C8: \u03A3a[i] * depth(i) \u306E\u6700\u5C0F\u5024\r\nint main() {\r\
    \n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::vector<long long> w(n);\r\n  for (int i = 0; i < n; ++i) std::cin\
    \ >> w[i];\r\n  std::vector<long long> sum(n + 1, 0);\r\n  std::partial_sum(w.begin(),\
    \ w.end(), sum.begin() + 1);\r\n  auto cost = [&sum](int i, int k, int j) -> long\
    \ long { return sum[j + 1] - sum[i]; };\r\n  std::cout << mongedp(n, cost, LINF)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dp/mongedp.hpp
  isVerificationFile: true
  path: test/dp/mongedp.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dp/mongedp.test.cpp
layout: document
redirect_from:
- /verify/test/dp/mongedp.test.cpp
- /verify/test/dp/mongedp.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/MongeDP"
---
