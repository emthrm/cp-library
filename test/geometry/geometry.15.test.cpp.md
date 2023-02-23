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
    ERROR: '0.00001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (2\u5186\u306E\u5171\u901A\u63A5\u7DDA)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
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
    \ (2\u5186\u306E\u5171\u901A\u63A5\u7DDA)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G\"\
    \n#define ERROR \"0.00001\"\n\n#include <algorithm>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <ranges>\n#include <vector>\n\n#include \"emthrm/geometry/geometry.hpp\"\
    \n\nint main() {\n  emthrm::geometry::Point c1_o, c2_o;\n  double c1r, c2r;\n\
    \  std::cin >> c1_o >> c1r >> c2_o >> c2r;\n  // GCC 12 adopted P2415.\n  const\
    \ std::vector<emthrm::geometry::Line> tangents =\n      emthrm::geometry::common_tangent(emthrm::geometry::Circle(c1_o,\
    \ c1r),\n                                       emthrm::geometry::Circle(c2_o,\
    \ c2r));\n  const auto ev = tangents | std::views::transform(&emthrm::geometry::Line::s);\n\
    \  // const auto ev =\n  //     emthrm::geometry::common_tangent(emthrm::geometry::Circle(c1_o,\
    \ c1r),\n  //                                      emthrm::geometry::Circle(c2_o,\
    \ c2r))\n  //     | std::views::transform(&emthrm::geometry::Line::s);\n  std::vector<emthrm::geometry::Point>\
    \ ans(ev.begin(), ev.end());\n  std::sort(ans.begin(), ans.end());\n  for (const\
    \ emthrm::geometry::Point& p : ans) {\n    std::cout << std::fixed << std::setprecision(6)\n\
    \              << p.x << ' ' << p.y << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.15.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.15.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.15.test.cpp
- /verify/test/geometry/geometry.15.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u5186\u306E\
  \u5171\u901A\u63A5\u7DDA)"
---
