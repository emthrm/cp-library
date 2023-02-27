---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/largest_rectangle.hpp
    title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\
      \u5F62 (largest rectangle in a histogram)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\
      \u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/dynamic_programming/largest_rectangle.test.cpp\"\n\
    /*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\
    \u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\n */\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/dynamic_programming/largest_rectangle.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <stack>\n#line 7 \"include/emthrm/dynamic_programming/largest_rectangle.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nlong long largest_rectangle(const\
    \ std::vector<T>& height) {\n  const int n = height.size();\n  std::vector<int>\
    \ left(n);\n  std::stack<T> st;\n  long long res = 0;\n  for (int i = 0; i < n;\
    \ ++i) {\n    while (!st.empty() && height[st.top()] >= height[i]) {\n      res\
    \ = std::max(\n          res, static_cast<long long>(height[st.top()]) * (i -\
    \ left[st.top()]));\n      st.pop();\n    }\n    left[i] = (st.empty() ? 0 : st.top()\
    \ + 1);\n    st.emplace(i);\n  }\n  while (!st.empty()) {\n    res = std::max(\n\
    \        res, static_cast<long long>(height[st.top()]) * (n - left[st.top()]));\n\
    \    st.pop();\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 11\
    \ \"test/dynamic_programming/largest_rectangle.test.cpp\"\n\nint main() {\n  int\
    \ n;\n  std::cin >> n;\n  std::vector<int> h(n);\n  for (int i = 0; i < n; ++i)\
    \ {\n    std::cin >> h[i];\n  }\n  std::cout << emthrm::largest_rectangle(h) <<\
    \ '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\
    \u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/largest_rectangle.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> h(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> h[i];\n  }\n  std::cout << emthrm::largest_rectangle(h)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/largest_rectangle.hpp
  isVerificationFile: true
  path: test/dynamic_programming/largest_rectangle.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
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
