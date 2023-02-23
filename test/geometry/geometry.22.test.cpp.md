---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
    \ (\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\
    \n#define ERROR \"0.000001\"\n\n#include <iomanip>\n#include <iostream>\n#include\
    \ <tuple>\n\n#include \"emthrm/geometry/geometry.hpp\"\n\nint main() {\n  int\
    \ n;\n  std::cin >> n;\n  emthrm::geometry::Polygon g(n);\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cin >> g[i];\n  }\n  const std::tuple<emthrm::geometry::Point,\
    \ emthrm::geometry::Point> ans =\n      rotating_calipers(g);\n  std::cout <<\
    \ std::fixed << std::setprecision(7)\n            << emthrm::geometry::distance(std::get<0>(ans),\
    \ std::get<1>(ans))\n            << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.22.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.22.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.22.test.cpp
- /verify/test/geometry/geometry.22.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u51F8\u591A\
  \u89D2\u5F62\u306E\u76F4\u5F84)"
---
