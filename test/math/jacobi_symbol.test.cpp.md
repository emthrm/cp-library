---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/jacobi_symbol.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/jacobi_symbol.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7\n */\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/984\"\n\n#include <iostream>\n\n#include\
    \ \"emthrm/math/jacobi_symbol.hpp\"\n\nint main() {\n  int p, n;\n  std::cin >>\
    \ p >> n;\n  std::cout << (n > 1 && emthrm::jacobi_symbol(n, p) == -1 ? 1 : 0)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/jacobi_symbol.hpp
  isVerificationFile: true
  path: test/math/jacobi_symbol.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/jacobi_symbol.test.cpp
layout: document
redirect_from:
- /verify/test/math/jacobi_symbol.test.cpp
- /verify/test/math/jacobi_symbol.test.cpp.html
title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
---
