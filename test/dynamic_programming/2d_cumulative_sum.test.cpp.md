---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/arc089/tasks/arc089_b
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links:
    - https://atcoder.jp/contests/arc089/tasks/arc089_b
  bundledCode: "#line 1 \"test/dynamic_programming/2d_cumulative_sum.test.cpp\"\n\
    /*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C\n\
    \ *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc089/tasks/arc089_b\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n\n#line 1 \"include/emthrm/dynamic_programming/2d_cumulative_sum.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/dynamic_programming/2d_cumulative_sum.hpp\"\n\
    #include <cassert>\n#include <iterator>\n#include <numeric>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nstruct CumulativeSum2D {\n  explicit\
    \ CumulativeSum2D(const int h, const int w)\n      : CumulativeSum2D(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w, 0))) {}\n\n  template <typename U>\n  explicit CumulativeSum2D(const\
    \ std::vector<std::vector<U>>& a)\n      : is_built(false), h(a.size()), w(a.front().size()),\n\
    \        data(h + 1, std::vector<T>(w + 1, 0)) {\n    for (int i = 0; i < h; ++i)\
    \ {\n      std::copy(a[i].begin(), a[i].end(), std::next(data[i + 1].begin()));\n\
    \    }\n  }\n\n  void add(const int y, const int x, const T val) {\n    assert(!is_built);\n\
    \    data[y + 1][x + 1] += val;\n  }\n\n  void build() {\n    assert(!is_built);\n\
    \    is_built = true;\n    for (int i = 0; i < h; ++i) {\n      std::partial_sum(data[i\
    \ + 1].begin(), data[i + 1].end(),\n                       data[i + 1].begin());\n\
    \    }\n    for (int j = 1; j <= w; ++j) {\n      for (int i = 1; i < h; ++i)\
    \ {\n        data[i + 1][j] += data[i][j];\n      }\n    }\n  }\n\n  T query(const\
    \ int y1, const int x1, const int y2, const int x2) const {\n    assert(is_built);\n\
    \    return y1 > y2 || x1 > x2 ? 0 : data[y2 + 1][x2 + 1] - data[y2 + 1][x1]\n\
    \                                    - data[y1][x2 + 1] + data[y1][x1];\n  }\n\
    \n private:\n  bool is_built;\n  const int h, w;\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 12 \"test/dynamic_programming/2d_cumulative_sum.test.cpp\"\
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
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C\
    \n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc089/tasks/arc089_b\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n\n#include \"emthrm/dynamic_programming/2d_cumulative_sum.hpp\"\
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
  timestamp: '2023-07-21 12:14:05+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/dynamic_programming/2d_cumulative_sum.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/2d_cumulative_sum.test.cpp
- /verify/test/dynamic_programming/2d_cumulative_sum.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
