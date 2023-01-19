---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/enumerate_k-th_power.hpp
    title: $i^k \bmod m$ ($0 \leq i \leq n$)
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1409
    document_title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
    links:
    - https://yukicoder.me/problems/no/1409
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/enumerate_k-th_power.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)\n */\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1409\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"emthrm/math/enumerate_k-th_power.hpp\"\n\nint main()\
    \ {\n  int t;\n  std::cin >> t;\n  while (t--) {\n    int v, x;\n    std::cin\
    \ >> v >> x;\n    const int p = x * v + 1;\n    const std::vector<int> ps = emthrm::enumerate_kth_power(p\
    \ - 1, x, p);\n    std::vector<int> a;\n    a.reserve(x);\n    for (int i = 1;\
    \ i < p; ++i) {\n      if (ps[i] == 1) a.emplace_back(i);\n    }\n    for (int\
    \ i = 0; i < x; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1 == x];\n   \
    \ }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/enumerate_k-th_power.hpp
  - include/emthrm/math/mod_pow.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/enumerate_k-th_power.test.cpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_k-th_power.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_k-th_power.test.cpp
- /verify/test/math/enumerate_k-th_power.test.cpp.html
title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
---
