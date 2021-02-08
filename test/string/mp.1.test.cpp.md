---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/mp.hpp
    title: "MP \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/MP \u6CD5 (`match(t)`)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/mp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/MP \u6CD5 (`match(t)`)\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../string/mp.hpp\"\
    \r\n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  for\
    \ (int e : MP(p).match(t)) std::cout << e << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/mp.hpp
  isVerificationFile: true
  path: test/string/mp.1.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/mp.1.test.cpp
layout: document
redirect_from:
- /verify/test/string/mp.1.test.cpp
- /verify/test/string/mp.1.test.cpp.html
title: "\u6587\u5B57\u5217/MP \u6CD5 (`match(t)`)"
---
