---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/fast_zeta_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc100/tasks/arc100_e
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
      \u30BF\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/arc100/tasks/arc100_c
    - https://atcoder.jp/contests/arc100/tasks/arc100_e
  bundledCode: "#line 1 \"test/math/convolution/fast_zeta_transform.test.cpp\"\n/*\r\
    \n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\
    \u5909\u63DB\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_e\"\
    \r\n// #define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\r\
    \n\r\n#include <algorithm>\r\n#include <functional>\r\n#include <iostream>\r\n\
    #include <utility>\r\n#include <vector>\r\n\r\n#line 4 \"math/convolution/fast_zeta_transform.hpp\"\
    \n\r\ntemplate <typename Ring>\r\nstd::vector<Ring> fast_zeta_transform(\r\n \
    \   std::vector<Ring> a, const bool adds_superset, const Ring ID = 0,\r\n    const\
    \ std::function<Ring(const Ring&, const Ring&)> fn =\r\n        [](const Ring&\
    \ a, const Ring& b) -> Ring { return a + b; }) {\r\n  int n = a.size(), p = 1;\r\
    \n  while ((1 << p) < n) ++p;\r\n  n = 1 << p;\r\n  a.resize(n, ID);\r\n  if (adds_superset)\
    \ {\r\n    for (int i = 1; i < n; i <<= 1) {\r\n      for (int s = 0; s < n; ++s)\
    \ {\r\n        if (s & i) continue;\r\n        a[s] = fn(a[s], a[s | i]);\r\n\
    \      }\r\n    }\r\n  } else {\r\n    for (int i = 1; i < n; i <<= 1) {\r\n \
    \     for (int s = 0; s < n; ++s) {\r\n        if (s & i) continue;\r\n      \
    \  a[s | i] = fn(a[s | i], a[s]);\r\n      }\r\n    }\r\n  }\r\n  return a;\r\n\
    }\r\n#line 14 \"test/math/convolution/fast_zeta_transform.test.cpp\"\n\r\nint\
    \ main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::pair<int, int>>\
    \ a(1 << n, {0, 0});\r\n  for (int i = 0; i < (1 << n); ++i) {\r\n    std::cin\
    \ >> a[i].first;\r\n  }\r\n  const std::function<std::pair<int, int>(const std::pair<int,\
    \ int>&,\r\n                                          const std::pair<int, int>&)>\
    \ max =\r\n      [](const std::pair<int, int>& a, const std::pair<int, int>& b)\r\
    \n          -> std::pair<int, int> {\r\n        int tmp[]{a.first, a.second, b.first,\
    \ b.second};\r\n        std::sort(tmp, tmp + 4, std::greater<int>());\r\n    \
    \    return {tmp[0], tmp[1]};\r\n      };\r\n  a = fast_zeta_transform(a, false,\
    \ {0, 0}, max);\r\n  std::vector<int> ans(1 << n);\r\n  for (int i = 0; i < (1\
    \ << n); ++i) {\r\n    ans[i] = a[i].first + a[i].second;\r\n  }\r\n  for (int\
    \ i = 1; i < (1 << n); ++i) {\r\n    ans[i] = std::max(ans[i], ans[i - 1]);\r\n\
    \    std::cout << ans[i] << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
    \u30BF\u5909\u63DB\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_e\"\
    \r\n// #define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\r\
    \n\r\n#include <algorithm>\r\n#include <functional>\r\n#include <iostream>\r\n\
    #include <utility>\r\n#include <vector>\r\n\r\n#include \"../../../math/convolution/fast_zeta_transform.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::pair<int,\
    \ int>> a(1 << n, {0, 0});\r\n  for (int i = 0; i < (1 << n); ++i) {\r\n    std::cin\
    \ >> a[i].first;\r\n  }\r\n  const std::function<std::pair<int, int>(const std::pair<int,\
    \ int>&,\r\n                                          const std::pair<int, int>&)>\
    \ max =\r\n      [](const std::pair<int, int>& a, const std::pair<int, int>& b)\r\
    \n          -> std::pair<int, int> {\r\n        int tmp[]{a.first, a.second, b.first,\
    \ b.second};\r\n        std::sort(tmp, tmp + 4, std::greater<int>());\r\n    \
    \    return {tmp[0], tmp[1]};\r\n      };\r\n  a = fast_zeta_transform(a, false,\
    \ {0, 0}, max);\r\n  std::vector<int> ans(1 << n);\r\n  for (int i = 0; i < (1\
    \ << n); ++i) {\r\n    ans[i] = a[i].first + a[i].second;\r\n  }\r\n  for (int\
    \ i = 1; i < (1 << n); ++i) {\r\n    ans[i] = std::max(ans[i], ans[i - 1]);\r\n\
    \    std::cout << ans[i] << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/fast_zeta_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_zeta_transform.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 22:30:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/fast_zeta_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fast_zeta_transform.test.cpp
- /verify/test/math/convolution/fast_zeta_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\
  \u63DB"
---
