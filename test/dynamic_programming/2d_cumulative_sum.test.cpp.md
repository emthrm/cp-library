---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc089/tasks/arc089_d
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links:
    - https://atcoder.jp/contests/arc089/tasks/arc089_b
    - https://atcoder.jp/contests/arc089/tasks/arc089_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/dynamic_programming/2d_cumulative_sum.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C\
    \n */\n#define PROBLEM \"https://atcoder.jp/contests/arc089/tasks/arc089_d\"\n\
    // #define PROBLEM \"https://atcoder.jp/contests/arc089/tasks/arc089_b\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n\n#include \"emthrm/dynamic_programming/2d_cumulative_sum.hpp\"\
    \n\nint main() {\n  int n, k;\n  std::cin >> n >> k;\n  emthrm::CumulativeSum2D<int>\
    \ black(k * 2, k * 2), white(k * 2, k * 2);\n  while (n--) {\n    int x, y;\n\
    \    char c;\n    std::cin >> x >> y >> c;\n    x %= k * 2;\n    y %= k * 2;\n\
    \    (c == 'B' ? black : white).add(y, x, 1);\n  }\n  black.build();\n  white.build();\n\
    \  int ans = 0;\n  for (int i = k - 1; i < k * 2; ++i) {\n    for (int j = k -\
    \ 1; j < k * 2; ++j) {\n      const int b = black.query(i - k + 1, j - k + 1,\
    \ i, j) +\n                    black.query(0, 0, i - k, j - k) +\n           \
    \         black.query(0, j + 1, i - k, k * 2 - 1) +\n                    black.query(i\
    \ + 1, 0, k * 2 - 1, j - k) +\n                    black.query(i + 1, j + 1, k\
    \ * 2 - 1, k * 2 - 1);\n      const int w = white.query(0, j - k + 1, i - k, j)\
    \ +\n                    white.query(i - k + 1, 0, i, j - k) +\n             \
    \       white.query(i - k + 1, j + 1, i, k * 2 - 1) +\n                    white.query(i\
    \ + 1, j - k + 1, k * 2 - 1, j);\n      ans = std::max(ans, b + w);\n    }\n \
    \ }\n  for (int i = k - 1; i < k * 2; ++i) {\n    for (int j = k - 1; j < k *\
    \ 2; ++j) {\n      const int b = black.query(0, j - k + 1, i - k, j) +\n     \
    \               black.query(i - k + 1, 0, i, j - k) +\n                    black.query(i\
    \ - k + 1, j + 1, i, k * 2 - 1) +\n                    black.query(i + 1, j -\
    \ k + 1, k * 2 - 1, j);\n      const int w = white.query(i - k + 1, j - k + 1,\
    \ i, j) +\n                    white.query(0, 0, i - k, j - k) +\n           \
    \         white.query(0, j + 1, i - k, k * 2 - 1) +\n                    white.query(i\
    \ + 1, 0, k * 2 - 1, j - k) +\n                    white.query(i + 1, j + 1, k\
    \ * 2 - 1, k * 2 - 1);\n      ans = std::max(ans, b + w);\n    }\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
  isVerificationFile: true
  path: test/dynamic_programming/2d_cumulative_sum.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 03:04:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/2d_cumulative_sum.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/2d_cumulative_sum.test.cpp
- /verify/test/dynamic_programming/2d_cumulative_sum.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
