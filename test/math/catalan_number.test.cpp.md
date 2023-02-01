---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/catalan_number.hpp
    title: "\u30AB\u30BF\u30E9\u30F3\u6570 (Catalan number)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/790
    document_title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
    links:
    - https://yukicoder.me/problems/no/790
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/catalan_number.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570\n */\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/790\"\n\n#include <iostream>\n\n#include\
    \ \"emthrm/math/catalan_number.hpp\"\n#include \"emthrm/math/modint.hpp\"\n\n\
    int main() {\n  int n;\n  std::cin >> n;\n  std::cout << emthrm::catalan_number<742909>(n)[n]\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/catalan_number.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/catalan_number.test.cpp
  requiredBy: []
  timestamp: '2023-02-02 03:55:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/catalan_number.test.cpp
layout: document
redirect_from:
- /verify/test/math/catalan_number.test.cpp
- /verify/test/math/catalan_number.test.cpp.html
title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
---
