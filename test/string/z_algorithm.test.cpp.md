---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/z_algorithm.hpp
    title: Z algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    document_title: "\u6587\u5B57\u5217/Z algorithm"
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/z_algorithm.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/Z algorithm\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n\
    #line 2 \"string/z_algorithm.hpp\"\n#include <algorithm>\r\n#line 4 \"string/z_algorithm.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::vector<int> z_algorithm(const T &s) {\r\n\
    \  const int n = s.size();\r\n  std::vector<int> res(n, 0);\r\n  for (int i =\
    \ 1, j = 0; i < n; ++i) {\r\n    if (i + res[i - j] < j + res[j]) {\r\n      res[i]\
    \ = res[i - j];\r\n    } else {\r\n      res[i] = std::max(j + res[j] - i, 0);\r\
    \n      while (i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];\r\n   \
    \   j = i;\r\n    }\r\n  }\r\n  res[0] = n;\r\n  return res;\r\n}\r\n#line 11\
    \ \"test/string/z_algorithm.test.cpp\"\n\r\nint main() {\r\n  std::string s;\r\
    \n  std::cin >> s;\r\n  const std::vector<int> ans = z_algorithm(s);\r\n  for\
    \ (int i = 0; i < s.length(); ++i) {\r\n    std::cout << ans[i] << \" \\n\"[i\
    \ + 1 == s.length()];\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/Z algorithm\r\n */\r\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include <iostream>\r\n\
    #include <string>\r\n#include <vector>\r\n\r\n#include \"../../string/z_algorithm.hpp\"\
    \r\n\r\nint main() {\r\n  std::string s;\r\n  std::cin >> s;\r\n  const std::vector<int>\
    \ ans = z_algorithm(s);\r\n  for (int i = 0; i < s.length(); ++i) {\r\n    std::cout\
    \ << ans[i] << \" \\n\"[i + 1 == s.length()];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: test/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/string/z_algorithm.test.cpp
- /verify/test/string/z_algorithm.test.cpp.html
title: "\u6587\u5B57\u5217/Z algorithm"
---
