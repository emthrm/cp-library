---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
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
    document_title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
    links:
    - https://atcoder.jp/contests/arc013/tasks/arc013_3
  bundledCode: "#line 1 \"test/game/nim.test.cpp\"\n/*\r\n * @brief \u30B2\u30FC\u30E0\
    /\u30CB\u30E0\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc013/tasks/arc013_3\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 3 \"game/nim.hpp\"\n\
    \r\ntemplate <typename T>\r\nbool nim(const std::vector<T> &a) {\r\n  long long\
    \ x = 0;\r\n  for (T e : a) x ^= e;\r\n  return x != 0;\r\n}\r\n#line 10 \"test/game/nim.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> tofu;\r\
    \n  while (n--) {\r\n    int x, y, z, m;\r\n    std::cin >> x >> y >> z >> m;\r\
    \n    int x_mn = x, x_mx = 0, y_mn = y, y_mx = 0, z_mn = z, z_mx = 0;\r\n    while\
    \ (m--) {\r\n      int xi, yi, zi;\r\n      std::cin >> xi >> yi >> zi;\r\n  \
    \    if (xi < x_mn) x_mn = xi;\r\n      if (xi > x_mx) x_mx = xi;\r\n      if\
    \ (yi < y_mn) y_mn = yi;\r\n      if (yi > y_mx) y_mx = yi;\r\n      if (zi <\
    \ z_mn) z_mn = zi;\r\n      if (zi > z_mx) z_mx = zi;\r\n    }\r\n    tofu.emplace_back(x_mn);\r\
    \n    tofu.emplace_back(x - 1 - x_mx);\r\n    tofu.emplace_back(y_mn);\r\n   \
    \ tofu.emplace_back(y - 1 - y_mx);\r\n    tofu.emplace_back(z_mn);\r\n    tofu.emplace_back(z\
    \ - 1 - z_mx);\r\n  }\r\n  std::cout << (nim(tofu) ? \"WIN\\n\" : \"LOSE\\n\"\
    );\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30B2\u30FC\u30E0/\u30CB\u30E0\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://atcoder.jp/contests/arc013/tasks/arc013_3\"\r\n\r\n\
    #include <iostream>\r\n#include <vector>\r\n#include \"../../game/nim.hpp\"\r\n\
    \r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> tofu;\r\
    \n  while (n--) {\r\n    int x, y, z, m;\r\n    std::cin >> x >> y >> z >> m;\r\
    \n    int x_mn = x, x_mx = 0, y_mn = y, y_mx = 0, z_mn = z, z_mx = 0;\r\n    while\
    \ (m--) {\r\n      int xi, yi, zi;\r\n      std::cin >> xi >> yi >> zi;\r\n  \
    \    if (xi < x_mn) x_mn = xi;\r\n      if (xi > x_mx) x_mx = xi;\r\n      if\
    \ (yi < y_mn) y_mn = yi;\r\n      if (yi > y_mx) y_mx = yi;\r\n      if (zi <\
    \ z_mn) z_mn = zi;\r\n      if (zi > z_mx) z_mx = zi;\r\n    }\r\n    tofu.emplace_back(x_mn);\r\
    \n    tofu.emplace_back(x - 1 - x_mx);\r\n    tofu.emplace_back(y_mn);\r\n   \
    \ tofu.emplace_back(y - 1 - y_mx);\r\n    tofu.emplace_back(z_mn);\r\n    tofu.emplace_back(z\
    \ - 1 - z_mx);\r\n  }\r\n  std::cout << (nim(tofu) ? \"WIN\\n\" : \"LOSE\\n\"\
    );\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - game/nim.hpp
  isVerificationFile: true
  path: test/game/nim.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/game/nim.test.cpp
layout: document
redirect_from:
- /verify/test/game/nim.test.cpp
- /verify/test/game/nim.test.cpp.html
title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
---
