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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (ccw(a, b, c))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
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
    \ (ccw(a, b, c))\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include <iostream>\n\n#include \"emthrm/geometry/geometry.hpp\"\n\nint main()\
    \ {\n  emthrm::geometry::Point p0, p1;\n  int q;\n  std::cin >> p0 >> p1 >> q;\n\
    \  while (q--) {\n    emthrm::geometry::Point p2;\n    std::cin >> p2;\n    const\
    \ int ans = ccw(p0, p1, p2);\n    if (ans == -2) {\n      std::cout << \"ONLINE_FRONT\\\
    n\";\n    } else if (ans == -1) {\n      std::cout << \"CLOCKWISE\\n\";\n    }\
    \ else if (ans == 0) {\n      std::cout << \"ON_SEGMENT\\n\";\n    } else if (ans\
    \ == 1) {\n      std::cout << \"COUNTER_CLOCKWISE\\n\";\n    } else if (ans ==\
    \ 2) {\n      std::cout << \"ONLINE_BACK\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.01.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.01.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.01.test.cpp
- /verify/test/geometry/geometry.01.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (ccw(a, b, c))"
---
