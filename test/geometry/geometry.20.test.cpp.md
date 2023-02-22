---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u51F8\u5305)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
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
    \ (\u51F8\u5305)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#include <algorithm>\n#include <cmath>\n#include <iostream>\n#include <iterator>\n\
    #include <utility>\n#include <vector>\n\n#include \"emthrm/geometry/geometry.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<emthrm::geometry::Point>\
    \ p(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> p[i];\n  }\n  emthrm::geometry::Polygon\
    \ convex_hull = monotone_chain(p, false);\n  const int m = convex_hull.size();\n\
    \  std::vector<std::pair<emthrm::geometry::Point, int>> ps;\n  ps.reserve(m);\n\
    \  for (int i = 0; i < m; ++i) {\n    ps.emplace_back(convex_hull[i], i);\n  }\n\
    \  std::sort(\n      ps.begin(), ps.end(),\n      [](const std::pair<emthrm::geometry::Point,\
    \ int>& a,\n         const std::pair<emthrm::geometry::Point, int>& b) -> bool\
    \ {\n        const emthrm::geometry::Point& a_p = a.first;\n        const emthrm::geometry::Point&\
    \ b_p = b.first;\n        const int sign = emthrm::geometry::sgn(b_p.y - a_p.y);\n\
    \        return sign == 0 ?\n               emthrm::geometry::sgn(b_p.x - a_p.x)\
    \ == 1 : sign == 1;\n      });\n  std::rotate(convex_hull.begin(),\n         \
    \     std::next(convex_hull.begin(), ps.front().second),\n              convex_hull.end());\n\
    \  std::cout << m << '\\n';\n  for (const emthrm::geometry::Point& p : convex_hull)\
    \ {\n    std::cout << static_cast<int>(std::round(p.x)) << ' '\n             \
    \ << static_cast<int>(std::round(p.y)) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.20.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.20.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.20.test.cpp
- /verify/test/geometry/geometry.20.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u51F8\u5305\
  )"
---
