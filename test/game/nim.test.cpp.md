---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2
    document_title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
    links:
    - https://yukicoder.me/problems/no/2
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/game/nim.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B2\u30FC\u30E0/\u30CB\u30E0\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/2\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    emthrm/game/nim.hpp\"\n#include \"emthrm/math/prime_factorization.hpp\"\n\nint\
    \ main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a;\n  for (const std::pair<int,\
    \ int>& p : emthrm::prime_factorization(n)) {\n    a.emplace_back(p.second);\n\
    \  }\n  std::cout << (emthrm::nim(a) ? \"Alice\\n\" : \"Bob\\n\");\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/game/nim.hpp
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: true
  path: test/game/nim.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/game/nim.test.cpp
layout: document
redirect_from:
- /verify/test/game/nim.test.cpp
- /verify/test/game/nim.test.cpp.html
title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
---
