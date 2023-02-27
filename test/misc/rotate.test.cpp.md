---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/misc/rotate.hpp
    title: "\u56DE\u8EE2 (rotation)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
    document_title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
  bundledCode: "#line 1 \"test/misc/rotate.test.cpp\"\n/*\n * @title \u305D\u306E\u4ED6\
    /\u56DE\u8EE2\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <set>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/misc/rotate.hpp\"\n\n\n\n#include <cassert>\n#line\
    \ 6 \"include/emthrm/misc/rotate.hpp\"\n\nnamespace emthrm {\n\ntemplate <int\
    \ ANGLE, typename T>\nstd::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>&\
    \ grid,\n                                   const T space = ' ') {\n  static_assert(ANGLE\
    \ == 45 || ANGLE == 90);\n  const int h = grid.size(), w = grid.front().size();\n\
    \  std::vector<std::vector<T>> rotated_grid;\n  if constexpr (ANGLE == 45) {\n\
    \    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, space));\n    for\
    \ (int i = 0; i < h; ++i) {\n      for (int j = 0; j < w; ++j) {\n        rotated_grid[i\
    \ + j][i - j + w - 1] = grid[i][j];\n      }\n    }\n  } else {\n    rotated_grid.assign(w,\
    \ std::vector<T>(h));\n    for (int i = 0; i < h; ++i) {\n      for (int j = 0;\
    \ j < w; ++j) {\n        rotated_grid[w - 1 - j][i] = grid[i][j];\n      }\n \
    \   }\n  }\n  return rotated_grid;\n}\n\n}  // namespace emthrm\n\n\n#line 13\
    \ \"test/misc/rotate.test.cpp\"\n\nint main() {\n  int h, w;\n  std::cin >> h\
    \ >> w;\n  std::vector<std::vector<char>> c(h, std::vector<char>(w));\n  for (int\
    \ i = 0; i < h; ++i) {\n    for (int j = 0; j < w; ++j) {\n      std::cin >> c[i][j];\n\
    \    }\n  }\n  c = emthrm::rotate<45>(c);\n  h = c.size();\n  w = c.front().size();\n\
    \  int y_min = h, y_max = -1, x_min = w, x_max = -1;\n  for (int i = 0; i < h;\
    \ ++i) {\n    for (int j = 0; j < w; ++j) {\n      if (c[i][j] == 'B') {\n   \
    \     y_min = std::min(y_min, i);\n        y_max = std::max(y_max, i);\n     \
    \   x_min = std::min(x_min, j);\n        x_max = std::max(x_max, j);\n      }\n\
    \    }\n  }\n  std::cout << std::max(y_max - y_min, x_max - x_min) << '\\n';\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u305D\u306E\u4ED6/\u56DE\u8EE2\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <set>\n#include <vector>\n\
    \n#include \"emthrm/misc/rotate.hpp\"\n\nint main() {\n  int h, w;\n  std::cin\
    \ >> h >> w;\n  std::vector<std::vector<char>> c(h, std::vector<char>(w));\n \
    \ for (int i = 0; i < h; ++i) {\n    for (int j = 0; j < w; ++j) {\n      std::cin\
    \ >> c[i][j];\n    }\n  }\n  c = emthrm::rotate<45>(c);\n  h = c.size();\n  w\
    \ = c.front().size();\n  int y_min = h, y_max = -1, x_min = w, x_max = -1;\n \
    \ for (int i = 0; i < h; ++i) {\n    for (int j = 0; j < w; ++j) {\n      if (c[i][j]\
    \ == 'B') {\n        y_min = std::min(y_min, i);\n        y_max = std::max(y_max,\
    \ i);\n        x_min = std::min(x_min, j);\n        x_max = std::max(x_max, j);\n\
    \      }\n    }\n  }\n  std::cout << std::max(y_max - y_min, x_max - x_min) <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/misc/rotate.hpp
  isVerificationFile: true
  path: test/misc/rotate.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/rotate.test.cpp
layout: document
redirect_from:
- /verify/test/misc/rotate.test.cpp
- /verify/test/misc/rotate.test.cpp.html
title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
---
