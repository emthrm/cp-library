---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dp/knuth_yao_speedup.hpp
    title: Knuth-Yao speedup
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
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth-Yao speedup"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
  bundledCode: "#line 1 \"test/dp/knuth_yao_speedup.test.cpp\"\n/*\r\n * @brief \u52D5\
    \u7684\u8A08\u753B\u6CD5/Knuth-Yao speedup\r\n */\r\n#define IGNORE\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"dp/knuth_yao_speedup.hpp\"\
    \n#include <algorithm>\r\n#line 4 \"dp/knuth_yao_speedup.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nT knuth_yao_speedup(const std::vector<std::vector<T>> &f, const T inf)\
    \ {\r\n  int n = f.size();\r\n  if (n == 0) return 0;\r\n  std::vector<std::vector<T>>\
    \ dp(n, std::vector<T>(n, inf));\r\n  std::vector<std::vector<int>> argmin(n,\
    \ std::vector<int>(n, -1));\r\n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i]\
    \ = 0;\r\n    argmin[i][i] = i;\r\n  }\r\n  for (int width = 2; width <= n; ++width)\
    \ {\r\n    for (int i = 0; i + width - 1 < n; ++i) {\r\n      int j = i + width\
    \ - 1, right = std::min(j - 1, argmin[i + 1][j]);\r\n      for (int k = argmin[i][j\
    \ - 1]; k <= right; ++k) {\r\n        T tmp = dp[i][k] + dp[k + 1][j] + f[i][j];\r\
    \n        if (dp[i][j] > tmp) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j]\
    \ = k;\r\n        }\r\n      }\r\n    }\r\n  }\r\n  return dp[0][n - 1];\r\n}\r\
    \n#line 10 \"test/dp/knuth_yao_speedup.test.cpp\"\n\r\n// \u4E8C\u5206\u63A2\u7D22\
    \u6728\u306E\u30B3\u30B9\u30C8: \u03A3a[i] * depth(i) \u306E\u6700\u5C0F\u5024\
    \r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int\
    \ n;\r\n  std::cin >> n;\r\n  std::vector<long long> w(n);\r\n  for (int i = 0;\
    \ i < n; ++i) std::cin >> w[i];\r\n  std::vector<std::vector<long long>> f(n,\
    \ std::vector<long long>(n, 0));\r\n  for (int i = 0; i < n; ++i) {\r\n    f[i][i]\
    \ = w[i];\r\n    for (int j = i + 1; j < n; ++j) f[i][j] = f[i][j - 1] + w[j];\r\
    \n  }\r\n  std::cout << knuth_yao_speedup(f, LINF) << '\\n';\r\n  return 0;\r\n\
    }\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Knuth-Yao speedup\r\n */\r\
    \n#define IGNORE\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../dp/knuth_yao_speedup.hpp\"\
    \r\n\r\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8: \u03A3a[i]\
    \ * depth(i) \u306E\u6700\u5C0F\u5024\r\nint main() {\r\n  constexpr long long\
    \ LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<long\
    \ long> w(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> w[i];\r\n  std::vector<std::vector<long\
    \ long>> f(n, std::vector<long long>(n, 0));\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    f[i][i] = w[i];\r\n    for (int j = i + 1; j < n; ++j) f[i][j] = f[i][j\
    \ - 1] + w[j];\r\n  }\r\n  std::cout << knuth_yao_speedup(f, LINF) << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  dependsOn:
  - dp/knuth_yao_speedup.hpp
  isVerificationFile: true
  path: test/dp/knuth_yao_speedup.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 03:52:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dp/knuth_yao_speedup.test.cpp
layout: document
redirect_from:
- /verify/test/dp/knuth_yao_speedup.test.cpp
- /verify/test/dp/knuth_yao_speedup.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth-Yao speedup"
---
