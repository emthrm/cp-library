---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/slide_min.hpp
    title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\
      \u5C0F\u5024"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/dp/slide_min.test.cpp\"\n/*\r\n * @brief \u52D5\u7684\
    \u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"dp/slide_min.hpp\"\
    \n#include <deque>\r\n#line 4 \"dp/slide_min.hpp\"\n\r\ntemplate <typename T>\r\
    \nstd::vector<T> slide_min(const std::vector<T> &a, int len, bool is_minimized\
    \ = true) {\r\n  int n = a.size();\r\n  std::vector<T> res(n - len + 1);\r\n \
    \ std::deque<T> deq;\r\n  for (int i = 0; i < n; ++i) {\r\n    while (!deq.empty()\
    \ && !(is_minimized ? a[deq.back()] < a[i] : a[deq.back()] > a[i])) deq.pop_back();\r\
    \n    deq.emplace_back(i);\r\n    if (i + 1 >= len) {\r\n      int left = i +\
    \ 1 - len;\r\n      res[left] = a[deq.front()];\r\n      if (deq.front() == left)\
    \ deq.pop_front();\r\n    }\r\n  }\r\n  return res;\r\n}\r\n#line 9 \"test/dp/slide_min.test.cpp\"\
    \n\r\nint main() {\r\n  int n, l;\r\n  std::cin >> n >> l;\r\n  std::vector<int>\
    \ a(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\n  std::vector<int>\
    \ ans = slide_min(a, l);\r\n  for (int i = 0; i + l <= n; ++i) std::cout << ans[i]\
    \ << \" \\n\"[i + l == n];\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\
    \u5C0F\u5024\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../dp/slide_min.hpp\"\
    \r\n\r\nint main() {\r\n  int n, l;\r\n  std::cin >> n >> l;\r\n  std::vector<int>\
    \ a(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\n  std::vector<int>\
    \ ans = slide_min(a, l);\r\n  for (int i = 0; i + l <= n; ++i) std::cout << ans[i]\
    \ << \" \\n\"[i + l == n];\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dp/slide_min.hpp
  isVerificationFile: true
  path: test/dp/slide_min.test.cpp
  requiredBy: []
  timestamp: '2021-02-11 02:20:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dp/slide_min.test.cpp
layout: document
redirect_from:
- /verify/test/dp/slide_min.test.cpp
- /verify/test/dp/slide_min.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---
