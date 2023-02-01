---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/osa_k.hpp
    title: "osa_k \u6CD5"
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
    PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_e
    document_title: "\u6570\u5B66/osa_k \u6CD5"
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/osa_k.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/osa_k \u6CD5\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\
    \n\n#include <algorithm>\n#include <iostream>\n#if __cplusplus < 201703L\n# include\
    \ <utility>\n#endif  // __cplusplus < 201703L\n#include <vector>\n\n#include \"\
    emthrm/math/osa_k.hpp\"\n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int>\
    \ a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const\
    \ int max_a = *std::max_element(a.begin(), a.end());\n  const emthrm::OsaK osa_k(max_a);\n\
    \  std::vector<int> prime_factor(max_a + 1, 0);\n  for (const int a_i : a) {\n\
    #if __cplusplus >= 201703L\n    for (const auto& [prime, _] : osa_k.query(a_i))\
    \ {\n      ++prime_factor[prime];\n    }\n#else\n    for (const std::pair<int,\
    \ int>& pr : osa_k.query(a_i)) {\n      ++prime_factor[pr.first];\n    }\n#endif\
    \  // __cplusplus >= 201703L\n  }\n  const int maximum =\n      *std::max_element(prime_factor.begin(),\
    \ prime_factor.end());\n  if (maximum <= 1) {\n    std::cout << \"pairwise coprime\\\
    n\";\n  } else if (maximum == n) {\n    std::cout << \"not coprime\\n\";\n  }\
    \ else {\n    std::cout << \"setwise coprime\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/osa_k.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/osa_k.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/math/osa_k.test.cpp
- /verify/test/math/osa_k.test.cpp.html
title: "\u6570\u5B66/osa_k \u6CD5"
---
