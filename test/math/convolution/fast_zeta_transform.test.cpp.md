---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/fast_zeta_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/arc100/tasks/arc100_e
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
      \u30BF\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/arc100/tasks/arc100_c
    - https://atcoder.jp/contests/arc100/tasks/arc100_e
  bundledCode: "#line 1 \"test/math/convolution/fast_zeta_transform.test.cpp\"\n/*\n\
    \ * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\
    \u5909\u63DB\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc100/tasks/arc100_e\n\
    \ * Link: \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <functional>\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\n\n\n#include <bit>\n#line 7 \"include/emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool ADDS_SUPERSET, typename Ring, typename\
    \ BinOp = std::plus<Ring>>\nstd::vector<Ring> fast_zeta_transform(\n    std::vector<Ring>\
    \ a, const Ring ID = 0, const BinOp bin_op = BinOp()) {\n  const int n = std::bit_ceil(a.size());\n\
    \  a.resize(n, ID);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int s = 0;\
    \ s < n; ++s) {\n      if (s & i) continue;\n      if constexpr (ADDS_SUPERSET)\
    \ {\n        a[s] = bin_op(a[s], a[s | i]);\n      } else {\n        a[s | i]\
    \ = bin_op(a[s | i], a[s]);\n      }\n    }\n  }\n  return a;\n}\n\n}  // namespace\
    \ emthrm\n\n\n#line 16 \"test/math/convolution/fast_zeta_transform.test.cpp\"\n\
    \nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::pair<int, int>>\
    \ a(1 << n, {0, 0});\n  for (int i = 0; i < (1 << n); ++i) {\n    std::cin >>\
    \ a[i].first;\n  }\n  a = emthrm::fast_zeta_transform<false>(\n          a, std::make_pair(0,\
    \ 0),\n          [](const std::pair<int, int>& a, const std::pair<int, int>& b)\n\
    \              -> std::pair<int, int> {\n            std::array<int, 4> tmp{a.first,\
    \ a.second, b.first, b.second};\n            std::sort(tmp.begin(), tmp.end(),\
    \ std::greater<int>());\n            return {tmp[0], tmp[1]};\n          });\n\
    \  std::vector<int> ans(1 << n);\n  for (int i = 0; i < (1 << n); ++i) {\n   \
    \ ans[i] = a[i].first + a[i].second;\n  }\n  for (int i = 1; i < (1 << n); ++i)\
    \ {\n    ans[i] = std::max(ans[i], ans[i - 1]);\n    std::cout << ans[i] << '\\\
    n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
    \u30BF\u5909\u63DB\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc100/tasks/arc100_e\n\
    \ * Link: \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <functional>\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\n#include \"emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::pair<int, int>>\
    \ a(1 << n, {0, 0});\n  for (int i = 0; i < (1 << n); ++i) {\n    std::cin >>\
    \ a[i].first;\n  }\n  a = emthrm::fast_zeta_transform<false>(\n          a, std::make_pair(0,\
    \ 0),\n          [](const std::pair<int, int>& a, const std::pair<int, int>& b)\n\
    \              -> std::pair<int, int> {\n            std::array<int, 4> tmp{a.first,\
    \ a.second, b.first, b.second};\n            std::sort(tmp.begin(), tmp.end(),\
    \ std::greater<int>());\n            return {tmp[0], tmp[1]};\n          });\n\
    \  std::vector<int> ans(1 << n);\n  for (int i = 0; i < (1 << n); ++i) {\n   \
    \ ans[i] = a[i].first + a[i].second;\n  }\n  for (int i = 1; i < (1 << n); ++i)\
    \ {\n    ans[i] = std::max(ans[i], ans[i - 1]);\n    std::cout << ans[i] << '\\\
    n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_zeta_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_zeta_transform.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
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
