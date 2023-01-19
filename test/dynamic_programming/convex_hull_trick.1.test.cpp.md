---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/convex_hull_trick.hpp
    title: convex hull trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/dp/tasks/dp_z
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_z
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/dynamic_programming/convex_hull_trick.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))\n\
    \ */\n#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_z\"\n\n#include\
    \ <iostream>\n\n#include \"emthrm/dynamic_programming/convex_hull_trick.hpp\"\n\
    \nint main() {\n  int n;\n  long long c;\n  std::cin >> n >> c;\n  emthrm::ConvexHullTrick<long\
    \ long> convex_hull_trick;\n  for (int i = 0; i < n; ++i) {\n    int h;\n    std::cin\
    \ >> h;\n    if (i == 0) {\n      convex_hull_trick.add(-2 * h, static_cast<long\
    \ long>(h) * h);\n    } else {\n      const long long dp =\n          convex_hull_trick.query(h)\
    \ + static_cast<long long>(h) * h + c;\n      if (i + 1 == n) {\n        std::cout\
    \ << dp << '\\n';\n      } else {\n        convex_hull_trick.add(-2 * h, dp +\
    \ static_cast<long long>(h) * h);\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/convex_hull_trick.hpp
  isVerificationFile: true
  path: test/dynamic_programming/convex_hull_trick.1.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/convex_hull_trick.1.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/convex_hull_trick.1.test.cpp
- /verify/test/dynamic_programming/convex_hull_trick.1.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
---
