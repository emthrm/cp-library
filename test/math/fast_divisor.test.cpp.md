---
data:
  _extendedDependsOn:
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
    PROBLEM: https://atcoder.jp/contests/abc170/tasks/abc170_d
    document_title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    links:
    - https://atcoder.jp/contests/abc170/tasks/abc170_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/fast_divisor.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc170/tasks/abc170_d\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <set>\n#include <vector>\n\n#include \"emthrm/math/fast_divisor.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const emthrm::Divisor\
    \ divisor(*std::max_element(a.begin(), a.end()));\n  std::multiset<int> s(a.begin(),\
    \ a.end());\n  std::cout << std::ranges::count_if(\n                   a,\n  \
    \                 [&divisor, &s](const int a_i) -> bool {\n                  \
    \   s.erase(s.lower_bound(a_i));\n                     const bool res = std::ranges::all_of(\n\
    \                         divisor.query(a_i),\n                         [&s](const\
    \ int d) -> bool { return !s.contains(d); });\n                     s.emplace(a_i);\n\
    \                     return res;\n                   })\n            << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/fast_divisor.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fast_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/fast_divisor.test.cpp
- /verify/test/math/fast_divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
