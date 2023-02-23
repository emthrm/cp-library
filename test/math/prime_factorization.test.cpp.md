---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    document_title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/prime_factorization.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\n\n#include\
    \ <iostream>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/math/prime_factorization.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<std::pair<int,\
    \ int>> ans = emthrm::prime_factorization(n);\n  std::cout << n << \": \";\n \
    \ for (int i = 0; std::cmp_less(i, ans.size()); ++i) {\n    for (int j = 0; j\
    \ < ans[i].second; ++j) {\n      std::cout << ans[i].first\n                <<\
    \ \" \\n\"[std::cmp_equal(i + 1, ans.size())\n                         && j +\
    \ 1 == ans[i].second];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: true
  path: test/math/prime_factorization.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/prime_factorization.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_factorization.test.cpp
- /verify/test/math/prime_factorization.test.cpp.html
title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
---
