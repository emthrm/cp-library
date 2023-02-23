---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/misc/rotate.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/misc/rotate.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/\u56DE\u8EE2\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <set>\n#include <vector>\n\
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
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/rotate.test.cpp
layout: document
redirect_from:
- /verify/test/misc/rotate.test.cpp
- /verify/test/misc/rotate.test.cpp.html
title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
---
