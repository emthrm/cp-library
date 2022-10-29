---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/twelvefold_way/pascal.hpp
    title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc254/tasks/abc254_b
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\
      \u4E09\u89D2\u5F62"
    links:
    - https://atcoder.jp/contests/abc254/tasks/abc254_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/pascal.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\
    \u4E09\u89D2\u5F62\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc254/tasks/abc254_b\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../math/twelvefold_way/pascal.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<std::vector<int>>\
    \ ans = pascal<int>(n - 1);\n  for (int i = 0; i < n; ++i) {\n    for (int j =\
    \ 0; j <= i; ++j) {\n      std::cout << ans[i][j] << \" \\n\"[j == i];\n    }\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - math/twelvefold_way/pascal.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/pascal.test.cpp
  requiredBy: []
  timestamp: '2022-08-13 17:26:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/pascal.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/pascal.test.cpp
- /verify/test/math/twelvefold_way/pascal.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\
  \u5F62"
---
