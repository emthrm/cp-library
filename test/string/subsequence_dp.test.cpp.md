---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/subsequence_dp.hpp
    title: "\u90E8\u5206\u5217 DP"
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
    document_title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
    links:
    - https://codeforces.com/problemset/problem/1149/B
  bundledCode: "#line 1 \"test/string/subsequence_dp.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/\u90E8\u5206\u5217 DP\r\n */\r\n#define IGNORE\r\n#define PROBLEM\
    \ \"https://codeforces.com/problemset/problem/1149/B\"\r\n\r\n#include <iostream>\r\
    \n#include <string>\r\n#include <vector>\r\n#line 4 \"string/subsequence_dp.hpp\"\
    \n\r\nstd::vector<std::vector<int>> nx_init(const std::string &s, const char basis\
    \ = 'a', const int char_sz = 26) {\r\n  int n = s.size();\r\n  std::vector<std::vector<int>>\
    \ nx(n, std::vector<int>(char_sz, n));\r\n  nx[n - 1][s[n - 1] - basis] = n -\
    \ 1;\r\n  for (int i = n - 2; i >= 0; --i) {\r\n    for (int j = 0; j < char_sz;\
    \ ++j) nx[i][j] = nx[i + 1][j];\r\n    nx[i][s[i] - basis] = i;\r\n  }\r\n  return\
    \ nx;\r\n}\r\n#line 11 \"test/string/subsequence_dp.test.cpp\"\n\r\nint main()\
    \ {\r\n  constexpr int D = 250;\r\n  int n, q;\r\n  std::string s;\r\n  std::cin\
    \ >> n >> q >> s;\r\n  std::vector<std::vector<int>> nx = nx_init(s);\r\n  std::vector<std::vector<std::vector<int>>>\
    \ dp(D + 1, std::vector<std::vector<int>>(D + 1, std::vector<int>(D + 1, n)));\r\
    \n  dp[0][0][0] = -1;\r\n  std::vector<int> len(3, 0);\r\n  std::vector<std::vector<char>>\
    \ str(3);\r\n  while (q--) {\r\n    char ope;\r\n    int i;\r\n    std::cin >>\
    \ ope >> i;\r\n    --i;\r\n    if (ope == '+') {\r\n      char c;\r\n      std::cin\
    \ >> c;\r\n      ++len[i];\r\n      str[i].emplace_back(c);\r\n      if (i ==\
    \ 0) {\r\n        for (int y = 0; y <= len[1]; ++y) for (int z = 0; z <= len[2];\
    \ ++z) {\r\n          int &now = dp[len[0]][y][z];\r\n          now = n;\r\n \
    \         if (len[0] > 0 && dp[len[0] - 1][y][z] + 1 < n && nx[dp[len[0] - 1][y][z]\
    \ + 1][str[0][len[0] - 1] - 'a'] < now) {\r\n            now = nx[dp[len[0] -\
    \ 1][y][z] + 1][str[0][len[0] - 1] - 'a'];\r\n          }\r\n          if (y >\
    \ 0 && dp[len[0]][y - 1][z] + 1 < n && nx[dp[len[0]][y - 1][z] + 1][str[1][y -\
    \ 1] - 'a'] < now) {\r\n            now = nx[dp[len[0]][y - 1][z] + 1][str[1][y\
    \ - 1] - 'a'];\r\n          }\r\n          if (z > 0 && dp[len[0]][y][z - 1] +\
    \ 1 < n && nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a'] < now) {\r\n    \
    \        now = nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a'];\r\n        \
    \  }\r\n        }\r\n      } else if (i == 1) {\r\n        for (int x = 0; x <=\
    \ len[0]; ++x) for (int z = 0; z <= len[2]; ++z) {\r\n          int &now = dp[x][len[1]][z];\r\
    \n          now = n;\r\n          if (x > 0 && dp[x - 1][len[1]][z] + 1 < n &&\
    \ nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a'] < now) {\r\n            now\
    \ = nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a'];\r\n          }\r\n    \
    \      if (len[1] > 0 && dp[x][len[1] - 1][z] + 1 < n && nx[dp[x][len[1] - 1][z]\
    \ + 1][str[1][len[1] - 1] - 'a'] < now) {\r\n            now = nx[dp[x][len[1]\
    \ - 1][z] + 1][str[1][len[1] - 1] - 'a'];\r\n          }\r\n          if (z >\
    \ 0 && dp[x][len[1]][z - 1] + 1 < n && nx[dp[x][len[1]][z - 1] + 1][str[2][z -\
    \ 1] - 'a'] < now) {\r\n            now = nx[dp[x][len[1]][z - 1] + 1][str[2][z\
    \ - 1] - 'a'];\r\n          }\r\n        }\r\n      } else if (i == 2) {\r\n \
    \       for (int x = 0; x <= len[0]; ++x) for (int y = 0; y <= len[1]; ++y) {\r\
    \n          int &now = dp[x][y][len[2]];\r\n          now = n;\r\n          if\
    \ (x > 0 && dp[x - 1][y][len[2]] + 1 < n && nx[dp[x - 1][y][len[2]] + 1][str[0][x\
    \ - 1] - 'a'] < now) {\r\n            now = nx[dp[x - 1][y][len[2]] + 1][str[0][x\
    \ - 1] - 'a'];\r\n          }\r\n          if (y > 0 && dp[x][y - 1][len[2]] +\
    \ 1 < n && nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a'] < now) {\r\n    \
    \        now = nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a'];\r\n        \
    \  }\r\n          if (len[2] > 0 && dp[x][y][len[2] - 1] + 1 < n && nx[dp[x][y][len[2]\
    \ - 1] + 1][str[2][len[2] - 1] - 'a'] < now) {\r\n            now = nx[dp[x][y][len[2]\
    \ - 1] + 1][str[2][len[2] - 1] - 'a'];\r\n          }\r\n        }\r\n      }\r\
    \n    } else if (ope == '-') {\r\n      --len[i];\r\n      str[i].pop_back();\r\
    \n    }\r\n    std::cout << (dp[len[0]][len[1]][len[2]] < n ? \"YES\\n\" : \"\
    NO\\n\");\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u90E8\u5206\u5217 DP\r\n */\r\n#define\
    \ IGNORE\r\n#define PROBLEM \"https://codeforces.com/problemset/problem/1149/B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#include\
    \ \"../../string/subsequence_dp.hpp\"\r\n\r\nint main() {\r\n  constexpr int D\
    \ = 250;\r\n  int n, q;\r\n  std::string s;\r\n  std::cin >> n >> q >> s;\r\n\
    \  std::vector<std::vector<int>> nx = nx_init(s);\r\n  std::vector<std::vector<std::vector<int>>>\
    \ dp(D + 1, std::vector<std::vector<int>>(D + 1, std::vector<int>(D + 1, n)));\r\
    \n  dp[0][0][0] = -1;\r\n  std::vector<int> len(3, 0);\r\n  std::vector<std::vector<char>>\
    \ str(3);\r\n  while (q--) {\r\n    char ope;\r\n    int i;\r\n    std::cin >>\
    \ ope >> i;\r\n    --i;\r\n    if (ope == '+') {\r\n      char c;\r\n      std::cin\
    \ >> c;\r\n      ++len[i];\r\n      str[i].emplace_back(c);\r\n      if (i ==\
    \ 0) {\r\n        for (int y = 0; y <= len[1]; ++y) for (int z = 0; z <= len[2];\
    \ ++z) {\r\n          int &now = dp[len[0]][y][z];\r\n          now = n;\r\n \
    \         if (len[0] > 0 && dp[len[0] - 1][y][z] + 1 < n && nx[dp[len[0] - 1][y][z]\
    \ + 1][str[0][len[0] - 1] - 'a'] < now) {\r\n            now = nx[dp[len[0] -\
    \ 1][y][z] + 1][str[0][len[0] - 1] - 'a'];\r\n          }\r\n          if (y >\
    \ 0 && dp[len[0]][y - 1][z] + 1 < n && nx[dp[len[0]][y - 1][z] + 1][str[1][y -\
    \ 1] - 'a'] < now) {\r\n            now = nx[dp[len[0]][y - 1][z] + 1][str[1][y\
    \ - 1] - 'a'];\r\n          }\r\n          if (z > 0 && dp[len[0]][y][z - 1] +\
    \ 1 < n && nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a'] < now) {\r\n    \
    \        now = nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a'];\r\n        \
    \  }\r\n        }\r\n      } else if (i == 1) {\r\n        for (int x = 0; x <=\
    \ len[0]; ++x) for (int z = 0; z <= len[2]; ++z) {\r\n          int &now = dp[x][len[1]][z];\r\
    \n          now = n;\r\n          if (x > 0 && dp[x - 1][len[1]][z] + 1 < n &&\
    \ nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a'] < now) {\r\n            now\
    \ = nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a'];\r\n          }\r\n    \
    \      if (len[1] > 0 && dp[x][len[1] - 1][z] + 1 < n && nx[dp[x][len[1] - 1][z]\
    \ + 1][str[1][len[1] - 1] - 'a'] < now) {\r\n            now = nx[dp[x][len[1]\
    \ - 1][z] + 1][str[1][len[1] - 1] - 'a'];\r\n          }\r\n          if (z >\
    \ 0 && dp[x][len[1]][z - 1] + 1 < n && nx[dp[x][len[1]][z - 1] + 1][str[2][z -\
    \ 1] - 'a'] < now) {\r\n            now = nx[dp[x][len[1]][z - 1] + 1][str[2][z\
    \ - 1] - 'a'];\r\n          }\r\n        }\r\n      } else if (i == 2) {\r\n \
    \       for (int x = 0; x <= len[0]; ++x) for (int y = 0; y <= len[1]; ++y) {\r\
    \n          int &now = dp[x][y][len[2]];\r\n          now = n;\r\n          if\
    \ (x > 0 && dp[x - 1][y][len[2]] + 1 < n && nx[dp[x - 1][y][len[2]] + 1][str[0][x\
    \ - 1] - 'a'] < now) {\r\n            now = nx[dp[x - 1][y][len[2]] + 1][str[0][x\
    \ - 1] - 'a'];\r\n          }\r\n          if (y > 0 && dp[x][y - 1][len[2]] +\
    \ 1 < n && nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a'] < now) {\r\n    \
    \        now = nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a'];\r\n        \
    \  }\r\n          if (len[2] > 0 && dp[x][y][len[2] - 1] + 1 < n && nx[dp[x][y][len[2]\
    \ - 1] + 1][str[2][len[2] - 1] - 'a'] < now) {\r\n            now = nx[dp[x][y][len[2]\
    \ - 1] + 1][str[2][len[2] - 1] - 'a'];\r\n          }\r\n        }\r\n      }\r\
    \n    } else if (ope == '-') {\r\n      --len[i];\r\n      str[i].pop_back();\r\
    \n    }\r\n    std::cout << (dp[len[0]][len[1]][len[2]] < n ? \"YES\\n\" : \"\
    NO\\n\");\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/subsequence_dp.hpp
  isVerificationFile: true
  path: test/string/subsequence_dp.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/subsequence_dp.test.cpp
layout: document
redirect_from:
- /verify/test/string/subsequence_dp.test.cpp
- /verify/test/string/subsequence_dp.test.cpp.html
title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
---
