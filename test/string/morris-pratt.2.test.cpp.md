---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/morris-pratt.hpp
    title: "Morris\u2013Pratt algorithm"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm (period(idx))"
    links:
    - https://codeforces.com/problemset/problem/1138/D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/morris-pratt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/Morris\u2013Pratt algorithm (period(idx))\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/problemset/problem/1138/D\"\
    \r\n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <iostream>\r\n\
    #include <string>\r\n\r\n#include \"../../string/morris-pratt.hpp\"\r\n\r\nint\
    \ main() {\r\n  constexpr int SIGMA = 2;\r\n  std::string s, t;\r\n  std::cin\
    \ >> s >> t;\r\n  int num[2];\r\n  for (int c = 0; c < SIGMA; ++c) {\r\n    num[c]\
    \ = std::count(s.begin(), s.end(), '0' + c);\r\n  }\r\n  const MorrisPratt morris_pratt(t);\r\
    \n  std::string ans = \"\";\r\n  const int period = morris_pratt.period(t.length());\r\
    \n  for (int pos = 0; num[t[pos] - '0'] > 0; pos = (pos + 1) % period) {\r\n \
    \   ans += t[pos];\r\n    --num[t[pos] - '0'];\r\n  }\r\n  for (int c = 0; c <\
    \ SIGMA; ++c) {\r\n    ans += std::string(num[c], '0' + c);\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/morris-pratt.hpp
  isVerificationFile: true
  path: test/string/morris-pratt.2.test.cpp
  requiredBy: []
  timestamp: '2022-02-27 15:05:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/morris-pratt.2.test.cpp
layout: document
redirect_from:
- /verify/test/string/morris-pratt.2.test.cpp
- /verify/test/string/morris-pratt.2.test.cpp.html
title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm (period(idx))"
---
