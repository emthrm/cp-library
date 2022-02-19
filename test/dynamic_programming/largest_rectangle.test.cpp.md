---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/largest_rectangle.hpp
    title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\
      \u5F62 (largest rectangle in a histogram)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\
      \u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/dynamic_programming/largest_rectangle.test.cpp\"\n\
    /*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\
    \u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"dynamic_programming/largest_rectangle.hpp\"\
    \n#include <algorithm>\r\n#include <stack>\r\n#line 5 \"dynamic_programming/largest_rectangle.hpp\"\
    \n\r\ntemplate <typename T>\r\nlong long largest_rectangle(const std::vector<T>&\
    \ height) {\r\n  const int n = height.size();\r\n  std::vector<int> left(n);\r\
    \n  std::stack<T> st;\r\n  long long res = 0;\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    while (!st.empty() && height[st.top()] >= height[i]) {\r\n      res\
    \ = std::max(\r\n          res, static_cast<long long>(height[st.top()]) * (i\
    \ - left[st.top()]));\r\n      st.pop();\r\n    }\r\n    left[i] = (st.empty()\
    \ ? 0 : st.top() + 1);\r\n    st.emplace(i);\r\n  }\r\n  while (!st.empty()) {\r\
    \n    res = std::max(\r\n        res, static_cast<long long>(height[st.top()])\
    \ * (n - left[st.top()]));\r\n    st.pop();\r\n  }\r\n  return res;\r\n}\r\n#line\
    \ 10 \"test/dynamic_programming/largest_rectangle.test.cpp\"\n\r\nint main() {\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> h(n);\r\n  for (int i = 0;\
    \ i < n; ++i) {\r\n    std::cin >> h[i];\r\n  }\r\n  std::cout << largest_rectangle(h)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\
    \u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62\r\n */\r\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\n#include \"../../dynamic_programming/largest_rectangle.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> h(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> h[i];\r\n  }\r\n  std::cout\
    \ << largest_rectangle(h) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/largest_rectangle.hpp
  isVerificationFile: true
  path: test/dynamic_programming/largest_rectangle.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/largest_rectangle.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/largest_rectangle.test.cpp
- /verify/test/dynamic_programming/largest_rectangle.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\
  \u6700\u5927\u9577\u65B9\u5F62"
---
