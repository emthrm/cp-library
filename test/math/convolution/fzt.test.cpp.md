---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fzt.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
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
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
      \u30BF\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/arc100/tasks/arc100_c
  bundledCode: "#line 1 \"test/math/convolution/fzt.test.cpp\"\n/*\r\n * @brief \u6570\
    \u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\r\n\
    \ */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\
    \r\n\r\n#include <algorithm>\r\n#include <functional>\r\n#include <iostream>\r\
    \n#include <utility>\r\n#include <vector>\r\n#line 3 \"math/convolution/fzt.hpp\"\
    \n\r\ntemplate <typename Ring, typename Fn>\r\nstd::vector<Ring> fzt(std::vector<Ring>\
    \ a,\r\n                      bool is_superset,\r\n                      const\
    \ Ring UNITY = 0,\r\n                      Fn fn = [](const Ring &a, const Ring\
    \ &b) -> Ring { return a + b; }) {\r\n  int n = a.size(), p = 1;\r\n  while ((1\
    \ << p) < n) ++p;\r\n  n = 1 << p;\r\n  a.resize(n, UNITY);\r\n  if (is_superset)\
    \ {\r\n    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {\r\n \
    \     if ((j & i) == 0) a[j] = fn(a[j], a[j | i]);\r\n    }\r\n  } else {\r\n\
    \    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {\r\n      if\
    \ ((j & i) == 0) a[j | i] = fn(a[j | i], a[j]);\r\n    }\r\n  }\r\n  return a;\r\
    \n}\r\n#line 13 \"test/math/convolution/fzt.test.cpp\"\n\r\nint main() {\r\n \
    \ int n;\r\n  std::cin >> n;\r\n  std::vector<std::pair<int, int>> a(1 << n, {0,\
    \ 0});\r\n  for (int i = 0; i < (1 << n); ++i) std::cin >> a[i].first;\r\n  std::vector<std::pair<int,\
    \ int>> f = fzt(a, false, {0, 0}, [](std::pair<int, int> a, std::pair<int, int>\
    \ b) -> std::pair<int, int> {\r\n    std::vector<int> tmp{a.first, a.second, b.first,\
    \ b.second};\r\n    std::sort(tmp.begin(), tmp.end(), std::greater<int>());\r\n\
    \    return {tmp[0], tmp[1]};\r\n  });\r\n  std::vector<int> ans(1 << n);\r\n\
    \  for (int i = 0; i < (1 << n); ++i) ans[i] = f[i].first + f[i].second;\r\n \
    \ for (int i = 1; i < (1 << n); ++i) {\r\n    if (ans[i - 1] > ans[i]) ans[i]\
    \ = ans[i - 1];\r\n    std::cout << ans[i] << '\\n';\r\n  }\r\n  return 0;\r\n\
    }\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
    \u30BF\u5909\u63DB\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\
    \r\n\r\n#include <algorithm>\r\n#include <functional>\r\n#include <iostream>\r\
    \n#include <utility>\r\n#include <vector>\r\n#include \"../../../math/convolution/fzt.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::pair<int,\
    \ int>> a(1 << n, {0, 0});\r\n  for (int i = 0; i < (1 << n); ++i) std::cin >>\
    \ a[i].first;\r\n  std::vector<std::pair<int, int>> f = fzt(a, false, {0, 0},\
    \ [](std::pair<int, int> a, std::pair<int, int> b) -> std::pair<int, int> {\r\n\
    \    std::vector<int> tmp{a.first, a.second, b.first, b.second};\r\n    std::sort(tmp.begin(),\
    \ tmp.end(), std::greater<int>());\r\n    return {tmp[0], tmp[1]};\r\n  });\r\n\
    \  std::vector<int> ans(1 << n);\r\n  for (int i = 0; i < (1 << n); ++i) ans[i]\
    \ = f[i].first + f[i].second;\r\n  for (int i = 1; i < (1 << n); ++i) {\r\n  \
    \  if (ans[i - 1] > ans[i]) ans[i] = ans[i - 1];\r\n    std::cout << ans[i] <<\
    \ '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/fzt.hpp
  isVerificationFile: true
  path: test/math/convolution/fzt.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/fzt.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fzt.test.cpp
- /verify/test/math/convolution/fzt.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\
  \u63DB"
---
