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
    ERROR: 1e-6
    PROBLEM: https://atcoder.jp/contests/abc246/tasks/abc246_b
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB)"
    links:
    - https://atcoder.jp/contests/abc246/tasks/abc246_b
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
    \ (\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB)\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc246/tasks/abc246_b\"\
    \n#define ERROR \"1e-6\"\n\n#include <iomanip>\n#include <iostream>\n\n#include\
    \ \"emthrm/geometry/geometry.hpp\"\n\nint main() {\n  emthrm::geometry::Point\
    \ p;\n  std::cin >> p;\n  const emthrm::geometry::Point ans = emthrm::geometry::unit_vector(p);\n\
    \  std::cout << std::fixed << std::setprecision(7)\n            << ans.x << '\
    \ ' << ans.y << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.23.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.23.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.23.test.cpp
- /verify/test/geometry/geometry.23.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u5358\u4F4D\
  \u30D9\u30AF\u30C8\u30EB)"
---
