---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/slide_min.hpp
    title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\
      \u5C0F\u5024"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/dynamic_programming/slide_min.test.cpp\"\n/*\n * @title\
    \ \u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n\
    \ *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/dynamic_programming/slide_min.hpp\"\
    \n\n\n\n#include <deque>\n#line 6 \"include/emthrm/dynamic_programming/slide_min.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool IS_MINIMIZED = true, typename T>\nstd::vector<T>\
    \ slide_min(const std::vector<T>& a, const int len) {\n  const int n = a.size();\n\
    \  std::vector<T> res(n - len + 1);\n  std::deque<T> deq;\n  for (int i = 0; i\
    \ < n; ++i) {\n    while (!deq.empty() &&\n           !(IS_MINIMIZED ? a[deq.back()]\
    \ < a[i] : a[deq.back()] > a[i])) {\n      deq.pop_back();\n    }\n    deq.emplace_back(i);\n\
    \    if (i + 1 >= len) {\n      const int left = i + 1 - len;\n      res[left]\
    \ = a[deq.front()];\n      if (deq.front() == left) deq.pop_front();\n    }\n\
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"test/dynamic_programming/slide_min.test.cpp\"\
    \n\nint main() {\n  int n, l;\n  std::cin >> n >> l;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const std::vector<int>\
    \ ans = emthrm::slide_min(a, l);\n  for (int i = 0; i + l <= n; ++i) {\n    std::cout\
    \ << ans[i] << \" \\n\"[i + l == n];\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\
    \u5C0F\u5024\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/slide_min.hpp\"\
    \n\nint main() {\n  int n, l;\n  std::cin >> n >> l;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const std::vector<int>\
    \ ans = emthrm::slide_min(a, l);\n  for (int i = 0; i + l <= n; ++i) {\n    std::cout\
    \ << ans[i] << \" \\n\"[i + l == n];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/slide_min.hpp
  isVerificationFile: true
  path: test/dynamic_programming/slide_min.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/slide_min.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/slide_min.test.cpp
- /verify/test/dynamic_programming/slide_min.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---
