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
  bundledCode: "#line 1 \"test/math/convolution/fast_zeta_transform.test.cpp\"\n/*\n\
    \ * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\
    \u5909\u63DB\n */\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_e\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\n\n\
    #include <algorithm>\n#include <functional>\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\n#line 4 \"math/convolution/fast_zeta_transform.hpp\"\n\n\
    template <typename Ring>\nstd::vector<Ring> fast_zeta_transform(\n    std::vector<Ring>\
    \ a, const bool adds_superset, const Ring ID = 0,\n    const std::function<Ring(const\
    \ Ring&, const Ring&)> fn =\n        [](const Ring& a, const Ring& b) -> Ring\
    \ { return a + b; }) {\n  int n = a.size(), p = 1;\n  while ((1 << p) < n) ++p;\n\
    \  n = 1 << p;\n  a.resize(n, ID);\n  if (adds_superset) {\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s & i) continue;\n\
    \        a[s] = fn(a[s], a[s | i]);\n      }\n    }\n  } else {\n    for (int\
    \ i = 1; i < n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s\
    \ & i) continue;\n        a[s | i] = fn(a[s | i], a[s]);\n      }\n    }\n  }\n\
    \  return a;\n}\n#line 14 \"test/math/convolution/fast_zeta_transform.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::pair<int, int>>\
    \ a(1 << n, {0, 0});\n  for (int i = 0; i < (1 << n); ++i) {\n    std::cin >>\
    \ a[i].first;\n  }\n  const std::function<std::pair<int, int>(const std::pair<int,\
    \ int>&,\n                                          const std::pair<int, int>&)>\
    \ max =\n      [](const std::pair<int, int>& a, const std::pair<int, int>& b)\n\
    \          -> std::pair<int, int> {\n        int tmp[]{a.first, a.second, b.first,\
    \ b.second};\n        std::sort(tmp, tmp + 4, std::greater<int>());\n        return\
    \ {tmp[0], tmp[1]};\n      };\n  a = fast_zeta_transform(a, false, {0, 0}, max);\n\
    \  std::vector<int> ans(1 << n);\n  for (int i = 0; i < (1 << n); ++i) {\n   \
    \ ans[i] = a[i].first + a[i].second;\n  }\n  for (int i = 1; i < (1 << n); ++i)\
    \ {\n    ans[i] = std::max(ans[i], ans[i - 1]);\n    std::cout << ans[i] << '\\\
    n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
    \u30BF\u5909\u63DB\n */\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_e\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\n\n\
    #include <algorithm>\n#include <functional>\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\n#include \"../../../math/convolution/fast_zeta_transform.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::pair<int, int>>\
    \ a(1 << n, {0, 0});\n  for (int i = 0; i < (1 << n); ++i) {\n    std::cin >>\
    \ a[i].first;\n  }\n  const std::function<std::pair<int, int>(const std::pair<int,\
    \ int>&,\n                                          const std::pair<int, int>&)>\
    \ max =\n      [](const std::pair<int, int>& a, const std::pair<int, int>& b)\n\
    \          -> std::pair<int, int> {\n        int tmp[]{a.first, a.second, b.first,\
    \ b.second};\n        std::sort(tmp, tmp + 4, std::greater<int>());\n        return\
    \ {tmp[0], tmp[1]};\n      };\n  a = fast_zeta_transform(a, false, {0, 0}, max);\n\
    \  std::vector<int> ans(1 << n);\n  for (int i = 0; i < (1 << n); ++i) {\n   \
    \ ans[i] = a[i].first + a[i].second;\n  }\n  for (int i = 1; i < (1 << n); ++i)\
    \ {\n    ans[i] = std::max(ans[i], ans[i - 1]);\n    std::cout << ans[i] << '\\\
    n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/convolution/fast_zeta_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_zeta_transform.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
