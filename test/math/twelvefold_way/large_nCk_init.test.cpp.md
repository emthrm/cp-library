---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/twelvefold_way/large_nCk_init.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A $n$ \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\
      \u6570\u8868 \u5DE8\u5927\u306A $n$ \u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/large_nCk_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\
    \u6570\u8868 \u5DE8\u5927\u306A $n$ \u7248\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <vector>\n\n#include \"\
    ../../../math/modint.hpp\"\n#include \"../../../math/twelvefold_way/large_nCk_init.hpp\"\
    \n\nint main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n \
    \ long long n;\n  int m;\n  std::cin >> n >> m;\n  const std::vector<ModInt> c\
    \ = large_nCk_init<0>(n, m - 1);\n  std::cout << ModInt(2).pow(n) - std::accumulate(c.begin(),\
    \ c.end(), ModInt(0))\n            << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/large_nCk_init.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/large_nCk_init.test.cpp
  requiredBy: []
  timestamp: '2022-11-26 03:31:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/large_nCk_init.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/large_nCk_init.test.cpp
- /verify/test/math/twelvefold_way/large_nCk_init.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868\
  \ \u5DE8\u5927\u306A $n$ \u7248"
---
