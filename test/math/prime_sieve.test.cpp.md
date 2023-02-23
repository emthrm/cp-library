---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/843
    document_title: "\u6570\u5B66/prime sieve"
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/prime_sieve.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/prime sieve\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \n\n#include <iostream>\n#include <set>\n#include <vector>\n\n#include \"emthrm/math/prime_sieve.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<int> tmp = emthrm::prime_sieve<true>(n);\n\
    \  const std::set<int> prime(tmp.begin(), tmp.end());\n  int ans = 0;\n  for (const\
    \ int p : prime) {\n    if (p * p - 2 > n) break;\n    if (prime.contains(p *\
    \ p - 2)) ans += (p == 2 ? 1 : 2);\n  }\n  std::cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/prime_sieve.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/prime_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_sieve.test.cpp
- /verify/test/math/prime_sieve.test.cpp.html
title: "\u6570\u5B66/prime sieve"
---
