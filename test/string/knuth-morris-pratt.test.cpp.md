---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/knuth-morris-pratt.hpp
    title: Knuth-Morris-Pratt algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/Knuth-Morris-Pratt algorithm"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/knuth-morris-pratt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/Knuth-Morris-Pratt algorithm\r\n */\r\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../string/knuth-morris-pratt.hpp\"\
    \r\n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  for\
    \ (int e : KnuthMorrisPratt<>(p).match(t)) std::cout << e << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - string/knuth-morris-pratt.hpp
  isVerificationFile: true
  path: test/string/knuth-morris-pratt.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/knuth-morris-pratt.test.cpp
layout: document
redirect_from:
- /verify/test/string/knuth-morris-pratt.test.cpp
- /verify/test/string/knuth-morris-pratt.test.cpp.html
title: "\u6587\u5B57\u5217/Knuth-Morris-Pratt algorithm"
---