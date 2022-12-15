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
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (2\u5186\u306E\u4EA4\u70B9)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
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
    \ (2\u5186\u306E\u4EA4\u70B9)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\"\
    \n#define ERROR \"0.000001\"\n\n#include <algorithm>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/geometry/geometry.hpp\"\n\
    \nint main() {\n  emthrm::geometry::Point c1_o, c2_o;\n  double c1r, c2r;\n  std::cin\
    \ >> c1_o >> c1r >> c2_o >> c2r;\n  std::vector<emthrm::geometry::Point> ans =\n\
    \      emthrm::geometry::intersection(emthrm::geometry::Circle(c1_o, c1r),\n \
    \                            emthrm::geometry::Circle(c2_o, c2r));\n  std::sort(ans.begin(),\
    \ ans.end());\n  if (ans.size() == 1) {\n    std::cout << std::fixed << std::setprecision(7)\n\
    \              << ans[0].x << ' ' << ans[0].y << ' '\n              << ans[0].x\
    \ << ' ' << ans[0].y << '\\n';\n  } else if (ans.size() == 2) {\n    for (int\
    \ i = 0; i < 2; ++i) {\n      std::cout << std::fixed << std::setprecision(7)\n\
    \                << ans[i].x << ' ' << ans[i].y << \" \\n\"[i + 1 == 2];\n   \
    \ }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.11.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.11.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.11.test.cpp
- /verify/test/geometry/geometry.11.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u5186\u306E\
  \u4EA4\u70B9)"
---
