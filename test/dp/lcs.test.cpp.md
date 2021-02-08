---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dp/lcs.hpp
    title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (longest common subsequence)"
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
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\
      \u5206\u5217"
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_f
  bundledCode: "#line 1 \"test/dp/lcs.test.cpp\"\n/*\r\n * @brief \u52D5\u7684\u8A08\
    \u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_f\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#line 2 \"dp/lcs.hpp\"\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nT lcs(const T &a, const T\
    \ &b) {\r\n  int a_sz = a.size(), b_sz = b.size();\r\n  std::vector<std::vector<int>>\
    \ dp(a_sz + 1, std::vector<int>(b_sz + 1, 0));\r\n  for (int i = 0; i < a_sz;\
    \ ++i) for (int j = 0; j < b_sz; ++j) {\r\n    dp[i + 1][j + 1] = a[i] == b[j]\
    \ ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]);\r\n  }\r\n  T res;\r\n\
    \  while (a_sz > 0 && b_sz > 0) {\r\n    if (dp[a_sz][b_sz] == dp[a_sz - 1][b_sz])\
    \ {\r\n      --a_sz;\r\n    } else if (dp[a_sz][b_sz] == dp[a_sz][b_sz - 1]) {\r\
    \n      --b_sz;\r\n    } else {\r\n      res.push_back(a[a_sz - 1]);\r\n     \
    \ --a_sz; --b_sz;\r\n    }\r\n  }\r\n  std::reverse(res.begin(), res.end());\r\
    \n  return res;\r\n}\r\n#line 10 \"test/dp/lcs.test.cpp\"\n\r\nint main() {\r\n\
    \  std::string s, t;\r\n  std::cin >> s >> t;\r\n  std::cout << lcs(s, t) << '\\\
    n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_f\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../dp/lcs.hpp\"\
    \r\n\r\nint main() {\r\n  std::string s, t;\r\n  std::cin >> s >> t;\r\n  std::cout\
    \ << lcs(s, t) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dp/lcs.hpp
  isVerificationFile: true
  path: test/dp/lcs.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dp/lcs.test.cpp
layout: document
redirect_from:
- /verify/test/dp/lcs.test.cpp
- /verify/test/dp/lcs.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217"
---
