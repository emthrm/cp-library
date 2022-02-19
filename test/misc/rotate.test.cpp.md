---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: misc/rotate.hpp
    title: "\u56DE\u8EE2 (rotation)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
    document_title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
  bundledCode: "#line 1 \"test/misc/rotate.test.cpp\"\n/*\r\n * @brief \u305D\u306E\
    \u4ED6/\u56DE\u8EE2\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <set>\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"misc/rotate.hpp\"\n#include <cassert>\r\n#line 4 \"\
    misc/rotate.hpp\"\n\r\ntemplate <typename T>\r\nstd::vector<std::vector<T>> rotate(const\
    \ std::vector<std::vector<T>> &grid,\r\n                                   const\
    \ int angle, const T space = ' ') {\r\n  const int h = grid.size(), w = grid.front().size();\r\
    \n  std::vector<std::vector<T>> rotated_grid;\r\n  if (angle == 45) {\r\n    rotated_grid.assign(h\
    \ + w - 1, std::vector<T>(h + w - 1, space));\r\n    for (int i = 0; i < h; ++i)\
    \ {\r\n      for (int j = 0; j < w; ++j) {\r\n        rotated_grid[i + j][i -\
    \ j + w - 1] = grid[i][j];\r\n      }\r\n    }\r\n  } else if (angle == 90) {\r\
    \n    rotated_grid.assign(w, std::vector<T>(h));\r\n    for (int i = 0; i < h;\
    \ ++i) {\r\n      for (int j = 0; j < w; ++j) {\r\n        rotated_grid[w - 1\
    \ - j][i] = grid[i][j];\r\n      }\r\n    }\r\n  } else {\r\n    assert(false);\r\
    \n  }\r\n  return rotated_grid;\r\n}\r\n#line 12 \"test/misc/rotate.test.cpp\"\
    \n\r\nint main() {\r\n  int h, w;\r\n  std::cin >> h >> w;\r\n  std::vector<std::vector<char>>\
    \ c(h, std::vector<char>(w));\r\n  for (int i = 0; i < h; ++i) {\r\n    for (int\
    \ j = 0; j < w; ++j) {\r\n      std::cin >> c[i][j];\r\n    }\r\n  }\r\n  c =\
    \ rotate(c, 45);\r\n  h = c.size();\r\n  w = c.front().size();\r\n  int y_min\
    \ = h, y_max = -1, x_min = w, x_max = -1;\r\n  for (int i = 0; i < h; ++i) {\r\
    \n    for (int j = 0; j < w; ++j) {\r\n      if (c[i][j] == 'B') {\r\n       \
    \ y_min = std::min(y_min, i);\r\n        y_max = std::max(y_max, i);\r\n     \
    \   x_min = std::min(x_min, j);\r\n        x_max = std::max(x_max, j);\r\n   \
    \   }\r\n    }\r\n  }\r\n  std::cout << std::max(y_max - y_min, x_max - x_min)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u56DE\u8EE2\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n\
    \r\n#include \"../../misc/rotate.hpp\"\r\n\r\nint main() {\r\n  int h, w;\r\n\
    \  std::cin >> h >> w;\r\n  std::vector<std::vector<char>> c(h, std::vector<char>(w));\r\
    \n  for (int i = 0; i < h; ++i) {\r\n    for (int j = 0; j < w; ++j) {\r\n   \
    \   std::cin >> c[i][j];\r\n    }\r\n  }\r\n  c = rotate(c, 45);\r\n  h = c.size();\r\
    \n  w = c.front().size();\r\n  int y_min = h, y_max = -1, x_min = w, x_max = -1;\r\
    \n  for (int i = 0; i < h; ++i) {\r\n    for (int j = 0; j < w; ++j) {\r\n   \
    \   if (c[i][j] == 'B') {\r\n        y_min = std::min(y_min, i);\r\n        y_max\
    \ = std::max(y_max, i);\r\n        x_min = std::min(x_min, j);\r\n        x_max\
    \ = std::max(x_max, j);\r\n      }\r\n    }\r\n  }\r\n  std::cout << std::max(y_max\
    \ - y_min, x_max - x_min) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - misc/rotate.hpp
  isVerificationFile: true
  path: test/misc/rotate.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/rotate.test.cpp
layout: document
redirect_from:
- /verify/test/misc/rotate.test.cpp
- /verify/test/misc/rotate.test.cpp.html
title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
---
