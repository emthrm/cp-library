---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rotate.hpp
    title: "\u56DE\u8EE2 (rotation)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
    document_title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
  bundledCode: "#line 1 \"test/misc/rotate.test.cpp\"\n/*\r\n * @brief \u305D\u306E\
    \u4ED6/\u56DE\u8EE2\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\"\
    \r\n\r\n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n#line 2\
    \ \"misc/rotate.hpp\"\n#include <cassert>\r\n#line 4 \"misc/rotate.hpp\"\n\r\n\
    template <typename T>\r\nstd::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>\
    \ &grid, int angle, T basis = ' ') {\r\n  int h = grid.size(), w = grid.front().size();\r\
    \n  std::vector<std::vector<T>> rotated_grid;\r\n  if (angle == 45) {\r\n    rotated_grid.assign(h\
    \ + w - 1, std::vector<T>(h + w - 1, basis));\r\n    for (int i = 0; i < h; ++i)\
    \ for (int j = 0; j < w; ++j) rotated_grid[i + j][i - j + w - 1] = grid[i][j];\r\
    \n  } else if (angle == 90) {\r\n    rotated_grid.assign(w, std::vector<T>(h));\r\
    \n    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) rotated_grid[w -\
    \ 1 - j][i] = grid[i][j];\r\n  } else {\r\n    assert(false);\r\n  }\r\n  return\
    \ rotated_grid;\r\n}\r\n#line 10 \"test/misc/rotate.test.cpp\"\n\r\nint main()\
    \ {\r\n  int h, w;\r\n  std::cin >> h >> w;\r\n  std::vector<std::vector<char>>\
    \ c(h, std::vector<char>(w));\r\n  for (int i = 0; i < h; ++i) for (int j = 0;\
    \ j < w; ++j) std::cin >> c[i][j];\r\n  c = rotate(c, 45);\r\n  h = c.size();\r\
    \n  w = c.front().size();\r\n  std::set<int> hor, ver;\r\n  for (int i = 0; i\
    \ < h; ++i) for (int j = 0; j < w; ++j) {\r\n    if (c[i][j] == 'B') {\r\n   \
    \   hor.emplace(i);\r\n      ver.emplace(j);\r\n    }\r\n  }\r\n  int ans = 0;\r\
    \n  if (hor.size() >= 2 && *hor.rbegin() - *hor.begin() > ans) ans = *hor.rbegin()\
    \ - *hor.begin();\r\n  if (ver.size() >= 2 && *ver.rbegin() - *ver.begin() > ans)\
    \ ans = *ver.rbegin() - *ver.begin();\r\n  std::cout << ans << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u56DE\u8EE2\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\"\r\n\r\n#include\
    \ <iostream>\r\n#include <set>\r\n#include <vector>\r\n#include \"../../misc/rotate.hpp\"\
    \r\n\r\nint main() {\r\n  int h, w;\r\n  std::cin >> h >> w;\r\n  std::vector<std::vector<char>>\
    \ c(h, std::vector<char>(w));\r\n  for (int i = 0; i < h; ++i) for (int j = 0;\
    \ j < w; ++j) std::cin >> c[i][j];\r\n  c = rotate(c, 45);\r\n  h = c.size();\r\
    \n  w = c.front().size();\r\n  std::set<int> hor, ver;\r\n  for (int i = 0; i\
    \ < h; ++i) for (int j = 0; j < w; ++j) {\r\n    if (c[i][j] == 'B') {\r\n   \
    \   hor.emplace(i);\r\n      ver.emplace(j);\r\n    }\r\n  }\r\n  int ans = 0;\r\
    \n  if (hor.size() >= 2 && *hor.rbegin() - *hor.begin() > ans) ans = *hor.rbegin()\
    \ - *hor.begin();\r\n  if (ver.size() >= 2 && *ver.rbegin() - *ver.begin() > ans)\
    \ ans = *ver.rbegin() - *ver.begin();\r\n  std::cout << ans << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - misc/rotate.hpp
  isVerificationFile: true
  path: test/misc/rotate.test.cpp
  requiredBy: []
  timestamp: '2021-06-21 17:19:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/rotate.test.cpp
layout: document
redirect_from:
- /verify/test/misc/rotate.test.cpp
- /verify/test/misc/rotate.test.cpp.html
title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
---
