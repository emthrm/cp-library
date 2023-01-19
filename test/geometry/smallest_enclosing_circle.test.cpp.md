---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/geometry/smallest_enclosing_circle.hpp
    title: "\u6700\u5C0F\u5305\u542B\u5186 (smallest enclosing circle)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://atcoder.jp/contests/abc151/tasks/abc151_f
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186"
    links:
    - https://atcoder.jp/contests/abc151/tasks/abc151_f
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186\
    \n */\n#define PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_f\"\n\
    #define ERROR \"1e-6\"\n\n#include <iomanip>\n#include <iostream>\n#include <vector>\n\
    \n#include \"emthrm/geometry/geometry.hpp\"\n#include \"emthrm/geometry/smallest_enclosing_circle.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<emthrm::geometry::Point>\
    \ p(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> p[i];\n  }\n  std::cout\
    \ << std::fixed << std::setprecision(6)\n            << emthrm::geometry::smallest_enclosing_circle(p).r\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  - include/emthrm/geometry/smallest_enclosing_circle.hpp
  isVerificationFile: true
  path: test/geometry/smallest_enclosing_circle.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 02:23:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/smallest_enclosing_circle.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/smallest_enclosing_circle.test.cpp
- /verify/test/geometry/smallest_enclosing_circle.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186"
---
