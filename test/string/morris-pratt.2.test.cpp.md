---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/morris-pratt.hpp
    title: Morris-Pratt algorithm
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
    document_title: "\u6587\u5B57\u5217/Morris-Pratt algorithm (period(idx))"
    links:
    - https://codeforces.com/problemset/problem/1138/D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/morris-pratt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/Morris-Pratt algorithm (period(idx))\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/problemset/problem/1138/D\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <string>\r\n#include\
    \ \"../../string/morris-pratt.hpp\"\r\n\r\nint main() {\r\n  std::string s, t;\r\
    \n  std::cin >> s >> t;\r\n  int zero = std::count(s.begin(), s.end(), '0'), one\
    \ = std::count(s.begin(), s.end(), '1');\r\n  MorrisPratt mp(t);\r\n  std::string\
    \ ans = \"\";\r\n  int period = mp.period(t.length()), pos = 0;\r\n  while (true)\
    \ {\r\n    if (t[pos] == '0') {\r\n      if (zero == 0) break;\r\n      ans +=\
    \ '0';\r\n      --zero;\r\n    } else {\r\n      if (one == 0) break;\r\n    \
    \  ans += '1';\r\n      --one;\r\n    }\r\n    pos = (pos + 1) % period;\r\n \
    \ }\r\n  while (zero--) ans += '0';\r\n  while (one--) ans += '1';\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/morris-pratt.hpp
  isVerificationFile: true
  path: test/string/morris-pratt.2.test.cpp
  requiredBy: []
  timestamp: '2021-04-28 01:24:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/morris-pratt.2.test.cpp
layout: document
redirect_from:
- /verify/test/string/morris-pratt.2.test.cpp
- /verify/test/string/morris-pratt.2.test.cpp.html
title: "\u6587\u5B57\u5217/Morris-Pratt algorithm (period(idx))"
---
