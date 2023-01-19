---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/montmort_number.hpp
    title: "\u30E2\u30F3\u30E2\u30FC\u30EB\u6570 (Montmort number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    document_title: "\u6570\u5B66/\u30E2\u30F3\u30E2\u30FC\u30EB\u6570"
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E2\u30F3\u30E2\u30FC\u30EB\u6570\n */\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/math/modint.hpp\"\n#include\
    \ \"emthrm/math/montmort_number.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n\
    \  int n, m;\n  std::cin >> n >> m;\n  ModInt::set_mod(m);\n  const std::vector<ModInt>\
    \ b = emthrm::montmort_number<ModInt>(n);\n  for (int i = 1; i <= n; ++i) {\n\
    \    std::cout << b[i] << \" \\n\"[i == n];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/montmort_number.hpp
  isVerificationFile: true
  path: test/math/montmort_number.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/montmort_number.test.cpp
layout: document
redirect_from:
- /verify/test/math/montmort_number.test.cpp
- /verify/test/math/montmort_number.test.cpp.html
title: "\u6570\u5B66/\u30E2\u30F3\u30E2\u30FC\u30EB\u6570"
---
