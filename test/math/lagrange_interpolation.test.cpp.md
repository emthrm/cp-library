---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/lagrange_interpolation.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u7248"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\
      \ \u8A55\u4FA1\u7248"
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/lagrange_interpolation.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\
    \ \u8A55\u4FA1\u7248\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/arc033/tasks/arc033_4\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <vector>\n\n#include \"\
    ../../math/lagrange_interpolation.hpp\"\n#include \"../../math/modint.hpp\"\n\n\
    int main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(1000000007);\n  int\
    \ n;\n  std::cin >> n;\n  std::vector<ModInt> x(n + 1);\n  std::iota(x.begin(),\
    \ x.end(), 0);\n  std::vector<ModInt> a(n + 1);\n  for (int i = 0; i <= n; ++i)\
    \ {\n    std::cin >> a[i];\n  }\n  ModInt t;\n  std::cin >> t;\n  std::cout <<\
    \ lagrange_interpolation(x, a, t) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/lagrange_interpolation.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/lagrange_interpolation.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/lagrange_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/math/lagrange_interpolation.test.cpp
- /verify/test/math/lagrange_interpolation.test.cpp.html
title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\
  \u7248"
---
