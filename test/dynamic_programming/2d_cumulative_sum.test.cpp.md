---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dynamic_programming/2d_cumulative_sum.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc089/tasks/arc089_b
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links:
    - https://atcoder.jp/contests/arc089/tasks/arc089_b
  bundledCode: "#line 1 \"test/dynamic_programming/2d_cumulative_sum.test.cpp\"\n\
    /*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C\
    \r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc089/tasks/arc089_b\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"dynamic_programming/2d_cumulative_sum.hpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstruct CumulativeSum2D\
    \ {\n  CumulativeSum2D(const int h, const int w)\n  : CumulativeSum2D(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w, 0))) {}\n\n  template <typename U>\n  CumulativeSum2D(const\
    \ std::vector<std::vector<U>> &a) : h(a.size()), w(a.front().size()) {\n    dat.assign(h\
    \ + 1, std::vector<T>(w + 1, 0));\n    for (int i = 0; i < h; ++i) {\n      for\
    \ (int j = 0; j < w; ++j) {\n        dat[i + 1][j + 1] = a[i][j];\n      }\n \
    \   }\n  }\n\n  void add(const int y, const int x, const T val) {\n    assert(!is_built);\n\
    \    dat[y + 1][x + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n\
    \    is_built = true;\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        dat[i + 1][j + 1] += dat[i + 1][j];\n      }\n    }\n\
    \    for (int j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i) {\n   \
    \     dat[i + 1][j] += dat[i][j];\n      }\n    }\n  }\n\n  T query(const int\
    \ y1, const int x1, const int y2, const int x2) const {\n    assert(is_built);\n\
    \    return y1 <= y2 && x1 <= x2 ? dat[y2 + 1][x2 + 1] - dat[y2 + 1][x1] - dat[y1][x2\
    \ + 1] + dat[y1][x1] : 0;\n  }\n\nprivate:\n  bool is_built = false;\n  const\
    \ int h, w;\n  std::vector<std::vector<T>> dat;\n};\n#line 8 \"test/dynamic_programming/2d_cumulative_sum.test.cpp\"\
    \n\r\nint main() {\r\n  int n, k;\r\n  std::cin >> n >> k;\r\n  CumulativeSum2D<int>\
    \ black(k * 2, k * 2), white(k * 2, k * 2);\r\n  while (n--) {\r\n    int x, y;\r\
    \n    char c;\r\n    std::cin >> x >> y >> c;\r\n    x %= k * 2;\r\n    y %= k\
    \ * 2;\r\n    (c == 'B' ? black : white).add(y, x, 1);\r\n  }\r\n  black.build();\r\
    \n  white.build();\r\n  int ans = 0;\r\n  for (int i = k - 1; i < k * 2; ++i)\
    \ {\r\n    for (int j = k - 1; j < k * 2; ++j) {\r\n      const int b = black.query(i\
    \ - k + 1, j - k + 1, i, j)\r\n                    + black.query(0, 0, i - k,\
    \ j - k)\r\n                    + black.query(0, j + 1, i - k, k * 2 - 1)\r\n\
    \                    + black.query(i + 1, 0, k * 2 - 1, j - k)\r\n           \
    \         + black.query(i + 1, j + 1, k * 2 - 1, k * 2 - 1);\r\n      const int\
    \ w = white.query(0, j - k + 1, i - k, j)\r\n                    + white.query(i\
    \ - k + 1, 0, i, j - k)\r\n                    + white.query(i - k + 1, j + 1,\
    \ i, k * 2 - 1)\r\n                    + white.query(i + 1, j - k + 1, k * 2 -\
    \ 1, j);\r\n      if (b + w > ans) {\r\n        ans = b + w;\r\n      }\r\n  \
    \  }\r\n  }\r\n  for (int i = k - 1; i < k * 2; ++i) {\r\n    for (int j = k -\
    \ 1; j < k * 2; ++j) {\r\n      const int b = black.query(0, j - k + 1, i - k,\
    \ j)\r\n                    + black.query(i - k + 1, 0, i, j - k)\r\n        \
    \            + black.query(i - k + 1, j + 1, i, k * 2 - 1)\r\n               \
    \     + black.query(i + 1, j - k + 1, k * 2 - 1, j);\r\n      const int w = white.query(i\
    \ - k + 1, j - k + 1, i, j)\r\n                    + white.query(0, 0, i - k,\
    \ j - k)\r\n                    + white.query(0, j + 1, i - k, k * 2 - 1)\r\n\
    \                    + white.query(i + 1, 0, k * 2 - 1, j - k)\r\n           \
    \         + white.query(i + 1, j + 1, k * 2 - 1, k * 2 - 1);\r\n      if (b +\
    \ w > ans) {\r\n        ans = b + w;\r\n      }\r\n    }\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C\
    \r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc089/tasks/arc089_b\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../dynamic_programming/2d_cumulative_sum.hpp\"\
    \r\n\r\nint main() {\r\n  int n, k;\r\n  std::cin >> n >> k;\r\n  CumulativeSum2D<int>\
    \ black(k * 2, k * 2), white(k * 2, k * 2);\r\n  while (n--) {\r\n    int x, y;\r\
    \n    char c;\r\n    std::cin >> x >> y >> c;\r\n    x %= k * 2;\r\n    y %= k\
    \ * 2;\r\n    (c == 'B' ? black : white).add(y, x, 1);\r\n  }\r\n  black.build();\r\
    \n  white.build();\r\n  int ans = 0;\r\n  for (int i = k - 1; i < k * 2; ++i)\
    \ {\r\n    for (int j = k - 1; j < k * 2; ++j) {\r\n      const int b = black.query(i\
    \ - k + 1, j - k + 1, i, j)\r\n                    + black.query(0, 0, i - k,\
    \ j - k)\r\n                    + black.query(0, j + 1, i - k, k * 2 - 1)\r\n\
    \                    + black.query(i + 1, 0, k * 2 - 1, j - k)\r\n           \
    \         + black.query(i + 1, j + 1, k * 2 - 1, k * 2 - 1);\r\n      const int\
    \ w = white.query(0, j - k + 1, i - k, j)\r\n                    + white.query(i\
    \ - k + 1, 0, i, j - k)\r\n                    + white.query(i - k + 1, j + 1,\
    \ i, k * 2 - 1)\r\n                    + white.query(i + 1, j - k + 1, k * 2 -\
    \ 1, j);\r\n      if (b + w > ans) {\r\n        ans = b + w;\r\n      }\r\n  \
    \  }\r\n  }\r\n  for (int i = k - 1; i < k * 2; ++i) {\r\n    for (int j = k -\
    \ 1; j < k * 2; ++j) {\r\n      const int b = black.query(0, j - k + 1, i - k,\
    \ j)\r\n                    + black.query(i - k + 1, 0, i, j - k)\r\n        \
    \            + black.query(i - k + 1, j + 1, i, k * 2 - 1)\r\n               \
    \     + black.query(i + 1, j - k + 1, k * 2 - 1, j);\r\n      const int w = white.query(i\
    \ - k + 1, j - k + 1, i, j)\r\n                    + white.query(0, 0, i - k,\
    \ j - k)\r\n                    + white.query(0, j + 1, i - k, k * 2 - 1)\r\n\
    \                    + white.query(i + 1, 0, k * 2 - 1, j - k)\r\n           \
    \         + white.query(i + 1, j + 1, k * 2 - 1, k * 2 - 1);\r\n      if (b +\
    \ w > ans) {\r\n        ans = b + w;\r\n      }\r\n    }\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/2d_cumulative_sum.hpp
  isVerificationFile: true
  path: test/dynamic_programming/2d_cumulative_sum.test.cpp
  requiredBy: []
  timestamp: '2021-09-20 16:05:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dynamic_programming/2d_cumulative_sum.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/2d_cumulative_sum.test.cpp
- /verify/test/dynamic_programming/2d_cumulative_sum.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
