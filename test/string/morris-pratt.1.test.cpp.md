---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/string/morris-pratt.hpp
    title: "Morris\u2013Pratt algorithm"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm (match(t))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/morris-pratt.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/Morris\u2013Pratt algorithm (match(t))\n\
    \ */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/morris-pratt.hpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  for (const int\
    \ ans : emthrm::MorrisPratt(p).match(t)) {\n    std::cout << ans << '\\n';\n \
    \ }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/morris-pratt.hpp
  isVerificationFile: true
  path: test/string/morris-pratt.1.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/morris-pratt.1.test.cpp
layout: document
redirect_from:
- /verify/test/string/morris-pratt.1.test.cpp
- /verify/test/string/morris-pratt.1.test.cpp.html
title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm (match(t))"
---
