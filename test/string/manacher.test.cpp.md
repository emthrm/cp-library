---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/manacher.hpp
    title: Manacher
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    document_title: "\u6587\u5B57\u5217/Manacher"
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/manacher.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/Manacher\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/manacher.hpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  const int n = s.length();\n\
    \  emthrm::Manacher manacher(s);\n  for (int i = 0; i < n; ++i) {\n    std::cout\
    \ << (manacher.odd(i) - 1) * 2 + 1;\n    if (i + 1 == n) {\n      std::cout <<\
    \ '\\n';\n    } else {\n      std::cout << ' ' << manacher.even(i) * 2 << ' ';\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/manacher.hpp
  isVerificationFile: true
  path: test/string/manacher.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/manacher.test.cpp
layout: document
redirect_from:
- /verify/test/string/manacher.test.cpp
- /verify/test/string/manacher.test.cpp.html
title: "\u6587\u5B57\u5217/Manacher"
---
