---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/berlekamp-massey.hpp
    title: "Berlekamp\u2013Massey algorithm"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013\
      Massey algorithm"
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/formal_power_series/berlekamp-massey.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013\
    Massey algorithm\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/formal_power_series/berlekamp-massey.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  int n;\n  std::cin >> n;\n  std::vector<ModInt>\
    \ a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const\
    \ std::vector<ModInt> c = berlekamp_massey(a);\n  const int d = c.size() - 1;\n\
    \  std::cout << d << '\\n';\n  for (int i = 0; i < d; ++i) {\n    std::cout <<\
    \ -c[i + 1];\n    if (i + 1 < d) std::cout << ' ';\n  }\n  std::cout << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/berlekamp-massey.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/berlekamp-massey.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/berlekamp-massey.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/berlekamp-massey.test.cpp
- /verify/test/math/formal_power_series/berlekamp-massey.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013Massey algorithm"
---
