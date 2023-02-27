---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/knuth_yao_speedup.hpp
    title: "Knuth\u2013Yao speedup"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
  bundledCode: "#line 1 \"test/dynamic_programming/knuth_yao_speedup.test.cpp\"\n\
    /*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup\n *\n * verification-helper:\
    \ PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\n */\n\
    \n#include <iostream>\n#include <limits>\n#include <vector>\n\n#line 1 \"include/emthrm/dynamic_programming/knuth_yao_speedup.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"include/emthrm/dynamic_programming/knuth_yao_speedup.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> knuth_yao_speedup(\n\
    \    const std::vector<std::vector<T>>& w, const T inf) {\n  const int n = w.size();\n\
    \  std::vector<std::vector<T>> dp(n, std::vector<T>(n, inf));\n  if (n == 0) [[unlikely]]\
    \ return dp;\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n, -1));\n\
    \  for (int j = 0; j < n; ++j) {\n    dp[j][j] = 0;\n    argmin[j][j] = j;\n \
    \   for (int i = j - 1; i >= 0; --i) {\n      const int right = std::min(j - 1,\
    \ argmin[i + 1][j]);\n      for (int k = argmin[i][j - 1]; k <= right; ++k) {\n\
    \        const T tmp = dp[i][k] + dp[k + 1][j];\n        if (tmp < dp[i][j]) {\n\
    \          dp[i][j] = tmp;\n          argmin[i][j] = k;\n        }\n      }\n\
    \      dp[i][j] += w[i][j];\n    }\n  }\n  return dp;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 12 \"test/dynamic_programming/knuth_yao_speedup.test.cpp\"\n\n// \u4E8C\
    \u5206\u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N w_i * depth(i)\
    \ \u306E\u6700\u5C0F\u5024\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<long\
    \ long>> w(n, std::vector<long long>(n));\n  for (int j = 0; j < n; ++j) {\n \
    \   std::cin >> w.front()[j];\n    if (j > 0) [[likely]] w.front()[j] += w.front()[j\
    \ - 1];\n  }\n  for (int i = 1; i < n; ++i) {\n    for (int j = i; j < n; ++j)\
    \ {\n      w[i][j] = w.front()[j] - w.front()[i - 1];\n    }\n  }\n  std::cout\
    \ << emthrm::knuth_yao_speedup(\n                   w, std::numeric_limits<long\
    \ long>::max())[0][n - 1]\n            << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup\n *\n\
    \ * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\n\
    \ */\n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#include\
    \ \"emthrm/dynamic_programming/knuth_yao_speedup.hpp\"\n\n// \u4E8C\u5206\u63A2\
    \u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N w_i * depth(i) \u306E\u6700\
    \u5C0F\u5024\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<long\
    \ long>> w(n, std::vector<long long>(n));\n  for (int j = 0; j < n; ++j) {\n \
    \   std::cin >> w.front()[j];\n    if (j > 0) [[likely]] w.front()[j] += w.front()[j\
    \ - 1];\n  }\n  for (int i = 1; i < n; ++i) {\n    for (int j = i; j < n; ++j)\
    \ {\n      w[i][j] = w.front()[j] - w.front()[i - 1];\n    }\n  }\n  std::cout\
    \ << emthrm::knuth_yao_speedup(\n                   w, std::numeric_limits<long\
    \ long>::max())[0][n - 1]\n            << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/knuth_yao_speedup.hpp
  isVerificationFile: true
  path: test/dynamic_programming/knuth_yao_speedup.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/knuth_yao_speedup.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
---
