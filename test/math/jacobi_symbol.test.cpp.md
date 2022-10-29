---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/jacobi_symbol.hpp
    title: "\u30E4\u30B3\u30D3\u8A18\u53F7"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/984
    document_title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
    links:
    - https://yukicoder.me/problems/no/984
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/jacobi_symbol.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7\n */\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/984\"\n\n#include <iostream>\n\n#include\
    \ \"../../math/jacobi_symbol.hpp\"\n\nint main() {\n  int p, n;\n  std::cin >>\
    \ p >> n;\n  std::cout << (n > 1 && jacobi_symbol(n, p) == -1 ? 1 : 0) << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - math/jacobi_symbol.hpp
  isVerificationFile: true
  path: test/math/jacobi_symbol.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/jacobi_symbol.test.cpp
layout: document
redirect_from:
- /verify/test/math/jacobi_symbol.test.cpp
- /verify/test/math/jacobi_symbol.test.cpp.html
title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
---
